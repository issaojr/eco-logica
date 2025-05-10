#include "ui/funcionarios/ui_tela_menu_cadastro_funcionarios.h"
#include "ui/ui_menu.h"

void ui_desenhar_tela_menu_cadastro_funcionarios(
    const char *nome_funcionario, 
    const int matricula) {

    const char *titulo = "EcoLógica Soluções Ambientais";
    const char *subtitulo = "Sistema de Gestão Ambiental";
    const char *cabecalho = "MENU DE CADASTRO DE FUNCIONÁRIOS";

    // Desenha tela de menu de cadastro de funcionários
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
    { 1, "Listar Funcionários" },
    { 2, "Adicionar Funcionário" },
    { 3, "Editar Funcionário" },
    { 4, "Excluir Funcionário" },
    { 5, "Voltar" }
};

size_t tela_menu_cadastro_funcionarios_mapa_n =
    sizeof(tela_menu_cadastro_funcionarios_mapa) / sizeof(tela_menu_cadastro_funcionarios_mapa[0]);

char *tela_menu_cadastro_funcionarios_prompt = PROMPT_OPCOES(1, 5);