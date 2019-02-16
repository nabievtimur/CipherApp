#include "pch.h"
#include "Utills.h"

uint32_t* Utills::toBlock(char* text, int size) {
	uint32_t* block = new uint32_t[size];
	for (int i = 0; i / 4 < size; i += 4) {
		block[i / 4] = (unsigned char)text[i];
		block[i / 4] = (block[i / 4] << 8) | (unsigned char)text[i + 1];
		block[i / 4] = (block[i / 4] << 8) | (unsigned char)text[i + 2];
		block[i / 4] = (block[i / 4] << 8) | (unsigned char)text[i + 3];
	}
	return block;
}

wchar_t* Utills::toUTFWchar(char * text, int size) {
	wchar_t* wtext = new wchar_t[size];
	for (int i = 0; i < size; i++) {
		wtext[i] = (wchar_t)text[i];
	}
	return wtext;
}

char* Utills::toChar(uint32_t* block, int size) {
	char* text = new char[size * 4];
	for (int i = 0; i / 4 < size; i+=4) {
		text[i] = block[i / 4] >> 24;
		text[i + 1] = block[i / 4] << 8 >> 24;
		text[i + 2] = block[i / 4] << 16 >> 24;
		text[i + 3] = block[i / 4] << 24 >> 24;
	}
	
	return text;
}
