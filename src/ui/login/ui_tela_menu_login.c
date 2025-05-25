#include "ui/login/ui_tela_menu_login.h"

void ui_desenhar_tela_menu_login(void)
{

    // Desenha tela de menu login
    ui_desenhar_tela_padrao(
        UI_TITULO_PROGRAMA,
        UI_SUBTITULO_PROGRAMA,
        NULL,
        NULL);

    ui_exibir_data_hora();

    ui_exibir_info("Bem-Vindo(a)! Por favor, faça login para acessar mais opções.");
    printf("\n");
}

/* Códigos devem bater com o enum em estados.h */
const opcao_t tela_menu_login_mapa[] = {
    {1, "Login"},
    {2, "Sobre o projeto"},
    {3, "Sair"}};

const size_t tela_menu_login_mapa_n =
    sizeof(tela_menu_login_mapa) / sizeof(tela_menu_login_mapa[0]);

const char *tela_menu_login_prompt(void)
{
    return ui_prompt_opcao(1, tela_menu_login_mapa_n);
}

void ui_desenhar_tela_form_login(void)
{

    // Desenha tela de menu login
    ui_desenhar_tela_padrao(
        UI_TITULO_PROGRAMA,
        UI_SUBTITULO_PROGRAMA,
        NULL,
        NULL);
}
