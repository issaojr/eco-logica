#ifndef ESTADO_MSG_ATUALIZACAO_RESIDUOS_H
#define ESTADO_MSG_ATUALIZACAO_RESIDUOS_H

#include <stdlib.h>
#include "estados/estado.h"
#include "ui/ui_comum.h"

/**
 * Cria instância do estado para exibir mensagem de operação de resíduos
 * @return ponteiro para o estado criado ou NULL em caso de falha
 */
estado_t *criar_estado_msg_atualizacao_residuos(void);

#endif // ESTADO_MSG_ATUALIZACAO_RESIDUOS_H
