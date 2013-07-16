/** \file main.c
 * \brief Sample LPC1114 project
 * \details This file holds a very basic code for LPC1114. This code configures
 * flash access time, enables the PLL and all required clocks and peripherals
 * to achieve the highest allowed frequency for LPC1114 (50MHz). Main code
 * block just blinks the LED. The LED port and pin are defined in config.h
 * file. Target core frequency and quartz crystal resonator frequency are
 * defined there as well.
 *
 * \author Freddie Chopin, http://www.freddiechopin.info/
 * \date 2012-01-08
 */

/******************************************************************************
* project: lpc1114_blink_led
* chip: LPC1114
* compiler: arm-none-eabi-gcc (Sourcery CodeBench Lite 2011.09-69) 4.6.1
*
* prefix: (none)
*
* available global functions:
* 	int main(void)
*
* available local functions:
* 	static void flash_access_time(uint32_t frequency)
* 	static uint32_t pll_start(uint32_t crystal, uint32_t frequency)
* 	static void system_init(void)
*
* available interrupt handlers:
******************************************************************************/

/*
+=============================================================================+
| includes
+=============================================================================+
*/

#include <stdint.h>

#include "inc/LPC11xx.h"

#include "config.h"

#include "hdr/hdr_syscon.h"

#include <test.h>
#include <panic.h>
#include <itoa.h>
#include <serial.h>
#include <checksum.h>

#define BUTTON_GPIO							LPC_GPIO2	///< GPIO port to which the LED is connected
#define BUTTON_pin								6			///< pin number of the LED
#define BUTTON									(1 << BUTTON_pin)

/// "variable" to manipulate the pin directly via GPIO masked access
#define BUTTON_gma								gpio_masked_access_t GPIO_MASKED_ACCESS(BUTTON_GPIO, BUTTON_pin)


void PROGRESS(float p){
  //serialprint(".");
	LED_gma ^= LED;
}

void PANIC(paniccode errorCode){
  serialprint("PANIC ");
  char buf[2];
  buf[0]=errorCode+64;
  buf[1]=0;
  serialprint(buf);
  serialprint("\r\n");

  volatile uint32_t count, count_max = 100000;

	while (1)
	{
		for (count = 0; count < count_max; count++);	// delay
		LED_gma = LED;						// instead of LED_GPIO->DATA |= LED;
		for (count = 0; count < count_max; count++);	// delay
		LED_gma = 0;						// instead of LED_GPIO->DATA &= ~LED;
	}}

void FAIL(const char *msg){

  serialprint("FAIL ");
  serialprint(msg);

  volatile uint32_t count, count_max = 200000;

	while (1)
	{
		for (count = 0; count < count_max; count++);	// delay
		LED_gma = LED;						// instead of LED_GPIO->DATA |= LED;
		for (count = 0; count < count_max; count++);	// delay
		LED_gma = 0;						// instead of LED_GPIO->DATA &= ~LED;
	}
}


/*
+=============================================================================+
| module variables
+=============================================================================+
*/

/*
+=============================================================================+
| local functions' declarations
+=============================================================================+
*/

static void flash_access_time(uint32_t frequency);
static uint32_t pll_start(uint32_t crystal, uint32_t frequency);
static void system_init(void);

/*
+=============================================================================+
| global functions
+=============================================================================+
*/

/*------------------------------------------------------------------------*//**
* \brief main code block
* \details Call some static initialization functions and blink the led with
* frequency defined via count_max variable.
*//*-------------------------------------------------------------------------*/

#define ADC_NUM 8 /* for LPC11xx */
#define ADC_CLK 4500000 /* set to 4.5Mhz */
#define ADC_OFFSET 0x10
#define ADC_INDEX 4

#define ADC_DONE 0x80000000
#define ADC_OVERRUN 0x40000000

int adcinit(){
  uint32_t ADC_Clk = ADC_CLK;
  uint32_t i;

  /* Disable Power down bit to the ADC block. */
  LPC_SYSCON->PDRUNCFG &= ~(0x1<<4);

  /* Enable AHB clock to the ADC. */
  LPC_SYSCON->SYSAHBCLKCTRL |= (1<<13);

  /* Unlike some other pings, for ADC test, all the pins need
to set to analog mode. Bit 7 needs to be cleared according
to design team. */
  LPC_IOCON->R_PIO1_2 &= ~0x8F; /* ADC I/O config */
  LPC_IOCON->R_PIO1_2 |= 0x01; /* ADC IN0 */
  LPC_IOCON->PIO1_11 &= ~0x8F; /* ADC I/O config */
  LPC_IOCON->PIO1_11 |= 0x01; /* ADC IN1 */

  LPC_ADC->CR = ((48000000UL/LPC_SYSCON->SYSAHBCLKDIV)/ADC_Clk-1)<<8;

  return;
}

#define tickring 128
int ticks[tickring];
int tickpos=0;

void recordTick(int val){
  ticks[tickpos]=val;
  tickpos++;
  if(tickpos>tickring){
    tickpos=0;
  }
}

uint32_t adcread( uint8_t channelNum )
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

void printticks(){
  int i;
  char buf[10];
  for(i=0;i<tickring;i++){
    int tp = tickpos+i;
    tp%=tickring;
    my_itoa(ticks[tp],buf,10);
    serialprint("tick = ");
    serialprint(buf);
    serialprint("\n");
  }
}

void goadc(){
  for(;;){
    char buf[10];
    uint32_t val;

    val = adcread(3); 
    my_itoa(val,buf,10);
    serialprint("AD3 = ");
    serialprint(buf);
    serialprint("\n");
  }
}

#define RDET_GPIO							LPC_GPIO0	///< GPIO port to which the LED is connected
#define RDET_pin								5			///< pin number of the LED
#define RDET									(1 << RDET_pin)

/// "variable" to manipulate the pin directly via GPIO masked access
#define RDET_gma								gpio_masked_access_t GPIO_MASKED_ACCESS(RDET_GPIO, RDET_pin)

int main(void)
{
  int q;
	volatile uint32_t count, count_max = 1000000;//1000000;	// with core frequency ~50MHz this gives ~1.5Hz blinking frequency

	pll_start(CRYSTAL, FREQUENCY);			// start the PLL
	system_init();							// initialize other necessary elements
  //Configure for GPIO
  serialinit();
  if( !verifyChecksum() ){
    PANIC(PANIC_FLASH_CRC_MISMATCH);
  }
  initprinter();

  adcinit();

	LED_GPIO->DIR |= LED;					// set the direction of the LED pin to output
	BUTTON_GPIO->DIR &= ~BUTTON;					// set the direction of the Button pin to input
  MOTOR_GPIO->DIR |= MOTOR;
  MOTOR_gma=0;


//    testBigNat();
//    testBigInt();
//    testBitElliptic();
//  goadc();

//    testbitaddress();

/*
  while (1)
  	{
      serialprint("\r\nLOOP");
      LED_gma = LED;						// instead of LED_GPIO->DATA &= ~LED;
      for (count = 0; count < count_max; count++);	// delay
      LED_gma = 0;						// instead of LED_GPIO->DATA |= LED;

//      for(q=0;q<12;q++){
//        serialprint(".");
        LPC_GPIO0->DATA = 0xFFFFFF;
        LPC_GPIO1->DATA = 0xFFFFFF;
        LPC_GPIO2->DATA = 0xFFFFFF;
        LPC_GPIO3->DATA = 0xFFFFFF;
  		  for (count = 0; count < count_max; count++);	// delay
        LPC_GPIO0->DATA = 0;
        LPC_GPIO1->DATA = 0;
        LPC_GPIO2->DATA = 0;
        LPC_GPIO3->DATA = 0;
      //}
    }

*/
	while (1)
	{
    serialprint("BEGIN\n");

    LED_gma = LED;

    //testbitaddress();


    while((BUTTON_gma & BUTTON) == 0){}

    serialprint("go\n");

  //	while (1)
  //	{
  //    LED_gma = 0;						// instead of LED_GPIO->DATA &= ~LED;
  //    for (count = 0; count < count_max; count++);	// delay
  //    LED_gma = LED;						// instead of LED_GPIO->DATA |= LED;

  //    for(q=0;q<12;q++){
  //      LPC_GPIO0->DATA = 1<<q;
  //      LPC_GPIO1->DATA = 1<<q;

  //      LPC_GPIO0->DATA |= 1<<10;
  //      MOTOR_gma=MOTOR;
  //		  for (count = 0; count < count_max; count++);	// delay
  //      LPC_GPIO0->DATA &= ~(1<<10);
  //      MOTOR_gma=0;
  //		  for (count = 0; count < count_max; count++);	// delay
  //    }
  //  }

    serialprint("print\n");
  //  m190test();
    printpaperwallet();  

    printticks();
  //  testBigNat();
  //  testBigInt();
  //  testBitElliptic();
  //  testbitaddress();

    serialprint("done\n");


	}
}

/*
+=============================================================================+
| local functions
+=============================================================================+
*/

/*------------------------------------------------------------------------*//**
* \brief Configures flash access time.
* \details Configures flash access time which allows the chip to run at higher
* speeds.
*
* \param [in] frequency defines the target frequency of the core
*//*-------------------------------------------------------------------------*/

static void flash_access_time(uint32_t frequency)
{
	uint32_t access_time, flashcfg_register;

	if (frequency < 20000000ul)				// 1 system clock for core speed below 20MHz
		access_time = FLASHCFG_FLASHTIM_1CLK;
	else if (frequency < 40000000ul)		// 2 system clocks for core speed between 20MHz and 40MHz
		access_time = FLASHCFG_FLASHTIM_2CLK;
	else									// 3 system clocks for core speed over 40MHz
		access_time = FLASHCFG_FLASHTIM_3CLK;

	// do not modify reserved bits in FLASHCFG register
	flashcfg_register = FLASHCFG;			// read register
	flashcfg_register &= ~(FLASHCFG_FLASHTIM_mask << FLASHCFG_FLASHTIM_bit);	// mask the FLASHTIM field
	flashcfg_register |= access_time << FLASHCFG_FLASHTIM_bit;	// use new FLASHTIM value
	FLASHCFG = flashcfg_register;			// save the new value back to the register
}

/*------------------------------------------------------------------------*//**
* \brief Starts the PLL.
* \details Configure and enable PLL to achieve some frequency with some
* crystal. Before the speed change flash access time is configured via
* flash_access_time(). Main oscillator is configured and started. PLL
* parameters m and p are based on function parameters. The PLL is configured,
* started and selected as the main clock. AHB clock divider is set to 1.
*
* \param [in] crystal is the frequency of the crystal resonator connected to
* the LPC1114 chip.
* \param [in] frequency is the desired target frequency after enabling the PLL
*
* \return real frequency that was set
*//*-------------------------------------------------------------------------*/

static uint32_t pll_start(uint32_t crystal, uint32_t frequency)
{
	uint32_t m, p = 0, fcco;

	flash_access_time(frequency);			// configure flash access time first

	// SYSOSCCTRL_FREQRANGE should be 0 for crystals in range 1 - 20MHz
	// SYSOSCCTRL_FREQRANGE should be 1 for crystals in range 15 - 25MHz
	if (crystal < 17500000)					// divide the ranges on 17.5MHz then
		LPC_SYSCON->SYSOSCCTRL = 0;			// "lower speed" crystals
	else
		LPC_SYSCON->SYSOSCCTRL = SYSOSCCTRL_FREQRANGE;	// "higher speed" crystals

	LPC_SYSCON->PDRUNCFG &= ~PDRUNCFG_SYSOSC_PD;	// power-up main oscillator

	LPC_SYSCON->SYSPLLCLKSEL = SYSPLLCLKSEL_SEL_IRC;	// select main oscillator as the input clock for PLL
	LPC_SYSCON->SYSPLLCLKUEN = 0;			// confirm the change of PLL input clock by toggling the...
	LPC_SYSCON->SYSPLLCLKUEN = SYSPLLUEN_ENA;	// ...ENA bit in LPC_SYSCON->SYSPLLCLKUEN register

	// calculate PLL parameters
	m = frequency / crystal;				// M is the PLL multiplier
	fcco = m * crystal * 2;					// FCCO is the internal PLL frequency

	frequency = crystal * m;

	while (fcco < 156000000)
	{
		fcco *= 2;
		p++;								// find P which gives FCCO in the allowed range (over 156MHz)
	}

	LPC_SYSCON->SYSPLLCTRL = ((m - 1) << SYSPLLCTRL_MSEL_bit) | (p << SYSPLLCTRL_PSEL_bit);	// configure PLL
	LPC_SYSCON->PDRUNCFG &= ~PDRUNCFG_SYSPLL_PD; // power-up PLL

	while (!(LPC_SYSCON->SYSPLLSTAT & SYSPLLSTAT_LOCK));	// wait for PLL lock

	LPC_SYSCON->MAINCLKSEL = MAINCLKSEL_SEL_PLLOUT;	// select PLL output as the main clock
	LPC_SYSCON->MAINCLKUEN = 0;				// confirm the change of main clock by toggling the...
	LPC_SYSCON->MAINCLKUEN = MAINCLKUEN_ENA;	// ...ENA bit in LPC_SYSCON->MAINCLKUEN register

	LPC_SYSCON->SYSAHBCLKDIV = 1;			// set AHB clock divider to 1

	return frequency;
}

/*------------------------------------------------------------------------*//**
* \brief Initializes system.
* \details Enables clock for IO configuration block.
*//*-------------------------------------------------------------------------*/

static void system_init(void)
{
	LPC_SYSCON->SYSAHBCLKCTRL |= SYSAHBCLKCTRL_IOCON;	// enable clock for IO configuration block
}

/*
+=============================================================================+
| ISRs
+=============================================================================+
*/

/******************************************************************************
* END OF FILE
******************************************************************************/
