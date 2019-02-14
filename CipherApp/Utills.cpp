#include "pch.h"
#include "Utills.h"

wchar_t* Utills::toWchar(char * text) {
	wchar_t* wtext = new wchar_t[strlen(text)];
	for (int i = 0; i < strlen(text); i++) {
		wtext[i] = (wchar_t)text[i];
	}
	return wtext;
}

wchar_t* Utills::toUTFWchar(char * text) {
	return nullptr;
}
