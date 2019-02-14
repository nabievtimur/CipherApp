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
	std::fstream fin(in, std::ios::in | std::ios::binary);
	std::fstream fout(out, std::ios::out | std::ios::binary);
	fin.seekg(0, std::ios::end);
	long long size = fin.tellg();
	fin.seekg(0);
	char* buffer = new char[blockCount];
	fin >> std::noskipws;

	if (fin.is_open()) {
		for (int i = 0; i * blockCount < size; i++) {
			for (int j = 0; j < blockCount; j++) {
				if (i * blockCount + j < size) {
					fin >> buffer[j];
				}
				else {
					buffer[j] = (char)0;
				}
			}
			char* enBlock = Utills::toChar(this->encryptBlock(Utills::toWchar(buffer, blockCount)), blockCount);
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
	return this->encrypt();
}

wchar_t* Crypt::Cipher::encryptBlock(wchar_t* block) {
	//wcahr_t* encryptBlock = new wcahr_t[blockCount];
	//for (int i = 0; i < blockCount; i++) {
	//	encryptBlock[i] = (wcahr_t)block[i];
	//}
	return block;
}
