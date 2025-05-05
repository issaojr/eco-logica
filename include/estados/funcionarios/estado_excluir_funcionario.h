#ifndef ESTADO_EXCLUIR_FUNCIONARIO_H
#define ESTADO_EXCLUIR_FUNCIONARIO_H

#include "estados/estado.h"

/**
 * Cria uma inst�ncia do estado para excluir funcion�rio
 * @return Ponteiro para o estado criado ou NULL em caso de falha
 */
estado_t* criar_estado_excluir_funcionario(void);

#endif // ESTADO_EXCLUIR_FUNCIONARIO_H