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
    
    // Strings de título e mensagens
    const char *residuosTitle = "EcoLógica: Atualização Mensal de Resíduos";
    const char *msgCnpjError = "Erro: CNPJ inválido!";
    const char *msgAnoError = "Erro: Ano inválido!";
    const char *msgMesError = "Erro: Mês inválido!";
    const char *msgQuantidadeError = "Erro: Quantidade inválida!";
    const char *msgCustoError = "Erro: Custo inválido!";
    const char *msgAtualizacaoSuccess = "Atualização registrada com sucesso!";
    const char *msgAtualizacaoError = "Erro ao registrar a atualização!";

    showLoggedUser(); // Exibe o usuário logado, se houver

    showTitleScreen(residuosTitle); // Exibe o título da tela de atualização mensal

    // CNPJ
    printf(">> Digite o CNPJ da indústria: ");
    if (scanf("%19s", r.cnpj) != 1) {
        //printf("Entrada inválida para CNPJ.\n");
        while(getchar()!='\n');
        showErrorDialog(msgCnpjError);
        return;
    }
    while(getchar()!='\n');

    // Ano
    printf(">> Digite o ano (ex.: 2025): ");
    if (scanf("%d", &r.ano) != 1) {
        //printf("Entrada inválida para ano.\n");
        while(getchar()!='\n');
        showErrorDialog(msgAnoError);
        return;
    }
    while(getchar()!='\n');

    // Mês
    printf(">> Digite o mês (1–12): ");
    if (scanf("%d", &r.mes) != 1) {
        //printf("Entrada inválida para mês.\n");
        while(getchar()!='\n');
        showErrorDialog(msgMesError);
        return;
    }
    while(getchar()!='\n');

    // Quantidade tratada
    printf(">> Digite a quantidade de resíduos tratados: ");
    if (scanf("%lf", &r.quantidadeTratada) != 1) {
        //printf("Entrada inválida para quantidade.\n");
        while(getchar()!='\n');
        showErrorDialog(msgQuantidadeError);
        return;
    }
    while(getchar()!='\n');

    // Custo estimado
    printf(">> Digite o custo estimado (R$): ");
    if (scanf("%lf", &r.custoEstimado) != 1) {
        //printf("Entrada inválida para custo.\n");
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
