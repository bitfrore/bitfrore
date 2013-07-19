// Copyright 2013 Steven Pearson
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file.

#include <m190printer.h>
#include <platform.h>
#include "inc/LPC11xx.h"
#include "hdr/hdr_gpio_masked_access.h"
#include <config.h>
#include <watchdog.h>
#include <panic.h>

#define RECORD_TICKS

#define ADC_NUM 8 /* for LPC11xx */
#define ADC_CLK 2400000 /* set to 2.4Mhz */
#define ADC_OFFSET 0x10
#define ADC_INDEX 4

#define ADC_DONE 0x80000000
#define ADC_OVERRUN 0x40000000

#define RDET_GPIO							LPC_GPIO2	///< GPIO port to which the LED is connected
#define RDET_pin								3			///< pin number of the LED
#define RDET									(1 << RDET_pin)

/// "variable" to manipulate the pin directly via GPIO masked access
#define RDET_gma								gpio_masked_access_t GPIO_MASKED_ACCESS(RDET_GPIO, RDET_pin)

#define SOLA_GPIO LPC_GPIO2
#define SOLA_pin  1
#define SOLA		  (1 << SOLA_pin)
#define SOLA_gma  gpio_masked_access_t GPIO_MASKED_ACCESS(SOLA_GPIO, SOLA_pin)

#define SOLB_GPIO LPC_GPIO0
#define SOLB_pin  10
#define SOLB		  (1 << SOLB_pin)
#define SOLB_gma  gpio_masked_access_t GPIO_MASKED_ACCESS(SOLB_GPIO, SOLB_pin)

#define SOLC_GPIO LPC_GPIO2
#define SOLC_pin  11
#define SOLC		  (1 << SOLC_pin)
#define SOLC_gma  gpio_masked_access_t GPIO_MASKED_ACCESS(SOLC_GPIO, SOLC_pin)

#define SOLD_GPIO LPC_GPIO2
#define SOLD_pin  4
#define SOLD		  (1 << SOLD_pin)
#define SOLD_gma  gpio_masked_access_t GPIO_MASKED_ACCESS(SOLD_GPIO, SOLD_pin)

#define SOLE_GPIO LPC_GPIO3
#define SOLE_pin  5
#define SOLE		  (1 << SOLE_pin)
#define SOLE_gma  gpio_masked_access_t GPIO_MASKED_ACCESS(SOLE_GPIO, SOLE_pin)

#define SOLF_GPIO LPC_GPIO0
#define SOLF_pin  7
#define SOLF		  (1 << SOLF_pin)
#define SOLF_gma  gpio_masked_access_t GPIO_MASKED_ACCESS(SOLF_GPIO, SOLF_pin)

#define SOLG_GPIO LPC_GPIO0
#define SOLG_pin  2
#define SOLG		  (1 << SOLG_pin)
#define SOLG_gma  gpio_masked_access_t GPIO_MASKED_ACCESS(SOLG_GPIO, SOLG_pin)

#define SOLH_GPIO LPC_GPIO2
#define SOLH_pin  8
#define SOLH		  (1 << SOLH_pin)
#define SOLH_gma  gpio_masked_access_t GPIO_MASKED_ACCESS(SOLH_GPIO, SOLH_pin)

static const uint8_t ASCII[] PROGMEM =
{
 0x00, 0x00, 0x00, 0x00, 0x00 // 20  
,0x00, 0x00, 0x5f, 0x00, 0x00 // 21 !
,0x00, 0x07, 0x00, 0x07, 0x00 // 22 "
,0x14, 0x7f, 0x14, 0x7f, 0x14 // 23 #
,0x24, 0x2a, 0x7f, 0x2a, 0x12 // 24 $
,0x23, 0x13, 0x08, 0x64, 0x62 // 25 %
,0x36, 0x49, 0x55, 0x22, 0x50 // 26 &
,0x00, 0x05, 0x03, 0x00, 0x00 // 27 '
,0x00, 0x1c, 0x22, 0x41, 0x00 // 28 (
,0x00, 0x41, 0x22, 0x1c, 0x00 // 29 )
,0x14, 0x08, 0x3e, 0x08, 0x14 // 2a *
,0x08, 0x08, 0x3e, 0x08, 0x08 // 2b +
,0x00, 0x50, 0x30, 0x00, 0x00 // 2c ,
,0x08, 0x08, 0x08, 0x08, 0x08 // 2d -
,0x00, 0x60, 0x60, 0x00, 0x00 // 2e .
,0x20, 0x10, 0x08, 0x04, 0x02 // 2f /
,0x3e, 0x51, 0x49, 0x45, 0x3e // 30 0
,0x00, 0x42, 0x7f, 0x40, 0x00 // 31 1
,0x42, 0x61, 0x51, 0x49, 0x46 // 32 2
,0x21, 0x41, 0x45, 0x4b, 0x31 // 33 3
,0x18, 0x14, 0x12, 0x7f, 0x10 // 34 4
,0x27, 0x45, 0x45, 0x45, 0x39 // 35 5
,0x3c, 0x4a, 0x49, 0x49, 0x30 // 36 6
,0x01, 0x71, 0x09, 0x05, 0x03 // 37 7
,0x36, 0x49, 0x49, 0x49, 0x36 // 38 8
,0x06, 0x49, 0x49, 0x29, 0x1e // 39 9
,0x00, 0x36, 0x36, 0x00, 0x00 // 3a :
,0x00, 0x56, 0x36, 0x00, 0x00 // 3b ;
,0x08, 0x14, 0x22, 0x41, 0x00 // 3c <
,0x14, 0x14, 0x14, 0x14, 0x14 // 3d =
,0x00, 0x41, 0x22, 0x14, 0x08 // 3e >
,0x02, 0x01, 0x51, 0x09, 0x06 // 3f ?
,0x32, 0x49, 0x79, 0x41, 0x3e // 40 @
,0x7e, 0x11, 0x11, 0x11, 0x7e // 41 A
,0x7f, 0x49, 0x49, 0x49, 0x36 // 42 B
,0x3e, 0x41, 0x41, 0x41, 0x22 // 43 C
,0x7f, 0x41, 0x41, 0x22, 0x1c // 44 D
,0x7f, 0x49, 0x49, 0x49, 0x41 // 45 E
,0x7f, 0x09, 0x09, 0x09, 0x01 // 46 F
,0x3e, 0x41, 0x49, 0x49, 0x7a // 47 G
,0x7f, 0x08, 0x08, 0x08, 0x7f // 48 H
,0x00, 0x41, 0x7f, 0x41, 0x00 // 49 I
,0x20, 0x40, 0x41, 0x3f, 0x01 // 4a J
,0x7f, 0x08, 0x14, 0x22, 0x41 // 4b K
,0x7f, 0x40, 0x40, 0x40, 0x40 // 4c L
,0x7f, 0x02, 0x0c, 0x02, 0x7f // 4d M
,0x7f, 0x04, 0x08, 0x10, 0x7f // 4e N
,0x3e, 0x41, 0x41, 0x41, 0x3e // 4f O
,0x7f, 0x09, 0x09, 0x09, 0x06 // 50 P
,0x3e, 0x41, 0x51, 0x21, 0x5e // 51 Q
,0x7f, 0x09, 0x19, 0x29, 0x46 // 52 R
,0x46, 0x49, 0x49, 0x49, 0x31 // 53 S
,0x01, 0x01, 0x7f, 0x01, 0x01 // 54 T
,0x3f, 0x40, 0x40, 0x40, 0x3f // 55 U
,0x1f, 0x20, 0x40, 0x20, 0x1f // 56 V
,0x3f, 0x40, 0x38, 0x40, 0x3f // 57 W
,0x63, 0x14, 0x08, 0x14, 0x63 // 58 X
,0x07, 0x08, 0x70, 0x08, 0x07 // 59 Y
,0x61, 0x51, 0x49, 0x45, 0x43 // 5a Z
,0x00, 0x7f, 0x41, 0x41, 0x00 // 5b [
,0x02, 0x04, 0x08, 0x10, 0x20 // 5c ¥
,0x00, 0x41, 0x41, 0x7f, 0x00 // 5d ]
,0x04, 0x02, 0x01, 0x02, 0x04 // 5e ^
,0x40, 0x40, 0x40, 0x40, 0x40 // 5f _
,0x00, 0x01, 0x02, 0x04, 0x00 // 60 `
,0x20, 0x54, 0x54, 0x54, 0x78 // 61 a
,0x7f, 0x48, 0x44, 0x44, 0x38 // 62 b
,0x38, 0x44, 0x44, 0x44, 0x20 // 63 c
,0x38, 0x44, 0x44, 0x48, 0x7f // 64 d
,0x38, 0x54, 0x54, 0x54, 0x18 // 65 e
,0x08, 0x7e, 0x09, 0x01, 0x02 // 66 f
,0x0c, 0x52, 0x52, 0x52, 0x3e // 67 g
,0x7f, 0x08, 0x04, 0x04, 0x78 // 68 h
,0x00, 0x44, 0x7d, 0x40, 0x00 // 69 i
,0x20, 0x40, 0x44, 0x3d, 0x00 // 6a j 
,0x7f, 0x10, 0x28, 0x44, 0x00 // 6b k
,0x00, 0x41, 0x7f, 0x40, 0x00 // 6c l
,0x7c, 0x04, 0x18, 0x04, 0x78 // 6d m
,0x7c, 0x08, 0x04, 0x04, 0x78 // 6e n
,0x38, 0x44, 0x44, 0x44, 0x38 // 6f o
,0x7c, 0x14, 0x14, 0x14, 0x08 // 70 p
,0x08, 0x14, 0x14, 0x18, 0x7c // 71 q
,0x7c, 0x08, 0x04, 0x04, 0x08 // 72 r
,0x48, 0x54, 0x54, 0x54, 0x20 // 73 s
,0x04, 0x3f, 0x44, 0x40, 0x20 // 74 t
,0x3c, 0x40, 0x40, 0x20, 0x7c // 75 u
,0x1c, 0x20, 0x40, 0x20, 0x1c // 76 v
,0x3c, 0x40, 0x30, 0x40, 0x3c // 77 w
,0x44, 0x28, 0x10, 0x28, 0x44 // 78 x
,0x0c, 0x50, 0x50, 0x50, 0x3c // 79 y
,0x44, 0x64, 0x54, 0x4c, 0x44 // 7a z
,0x00, 0x08, 0x36, 0x41, 0x00 // 7b {
,0x00, 0x00, 0x7f, 0x00, 0x00 // 7c |
,0x00, 0x41, 0x36, 0x08, 0x00 // 7d }
,0x10, 0x08, 0x08, 0x10, 0x08 // 7e ←
,0x78, 0x46, 0x41, 0x46, 0x78 // 7f →
};

uint32_t m190adcread( uint8_t channelNum )
{
  uint32_t regVal, ADC_Data;

  /* channel number is 0 through 7 */
  if ( channelNum >= ADC_NUM )
  {
    channelNum = 0;	/* reset channel number to 0 */
  }
  LPC_ADC->CR &= 0xFFFFFF00;
  LPC_ADC->CR |= (1 << 24) | (1 << channelNum);	
  /* switch channel,start A/D convert */
  while ( 1 )	/* wait until end of A/D convert */
  {
    regVal = *(volatile unsigned long *)(LPC_ADC_BASE+ ADC_OFFSET + ADC_INDEX * channelNum);
    /* read result of A/D conversion */
    if ( regVal & ADC_DONE )
    {
      break;
    }
  }	
        
  LPC_ADC->CR &= 0xF8FFFFFF;	/* stop ADC now */
  if ( regVal & ADC_OVERRUN )	/* save data when it's not overrun, otherwise, return zero */
  {
    return ( 0 );
  }
  ADC_Data = ( regVal >> 6 ) & 0x3FF;
  return ( ADC_Data );	/* return A/D conversion value */
}

#ifdef RECORD_TICKS
extern "C" void recordTick(int val);
#endif

bool isTick(){
  static uint8_t flipflop;
  static int lastvals[3]; 
  static int lastvalpos=0;

  lastvalpos++;
  lastvalpos%=3;

  int val=m190adcread(7);

#ifdef RECORD_TICKS
  recordTick(val);
#endif   

  bool tickfound=false;

  int diff = lastvals[lastvalpos]-val;

  if(flipflop==0){
    if( diff > 25 ){
      flipflop=1;
      tickfound=true;
#ifdef RECORD_TICKS
      recordTick(9999);
#endif
    }
  } else {
    if( diff < -25 ){
      flipflop=0;
    }
  }
  
  lastvals[lastvalpos]=val;
  
  return tickfound;
}

const int RESET_LIMIT=30;

int tickcount=0;

bool isReset(){
  static uint8_t armed=0;

  int val = (RDET_gma & RDET);

  if( val ){
    switch(armed){
      case 0:
        armed=1;
        break;
      case RESET_LIMIT:
        armed++;
        return true;
      case RESET_LIMIT+1:
        break;
      default:
        armed++;
        break;
    }
  }
  else {
    armed=0;
  }
  
  return false;
}

void solenoidsoff(){
      SOLA_gma=0;
      SOLB_gma=0;
      SOLC_gma=0;
      SOLD_gma=0;
      SOLE_gma=0;
      SOLF_gma=0;
      SOLG_gma=0;
      SOLH_gma=0;
}

void solenoidson(){
      SOLA_gma=SOLA;
      SOLB_gma=SOLB;
      SOLC_gma=SOLC;
      SOLD_gma=SOLD;
      SOLE_gma=SOLE;
      SOLF_gma=SOLF;
      SOLG_gma=SOLG;
      SOLH_gma=SOLH;
}

void motoroff(){
  //Motor OFF
  MOTOR_gma=0;
}

void motoron(){
  //Motor OFF
  MOTOR_gma=MOTOR;
}

//TODO: I'd like the default error handler to call this too.
void PRINTERPANIC(paniccode c){
  motoroff();
  solenoidsoff();
  PANIC(c);
}

void m190::initialize(){

  /* Solenoids pins GPIO */
  //LPC_IOCON->PIO0_8 |=0x80; //Motor
  //LPC_IOCON->PIO2_1 = 0x80; //A
  LPC_IOCON->SWCLK_PIO0_10 |=0x81; //B
  //LPC_IOCON->PIO2_11 |=0x80; //C
  //LPC_IOCON->PIO2_4 |=0x80; //D
  //LPC_IOCON->PIO3_5 |=0x80; //E
  //LPC_IOCON->PIO0_7 |=0x80; //F
  //LPC_IOCON->PIO0_2 |=0x80; //G
  //LPC_IOCON->PIO2_8 =0x80; //H

  // Solenoids to output
  SOLA_GPIO->DIR |= SOLA;
  SOLB_GPIO->DIR |= SOLB;
  SOLC_GPIO->DIR |= SOLC;
  SOLD_GPIO->DIR |= SOLD;
  SOLE_GPIO->DIR |= SOLE;
  SOLF_GPIO->DIR |= SOLF;
  SOLG_GPIO->DIR |= SOLG;
  SOLH_GPIO->DIR |= SOLH;

  //Printer Motor to output

  MOTOR_GPIO->DIR |= MOTOR;

  solenoidsoff();
  motoroff();

  //Reset detector to input
  LPC_IOCON->PIO2_3 &= ~0x10; //Disable pull up
  LPC_IOCON->PIO2_3 |=0x89; //Enable GPIO and Pull Down
  RDET_GPIO->DIR &= ~RDET;
}

bool formfeedsource(void *ctx,int x,int y){
  return 0;
}

int calcPortVal(m190::pixelsource source,void *ctx,int x,int y,int solgroup){
  int ret=0;
  //Only power 3 solenoids max at a time
  switch(solgroup){
    case 0:
      if(source(ctx,x,y)){ret|=1;} //A
      if(source(ctx,x+54,y)){ret|=1<<3;} //D
      if(source(ctx,x+108,y)){ret|=1<<6;} //G
      break;
    case 1:
      if(source(ctx,x+18,y)){ret|=1<<1;} //B
      if(source(ctx,x+72,y)){ret|=1<<4;} //E
      if(source(ctx,x+126,y)){ret|=1<<7;} //H
      break;
    case 2:
      if(source(ctx,x+36,y)){ret|=1<<2;} //C
      if(source(ctx,x+90,y)){ret|=1<<5;} //F
      break;
  }

  return ret;        
}

void m190::print(pixelsource source,void *ctx,int rows,bool overlap){

  solenoidsoff();
  motoron();
  //analogWrite(PIN_MOTOR,200);
 
  int firsttick=1;

  int maxticks=overlap?60:54;

  //spin up
  int y=-2;
  int ticks=0;
  int fire=0;
  while(y<rows){
    if( isReset() ){
      #ifdef RECORD_TICKS
      recordTick(2000+ticks);
      tickcount=0;
      #endif

      ticks=0;
      y++;
      //calc first byte for this new row
      fire=calcPortVal(source,ctx,0,y,0);
    }

    //TODO: validate we get 90 ticks

    if (!isTick()){
      continue;
    }
    ticks++;
    //Feed the watchdog if we can detect the print head is moving.
    //If the head becomes jammed ticks will stop.
    Watchdog_Feed();
    if(ticks>90*2){
      //Reset detector is not working or timining generator has failed
      PRINTERPANIC(PANIC_PRINT_OVERTICK);
    }

    //We are in the printing range
    if( y>=0 && ticks >=firsttick && ticks <=maxticks ){
      if( (fire&(1<<0)) !=0 ){
        SOLA_gma=SOLA;
      }else{
        SOLA_gma=0;
      }
      if( (fire&(1<<1)) !=0 ){
        SOLB_gma=SOLB;
      }else{
        SOLB_gma=0;
      }
      if( (fire&(1<<2)) !=0 ){
        SOLC_gma=SOLC;
      }else{
        SOLC_gma=0;
      }

      if( (fire&(1<<3)) !=0 ){
        SOLD_gma=SOLD;
      }else{
        SOLD_gma=0;
      }

      if( (fire&(1<<4)) !=0 ){
        SOLE_gma=SOLE;
      }else{
        SOLE_gma=0;
      }

      if( (fire&(1<<5)) !=0 ){
        SOLF_gma=SOLF;
      }else{
        SOLF_gma=0;
      }

      if( (fire&(1<<6)) !=0 ){
        SOLG_gma=SOLG;
      }else{
        SOLG_gma=0;
      }

      if( (fire&(1<<7)) !=0 ){
        SOLH_gma=SOLH;
      }else{
        SOLH_gma=0;
      }


/*
      if( ticks%3==1){
        SOLC_gma=SOLC;
      }else{
        SOLC_gma=0;
      }
      if( ticks%3==2){
        SOLD_gma=SOLD;
      }else{
        SOLD_gma=0;
      }
*/
      //(fire&1)==1?SOLA_gma==SOLA:SOLA_gma=0;
      //(fire&(1<<1))==SOLB?SOLB_gma=SOLB:SOLB_gma=0;
      //(fire&(1<<2))!=0?SOLC_gma|=SOLC:SOLC_gma&=~SOLC;
      //(fire&(1<<3))!=0?SOLD_gma|=SOLD:SOLD_gma&=~SOLD;
      //(fire&(1<<4))!=0?SOLE_gma|=SOLE:SOLE_gma&=~SOLE;
      //(fire&(1<<5))!=0?SOLF_gma|=SOLF:SOLF_gma&=~SOLF;
      //(fire&(1<<6))!=0?SOLG_gma|=SOLG:SOLG_gma&=~SOLG;
      //(fire&(1<<7))!=0?SOLH_gma|=SOLH:SOLH_gma&=~SOLH;

      int pos = (ticks-firsttick)+1;
      int x=pos/3;
      int solgroup = pos%3;
  
      fire=calcPortVal(source,ctx,x,y,solgroup);
    } else {
      solenoidsoff();
    }
  }

  //Turn off all solenoids
  solenoidsoff();
  //stop the motor
  motoroff();
}

void m190::formfeed(int rows){
  m190::print(formfeedsource,0,rows,false);
}

struct stringcontext{
  const char *str;
  int len;
};

unsigned char getCharPixel(char c,int x,int y){
  //character and line spaces
  if( x>=5 || y >=7){
    return 0;
  }
  
  uint8_t b = pgm_read_byte(ASCII+((c - 0x20)*5)+x);
  
  return b&(1<<y);
}

unsigned char getStringPixel(const char *c,int l,int x,int y){
  //What character does this x and y coord relate to

  int lpos = y/8;
  int ypos = y%8;
  int cpos = (lpos*24)+(x/6);
  if( cpos >= l ){
    return 0;
  }
  int ppos = x%6;
  
  return getCharPixel(c[cpos],ppos,ypos);  
}

bool stringsource(void *ctx,int x,int y){
  stringcontext *sctx = (stringcontext *)ctx;
  
  return getStringPixel(sctx->str,sctx->len,x,y);
}

void m190::print(char *str){

  stringcontext ctx;
  ctx.str=str;
  ctx.len=0;
  char *l=str;
  while(*l!=0){
    ctx.len++;
    l++;    
  }

  int reqrows = ((ctx.len/24)+1)*8;


  print(stringsource,&ctx,reqrows,false);
}

struct bitmapcontext{
  const uint8_t *bitmap;
  int w;
  int h;
};

bool bitmapsource(void *ctx,int x,int y){
  bitmapcontext *bctx=(bitmapcontext *)ctx;

  int xbyte = x/8;
  int xbit = x%8;
  
  int pos = (bctx->w*y)+xbyte;
  int val = pgm_read_byte(bctx->bitmap+pos);
  return val & 1<<xbit;
}

void m190::printP(const uint8_t *bitmap,int w,int h){
  bitmapcontext ctx;
  ctx.bitmap=bitmap;
  ctx.w=w;
  ctx.h=h;

  print(bitmapsource,&ctx,h,true);
}

