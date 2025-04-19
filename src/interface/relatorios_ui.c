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

void iniciarInterfaceRelatorios(void) {
    int opcao;

    // Strings de título e mensagens
    const char *relatoriosTitle = "EcoLógica: Geração de Relatórios";
    //const char *msgCnpjInputError = "Erro: CNPJ inválido!";

    showLoggedUser(); // Exibe o usuário logado, se houver

    showTitleScreen(relatoriosTitle); // Exibe o título da tela de cadastro

    
    opcao = inputOption(); // Lê a opção do usuário

    char cnpj[32];
    int anoIni, anoFim, mes;
    switch (opcao) {
        case 1:
            printf("Digite o CNPJ da indústria: ");
            if (scanf("%31s", cnpj) != 1) { while(getchar()!='\n'); return; }
            while(getchar()!='\n');
            printf("Digite o ano inicial do semestre: ");
            scanf("%d", &anoIni); while(getchar()!='\n');
            printf("Digite o ano final do semestre: ");
            scanf("%d", &anoFim); while(getchar()!='\n');
            clearConsole();
            gerarRelatorioInsumosSemestre(cnpj, anoIni, anoFim);
            break;
        case 2:
            printf("Digite o CNPJ da indústria: ");
            if (scanf("%31s", cnpj) != 1) { while(getchar()!='\n'); return; }
            while(getchar()!='\n');
            printf("Digite o mês (1-12): ");
            scanf("%d", &mes); while(getchar()!='\n');
            printf("Digite o ano: ");
            scanf("%d", &anoIni); while(getchar()!='\n');
            clearConsole();
            gerarRelatorioGastosMensais(cnpj, mes, anoIni);
            break;
        case 3:
            clearConsole();
            gerarRelatorioGlobalRegioes();
            break;
        case 4:
            printf("Digite o ano inicial do período: ");
            scanf("%d", &anoIni); while(getchar()!='\n');
            printf("Digite o ano final do período: ");
            scanf("%d", &anoFim); while(getchar()!='\n');
            clearConsole();
            gerarRelatorioGlobalMenorProducao(anoIni, anoFim);
            break;
        case 5:
            printf("Digite o ano inicial do período: ");
            scanf("%d", &anoIni); while(getchar()!='\n');
            printf("Digite o ano final do período: ");
            scanf("%d", &anoFim); while(getchar()!='\n');
            clearConsole();
            gerarRelatorioGlobalAporteFinanceiro(anoIni, anoFim);
            break;
        case 0:
            return;
        default:
            printf("Opção inválida.\n");
            return;
    }

    // Exibir tabela de resultados aqui (business preencheria linhas)

    // menu de exportação
    showExportMenu();

    opcao = inputOption(); // Lê a opção do usuário

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

    showPauseMessage(); // Pausa para o usuário ver os resultados
}

void showRelatoriosMenu() {
    printf("Escolha uma opção >>\n\n");
    printf("1. Insumos Semestrais (por indústria)\n");
    printf("2. Gastos Mensais (por indústria)\n");
    printf("3. Regiões com Maior Volume\n");
    printf("4. Menor Produção no Período\n");
    printf("5. Aporte Financeiro Semestral\n");
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