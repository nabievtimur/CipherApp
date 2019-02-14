#include "pch.h"
#include "Cipher.h"

using namespace Crypt;

Cipher::Cipher() { }
Cipher::~Cipher() { }

Cipher::Cipher(uint32_t password, char * in, char * out, int block_size) {

}

int Cipher::encrypt() {
	return 0;
}

int Cipher::decrypt() {
	return 0;
}

uint32_t * Cipher::encryptBlock(uint32_t * block) {
	return nullptr;
}
