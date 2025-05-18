/* estado_msg_operacao_industria.h */
#ifndef ESTADO_MSG_OPERACAO_INDUSTRIA_H
#define ESTADO_MSG_OPERACAO_INDUSTRIA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estados/estado.h"
#include "ui/ui_comum.h"

/**
 * Cria uma instância do estado para exibir mensagem de operação em indústria
 * @return Ponteiro para o estado criado ou NULL em caso de falha
 */
estado_t *criar_estado_msg_operacao_industria(void);

#endif // ESTADO_MSG_OPERACAO_INDUSTRIA_H
