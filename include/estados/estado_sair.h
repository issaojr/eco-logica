#ifndef ESTADO_SAIR_H
#define ESTADO_SAIR_H

#include <stdlib.h>
#include <stdio.h>
#include "estados/estado.h"
#include "ui/ui_tela_sair.h"
#include "session.h"

/**
 * Cria uma instância do estado de saída
 * @return Ponteiro para o estado criado ou NULL em caso de falha
 */
estado_t *criar_estado_sair(void);

#endif // ESTADO_SAIR_H
