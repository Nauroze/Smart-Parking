#include "ParkingSpace.h"

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
#include <time.h>

using namespace std;

ParkingSpace::ParkingSpace()
{
    spaceID="Null";
    status='E';
    time_in=0;
    time_out=0;
    carID="0";
    unit_cost= 0.00138; //cost per second
    total_cost=0;


}

char ParkingSpace::getStatus() {

    return status;
}

void ParkingSpace::setStatus(char x)
{
    status=x;
}

void ParkingSpace::setTime_in()
{
    time_in = getTime();

}


void ParkingSpace::setTime_out()
{
    time_out = getTime();
}

int ParkingSpace::getTime()
{
     time_t rawtime = time(0);
     struct tm * timeinfo = localtime(&rawtime);

   return ((timeinfo->tm_yday)*86400 +(timeinfo->tm_hour)*3600 + (timeinfo->tm_min)*60 + (timeinfo->tm_sec));
}


int ParkingSpace::getDuration()
{
    if (time_in==NULL)
    {return 0;}
    return (time_out - time_in);
}

void ParkingSpace:: checkIn()
{
    setStatus('R');
    setTime_in();
}


void ParkingSpace:: checkOut()
{
    setStatus('E');
    setTime_out();
}

double ParkingSpace:: getCost()
{
    total_cost=getDuration()*unit_cost;

    total_cost= floor(total_cost*100+0.5)/100;

    return total_cost;
}

void ParkingSpace::setResId()  //For now, if bar code works, cool, if it doesn't work, generate the number in mainwindow to avoid the generation of the same number again.
{
   srand(time(NULL));
   resID=rand() % 9000 + 1000;
}

int ParkingSpace::getResId()
{
    if (resID!=NULL)
    {
        return resID;
    }
    return 0;
}

void ParkingSpace::resetAll()
{
    resID=NULL;
    spaceID="Null";
    status='E';
    time_in=0;
    time_out=0;
    carID="0";
    total_cost=0;

}
