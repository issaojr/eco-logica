#ifndef SESSION_H
#define SESSION_H

#include "persistencia/funcionario_dao.h" // Para funcionario_t

/**
 * @brief Retorna um ponteiro para o funcion�rio logado.
 * Se nenhum usu�rio estiver logado, retorna NULL.
 */
funcionario_t* get_funcionario_logado(void);

/**
 * @brief Define o funcion�rio logado.
 */
void set_funcionario_logado(funcionario_t *func);

/**
 * @brief Finaliza a sess�o do usu�rio, liberando a refer�ncia.
 */
void logout(void);

/**
 * @brief Armazena um valor inteiro na sess�o.
 * @param chave Nome da chave para identificar o valor
 * @param valor Valor inteiro a ser armazenado
 */
void session_set_int(const char *chave, int valor);

/**
 * @brief Recupera um valor inteiro da sess�o.
 * @param chave Nome da chave que identifica o valor
 * @param padrao Valor padr�o a retornar caso a chave n�o exista
 * @return O valor associado � chave ou o valor padr�o
 */
int session_get_int(const char *chave, int padrao);

/**
 * @brief Armazena um ponteiro na sess�o.
 * @param chave Nome da chave para identificar o ponteiro
 * @param ptr Ponteiro a ser armazenado
 */
void session_set_ptr(const char *chave, void *ptr);

/**
 * @brief Recupera um ponteiro da sess�o.
 * @param chave Nome da chave que identifica o ponteiro
 * @return O ponteiro associado � chave ou NULL
 */
void* session_get_ptr(const char *chave);

#endif // SESSION_H
