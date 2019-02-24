#include "pch.h"
#include "Cipher.h"

Crypt::Cipher::Cipher() { }
Crypt::Cipher::~Cipher() { }

Crypt::Cipher::Cipher(uint32_t password, char * in, char * out, int blockSize) {
	this->password = password;
	this->in = in;
	this->out = out;
	this->blockCount = blockSize / 32;
}

int Crypt::Cipher::encrypt() {
	std::fstream fin(this->in, std::ios::in | std::ios::binary);
	std::fstream fout(this->out, std::ios::out | std::ios::binary);
	fin.seekg(0, std::ios::end);
	long long size = fin.tellg();
	fin.seekg(0);
	char* buffer = new char[blockCount * 4];
	fin >> std::noskipws;

	if (fin.is_open()) {
		for (long long  i = 0; i * blockCount * 4 < size; i++) {
			for (int j = 0; j < blockCount * 4; j++) {
				if (i * blockCount * 4 + j < size) {
					fin >> buffer[j];
				}
				else {
					buffer[j] = (char)0;
				}
			}
			char* enBlock = Utills::toChar(this->encryptBlock(Utills::toBlock(buffer, blockCount)), blockCount);
			if (fout) {
				for (int j = 0; j < blockCount * 4; j++) {
					fout << enBlock[j];
				}
			}
			else {
				fin.close();
				return 102;
			}
		}
	}
	else {
		return 101;
	}
	fin.close();
	fout.close();
	return 0;
}

int Crypt::Cipher::decrypt() {
	std::fstream fin(in, std::ios::in | std::ios::binary);
	std::fstream fout(out, std::ios::out | std::ios::binary);
	fin.seekg(0, std::ios::end);
	long long size = fin.tellg();
	fin.seekg(0);
	char* buffer = new char[blockCount * 4];
	fin >> std::noskipws;

	if (fin.is_open()) {
		for (int i = 0; i * blockCount * 4 < size; i++) {
			for (int j = 0; j < blockCount * 4; j++) {
				if (i * blockCount * 4 + j < size) {
					fin >> buffer[j];
				}
				else {
					buffer[j] = (char)0;
				}
			}
			char* enBlock = Utills::toChar(this->decryptBlock(Utills::toBlock(buffer, blockCount)), blockCount);
			if (fout) {
				for (int j = 0; j < blockCount * 4; j++) {
					fout << enBlock[j];
				}
			}
			else {
				fin.close();
				return 102;
			}
		}
	}
	else {
		return 101;
	}
	fin.close();
	fout.close();
	return 0;
}

int Crypt::Cipher::checkOptions() {
	return 0;
}

uint32_t* Crypt::Cipher::ñyclicShiftByteLeft(uint32_t* block) {
	uint32_t* ROLblock = new uint32_t[this->blockCount];
	for (int i = this->blockCount - 1; i >= 0; i--) {
		ROLblock[i] = block[i] << 8 | block[(i + 1) % this->blockCount] >> 24;
	}
	return ROLblock;
}

uint32_t* Crypt::Cipher::ñyclicShiftByteRight(uint32_t* block) {
	uint32_t* RORblock = new uint32_t[this->blockCount];
	for (int i = 0; i < this->blockCount; i++) {
		RORblock[i] = block[i] >> 8 | block[(i - 1) < 0 ? blockCount - 1 : i - 1] << 24;
	}
	return RORblock;
}

uint32_t* Crypt::Cipher::ñyclicShiftBitLeft(uint32_t* block, int count) {
	count = count % 32;
	uint32_t* ROLblock = new uint32_t[this->blockCount];
	for (int i = this->blockCount - 1; i >= 0; i--) {
		ROLblock[i] = block[i] << count | block[(i + 1) % this->blockCount] >> (32 - count);
	}
	return ROLblock;
}

uint32_t* Crypt::Cipher::ñyclicShiftBitRight(uint32_t* block, int count) {
	count = count % 32;
	uint32_t* RORblock = new uint32_t[this->blockCount];
	for (int i = 0; i < this->blockCount; i++) {
		RORblock[i] = block[i] >> count | block[(i - 1) < 0 ? blockCount - 1 : i - 1] << (32 - count);
	}
	return RORblock;
}

uint32_t * Crypt::Cipher::XOR(uint32_t * firstBlock, uint32_t * secondBlock) {
	uint32_t* XORblock = new uint32_t[this->blockCount];
	for (int i = 0; i < this->blockCount; i++) {
		XORblock[i] = firstBlock[i] ^ secondBlock[i];
	}
	return XORblock;
}

uint32_t* Crypt::Cipher::encryptBlock(uint32_t* block) {
	return block;
}

uint32_t * Crypt::Cipher::decryptBlock(uint32_t * block) {
	return nullptr;
}
