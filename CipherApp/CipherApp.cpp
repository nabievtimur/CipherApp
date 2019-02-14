﻿#include "pch.h"

enum Mode { OFB, CTR };

int main(int argc, char* argv[]) {
	Mode mode = CTR;
	int block_size = 32;
	uint32_t iv = NULL;
	uint32_t password = NULL;
	char* in = nullptr;
	char* out = nullptr;
	bool reverse = false;

	for (int i = 1; i < argc; i++) {
		if (argv[i][0] == '-') {
			if (i + 1 >= argc) {
				std::cout << "Input meaning of option " << argv[i] << "." << std::endl;
			}
			else {
				switch (argv[i][1]) {
				case 'p':
					std::cout << "Option -p. ";
					password = MathCore::CRC32(Utills::toWchar(argv[i + 1], strlen(argv[i + 1])), strlen(argv[i + 1])); // TODO	to toUTFWchar
					i++;
					std::cout << "Password: " << argv[i] << "." << std::endl;
					break;
				case 'r':
					std::cout << "Option -r. Decrypt file." << std::endl;
					reverse = true;
					break;
				case 'b': {
					std::cout << "Option -b. ";
					int b = std::atoi(argv[i + 1]);
					if (b % 32 != 0) {
						std::cout << "Input the number of block size which is divisible by 32." << std::endl;
						return 1;
					}
					else {
						if (b == 0) {
							std::cout << "Error parse block size." << std::endl;
							return 1;
						}
						block_size = b;
						std::cout << "Block size: " << block_size << " bits." << std::endl;
					}
					i++;
					break;
				}
				case 'm':
					std::cout << "Option -m. ";
					switch (argv[i + 1][0]) {
					case 'O':
						mode = OFB;
						std::cout << "Mode: OFB." << std::endl;
						break;
					case 'C':
						mode = CTR;
						std::cout << "Mode: CTR." << std::endl;
						break;
					default:
						std::cout << "Unknown mode, probably you meant OFB or CTR." << std::endl;
						return 1;
					}
					i++;
					break;
				case 'i':
					if (argv[i][2] == 'v') {
						std::cout << "Option -iv. ";
					}
					else {
						std::cout << "Unknown option, probably you meant -iv." << std::endl;
					}
					break;
				case 'f':
					switch (argv[i][2]) {
					case 'i': {
						std::cout << "Option -fi. ";
						in = argv[i + 1];
						std::ifstream file(in);
						if (!file.is_open()) {
							std::cout << "Error input file";
							return 1;
						}
						std::cout << "Input file: " << in << std::endl;
						i++;
						break;
					}
					case 'o':
						std::cout << "Option -fo. ";
						out = argv[i + 1];
						std::cout << "Output file: " << out << std::endl;
						i++;
						break;
					default:
						std::cout << "Unknown option, probably you meant -fo or -fi." << std::endl;
						return 1;
					}
					break;
				default:
					std::cout << "Unknown option." << std::endl;
				}
			}
		}
	}

	if (in == nullptr) {
		std::cout << "Enter input file";
		return 1;
	}
	else if (out == nullptr) {
		std::cout << "Enter output file";
		return 1;
	}
	else if (password == NULL) {
		std::cout << "Enter password";
		return 1;
	}
	else if (mode == OFB && iv == NULL) {
		std::cout << "Enter initialize vector";
		return 1;
	}

	Crypt::Cipher* cipher;
	switch (mode) {
	case CTR:
		cipher = new Crypt::CTRCipher(password, in, out, block_size);
		break;
	case OFB: 
		cipher = new Crypt::OFBCipher(password, in, out, block_size, iv);
		break;
	default:
		std::cerr << "Unknown error";
		return 1;
	}
	
	int answer = 0;
	if (reverse) {
		answer = cipher->decrypt();
	}
	else {
		answer = cipher->encrypt();
	}
	std::cout << answer;
	switch (answer) {
	case 0:
		std::cout << "End work.";
		return 0;
	case 101:
		std::cout << "Error read input file.";
		return 1;
	case 102:
		std::cout << "Error create output file.";
		return 1;
	default:
		return 1;
	}
}