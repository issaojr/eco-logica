#ifndef MENU_H
#define MENU_H

#include <stdio.h>
#include "funcionario_ui.h" // Placeholder para a funcao de cadastro
#include "utils.h"            // Placeholder para a funcao de limpeza de tela
#include "session.h"         // Placeholder para a funcao de sessao
#include "industria_ui.h"    // Placeholder para a funcao de cadastro de industria
#include "residuos_ui.h"     // Placeholder para a funcao de residuos
#include "relatorios_ui.h"   // Placeholder para a funcao de relatorios
#include "login_ui.h"
#include "logged_user_ui.h" // Placeholder para a funcao de usuario logado
#include "strings_globais.h" // Placeholder para a funcao de strings globais
#include "screen_title_ui.h" // Placeholder para a funcao de titulo da tela
#include "info_dialog_ui.h" // Placeholder para a funcao de dialogo de informacao
#include "erros.h"          // Placeholder para a funcao de erros
#include "entrada_ui.h"     // Placeholder para a funcao de entrada


void menu_principal(void);

void mostrar_menu_login(void);
void mostrar_menu_principal(char *nome, int matricula);
void mostrar_msg_logout(void);
void mostrar_msg_opcao_invalida(void);
void mostrar_msg_saida(void);
void mostrar_item_menu(int opcao, const char *msg);


#endif // MENU_H
