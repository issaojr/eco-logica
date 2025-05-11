#include <stdio.h>
#include <stdlib.h>
#include "ui/industrias/ui_tela_cadastro_industrias.h"
#include "ui/ui_comum.h"
#include "ui/ui_menu.h"
#include "session.h"

/* Cada código aqui corresponde à posição lógica, mas o índice usado pela máquina
   de estados será a ordem em tela (1..5). */
const opcao_t tela_menu_cadastro_industrias_mapa[] = {
    { 1, "Listar Indústrias" },
    { 2, "Adicionar Indústria" },
    { 3, "Editar Indústria" },
    { 4, "Excluir Indústria" },
    { 5, "Voltar" }
};

const size_t tela_menu_cadastro_industrias_mapa_n =
    sizeof(tela_menu_cadastro_industrias_mapa) / sizeof(tela_menu_cadastro_industrias_mapa[0]);

const char *tela_menu_cadastro_industrias_prompt =
    "\n>> Escolha uma opção (1-5): ";

void ui_exibir_form_adicionar_industria(void) {
    ui_limpar_tela();
    ui_exibir_titulo("Adicionar Nova Indústria", NULL);
    ui_exibir_to_do("Exibir formulário de adição de indústria aqui.");
    ui_prompt_voltar_menu_principal(NULL);
}

void ui_exibir_form_editar_industria(void) {
    ui_limpar_tela();
    ui_exibir_titulo("Editar Indústria", NULL);
    ui_exibir_to_do("Exibir formulário de edição de indústria aqui.");
    ui_prompt_voltar_menu_principal(NULL);
}

void ui_exibir_form_excluir_industria(void) {
    ui_limpar_tela();
    ui_exibir_titulo("Excluir Indústria", NULL);
    ui_exibir_to_do("Exibir formulário de exclusão de indústria aqui.");
    ui_prompt_voltar_menu_principal(NULL);
}

void ui_exibir_lista_industrias(void) {
    ui_limpar_tela();
    ui_exibir_titulo("Lista de Indústrias", NULL);
    ui_exibir_to_do("Exibir lista de indústrias cadastradas aqui.");
    ui_prompt_voltar_menu_principal(NULL);
}