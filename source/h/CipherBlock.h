#include "Source.h"

/*
*	@brief Функция осуществляет шифрование одного блока
*	
*	@param[in]	uint32_t block - входной блок
*	@param[in]	uint32_t key - password обработанный CRC32
*	@param[out]	uint32_t* out - адрес памяти для результата */
int encryptBlock(uint32_t block, uint32_t key, uint32_t* out);

/*
*	@brief Функция осуществляет расшифрование одного блока
*	
*	@param[in]	uint32_t block - входной блок
*	@param[in]	uint32_t key - password обработанный CRC32
*	@param[out]	uint32_t* out - адрес памяти для результата */
int decryptBlock(uint32_t block, uint32_t key, uint32_t* out);