// Copyright 2013 Steven Pearson
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file.

#include "base58.h"
#include <bignat.h>
#include <platform.h>

const char BITCOIN[] PROGMEM = {"123456789ABCDEFGHJKLMNPQRSTUVWXYZabcdefghijkmnopqrstuvwxyz"};

void base58::encode(uint8_t *data,int dataLen,char *out,int outlen){
  WORD abuf[BIGNATBUFSIZE(37)];
  struct bignat a(abuf,sizeof(abuf)/__S);

  int i;
  for(i = 0;i<dataLen&&data[i]==0;i++){
    out[i]=pgm_read_byte(BITCOIN);
  }

  a.SetBytes(data,dataLen);
  a.String(58,BITCOIN,out+i,outlen-i);
}

int base58::decode(const char *data,uint8_t *out,int outlen){

  WORD abuf[BIGNATBUFSIZE(42)];
  struct bignat a(abuf,sizeof(abuf)/__S);

  WORD bbuf[BIGNATBUFSIZE(1)];
  struct bignat b(bbuf,sizeof(bbuf)/__S);
  b.Set(58);

  WORD cbuf[BIGNATBUFSIZE(1)];
  struct bignat c(cbuf,sizeof(cbuf)/__S);

  WORD tbuf[BIGNATBUFSIZE(42)];
  struct bignat t(tbuf,sizeof(tbuf)/__S);

  while(*data!=0){
    WORD val = 0;
    for(val=0;val<58;val++){
      if( BITCOIN[val]==*data){ 
        break;
      }
    }
    if(val==58){
      return -1;
    }
    t.Mul(a,b);
    c.Set(val);
    a.Add(t,c);
    data++;
  }

  return a.Bytes(out,outlen);
}
