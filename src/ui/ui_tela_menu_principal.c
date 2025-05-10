#include "ui/ui_tela_menu_principal.h"

void ui_desenhar_tela_menu_principal(const char *nome_funcionario, 
                                           const int matricula) {
    const char *titulo = "EcoL�gica Solu��es Ambientais";
    const char *subtitulo = "Sistema de Gest�o Ambiental";
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
    { 1, "Cadastro de Funcion�rio" },
    { 2, "Cadastro de Ind�stria" },
    { 3, "Atualiza��o Mensal de Res�duos" },
    { 4, "Relat�rios por Ind�stria" },
    { 5, "Relat�rios Globais" },
    { 6, "Logout" }
};

const size_t tela_menu_principal_mapa_n =
    sizeof(tela_menu_principal_mapa) / sizeof(tela_menu_principal_mapa[0]);

const char *tela_menu_principal_prompt = PROMPT_OPCOES(1, 6);
