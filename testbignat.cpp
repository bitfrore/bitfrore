#include <panic.h>
#include <bignat.h>
#include <platform.h>
#include <stdlib.h>
#include <string.h>
#include <serial.h>
#include <test.h>

const char BITCOIN[] = {"123456789ABCDEFGHJKLMNPQRSTUVWXYZabcdefghijkmnopqrstuvwxyz"};
const char DECIMAL[] = {"0123456789"};

extern "C" void FAIL(const char *msg);

void TestBytesRoundTrip(){
  WORD abuf[8];
  struct bignat a(abuf,sizeof(abuf));

  uint8_t aval[] = {16, 184, 76, 68};
  a.SetBytes(aval,sizeof(aval));

  uint8_t bval[4];
  a.Bytes(bval,sizeof(bval));

  if( memcmp(aval,bval,sizeof(bval)) != 0){
    FAIL(F("Bytes Round Trip 4"));
  }

  uint8_t a8val[] = {16, 184, 76, 68,7,8,5,9};
  a.SetBytes(a8val,sizeof(a8val));

  uint8_t b8val[8];
  a.Bytes(b8val,sizeof(b8val));

  if( memcmp(a8val,b8val,sizeof(b8val)) != 0){
    FAIL(F("Bytes Round Trip 8"));    
  } 

}

void TestCmp(){
  struct bignat zero(NULL,0);
  struct bignat zero2(NULL,0);
  
  if( zero.Cmp(zero2) != 0 ){
    FAIL(F("zero.Cmp(zero2) != 0"));
  }
  if( zero2.Cmp(zero) != 0 ){
    FAIL(F("zero2.Cmp(zero) != 0"));
  }

  WORD onebuf[1];
  struct bignat one(onebuf,sizeof(onebuf));
  one.Set(1);

  if( zero.Cmp(one) != -1 ){
    FAIL(F("zero.Cmp(one) != -1"));
  }
  if( one.Cmp(zero) != 1 ){
    FAIL(F("one.Cmp(zero) != 1"));
  }

  WORD abuf[4];
  struct bignat a(abuf,sizeof(abuf));
  WORD bbuf[4];
  struct bignat b(bbuf,sizeof(bbuf));

  uint8_t aval[] = {16, 56, 94, 68};
  a.SetBytes(aval,4);

  uint8_t bval[] = {37, 146, 1, 89};
  b.SetBytes(bval,4);

  if( a.Cmp(b) != -1 ){
    FAIL(F("a.Cmp(b) != -1"));
  }
  if( b.Cmp(a) != 1 ){
    FAIL(F("b.Cmp(a) != 1"));
  }

}

bool testMulAddConsistency(const struct bignat &a,const struct bignat &b){
  WORD onebuf[1];
  struct bignat one(onebuf,sizeof(onebuf));
  one.Set(1);

  WORD ibuf[4];
  struct bignat i(ibuf,sizeof(ibuf));

  WORD addbuf[8];
  struct bignat add(addbuf,sizeof(addbuf));

  WORD mulbuf[8];
  struct bignat mul(mulbuf,sizeof(mulbuf));

  while(i.Cmp(b)!=0){
    add.Add(add,a);
    i.Add(i,one);
  }
  
  mul.Mul(a,b);

  if( add.Cmp(mul) != 0){
    return false;
  }

  return true;
}

void TestMul(){
  uint8_t xval[] ={0x79,0xBE,0x66,0x7E,0xF9,0xDC,0xBB,0xAC,0x55,0xA0,0x62,0x95,0xCE,0x87,0xB,0x7,0x2,0x9B,0xFC,0xDB,0x2D,0xCE,0x28,0xD9,0x59,0xF2,0x81,0x5B,0x16,0xF8,0x17,0x98};

  uint8_t exVal[] = {
0x39,0xE5,0x8A,0x80,0x55,0xB6,0xFB,0x26,0x4B,0x75,
0xEC,0x8C,0x64,0x65,0x09,0x78,0x42,0x04,0xAC,0x15,
0xA8,0xC2,0x4E,0x05,0xBA,0xBC,0x97,0x29,0xAB,0x9B,
0x05,0x5C,0x3A,0x94,0x58,0xE4,0xCE,0x32,0x89,0x56,
0x0A,0x38,0xE0,0x8B,0xA8,0x17,0x5A,0x94,0x46,0xCE,
0x14,0xE6,0x08,0x24,0x5A,0xB3,0xA9,0x97,0x8A,0x8B,
0xD8,0xAC,0xAA,0x40
};
  WORD exbuf[64];
  struct bignat ex(exbuf,sizeof(exbuf));
  ex.SetBytes(exVal,sizeof(exVal));

  WORD xbuf[32];
  struct bignat x(xbuf,sizeof(xbuf));
  x.SetBytes(xval,sizeof(xval));

  WORD abuf[64];
  struct bignat a(abuf,sizeof(abuf));
  
  a.Mul(x,x);

  if( a.Cmp(ex) != 0){
    FAIL(F("Mul Fail"));
  }
}

void TestMulAddConsistency(){
  WORD abuf[4];
  struct bignat a(abuf,sizeof(abuf));
  WORD bbuf[4];
  struct bignat b(bbuf,sizeof(bbuf));

  a.Set(1);

  if( !testMulAddConsistency(a,b) ){
    FAIL(F("TestMulAddConsistency 1 0"));
  }

  a.Set(1);
  b.Set(1);
  if( !testMulAddConsistency(a,b) ){
    FAIL(F("TestMulAddConsistency 1 1"));
  }

  a.Set(255);
  b.Set(127);
  if( !testMulAddConsistency(a,b) ){
    FAIL(F("TestMulAddConsistency 255 127"));
  }

  uint8_t aval[] = {16, 184, 76, 68};
  a.SetBytes(aval,sizeof(aval));

  uint8_t bval[] = {123,216};
  b.SetBytes(bval,sizeof(bval));
  if( !testMulAddConsistency(a,b) ){
    FAIL(F("TestMulAddConsistency {16, 184, 76, 68} {123,216}"));
  }

}

bool testDivSubConsistency(const struct bignat &a,const struct bignat &b){

  WORD onebuf[1];
  struct bignat one(onebuf,sizeof(onebuf));
  one.Set(1);

  WORD ibuf[4];
  struct bignat i(ibuf,sizeof(ibuf));

  WORD subbuf[8];
  struct bignat sub(subbuf,sizeof(subbuf));

  WORD divbuf[8];
  struct bignat div(divbuf,sizeof(divbuf));
  WORD rbuf[8];
  struct bignat r(rbuf,sizeof(rbuf));

  WORD vbuf[33];

  sub.Set(a);

  while(sub.Cmp(b)>=0){
    sub.Sub(sub,b);
    i.Add(i,one);
  }
  
  div.Div(a,b,r,vbuf);

  if( i.Cmp(div) != 0){
    return false;
  }

  if( r.Cmp(sub) != 0){
    return false;
  }

  return true;
}

void TestDivSubConsistency(){
  WORD abuf[4];
  struct bignat a(abuf,sizeof(abuf));
  WORD bbuf[4];
  struct bignat b(bbuf,sizeof(bbuf));

  a.Set(1);
  b.Set(1);
  if( !testDivSubConsistency(a,b) ){
    FAIL(F("testDivSubConsistency 1 1"));
  }

  a.Set(255);
  b.Set(127);
  if( !testDivSubConsistency(a,b) ){
    FAIL(F("testDivSubConsistency 255 127"));
  }

  uint8_t aval[] = {16, 56, 94, 68};
  a.SetBytes(aval,sizeof(aval));

  uint8_t bval[] = {123,216};
  b.SetBytes(bval,sizeof(bval));
  if( !testDivSubConsistency(a,b) ){
    FAIL(F("testDivSubConsistency {16, 56, 94, 68} {123,216}"));
  }

}


void TestShl(){
  WORD abuf[2];
  struct bignat a(abuf,sizeof(abuf));
  WORD bbuf[2];
  struct bignat b(bbuf,sizeof(bbuf));
  uint8_t bval[] = {1,0};
  b.SetBytes(bval,sizeof(bval));

  a.Set(128);
  a.Shl(a,1);

  if( a.Cmp(b) != 0){
    FAIL(F("TestShl 128 << 1 != 256"));
  }
}

void TestBase58String(){
  char encoded[40];
  uint8_t dataA[] = {0,235,21,35,29,252,235,96,146,88,134,182,125,6,82,153,146,89,21,174,177,114,192,102,71};

  WORD bbuf[32];
  struct bignat b(bbuf,sizeof(bbuf));
  b.SetBytes(dataA,sizeof(dataA));
  b.String(58,BITCOIN,encoded,sizeof(encoded));

  char expected[] ="NS17iag9jJgTHD1VXjvLCEnZuQ3rJDE9L";

  if( strcmp(encoded,expected) != 0 ){
    FAIL(F("TestBase58String Failed"));
  }
}

void testBigNat(){
  TestBytesRoundTrip();

  serialprint("TestBytesRoundTrip\r\n");
  serialprint("TestCmp\r\n");
  TestCmp();
  serialprint("TestMulAddConsistency\r\n");
  TestMulAddConsistency();
  serialprint("TestDivSubConsistency\r\n");
  TestDivSubConsistency();
  serialprint("TestShl\r\n");
  TestShl();
  serialprint("TestBase58String\r\n");
  TestBase58String();
  serialprint("TestMul\r\n");
  TestMul();

}
