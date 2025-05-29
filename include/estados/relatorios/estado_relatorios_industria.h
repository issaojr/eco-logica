#ifndef ESTADO_RELATORIOS_INDUSTRIA_H
#define ESTADO_RELATORIOS_INDUSTRIA_H

#include <stdlib.h>
#include "estados/estado.h"
#include "ui/ui_comum.h"
#include "estruturas/industria.h"
#include "estruturas/residuo.h"
#include "business/business_residuos.h"
#include "business/business_industria.h"
#include "business/business_relatorios.h"
#include "ui/relatorios/ui_relatorios.h"
#include "ui/residuos/ui_tela_atualizacao_residuos.h"
#include "ui/ui_form.h"
#include "estruturas/relatorio.h"

/**
 * Cria instância do estado para relatórios por indústria
 * @return ponteiro para o estado criado ou NULL em caso de falha
 */
estado_t *criar_estado_relatorios_industria(void);

void reset_estado_rel_ind(void);

#endif 
