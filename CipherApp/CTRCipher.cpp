#include "pch.h"
#include "Cipher.h"

Crypt::CTRCipher::CTRCipher() { }
Crypt::CTRCipher::~CTRCipher() { }

Crypt::CTRCipher::CTRCipher(uint32_t password, char* in, char* out, int blockSize) {
	this->password = password;
	this->in = in;
	this->out = out;
	this->blockCount = blockSize / 32;
	this->counter = password >> 16 | password << 16; // �������� ��� ������������� �� ��������� �� ����������� ���������� �����
	if (this->counter > 0xFF000000) this->counter -= 0xFF000000;
}

uint32_t* Crypt::CTRCipher::encryptBlock(uint32_t* block) {
	uint32_t* enBlock = new uint32_t[blockCount];
	for (int i = 0; i < blockCount; i++) {
		enBlock[i] = (this->counter ^ password ^ block[i]);
		this->counter > 0xFF000000 ? this->counter -= 0xFF000000 : this->counter += 0x1385831;
		//�������� 0x1385831 ���������, ����� ������� �������� ��� ��������� ��������
	}
	return �yclicShiftByteRight(enBlock);
}

uint32_t* Crypt::CTRCipher::decryptBlock(uint32_t* block) {
	uint32_t* enBlock = �yclicShiftByteLeft(block);
	for (int i = 0; i < blockCount; i++) {
		enBlock[i] = (this->counter ^ password ^ enBlock[i]);
		this->counter > 0xFF000000 ? this->counter -= 0xFF000000 : this->counter += 0x1385831;
	}
	return enBlock;
}
