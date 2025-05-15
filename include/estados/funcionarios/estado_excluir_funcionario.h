#ifndef ESTADO_EXCLUIR_FUNCIONARIO_H
#define ESTADO_EXCLUIR_FUNCIONARIO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ui/funcionarios/ui_tela_cadastro_funcionarios.h"
#include "ui/ui_formulario.h"
#include "ui/ui_comum.h"
#include "business/business_funcionario.h"
#include "session.h"
#include "estados/estado.h"

/**
 * Cria uma instância do estado para excluir funcionário
 * @return Ponteiro para o estado criado ou NULL em caso de falha
 */
estado_t* criar_estado_excluir_funcionario(void);

#endif // ESTADO_EXCLUIR_FUNCIONARIO_H