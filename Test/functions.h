
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include <stdbool.h>
#include <time.h> 
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//const int size 20;

typedef struct {
	//char spaceID[6];
	string spaceID;
        char status;
	char time_in[20];
	char time_out[20];
	char carID[20];
} PARKING_SPACE;

typedef struct {
    PARKING_SPACE *spaces;
} PARKING_LOT;

char getStatus(PARKING_SPACE temp[], int x);

//void displayLot(PARKING_SPACE temp[]);
//void getTime(char *temp);
//void checkIn(PARKING_SPACE temp[]);
//void checkOut(PARKING_SPACE temp[]);
//PARKING_SPACE *getEmptySpace(PARKING_SPACE temp[]);
//PARKING_SPACE *getSpace(PARKING_SPACE temp[],char * carID);
//void reserveSpace (PARKING_SPACE temp[], char * carID);
//void cancelReserveSpace (PARKING_SPACE temp[], char * carID);
//void printDuration(char *checkIn, char* checkOut);
//

