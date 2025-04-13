#ifndef CRYPTO_H
#define CRYPTO_H

/**
 * @brief Aplica uma cifra XOR em uma string.
 * 
 * Esta função realiza a criptografia/descriptografia da string 'data'
 * utilizando a chave fornecida por 'key'. O mesmo método é aplicado
 * para criptografar e descriptografar.
 *
 * @param data A string a ser criptografada/descriptografada.
 * @param key A chave (um byte) utilizada no XOR.
 */
void xorCipher(char *data, char key);

#endif // CRYPTO_H
