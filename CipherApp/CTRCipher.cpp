#include "pch.h"
#include "Cipher.h"

Crypt::CTRCipher::CTRCipher() { }
Crypt::CTRCipher::~CTRCipher() { }

Crypt::CTRCipher::CTRCipher(uint32_t password, char* in, char* out, int blockSize) {
	this->password = password;
	this->in = in;
	this->out = out;
	this->blockCount = blockSize / 32;
	this->counter = 0x0;
}

wchar_t * Crypt::CTRCipher::encryptBlock(wchar_t* block) {
	return block;
}
