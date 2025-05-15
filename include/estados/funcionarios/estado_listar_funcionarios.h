#ifndef ESTADO_LISTAR_FUNCIONARIOS_H
#define ESTADO_LISTAR_FUNCIONARIOS_H

#define MAX_FUNCIONARIOS 100 // Tamanho m�ximo da lista de funcion�rios

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estados/estado.h"
#include "estados/estados.h"
#include "business/business_funcionario.h"
#include "persistencia/funcionario_dao.h"
#include "ui/funcionarios/ui_tela_cadastro_funcionarios.h"
#include "ui/ui_comum.h"
#include "session.h"
#include "estados/estado.h"

/**
 * Cria uma inst�ncia do estado para listar funcion�rios
 * @return Ponteiro para o estado criado ou NULL em caso de falha
 */
estado_t* criar_estado_listar_funcionarios(void);

#endif // ESTADO_LISTAR_FUNCIONARIOS_H