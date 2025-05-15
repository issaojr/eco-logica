#ifndef UI_FORM_FUNCIONARIO_H
#define UI_FORM_FUNCIONARIO_H

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <stddef.h>
#include "ui/ui_comum.h"

void ui_ler_matricula_cadastro_funcionario(int* matricula);
void ui_ler_nome_cadastro_funcionario(char* nome_buffer, size_t tamanho);
void ui_ler_senha_segura_cadastro_funcionario(char* senha_buffer, size_t tamanho);



#endif // UI_FORM_FUNCIONARIO_H