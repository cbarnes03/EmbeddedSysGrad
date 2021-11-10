#include <stdint.h>
#include <stdbool.h>
#include "inc/tm4c123gh6pm.h"
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/sysctl.h" 
#include "driverlib/interrupt.h"
#include "driverlib/gpio.h"
#include "driverlib/timer.h" // includes all necessary library and drivers to execute this program
int main(void)
{
uint32_t ui32Period;
SysCtlClockSet(SYSCTL_SYSDIV_5|SYSCTL_USE_PLL|SYSCTL_XTAL_16MHZ|
SYSCTL_OSC_MAIN); //enabling system clock
SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_3|GPIO_PIN_2| 
GPIO_PIN_3);  //enabling GPIO Pin 3 as Output
SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER0);
TimerConfigure(TIMER0_BASE, TIMER_CFG_PERIODIC);
ui32Period = (SysCtlClockGet() / 10) / .5;  //configuring the period
TimerLoadSet(TIMER0_BASE, TIMER_A, ui32Period -1);
IntEnable(INT_TIMER0A);
TimerIntEnable(TIMER0_BASE, TIMER_TIMA_TIMEOUT);
IntMasterEnable();
TimerEnable(TIMER0_BASE, TIMER_A);
while(1)
{
}
}
void TIMER0A_Handler(void) //Interrupt Service Routine
{
// Clear the timer interrupt
TimerIntClear(TIMER0_BASE, TIMER_TIMA_TIMEOUT);
// Read the current state of the GPIO pin and+
// write back the opposite state
if(GPIOPinRead(GPIO_PORTF_BASE, GPIO_PIN_3))
{
GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3, 0); //writing 0 to GPIO PF3
}
else
{
GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3, 8); //writing 8 in hex to the GPIO PF3
}
}
