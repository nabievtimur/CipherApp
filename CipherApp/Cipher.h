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

		virtual wchar_t* encryptBlock(wchar_t* block);
	};

	class CTRCipher : public Cipher {
	public:
		CTRCipher();
		CTRCipher(uint32_t password, char* in, char* out, int blockSize);
		~CTRCipher();
	private:
		uint32_t* counter;
		wchar_t* encryptBlock(wchar_t* block) override;
	};

	class OFBCipher : public Cipher	{
	public:
		OFBCipher();
		OFBCipher(uint32_t password, char* in, char* out, int blockSize, uint32_t iv);
		~OFBCipher();
	private:
		uint32_t iv;
		wchar_t* encryptBlock(wchar_t* block) override;
	};
}


