#include "ui/funcionarios/ui_tela_menu_cadastro_funcionarios.h"

/* Cada código aqui corresponde à posição lógica, mas o índice usado pela máquina
   de estados será a ordem em tela (1..5). */
const opcao_t tela_menu_cadastro_funcionarios_mapa[] = {
    { 1, "Listar Funcionários" },
    { 2, "Adicionar Funcionário" },
    { 3, "Editar Funcionário" },
    { 4, "Excluir Funcionário" },
    { 5, "Voltar" }
};

const size_t tela_menu_cadastro_funcionarios_mapa_n =
    sizeof(tela_menu_cadastro_funcionarios_mapa) / sizeof(tela_menu_cadastro_funcionarios_mapa[0]);

const char *tela_menu_cadastro_funcionarios_prompt =
    "\n>> Escolha uma opção (1-5): ";