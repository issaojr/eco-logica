#ifndef SESSION_H
#define SESSION_H

#include "persistencia/funcionario_dao.h" // Para funcionario_t

/**
 * @brief Retorna um ponteiro para o funcionário logado.
 * Se nenhum usuário estiver logado, retorna NULL.
 */
funcionario_t *get_funcionario_logado(void);

/**
 * @brief Define o funcionário logado.
 */
void set_funcionario_logado(funcionario_t *func);

/**
 * @brief Finaliza a sessão do usuário, liberando a referência.
 */
void logout(void);

#endif // SESSION_H
