#ifndef ESTADO_SOBRE_PROJETO_H
#define ESTADO_SOBRE_PROJETO_H

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "estados/estado.h" // Para estado_t e estado_aplicacao
#include "ui/ui_tela_sobre_projeto.h"
#include "estados/estado_menu_utils.h"
#include "ui/ui_comum.h"

/**
 * @file estado_sobre_projeto.h
 * @brief Declara��es para o estado de exibi��o de informa��es sobre o projeto.
 * @author Issao Hanaoka Junior
 * @date 2025-05-04
 */
estado_t* criar_estado_sobre_projeto(void);

#endif // ESTADO_SOBRE_PROJETO_H