#ifndef WATCHDOG_H
#define WATCHDOG_H

#ifdef __cplusplus
#define EXTERNC extern "C"
#else
#define EXTERNC
#endif

EXTERNC int Watchdog_Init();
EXTERNC void Watchdog_Feed();

#endif
