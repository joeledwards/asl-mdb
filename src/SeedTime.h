#ifndef __SEEDRECORD_H__
#define __SEEDRECORD_H__

#include "seed.h"
#include <sys/types.h>
#include <arpa/inet.h>
#include <string>

class SeedTime
{
    uint8_t *raw;
    size_t   length;
    struct seed_time *time;

    public:

    SeedTime(uint8_t *data, size_t length);

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
