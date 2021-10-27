#include <math.h>
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/fpu.h"
#include "driverlib/sysctl.h"
#include "driverlib/rom.h"
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
#define SERIES_LENGTH 100
float gSeriesData[SERIES_LENGTH];
int dataCount = 0;
int main(void)
{
float fRadians;											// this variable is needed to calculate sine
ROM_FPULazyStackingEnable();							
ROM_FPUEnable();										// turns on the FPU
ROM_SysCtlClockSet(SYSCTL_SYSDIV_4|SYSCTL_USE_PLL|SYSCTL_XTAL_50MHZ|SYSCTL_OSC_MAIN);		// Sets up clock for 50MHz
fRadians = ((2 * M_PI) / SERIES_LENGTH);												
while(dataCount < SERIES_LENGTH)
{
gSeriesData[dataCount] = sinf(fRadians * dataCount);		// Calculates the full cycle of a sine wave in side a 100-data point long array
dataCount++;
}
while(1)													// the Suspend button traps the execution inside this endless While Loop
{
}
} 