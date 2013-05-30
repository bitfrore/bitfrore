#include <panic.h>
#include <bignat.h>
#include <bigint.h>
#include <platform.h>
#include <serial.h>
#include <test.h>

const char DECIMAL[] PROGMEM = {"0123456789"};

extern "C" void FAIL(const char *msg);

void biTestCmp(){
  WORD abuf[4];
  struct bigint a(abuf,sizeof(abuf));
  WORD bbuf[4];
  struct bigint b(bbuf,sizeof(bbuf));

  uint8_t aval[] = {16, 56, 94, 68};
  a.SetBytes(0,aval,4);

  uint8_t bval[] = {37, 146, 1, 89};
  b.SetBytes(0,bval,4);

  if( a.Cmp(b) != -1 ){
    FAIL(F("a.Cmp(b) != -1"));
  }
  if( b.Cmp(a) != 1 ){
    FAIL(F("b.Cmp(a) != 1"));
  }

  b.SetBytes(1,bval,4);
  if( a.Cmp(b) != 1 ){
    FAIL(F("a.Cmp(-b) != 1"));
  }
  if( b.Cmp(a) != -1 ){
    FAIL(F("-b.Cmp(a) != -1"));
  }

}

void biTestMul(){
  WORD abuf[4];
  struct bigint a(abuf,sizeof(abuf));
  WORD bbuf[4];
  struct bigint b(bbuf,sizeof(bbuf));
  WORD cbuf[4];
  struct bigint c(cbuf,sizeof(cbuf));

  WORD rbuf[8];
  struct bigint r(rbuf,sizeof(rbuf));
  WORD r2buf[8];
  struct bigint r2(r2buf,sizeof(r2buf));

  uint8_t aval[] = {16, 56, 94, 68};
  a.SetBytes(0,aval,4);

  uint8_t bval[] = {37, 146, 1, 89};
  b.SetBytes(0,bval,4);
  c.SetBytes(1,bval,4);

  r.Mul(a,b);
  r2.Mul(a,c);

  if(r.AbsValue().Cmp(r2.AbsValue()) != 0){
    FAIL(F("abs(a*b) != abs(a*-b)"));
  }

  if( r2.Sign() != -1 ){
    FAIL(F("a*-b is positive"));
  }
  
  if( r2.Sign() == r.Sign() ){
    FAIL(F("a*b has same sign as a*-b"));
  }
}

void biTestDiv(){
  WORD abuf[4];
  struct bigint a(abuf,sizeof(abuf));
  WORD bbuf[4];
  struct bigint b(bbuf,sizeof(bbuf));
  WORD cbuf[4];
  struct bigint c(cbuf,sizeof(cbuf));

  WORD qbuf[8];
  struct bigint q(qbuf,sizeof(qbuf));
  WORD q2buf[8];
  struct bigint q2(q2buf,sizeof(q2buf));

  WORD rbuf[8];
  struct bigint r(rbuf,sizeof(rbuf));
  WORD r2buf[8];
  struct bigint r2(r2buf,sizeof(r2buf));

  WORD vbuf[33];

  uint8_t aval[] = {37, 146, 1, 89};
  a.SetBytes(0,aval,4);

  uint8_t bval[] = {16, 56, 94, 68};
  b.SetBytes(0,bval,4);
  c.SetBytes(1,bval,4);

  q.QuoRem(a,b,r,vbuf);
  q2.QuoRem(a,c,r2,vbuf);

  if(r.Cmp(r2) != 0){
    FAIL(F("remainder a/b != remainder a/-b"));
  }

  if(q.AbsValue().Cmp(q2.AbsValue()) != 0){
    FAIL(F("abs(a/b) != abs(a/-b)"));
  }

  if( q2.Sign() != -1 ){
    FAIL(F("a/-b is positive"));
  }
  
  if( q2.Sign() == q.Sign() ){
    FAIL(F("a/b has same sign as a/-b"));
  }
}

bool testGcd(const struct bigint &d,const struct bigint &x,const struct bigint &a,const struct bigint &b){
  serialprint("TestGcd \r\n");

  WORD Xbuf[4];
  struct bigint X(Xbuf,sizeof(Xbuf));

  WORD Dbuf[4];
  struct bigint D(Dbuf,sizeof(Dbuf));
  serialprint("D.GCD \r\n");
  D.GCD(X,a,b);

  if( D.Cmp(d) != 0 ){
    FAIL(F("D.Cmp(d) != 0"));
  }
  if( X.Cmp(x) != 0 ){
    FAIL(F("X.Cmp(x) != 0"));
  }
  
}

void biTestGCD(){
  
  serialprint("biTestGCD1 \r\n");

  WORD dbuf[4];
  struct bigint d(dbuf,sizeof(dbuf));
  uint8_t dval[] = {3,167};
  d.SetBytes(0,dval,sizeof(dval));

  serialprint("biTestGCD2 \r\n");

  WORD xbuf[4];
  struct bigint x(xbuf,sizeof(xbuf));
  uint8_t xval[] = {3};
  x.SetBytes(1,xval,sizeof(xval));

  serialprint("biTestGCD3 \r\n");

  WORD abuf[4];
  struct bigint a(abuf,sizeof(abuf));
  uint8_t aval[] = {252,3};
  a.SetBytes(0,aval,sizeof(aval));
  
  serialprint("biTestGCD4 \r\n");

  WORD bbuf[4];
  struct bigint b(bbuf,sizeof(bbuf));
  uint8_t bval[] = {94,246};
  b.SetBytes(0,bval,sizeof(bval));

  serialprint("biTestGCD5 \r\n");

  testGcd(d,x,a,b);
}

void biTestModInverse(){

  WORD onebuf[1];
  struct bigint one(onebuf,sizeof(onebuf));
  one.Set(1);

  WORD ebuf[4];
  struct bigint e(ebuf,sizeof(ebuf));
  e.Set(1);

  WORD pbuf[4];
  struct bigint p(pbuf,sizeof(pbuf));
  p.Set(13);

  WORD ibuf[4];
  struct bigint i(ibuf,sizeof(ibuf));

  WORD i2buf[4];
  struct bigint i2(i2buf,sizeof(i2buf));

  i.ModInverse(e,p);
  i2.Mul(i,e);
  i.Mod(i2,p);
  if( i.Cmp(one) != 0){
    FAIL(F("ModInverse Failed"));
  }

}


void testBigInt(){
  serialprint("testBigInt\r\n");

  serialprint("TestCmp\r\n");
  biTestCmp();
  serialprint("TestMul\r\n");
  biTestMul();
  serialprint("TestDiv\r\n");
  biTestDiv();
  serialprint("TestGCD\r\n");
  biTestGCD();
  serialprint("TestModInverse\r\n");
  biTestModInverse();
}

