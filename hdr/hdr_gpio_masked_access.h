/** \file hdr_gpio_masked_access.h
 * \brief Header for GPIO masked access in LPC11xx
 * \details This header contains definitions necessary for using GPIO masked
 * access feature of LPC11xx chips. GPIO masked access gives you the ability to
 * set the state of single GPIO pin (or group of pins) without affecting other
 * pins of the same port, avoiding possible read-modify-store problems. It is
 * also possible to use GPIO masked access to get the state of single GPIO pin
 * (or group of pins) without any masking (single read operation).
 *
 * To use this mechanism in an convenient way add three definitions to your
 * code (in the example PIO1_5 (port 1, pin 5) is used):
 * - #define SOMETHING_GPIO LPC_GPIO1 // GPIO port of the pin
 * - #define SOMETHING_pin 5 // number of the pin
 * - #define SOMETHING (1 << SOMETHING_pin) // bit mask
 *
 * Then you can define a GPIO masked access "variable" using the macros from
 * this header:
 * - #define SOMETHING_gma gpio_masked_access_t GPIO_MASKED_ACCESS(SOMETHING_GPIO, SOMETHING_pin)
 *
 * Changing the state of the pin is then very simple:
 * - SOMETHING_gma = 0;			// pin state == 0
 * - SOMETHING_gma = SOMETHING;	// pin state == 1
 *
 * To set pin state to 0 you can actually write any number that has binary 0 on
 * SOMETHING_pin bit, so these are equivalent:
 * - SOMETHING_gma = 0;
 * - SOMETHING_gma = ANYTHING & ~(SOMETHING);
 * - SOMETHING_gma = 0xFFFFFFFF & ~(SOMETHING);
 * - ...
 *
 * The same is true for setting pin state to 1, so these are also equivalent:
 * - SOMETHING_gma = SOMETHING;
 * - SOMETHING_gma = SOMETHING | ANYTHING;
 * - SOMETHING_gma = 0xFFFFFFFF;
 * - ...
 *
 * You can also get the state of the pin by reading this "variable":
 * - uint32_t state_of_pin = SOMETHING_gma; // if pin state == 0, state_of_pin == 0, otherwise state_of_pin == SOMETHING
 *
 * \author Freddie Chopin, http://www.freddiechopin.info/
 * \date 2012-01-08
 */

/******************************************************************************
* chip: LPC11xx
* compiler: arm-none-eabi-gcc (Sourcery CodeBench Lite 2011.09-69) 4.6.1
******************************************************************************/

#ifndef HDR_GPIO_MASKED_ACCESS_H_
#define HDR_GPIO_MASKED_ACCESS_H_

#include <stdint.h>

/*
+=============================================================================+
| strange variables
+=============================================================================+
*/

/// GPIO masked access "variable" type
#define gpio_masked_access_t				*(volatile uint32_t*)

/*
+=============================================================================+
| macros
+=============================================================================+
*/

/// macro used to calculate the address on the bus that is used to access selected pin
#define GPIO_MASKED_ACCESS(gpio, pin)		((uint32_t)gpio + (1 << (pin + 2)))

/******************************************************************************
* END OF FILE
******************************************************************************/
#endif /* HDR_GPIO_MASKED_ACCESS_H_ */
