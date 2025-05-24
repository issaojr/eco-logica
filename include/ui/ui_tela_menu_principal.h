#ifndef UI_TELA_MENU_PRINCIPAL_H
#define UI_TELA_MENU_PRINCIPAL_H

#include "ui/ui_menu.h"
#include "ui/ui_comum.h"

/* mapa de opções e prompt da tela de menu principal */
extern const opcao_t tela_menu_principal_mapa[];
extern const size_t tela_menu_principal_mapa_n;
extern const char *tela_menu_principal_prompt(void);

void ui_desenhar_tela_menu_principal(const char *nome_funcionario,
                                     const char *matricula);

void ui_desenhar_cabecalho_menu_principal(void);

#endif /* UI_TELA_MENU_PRINCIPAL_UI */
