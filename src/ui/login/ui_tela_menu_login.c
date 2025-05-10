#include "ui/login/ui_tela_menu_login.h"
#include "ui/ui_comum.h"

/* Códigos devem bater com o enum em estados.h */
const opcao_t tela_menu_login_mapa[] = {
    { 1, "Login" },
    { 2, "Sobre o projeto" },
    { 3, "Sair" }
};

const size_t tela_menu_login_mapa_n =
    sizeof(tela_menu_login_mapa) / sizeof(tela_menu_login_mapa[0]);

const char *tela_menu_login_prompt = PROMPT_OPCOES(1, 3);