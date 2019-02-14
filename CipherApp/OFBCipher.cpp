#include "pch.h"
#include "Cipher.h"

Crypt::OFBCipher::OFBCipher() { }
Crypt::OFBCipher::~OFBCipher() { }

Crypt::OFBCipher::OFBCipher(uint32_t password, char * in, char * out, int block_size, uint32_t iv) {

}

uint32_t * Crypt::OFBCipher::encryptBlock(uint32_t * block) {
	return nullptr;
}
