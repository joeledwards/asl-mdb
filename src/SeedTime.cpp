#include "SeedTime.h"

SeedTime::SeedTime(uint8_t *data, size_t data_length)
{
    raw = data;
    length = data_length;
    time = (struct seed_time *)data;
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

