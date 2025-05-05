/* estado_adicionar_funcionario.h */
#ifndef ESTADO_ADICIONAR_FUNCIONARIO_H
#define ESTADO_ADICIONAR_FUNCIONARIO_H

#include "estados/estado.h"

/**
 * Cria uma instância do estado para adicionar funcionário
 * @return Ponteiro para o estado criado ou NULL em caso de falha
 */
estado_t* criar_estado_adicionar_funcionario(void);

#endif // ESTADO_ADICIONAR_FUNCIONARIO_H
