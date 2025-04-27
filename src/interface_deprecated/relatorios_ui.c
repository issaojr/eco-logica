#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "relatorios_ui.h"
#include "utils.h"
#include "relatorios_business.h"
#include "info_dialog_ui.h"
#include "logged_user_ui.h" // Para mostrar o usu�rio logado
#include "screen_title_ui.h" // Para mostrar o t�tulo da tela
#include "strings_globais.h" // Para strings globais

void iniciarInterfaceRelatorios(int tipoRelatorio) {
    int opcao = -1; // Inicializa a op��o como inv�lida
    const char *msgErro = "Tipo de relat�rio inv�lido!";

    switch (tipoRelatorio) {
    case POR_INDUSTRIA:
        showRelatoriosPorIndustriaMenu(); // Exibe o menu de relat�rios por ind�stria
        break;
    case GLOBAL:
        showRelatoriosGlobaisMenu(); // Exibe o menu de relat�rios globais
        break;    
    default:        
        mostrar_dlg_erro(msgErro); // Exibe mensagem de erro
        break;
    }

    opcao = -1;

    // Exibir tabela de resultados aqui (business preencheria linhas)

    // menu de exporta��o
    showExportMenu();

    // Ler a op��o do usu�rio

    switch (opcao) {
        case 1:
            printf("Fun��o de exporta��o TXT ainda n�o implementada.\n");
            break;
        case 2:
            printf("Fun��o de exporta��o CSV ainda n�o implementada.\n");
            break;
        case 3:
            printf("Fun��o de exporta��o XLS ainda n�o implementada.\n");
            break;
        case 4:
            return;
        case 0:
            exit(0);
        default:
            printf("Op��o inv�lida.\n");
    }

    mostrar_msg_pausa(); // Pausa para o usu�rio ver os resultados
}

void showRelatoriosPorIndustriaMenu() {
    printf("Escolha uma op��o >>\n\n");
    printf("1. Insumos Tratados\n");
    printf("2. Gastos\n");
    printf("9. Voltar ao Menu Anterior\n");
    printf("0. Voltar ao Menu Principal\n");
    printf("\n>> Op��o: ");
}

void showRelatoriosGlobaisMenu() {
    printf("Escolha uma op��o >>\n\n");
    printf("1. Regi�es com Maior Volume de Res�duos Tratados\n");
    printf("2. Ind�strias com Menores Volumes de Res�duos Tratados\n");
    printf("3. Aporte Financeiro\n");
    printf("9. Voltar ao Menu Anterior\n");
    printf("0. Voltar ao Menu Principal\n");
    printf("\n>> Op��o: ");
}

void showExportMenu() {
    printf("Deseja Exportar? >>\n\n");
    printf("1. Exportar para TXT\n");
    printf("2. Exportar para CSV\n");
    printf("3. Exportar para XLS\n");
    printf("0. Voltar ao Menu Principal\n");
    printf("\n>> Op��o: ");
}