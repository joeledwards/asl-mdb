#include "SeedRecord.h"

SeedRecord::SeedRecord(uint8_t *data, size_t data_length)
{
    raw = data;
    length = data_length;
    header = (struct seed_header *)raw;
}

uint16_t SeedRecord::getRecordLength()
{
    return 0;
}

unsigned long SeedRecord::getSequenceNumber()
{
    return (unsigned long)atol(header->sequence_number);
}

char SeedRecord::getQualityIndicator()
{
    return header->quality_indicator;
}

std::string SeedRecord::getNetwork()
{
    return std::string(header->network, 2);
}

std::string SeedRecord::getStation()
{
    return std::string(header->station, 5);
}

std::string SeedRecord::getLocation()
{
    return std::string(header->location, 2);
}

std::string SeedRecord::getChannel()
{
    return std::string(header->channel, 3);
}

SeedTime * SeedRecord::getStartTime()
{

    return new SeedTime(&header->start_time);
}

unsigned short SeedRecord::getNumberOfSamples()
{
    return ntohs(header->number_of_samples); 
}

short SeedRecord::getSampleRateFactor()
{
    return ntohs(header->sample_rate_factor);
}

short SeedRecord::getSampleRateMultiplier()
{
    return ntohs(header->sample_rate_multiplier);
}

uint8_t SeedRecord::getActivityFlags()
{
    return ntohs(header->activity_flags);
}

uint8_t SeedRecord::getIOAndClockFlags()
{
    return ntohs(header->io_and_clock_flags);
}

uint8_t SeedRecord::getDataQualityFlags()
{
    return ntohs(header->data_quality_flags);
}

uint8_t SeedRecord::getNumberOfBlockettes()
{
    return ntohs(header->number_of_blockettes);
}

long SeedRecord::getTimeCorrection()
{
    return ntohs(header->time_correction);
}

size_t SeedRecord::getBeginningOfData()
{
    return ntohs(header->beginning_of_data);
}

size_t SeedRecord::getFirstBlockette()
{
    return ntohs(header->first_blockette);
}

