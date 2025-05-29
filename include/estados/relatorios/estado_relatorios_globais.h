#ifndef ESTADO_RELATORIOS_GLOBAIS_H
#define ESTADO_RELATORIOS_GLOBAIS_H

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
 * Cria instância do estado para relatórios globais
 * @return ponteiro para o estado criado ou NULL em caso de falha
 */
estado_t *criar_estado_relatorios_globais(void);

/**
 * Reseta o estado de relatórios globais
 */
void reset_estado_rel_globais(void);

#endif // ESTADO_RELATORIOS_GLOBAIS_H
