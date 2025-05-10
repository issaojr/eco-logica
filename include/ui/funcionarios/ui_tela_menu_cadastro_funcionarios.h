#ifndef UI_TELA_MENU_CADASTRO_FUNCIONARIOS_H
#define UI_TELA_MENU_CADASTRO_FUNCIONARIOS_H

#include "ui/ui_menu.h"
#include "ui/ui_comum.h"

void ui_desenhar_tela_menu_cadastro_funcionarios(
    const char *nome_funcionario, 
    const int matricula);

/* mapa de opções e prompt da tela de cadastro de funcionários */
extern opcao_t tela_menu_cadastro_funcionarios_mapa[];
extern size_t   tela_menu_cadastro_funcionarios_mapa_n;
extern char    *tela_menu_cadastro_funcionarios_prompt;

#endif /* UI_TELA_MENU_CADASTRO_FUNCIONARIOS_H */