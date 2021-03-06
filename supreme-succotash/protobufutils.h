#pragma once

#include "stdint.h"

// for sf::Vector3f
#include "SFML/Graphics.hpp"

// byte streams
struct Stream {

	uint8_t const * const bytesStart;
	uint8_t const * const bytesEnd;
	uint8_t const * bytes;

	uint32_t len;

	Stream(uint8_t const * const _bytesStart, uint32_t _len) :
		bytesStart(_bytesStart),
		bytesEnd(_bytesStart + _len),
		bytes(_bytesStart),
		len(_len)
	{}
};

// move forward this many bytes
void advance(Stream& stream, size_t n);

// read a single byte and move the pointer forward
int32_t readByte(Stream& stream);

// read four bytes interpreted as a float
float readFloat(Stream& stream);

uint32_t readUInt32(Stream& stream);

// read a varint32 from a stream, and move the given pointer forward so that
// it points to the byte after the varint32
uint32_t readVarint32(Stream& stream);

// same thing, for varint64
uint64_t readVarint64(Stream& stream);

// read a string, where the first byte is the start of a varint for the length
size_t readString(Stream& stream, uint8_t* buf);

// read a vector3, where the first byte is the start of a varint32 for the length
sf::Vector3f readVector3f(Stream& stream);

