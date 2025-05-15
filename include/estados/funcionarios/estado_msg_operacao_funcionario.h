#ifndef ESTADO_MSG_OPERACAO_FUNCIONARIO_H
#define ESTADO_MSG_OPERACAO_FUNCIONARIO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ui/ui_comum.h"
#include "estados/estado.h"

/**
 * Cria uma inst�ncia do estado para exibir mensagem de opera��o em funcion�rio
 * @return Ponteiro para o estado criado ou NULL em caso de falha
 */
estado_t* criar_estado_msg_operacao_funcionario(void);

#endif // ESTADO_MSG_OPERACAO_FUNCIONARIO_H