#ifndef ESTADO_EDITAR_FUNCIONARIO_H
#define ESTADO_EDITAR_FUNCIONARIO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estados/estado.h"
#include "ui/funcionarios/ui_tela_cadastro_funcionarios.h"
#include "ui/ui_comum.h"
#include "business/business_funcionario.h"
#include "session.h"

/**
 * Cria uma instância do estado para editar funcionário
 * @return Ponteiro para o estado criado ou NULL em caso de falha
 */
estado_t *criar_estado_editar_funcionario(void);

#endif // ESTADO_EDITAR_FUNCIONARIO_H
