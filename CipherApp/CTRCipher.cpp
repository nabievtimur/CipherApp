#include "pch.h"
#include "Cipher.h"

Crypt::CTRCipher::CTRCipher() { }
Crypt::CTRCipher::~CTRCipher() { }

Crypt::CTRCipher::CTRCipher(uint32_t password, char* in, char* out, int blockSize) {
	this->password = password;
	this->in = in;
	this->out = out;
	this->blockCount = blockSize / 32;
	this->counter = password; // значение для инициализации не зависящее от реализации шифра
	password > 0xFF000000 ? this->counter = password - 0xFF000000 : this->counter = password;
}

uint32_t* Crypt::CTRCipher::encryptBlock(uint32_t* block) {
	uint32_t* enBlock = new uint32_t[blockCount];
	for (int i = 0; i < blockCount; i++) {
		enBlock[i] = (uint32_t)(this->counter ^ password ^ block[i]);
		this->counter > 0xFF000000 ? this->counter -= 0xFF000000 : this->counter += 0x1385831; 
		//значение 0x1385831 подобрано, чтобы счётчик пробегал все возможные значения
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

uint32_t * Crypt::CTRCipher::decryptBlock(uint32_t * block)
{
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
		enBlock[i] = (uint32_t)(this->counter ^ password ^ enBlock[i]);
		this->counter > 0xFF000000 ? this->counter -= 0xFF000000 : this->counter += 0x1385831;
		//значение 0x1385831 подобрано, чтобы счётчик пробегал все возможные значения
	}
	
	return enBlock;
}
