// Copyright 2013 Steven Pearson
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file.

#include <bitaddress.h>
#include <base58.h>

#include <bitelliptic.h>
#include <rmd160.h>
#include <sha256.h>
#include <base58.h>
#include <panic.h>
#include <platform.h>

#define ADDRESS_VERIFY

bool bitaddress::checkPrivateKey(uint8_t *PRIVATE){
  static const uint8_t MAXKEY[32] = {0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFE,0xBA,0xAE,0xDC,0xE6,0xAF,0x48,0xA0,0x3B,0xBF,0xD2,0x5E,0x8C,0xD0,0x36,0x41,0x40};
    bool allzero = true;
    for (int i=0; i<32; i++){
        if (PRIVATE[i] != 0){
            allzero = false;
            break;
	}
    }

    if(allzero) return false;

    for (int i=0; i<32; i++) {
        if (PRIVATE[i] < MAXKEY[i])
            return true;
        if (PRIVATE[i] > MAXKEY[i])
            return false;
    }
    return true;
}

void generatePublicKeyImpl(uint8_t *PRIVATE,struct bigint &pubx,struct bigint &puby){
  WORD pbuf[BIGNATBUFSIZE(32)];
  WORD gxbuf[BIGNATBUFSIZE(32)];
  WORD gybuf[BIGNATBUFSIZE(32)];

  struct bigint P(pbuf,sizeof(pbuf)/__S);
  struct bigint Gx(gxbuf,sizeof(gxbuf)/__S);
  struct bigint Gy(gybuf,sizeof(gybuf)/__S);
  P.SetBytesP(__P,sizeof(__P));
  
  //Gx and Gy are only needed for the initial add step. I may be able to avoid allocating them by allocating them within addjacobian
  Gx.SetBytesP(_Gx,sizeof(_Gx));
  Gy.SetBytesP(_Gy,sizeof(_Gy));
  
  struct bitcurve S256(P,Gx,Gy);

  S256.ScalarBaseMult(PRIVATE,32,pubx,puby);

#ifdef ADDRESS_VERIFY
  int oncurve = S256.isOnCurve(pubx,puby);
  if( !oncurve ){
    PANIC(PANIC_BITADDRESS_PK_NOTONCURVE);
  }
#endif
}

void checkGeneratePublicKey(uint8_t *PRIVATE,struct bigint &pubx,struct bigint &puby){
  //The check buffers cause an offset in the stack ensuring different SRAM is used for the entire calculation
  WORD checkxbuf[BIGNATBUFSIZE(32)];
  WORD checkybuf[BIGNATBUFSIZE(32)];
  struct bigint checkx(checkxbuf,sizeof(checkxbuf)/__S);
  struct bigint checky(checkybuf,sizeof(checkybuf)/__S);

  generatePublicKeyImpl(PRIVATE,checkx,checky);

  if( checkx.Cmp(pubx) !=0 ||checky.Cmp(puby) !=0 ){
    PANIC(PANIC_BITADDRESS_DOUBLECHECK);  
  }
}

void bitaddress::generatePublicKey(uint8_t *PRIVATE,struct bigint &pubx,struct bigint &puby){
  generatePublicKeyImpl(PRIVATE,pubx,puby);
  checkGeneratePublicKey(PRIVATE,pubx,puby);
}


void bitaddress::generatePrivateWIF(uint8_t *PRIVATE,char *out,int limit){
  uint8_t wifbuf[37];
  wifbuf[0]=0x80;
//  memcpy(wifbuf+1,PRIVATE,32);
  for(int i=0;i<32;i++){
    wifbuf[i+1]=PRIVATE[i];
  }
  
  struct SHA256_CTX ctx;
  sha256_init(&ctx);
  sha256_update(&ctx,wifbuf,33);
  
  uint8_t hash[32];
  sha256_final(&ctx,hash);
  
  sha256_init(&ctx);
  sha256_update(&ctx,hash,32);
  sha256_final(&ctx,hash);
  
  wifbuf[33]=hash[0];
  wifbuf[34]=hash[1];
  wifbuf[35]=hash[2];
  wifbuf[36]=hash[3];
  
  base58::encode(wifbuf,sizeof(wifbuf),out,limit);
}

void bitaddress::generateAddress(const struct bigint &x,const struct bigint &y,char *out,int limit){
  uint8_t four=4;
  
  struct SHA256_CTX ctx;
  sha256_init(&ctx);
  sha256_update(&ctx,&four,1);
  
  uint8_t tbuf[32];
  x._abs.Bytes(tbuf,sizeof(tbuf));
  sha256_update(&ctx,tbuf,sizeof(tbuf));
  y._abs.Bytes(tbuf,sizeof(tbuf));
  sha256_update(&ctx,tbuf,sizeof(tbuf));
  uint8_t hash[32];
  sha256_final(&ctx,hash);
  
  uint8_t digest[25];
  struct digest d;
  Reset(&d);
  Write(&d,hash,sizeof(hash));
  Sum(&d,digest+1);
  
  digest[0]=0;
  
  sha256_init(&ctx);
  sha256_update(&ctx,digest,21);
  sha256_final(&ctx,hash);

  sha256_init(&ctx);
  sha256_update(&ctx,hash,sizeof(hash));
  sha256_final(&ctx,hash);
  
  digest[21]=hash[0];
  digest[22]=hash[1];
  digest[23]=hash[2];
  digest[24]=hash[3];
  
  base58::encode(digest,sizeof(digest),out,limit);
}
