#include <panic.h>
#include <bignat.h>
#include <bigint.h>
#include <progress.h>
#include <bitelliptic.h>
#include <base58.h>
#include <sha256.h>
#include <rmd160.h>
#include <bitaddress.h>
#include <platform.h>
#include <serial.h>
#include <test.h>

void testbitaddress(){
  serialprint("testbitaddress\r\n");

  uint8_t PRIVATE[]={0x18,0xE1,0x4A,0x7B,0x6A,0x30,0x7F,0x42,0x6A,0x94,0xF8,0x11,0x47,0x01,0xE7,0xC8,0xE7,0x74,0xE7,0xF9,0xA4,0x7E,0x2C,0x20,0x35,0xDB,0x29,0xA2,0x06,0x32,0x17,0x25};

  WORD xbuf[BIGNATBUFSIZE(32)];
  WORD ybuf[BIGNATBUFSIZE(32)];
  struct bigint pubx(xbuf,sizeof(xbuf)/__S);
  struct bigint puby(ybuf,sizeof(ybuf)/__S);

  bitaddress::generatePublicKey(PRIVATE,pubx,puby);

  serialprint("Generate WIF\r\n");

  char wif[60];
  bitaddress::generatePrivateWIF(PRIVATE,wif,sizeof(wif));
  serialprint(wif);
  serialprint("\r\n");
  char address[36];
  bitaddress::generateAddress(pubx,puby,address,sizeof(address));
  serialprint(address);
  serialprint("\r\n");
}
