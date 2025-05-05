#ifndef ESTADO_LISTAR_FUNCIONARIOS_H
#define ESTADO_LISTAR_FUNCIONARIOS_H

#include "estados/estado.h"

/**
 * Cria uma instância do estado para listar funcionários
 * @return Ponteiro para o estado criado ou NULL em caso de falha
 */
estado_t* criar_estado_listar_funcionarios(void);

#endif // ESTADO_LISTAR_FUNCIONARIOS_H