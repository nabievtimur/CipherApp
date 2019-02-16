#pragma once
#include "pch.h"

namespace Utills {
	uint32_t* toBlock(char* text, int size);
	wchar_t* toUTFWchar(char* text, int size);
	char* toChar(uint32_t* wtext, int size);
}