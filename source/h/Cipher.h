#include "Source.h"

enum MODES 
{
	CTR = 0x01,
	OFB = 0x02
}

int encrypt(
	MODES mode, 
	uint8_t* in, 
	size_t inSize,
	uint8_t* out, 
	size_t* outSize, 
	std::string pass, 
	std::string iv)

int decrypt(
	MODES mode, 
	uint8_t* in, 
	size_t inSize, 
	uint8_t* out, 
	size_t* outSize,
	std::string pass,
	std::string iv)

// TODO: Вызов функции с nullptr в out позволяет узнать размер массива, который будет записан в outSize