/* estado_msg_cadastro_industria.h */
#ifndef ESTADO_MSG_CADASTRO_INDUSTRIA_H
#define ESTADO_MSG_CADASTRO_INDUSTRIA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estados/estado.h"
#include "ui/ui_comum.h"

/**
 * Cria uma instância do estado para exibir mensagem de cadastro de indústria
 * @return Ponteiro para o estado criado ou NULL em caso de falha
 */
estado_t *criar_estado_msg_cadastro_industria(void);

#endif // ESTADO_MSG_CADASTRO_INDUSTRIA_H
