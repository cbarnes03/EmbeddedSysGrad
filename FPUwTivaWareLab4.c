#include <math.h>										// The code uses sinf() function which is prototyped by this header file 
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/fpu.h"								// This header file provides support for Floating Point Unit
#include "driverlib/sysctl.h"
#include "driverlib/rom.h"
#ifndef M_PI											// In the case of M_PI not being defined, ifndef defines it
#define M_PI 3.14159265358979323846
#endif
#define SERIES_LENGTH 100								// SERIES_LENGTH is the depth of our data buffer
float gSeriesData[SERIES_LENGTH];						// This line is an array of floats SERIES_LENGTH long
int dataCount = 0;										// This is a counter for our computation loop
int main(void)
{
float fRadians;											// This variable is needed to calculate sine
ROM_FPULazyStackingEnable();							
ROM_FPUEnable();										// Turns on the FPU
ROM_SysCtlClockSet(SYSCTL_SYSDIV_4|SYSCTL_USE_PLL|SYSCTL_XTAL_50MHZ|SYSCTL_OSC_MAIN);		// Sets up clock for 50MHz
fRadians = ((2 * M_PI) / SERIES_LENGTH);												
while(dataCount < SERIES_LENGTH)
{
gSeriesData[dataCount] = sinf(fRadians * dataCount);		// Calculates the full cycle of a sine wave in side a 100-data point long array
dataCount++;
}
while(1)													// The Suspend button traps the execution inside this endless While Loop
{
}
} 