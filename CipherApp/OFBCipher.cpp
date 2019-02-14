#include "pch.h"
#include "Cipher.h"

Crypt::OFBCipher::OFBCipher() { }
Crypt::OFBCipher::~OFBCipher() { }

Crypt::OFBCipher::OFBCipher(uint32_t password, char * in, char * out, int blockSize, uint32_t iv) {
	this->password = password;
	this->in = in;
	this->out = out;
	this->blockCount = blockSize / 32;
	this->iv = iv;
}

wchar_t* Crypt::OFBCipher::encryptBlock(wchar_t* block) {
	return block;
}
