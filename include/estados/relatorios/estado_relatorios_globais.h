#ifndef ESTADO_RELATORIOS_GLOBAIS_H
#define ESTADO_RELATORIOS_GLOBAIS_H

#include <stdlib.h>
#include "estados/estado.h"
#include "ui/ui_comum.h"

/**
 * Cria instância do estado para relatórios globais
 * @return ponteiro para o estado criado ou NULL em caso de falha
 */
estado_t *criar_estado_relatorios_globais(void);

#endif // ESTADO_RELATORIOS_GLOBAIS_H