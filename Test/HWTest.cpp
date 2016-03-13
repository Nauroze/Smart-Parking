//============================================================================
// Name        : HWTest.cpp
// Author      : MK
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <BlackADC.h>
#include <BlackGPIO.h>
#include <unistd.h>
#include "GPIOEXP.h"
#include "GPIOVal.h"

#define Spots 15
#define TreshValue 20
using namespace BlackLib;

using namespace std;
int* GetArray();
int LEDStatus(int,int,int,string);

int SensorValue [Spots];
int ParkingLocation [Spots];
string ParkingStatus[Spots];

int main() {

	GPIOEXP(30); // MUX1 SENSORS
	GPIOEXP(31); // MUX1 SENSORS
	GPIOEXP(48); // MUX1 SENSORS


			 while(true){
				BlackADC myAdc(AIN0);
				int i = 0;
						for (int C =0;C<2;C++){
							for (int B=0;B<2; B++){
								for (int A=0; A<2;A++){

										GPIOVal(30,A);
										GPIOVal(31,B);
										GPIOVal(48,C);

										int val1 = myAdc.getNumericValue();
										SensorValue[i]=val1;

												if (i < 9){
													if (val1 < TreshValue){
													ParkingLocation[i]= 0;
													ParkingStatus[i]="Empty";
													LEDStatus(A,B,C,ParkingStatus[i]);
													}
													if(val1 >= TreshValue) {
														ParkingLocation[i]= 1;
														ParkingStatus[i]="Occupied";
														LEDStatus(A,B,C,ParkingStatus[i]);
													}

												//sleep(1);
												}
												i++;
										}
									}
								}


		for(int x=0; x<8;x++){
		cout << "*******\n";
		cout << "Sensor # "<<x<<": "<< SensorValue[x]<<" mV << ";
	 	cout << "LOT "<<x<<": "<< ParkingLocation[x]<<" << ";
	 	cout << "LOT "<<x<<": "<< ParkingStatus[x]<<" >> ";
	 	cout << "*******\n";
		}
	sleep(1);
	}
 return 0;
}

int* GetArray(){

	return ParkingLocation;
}
int LEDStatus(int A,int B, int C, string Val){


}
