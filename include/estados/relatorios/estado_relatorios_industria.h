#ifndef ESTADO_RELATORIOS_INDUSTRIA_H
#define ESTADO_RELATORIOS_INDUSTRIA_H

#include <stdlib.h>
#include "estados/estado.h"
#include "ui/ui_comum.h"

/**
 * Cria inst�ncia do estado para relat�rios por ind�stria
 * @return ponteiro para o estado criado ou NULL em caso de falha
 */
estado_t* criar_estado_relatorios_industria(void);

#endif // ESTADO_RELATORIOS_INDUSTRIA_H