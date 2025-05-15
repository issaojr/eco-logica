/* estado_adicionar_funcionario.h */
#ifndef ESTADO_ADICIONAR_FUNCIONARIO_H
#define ESTADO_ADICIONAR_FUNCIONARIO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estados/estado.h"
#include "ui/funcionarios/ui_tela_cadastro_funcionarios.h"
#include "ui/ui_comum.h"
#include "ui/ui_formulario.h"
#include "business/business_funcionario.h"
#include "session.h"

/**
 * Cria uma instância do estado para adicionar funcionário
 * @return Ponteiro para o estado criado ou NULL em caso de falha
 */
estado_t* criar_estado_adicionar_funcionario(void);

#endif // ESTADO_ADICIONAR_FUNCIONARIO_H
