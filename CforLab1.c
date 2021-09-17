#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "driverlib/sysctl.h"
#include "driverlib/pin_map.h"
#include "driverlib/debug.h"
#include "driverlib/gpio.h"
int main(void)
{
SysCtlClockSet(SYSCTL_SYSDIV_5|SYSCTL_USE_PLL|SYSCTL_XTAL_16MHZ|SYSCTL_OSC_MAIN); // Sets Clock Freq to 16MHz
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);	// Enables the use of general purpise Input/Outputs
	GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3); // Declares that Pins 1, 2, 3 are Outputs
while(1){	//Beginning of infinite WHILE loop
	GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3, 0x08); // 0x08 = 1000 in binary, this enables the 4th bit(pin 3) and turns on the LED
	SysCtlDelay(20000000); // Adds 20,000,000 cycle delay = 1.25seconds
	GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3, 0x00); // 0x00 = 0000 in binary, this disables the 4th bit(pin 3) and turns off the LED
	SysCtlDelay(20000000); // Adds 20,000,000 cycle delay = 1.25seconds
}
}
