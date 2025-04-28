#ifndef CRYPTO_H
#define CRYPTO_H

#include <stddef.h>

/**
 * Aplica XOR cipher em data com a chave especificada (in-place).
 * @param data String a ser cifrada/decifrada (mut�vel).
 * @param key Chave de cifragem.
 */
void xor_cipher(char *data, char key);

/**
 * Gera representa��o hexadecimal ASCII da senha ap�s XOR cipher.
 * @param senha Entrada em texto claro.
 * @param output Buffer para sa�da; deve ter tamanho >= 2*strlen(senha) + 1.
 * @param key Chave de XOR.
 */
void hash_senha(const char *senha, char *output, char key);

#endif // CRYPTO_H