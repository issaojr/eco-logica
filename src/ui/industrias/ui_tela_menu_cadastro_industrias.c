#include "ui/industrias/ui_tela_menu_cadastro_industrias.h"

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