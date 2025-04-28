#ifndef SESSION_H
#define SESSION_H

#include "funcionario.h"

/**
 * @brief Retorna um ponteiro para o funcion�rio logado.
 * Se nenhum usu�rio estiver logado, retorna NULL.
 */
funcionario_t* get_usuario_logado(void);

/**
 * @brief Define o funcion�rio logado.
 */
void set_usuario_logado(funcionario_t *func);

/**
 * @brief Finaliza a sess�o do usu�rio, liberando a refer�ncia.
 */
void logout(void);

#endif // SESSION_H
