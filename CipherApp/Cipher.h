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
		OFBCipher(uint32_t password, char* in, char* out, int blockSize, uint32_t iv);
		~OFBCipher();
	private:
		uint32_t iv;
		uint32_t* encryptBlock(uint32_t* block) override;
		uint32_t* decryptBlock(uint32_t* block) override;
	};
}


