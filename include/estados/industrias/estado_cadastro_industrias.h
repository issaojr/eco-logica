
#ifndef ESTADO_CADASTRO_INDUSTRIAS_H
#define ESTADO_CADASTRO_INDUSTRIAS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estados/estado.h"
#include "ui/industrias/ui_tela_cadastro_industrias.h"
#include "ui/ui_comum.h"
#include "estados/estado_menu_utils.h"
#include "session.h"

/**
 * Cria uma instância do estado para cadastro de indústria
 * @return Ponteiro para o estado criado ou NULL em caso de falha
 */
estado_t *criar_estado_cadastro_industrias(void);

#endif 
