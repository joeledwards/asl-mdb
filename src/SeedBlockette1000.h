#ifndef __SEEDBLOCKETTE_1000_H__
#define __SEEDBLOCKETTE_1000_H__

#include "Seed.h"
#include <sys/types.h>
#include <arpa/inet.h>
#include <string>

class SeedBlockette1000
{
	uint8_t *raw;
	size_t length;
	struct seed_blockette_1000 *blockette_1000;

	public: 

	SeedBlockette1000(uint8_t *data, size_t length);

	uint16_t getBlocketteType();
	uint16_t getNextBlocketteByteNumber();
	int8_t getEncodingFormat();
	uint8_t getWordOrder();
	uint8_t getDataRecordLength();
	uint8_t getReserved();
};
#endif
