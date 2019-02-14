#include "pch.h"
#include "Cipher.h"

using namespace Crypt;

OFBCipher::OFBCipher() { }
OFBCipher::~OFBCipher() { }

OFBCipher::OFBCipher(uint32_t password, char * in, char * out, int block_size, uint32_t iv) {

}

uint32_t * OFBCipher::encryptBlock(uint32_t * block) {
	return nullptr;
}
