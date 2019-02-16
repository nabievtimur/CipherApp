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

uint32_t* Crypt::OFBCipher::encryptBlock(uint32_t* block) {
	uint32_t* enBlock = new uint32_t[blockCount];
	for (int i = 0; i < blockCount; i++) {
		enBlock[i] = (uint32_t)(this->iv ^ password ^ block[i]);
		this->iv = this->iv ^ block[i];
	}
	uint32_t b = enBlock[blockCount - 1] << 24;
	uint32_t c = b;
	for (int j = 0; j < blockCount; j++) {
		c = enBlock[j] << 24;
		enBlock[j] = b + (enBlock[j] >> 8);
		b = c;
	}
	return enBlock;
}

uint32_t * Crypt::OFBCipher::decryptBlock(uint32_t * block) {
	uint32_t* enBlock = new uint32_t[blockCount];
	for (int i = 0; i < blockCount; i++) {
		enBlock[i] = (uint32_t)(block[i]);
	}
	uint32_t b = enBlock[0] >> 24;
	uint32_t c = b;
	for (int j = blockCount - 1; j >= 0; j--) {
		c = enBlock[j] >> 24;
		enBlock[j] = b + (enBlock[j] << 8);
		b = c;
	}
	for (int i = 0; i < blockCount; i++) {
		enBlock[i] = (uint32_t)(this->iv ^ password ^ enBlock[i]);
		this->iv = this->iv ^ enBlock[i];
	}

	return enBlock;
}
