#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "relatorios_ui.h"
#include "utils.h"
#include "relatorios_business.h"
#include "info_dialog_ui.h"
#include "logged_user_ui.h" // Para mostrar o usuário logado
#include "screen_title_ui.h" // Para mostrar o título da tela
#include "strings_globais.h" // Para strings globais

void iniciarInterfaceRelatorios(int tipoRelatorio) {
    int opcao = -1; // Inicializa a opção como inválida
    const char *msgErro = "Tipo de relatório inválido!";

    switch (tipoRelatorio) {
    case POR_INDUSTRIA:
        showRelatoriosPorIndustriaMenu(); // Exibe o menu de relatórios por indústria
        break;
    case GLOBAL:
        showRelatoriosGlobaisMenu(); // Exibe o menu de relatórios globais
        break;    
    default:        
        mostrar_dlg_erro(msgErro); // Exibe mensagem de erro
        break;
    }

    opcao = -1;

    // Exibir tabela de resultados aqui (business preencheria linhas)

    // menu de exportação
    showExportMenu();

    // Ler a opção do usuário

    switch (opcao) {
        case 1:
            printf("Função de exportação TXT ainda não implementada.\n");
            break;
        case 2:
            printf("Função de exportação CSV ainda não implementada.\n");
            break;
        case 3:
            printf("Função de exportação XLS ainda não implementada.\n");
            break;
        case 4:
            return;
        case 0:
            exit(0);
        default:
            printf("Opção inválida.\n");
    }

    mostrar_msg_pausa(); // Pausa para o usuário ver os resultados
}

void showRelatoriosPorIndustriaMenu() {
    printf("Escolha uma opção >>\n\n");
    printf("1. Insumos Tratados\n");
    printf("2. Gastos\n");
    printf("9. Voltar ao Menu Anterior\n");
    printf("0. Voltar ao Menu Principal\n");
    printf("\n>> Opção: ");
}

void showRelatoriosGlobaisMenu() {
    printf("Escolha uma opção >>\n\n");
    printf("1. Regiões com Maior Volume de Resíduos Tratados\n");
    printf("2. Indústrias com Menores Volumes de Resíduos Tratados\n");
    printf("3. Aporte Financeiro\n");
    printf("9. Voltar ao Menu Anterior\n");
    printf("0. Voltar ao Menu Principal\n");
    printf("\n>> Opção: ");
}

void showExportMenu() {
    printf("Deseja Exportar? >>\n\n");
    printf("1. Exportar para TXT\n");
    printf("2. Exportar para CSV\n");
    printf("3. Exportar para XLS\n");
    printf("0. Voltar ao Menu Principal\n");
    printf("\n>> Opção: ");
}