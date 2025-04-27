#include "tela_menu_principal_ui.h"

/* Cada c�digo aqui corresponde � posi��o l�gica, mas o �ndice usado pela m�quina
   de estados ser� a ordem em tela (0..5). */
const opcao_t tela_menu_principal_mapa[] = {
    { 1, "Cadastro de Funcion�rio" },
    { 2, "Cadastro de Ind�stria" },
    { 3, "Atualiza��o Mensal de Res�duos" },
    { 4, "Relat�rios por Ind�stria" },
    { 5, "Relat�rios Globais" },
    { 6, "Logout" }
};

const size_t tela_menu_principal_mapa_n =
    sizeof(tela_menu_principal_mapa) / sizeof(tela_menu_principal_mapa[0]);

const char *tela_menu_principal_prompt =
    "Escolha uma op��o (1�6): ";
