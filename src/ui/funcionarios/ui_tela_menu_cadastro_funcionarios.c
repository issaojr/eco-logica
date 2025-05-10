#include "ui/funcionarios/ui_tela_menu_cadastro_funcionarios.h"
#include "ui/ui_menu.h"

void ui_desenhar_tela_menu_cadastro_funcionarios(
    const char *nome_funcionario, 
    const int matricula) {

    const char *titulo = "EcoL�gica Solu��es Ambientais";
    const char *subtitulo = "Sistema de Gest�o Ambiental";
    const char *cabecalho = "MENU DE CADASTRO DE FUNCION�RIOS";

    // Desenha tela de menu de cadastro de funcion�rios
    ui_desenhar_tela_menu_padrao(
        titulo, 
        subtitulo, 
        nome_funcionario, 
        matricula, 
        cabecalho
    );

    printf("\n");
}

opcao_t tela_menu_cadastro_funcionarios_mapa[] = {
    { 1, "Listar Funcion�rios" },
    { 2, "Adicionar Funcion�rio" },
    { 3, "Editar Funcion�rio" },
    { 4, "Excluir Funcion�rio" },
    { 5, "Voltar" }
};

size_t tela_menu_cadastro_funcionarios_mapa_n =
    sizeof(tela_menu_cadastro_funcionarios_mapa) / sizeof(tela_menu_cadastro_funcionarios_mapa[0]);

char *tela_menu_cadastro_funcionarios_prompt = PROMPT_OPCOES(1, 5);