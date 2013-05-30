// Copyright 2013 Steven Pearson
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file.

#include <rng.h>
#include <sha256.h>
#include <panic.h>
#include <progress.h>
#include "inc/LPC11xx.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <serial.h>

#define NIST_RNG_VERIFY
#define NIST_RUN_RNG_VERIFY
#define DEBIAS

//#define DEBUG

//#define RNGVALDEBUG

#ifdef DEBUG
void DBGPRINT(char *str);
#endif

#define ADC_NUM 8 /* for LPC11xx */
#define ADC_CLK 2400000 /* set to 2.4Mhz */
#define ADC_OFFSET 0x10
#define ADC_INDEX 4

#define ADC_DONE 0x80000000
#define ADC_OVERRUN 0x40000000

uint32_t rngadcread( uint8_t channelNum )
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

uint8_t getSampleImpl(){
  int s = rngadcread(4);
//  char msg[32];
//  sprintf(msg,"RAW SAMPLE %d\r\n",s);
//  serialprint(msg);

  //Analog values have 10 bits of accuracy. Condense these 10 bits of noise into 1 bit
  uint8_t r = (s ^ s>>1 ^ s>>2  ^ s>>3 ^ s>>4 ^ s>>5 ^ s>>6 ^ s>>7 ^ s>>8 ^ s>>9)&0x01;
  return r;
}

uint8_t getSample(){
#ifdef DEBIAS
  //Von neumann debiasing
  for(uint8_t i=0;i<100;i++){
    uint8_t s1 =getSampleImpl();
    uint8_t s2 =getSampleImpl();

#ifdef RNGVALDEBUG
  char out[5];
  itoa(s1,out,10);
  DBGPRINT(out);
  itoa(s2,out,10);
  DBGPRINT(out);
#endif    

    //debias
    if(s1 != s2){
      return s1;
    }
  }
  PANIC(PANIC_RNG_FAIL_DEBIAS);
#else
  return getSampleImpl();
#endif
}

const int rounds = 50;
const int n=8*rounds*32;

bool generateimpl(uint8_t data[32]){
#ifdef NIST_RNG_VERIFY
  uint8_t last=0;  
  int p=0;
  int v=0;
#endif

  for( uint8_t r = 0; r < rounds ; r++){
    PROGRESS((float)r/(float)rounds);
    for( uint8_t i = 0; i < 32 ; i++ ){
      for(uint8_t bit=0;bit<8;bit++){
        uint8_t s = getSample();
//  char msg[32];
//  sprintf(msg,"FLIP %d\r\n",s);
//  serialprint(msg);

        if(data!=NULL){
          data[i] ^= (s<<bit);
        }
#ifdef NIST_RNG_VERIFY
        if( s==1 ){
          p++;
        }
        if(s!=last){
          v++;
          last=s;
        }
#endif
      }
    }
  }

#ifdef NIST_RNG_VERIFY

  float rootn = sqrt(n);
  float roottwo = sqrt(2);

  float freq = abs(n-(p<<1));

  float sobs = freq/rootn;
  float Pfreq = sobs/roottwo;

  if(Pfreq>1.82139){
    serialprint("FAIL FREQ");
#ifdef DEBUG
    char out[5];
    itoa(p,out,10);
    DBGPRINT(out);

    DBGPRINT("FAIL FREQ");
#endif
    return false;
  } else {
#ifdef NIST_RUN_RNG_VERIFY
    float pi = (float)p/n;
    float twonpi=2.0*n*pi;
    float tworoottwonpi=2.0*sqrt(2.0*n)*pi;

    float ompi = 1.0-pi;
    float Prun = abs(((float)v-twonpi*(ompi)))/(tworoottwonpi*ompi);

    //char msg[32];
    //sprintf(msg,"PRUN %f\r\n",Prun);
    //serialprint(msg);
  

    if(Prun>1.82139){
      serialprint("FAIL RUN");

#ifdef DEBUG
    DBGPRINT("FAIL RUN");
#endif
      return false;
    }
#endif
  }
#endif
  return true;
}

void rng::generate(uint8_t data[32]){

  bool pass = generateimpl(data);
#ifdef NIST_RNG_VERIFY

  //If the value looks non random check 10 more times to ensure the random number generator is still functioning
  if( !pass ){
    uint8_t failcount=0;
    for(uint8_t i=0;i<10;i++){      
      serialprint("CHECKRNG");
#ifdef DEBUG
      DBGPRINT("CHECK RNG");
#endif
      if(!generateimpl(NULL)){
        failcount++;
        //10% chance of seeing a failure in 10 samples
        if(failcount>2){
          PANIC(PANIC_RNG_FAIL_NIST);
        }
      }
    }
  }
#endif
}
