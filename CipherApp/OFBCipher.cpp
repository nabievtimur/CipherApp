#include "pch.h"
#include "Cipher.h"

Crypt::OFBCipher::OFBCipher() { }
Crypt::OFBCipher::~OFBCipher() { }

int Crypt::OFBCipher::checkOptions() {
	std::fstream file(this->ivFile, std::ios::in | std::ios::binary);
	if (file) {
		file.seekg(0, std::ios::end);
		if (file.tellg() < blockCount * 4) {
			std::cout << "IV size smaller than block size.";
			return 1;
		}
		return 0;
	}
	else {
		std::cout << "Can`t open file with IV.";
		return 1;
	}
}

Crypt::OFBCipher::OFBCipher(uint32_t password, char * in, char * out, int blockSize, char* ivFile) {
	this->password = password;
	this->in = in;
	this->out = out;
	this->blockCount = blockSize / 32;
	this->ivFile = ivFile;
	this->iv = new uint32_t[this->blockCount];
	std::fstream file(this->ivFile, std::ios::in | std::ios::binary);
	file.seekg(0, std::ios::end);
	long long size = file.tellg();
	file.seekg(0);
	char* buffer = new char[this->blockCount * 4];
	file >> std::noskipws;
	if (file) {
		for (int i = 0; i < this->blockCount * 4; i++) {
			file >> buffer[i];
		}
		this->iv = Utills::toBlock(buffer, this->blockCount * 4);
		int i = this->blockCount * 4;
		while (i < size) {
			int p = (i / 4) % this->blockCount; // Позиция блока в iv;
			int b = i % 4 == 0 ? 0 : 4 - (i % 4); // Позиция байтв в блоке iv;
			char byte;
			file >> byte;
			uint32_t ivBlock = (unsigned char)byte << 8 * b;
			this->iv[p] ^= ivBlock;
			i++;
		}
	}
}

uint32_t* Crypt::OFBCipher::encryptBlock(uint32_t* block) {
	uint32_t* enBlock = new uint32_t[this->blockCount];
	for (int i = 0; i < this->blockCount; i++) {
		enBlock[i] = this->password ^ block[i] ^ this->iv[i];
		this->iv[i] = this->iv[i] ^ block[i];
	}
	uint32_t b = enBlock[this->blockCount - 1] << 24;
	uint32_t c = b;
	for (int j = 0; j < this->blockCount; j++) {
		c = enBlock[j] << 24;
		enBlock[j] = b | (enBlock[j] >> 8);
		b = c;
	}
	return enBlock;
}

uint32_t* Crypt::OFBCipher::decryptBlock(uint32_t * block) {
	uint32_t* enBlock = new uint32_t[this->blockCount];
	for (int i = this->blockCount - 1; i >= 0; i--) {
		enBlock[i] = block[i] << 8 | block[(i + 1) % this->blockCount] >> 24;
	}
	for (int i = 0; i < this->blockCount; i++) {
		enBlock[i] = this->password ^ enBlock[i] ^ this->iv[i];
		this->iv[i] = this->iv[i] ^ enBlock[i];
	}
	return enBlock;
}
