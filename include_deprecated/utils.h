#ifndef UTILS_H
#define UTILS_H

#define TAMANHO_ARRAY(array) (sizeof(array) / sizeof(array[0]))

void clear_console(void);
void pauseConsole(const char *msg);

/**
 * @brief Converte todos os caracteres alfab�ticos de uma string para mai�sculas.
 *
 * @param str A string a ser convertida (modificada in-place).
 */
void to_upper_case(char *str);

/**
 * @brief C�pia segura de string, sempre assegurando termina��o nula.
 *
 * @param dest  Buffer de destino.
 * @param src   String de origem.
 * @param size  Tamanho total do buffer de destino (incluindo o '\\0').
 */
void safeStrCopy(char *dest, const char *src, size_t size);

/**
 * @brief Cria uma nova string centralizada em um espa�o de width colunas.
 *
 * @param msg   Mensagem de entrada (n�o modificada).
 * @param width Comprimento total do campo (colunas).
 * @return Ponteiro para buffer alocado (chamador faz free), ou NULL se erro.
 */
char *centralizar_msg(const char *msg, size_t width);

/**
 * @brief Vers�o �default�: centraliza msg em um campo de 48 colunas.
 *
 * @param msg Mensagem de entrada.
 * @return Ponteiro para buffer alocado (chamador faz free), ou NULL se erro.
 */
char *centerMessageDefault(const char *msg);

/**
 * @brief Cria uma nova string alinhada � direita em um espa�o de width colunas.
 *
 * @param msg   Mensagem de entrada (n�o modificada).
 * @param width Comprimento total do campo (colunas).
 * @return Ponteiro para buffer alocado (chamador faz free), ou NULL se erro.
 */
char *rightAlignMessage(const char *msg, size_t width);

/**
 * @brief Vers�o �default�: alinha msg � direita em um campo de 48 colunas.
 *
 * @param msg Mensagem de entrada.
 * @return Ponteiro para buffer alocado (chamador faz free), ou NULL se erro.
 */
char *rightAlignMessageDefault(const char *msg);

/**
 * @brief Libera um buffer de string e retorna NULL para facilitar atribui��o.
 *
 * @param s Ponteiro para buffer alocado.
 * @return NULL
 */
char *libera_mem_str(char *s);




#endif // UTILS_H