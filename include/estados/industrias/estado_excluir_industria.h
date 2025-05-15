
#ifndef ESTADO_EXCLUIR_INDUSTRIA_H
#define ESTADO_EXCLUIR_INDUSTRIA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estados/estado.h"
#include "ui/industrias/ui_tela_cadastro_industrias.h"
#include "ui/ui_comum.h"

/**
 * Cria uma instância do estado para excluir indústria
 * @return Ponteiro para o estado criado ou NULL em caso de falha
 */
estado_t* criar_estado_excluir_industria(void);

#endif // ESTADO_EXCLUIR_INDUSTRIA_H
