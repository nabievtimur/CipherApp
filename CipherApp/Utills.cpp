#include "pch.h"
#include "Utills.h"

wchar_t* Utills::toWchar(char* text, int size) {
	wchar_t* wtext = new wchar_t[size];
	for (int i = 0; i < size; i++) {
		wtext[i] = (wchar_t)text[i];
	}
	return wtext;
}

wchar_t* Utills::toUTFWchar(char * text, int size) {
	return nullptr;
}

char* Utills::toChar(wchar_t* wtext, int size)
{
	char* text = new char[size * 4];
	for (int i = 0; i / 4 < size; i+=4) {
		text[i] = wtext[i / 4] >> 24;
		text[i + 1] = wtext[i / 4] << 8 >> 24;
		text[i + 2] = wtext[i / 4] << 16 >> 24;
		text[i + 3] = wtext[i / 4] << 24 >> 24;
		std::cout << text[i] << std::endl;
		std::cout << text[i + 1] << std::endl;
		std::cout << text[i + 2] << std::endl;
		std::cout << text[i + 3] << std::endl;
	}
	return text;
}
