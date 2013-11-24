#ifndef PANIC_H
#define PANIC_H
// Copyright 2013 Steven Pearson
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file.

typedef unsigned char paniccode;

const paniccode PANIC_UNKNOWN_ERROR=1; //A
const paniccode PANIC_NAT_MAKE_OVERFLOW=2; //B
const paniccode PANIC_NAT_SUB_UNDERFLOW=3; //C
const paniccode PANIC_NAT_SUB_CNONZERO=4; //D
const paniccode PANIC_NAT_TOWORD_OVERFLOW=5; //E
const paniccode PANIC_NAT_DIVZERO=6; //F
const paniccode PANIC_NAT_TOSTRING_OVERFLOW=7; //G
const paniccode PANIC_NAT_MUL_ALIAS=8; //H
const paniccode PANIC_NAT_DIV_ALIAS=9; //I
const paniccode PANIC_NAT_DIV_SHIFTOFF=10; //J
const paniccode PANIC_INT_MOD_ALIAS=11; //K
const paniccode PANIC_RMD160_SUM_NXNOTZERO=12; //L
const paniccode PANIC_BITADDRESS_PK_NOTONCURVE=13; //M
const paniccode PANIC_NAT_BYTES_OVERFLOW=14; //N
const paniccode PANIC_RNG_FAIL_DEBIAS=15; //O
const paniccode PANIC_RNG_FAIL_NIST=16; //P
const paniccode PANIC_NAT_SET_ALIAS=17; //Q
const paniccode PANIC_NAT_POTENTIAL_OVERFLOW=18; //R
const paniccode PANIC_FLASH_CRC_MISMATCH=19; //S
const paniccode PANIC_WATCHDOG=20; //T
const paniccode PANIC_RNG_MEMCMP=21; //U
const paniccode PANIC_BITADDRESS_DOUBLECHECK=22; //V
const paniccode PANIC_PRINT_OVERTICK=23; //W
const paniccode PANIC_MEMTEST=24; //X
const paniccode PANIC_BITADDRESS_PK_OUTOFRANGE=25; //Y

#ifdef __cplusplus
#define EXTERNC extern "C"
#else
#define EXTERNC
#endif

EXTERNC void PANIC(paniccode p);
EXTERNC void FAIL(const char *m);

#endif

