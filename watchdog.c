#include <watchdog.h>
#include "inc/LPC11xx.h"

void Watchdog_Feed(){
  /*
  ** Send watchdog "feed" sequence- final step to begin the timeout
  */
  __disable_irq();
  LPC_WDT->FEED = 0xAA;
  LPC_WDT->FEED = 0x55;
  __enable_irq();
}

int Watchdog_Init(void) {
  int reset=0;
  /*
  ** Make sure WDT config clock is turned on
  */
  LPC_SYSCON->SYSAHBCLKCTRL |= 0x08000;

  /*
  ** Enable internal RC clock
  */
  LPC_SYSCON->PDRUNCFG &= ~(1);

  /*
  ** Select internal RC for watchdog
  */
  LPC_SYSCON->WDTCLKSEL = 0;

  /*
  ** Toggle WDTCLKUEN to latch clock selection
  */
  LPC_SYSCON->WDTCLKUEN = 0;
  LPC_SYSCON->WDTCLKUEN = 1;

  /*
  ** We are using the internal RC clock to drive the watchdog because it is
  ** independent of PLL settings. The "System Clock" option routes the clock
  ** after the PLL to the watchdog. The "System Clock" could vary depending
  ** on what CPU speed is configured with the PLL.
  */

  /*
  ** Set watchdog counter value to timeout 50 ms
  */
  LPC_WDT->TC = (unsigned int) (((unsigned int) 12000000/4)/1000) * (unsigned int) 1000;

  /*
  ** Set up watchdog clock "divide" by one (default state is gated off)
  */
  LPC_SYSCON->WDTCLKDIV = 1;

  //return previous state of watchdog reset
  reset = LPC_WDT->MOD & (1<<2);

  /*
  ** Enable watchdog, and arm it to generate a reset upon timeout
  */
  LPC_WDT->MOD = 0x03;

  Watchdog_Feed();

  return reset;
}
