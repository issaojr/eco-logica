
#ifndef ESTADO_EDITAR_INDUSTRIA_H
#define ESTADO_EDITAR_INDUSTRIA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estados/estado.h"
#include "ui/industrias/ui_tela_cadastro_industrias.h"
#include "ui/ui_comum.h"


/**
 * Cria uma inst�ncia do estado para editar ind�stria
 * @return Ponteiro para o estado criado ou NULL em caso de falha
 */
estado_t* criar_estado_editar_industria(void);

#endif // ESTADO_EDITAR_INDUSTRIA_H
