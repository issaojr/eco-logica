// EcoLogica/include/utils.h
#ifndef UTILS_H
#define UTILS_H

void clearConsole(void);
void pauseConsole(const char *msg);

/**
 * @brief Converte todos os caracteres alfab�ticos de uma string para mai�sculas.
 *
 * @param str A string a ser convertida (modificada in-place).
 */
void toUpperCase(char *str);

/**
 * @brief C�pia segura de string, sempre assegurando termina��o nula.
 *
 * @param dest  Buffer de destino.
 * @param src   String de origem.
 * @param size  Tamanho total do buffer de destino (incluindo o '\\0').
 */
void safeStrCopy(char *dest, const char *src, size_t size);

#endif // UTILS_H
