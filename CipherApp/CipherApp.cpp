#include "pch.h"

int main() {
	char* text = new char[2];
	text[0] = 'H';
	text[1] = 'i';
	std::cout << std::hex << (uint32_t)text[0] << " " << (uint32_t)text[1] << std::endl;
	std::cout << std::hex << MathCore::CRC32(Utills::toWchar(text), 2);
    return 0; 
}