#ifndef ESTADO_ATUALIZACAO_RESIDUOS_H
#define ESTADO_ATUALIZACAO_RESIDUOS_H

#include <stdlib.h>
#include "estados/estado.h"
#include "ui/ui_comum.h"

/**
 * Cria instância do estado para atualização de resíduos
 * @return ponteiro para o estado criado ou NULL em caso de falha
 */
estado_t *criar_estado_atualizacao_residuos(void);

#endif // ESTADO_ATUALIZACAO_RESIDUOS_H
