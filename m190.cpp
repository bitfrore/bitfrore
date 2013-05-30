#include <panic.h>
#include <progress.h>
#include <bignat.h>
#include <bigint.h>
#include <sha256.h>
#include <rmd160.h>
#include <base58.h>
#include <bitelliptic.h>
#include <bitaddress.h>
#include <rng.h>
#include <qrencode.h>
#include <m190printer.h>
#include <platform.h>
#include <test.h>

const float qrxscale=2.25;
const int qryscale=2;

//const float qrxscale=1.125;
//const int qryscale=1;

//const int qryscale=3;
//const float qrxscale=3.375;

bool qrcodesource(void *ctx,int x,int y){
  qrcontext *qr=(qrcontext *)ctx;

  float fx = (float)x/qrxscale;
  x=fx;
  y/=qryscale;
  if(x<0||x>WD||y<0||y>WD){
    return 0;
  } else {
    return qr->getQRBit(x,y);
  }
}

uint8_t qroffset=20;

bool qrcodesource2(void *ctx,int x,int y){
//  return( x==10 || y==10);
  qrcontext *qr=(qrcontext *)ctx;

  float fx = (float)x/qrxscale;
  x=fx;
  x-=qroffset;
  y/=qryscale;
  if(x<0||x>WD||y<0||y>WD){
    return 0;
  } else {
    return qr->getQRBit(x,y);
  }
}


bool horizlinesource(void *ctx,int x,int y){
  return 1;  
}

void horizline(){
  m190::print(horizlinesource,0,5,true);
  m190::formfeed(2);
}

void printqr(char *encoded){
  qrcontext qr;
  qr.qrencode(encoded);
  m190::print(qrcodesource2,&qr,WD*qryscale,true);
}

void printprivate(uint8_t *PRIVATE){
  char encoded[52];
  bitaddress::generatePrivateWIF(PRIVATE,encoded,sizeof(encoded));
  printqr(encoded);
  m190::formfeed(5);
  m190::print(encoded);
}

void printpublic(const struct bigint &x,const struct bigint &y){
  char encoded[40];
  bitaddress::generateAddress(x,y,encoded,sizeof(encoded)); 
  
  m190::print(encoded);
  m190::formfeed(5);
  printqr(encoded);
}

void generatePrivateKey(uint8_t *PRIVATE){
  rng::generate(PRIVATE);
}

void initprinter(){
  m190::initialize();
}

void printpaperwallet(){
  uint8_t PRIVATE[32];
  WORD xbuf[BIGNATBUFSIZE(32)];
  WORD ybuf[BIGNATBUFSIZE(32)];
  struct bigint pubx(xbuf,sizeof(xbuf)/__S);
  struct bigint puby(ybuf,sizeof(ybuf)/__S);
  generatePrivateKey(PRIVATE);

  bitaddress::generatePublicKey(PRIVATE,pubx,puby);

  m190::formfeed(30);

  qroffset=5;
  printprivate(PRIVATE);
  m190::formfeed(75);
  
  
  qroffset=5;
  printpublic(pubx,puby);
  m190::formfeed(20);

}
