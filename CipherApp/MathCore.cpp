#include "pch.h"
#include "MathCore.h"

uint32_t MathCore::CRC32(wchar_t * text, int size) {
	uint32_t crc = 0x39282315;
	for (int i = 0; i < size; i++) {
		uint32_t let = (uint32_t)text[i];
		for (int j = 0; j < 32; j++) {
			if (let >> 31) {
				if (crc >> 31) {
					crc = crc << 1;
					crc += 0x01;
					crc ^= 0x04C11DB7;
				}
				else {
					crc = crc << 1;
					crc += 0x01;
				}
			}
			else {
				if (crc >> 31) {
					crc = crc << 1;
					crc ^= 0x04C11DB7;
				}
				else {
					crc = crc << 1;
				}
			}
			let = let << 1;
		}
	};
	return crc ^ 0x45672314;
}
