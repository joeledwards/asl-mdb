#include "SeedTime.h"
#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>

SeedTime::SeedTime(struct seed_time *time)
{
    this->time = time;
}

// Time methods
unsigned short SeedTime::getYear()
{
    return ntohs(time->year);
}

unsigned short SeedTime::getYDay()
{
    return ntohs(time->yday);
}

unsigned short SeedTime::getMonth()
{
    //TODO: complete
    return 0;
}

unsigned short SeedTime::getDay()
{
    //TODO: complete
    return 0;
}

unsigned short SeedTime::getHour()
{
    return time->hour;
}

unsigned short SeedTime::getMinute()
{
    return time->minute;
}

unsigned short SeedTime::getSecond()
{
    return time->second;
}

unsigned short SeedTime::getHUsecond()
{
    return ntohs(time->husecond);
}

