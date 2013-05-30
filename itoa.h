#ifndef ITOA_H
#define ITOA_H

#include <stdint.h>

#ifdef __cplusplus
#define EXTERNC extern "C"
#else
#define EXTERNC
#endif

EXTERNC void my_itoa(uint32_t i,char *buf,int limit);

#endif
