#ifndef __SEED_H__
#define __SEED_H__
#include <cstdlib>
#include <cstddef>
#include <stdint.h>

#define SEED_TIME_OFFSET 20

struct seed_time {
    uint16_t year;
    uint16_t yday;
    uint8_t  hour;
    uint8_t  minute;
    uint8_t  second;
    uint8_t  reserved;
    uint16_t husecond;
} __attribute__ ((__packed__));

struct seed_header {
    char sequence_number[6];            //  0 [6]   -  1
    char quality_indicator;             //  6 [1]   -  2
    char reserved;                      //  7 [1]   -  3
    char station[5];                    //  8 [5]   -  4
    char location[2];                   // 13 [2]   -  5
    char channel[3];                    // 15 [3]   -  6
    char network[2];                    // 18 [2]   -  7
    struct seed_time start_time;        // 20 [10]  -  8
    uint16_t number_of_samples;         // 30 [2]   -  9`
    int16_t  sample_rate_factor;        // 32 [2]   - 10
    int16_t  sample_rate_multiplier;    // 34 [2]   - 11
    uint8_t  activity_flags;            // 36 [1]   - 12
    uint8_t  io_and_clock_flags;        // 37 [1]   - 13
    uint8_t  data_quality_flags;        // 38 [1]   - 14
    uint8_t  number_of_blockettes;      // 39 [1]   - 15
    int32_t  time_correction;           // 40 [4]   - 16
    uint16_t beginning_of_data;         // 44 [2]   - 17
    uint16_t first_blockette;           // 46 [2]   - 18
} __attribute__ ((__packed__));

struct seed_blockette_1000 {
	uint16_t blockette_type;
	uint16_t next_blockette_byte_number;
	int8_t encoding_format;
	uint8_t word_order;
	uint8_t data_record_length;
	uint8_t reserved;
} __attribute__ ((__packed__));
#endif
