#include "pch.h"
#include "Cipher.h"

using namespace Crypt;

CTRCipher::CTRCipher() { }
CTRCipher::~CTRCipher() { }

CTRCipher::CTRCipher(uint32_t password, char* in, char* out, int block_size) {

}

uint32_t * Crypt::CTRCipher::encryptBlock(uint32_t * block) {
	return nullptr;
}
