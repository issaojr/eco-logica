#include "ui/ui_tela_menu_principal.h"

/* Cada código aqui corresponde à posição lógica, mas o índice usado pela máquina
   de estados será a ordem em tela (1..6). */
const opcao_t tela_menu_principal_mapa[] = {
    { 1, "Cadastro de Funcionário" },
    { 2, "Cadastro de Indústria" },
    { 3, "Atualização Mensal de Resíduos" },
    { 4, "Relatórios por Indústria" },
    { 5, "Relatórios Globais" },
    { 6, "Logout" }
};

const size_t tela_menu_principal_mapa_n =
    sizeof(tela_menu_principal_mapa) / sizeof(tela_menu_principal_mapa[0]);

const char *tela_menu_principal_prompt =
    "\n>> Escolha uma opção (1–6): ";
