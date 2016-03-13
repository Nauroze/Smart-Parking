/*
 * GPIOVal.cpp
 *
 *  Created on: Feb 7, 2015
 *      Author: mahmoudkhalaf
 */
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <BlackADC.h>
#include <BlackGPIO.h>
#include <unistd.h>
#include "GPIOVal.h"

GPIOVal::GPIOVal(int GPIOPin, int Val) {
	FILE *GPIOHandle = NULL;


			sprintf(GPIOValue, "/sys/class/gpio/gpio%d/value", GPIOPin);

			if ((GPIOHandle = fopen(GPIOValue, "rb+")) == NULL){
						printf("cant change value handle. \n");

					}
			if (Val == 0){
					strcpy (setValue, "0");
					fwrite(&setValue, sizeof(char), 3, GPIOHandle);
					fclose(GPIOHandle);
				}
			if (Val == 1){
				strcpy (setValue, "1");
				fwrite(&setValue, sizeof(char), 3, GPIOHandle);
				fclose(GPIOHandle);
}
}
GPIOVal::~GPIOVal() {
	// TODO Auto-generated destructor stub
}

