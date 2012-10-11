#ifndef __SEEDTIME_H__
#define __SEEDTIME_H__

#include "Seed.h"
#include <sys/types.h>
#include <arpa/inet.h>
#include <string>

class SeedTime
{
    struct seed_time *time;

    public:

    SeedTime(struct seed_time *time);

    unsigned short getYear();
    unsigned short getYDay();
    unsigned short getMonth();
    unsigned short getDay();
    unsigned short getHour();
    unsigned short getMinute();
    unsigned short getSecond();
    unsigned short getHUsecond();
};
#endif
