#pragma once
#include "pch.h"

namespace MathCore {
	uint32_t CRC32(wchar_t* text, int size);
	// Циклический сдвиг влево вправо.
	uint32_t ROR(uint32_t b, int count);
	uint32_t ROL(uint32_t b, int count);
	// Логический сдвиг влево вправо, заполняет нулями.
	uint32_t SHR(uint32_t b, int count);
	uint32_t SHL(uint32_t b, int count);

}