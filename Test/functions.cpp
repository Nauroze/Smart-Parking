
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include <stdbool.h>
#include <time.h>  

#include "functions.h"

char getStatus(PARKING_SPACE temp[], int x) {
    if ((temp.size())<x||x<0)
    {
        return '*';
    }

    return temp[x].status;
}

//PARKING_SPACE* getEmptySPACE(PARKING_SPACE temp[]){
//	PARKING_SPACE *emptySpace;
//	for (int i=0; i<10; i++) {
//		emptySpace = &temp[i];
//		if(emptySpace->status == 'E') {
//			return emptySpace;
//		}
//	}
//	return NULL;
//}

//PARKING_SPACE* getSpace(PARKING_SPACE temp[],char * carID){
//	PARKING_SPACE *SPACE;
//	for (int i=0; i<10; i++) {
//		SPACE = &temp[i];
//		if(strcmp(SPACE->carID, carID)==0) {
//			return SPACE;
//		}
//	}
//	return NULL;
//}




//void getTime(char *temp) {
//  time_t rawtime;
//  struct tm * timeinfo;

//  time ( &rawtime );
//  timeinfo = localtime ( &rawtime );
//  strcpy(temp,asctime (timeinfo));
//}

//void checkIn(PARKING_SPACE temp[]){
//	PARKING_SPACE *emptySpace = getEmptySPACE(temp); // get unocupied space

//	if (emptySpace != NULL ) {
//		emptySpace->status = 'O';
//		getTime((emptySpace->time_in));
//		printf("Enter car's ID: ");
//		scanf("%s",(emptySpace->carID));
//	}else {
//		printf("Sorry the parking lot is full,\n");
//	}
//}

//void checkOut(PARKING_SPACE temp[]){
//	char carID[80];
//	printf("Please enter carID: ");
//	scanf("%s",carID);
//	PARKING_SPACE *Space = getSpace(temp,carID); // find car on checkout
	
//	if(Space!=NULL) {
//		Space->status = 'E';
//		getTime((Space->time_out));
//		strcpy((Space->carID),"----");
//		printf("hr:min -> "); printDuration(Space->time_in, Space->time_out); printf("\n");
//	} else {
//		printf("Sorry the Car's ID can not be identified\n");
//    }
//}

//void displayLot(PARKING_SPACE temp[]){
//	cout << endl;
//	for(int i=8; i>=0; i-=2) {
//		cout<< "|  ["<< temp[i].spaceID <<"] "<< temp[i].status << " by (" << temp[i].carID << ")          ("<<
//        temp[i+1].carID << ") is " << temp[i+1].status  << " [" << temp[i+1].spaceID <<"]  |" << endl;
//	}
//	printf("\n");
//}

//void reserveSpace (PARKING_SPACE temp[], char * carID){
//	PARKING_SPACE *space = NULL;
//	int i;
//	for(i=10-1; i>=(0.75*(10-1));i--) {
//		space = &temp[i];
//		if(space->status=='E') {
//			space->status = 'R';
//			getTime(space->time_in);
//			strcpy(space->carID,carID);
//			break;
//		}
//    }
// 	if(i<0.75*(10-1)) { cout <<"Sorry we are fully booked"<< endl; }
//}

//void cancelReserveSpace (PARKING_SPACE temp[], char * carID) {
//    PARKING_SPACE *space = getSpace( temp, carID);
//    if( space != NULL ) {
//        if(space->status == 'B') {
//             space->status = 'E';
//             strcpy(space->carID,"----");
//        }
//    }
//}

//void printDuration(char *checkIn, char* checkOut){
//	char day[4], month[4], date [3], hours[3], minutes[3], seconds[3];
//	int day2, month2, date2, hours2, minutes2, seconds2;
	
//	strncpy(day,checkIn+0,3); strncpy(month,checkIn+4,3);
//	strncpy(date,checkIn+8,2); strncpy(hours,checkIn+11,2);
//	strncpy(minutes,checkIn+14,2); strncpy(seconds,checkIn+17,2);
//	day[3] = month[3] = hours[2] = minutes[2] = seconds[2] = '\0';
	
//	date2 = atoi(date); hours2 = atoi(hours); minutes2 = atoi(minutes);

//	strncpy(day,checkOut+0,3); strncpy(month,checkOut+4,3);
//	strncpy(date,checkOut+8,2); strncpy(hours,checkOut+11,2);
//	strncpy(minutes,checkOut+14,2); strncpy(seconds,checkOut+17,2);
//	day[3] = month[3] = hours[2] = minutes[2] = seconds[2] = '\0';

//	//printf("%s  %s  %d %d:%d:%s \n",day, month, atoi(date)-date2, atoi(hours)-hours2,  atoi(minutes)-minutes2, 0);

//	printf("%d:%d",atoi(hours)-hours2,atoi(minutes)-minutes2);

//}
