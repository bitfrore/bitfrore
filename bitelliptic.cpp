//This code is derived form https://github.com/ThePiachu/Golang-Koblitz-elliptic-curve-DSA-library/tree/master/bitelliptic
// Copyright 2010 The Go Authors. All rights reserved.
// Copyright 2011 ThePiachu. All rights reserved.
// Copyright 2013 Steven Pearson. All rights reserved.
// Use of this source code is governed by a BSD-style
// license that can be found in the GOLANG_LICENSE file.

#include <bitelliptic.h>
#include <progress.h>
#include <platform.h>
#include <serial.h>

int bitcurve::isOnCurve(const struct bigint &x,const struct bigint &y) const{
    WORD tbuf[(BIGNATBUFSIZE(32)*3)+1];
    struct bigint t(tbuf,sizeof(tbuf)/__S);

    WORD y2buf[(BIGNATBUFSIZE(32)*2)+1];
    struct bigint y2(y2buf,sizeof(y2buf)/__S);

    WORD x3buf[(BIGNATBUFSIZE(32)*3)+2];
    struct bigint x3(x3buf,sizeof(x3buf)/__S);

    WORD bbuf[BIGNATBUFSIZE(32)];
    struct bigint b(bbuf,sizeof(bbuf)/__S);
    b.SetBytesP(__B,sizeof(__B));
    
    t.Mul(y,y);//64
    y2.Mod(t,this->P);
    
    x3.Mul(x,x);//64
    t.Mul(x3,x);//96
    t.Add(t,b);//97
    x3.Mod(t,this->P);//98
    
    return x3.Cmp(y2) == 0;
}

bitcurve::bitcurve(const struct bigint &P,const struct bigint &Gx,const struct bigint &Gy) : P(P),Gx(Gx),Gy(Gy){ 
}

/*
void printNatBytes(const struct bignat &a){
  Serial.print(F("{"));
  for(int i=0;i<a.len;i++){
    Serial.print(F("0x"));
    Serial.print(a.data[i],HEX);
    Serial.print(F(","));
  }
  Serial.print(F("}"));
}

void printlnNatBytes(const struct bignat &a){
  printNatBytes(a);
  Serial.println();
}
*/

void bitcurve::_doubleJacobianZ(const struct bigint &y,struct bigint &z){
    WORD tbuf[(BIGNATBUFSIZE(32)*2)+2];
    struct bigint t(tbuf,sizeof(tbuf)/__S);
  
    WORD z3buf[(BIGNATBUFSIZE(32)*2)+1];    
    struct bigint z3(z3buf,sizeof(z3buf)/__S);
    z3.Mul(y,z); //96
    
    t.Set(2); //1
    z3.Mul(t,z3);//97
    
    t.Mod(z3,this->P);//32  

    z.Set(t);
}

void bitcurve::_doubleJacobianX(const struct bigint &f,const struct bigint &d,struct bigint &x){
    WORD tbuf[(((BIGNATBUFSIZE(32)*2)+1)*2)+1+1+1+1];
    struct bigint t(tbuf,sizeof(tbuf)/__S);
  
    WORD x3buf[(((BIGNATBUFSIZE(32)*2)+1)*2)+1+1+1];    
    struct bigint x3(x3buf,sizeof(x3buf)/__S);
    //serialprint("doubleJacobianX set\r\n");

    t.Set(2);//1
    //serialprint("doubleJacobianX mul\r\n");
    x3.Mul(t,d);//132
    
    //serialprint("doubleJacobianX sub\r\n");
    x3.Sub(f,x3);//130

    //serialprint("doubleJacobianX mod\r\n");
    t.Mod(x3,this->P);//32

    //serialprint("doubleJacobianX set\r\n");
    x.Set(t);
    //serialprint("doubleJacobianX done\r\n");
}

void bitcurve::_doubleJacobianY(const struct bigint &d,const struct bigint &e,const struct bigint &c,const struct bigint &x,struct bigint &y){
    WORD tbuf[BIGNATBUFSIZE(1)];
    struct bigint t(tbuf,sizeof(tbuf)/__S);
    WORD t2buf[(BIGNATBUFSIZE(32)*2)+1 + (((BIGNATBUFSIZE(32)*2)+1)*2)+1+1+1+1];
    struct bigint t2(t2buf,sizeof(t2buf)/__S);
  
    WORD y3buf[(BIGNATBUFSIZE(32)*2)+1 + (((BIGNATBUFSIZE(32)*2)+1)*2)+1+1+1];
    struct bigint y3(y3buf,sizeof(y3buf)/__S);
    t2.Sub(d,x);//131 (((BIGNATBUFSIZE(32)*2)+1)*2)+1+1
    y3.Mul(e,t2);//196 (BIGNATBUFSIZE(32)*2)+1 + (((BIGNATBUFSIZE(32)*2)+1)*2)+1+1 
    t.Set(8);//1
    t2.Mul(t,c);//65 (BIGNATBUFSIZE(32)*2*2) + 1
    y3.Sub(y3,t2);//196 (BIGNATBUFSIZE(32)*2)+1 + (((BIGNATBUFSIZE(32)*2)+1)*2)+1+1+1
    t2.Mod(y3,this->P);//32
    y.Set(t2);
}

void bitcurve::_doubleJacobianE(const struct bigint &x,struct bigint &e){
  WORD tbuf[BIGNATBUFSIZE(1)];
  struct bigint t(tbuf,sizeof(tbuf)/__S);
  
  WORD abuf[BIGNATBUFSIZE(32)*2];
  struct bigint a(abuf,sizeof(abuf)/__S);
  a.Mul(x,x); //64

  t.Set(3);//1
  e.Mul(t,a);//65
}

void bitcurve::_doubleJacobianCD(const struct bigint &x,const struct bigint &y,struct bigint &c,struct bigint &dout){

  //TODO:I have recalcutaled A here. I'm not sure I can afford the 64 bytes of stack.
  //I could try to re-combine Jacobian CD and JacobianE
  WORD abuf[BIGNATBUFSIZE(32)*2];
  struct bigint a(abuf,sizeof(abuf)/__S);
  a.Mul(x,x); //64

  WORD bbuf[((BIGNATBUFSIZE(32)*2)+1)*2];
  struct bigint b(bbuf,sizeof(bbuf)/__S);
  b.Mul(y,y); //64

  c.Mul(b,b); //128

  WORD tbuf[BIGNATBUFSIZE(1)];
  struct bigint t(tbuf,sizeof(tbuf)/__S);

  dout.Add(x,b);//65
  
  b.Mul(dout,dout);//130
  
  b.Sub(b,a);//130
  
  b.Sub(b,c);//130
  
  t.Set(2);//1
  dout.Mul(b,t);//131 
}

void bitcurve::doubleJacobian(struct bigint &x,struct bigint &y,struct bigint &z){
  WORD cbuf[BIGNATBUFSIZE(32)*2*2];
  struct bigint c(cbuf,sizeof(cbuf)/__S);

  WORD dbuf[(((BIGNATBUFSIZE(32)*2)+1)*2)+1];
  struct bigint d(dbuf,sizeof(dbuf)/__S);

  WORD ebuf[(BIGNATBUFSIZE(32)*2)+1];
  struct bigint e(ebuf,sizeof(ebuf)/__S);

  WORD fbuf[((BIGNATBUFSIZE(32)*2)+1)*2];
  struct bigint f(fbuf,sizeof(fbuf)/__S);
  
  //serialprint("doubleJacobianE\r\n");

  _doubleJacobianE(x,e);

  //serialprint("doubleJacobian MUL\r\n");
  f.Mul(e,e);//130

  //serialprint("doubleJacobian CD\r\n");
  _doubleJacobianCD(x,y,c,d);

  //serialprint("doubleJacobian z\r\n");
  _doubleJacobianZ(y,z);
  //serialprint("doubleJacobian x\r\n");
  _doubleJacobianX(f,d,x); 
  //serialprint("doubleJacobian y\r\n");
  _doubleJacobianY(d,e,c,x,y);
  //serialprint("doubleJacobian DONE\r\n");
}

void bitcurve::addJacobian(const struct bigint &x1,const struct bigint &y1,const struct bigint &z1,struct bigint &x2,struct bigint &y2,struct bigint &z2){
  WORD z1z1buf[BIGNATBUFSIZE(32)];
  struct bigint z1z1(z1z1buf,sizeof(z1z1buf)/__S);
  WORD z2z2buf[BIGNATBUFSIZE(32)];
  struct bigint z2z2(z2z2buf,sizeof(z2z2buf)/__S);
  
  _addJacobianZ12(z1,z2,z1z1,z2z2);

  WORD u1buf[BIGNATBUFSIZE(32)];
  struct bigint u1(u1buf,sizeof(u1buf)/__S);
  WORD hbuf[(BIGNATBUFSIZE(32)*2)+1];
  struct bigint h(hbuf,sizeof(hbuf)/__S);

  _addJacobianHU1(x1,x2,z1z1,z2z2,u1,h);
  
  WORD jbuf[(BIGNATBUFSIZE(32)*2)+1+(((BIGNATBUFSIZE(32)*2)+1)*2)];
  struct bigint j(jbuf,sizeof(jbuf)/__S);
  //This is a horrible hack I need 230 bytes of scratch space in addJacobianY v and r are last used in y and the scratch space is needed after their last use.
  WORD vrbuf[BIGNATBUFSIZE(232)];
  struct bigint vrstomp(vrbuf,sizeof(vrbuf)/__S);
  struct bigint v(vrbuf,BIGNATBUFSIZE(196));

  _addJacobianJV(h,u1,j,v);
  
  WORD s1buf[BIGNATBUFSIZE(32)];
  struct bigint s1(s1buf,sizeof(s1buf)/__S);
  struct bigint r(vrbuf+BIGNATBUFSIZE(196),(BIGNATBUFSIZE(232)-BIGNATBUFSIZE(196)));
  
  this->_addJacobianS1R(y1,z2,z2z2,y2,z1,z1z1,h,s1,r);
  
  this->_addJacobianX(r,v,j,x2);
  this->_addJacobianY(r,v,s1,x2,j,y2,vrstomp);
  this->_addJacobianZ(z1,z1z1,z2z2,h,z2);
}

void bitcurve::_addJacobianZ12(const struct bigint &z1,const struct bigint &z2,struct bigint &z1z1,struct bigint &z2z2){

  WORD tbuf[(BIGNATBUFSIZE(32)*2)];
  struct bigint t(tbuf,sizeof(tbuf)/__S);
  WORD t2buf[(BIGNATBUFSIZE(32)*2)+1];
  struct bigint t2(t2buf,sizeof(t2buf)/__S);
  
  t.Mul(z1,z1); //64
  t2.Mod(t,this->P);//32
  z1z1.Set(t2);
  
  t.Mul(z2,z2); //64
  t2.Mod(t,this->P);//32
  z2z2.Set(t2);  
}

void bitcurve::_addJacobianHU1(const struct bigint &x1,const struct bigint &x2,const struct bigint &z1z1,const struct bigint &z2z2,struct bigint &u1out,struct bigint &h){

  WORD u1buf[(BIGNATBUFSIZE(32)*2)+1];
  struct bigint u1(u1buf,sizeof(u1buf)/__S);
  h.Mul(x1,z2z2); //64
  u1.Mod(h,this->P); //32
  u1out.Set(u1);
  
  WORD u2buf[(BIGNATBUFSIZE(32)*2)+1];
  struct bigint u2(u2buf,sizeof(u2buf)/__S);
  u1.Mul(x2,z1z1); //64
  u2.Mod(u1,this->P); //32

  h.Sub(u2,u1out);//64
  if( h.neg ){
    h.Add(h,this->P);//64
  }
}

void bitcurve::_addJacobianJV(const struct bigint &h,const struct bigint &u1,struct bigint &j,struct bigint &v){
  
  WORD ibuf[((BIGNATBUFSIZE(32)*2)+1)*2];
  struct bigint i(ibuf,sizeof(ibuf)/__S);
  j.Lsh(h,1);//65
  i.Mul(j,j);//130
  
  j.Mul(h,i);//192
  v.Mul(u1,i);//162
}

void bitcurve::_addJacobianS1R(const struct bigint &y1,const struct bigint &z2,const struct bigint &z2z2,const struct bigint &y2,const struct bigint &z1,const struct bigint &z1z1,const struct bigint &h,struct bigint &s1out,struct bigint &r){

  WORD s1buf[(BIGNATBUFSIZE(32)*3)+1];
  struct bigint s1(s1buf,sizeof(s1buf)/__S);
  WORD s2buf[(BIGNATBUFSIZE(32)*3)+1];
  struct bigint s2(s2buf,sizeof(s2buf)/__S);
  
  s1.Mul(y1,z2);//64
  s2.Mul(s1,z2z2);//96
  s1.Mod(s2,this->P);//32  
  s1out.Set(s1);

  s2.Mul(y2,z1);//33
  s1.Mul(s2,z1z1);//65
  s2.Mod(s1,this->P);//32  
  
  r.Sub(s2,s1out);//33 (s1 and s2 are only 32 at the moment)
  if( r.neg ){
    r.Add(r,this->P);//33
  }
  r.Lsh(r,1);//34
}

void bitcurve::_addJacobianX(const struct bigint &r,const struct bigint &v,const struct bigint &j,struct bigint &x2){
  
  WORD tbuf[BIGNATBUFSIZE(196)];
  struct bigint t(tbuf,sizeof(tbuf)/__S);
  
  WORD x3buf[BIGNATBUFSIZE(195)];
  struct bigint x3(x3buf,sizeof(x3buf)/__S);
  t.Set(r);//33
  x3.Mul(t,t);//66
  x3.Sub(x3,j);//193
  x3.Sub(x3,v);//194
  x3.Sub(x3,v);//195
  t.Mod(x3,this->P);//32
  
  x2.Set(t);
}


//TODO: I don't like the modificaion s1 and the destruction of V
void bitcurve::_addJacobianY(const struct bigint &r,struct bigint &v,struct bigint &s1,const struct bigint &x3,const struct bigint &j,struct bigint &y2,struct bigint &vrstomp){

  WORD tbuf[BIGNATBUFSIZE(230)];
  struct bigint t(tbuf,sizeof(tbuf)/__S);

  v.Sub(v,x3);//196 v.Sub(v,x3);
  t.Mul(r,v);//230 y3.Mul(r,v);

  //v and r now free togethe they provide 230 bytes
  vrstomp.Mul(s1,j); //224
  vrstomp.Lsh(vrstomp,1); //225
  
  t.Sub(t,vrstomp); //
  vrstomp.Mod(t,this->P);
  
  y2.Set(vrstomp);
}

void bitcurve::_addJacobianZ(const struct bigint &z1,const struct bigint &z1z1,const struct bigint &z2z2,const struct bigint &h,struct bigint &z2){

  WORD tbuf[BIGNATBUFSIZE(132)];
  struct bigint t(tbuf,sizeof(tbuf)/__S);
  
  WORD z3buf[BIGNATBUFSIZE(133)];
  struct bigint z3(z3buf,sizeof(z3buf)/__S);
  t.Add(z1,z2);//33
  z3.Mul(t,t);//66
  z3.Sub(z3,z1z1);//67
  if( z3.neg ){
    z3.Add(z3,this->P);//67
  }
  z3.Sub(z3,z2z2);//68
  if( z3.neg ){
    z3.Add(z3,this->P);//68
  }  
  t.Mul(z3,h);//132
  z3.Mod(t,this->P);//32

  z2.Set(z3);
}

void bitcurve::affineFromJacobian(struct bigint &x,struct bigint &y,struct bigint &z){
  WORD zinvbuf[BIGNATBUFSIZE(64)];
  struct bigint zinv(zinvbuf,sizeof(zinvbuf)/__S);
  
  zinv.ModInverse(z,this->P);
  
  this->_affineFromJacobianXY(x,y,zinv);
}

void bitcurve::_affineFromJacobianXY(struct bigint &x,struct bigint &y,const struct bigint &zinv){
  WORD zinvsqbuf[BIGNATBUFSIZE(192)];
  struct bigint zinvsq(zinvsqbuf,sizeof(zinvsqbuf)/__S);

  zinvsq.Mul(zinv,zinv);

  WORD tbuf[BIGNATBUFSIZE(161)];
  struct bigint t(tbuf,sizeof(tbuf)/__S);

  WORD outbuf[BIGNATBUFSIZE(224)];
  struct bigint out(outbuf,sizeof(outbuf)/__S);
  t.Mul(x,zinvsq);
  
  out.Mod(t,this->P);
  
  x.Set(out);

  t.Set(zinvsq);
  zinvsq.Mul(t,zinv);

  t.Mul(y,zinvsq);

  out.Mod(t,this->P);

  y.Set(out);
}


void bitcurve::ScalarMult(const struct bigint &Bx,const struct bigint &By,const uint8_t *k,int klen,struct bigint &x,struct bigint &y){

  //serialprint("ScalarMult\r\n");

  WORD bzbuf[BIGNATBUFSIZE(1)];
  struct bigint Bz(bzbuf,sizeof(bzbuf)/__S);
  Bz.Set(1);
  
  WORD zbuf[BIGNATBUFSIZE(32)];
  struct bigint z(zbuf,sizeof(zbuf)/__S);
  z.Set(Bz);

  x.Set(Bx);
  y.Set(By);
  
  uint8_t seenFirstTrue = 0;
  for( int i = 0 ; i < klen ; i++ ){
    PROGRESS( (float)i / (float) klen );
    //serialprint("Progress\r\n");

    uint8_t b = k[i];
    for( int bitNum = 0 ; bitNum<8;bitNum++){
      if( seenFirstTrue ){
        //serialprint("doubleJacobian\r\n");
        this->doubleJacobian(x,y,z);
      }
      if( ((uint8_t)((uint8_t)b & (uint8_t)0x80)) == (uint8_t)0x80 ) {
        if( !seenFirstTrue ){
          seenFirstTrue=1;
        } else {
          //serialprint("addJacobian\r\n");
          this->addJacobian(Bx,By,Bz,x,y,z);
        }
      }
      b<<=1;
    }
  }
  
  if(!seenFirstTrue){
    x._abs.make(0);
    y._abs.make(0);
    return;
  }
  
  this->affineFromJacobian(x,y,z);  
}


void bitcurve::ScalarBaseMult(const uint8_t *k,int klen,struct bigint &x,struct bigint &y){
  this->ScalarMult(this->Gx,this->Gy,k,klen,x,y);
}
