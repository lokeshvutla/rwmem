#pragma once

#include <string>
#include "imap.h"
#include "helpers.h"

class I2CMap : public IMap
{
public:
	I2CMap(unsigned adapter_nr, uint16_t i2c_addr, uint16_t addr_len, Endianness addr_endianness,
	       Endianness data_endianness);
	~I2CMap();

	uint64_t read(uint64_t addr, unsigned numbytes) const;
	void write(uint64_t addr, unsigned numbytes, uint64_t value);

	void map(uint64_t offset, uint64_t length) { }
	void unmap() { }

private:
	int m_fd;
	uint16_t m_i2c_addr;

	uint8_t m_address_bytes;
	Endianness m_address_endianness;
	Endianness m_data_endianness;
};
