#pragma once
#include "pch.h"

namespace Utills {
	wchar_t* toWchar(char* text, int size);
	wchar_t* toUTFWchar(char* text, int size);
	char* toChar(wchar_t* wtext, int size);
}