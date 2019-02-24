#pragma once
#include "pch.h"

namespace Crypt {
	class Cipher {
	public:
		Cipher();
		Cipher(uint32_t password, char* in, char* out, int blockSize);
		~Cipher();
		int encrypt();
		int decrypt();
		virtual int checkOptions();
		uint32_t* ñyclicShiftByteLeft(uint32_t* block);
		uint32_t* ñyclicShiftByteRight(uint32_t* block);
		uint32_t* ñyclicShiftBitLeft(uint32_t* block, int count);
		uint32_t* ñyclicShiftBitRight(uint32_t* block, int count);
		uint32_t* XOR(uint32_t* firstBlock, uint32_t* secondBlock);

	protected:
		uint32_t password;
		char* in;
		char* out;
		int blockCount;

		virtual uint32_t* encryptBlock(uint32_t* block);
		virtual uint32_t* decryptBlock(uint32_t* block);
	};

	class CTRCipher : public Cipher {
	public:
		CTRCipher();
		CTRCipher(uint32_t password, char* in, char* out, int blockSize);
		~CTRCipher();
	private:
		uint32_t counter;
		uint32_t* encryptBlock(uint32_t* block) override;
		uint32_t* decryptBlock(uint32_t* block) override;
	};

	class OFBCipher : public Cipher	{
	public:
		OFBCipher();
		OFBCipher(uint32_t password, char* in, char* out, int blockSize, char* ivFile);
		~OFBCipher();
		int checkOptions() override;
	private:
		char* ivFile;
		uint32_t* iv;
		uint32_t* encryptBlock(uint32_t* block) override;
		uint32_t* decryptBlock(uint32_t* block) override;
	};
}


