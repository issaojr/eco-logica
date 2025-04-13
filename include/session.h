#ifndef SESSION_H
#define SESSION_H

#include "funcionario.h"

/**
 * @brief Retorna um ponteiro para o funcionário logado.
 * Se nenhum usuário estiver logado, retorna NULL.
 */
Funcionario* getUsuarioLogado(void);

/**
 * @brief Define o funcionário logado.
 */
void setUsuarioLogado(Funcionario *func);

/**
 * @brief Finaliza a sessão do usuário, liberando a referência.
 */
void logout(void);

#endif // SESSION_H
