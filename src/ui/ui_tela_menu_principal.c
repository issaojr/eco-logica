#include "ui/ui_tela_menu_principal.h"

void ui_desenhar_tela_menu_principal(const char *nome_funcionario, 
                                           const int matricula) {
    const char *titulo = "EcoLógica Soluções Ambientais";
    const char *subtitulo = "Sistema de Gestão Ambiental";
    const char *cabecalho = "MENU PRINCIPAL";
    
    // Desenha tela de menu principal
    ui_desenhar_tela_menu_padrao(
        titulo, 
        subtitulo, 
        nome_funcionario, 
        matricula, 
        cabecalho
    );
    
    printf("\n");
}

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

const char *tela_menu_principal_prompt = PROMPT_OPCOES(1, 6);
