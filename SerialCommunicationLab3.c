#include<stdint.h>														// includes required libraries
#include<stdbool.h>
#include"inc/hw_memmap.h"
#include"inc/hw_types.h"
#include"driverlib/gpio.h"
#include"driverlib/pin_map.h"
#include"driverlib/sysctl.h"
#include"driverlib/uart.h"
 
#define GPIO_PA0_U0RX 0x00000001
#define GPIO_PA1_U0TX 0x00000401
intmain(void) 
{
SysCtlClockSet(SYSCTL_SYSDIV_5|SYSCTL_USE_PLL|SYSCTL_OSC_MAIN| 			// enables sysctl for 16MHz
SYSCTL_XTAL_16MHZ);
SysCtlPeripheralEnable(SYSCTL_PERIPH_UART0); 							// enables sysctl for Peripheral UART0
SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);							// Enables sysctl for GPIOA
GPIOPinConfigure(GPIO_PA0_U0RX); 										// Configures GPIO PA0 to the receiver			
GPIOPinConfigure(GPIO_PA1_U0TX); 										// Configures GPIO PA1 to the transmitter
GPIOPinTypeUART(GPIO_PORTA_BASE, GPIO_PIN_0 | GPIO_PIN_1);				// Delcares GPIO PORTA for UART 
UARTConfigSetExpClk(UART0_BASE, SysCtlClockGet(), 115200, 				// Sets Baud Rate for the UART Clk
(UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE | UART_CONFIG_PAR_NONE)); 	// 
UARTCharPut(UART0_BASE, 'E'); 											// displays the Echo Output on the Tera Term UART windows
UARTCharPut(UART0_BASE, 'c'); 
UARTCharPut(UART0_BASE, 'h');
UARTCharPut(UART0_BASE, 'o');
UARTCharPut(UART0_BASE, ' ');
UARTCharPut(UART0_BASE, 'O'); 
UARTCharPut(UART0_BASE, 'u'); 
UARTCharPut(UART0_BASE, 't'); 
UARTCharPut(UART0_BASE, 'p'); 
UARTCharPut(UART0_BASE, 'u'); 
UARTCharPut(UART0_BASE, 't'); 
UARTCharPut(UART0_BASE, ': '); 
UARTCharPut(UART0_BASE, ' '); 
UARTCharPut(UART0_BASE, '\n');
 
while (1)																// While loop to allow for UART operation
if (UARTCharsAvail(UART0_BASE)) UARTCharPut(UART0_BASE, 
UARTCharGet(UART0_BASE));
}
}