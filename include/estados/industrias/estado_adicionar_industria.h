
#ifndef ESTADO_ADICIONAR_INDUSTRIA_H
#define ESTADO_ADICIONAR_INDUSTRIA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estados/estado.h"
#include "business/business_industria.h"
#include "ui/industrias/ui_tela_cadastro_industrias.h"
#include "ui/ui_comum.h"
#include "session.h"






/**
 * Cria uma instância do estado para adicionar indústria
 * @return Ponteiro para o estado criado ou NULL em caso de falha
 */
estado_t *criar_estado_adicionar_industria(void);

#endif 
