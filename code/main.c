#include <stdio.h>
#include "platform.h"
#include "xil_printf.h"
#include "xparameters.h"
#include "xstatus.h"
#include "xgpio.h"

#define ID_GPIO XPAR_AXI_GPIO_0_DEVICE_ID
#define CHANNEL_LED 1

XGpio gpio;

int main()
{
    init_platform();
    XGpio_Initialize(&gpio, ID_GPIO);	// Initialize GPIO instance
    XGpio_SetDataDirection(&gpio, CHANNEL_LED, 0x00); // Set output
    XGpio_DiscreteWrite(&gpio, CHANNEL_LED, 0xC3);  // Write 1100_0011 to GPIO
    cleanup_platform();
    return 0;
}
