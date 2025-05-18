/* estado_cadastro_funcionarios.h */
#ifndef ESTADO_CADASTRO_FUNCIONARIOS_H
#define ESTADO_CADASTRO_FUNCIONARIOS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estados/estado.h"
#include "ui/funcionarios/ui_tela_cadastro_funcionarios.h"
#include "ui/ui_comum.h"
#include "estados/estado_menu_utils.h"
#include "session.h"

/**
 * Cria uma instância do estado para cadastro de funcionários
 * @return Ponteiro para o estado criado ou NULL em caso de falha
 */
estado_t *criar_estado_cadastro_funcionarios(void);

#endif // ESTADO_CADASTRO_FUNCIONARIOS_H
