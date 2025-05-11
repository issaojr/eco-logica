#include <stdio.h>
#include <stdlib.h>
#include "ui/industrias/ui_tela_cadastro_industrias.h"
#include "ui/ui_comum.h"
#include "ui/ui_menu.h"
#include "session.h"

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

void ui_exibir_form_adicionar_industria(void) {
    ui_limpar_tela();
    ui_exibir_titulo("Adicionar Nova Ind�stria", NULL);
    ui_exibir_to_do("Exibir formul�rio de adi��o de ind�stria aqui.");
    ui_prompt_voltar_menu_principal(NULL);
}

void ui_exibir_form_editar_industria(void) {
    ui_limpar_tela();
    ui_exibir_titulo("Editar Ind�stria", NULL);
    ui_exibir_to_do("Exibir formul�rio de edi��o de ind�stria aqui.");
    ui_prompt_voltar_menu_principal(NULL);
}

void ui_exibir_form_excluir_industria(void) {
    ui_limpar_tela();
    ui_exibir_titulo("Excluir Ind�stria", NULL);
    ui_exibir_to_do("Exibir formul�rio de exclus�o de ind�stria aqui.");
    ui_prompt_voltar_menu_principal(NULL);
}

void ui_exibir_lista_industrias(void) {
    ui_limpar_tela();
    ui_exibir_titulo("Lista de Ind�strias", NULL);
    ui_exibir_to_do("Exibir lista de ind�strias cadastradas aqui.");
    ui_prompt_voltar_menu_principal(NULL);
}