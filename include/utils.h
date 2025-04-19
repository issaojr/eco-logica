#ifndef UTILS_H
#define UTILS_H

void clearConsole(void);
void pauseConsole(const char *msg);

/**
 * @brief Converte todos os caracteres alfabéticos de uma string para maiúsculas.
 *
 * @param str A string a ser convertida (modificada in-place).
 */
void toUpperCase(char *str);

/**
 * @brief Cópia segura de string, sempre assegurando terminação nula.
 *
 * @param dest  Buffer de destino.
 * @param src   String de origem.
 * @param size  Tamanho total do buffer de destino (incluindo o '\\0').
 */
void safeStrCopy(char *dest, const char *src, size_t size);

/**
 * @brief Lê uma opção do usuário e limpa o buffer.
 *
 * @return A opção lida.
 */
int inputOption(void);

/**
 * @brief Cria uma nova string centralizada em um espaço de width colunas.
 *
 * @param msg   Mensagem de entrada (não modificada).
 * @param width Comprimento total do campo (colunas).
 * @return Ponteiro para buffer alocado (chamador faz free), ou NULL se erro.
 */
char *centerMessage(const char *msg, size_t width);

/**
 * @brief Versão “default”: centraliza msg em um campo de 48 colunas.
 *
 * @param msg Mensagem de entrada.
 * @return Ponteiro para buffer alocado (chamador faz free), ou NULL se erro.
 */
char *centerMessageDefault(const char *msg);

/**
 * @brief Cria uma nova string alinhada à direita em um espaço de width colunas.
 *
 * @param msg   Mensagem de entrada (não modificada).
 * @param width Comprimento total do campo (colunas).
 * @return Ponteiro para buffer alocado (chamador faz free), ou NULL se erro.
 */
char *rightAlignMessage(const char *msg, size_t width);

/**
 * @brief Versão “default”: alinha msg à direita em um campo de 48 colunas.
 *
 * @param msg Mensagem de entrada.
 * @return Ponteiro para buffer alocado (chamador faz free), ou NULL se erro.
 */
char *rightAlignMessageDefault(const char *msg);

/**
 * @brief Libera um buffer de string e retorna NULL para facilitar atribuição.
 *
 * @param s Ponteiro para buffer alocado.
 * @return NULL
 */
char *freeString(char *s);



#endif // UTILS_H