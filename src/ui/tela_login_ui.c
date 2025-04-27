#include "tela_login_ui.h"

/* Códigos devem bater com o enum em estados.h */
const opcao_t tela_login_mapa[] = {
    { 1, "Login" },
    { 2, "Sobre o projeto" },
    { 3, "Sair" }
};

const size_t tela_login_mapa_n =
    sizeof(tela_login_mapa) / sizeof(tela_login_mapa[0]);

const char *tela_login_prompt = "Escolha uma opção (1–3): ";