#ifndef __SEEDRECORD_H__
#define __SEEDRECORD_H__

#include "Seed.h"
#include "SeedTime.h"
#include "SeedBlockette1000.h"
#include <sys/types.h>
#include <arpa/inet.h>
#include <string>

class SeedRecord
{
    uint8_t *raw;
    size_t   length;
    struct seed_header *header;

    public:

    SeedRecord(uint8_t *data, size_t length);

    uint16_t getRecordLength();

    unsigned long getSequenceNumber();
    char getQualityIndicator();

    std::string getNetwork();
    std::string getStation();
    std::string getLocation();
    std::string getChannel();

	SeedTime *getStartTime();

    unsigned short getNumberOfSamples();
    short getSampleRateFactor();
    short getSampleRateMultiplier();
    uint8_t getActivityFlags();
    uint8_t getIOAndClockFlags();
    uint8_t getDataQualityFlags();
    uint8_t getNumberOfBlockettes();
    long getTimeCorrection();
    size_t getBeginningOfData();
    size_t getFirstBlockette();


};
#endif
