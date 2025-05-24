#ifndef BUSINESS_CRYPTO_H
#define BUSINESS_CRYPTO_H

#include <stddef.h>
#include <string.h>
#include <stdio.h>

/**
 * Aplica XOR cipher em data com a chave especificada (in-place).
 * @param data String a ser cifrada/decifrada (mutável).
 * @param key Chave de cifragem.
 */
void xor_cipher(char *data, char key);

/**
 * Gera representação hexadecimal ASCII da senha após XOR cipher.
 * @param senha Entrada em texto claro.
 * @param output Buffer para saída; deve ter tamanho >= 2*strlen(senha) + 1.
 * @param key Chave de XOR.
 */
void hash_senha(const char *senha, char *output, char key);

#endif // BUSINESS_CRYPTO_H
