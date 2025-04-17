#include <stdio.h>
#include <string.h>
#include "../../include/residuos_ui.h"
#include "../../include/residuos.h"
#include "../../include/utils.h"             // clearConsole, pauseConsole
#include "../../include/residuos_business.h"// processarAtualizacaoMensal

void iniciarInterfaceResiduos(void) {
    Residuos r;
    clearConsole();
    printf("=== Atualiza��o Mensal de Res�duos ===\n");

    // CNPJ
    printf("Digite o CNPJ da ind�stria: ");
    if (scanf("%19s", r.cnpj) != 1) {
        printf("Entrada inv�lida para CNPJ.\n");
        while(getchar()!='\n');
        return;
    }
    while(getchar()!='\n');

    // Ano
    printf("Digite o ano (ex.: 2025): ");
    if (scanf("%d", &r.ano) != 1) {
        printf("Entrada inv�lida para ano.\n");
        while(getchar()!='\n');
        return;
    }
    while(getchar()!='\n');

    // M�s
    printf("Digite o m�s (1�12): ");
    if (scanf("%d", &r.mes) != 1) {
        printf("Entrada inv�lida para m�s.\n");
        while(getchar()!='\n');
        return;
    }
    while(getchar()!='\n');

    // Quantidade tratada
    printf("Digite a quantidade de res�duos tratados: ");
    if (scanf("%lf", &r.quantidadeTratada) != 1) {
        printf("Entrada inv�lida para quantidade.\n");
        while(getchar()!='\n');
        return;
    }
    while(getchar()!='\n');

    // Custo estimado
    printf("Digite o custo estimado (R$): ");
    if (scanf("%lf", &r.custoEstimado) != 1) {
        printf("Entrada inv�lida para custo.\n");
        while(getchar()!='\n');
        return;
    }
    while(getchar()!='\n');

    if (processarAtualizacaoMensal(&r) == 0) {
        printf("Atualiza��o registrada com sucesso!\n");
    } else {
        printf("Erro ao registrar a atualiza��o.\n");
    }

    pauseConsole("Pressione ENTER para continuar...");
}
