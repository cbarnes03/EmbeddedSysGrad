#include <stdint.h>
#include <stdbool.h>
#include "utils/ustdlib.h"
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "driverlib/sysctl.h"
#include "driverlib/pin_map.h"
#include "driverlib/debug.h"
#include "driverlib/hibernate.h"
#include "driverlib/gpio.h"
// The above are the required libraries necessary to execute this experiment
int main(void) // main function
{
SysCtlClockSet(SYSCTL_SYSDIV_5|SYSCTL_USE_PLL|SYSCTL_XTAL_16MHZ|SYSCTL_OSC_MAIN); 				// sets the SysCtlClock to 16MHz
SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF); 													// enables the required peripherals for the GPIO
GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3);  						// Declares the GPIO pins (Pins 1,2,3) as OUTPUTs
GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3, 0x08); 							// Writes the above pins and which turns on the LED
SysCtlPeripheralEnable(SYSCTL_PERIPH_HIBERNATE); 												// Enables the required periphals in to allow hibernation
HibernateEnableExpClk(SysCtlClockGet()); 														// Enables the SysCtlClock to allow for Hibernation
HibernateGPIORetentionEnable(); 																// Enables GPIO to hibernate 
SysCtlDelay(64000000); 																			// Adds a delay to for approximately 4 seconds
HibernateRTCSet(0); 																			// Sets the Real Time Clock to allow for the interrupt of the hibernation
HibernateRTCEnable(); 																			// Enables Hibernate
HibernateRTCMatchSet(0,5);																		// Sets the points at which the RTC will trigger interrupt (after 5 seconds)
HibernateWakeSet(HIBERNATE_WAKE_PIN | HIBERNATE_WAKE_RTC); 										// Defines the wakeup process
GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_3, 0x00); 												// Writes to the Pin 3 which turns off the LED
HibernateRequest(); 																			// Requests Hibernate to turn on for the times when LED is off
while(1) 																						// sets the system to repeat
{
}
}
