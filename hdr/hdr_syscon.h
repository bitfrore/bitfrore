/** \file hdr_syscon.h
 * \brief Header with definition of bits in system configuration registers
 * \author Freddie Chopin, http://www.freddiechopin.info/
 * \date 2012-01-08
 */

/******************************************************************************
* chip: LPC11xx
* compiler: arm-none-eabi-gcc (Sourcery CodeBench Lite 2011.09-69) 4.6.1
******************************************************************************/

#ifndef HDR_SYSCON_H_
#define HDR_SYSCON_H_

/*
+-----------------------------------------------------------------------------+
| SYSMEMREMAP - System memory remap register
+-----------------------------------------------------------------------------+
*/

#define SYSMEMREMAP_MAP_bit					0
#define SYSMEMREMAP_MAP_0_bit				0
#define SYSMEMREMAP_MAP_1_bit				1

#define SYSMEMREMAP_MAP_0					(1 << SYSMEMREMAP_MAP_0_bit)
#define SYSMEMREMAP_MAP_1					(1 << SYSMEMREMAP_MAP_1_bit)

#define SYSMEMREMAP_MAP_BOOT_value			0
#define SYSMEMREMAP_MAP_RAM_value			1
#define SYSMEMREMAP_MAP_FLASH_value			2
#define SYSMEMREMAP_MAP_mask				3

#define SYSMEMREMAP_MAP_BOOT				(SYSMEMREMAP_MAP_BOOT_value << SYSMEMREMAP_MAP_bit)
#define SYSMEMREMAP_MAP_RAM					(SYSMEMREMAP_MAP_RAM_value << SYSMEMREMAP_MAP_bit)
#define SYSMEMREMAP_MAP_FLASH				(SYSMEMREMAP_MAP_FLASH_value << SYSMEMREMAP_MAP_bit)

/*
+-----------------------------------------------------------------------------+
| PRESETCTRL - Peripheral reset control register
+-----------------------------------------------------------------------------+
*/

#define PRESETCTRL_SSP0_RST_N_bit			0
#define PRESETCTRL_I2C_RST_N_bit			1
#define PRESETCTRL_SSP1_RST_N_bit			2
#define PRESETCTRL_CAN_RST_N_bit			3

#define PRESETCTRL_SSP0_RST_N				(1 << PRESETCTRL_SSP0_RST_N_bit)
#define PRESETCTRL_I2C_RST_N				(1 << PRESETCTRL_I2C_RST_N_bit)
#define PRESETCTRL_SSP1_RST_N				(1 << PRESETCTRL_SSP1_RST_N_bit)
#define PRESETCTRL_CAN_RST_N				(1 << PRESETCTRL_CAN_RST_N_bit)

/*
+-----------------------------------------------------------------------------+
| SYSPLLCTRL - System PLL control register
+-----------------------------------------------------------------------------+
*/

#define SYSPLLCTRL_MSEL_bit					0
#define SYSPLLCTRL_MSEL_0_bit				0
#define SYSPLLCTRL_MSEL_1_bit				1
#define SYSPLLCTRL_MSEL_2_bit				2
#define SYSPLLCTRL_MSEL_3_bit				3
#define SYSPLLCTRL_MSEL_4_bit				4
#define SYSPLLCTRL_PSEL_bit					5
#define SYSPLLCTRL_PSEL_0_bit				5
#define SYSPLLCTRL_PSEL_1_bit				6

#define SYSPLLCTRL_MSEL_0					(1 << SYSPLLCTRL_MSEL_0_bit)
#define SYSPLLCTRL_MSEL_1					(1 << SYSPLLCTRL_MSEL_1_bit)
#define SYSPLLCTRL_MSEL_2					(1 << SYSPLLCTRL_MSEL_2_bit)
#define SYSPLLCTRL_MSEL_3					(1 << SYSPLLCTRL_MSEL_3_bit)
#define SYSPLLCTRL_MSEL_4					(1 << SYSPLLCTRL_MSEL_4_bit)
#define SYSPLLCTRL_PSEL_0					(1 << SYSPLLCTRL_PSEL_0_bit)
#define SYSPLLCTRL_PSEL_1					(1 << SYSPLLCTRL_PSEL_1_bit)

#define SYSPLLCTRL_MSEL_1_value				0
#define SYSPLLCTRL_MSEL_2_value				1
#define SYSPLLCTRL_MSEL_3_value				2
#define SYSPLLCTRL_MSEL_4_value				3
#define SYSPLLCTRL_MSEL_5_value				4
#define SYSPLLCTRL_MSEL_6_value				5
#define SYSPLLCTRL_MSEL_7_value				6
#define SYSPLLCTRL_MSEL_8_value				7
#define SYSPLLCTRL_MSEL_9_value				8
#define SYSPLLCTRL_MSEL_10_value			9
#define SYSPLLCTRL_MSEL_11_value			10
#define SYSPLLCTRL_MSEL_12_value			11
#define SYSPLLCTRL_MSEL_13_value			12
#define SYSPLLCTRL_MSEL_14_value			13
#define SYSPLLCTRL_MSEL_15_value			14
#define SYSPLLCTRL_MSEL_16_value			15
#define SYSPLLCTRL_MSEL_17_value			16
#define SYSPLLCTRL_MSEL_18_value			17
#define SYSPLLCTRL_MSEL_19_value			18
#define SYSPLLCTRL_MSEL_20_value			19
#define SYSPLLCTRL_MSEL_21_value			20
#define SYSPLLCTRL_MSEL_22_value			21
#define SYSPLLCTRL_MSEL_23_value			22
#define SYSPLLCTRL_MSEL_24_value			23
#define SYSPLLCTRL_MSEL_25_value			24
#define SYSPLLCTRL_MSEL_26_value			25
#define SYSPLLCTRL_MSEL_27_value			26
#define SYSPLLCTRL_MSEL_28_value			27
#define SYSPLLCTRL_MSEL_29_value			28
#define SYSPLLCTRL_MSEL_30_value			29
#define SYSPLLCTRL_MSEL_31_value			30
#define SYSPLLCTRL_MSEL_32_value			31
#define SYSPLLCTRL_MSEL_mask				31

#define SYSPLLCTRL_PSEL_1_value				0
#define SYSPLLCTRL_PSEL_2_value				1
#define SYSPLLCTRL_PSEL_4_value				2
#define SYSPLLCTRL_PSEL_8_value				3
#define SYSPLLCTRL_PSEL_mask				3

// underscores removed to avoid redefinition

#define SYSPLLCTRL_MSEL1					(SYSPLLCTRL_MSEL_1_value << SYSPLLCTRL_MSEL_bit)
#define SYSPLLCTRL_MSEL2					(SYSPLLCTRL_MSEL_2_value << SYSPLLCTRL_MSEL_bit)
#define SYSPLLCTRL_MSEL3					(SYSPLLCTRL_MSEL_3_value << SYSPLLCTRL_MSEL_bit)
#define SYSPLLCTRL_MSEL4					(SYSPLLCTRL_MSEL_4_value << SYSPLLCTRL_MSEL_bit)
#define SYSPLLCTRL_MSEL5					(SYSPLLCTRL_MSEL_5_value << SYSPLLCTRL_MSEL_bit)
#define SYSPLLCTRL_MSEL6					(SYSPLLCTRL_MSEL_6_value << SYSPLLCTRL_MSEL_bit)
#define SYSPLLCTRL_MSEL7					(SYSPLLCTRL_MSEL_7_value << SYSPLLCTRL_MSEL_bit)
#define SYSPLLCTRL_MSEL8					(SYSPLLCTRL_MSEL_8_value << SYSPLLCTRL_MSEL_bit)
#define SYSPLLCTRL_MSEL9					(SYSPLLCTRL_MSEL_9_value << SYSPLLCTRL_MSEL_bit)
#define SYSPLLCTRL_MSEL10					(SYSPLLCTRL_MSEL_10_value << SYSPLLCTRL_MSEL_bit)
#define SYSPLLCTRL_MSEL11					(SYSPLLCTRL_MSEL_11_value << SYSPLLCTRL_MSEL_bit)
#define SYSPLLCTRL_MSEL12					(SYSPLLCTRL_MSEL_12_value << SYSPLLCTRL_MSEL_bit)
#define SYSPLLCTRL_MSEL13					(SYSPLLCTRL_MSEL_13_value << SYSPLLCTRL_MSEL_bit)
#define SYSPLLCTRL_MSEL14					(SYSPLLCTRL_MSEL_14_value << SYSPLLCTRL_MSEL_bit)
#define SYSPLLCTRL_MSEL15					(SYSPLLCTRL_MSEL_15_value << SYSPLLCTRL_MSEL_bit)
#define SYSPLLCTRL_MSEL16					(SYSPLLCTRL_MSEL_16_value << SYSPLLCTRL_MSEL_bit)
#define SYSPLLCTRL_MSEL17					(SYSPLLCTRL_MSEL_17_value << SYSPLLCTRL_MSEL_bit)
#define SYSPLLCTRL_MSEL18					(SYSPLLCTRL_MSEL_18_value << SYSPLLCTRL_MSEL_bit)
#define SYSPLLCTRL_MSEL19					(SYSPLLCTRL_MSEL_19_value << SYSPLLCTRL_MSEL_bit)
#define SYSPLLCTRL_MSEL20					(SYSPLLCTRL_MSEL_20_value << SYSPLLCTRL_MSEL_bit)
#define SYSPLLCTRL_MSEL21					(SYSPLLCTRL_MSEL_21_value << SYSPLLCTRL_MSEL_bit)
#define SYSPLLCTRL_MSEL22					(SYSPLLCTRL_MSEL_22_value << SYSPLLCTRL_MSEL_bit)
#define SYSPLLCTRL_MSEL23					(SYSPLLCTRL_MSEL_23_value << SYSPLLCTRL_MSEL_bit)
#define SYSPLLCTRL_MSEL24					(SYSPLLCTRL_MSEL_24_value << SYSPLLCTRL_MSEL_bit)
#define SYSPLLCTRL_MSEL25					(SYSPLLCTRL_MSEL_25_value << SYSPLLCTRL_MSEL_bit)
#define SYSPLLCTRL_MSEL26					(SYSPLLCTRL_MSEL_26_value << SYSPLLCTRL_MSEL_bit)
#define SYSPLLCTRL_MSEL27					(SYSPLLCTRL_MSEL_27_value << SYSPLLCTRL_MSEL_bit)
#define SYSPLLCTRL_MSEL28					(SYSPLLCTRL_MSEL_28_value << SYSPLLCTRL_MSEL_bit)
#define SYSPLLCTRL_MSEL29					(SYSPLLCTRL_MSEL_29_value << SYSPLLCTRL_MSEL_bit)
#define SYSPLLCTRL_MSEL30					(SYSPLLCTRL_MSEL_30_value << SYSPLLCTRL_MSEL_bit)
#define SYSPLLCTRL_MSEL31					(SYSPLLCTRL_MSEL_31_value << SYSPLLCTRL_MSEL_bit)
#define SYSPLLCTRL_MSEL32					(SYSPLLCTRL_MSEL_32_value << SYSPLLCTRL_MSEL_bit)

// underscores removed to avoid redefinition

#define SYSPLLCTRL_PSEL1					(SYSPLLCTRL_PSEL_1_value << SYSPLLCTRL_PSEL_bit)
#define SYSPLLCTRL_PSEL2					(SYSPLLCTRL_PSEL_2_value << SYSPLLCTRL_PSEL_bit)
#define SYSPLLCTRL_PSEL4					(SYSPLLCTRL_PSEL_4_value << SYSPLLCTRL_PSEL_bit)
#define SYSPLLCTRL_PSEL8					(SYSPLLCTRL_PSEL_8_value << SYSPLLCTRL_PSEL_bit)

/*
+-----------------------------------------------------------------------------+
| SYSPLLSTAT - System PLL status register
+-----------------------------------------------------------------------------+
*/

#define SYSPLLSTAT_LOCK_bit					0

#define SYSPLLSTAT_LOCK						(1 << SYSPLLSTAT_LOCK_bit)

/*
+-----------------------------------------------------------------------------+
| SYSOSCCTRL - System oscillator control register
+-----------------------------------------------------------------------------+
*/

#define SYSOSCCTRL_BYPASS_bit				0
#define SYSOSCCTRL_FREQRANGE_bit			1

#define SYSOSCCTRL_BYPASS					(1 << SYSOSCCTRL_BYPASS_bit)
#define SYSOSCCTRL_FREQRANGE				(1 << SYSOSCCTRL_FREQRANGE_bit)

/*
+-----------------------------------------------------------------------------+
| WDTOSCCTRL - Watchdog oscillator control register
+-----------------------------------------------------------------------------+
*/

#define WDTOSCCTRL_DIVSEL_bit				0
#define WDTOSCCTRL_DIVSEL_0_bit				0
#define WDTOSCCTRL_DIVSEL_1_bit				1
#define WDTOSCCTRL_DIVSEL_2_bit				2
#define WDTOSCCTRL_DIVSEL_3_bit				3
#define WDTOSCCTRL_DIVSEL_4_bit				4
#define WDTOSCCTRL_FREQSEL_bit				5
#define WDTOSCCTRL_FREQSEL_0_bit			5
#define WDTOSCCTRL_FREQSEL_1_bit			6
#define WDTOSCCTRL_FREQSEL_2_bit			7
#define WDTOSCCTRL_FREQSEL_3_bit			8

#define WDTOSCCTRL_DIVSEL_0					(1 << WDTOSCCTRL_DIVSEL_0_bit)
#define WDTOSCCTRL_DIVSEL_1					(1 << WDTOSCCTRL_DIVSEL_1_bit)
#define WDTOSCCTRL_DIVSEL_2					(1 << WDTOSCCTRL_DIVSEL_2_bit)
#define WDTOSCCTRL_DIVSEL_3					(1 << WDTOSCCTRL_DIVSEL_3_bit)
#define WDTOSCCTRL_DIVSEL_4					(1 << WDTOSCCTRL_DIVSEL_4_bit)
#define WDTOSCCTRL_FREQSEL_0				(1 << WDTOSCCTRL_FREQSEL_0_bit)
#define WDTOSCCTRL_FREQSEL_1				(1 << WDTOSCCTRL_FREQSEL_1_bit)
#define WDTOSCCTRL_FREQSEL_2				(1 << WDTOSCCTRL_FREQSEL_2_bit)
#define WDTOSCCTRL_FREQSEL_3				(1 << WDTOSCCTRL_FREQSEL_3_bit)

#define WDTOSCCTRL_DIVSEL_2_value			0
#define WDTOSCCTRL_DIVSEL_4_value			1
#define WDTOSCCTRL_DIVSEL_6_value			2
#define WDTOSCCTRL_DIVSEL_8_value			3
#define WDTOSCCTRL_DIVSEL_10_value			4
#define WDTOSCCTRL_DIVSEL_12_value			5
#define WDTOSCCTRL_DIVSEL_14_value			6
#define WDTOSCCTRL_DIVSEL_16_value			7
#define WDTOSCCTRL_DIVSEL_18_value			8
#define WDTOSCCTRL_DIVSEL_20_value			9
#define WDTOSCCTRL_DIVSEL_22_value			10
#define WDTOSCCTRL_DIVSEL_24_value			11
#define WDTOSCCTRL_DIVSEL_26_value			12
#define WDTOSCCTRL_DIVSEL_28_value			13
#define WDTOSCCTRL_DIVSEL_30_value			14
#define WDTOSCCTRL_DIVSEL_32_value			15
#define WDTOSCCTRL_DIVSEL_34_value			16
#define WDTOSCCTRL_DIVSEL_36_value			17
#define WDTOSCCTRL_DIVSEL_38_value			18
#define WDTOSCCTRL_DIVSEL_40_value			19
#define WDTOSCCTRL_DIVSEL_42_value			20
#define WDTOSCCTRL_DIVSEL_44_value			21
#define WDTOSCCTRL_DIVSEL_46_value			22
#define WDTOSCCTRL_DIVSEL_48_value			23
#define WDTOSCCTRL_DIVSEL_50_value			24
#define WDTOSCCTRL_DIVSEL_52_value			25
#define WDTOSCCTRL_DIVSEL_54_value			26
#define WDTOSCCTRL_DIVSEL_56_value			27
#define WDTOSCCTRL_DIVSEL_58_value			28
#define WDTOSCCTRL_DIVSEL_60_value			29
#define WDTOSCCTRL_DIVSEL_62_value			30
#define WDTOSCCTRL_DIVSEL_64_value			31
#define WDTOSCCTRL_DIVSEL_mask				31

#define WDTOSCCTRL_FREQSEL_500kHz_value		1
#define WDTOSCCTRL_FREQSEL_800kHz_value		2
#define WDTOSCCTRL_FREQSEL_1100kHz_value	3
#define WDTOSCCTRL_FREQSEL_1400kHz_value	4
#define WDTOSCCTRL_FREQSEL_1600kHz_value	5
#define WDTOSCCTRL_FREQSEL_1800kHz_value	6
#define WDTOSCCTRL_FREQSEL_2000kHz_value	7
#define WDTOSCCTRL_FREQSEL_2200kHz_value	8
#define WDTOSCCTRL_FREQSEL_2400kHz_value	9
#define WDTOSCCTRL_FREQSEL_2600kHz_value	10
#define WDTOSCCTRL_FREQSEL_2700kHz_value	11
#define WDTOSCCTRL_FREQSEL_2900kHz_value	12
#define WDTOSCCTRL_FREQSEL_3100kHz_value	13
#define WDTOSCCTRL_FREQSEL_3200kHz_value	14
#define WDTOSCCTRL_FREQSEL_3400kHz_value	15
#define WDTOSCCTRL_FREQSEL_mask				15

// underscores removed to avoid redefinition

#define WDTOSCCTRL_DIVSEL2					(WDTOSCCTRL_DIVSEL_2_value << WDTOSCCTRL_DIVSEL_bit)
#define WDTOSCCTRL_DIVSEL4					(WDTOSCCTRL_DIVSEL_4_value << WDTOSCCTRL_DIVSEL_bit)
#define WDTOSCCTRL_DIVSEL6					(WDTOSCCTRL_DIVSEL_6_value << WDTOSCCTRL_DIVSEL_bit)
#define WDTOSCCTRL_DIVSEL8					(WDTOSCCTRL_DIVSEL_8_value << WDTOSCCTRL_DIVSEL_bit)
#define WDTOSCCTRL_DIVSEL10					(WDTOSCCTRL_DIVSEL_10_value << WDTOSCCTRL_DIVSEL_bit)
#define WDTOSCCTRL_DIVSEL12					(WDTOSCCTRL_DIVSEL_12_value << WDTOSCCTRL_DIVSEL_bit)
#define WDTOSCCTRL_DIVSEL14					(WDTOSCCTRL_DIVSEL_14_value << WDTOSCCTRL_DIVSEL_bit)
#define WDTOSCCTRL_DIVSEL16					(WDTOSCCTRL_DIVSEL_16_value << WDTOSCCTRL_DIVSEL_bit)
#define WDTOSCCTRL_DIVSEL18					(WDTOSCCTRL_DIVSEL_18_value << WDTOSCCTRL_DIVSEL_bit)
#define WDTOSCCTRL_DIVSEL20					(WDTOSCCTRL_DIVSEL_20_value << WDTOSCCTRL_DIVSEL_bit)
#define WDTOSCCTRL_DIVSEL22					(WDTOSCCTRL_DIVSEL_22_value << WDTOSCCTRL_DIVSEL_bit)
#define WDTOSCCTRL_DIVSEL24					(WDTOSCCTRL_DIVSEL_24_value << WDTOSCCTRL_DIVSEL_bit)
#define WDTOSCCTRL_DIVSEL26					(WDTOSCCTRL_DIVSEL_26_value << WDTOSCCTRL_DIVSEL_bit)
#define WDTOSCCTRL_DIVSEL28					(WDTOSCCTRL_DIVSEL_28_value << WDTOSCCTRL_DIVSEL_bit)
#define WDTOSCCTRL_DIVSEL30					(WDTOSCCTRL_DIVSEL_30_value << WDTOSCCTRL_DIVSEL_bit)
#define WDTOSCCTRL_DIVSEL32					(WDTOSCCTRL_DIVSEL_32_value << WDTOSCCTRL_DIVSEL_bit)
#define WDTOSCCTRL_DIVSEL34					(WDTOSCCTRL_DIVSEL_34_value << WDTOSCCTRL_DIVSEL_bit)
#define WDTOSCCTRL_DIVSEL36					(WDTOSCCTRL_DIVSEL_36_value << WDTOSCCTRL_DIVSEL_bit)
#define WDTOSCCTRL_DIVSEL38					(WDTOSCCTRL_DIVSEL_38_value << WDTOSCCTRL_DIVSEL_bit)
#define WDTOSCCTRL_DIVSEL40					(WDTOSCCTRL_DIVSEL_40_value << WDTOSCCTRL_DIVSEL_bit)
#define WDTOSCCTRL_DIVSEL42					(WDTOSCCTRL_DIVSEL_42_value << WDTOSCCTRL_DIVSEL_bit)
#define WDTOSCCTRL_DIVSEL44					(WDTOSCCTRL_DIVSEL_44_value << WDTOSCCTRL_DIVSEL_bit)
#define WDTOSCCTRL_DIVSEL46					(WDTOSCCTRL_DIVSEL_46_value << WDTOSCCTRL_DIVSEL_bit)
#define WDTOSCCTRL_DIVSEL48					(WDTOSCCTRL_DIVSEL_48_value << WDTOSCCTRL_DIVSEL_bit)
#define WDTOSCCTRL_DIVSEL50					(WDTOSCCTRL_DIVSEL_50_value << WDTOSCCTRL_DIVSEL_bit)
#define WDTOSCCTRL_DIVSEL52					(WDTOSCCTRL_DIVSEL_52_value << WDTOSCCTRL_DIVSEL_bit)
#define WDTOSCCTRL_DIVSEL54					(WDTOSCCTRL_DIVSEL_54_value << WDTOSCCTRL_DIVSEL_bit)
#define WDTOSCCTRL_DIVSEL56					(WDTOSCCTRL_DIVSEL_56_value << WDTOSCCTRL_DIVSEL_bit)
#define WDTOSCCTRL_DIVSEL58					(WDTOSCCTRL_DIVSEL_58_value << WDTOSCCTRL_DIVSEL_bit)
#define WDTOSCCTRL_DIVSEL60					(WDTOSCCTRL_DIVSEL_60_value << WDTOSCCTRL_DIVSEL_bit)
#define WDTOSCCTRL_DIVSEL62					(WDTOSCCTRL_DIVSEL_62_value << WDTOSCCTRL_DIVSEL_bit)
#define WDTOSCCTRL_DIVSEL64					(WDTOSCCTRL_DIVSEL_64_value << WDTOSCCTRL_DIVSEL_bit)

#define WDTOSCCTRL_FREQSEL_500kHz			(WDTOSCCTRL_FREQSEL_500kHz_value << WDTOSCCTRL_FREQSEL_bit)
#define WDTOSCCTRL_FREQSEL_800kHz			(WDTOSCCTRL_FREQSEL_800kHz_value << WDTOSCCTRL_FREQSEL_bit)
#define WDTOSCCTRL_FREQSEL_1100kHz			(WDTOSCCTRL_FREQSEL_1100kHz_value << WDTOSCCTRL_FREQSEL_bit)
#define WDTOSCCTRL_FREQSEL_1400kHz			(WDTOSCCTRL_FREQSEL_1400kHz_value << WDTOSCCTRL_FREQSEL_bit)
#define WDTOSCCTRL_FREQSEL_1600kHz			(WDTOSCCTRL_FREQSEL_1600kHz_value << WDTOSCCTRL_FREQSEL_bit)
#define WDTOSCCTRL_FREQSEL_1800kHz			(WDTOSCCTRL_FREQSEL_1800kHz_value << WDTOSCCTRL_FREQSEL_bit)
#define WDTOSCCTRL_FREQSEL_2000kHz			(WDTOSCCTRL_FREQSEL_2000kHz_value << WDTOSCCTRL_FREQSEL_bit)
#define WDTOSCCTRL_FREQSEL_2200kHz			(WDTOSCCTRL_FREQSEL_2200kHz_value << WDTOSCCTRL_FREQSEL_bit)
#define WDTOSCCTRL_FREQSEL_2400kHz			(WDTOSCCTRL_FREQSEL_2400kHz_value << WDTOSCCTRL_FREQSEL_bit)
#define WDTOSCCTRL_FREQSEL_2600kHz			(WDTOSCCTRL_FREQSEL_2600kHz_value << WDTOSCCTRL_FREQSEL_bit)
#define WDTOSCCTRL_FREQSEL_2700kHz			(WDTOSCCTRL_FREQSEL_2700kHz_value << WDTOSCCTRL_FREQSEL_bit)
#define WDTOSCCTRL_FREQSEL_2900kHz			(WDTOSCCTRL_FREQSEL_2900kHz_value << WDTOSCCTRL_FREQSEL_bit)
#define WDTOSCCTRL_FREQSEL_3100kHz			(WDTOSCCTRL_FREQSEL_3100kHz_value << WDTOSCCTRL_FREQSEL_bit)
#define WDTOSCCTRL_FREQSEL_3200kHz			(WDTOSCCTRL_FREQSEL_3200kHz_value << WDTOSCCTRL_FREQSEL_bit)
#define WDTOSCCTRL_FREQSEL_3400kHz			(WDTOSCCTRL_FREQSEL_3400kHz_value << WDTOSCCTRL_FREQSEL_bit)

/*
+-----------------------------------------------------------------------------+
| IRCCTRL - Internal resonant crystal control register
+-----------------------------------------------------------------------------+
*/

#define IRCCTRL_TRIM_bit					0
#define IRCCTRL_TRIM_0_bit					0
#define IRCCTRL_TRIM_1_bit					1
#define IRCCTRL_TRIM_2_bit					2
#define IRCCTRL_TRIM_3_bit					3
#define IRCCTRL_TRIM_4_bit					4
#define IRCCTRL_TRIM_5_bit					5
#define IRCCTRL_TRIM_6_bit					6
#define IRCCTRL_TRIM_7_bit					7

#define IRCCTRL_TRIM_0						(1 << IRCCTRL_TRIM_0_bit)
#define IRCCTRL_TRIM_1						(1 << IRCCTRL_TRIM_1_bit)
#define IRCCTRL_TRIM_2						(1 << IRCCTRL_TRIM_2_bit)
#define IRCCTRL_TRIM_3						(1 << IRCCTRL_TRIM_3_bit)
#define IRCCTRL_TRIM_4						(1 << IRCCTRL_TRIM_4_bit)
#define IRCCTRL_TRIM_5						(1 << IRCCTRL_TRIM_5_bit)
#define IRCCTRL_TRIM_6						(1 << IRCCTRL_TRIM_6_bit)
#define IRCCTRL_TRIM_7						(1 << IRCCTRL_TRIM_7_bit)

/*
+-----------------------------------------------------------------------------+
| SYSRSTSTAT - System reset status register
+-----------------------------------------------------------------------------+
*/

#define SYSRSTSTAT_POR_bit					0
#define SYSRSTSTAT_EXTRST_bit				1
#define SYSRSTSTAT_WDT_bit					2
#define SYSRSTSTAT_BOD_bit					3
#define SYSRSTSTAT_SYSRST_bit				4

#define SYSRSTSTAT_POR						(1 << SYSRSTSTAT_POR_bit)
#define SYSRSTSTAT_EXTRST					(1 << SYSRSTSTAT_EXTRST_bit)
#define SYSRSTSTAT_WDT						(1 << SYSRSTSTAT_WDT_bit)
#define SYSRSTSTAT_BOD						(1 << SYSRSTSTAT_BOD_bit)
#define SYSRSTSTAT_SYSRST					(1 << SYSRSTSTAT_SYSRST_bit)

/*
+-----------------------------------------------------------------------------+
| SYSPLLCLKSEL - System PLL clock source select register
+-----------------------------------------------------------------------------+
*/

#define SYSPLLCLKSEL_SEL_bit				0
#define SYSPLLCLKSEL_SEL_0_bit				0
#define SYSPLLCLKSEL_SEL_1_bit				1

#define SYSPLLCLKSEL_SEL_0					(1 << SYSPLLCLKSEL_SEL_0_bit)
#define SYSPLLCLKSEL_SEL_1					(1 << SYSPLLCLKSEL_SEL_1_bit)

#define SYSPLLCLKSEL_SEL_IRC_value			0
#define SYSPLLCLKSEL_SEL_SYSOSC_value		1
#define SYSPLLCLKSEL_SEL_mask				3

#define SYSPLLCLKSEL_SEL_IRC				(SYSPLLCLKSEL_SEL_IRC_value	<< SYSPLLCLKSEL_SEL_bit)
#define SYSPLLCLKSEL_SEL_SYSOSC				(SYSPLLCLKSEL_SEL_SYSOSC_value	<< SYSPLLCLKSEL_SEL_bit)

/*
+-----------------------------------------------------------------------------+
| SYSPLLUEN - System PLL clock source update enable register
+-----------------------------------------------------------------------------+
*/

#define SYSPLLUEN_ENA_bit					0

#define SYSPLLUEN_ENA						(1 << SYSPLLUEN_ENA_bit)

/*
+-----------------------------------------------------------------------------+
| MAINCLKSEL - Main clock source select register
+-----------------------------------------------------------------------------+
*/

#define MAINCLKSEL_SEL_bit					0
#define MAINCLKSEL_SEL_0_bit				0
#define MAINCLKSEL_SEL_1_bit				1

#define MAINCLKSEL_SEL_0					(1 << MAINCLKSEL_SEL_0_bit)
#define MAINCLKSEL_SEL_1					(1 << MAINCLKSEL_SEL_1_bit)

#define MAINCLKSEL_SEL_IRC_value			0
#define MAINCLKSEL_SEL_PLLIN_value			1
#define MAINCLKSEL_SEL_WDT_value			2
#define MAINCLKSEL_SEL_PLLOUT_value			3
#define MAINCLKSEL_SEL_mask					3

#define MAINCLKSEL_SEL_IRC					(MAINCLKSEL_SEL_IRC_value << MAINCLKSEL_SEL_bit)
#define MAINCLKSEL_SEL_PLLIN				(MAINCLKSEL_SEL_PLLIN_value << MAINCLKSEL_SEL_bit)
#define MAINCLKSEL_SEL_WDT					(MAINCLKSEL_SEL_WDT_value << MAINCLKSEL_SEL_bit)
#define MAINCLKSEL_SEL_PLLOUT				(MAINCLKSEL_SEL_PLLOUT_value << MAINCLKSEL_SEL_bit)

/*
+-----------------------------------------------------------------------------+
| MAINCLKUEN - Main clock source update enable register
+-----------------------------------------------------------------------------+
*/

#define MAINCLKUEN_ENA_bit					0

#define MAINCLKUEN_ENA						(1 << MAINCLKUEN_ENA_bit)

/*
+-----------------------------------------------------------------------------+
| SYSAHBCLKDIV - System AHB clock divider register
+-----------------------------------------------------------------------------+
*/

#define SYSAHBCLKDIV_DIV_bit				0
#define SYSAHBCLKDIV_DIV_0_bit				0
#define SYSAHBCLKDIV_DIV_1_bit				1
#define SYSAHBCLKDIV_DIV_2_bit				2
#define SYSAHBCLKDIV_DIV_3_bit				3
#define SYSAHBCLKDIV_DIV_4_bit				4
#define SYSAHBCLKDIV_DIV_5_bit				5
#define SYSAHBCLKDIV_DIV_6_bit				6
#define SYSAHBCLKDIV_DIV_7_bit				7

#define SYSAHBCLKDIV_DIV_0					(1 << SYSAHBCLKDIV_DIV_0_bit)
#define SYSAHBCLKDIV_DIV_1					(1 << SYSAHBCLKDIV_DIV_1_bit)
#define SYSAHBCLKDIV_DIV_2					(1 << SYSAHBCLKDIV_DIV_2_bit)
#define SYSAHBCLKDIV_DIV_3					(1 << SYSAHBCLKDIV_DIV_3_bit)
#define SYSAHBCLKDIV_DIV_4					(1 << SYSAHBCLKDIV_DIV_4_bit)
#define SYSAHBCLKDIV_DIV_5					(1 << SYSAHBCLKDIV_DIV_5_bit)
#define SYSAHBCLKDIV_DIV_6					(1 << SYSAHBCLKDIV_DIV_6_bit)
#define SYSAHBCLKDIV_DIV_7					(1 << SYSAHBCLKDIV_DIV_7_bit)

#define SYSAHBCLKDIV_DIV_CLKDISABLED_value	0
#define SYSAHBCLKDIV_DIV_mask				255

#define SYSAHBCLKDIV_DIV_CLKDISABLED		(SYSAHBCLKDIV_DIV_CLKDISABLED_value << SYSAHBCLKDIV_DIV_bit)

/*
+-----------------------------------------------------------------------------+
| SYSAHBCLKCTRL - System AHB clock control register
+-----------------------------------------------------------------------------+
*/

#define SYSAHBCLKCTRL_SYS_bit				0
#define SYSAHBCLKCTRL_ROM_bit				1
#define SYSAHBCLKCTRL_RAM_bit				2
#define SYSAHBCLKCTRL_FLASHREG_bit			3
#define SYSAHBCLKCTRL_FLASHARRAY_bit		4
#define SYSAHBCLKCTRL_I2C_bit				5
#define SYSAHBCLKCTRL_GPIO_bit				6
#define SYSAHBCLKCTRL_CT16B0_bit			7
#define SYSAHBCLKCTRL_CT16B1_bit			8
#define SYSAHBCLKCTRL_CT32B0_bit			9
#define SYSAHBCLKCTRL_CT32B1_bit			10
#define SYSAHBCLKCTRL_SSP0_bit				11
#define SYSAHBCLKCTRL_UART_bit				12
#define SYSAHBCLKCTRL_ADC_bit				13
#define SYSAHBCLKCTRL_WDT_bit				15
#define SYSAHBCLKCTRL_IOCON_bit				16
#define SYSAHBCLKCTRL_CAN_bit				17
#define SYSAHBCLKCTRL_SSP1_bit				18

#define SYSAHBCLKCTRL_SYS					(1 << SYSAHBCLKCTRL_SYS_bit)
#define SYSAHBCLKCTRL_ROM					(1 << SYSAHBCLKCTRL_ROM_bit)
#define SYSAHBCLKCTRL_RAM					(1 << SYSAHBCLKCTRL_RAM_bit)
#define SYSAHBCLKCTRL_FLASHREG				(1 << SYSAHBCLKCTRL_FLASHREG_bit)
#define SYSAHBCLKCTRL_FLASHARRAY			(1 << SYSAHBCLKCTRL_FLASHARRAY_bit)
#define SYSAHBCLKCTRL_I2C					(1 << SYSAHBCLKCTRL_I2C_bit)
#define SYSAHBCLKCTRL_GPIO					(1 << SYSAHBCLKCTRL_GPIO_bit)
#define SYSAHBCLKCTRL_CT16B0				(1 << SYSAHBCLKCTRL_CT16B0_bit)
#define SYSAHBCLKCTRL_CT16B1				(1 << SYSAHBCLKCTRL_CT16B1_bit)
#define SYSAHBCLKCTRL_CT32B0				(1 << SYSAHBCLKCTRL_CT32B0_bit)
#define SYSAHBCLKCTRL_CT32B1				(1 << SYSAHBCLKCTRL_CT32B1_bit)
#define SYSAHBCLKCTRL_SSP0					(1 << SYSAHBCLKCTRL_SSP0_bit)
#define SYSAHBCLKCTRL_UART					(1 << SYSAHBCLKCTRL_UART_bit)
#define SYSAHBCLKCTRL_ADC					(1 << SYSAHBCLKCTRL_ADC_bit)
#define SYSAHBCLKCTRL_WDT					(1 << SYSAHBCLKCTRL_WDT_bit)
#define SYSAHBCLKCTRL_IOCON					(1 << SYSAHBCLKCTRL_IOCON_bit)
#define SYSAHBCLKCTRL_CAN					(1 << SYSAHBCLKCTRL_CAN_bit)
#define SYSAHBCLKCTRL_SSP1					(1 << SYSAHBCLKCTRL_SSP1_bit)

/*
+-----------------------------------------------------------------------------+
| SSP0CLKDIV - SPI0 clock divider register
+-----------------------------------------------------------------------------+
*/

#define SSP0CLKDIV_DIV_bit					0
#define SSP0CLKDIV_DIV_0_bit				0
#define SSP0CLKDIV_DIV_1_bit				1
#define SSP0CLKDIV_DIV_2_bit				2
#define SSP0CLKDIV_DIV_3_bit				3
#define SSP0CLKDIV_DIV_4_bit				4
#define SSP0CLKDIV_DIV_5_bit				5
#define SSP0CLKDIV_DIV_6_bit				6
#define SSP0CLKDIV_DIV_7_bit				7

#define SSP0CLKDIV_DIV_0					(1 << SSP0CLKDIV_DIV_0_bit)
#define SSP0CLKDIV_DIV_1					(1 << SSP0CLKDIV_DIV_1_bit)
#define SSP0CLKDIV_DIV_2					(1 << SSP0CLKDIV_DIV_2_bit)
#define SSP0CLKDIV_DIV_3					(1 << SSP0CLKDIV_DIV_3_bit)
#define SSP0CLKDIV_DIV_4					(1 << SSP0CLKDIV_DIV_4_bit)
#define SSP0CLKDIV_DIV_5					(1 << SSP0CLKDIV_DIV_5_bit)
#define SSP0CLKDIV_DIV_6					(1 << SSP0CLKDIV_DIV_6_bit)
#define SSP0CLKDIV_DIV_7					(1 << SSP0CLKDIV_DIV_7_bit)

#define SSP0CLKDIV_DIV_CLKDISABLED_value	0
#define SSP0CLKDIV_DIV_mask					255

#define SSP0CLKDIV_DIV_CLKDISABLED			(SSP0CLKDIV_DIV_CLKDISABLED_value << SSP0CLKDIV_DIV_bit)

/*
+-----------------------------------------------------------------------------+
| UARTCLKDIV - UART clock divider register
+-----------------------------------------------------------------------------+
*/

#define UARTCLKDIV_DIV_bit					0
#define UARTCLKDIV_DIV_0_bit				0
#define UARTCLKDIV_DIV_1_bit				1
#define UARTCLKDIV_DIV_2_bit				2
#define UARTCLKDIV_DIV_3_bit				3
#define UARTCLKDIV_DIV_4_bit				4
#define UARTCLKDIV_DIV_5_bit				5
#define UARTCLKDIV_DIV_6_bit				6
#define UARTCLKDIV_DIV_7_bit				7

#define UARTCLKDIV_DIV_0					(1 << UARTCLKDIV_DIV_0_bit)
#define UARTCLKDIV_DIV_1					(1 << UARTCLKDIV_DIV_1_bit)
#define UARTCLKDIV_DIV_2					(1 << UARTCLKDIV_DIV_2_bit)
#define UARTCLKDIV_DIV_3					(1 << UARTCLKDIV_DIV_3_bit)
#define UARTCLKDIV_DIV_4					(1 << UARTCLKDIV_DIV_4_bit)
#define UARTCLKDIV_DIV_5					(1 << UARTCLKDIV_DIV_5_bit)
#define UARTCLKDIV_DIV_6					(1 << UARTCLKDIV_DIV_6_bit)
#define UARTCLKDIV_DIV_7					(1 << UARTCLKDIV_DIV_7_bit)

#define UARTCLKDIV_DIV_CLKDISABLED_value	0
#define UARTCLKDIV_DIV_mask					255

#define UARTCLKDIV_DIV_CLKDISABLED			(UARTCLKDIV_DIV_CLKDISABLED_value << UARTCLKDIV_DIV_bit)

/*
+-----------------------------------------------------------------------------+
| SSP1CLKDIV - SPI1 clock divider register
+-----------------------------------------------------------------------------+
*/

#define SSP1CLKDIV_DIV_bit					0
#define SSP1CLKDIV_DIV_0_bit				0
#define SSP1CLKDIV_DIV_1_bit				1
#define SSP1CLKDIV_DIV_2_bit				2
#define SSP1CLKDIV_DIV_3_bit				3
#define SSP1CLKDIV_DIV_4_bit				4
#define SSP1CLKDIV_DIV_5_bit				5
#define SSP1CLKDIV_DIV_6_bit				6
#define SSP1CLKDIV_DIV_7_bit				7

#define SSP1CLKDIV_DIV_0					(1 << SSP1CLKDIV_DIV_0_bit)
#define SSP1CLKDIV_DIV_1					(1 << SSP1CLKDIV_DIV_1_bit)
#define SSP1CLKDIV_DIV_2					(1 << SSP1CLKDIV_DIV_2_bit)
#define SSP1CLKDIV_DIV_3					(1 << SSP1CLKDIV_DIV_3_bit)
#define SSP1CLKDIV_DIV_4					(1 << SSP1CLKDIV_DIV_4_bit)
#define SSP1CLKDIV_DIV_5					(1 << SSP1CLKDIV_DIV_5_bit)
#define SSP1CLKDIV_DIV_6					(1 << SSP1CLKDIV_DIV_6_bit)
#define SSP1CLKDIV_DIV_7					(1 << SSP1CLKDIV_DIV_7_bit)

#define SSP1CLKDIV_DIV_CLKDISABLED_value	0
#define SSP1CLKDIV_DIV_mask					255

#define SSP1CLKDIV_DIV_CLKDISABLED			(SSP1CLKDIV_DIV_CLKDISABLED_value << SSP1CLKDIV_DIV_bit)

/*
+-----------------------------------------------------------------------------+
| WDTCLKSEL - WDT clock source select register
+-----------------------------------------------------------------------------+
*/

#define WDTCLKSEL_SEL_bit					0
#define WDTCLKSEL_SEL_0_bit					0
#define WDTCLKSEL_SEL_1_bit					1

#define WDTCLKSEL_SEL_0						(1 << WDTCLKSEL_SEL_0_bit)
#define WDTCLKSEL_SEL_1						(1 << WDTCLKSEL_SEL_1_bit)

#define WDTCLKSEL_SEL_IRC_value				0
#define WDTCLKSEL_SEL_MAINCLK_value			1
#define WDTCLKSEL_SEL_WDTOSC_value			2
#define WDTCLKSEL_SEL_mask					255

#define WDTCLKSEL_SEL_IRC					(WDTCLKSEL_SEL_IRC_value << WDTCLKSEL_SEL_bit)
#define WDTCLKSEL_SEL_MAINCLK				(WDTCLKSEL_SEL_MAINCLK_value << WDTCLKSEL_SEL_bit)
#define WDTCLKSEL_SEL_WDTOSC				(WDTCLKSEL_SEL_WDTOSC_value << WDTCLKSEL_SEL_bit)

/*
+-----------------------------------------------------------------------------+
| WDTCLKUEN - WDT clock source update enable register
+-----------------------------------------------------------------------------+
*/

#define WDTCLKUEN_ENA_bit					0

#define WDTCLKUEN_ENA						(1 << WDTCLKUEN_ENA_bit)

/*
+-----------------------------------------------------------------------------+
| WDTCLKDIV - WDT clock divider register
+-----------------------------------------------------------------------------+
*/

#define WDTCLKDIV_DIV_bit					0
#define WDTCLKDIV_DIV_0_bit					0
#define WDTCLKDIV_DIV_1_bit					1
#define WDTCLKDIV_DIV_2_bit					2
#define WDTCLKDIV_DIV_3_bit					3
#define WDTCLKDIV_DIV_4_bit					4
#define WDTCLKDIV_DIV_5_bit					5
#define WDTCLKDIV_DIV_6_bit					6
#define WDTCLKDIV_DIV_7_bit					7

#define WDTCLKDIV_DIV_0						(1 << WDTCLKDIV_DIV_0_bit)
#define WDTCLKDIV_DIV_1						(1 << WDTCLKDIV_DIV_1_bit)
#define WDTCLKDIV_DIV_2						(1 << WDTCLKDIV_DIV_2_bit)
#define WDTCLKDIV_DIV_3						(1 << WDTCLKDIV_DIV_3_bit)
#define WDTCLKDIV_DIV_4						(1 << WDTCLKDIV_DIV_4_bit)
#define WDTCLKDIV_DIV_5						(1 << WDTCLKDIV_DIV_5_bit)
#define WDTCLKDIV_DIV_6						(1 << WDTCLKDIV_DIV_6_bit)
#define WDTCLKDIV_DIV_7						(1 << WDTCLKDIV_DIV_7_bit)

#define WDTCLKDIV_DIV_CLKDISABLED_value		0
#define WDTCLKDIV_DIV_mask					255

#define WDTCLKDIV_DIV_CLKDISABLED			(WDTCLKDIV_DIV_CLKDISABLED_value << WDTCLKDIV_DIV_bit)

/*
+-----------------------------------------------------------------------------+
| CLKOUTCLKSEL - CLKOUT clock source select register
+-----------------------------------------------------------------------------+
*/

#define CLKOUTCLKSEL_SEL_bit				0
#define CLKOUTCLKSEL_SEL_0_bit				0
#define CLKOUTCLKSEL_SEL_1_bit				1

#define CLKOUTCLKSEL_SEL_0					(1 << CLKOUTCLKSEL_SEL_0_bit)
#define CLKOUTCLKSEL_SEL_1					(1 << CLKOUTCLKSEL_SEL_1_bit)

#define CLKOUTCLKSEL_SEL_IRC_value			0
#define CLKOUTCLKSEL_SEL_SYSOSC_value		1
#define CLKOUTCLKSEL_SEL_WDTOSC_value		2
#define CLKOUTCLKSEL_SEL_MAINCLK_value		3
#define CLKOUTCLKSEL_SEL_mask				3

#define CLKOUTCLKSEL_SEL_IRC				(CLKOUTCLKSEL_SEL_IRC_value << CLKOUTCLKSEL_SEL_bit)
#define CLKOUTCLKSEL_SEL_SYSOSC				(CLKOUTCLKSEL_SEL_SYSOSC_value << CLKOUTCLKSEL_SEL_bit)
#define CLKOUTCLKSEL_SEL_WDTOSC				(CLKOUTCLKSEL_SEL_WDTOSC_value << CLKOUTCLKSEL_SEL_bit)
#define CLKOUTCLKSEL_SEL_MAINCLK			(CLKOUTCLKSEL_SEL_MAINCLK_value << CLKOUTCLKSEL_SEL_bit)

/*
+-----------------------------------------------------------------------------+
| CLKOUTUEN - CLKOUT clock source update enable register
+-----------------------------------------------------------------------------+
*/

#define CLKOUTUEN_ENA_bit					0

#define CLKOUTUEN_ENA						(1 << CLKOUTUEN_ENA_bit)

/*
+-----------------------------------------------------------------------------+
| CLKOUTCLKDIV - CLKOUT clock divider registers
+-----------------------------------------------------------------------------+
*/

#define CLKOUTCLKDIV_DIV_bit				0
#define CLKOUTCLKDIV_DIV_0_bit				0
#define CLKOUTCLKDIV_DIV_1_bit				1
#define CLKOUTCLKDIV_DIV_2_bit				2
#define CLKOUTCLKDIV_DIV_3_bit				3
#define CLKOUTCLKDIV_DIV_4_bit				4
#define CLKOUTCLKDIV_DIV_5_bit				5
#define CLKOUTCLKDIV_DIV_6_bit				6
#define CLKOUTCLKDIV_DIV_7_bit				7

#define CLKOUTCLKDIV_DIV_0					(1 << CLKOUTCLKDIV_DIV_0_bit)
#define CLKOUTCLKDIV_DIV_1					(1 << CLKOUTCLKDIV_DIV_1_bit)
#define CLKOUTCLKDIV_DIV_2					(1 << CLKOUTCLKDIV_DIV_2_bit)
#define CLKOUTCLKDIV_DIV_3					(1 << CLKOUTCLKDIV_DIV_3_bit)
#define CLKOUTCLKDIV_DIV_4					(1 << CLKOUTCLKDIV_DIV_4_bit)
#define CLKOUTCLKDIV_DIV_5					(1 << CLKOUTCLKDIV_DIV_5_bit)
#define CLKOUTCLKDIV_DIV_6					(1 << CLKOUTCLKDIV_DIV_6_bit)
#define CLKOUTCLKDIV_DIV_7					(1 << CLKOUTCLKDIV_DIV_7_bit)

#define CLKOUTCLKDIV_DIV_CLKDISABLED_value	0
#define CLKOUTCLKDIV_DIV_mask				255

#define CLKOUTCLKDIV_DIV_CLKDISABLED		(CLKOUTCLKDIV_DIV_CLKDISABLED_value << CLKOUTCLKDIV_DIV_bit)

/*
+-----------------------------------------------------------------------------+
| PIOPORCAP0 - POR captured PIO status registers 0
+-----------------------------------------------------------------------------+
*/

#define PIOPORCAP0_CAPPIO0_0_bit			0
#define PIOPORCAP0_CAPPIO0_1_bit			1
#define PIOPORCAP0_CAPPIO0_2_bit			2
#define PIOPORCAP0_CAPPIO0_3_bit			3
#define PIOPORCAP0_CAPPIO0_4_bit			4
#define PIOPORCAP0_CAPPIO0_5_bit			5
#define PIOPORCAP0_CAPPIO0_6_bit			6
#define PIOPORCAP0_CAPPIO0_7_bit			7
#define PIOPORCAP0_CAPPIO0_8_bit			8
#define PIOPORCAP0_CAPPIO0_9_bit			9
#define PIOPORCAP0_CAPPIO0_10_bit			10
#define PIOPORCAP0_CAPPIO0_11_bit			11
#define PIOPORCAP0_CAPPIO1_0_bit			12
#define PIOPORCAP0_CAPPIO1_1_bit			13
#define PIOPORCAP0_CAPPIO1_2_bit			14
#define PIOPORCAP0_CAPPIO1_3_bit			15
#define PIOPORCAP0_CAPPIO1_4_bit			16
#define PIOPORCAP0_CAPPIO1_5_bit			17
#define PIOPORCAP0_CAPPIO1_6_bit			18
#define PIOPORCAP0_CAPPIO1_7_bit			19
#define PIOPORCAP0_CAPPIO1_8_bit			20
#define PIOPORCAP0_CAPPIO1_9_bit			21
#define PIOPORCAP0_CAPPIO1_10_bit			22
#define PIOPORCAP0_CAPPIO1_11_bit			23
#define PIOPORCAP0_CAPPIO2_0_bit			24
#define PIOPORCAP0_CAPPIO2_1_bit			25
#define PIOPORCAP0_CAPPIO2_2_bit			26
#define PIOPORCAP0_CAPPIO2_3_bit			27
#define PIOPORCAP0_CAPPIO2_4_bit			28
#define PIOPORCAP0_CAPPIO2_5_bit			29
#define PIOPORCAP0_CAPPIO2_6_bit			30
#define PIOPORCAP0_CAPPIO2_7_bit			31

#define PIOPORCAP0_CAPPIO0_0				(1 << PIOPORCAP0_CAPPIO0_0_bit)
#define PIOPORCAP0_CAPPIO0_1				(1 << PIOPORCAP0_CAPPIO0_1_bit)
#define PIOPORCAP0_CAPPIO0_2				(1 << PIOPORCAP0_CAPPIO0_2_bit)
#define PIOPORCAP0_CAPPIO0_3				(1 << PIOPORCAP0_CAPPIO0_3_bit)
#define PIOPORCAP0_CAPPIO0_4				(1 << PIOPORCAP0_CAPPIO0_4_bit)
#define PIOPORCAP0_CAPPIO0_5				(1 << PIOPORCAP0_CAPPIO0_5_bit)
#define PIOPORCAP0_CAPPIO0_6				(1 << PIOPORCAP0_CAPPIO0_6_bit)
#define PIOPORCAP0_CAPPIO0_7				(1 << PIOPORCAP0_CAPPIO0_7_bit)
#define PIOPORCAP0_CAPPIO0_8				(1 << PIOPORCAP0_CAPPIO0_8_bit)
#define PIOPORCAP0_CAPPIO0_9				(1 << PIOPORCAP0_CAPPIO0_9_bit)
#define PIOPORCAP0_CAPPIO0_10				(1 << PIOPORCAP0_CAPPIO0_10_bit)
#define PIOPORCAP0_CAPPIO0_11				(1 << PIOPORCAP0_CAPPIO0_11_bit)
#define PIOPORCAP0_CAPPIO1_0				(1 << PIOPORCAP0_CAPPIO1_0_bit)
#define PIOPORCAP0_CAPPIO1_1				(1 << PIOPORCAP0_CAPPIO1_1_bit)
#define PIOPORCAP0_CAPPIO1_2				(1 << PIOPORCAP0_CAPPIO1_2_bit)
#define PIOPORCAP0_CAPPIO1_3				(1 << PIOPORCAP0_CAPPIO1_3_bit)
#define PIOPORCAP0_CAPPIO1_4				(1 << PIOPORCAP0_CAPPIO1_4_bit)
#define PIOPORCAP0_CAPPIO1_5				(1 << PIOPORCAP0_CAPPIO1_5_bit)
#define PIOPORCAP0_CAPPIO1_6				(1 << PIOPORCAP0_CAPPIO1_6_bit)
#define PIOPORCAP0_CAPPIO1_7				(1 << PIOPORCAP0_CAPPIO1_7_bit)
#define PIOPORCAP0_CAPPIO1_8				(1 << PIOPORCAP0_CAPPIO1_8_bit)
#define PIOPORCAP0_CAPPIO1_9				(1 << PIOPORCAP0_CAPPIO1_9_bit)
#define PIOPORCAP0_CAPPIO1_10				(1 << PIOPORCAP0_CAPPIO1_10_bit)
#define PIOPORCAP0_CAPPIO1_11				(1 << PIOPORCAP0_CAPPIO1_11_bit)
#define PIOPORCAP0_CAPPIO2_0				(1 << PIOPORCAP0_CAPPIO2_0_bit)
#define PIOPORCAP0_CAPPIO2_1				(1 << PIOPORCAP0_CAPPIO2_1_bit)
#define PIOPORCAP0_CAPPIO2_2				(1 << PIOPORCAP0_CAPPIO2_2_bit)
#define PIOPORCAP0_CAPPIO2_3				(1 << PIOPORCAP0_CAPPIO2_3_bit)
#define PIOPORCAP0_CAPPIO2_4				(1 << PIOPORCAP0_CAPPIO2_4_bit)
#define PIOPORCAP0_CAPPIO2_5				(1 << PIOPORCAP0_CAPPIO2_5_bit)
#define PIOPORCAP0_CAPPIO2_6				(1 << PIOPORCAP0_CAPPIO2_6_bit)
#define PIOPORCAP0_CAPPIO2_7				(1 << PIOPORCAP0_CAPPIO2_7_bit)

/*
+-----------------------------------------------------------------------------+
| PIOPORCAP1 - POR captured PIO status registers 1
+-----------------------------------------------------------------------------+
*/

#define PIOPORCAP1_CAPPIO2_8_bit			0
#define PIOPORCAP1_CAPPIO2_9_bit			1
#define PIOPORCAP1_CAPPIO2_10_bit			2
#define PIOPORCAP1_CAPPIO2_11_bit			3
#define PIOPORCAP1_CAPPIO3_0_bit			4
#define PIOPORCAP1_CAPPIO3_1_bit			5
#define PIOPORCAP1_CAPPIO3_2_bit			6
#define PIOPORCAP1_CAPPIO3_3_bit			7
#define PIOPORCAP1_CAPPIO3_4_bit			8
#define PIOPORCAP1_CAPPIO3_5_bit			9

#define PIOPORCAP1_CAPPIO2_8				(1 << PIOPORCAP1_CAPPIO2_8_bit)
#define PIOPORCAP1_CAPPIO2_9				(1 << PIOPORCAP1_CAPPIO2_9_bit)
#define PIOPORCAP1_CAPPIO2_10				(1 << PIOPORCAP1_CAPPIO2_10_bit)
#define PIOPORCAP1_CAPPIO2_11				(1 << PIOPORCAP1_CAPPIO2_11_bit)
#define PIOPORCAP1_CAPPIO3_0				(1 << PIOPORCAP1_CAPPIO3_0_bit)
#define PIOPORCAP1_CAPPIO3_1				(1 << PIOPORCAP1_CAPPIO3_1_bit)
#define PIOPORCAP1_CAPPIO3_2				(1 << PIOPORCAP1_CAPPIO3_2_bit)
#define PIOPORCAP1_CAPPIO3_3				(1 << PIOPORCAP1_CAPPIO3_3_bit)
#define PIOPORCAP1_CAPPIO3_4				(1 << PIOPORCAP1_CAPPIO3_4_bit)
#define PIOPORCAP1_CAPPIO3_5				(1 << PIOPORCAP1_CAPPIO3_5_bit)

/*
+-----------------------------------------------------------------------------+
| BODCTRL - BOD control register
+-----------------------------------------------------------------------------+
*/

#define BODCTRL_BODRSTLEV_bit				0
#define BODCTRL_BODRSTLEV_0_bit				0
#define BODCTRL_BODRSTLEV_1_bit				1
#define BODCTRL_BODINTVAL_bit				2
#define BODCTRL_BODINTVAL_0_bit				2
#define BODCTRL_BODINTVAL_1_bit				3
#define BODCTRL_BODRSTENA_bit				4

#define BODCTRL_BODRSTLEV_0					(1 << BODCTRL_BODRSTLEV_0_bit)
#define BODCTRL_BODRSTLEV_1					(1 << BODCTRL_BODRSTLEV_1_bit)
#define BODCTRL_BODINTVAL_0					(1 << BODCTRL_BODINTVAL_0_bit)
#define BODCTRL_BODINTVAL_1					(1 << BODCTRL_BODINTVAL_1_bit)
#define BODCTRL_BODRSTENA					(1 << BODCTRL_BODRSTENA_bit)

#define BODCTRL_BODRSTLEV_LEVEL0_value		0
#define BODCTRL_BODRSTLEV_LEVEL1_value		1
#define BODCTRL_BODRSTLEV_LEVEL2_value		2
#define BODCTRL_BODRSTLEV_LEVEL3_value		3
#define BODCTRL_BODRSTLEV_mask				3

#define BODCTRL_BODINTVAL_LEVEL0_value		0
#define BODCTRL_BODINTVAL_LEVEL1_value		1
#define BODCTRL_BODINTVAL_LEVEL2_value		2
#define BODCTRL_BODINTVAL_LEVEL3_value		3
#define BODCTRL_BODINTVAL_mask				3

#define BODCTRL_BODRSTLEV_LEVEL0			(BODCTRL_BODRSTLEV_LEVEL0_value << BODCTRL_BODRSTLEV_bit)
#define BODCTRL_BODRSTLEV_LEVEL1			(BODCTRL_BODRSTLEV_LEVEL1_value << BODCTRL_BODRSTLEV_bit)
#define BODCTRL_BODRSTLEV_LEVEL2			(BODCTRL_BODRSTLEV_LEVEL2_value << BODCTRL_BODRSTLEV_bit)
#define BODCTRL_BODRSTLEV_LEVEL3			(BODCTRL_BODRSTLEV_LEVEL3_value << BODCTRL_BODRSTLEV_bit)

#define BODCTRL_BODINTVAL_LEVEL0			(BODCTRL_BODINTVAL_LEVEL0_value << BODCTRL_BODINTVAL_bit)
#define BODCTRL_BODINTVAL_LEVEL1			(BODCTRL_BODINTVAL_LEVEL1_value << BODCTRL_BODINTVAL_bit)
#define BODCTRL_BODINTVAL_LEVEL2			(BODCTRL_BODINTVAL_LEVEL2_value << BODCTRL_BODINTVAL_bit)
#define BODCTRL_BODINTVAL_LEVEL3			(BODCTRL_BODINTVAL_LEVEL3_value << BODCTRL_BODINTVAL_bit)

/*
+-----------------------------------------------------------------------------+
| SYSTCKCAL - System tick timer calibration register
+-----------------------------------------------------------------------------+
*/

#define SYSTCKCAL_CAL_bit					0
#define SYSTCKCAL_CAL_0_bit					0
#define SYSTCKCAL_CAL_1_bit					1
#define SYSTCKCAL_CAL_2_bit					2
#define SYSTCKCAL_CAL_3_bit					3
#define SYSTCKCAL_CAL_4_bit					4
#define SYSTCKCAL_CAL_5_bit					5
#define SYSTCKCAL_CAL_6_bit					6
#define SYSTCKCAL_CAL_7_bit					7
#define SYSTCKCAL_CAL_8_bit					8
#define SYSTCKCAL_CAL_9_bit					9
#define SYSTCKCAL_CAL_10_bit				10
#define SYSTCKCAL_CAL_11_bit				11
#define SYSTCKCAL_CAL_12_bit				12
#define SYSTCKCAL_CAL_13_bit				13
#define SYSTCKCAL_CAL_14_bit				14
#define SYSTCKCAL_CAL_15_bit				15
#define SYSTCKCAL_CAL_16_bit				16
#define SYSTCKCAL_CAL_17_bit				17
#define SYSTCKCAL_CAL_18_bit				18
#define SYSTCKCAL_CAL_19_bit				19
#define SYSTCKCAL_CAL_20_bit				20
#define SYSTCKCAL_CAL_21_bit				21
#define SYSTCKCAL_CAL_22_bit				22
#define SYSTCKCAL_CAL_23_bit				23
#define SYSTCKCAL_CAL_24_bit				24
#define SYSTCKCAL_CAL_25_bit				25

#define SYSTCKCAL_CAL_0						(1 << SYSTCKCAL_CAL_0_bit)
#define SYSTCKCAL_CAL_1						(1 << SYSTCKCAL_CAL_1_bit)
#define SYSTCKCAL_CAL_2						(1 << SYSTCKCAL_CAL_2_bit)
#define SYSTCKCAL_CAL_3						(1 << SYSTCKCAL_CAL_3_bit)
#define SYSTCKCAL_CAL_4						(1 << SYSTCKCAL_CAL_4_bit)
#define SYSTCKCAL_CAL_5						(1 << SYSTCKCAL_CAL_5_bit)
#define SYSTCKCAL_CAL_6						(1 << SYSTCKCAL_CAL_6_bit)
#define SYSTCKCAL_CAL_7						(1 << SYSTCKCAL_CAL_7_bit)
#define SYSTCKCAL_CAL_8						(1 << SYSTCKCAL_CAL_8_bit)
#define SYSTCKCAL_CAL_9						(1 << SYSTCKCAL_CAL_9_bit)
#define SYSTCKCAL_CAL_10					(1 << SYSTCKCAL_CAL_10_bit)
#define SYSTCKCAL_CAL_11					(1 << SYSTCKCAL_CAL_11_bit)
#define SYSTCKCAL_CAL_12					(1 << SYSTCKCAL_CAL_12_bit)
#define SYSTCKCAL_CAL_13					(1 << SYSTCKCAL_CAL_13_bit)
#define SYSTCKCAL_CAL_14					(1 << SYSTCKCAL_CAL_14_bit)
#define SYSTCKCAL_CAL_15					(1 << SYSTCKCAL_CAL_15_bit)
#define SYSTCKCAL_CAL_16					(1 << SYSTCKCAL_CAL_16_bit)
#define SYSTCKCAL_CAL_17					(1 << SYSTCKCAL_CAL_17_bit)
#define SYSTCKCAL_CAL_18					(1 << SYSTCKCAL_CAL_18_bit)
#define SYSTCKCAL_CAL_19					(1 << SYSTCKCAL_CAL_19_bit)
#define SYSTCKCAL_CAL_20					(1 << SYSTCKCAL_CAL_20_bit)
#define SYSTCKCAL_CAL_21					(1 << SYSTCKCAL_CAL_21_bit)
#define SYSTCKCAL_CAL_22					(1 << SYSTCKCAL_CAL_22_bit)
#define SYSTCKCAL_CAL_23					(1 << SYSTCKCAL_CAL_23_bit)
#define SYSTCKCAL_CAL_24					(1 << SYSTCKCAL_CAL_24_bit)
#define SYSTCKCAL_CAL_25					(1 << SYSTCKCAL_CAL_25_bit)

/*
+-----------------------------------------------------------------------------+
| STARTAPRP0 - Start logic edge control register 0
+-----------------------------------------------------------------------------+
*/

#define STARTAPRP0_APRPIO0_0_bit			0
#define STARTAPRP0_APRPIO0_1_bit			1
#define STARTAPRP0_APRPIO0_2_bit			2
#define STARTAPRP0_APRPIO0_3_bit			3
#define STARTAPRP0_APRPIO0_4_bit			4
#define STARTAPRP0_APRPIO0_5_bit			5
#define STARTAPRP0_APRPIO0_6_bit			6
#define STARTAPRP0_APRPIO0_7_bit			7
#define STARTAPRP0_APRPIO0_8_bit			8
#define STARTAPRP0_APRPIO0_9_bit			9
#define STARTAPRP0_APRPIO0_10_bit			10
#define STARTAPRP0_APRPIO0_11_bit			11
#define STARTAPRP0_APRPIO1_0_bit			12

#define STARTAPRP0_APRPIO0_0				(1 << STARTAPRP0_APRPIO0_0_bit)
#define STARTAPRP0_APRPIO0_1				(1 << STARTAPRP0_APRPIO0_1_bit)
#define STARTAPRP0_APRPIO0_2				(1 << STARTAPRP0_APRPIO0_2_bit)
#define STARTAPRP0_APRPIO0_3				(1 << STARTAPRP0_APRPIO0_3_bit)
#define STARTAPRP0_APRPIO0_4				(1 << STARTAPRP0_APRPIO0_4_bit)
#define STARTAPRP0_APRPIO0_5				(1 << STARTAPRP0_APRPIO0_5_bit)
#define STARTAPRP0_APRPIO0_6				(1 << STARTAPRP0_APRPIO0_6_bit)
#define STARTAPRP0_APRPIO0_7				(1 << STARTAPRP0_APRPIO0_7_bit)
#define STARTAPRP0_APRPIO0_8				(1 << STARTAPRP0_APRPIO0_8_bit)
#define STARTAPRP0_APRPIO0_9				(1 << STARTAPRP0_APRPIO0_9_bit)
#define STARTAPRP0_APRPIO0_10				(1 << STARTAPRP0_APRPIO0_10_bit)
#define STARTAPRP0_APRPIO0_11				(1 << STARTAPRP0_APRPIO0_11_bit)
#define STARTAPRP0_APRPIO1_0				(1 << STARTAPRP0_APRPIO1_0_bit)

/*
+-----------------------------------------------------------------------------+
| STARTERP0 - Start logic signal enable register 0
+-----------------------------------------------------------------------------+
*/

#define STARTERP0_ERPIO0_0_bit				0
#define STARTERP0_ERPIO0_1_bit				1
#define STARTERP0_ERPIO0_2_bit				2
#define STARTERP0_ERPIO0_3_bit				3
#define STARTERP0_ERPIO0_4_bit				4
#define STARTERP0_ERPIO0_5_bit				5
#define STARTERP0_ERPIO0_6_bit				6
#define STARTERP0_ERPIO0_7_bit				7
#define STARTERP0_ERPIO0_8_bit				8
#define STARTERP0_ERPIO0_9_bit				9
#define STARTERP0_ERPIO0_10_bit				10
#define STARTERP0_ERPIO0_11_bit				11
#define STARTERP0_ERPIO1_0_bit				12

#define STARTERP0_ERPIO0_0					(1 << STARTERP0_ERPIO0_0_bit)
#define STARTERP0_ERPIO0_1					(1 << STARTERP0_ERPIO0_1_bit)
#define STARTERP0_ERPIO0_2					(1 << STARTERP0_ERPIO0_2_bit)
#define STARTERP0_ERPIO0_3					(1 << STARTERP0_ERPIO0_3_bit)
#define STARTERP0_ERPIO0_4					(1 << STARTERP0_ERPIO0_4_bit)
#define STARTERP0_ERPIO0_5					(1 << STARTERP0_ERPIO0_5_bit)
#define STARTERP0_ERPIO0_6					(1 << STARTERP0_ERPIO0_6_bit)
#define STARTERP0_ERPIO0_7					(1 << STARTERP0_ERPIO0_7_bit)
#define STARTERP0_ERPIO0_8					(1 << STARTERP0_ERPIO0_8_bit)
#define STARTERP0_ERPIO0_9					(1 << STARTERP0_ERPIO0_9_bit)
#define STARTERP0_ERPIO0_10					(1 << STARTERP0_ERPIO0_10_bit)
#define STARTERP0_ERPIO0_11					(1 << STARTERP0_ERPIO0_11_bit)
#define STARTERP0_ERPIO1_0					(1 << STARTERP0_ERPIO1_0_bit)

/*
+-----------------------------------------------------------------------------+
| STARTRSRP0CLR - Start logic reset register 0
+-----------------------------------------------------------------------------+
*/

#define STARTRSRP0CLR_RSRPIO0_0_bit			0
#define STARTRSRP0CLR_RSRPIO0_1_bit			1
#define STARTRSRP0CLR_RSRPIO0_2_bit			2
#define STARTRSRP0CLR_RSRPIO0_3_bit			3
#define STARTRSRP0CLR_RSRPIO0_4_bit			4
#define STARTRSRP0CLR_RSRPIO0_5_bit			5
#define STARTRSRP0CLR_RSRPIO0_6_bit			6
#define STARTRSRP0CLR_RSRPIO0_7_bit			7
#define STARTRSRP0CLR_RSRPIO0_8_bit			8
#define STARTRSRP0CLR_RSRPIO0_9_bit			9
#define STARTRSRP0CLR_RSRPIO0_10_bit		10
#define STARTRSRP0CLR_RSRPIO0_11_bit		11
#define STARTRSRP0CLR_RSRPIO1_0_bit			12

#define STARTRSRP0CLR_RSRPIO0_0				(1 << STARTRSRP0CLR_RSRPIO0_0_bit)
#define STARTRSRP0CLR_RSRPIO0_1				(1 << STARTRSRP0CLR_RSRPIO0_1_bit)
#define STARTRSRP0CLR_RSRPIO0_2				(1 << STARTRSRP0CLR_RSRPIO0_2_bit)
#define STARTRSRP0CLR_RSRPIO0_3				(1 << STARTRSRP0CLR_RSRPIO0_3_bit)
#define STARTRSRP0CLR_RSRPIO0_4				(1 << STARTRSRP0CLR_RSRPIO0_4_bit)
#define STARTRSRP0CLR_RSRPIO0_5				(1 << STARTRSRP0CLR_RSRPIO0_5_bit)
#define STARTRSRP0CLR_RSRPIO0_6				(1 << STARTRSRP0CLR_RSRPIO0_6_bit)
#define STARTRSRP0CLR_RSRPIO0_7				(1 << STARTRSRP0CLR_RSRPIO0_7_bit)
#define STARTRSRP0CLR_RSRPIO0_8				(1 << STARTRSRP0CLR_RSRPIO0_8_bit)
#define STARTRSRP0CLR_RSRPIO0_9				(1 << STARTRSRP0CLR_RSRPIO0_9_bit)
#define STARTRSRP0CLR_RSRPIO0_10			(1 << STARTRSRP0CLR_RSRPIO0_10_bit)
#define STARTRSRP0CLR_RSRPIO0_11			(1 << STARTRSRP0CLR_RSRPIO0_11_bit)
#define STARTRSRP0CLR_RSRPIO1_0				(1 << STARTRSRP0CLR_RSRPIO1_0_bit)

/*
+-----------------------------------------------------------------------------+
| STARTSRP0 - Start logic status register 0
+-----------------------------------------------------------------------------+
*/

#define STARTSRP0_SRPIO0_0_bit				0
#define STARTSRP0_SRPIO0_1_bit				1
#define STARTSRP0_SRPIO0_2_bit				2
#define STARTSRP0_SRPIO0_3_bit				3
#define STARTSRP0_SRPIO0_4_bit				4
#define STARTSRP0_SRPIO0_5_bit				5
#define STARTSRP0_SRPIO0_6_bit				6
#define STARTSRP0_SRPIO0_7_bit				7
#define STARTSRP0_SRPIO0_8_bit				8
#define STARTSRP0_SRPIO0_9_bit				9
#define STARTSRP0_SRPIO0_10_bit				10
#define STARTSRP0_SRPIO0_11_bit				11
#define STARTSRP0_SRPIO1_0_bit				12

#define STARTSRP0_SRPIO0_0					(1 << STARTSRP0_SRPIO0_0_bit)
#define STARTSRP0_SRPIO0_1					(1 << STARTSRP0_SRPIO0_1_bit)
#define STARTSRP0_SRPIO0_2					(1 << STARTSRP0_SRPIO0_2_bit)
#define STARTSRP0_SRPIO0_3					(1 << STARTSRP0_SRPIO0_3_bit)
#define STARTSRP0_SRPIO0_4					(1 << STARTSRP0_SRPIO0_4_bit)
#define STARTSRP0_SRPIO0_5					(1 << STARTSRP0_SRPIO0_5_bit)
#define STARTSRP0_SRPIO0_6					(1 << STARTSRP0_SRPIO0_6_bit)
#define STARTSRP0_SRPIO0_7					(1 << STARTSRP0_SRPIO0_7_bit)
#define STARTSRP0_SRPIO0_8					(1 << STARTSRP0_SRPIO0_8_bit)
#define STARTSRP0_SRPIO0_9					(1 << STARTSRP0_SRPIO0_9_bit)
#define STARTSRP0_SRPIO0_10					(1 << STARTSRP0_SRPIO0_10_bit)
#define STARTSRP0_SRPIO0_11					(1 << STARTSRP0_SRPIO0_11_bit)
#define STARTSRP0_SRPIO1_0					(1 << STARTSRP0_SRPIO1_0_bit)

/*
+-----------------------------------------------------------------------------+
| PDSLEEPCFG - Deep-sleep mode configuration register
+-----------------------------------------------------------------------------+
*/

#define PDSLEEPCFG_BOD_PD_bit				3
#define PDSLEEPCFG_WDTOSC_PD_bit			6

#define PDSLEEPCFG_BOD_PD					(1 << PDSLEEPCFG_BOD_PD_bit)
#define PDSLEEPCFG_WDTOSC_PD				(1 << PDSLEEPCFG_WDTOSC_PD_bit)


/*
+-----------------------------------------------------------------------------+
| PDAWAKECFG - Wake-up configuration register
+-----------------------------------------------------------------------------+
*/

#define PDAWAKECFG_IRCOUT_PD_bit			0
#define PDAWAKECFG_IRC_PD_bit				1
#define PDAWAKECFG_FLASH_PD_bit				2
#define PDAWAKECFG_BOD_PD_bit				3
#define PDAWAKECFG_ADC_PD_bit				4
#define PDAWAKECFG_SYSOSC_PD_bit			5
#define PDAWAKECFG_WDTOSC_PD_bit			6
#define PDAWAKECFG_SYSPLL_PD_bit			7

#define PDAWAKECFG_IRCOUT_PD				(1 << PDAWAKECFG_IRCOUT_PD_bit)
#define PDAWAKECFG_IRC_PD					(1 << PDAWAKECFG_IRC_PD_bit)
#define PDAWAKECFG_FLASH_PD					(1 << PDAWAKECFG_FLASH_PD_bit)
#define PDAWAKECFG_BOD_PD					(1 << PDAWAKECFG_BOD_PD_bit)
#define PDAWAKECFG_ADC_PD					(1 << PDAWAKECFG_ADC_PD_bit)
#define PDAWAKECFG_SYSOSC_PD				(1 << PDAWAKECFG_SYSOSC_PD_bit)
#define PDAWAKECFG_WDTOSC_PD				(1 << PDAWAKECFG_WDTOSC_PD_bit)
#define PDAWAKECFG_SYSPLL_PD				(1 << PDAWAKECFG_SYSPLL_PD_bit)

/*
+-----------------------------------------------------------------------------+
| PDRUNCFG - Power-down configuration register
+-----------------------------------------------------------------------------+
*/

#define PDRUNCFG_IRCOUT_PD_bit				0
#define PDRUNCFG_IRC_PD_bit					1
#define PDRUNCFG_FLASH_PD_bit				2
#define PDRUNCFG_BOD_PD_bit					3
#define PDRUNCFG_ADC_PD_bit					4
#define PDRUNCFG_SYSOSC_PD_bit				5
#define PDRUNCFG_WDTOSC_PD_bit				6
#define PDRUNCFG_SYSPLL_PD_bit				7

#define PDRUNCFG_IRCOUT_PD					(1 << PDRUNCFG_IRCOUT_PD_bit)
#define PDRUNCFG_IRC_PD						(1 << PDRUNCFG_IRC_PD_bit)
#define PDRUNCFG_FLASH_PD					(1 << PDRUNCFG_FLASH_PD_bit)
#define PDRUNCFG_BOD_PD						(1 << PDRUNCFG_BOD_PD_bit)
#define PDRUNCFG_ADC_PD						(1 << PDRUNCFG_ADC_PD_bit)
#define PDRUNCFG_SYSOSC_PD					(1 << PDRUNCFG_SYSOSC_PD_bit)
#define PDRUNCFG_WDTOSC_PD					(1 << PDRUNCFG_WDTOSC_PD_bit)
#define PDRUNCFG_SYSPLL_PD					(1 << PDRUNCFG_SYSPLL_PD_bit)

/*
+-----------------------------------------------------------------------------+
| DEVICE_ID - Device ID register
+-----------------------------------------------------------------------------+
*/

#define DEVICE_ID_DEVICEID_LPC1111FHN33_101_value	0x041E502B
#define DEVICE_ID_DEVICEID_LPC1111FHN33_201_value	0x0416502B
#define DEVICE_ID_DEVICEID_LPC1112FHN33_101_value	0x042D502B
#define DEVICE_ID_DEVICEID_LPC1112FHN33_201_value	0x0425502B
#define DEVICE_ID_DEVICEID_LPC1113FHN33_201_value	0x0434502B
#define DEVICE_ID_DEVICEID_LPC1113FHN33_301_value	0x0434102B
#define DEVICE_ID_DEVICEID_LPC1113FBD48_301_value	0x0434102B
#define DEVICE_ID_DEVICEID_LPC1114FHN33_201_value	0x0444502B
#define DEVICE_ID_DEVICEID_LPC1114FHN33_301_value	0x0444102B
#define DEVICE_ID_DEVICEID_LPC1114FBD48_301_value	0x0444102B
#define DEVICE_ID_DEVICEID_LPC1114FA44_301_value	0x0444102B
#define DEVICE_ID_DEVICEID_LPC11C12_FBD48_301_value	0x1421102B
#define DEVICE_ID_DEVICEID_LPC11C14_FBD48_301_value	0x1440102B

/*
+-----------------------------------------------------------------------------+
| FLASHCFG - Flash configuration register
+-----------------------------------------------------------------------------+
*/

// Why is this register missing from LPC11xx.h file?
// Temporary define it here for now...
#include <stdint.h>
#define FLASHCFG							(*(volatile uint32_t*)0x4003C010)
// end of temporary fix

#define FLASHCFG_FLASHTIM_bit				0
#define FLASHCFG_FLASHTIM_0_bit				0
#define FLASHCFG_FLASHTIM_1_bit				1

#define FLASHCFG_FLASHTIM_0					(1 << FLASHCFG_FLASHTIM_0_bit)
#define FLASHCFG_FLASHTIM_1					(1 << FLASHCFG_FLASHTIM_1_bit)

#define FLASHCFG_FLASHTIM_1CLK_value		0
#define FLASHCFG_FLASHTIM_2CLK_value		1
#define FLASHCFG_FLASHTIM_3CLK_value		2
#define FLASHCFG_FLASHTIM_mask				3

#define FLASHCFG_FLASHTIM_1CLK				(FLASHCFG_FLASHTIM_1CLK_value << FLASHCFG_FLASHTIM_bit)
#define FLASHCFG_FLASHTIM_2CLK				(FLASHCFG_FLASHTIM_2CLK_value << FLASHCFG_FLASHTIM_bit)
#define FLASHCFG_FLASHTIM_3CLK				(FLASHCFG_FLASHTIM_3CLK_value << FLASHCFG_FLASHTIM_bit)

/******************************************************************************
* END OF FILE
******************************************************************************/
#endif /* HDR_SYSCON_H_ */
