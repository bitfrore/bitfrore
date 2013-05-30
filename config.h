/** \file config.h
 * \brief Basic configuration of the project
 * \author Freddie Chopin, http://www.freddiechopin.info/
 * \date 2012-01-08
 */

/******************************************************************************
* project: lpc1114_blink_led
* chip: LPC1114
* compiler: arm-none-eabi-gcc (Sourcery CodeBench Lite 2011.09-69) 4.6.1
******************************************************************************/

#ifndef CONFIG_H_
#define CONFIG_H_

#include "hdr/hdr_gpio_masked_access.h"

/*
+=============================================================================+
| global definitions
+=============================================================================+
*/

#define CRYSTAL								12000000	///< quartz crystal resonator which is connected to the chip
#define FREQUENCY							50000000	///< desired target frequency of the core

#define LED_GPIO							LPC_GPIO1	///< GPIO port to which the LED is connected

#define LED_pin								8			///< pin number of the LED

#define LED									(1 << LED_pin)

/// "variable" to manipulate the pin directly via GPIO masked access
#define LED_gma								gpio_masked_access_t GPIO_MASKED_ACCESS(LED_GPIO, LED_pin)

#define MOTOR_GPIO							LPC_GPIO1	///< GPIO port to which the LED is connected
#define MOTOR_pin								9			///< pin number of the LED
#define MOTOR									(1 << MOTOR_pin)

/// "variable" to manipulate the pin directly via GPIO masked access
#define MOTOR_gma								gpio_masked_access_t GPIO_MASKED_ACCESS(MOTOR_GPIO, MOTOR_pin)


/*
+=============================================================================+
| strange variables
+=============================================================================+
*/

/*
+=============================================================================+
| global variables
+=============================================================================+
*/

/*
+=============================================================================+
| global functions' declarations
+=============================================================================+
*/

/******************************************************************************
* END OF FILE
******************************************************************************/
#endif /* CONFIG_H_ */
