#ifndef PARKINGSPACE_H
#define PARKINGSPACE_H

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


class ParkingSpace
{
public:
    ParkingSpace();      

    char getStatus();
    void setStatus(char x);
    int getTime();
    void setTime_in();
    void setTime_out();
    int getDuration();
    void checkIn();
    void checkOut();
    double getCost();
    void setResId();
    int getResId();
    void resetAll();


private:

    string spaceID;
    char status;
    int time_in;
    int time_out;
    string carID;
    int time_parked;
    int time_left;
    int month_seconds;
    double unit_cost;
    double total_cost;
    int resID;


};

#endif // PARKINGSPACE_H
