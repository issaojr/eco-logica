#ifndef ESTADO_ATUALIZACAO_RESIDUOS_H
#define ESTADO_ATUALIZACAO_RESIDUOS_H

#include <stdlib.h>
#include "estados/estado.h"
#include "ui/ui_comum.h"
#include "business/business_residuos.h"
#include "business/business_industria.h"
#include "estruturas/residuo.h"
#include "estruturas/industria.h"
#include "ui/residuos/ui_tela_atualizacao_residuos.h"
#include "session.h"

/**
 * Estado de atualização de resíduos
 */
bool atualizar_residuo(const residuo_t *r);

/**
 * Cria instância do estado para atualização de resíduos
 * @return ponteiro para o estado criado ou NULL em caso de falha
 */
estado_t *criar_estado_atualizacao_residuos(void);

#endif 
