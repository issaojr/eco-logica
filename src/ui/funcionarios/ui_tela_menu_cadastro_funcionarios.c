#include "ui/funcionarios/ui_tela_menu_cadastro_funcionarios.h"

/* Cada c�digo aqui corresponde � posi��o l�gica, mas o �ndice usado pela m�quina
   de estados ser� a ordem em tela (1..5). */
const opcao_t tela_menu_cadastro_funcionarios_mapa[] = {
    { 1, "Listar Funcion�rios" },
    { 2, "Adicionar Funcion�rio" },
    { 3, "Editar Funcion�rio" },
    { 4, "Excluir Funcion�rio" },
    { 5, "Voltar" }
};

const size_t tela_menu_cadastro_funcionarios_mapa_n =
    sizeof(tela_menu_cadastro_funcionarios_mapa) / sizeof(tela_menu_cadastro_funcionarios_mapa[0]);

const char *tela_menu_cadastro_funcionarios_prompt =
    "\n>> Escolha uma op��o (1-5): ";