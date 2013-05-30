/** \file vectors.c
 * \brief LPC11xx vector table and __Default_Handler()
 * \details LPC11xx vector table and __Default_Handler()
 * \author Freddie Chopin, http://www.freddiechopin.info/
 * \date 2012-01-08
 */

/******************************************************************************
* chip: LPC11xx
* compiler: arm-none-eabi-gcc (Sourcery CodeBench Lite 2011.09-69) 4.6.1
******************************************************************************/

/*------------------------------------------------------------------------*//**
* \brief Default interrupt handler.
* \details Default interrupt handler, used for interrupts that don't have their
* own handler defined.
*//*-------------------------------------------------------------------------*/

static void __Default_Handler(void) __attribute__ ((interrupt));
static void __Default_Handler(void)
{
	while (1);
}

/*
+=============================================================================+
| assign all unhandled interrupts to the default handler
+=============================================================================+
*/

// Reserved 0x08
void __Reserved_0x08_Handler(void) __attribute__ ((interrupt, weak, alias("__Default_Handler")));

// All class of fault
void HardFault_Handler(void) __attribute__ ((interrupt, weak, alias("__Default_Handler")));

// Reserved 0x10
void __Reserved_0x10_Handler(void) __attribute__ ((interrupt, weak, alias("__Default_Handler")));

// Reserved 0x14
void __Reserved_0x14_Handler(void) __attribute__ ((interrupt, weak, alias("__Default_Handler")));

// Reserved 0x18
void __Reserved_0x18_Handler(void) __attribute__ ((interrupt, weak, alias("__Default_Handler")));

// Reserved 0x1C
void __Reserved_0x1C_Handler(void) __attribute__ ((interrupt, weak, alias("__Default_Handler")));

// Reserved 0x20
void __Reserved_0x20_Handler(void) __attribute__ ((interrupt, weak, alias("__Default_Handler")));

// Reserved 0x24
void __Reserved_0x24_Handler(void) __attribute__ ((interrupt, weak, alias("__Default_Handler")));

// Reserved 0x28
void __Reserved_0x28_Handler(void) __attribute__ ((interrupt, weak, alias("__Default_Handler")));

// System service call via SWI instruction
void SVC_Handler(void) __attribute__ ((interrupt, weak, alias("__Default_Handler")));

// Reserved 0x30
void __Reserved_0x30_Handler(void) __attribute__ ((interrupt, weak, alias("__Default_Handler")));

// Reserved 0x34
void __Reserved_0x34_Handler(void) __attribute__ ((interrupt, weak, alias("__Default_Handler")));

// Pendable request for system service
void PendSV_Handler(void) __attribute__ ((interrupt, weak, alias("__Default_Handler")));

// System tick timer
void SysTick_Handler(void) __attribute__ ((interrupt, weak, alias("__Default_Handler")));

// Start logic wake-up from PIO0_0 interrupt
void WAKEUP_PIO0_0_IRQHandler(void) __attribute__ ((interrupt, weak, alias("__Default_Handler")));

// Start logic wake-up from PIO0_1 interrupt
void WAKEUP_PIO0_1_IRQHandler(void) __attribute__ ((interrupt, weak, alias("__Default_Handler")));

// Start logic wake-up from PIO0_2 interrupt
void WAKEUP_PIO0_2_IRQHandler(void) __attribute__ ((interrupt, weak, alias("__Default_Handler")));

// Start logic wake-up from PIO0_3 interrupt
void WAKEUP_PIO0_3_IRQHandler(void) __attribute__ ((interrupt, weak, alias("__Default_Handler")));

// Start logic wake-up from PIO0_4 interrupt
void WAKEUP_PIO0_4_IRQHandler(void) __attribute__ ((interrupt, weak, alias("__Default_Handler")));

// Start logic wake-up from PIO0_5 interrupt
void WAKEUP_PIO0_5_IRQHandler(void) __attribute__ ((interrupt, weak, alias("__Default_Handler")));

// Start logic wake-up from PIO0_6 interrupt
void WAKEUP_PIO0_6_IRQHandler(void) __attribute__ ((interrupt, weak, alias("__Default_Handler")));

// Start logic wake-up from PIO0_7 interrupt
void WAKEUP_PIO0_7_IRQHandler(void) __attribute__ ((interrupt, weak, alias("__Default_Handler")));

// Start logic wake-up from PIO0_8 interrupt
void WAKEUP_PIO0_8_IRQHandler(void) __attribute__ ((interrupt, weak, alias("__Default_Handler")));

// Start logic wake-up from PIO0_9 interrupt
void WAKEUP_PIO0_9_IRQHandler(void) __attribute__ ((interrupt, weak, alias("__Default_Handler")));

// Start logic wake-up from PIO0_10 interrupt
void WAKEUP_PIO0_10_IRQHandler(void) __attribute__ ((interrupt, weak, alias("__Default_Handler")));

// Start logic wake-up from PIO0_11 interrupt
void WAKEUP_PIO0_11_IRQHandler(void) __attribute__ ((interrupt, weak, alias("__Default_Handler")));

// Start logic wake-up from PIO1_0 interrupt
void WAKEUP_PIO1_0_IRQHandler(void) __attribute__ ((interrupt, weak, alias("__Default_Handler")));

// C_CAN interrupt (LPC11C12/C14 only)
void CAN_IRQHandler(void) __attribute__ ((interrupt, weak, alias("__Default_Handler")));

// SPI/SSP1 interrupt
void SSP1_IRQHandler(void) __attribute__ ((interrupt, weak, alias("__Default_Handler")));

// I2C interrupt
void I2C_IRQHandler(void) __attribute__ ((interrupt, weak, alias("__Default_Handler")));

// CT16B0 (16-bit Timer0) interrupt
void TIMER16_0_IRQHandler(void) __attribute__ ((interrupt, weak, alias("__Default_Handler")));

// CT16B1 (16-bit Timer1) interrupt
void TIMER16_1_IRQHandler(void) __attribute__ ((interrupt, weak, alias("__Default_Handler")));

// CT32B0 (32-bit Timer0) interrupt
void TIMER32_0_IRQHandler(void) __attribute__ ((interrupt, weak, alias("__Default_Handler")));

// CT32B1 (32-bit Timer1) interrupt
void TIMER32_1_IRQHandler(void) __attribute__ ((interrupt, weak, alias("__Default_Handler")));

// SPI/SSP0 interrupt
void SSP0_IRQHandler(void) __attribute__ ((interrupt, weak, alias("__Default_Handler")));

// UART interrupt
void UART_IRQHandler(void) __attribute__ ((interrupt, weak, alias("__Default_Handler")));

// Reserved 0x98
void __Reserved_0x98_Handler(void) __attribute__ ((interrupt, weak, alias("__Default_Handler")));

// Reserved 0x9C
void __Reserved_0x9C_Handler(void) __attribute__ ((interrupt, weak, alias("__Default_Handler")));

// A/D Converter interrupt
void ADC_IRQHandler(void) __attribute__ ((interrupt, weak, alias("__Default_Handler")));

// Watchdog timer interrupt
void WDT_IRQHandler(void) __attribute__ ((interrupt, weak, alias("__Default_Handler")));

// Brown Out Detect interrupt
void BOD_IRQHandler(void) __attribute__ ((interrupt, weak, alias("__Default_Handler")));

// Reserved 0xAC
void __Reserved_0xAC_Handler(void) __attribute__ ((interrupt, weak, alias("__Default_Handler")));

// PIO INT3 interrupt
void PIOINT3_IRQHandler(void) __attribute__ ((interrupt, weak, alias("__Default_Handler")));

// PIO INT2 interrupt
void PIOINT2_IRQHandler(void) __attribute__ ((interrupt, weak, alias("__Default_Handler")));

// PIO INT1 interrupt
void PIOINT1_IRQHandler(void) __attribute__ ((interrupt, weak, alias("__Default_Handler")));

// PIO INT0 interrupt
void PIOINT0_IRQHandler(void) __attribute__ ((interrupt, weak, alias("__Default_Handler")));

/*
+=============================================================================+
| Vector table
+=============================================================================+
*/

extern const char __main_stack_end;			// imported main stack end (from linker script)

void Reset_Handler(void);					// import the address of Reset_Handler()

void (* const vectors[])(void) __attribute__ ((section(".vectors"))) = {
		(void (*)(void))&__main_stack_end,	// Main stack end address
		Reset_Handler,						// Reset
		__Reserved_0x08_Handler,			// Reserved 0x08
		HardFault_Handler,					// All class of fault
		__Reserved_0x10_Handler,			// Reserved 0x10
		__Reserved_0x14_Handler,			// Reserved 0x14
		__Reserved_0x18_Handler,			// Reserved 0x18
		__Reserved_0x1C_Handler,			// Reserved 0x1C
		__Reserved_0x20_Handler,			// Reserved 0x20
		__Reserved_0x24_Handler,			// Reserved 0x24
		__Reserved_0x28_Handler,			// Reserved 0x28
		SVC_Handler,						// System service call via SWI instruction
		__Reserved_0x30_Handler,			// Reserved 0x30
		__Reserved_0x34_Handler,			// Reserved 0x34
		PendSV_Handler,						// Pendable request for system service
		SysTick_Handler,					// System tick timer
		WAKEUP_PIO0_0_IRQHandler,			// Start logic wake-up from PIO0_0 interrupt
		WAKEUP_PIO0_1_IRQHandler,			// Start logic wake-up from PIO0_1 interrupt
		WAKEUP_PIO0_2_IRQHandler,			// Start logic wake-up from PIO0_2 interrupt
		WAKEUP_PIO0_3_IRQHandler,			// Start logic wake-up from PIO0_3 interrupt
		WAKEUP_PIO0_4_IRQHandler,			// Start logic wake-up from PIO0_4 interrupt
		WAKEUP_PIO0_5_IRQHandler,			// Start logic wake-up from PIO0_5 interrupt
		WAKEUP_PIO0_6_IRQHandler,			// Start logic wake-up from PIO0_6 interrupt
		WAKEUP_PIO0_7_IRQHandler,			// Start logic wake-up from PIO0_7 interrupt
		WAKEUP_PIO0_8_IRQHandler,			// Start logic wake-up from PIO0_8 interrupt
		WAKEUP_PIO0_9_IRQHandler,			// Start logic wake-up from PIO0_9 interrupt
		WAKEUP_PIO0_10_IRQHandler,			// Start logic wake-up from PIO0_10 interrupt
		WAKEUP_PIO0_11_IRQHandler,			// Start logic wake-up from PIO0_11 interrupt
		WAKEUP_PIO1_0_IRQHandler,			// Start logic wake-up from PIO1_0 interrupt
		CAN_IRQHandler,						// C_CAN interrupt (LPC11C12/C14 only)
		SSP1_IRQHandler,					// SPI/SSP1 interrupt
		I2C_IRQHandler,						// I2C interrupt
		TIMER16_0_IRQHandler,				// CT16B0 (16-bit Timer0) interrupt
		TIMER16_1_IRQHandler,				// CT16B1 (16-bit Timer1) interrupt
		TIMER32_0_IRQHandler,				// CT32B0 (32-bit Timer0) interrupt
		TIMER32_1_IRQHandler,				// CT32B1 (32-bit Timer1) interrupt
		SSP0_IRQHandler,					// SPI/SSP0 interrupt
		UART_IRQHandler,					// UART interrupt
		__Reserved_0x98_Handler,			// Reserved 0x98
		__Reserved_0x9C_Handler,			// Reserved 0x9C
		ADC_IRQHandler,						// A/D Converter interrupt
		WDT_IRQHandler,						// Watchdog timer interrupt
		BOD_IRQHandler,						// Brown Out Detect interrupt
		__Reserved_0xAC_Handler,			// Reserved 0xAC
		PIOINT3_IRQHandler,					// PIO INT3 interrupt
		PIOINT2_IRQHandler,					// PIO INT2 interrupt
		PIOINT1_IRQHandler,					// PIO INT1 interrupt
		PIOINT0_IRQHandler,					// PIO INT0 interrupt
};

/******************************************************************************
* END OF FILE
******************************************************************************/
