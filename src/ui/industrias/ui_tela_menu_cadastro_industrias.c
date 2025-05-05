#include "ui/industrias/ui_tela_menu_cadastro_industrias.h"

/* Cada c�digo aqui corresponde � posi��o l�gica, mas o �ndice usado pela m�quina
   de estados ser� a ordem em tela (1..5). */
const opcao_t tela_menu_cadastro_industrias_mapa[] = {
    { 1, "Listar Ind�strias" },
    { 2, "Adicionar Ind�stria" },
    { 3, "Editar Ind�stria" },
    { 4, "Excluir Ind�stria" },
    { 5, "Voltar" }
};

const size_t tela_menu_cadastro_industrias_mapa_n =
    sizeof(tela_menu_cadastro_industrias_mapa) / sizeof(tela_menu_cadastro_industrias_mapa[0]);

const char *tela_menu_cadastro_industrias_prompt =
    "\n>> Escolha uma op��o (1-5): ";