#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <BlackADC.h>
#include <BlackGPIO.h>
#include <unistd.h>
#include "GPIOEXP.h"

GPIOEXP::GPIOEXP(int GPIOPin) {
	FILE *GPIOHandle = NULL;

			sprintf(GPIOString, "%d", GPIOPin);
			sprintf(GPIOValue, "/sys/class/gpio/gpio%d/value", GPIOPin);
			sprintf(GPIODirection, "/sys/class/gpio/gpio%d/direction", GPIOPin);

			//Export The PIN

			if ((GPIOHandle = fopen("/sys/class/gpio/export", "ab")) == NULL) {
			//	printf("CANT OPEN pin. \n");

			}
			strcpy(setValue, GPIOString);
			fwrite(&setValue, sizeof(char), 2, GPIOHandle);
			fclose(GPIOHandle);

			// Set the Direction of the pin
			if ((GPIOHandle = fopen(GPIODirection, "rb+")) == NULL) {
			//	printf("cant open direction handle. \n");

			}
			strcpy(setValue, "out");
			fwrite(&setValue, sizeof(char), 3, GPIOHandle);
			fclose(GPIOHandle);


}


GPIOEXP::~GPIOEXP() {
	// TODO Auto-generated destructor stub
}

