#ifndef SESSION_H
#define SESSION_H

#include "persistencia/funcionario_dao.h" // Para funcionario_t

/**
 * @brief Retorna um ponteiro para o funcionário logado.
 * Se nenhum usuário estiver logado, retorna NULL.
 */
funcionario_t* get_funcionario_logado(void);

/**
 * @brief Define o funcionário logado.
 */
void set_funcionario_logado(funcionario_t *func);

/**
 * @brief Finaliza a sessão do usuário, liberando a referência.
 */
void logout(void);

/**
 * @brief Armazena um valor inteiro na sessão.
 * @param chave Nome da chave para identificar o valor
 * @param valor Valor inteiro a ser armazenado
 */
void session_set_int(const char *chave, int valor);

/**
 * @brief Recupera um valor inteiro da sessão.
 * @param chave Nome da chave que identifica o valor
 * @param padrao Valor padrão a retornar caso a chave não exista
 * @return O valor associado à chave ou o valor padrão
 */
int session_get_int(const char *chave, int padrao);

/**
 * @brief Armazena um ponteiro na sessão.
 * @param chave Nome da chave para identificar o ponteiro
 * @param ptr Ponteiro a ser armazenado
 */
void session_set_ptr(const char *chave, void *ptr);

/**
 * @brief Recupera um ponteiro da sessão.
 * @param chave Nome da chave que identifica o ponteiro
 * @return O ponteiro associado à chave ou NULL
 */
void* session_get_ptr(const char *chave);

#endif // SESSION_H
