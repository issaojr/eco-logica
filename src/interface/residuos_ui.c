#include <stdio.h>
#include <string.h>
#include "residuos_ui.h"
#include "residuos.h"
#include "utils.h"             // clearConsole, pauseConsole
#include "residuos_business.h"// processarAtualizacaoMensal
#include "logged_user_ui.h"   // showLoggedUser
#include "screen_title_ui.h"  // showTitleScreen
#include "info_dialog_ui.h"  // showInfoDialog, showErrorDialog
#include "strings_globais.h" // MSG_ENTER_CONTINUAR

void iniciarInterfaceResiduos(void) {
    Residuos r;
    
    // Strings de t�tulo e mensagens
    const char *residuosTitle = "EcoL�gica: Atualiza��o Mensal de Res�duos";
    const char *msgCnpjError = "Erro: CNPJ inv�lido!";
    const char *msgAnoError = "Erro: Ano inv�lido!";
    const char *msgMesError = "Erro: M�s inv�lido!";
    const char *msgQuantidadeError = "Erro: Quantidade inv�lida!";
    const char *msgCustoError = "Erro: Custo inv�lido!";
    const char *msgAtualizacaoSuccess = "Atualiza��o registrada com sucesso!";
    const char *msgAtualizacaoError = "Erro ao registrar a atualiza��o!";

    showLoggedUser(); // Exibe o usu�rio logado, se houver

    showTitleScreen(residuosTitle); // Exibe o t�tulo da tela de atualiza��o mensal

    // CNPJ
    printf(">> Digite o CNPJ da ind�stria: ");
    if (scanf("%19s", r.cnpj) != 1) {
        //printf("Entrada inv�lida para CNPJ.\n");
        while(getchar()!='\n');
        showErrorDialog(msgCnpjError);
        return;
    }
    while(getchar()!='\n');

    // Ano
    printf(">> Digite o ano (ex.: 2025): ");
    if (scanf("%d", &r.ano) != 1) {
        //printf("Entrada inv�lida para ano.\n");
        while(getchar()!='\n');
        showErrorDialog(msgAnoError);
        return;
    }
    while(getchar()!='\n');

    // M�s
    printf(">> Digite o m�s (1�12): ");
    if (scanf("%d", &r.mes) != 1) {
        //printf("Entrada inv�lida para m�s.\n");
        while(getchar()!='\n');
        showErrorDialog(msgMesError);
        return;
    }
    while(getchar()!='\n');

    // Quantidade tratada
    printf(">> Digite a quantidade de res�duos tratados: ");
    if (scanf("%lf", &r.quantidadeTratada) != 1) {
        //printf("Entrada inv�lida para quantidade.\n");
        while(getchar()!='\n');
        showErrorDialog(msgQuantidadeError);
        return;
    }
    while(getchar()!='\n');

    // Custo estimado
    printf(">> Digite o custo estimado (R$): ");
    if (scanf("%lf", &r.custoEstimado) != 1) {
        //printf("Entrada inv�lida para custo.\n");
        while(getchar()!='\n');
        showErrorDialog(msgCustoError);
        return;
    }
    while(getchar()!='\n');

    if (processarAtualizacaoMensal(&r) == 0) {
        showInfoDialog(msgAtualizacaoSuccess); // Exibe mensagem de sucesso
    } else {
        showErrorDialog(msgAtualizacaoError); // Exibe mensagem de erro
    }
}
