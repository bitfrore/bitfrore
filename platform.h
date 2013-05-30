#ifndef PLATFORM_H
#define PLATFORM_H

//#include <Arduino.h>

#include <stdint.h>

#define PROGMEM
#define pgm_read_byte(x)        (*((const char *)x))
#define pgm_read_dword(x)        (*((const unsigned long *)x))
typedef const char* fstring;

#define PSTR(x)  x
#if defined F
#undef F
#endif
#define F(X) (X)
#define memcpy_P(dest, src, num) memcpy((dest), (src), (num)) 

#endif
