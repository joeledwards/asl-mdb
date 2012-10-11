#include "SeedBlockette1000.h"

SeedBlockette1000::SeedBlockette1000(uint8_t *data, size_t data_length)
{
    raw = data;
    length = data_length;
    blockette_1000 = (struct seed_blockette_1000 *)data;
}

uint16_t SeedBlockette1000::getBlocketteType()
{
	return ntohs(blockette_1000->blockette_type);
}

uint16_t SeedBlockette1000::getNextBlocketteByteNumber()
{
	return ntohs(blockette_1000->next_blockette_byte_number);
}

int8_t SeedBlockette1000::getEncodingFormat()
{
	return ntohs(blockette_1000->encoding_format);
}

uint8_t SeedBlockette1000::getWordOrder()
{
	return ntohs(blockette_1000->word_order);
}

uint8_t SeedBlockette1000::getDataRecordLength()
{
	return ntohs(blockette_1000->data_record_length);
}

uint8_t SeedBlockette1000::getReserved()
{
	return ntohs(blockette_1000->reserved);
}
