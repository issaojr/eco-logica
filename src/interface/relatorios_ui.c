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

void iniciarInterfaceRelatorios(void) {
    int opcao;

    // Strings de t�tulo e mensagens
    const char *relatoriosTitle = "EcoL�gica: Gera��o de Relat�rios";
    //const char *msgCnpjInputError = "Erro: CNPJ inv�lido!";

    showLoggedUser(); // Exibe o usu�rio logado, se houver

    showTitleScreen(relatoriosTitle); // Exibe o t�tulo da tela de cadastro

    
    opcao = inputOption(); // L� a op��o do usu�rio

    char cnpj[32];
    int anoIni, anoFim, mes;
    switch (opcao) {
        case 1:
            printf("Digite o CNPJ da ind�stria: ");
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
            printf("Digite o CNPJ da ind�stria: ");
            if (scanf("%31s", cnpj) != 1) { while(getchar()!='\n'); return; }
            while(getchar()!='\n');
            printf("Digite o m�s (1-12): ");
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
            printf("Digite o ano inicial do per�odo: ");
            scanf("%d", &anoIni); while(getchar()!='\n');
            printf("Digite o ano final do per�odo: ");
            scanf("%d", &anoFim); while(getchar()!='\n');
            clearConsole();
            gerarRelatorioGlobalMenorProducao(anoIni, anoFim);
            break;
        case 5:
            printf("Digite o ano inicial do per�odo: ");
            scanf("%d", &anoIni); while(getchar()!='\n');
            printf("Digite o ano final do per�odo: ");
            scanf("%d", &anoFim); while(getchar()!='\n');
            clearConsole();
            gerarRelatorioGlobalAporteFinanceiro(anoIni, anoFim);
            break;
        case 0:
            return;
        default:
            printf("Op��o inv�lida.\n");
            return;
    }

    // Exibir tabela de resultados aqui (business preencheria linhas)

    // menu de exporta��o
    showExportMenu();

    opcao = inputOption(); // L� a op��o do usu�rio

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

    showPauseMessage(); // Pausa para o usu�rio ver os resultados
}

void showRelatoriosMenu() {
    printf("Escolha uma op��o >>\n\n");
    printf("1. Insumos Semestrais (por ind�stria)\n");
    printf("2. Gastos Mensais (por ind�stria)\n");
    printf("3. Regi�es com Maior Volume\n");
    printf("4. Menor Produ��o no Per�odo\n");
    printf("5. Aporte Financeiro Semestral\n");
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