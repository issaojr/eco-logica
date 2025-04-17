#include <stdio.h>
#include <string.h>
#include "../../include/residuos_ui.h"
#include "../../include/residuos.h"
#include "../../include/utils.h"             // clearConsole, pauseConsole
#include "../../include/residuos_business.h"// processarAtualizacaoMensal

void iniciarInterfaceResiduos(void) {
    Residuos r;
    clearConsole();
    printf("=== Atualização Mensal de Resíduos ===\n");

    // CNPJ
    printf("Digite o CNPJ da indústria: ");
    if (scanf("%19s", r.cnpj) != 1) {
        printf("Entrada inválida para CNPJ.\n");
        while(getchar()!='\n');
        return;
    }
    while(getchar()!='\n');

    // Ano
    printf("Digite o ano (ex.: 2025): ");
    if (scanf("%d", &r.ano) != 1) {
        printf("Entrada inválida para ano.\n");
        while(getchar()!='\n');
        return;
    }
    while(getchar()!='\n');

    // Mês
    printf("Digite o mês (1–12): ");
    if (scanf("%d", &r.mes) != 1) {
        printf("Entrada inválida para mês.\n");
        while(getchar()!='\n');
        return;
    }
    while(getchar()!='\n');

    // Quantidade tratada
    printf("Digite a quantidade de resíduos tratados: ");
    if (scanf("%lf", &r.quantidadeTratada) != 1) {
        printf("Entrada inválida para quantidade.\n");
        while(getchar()!='\n');
        return;
    }
    while(getchar()!='\n');

    // Custo estimado
    printf("Digite o custo estimado (R$): ");
    if (scanf("%lf", &r.custoEstimado) != 1) {
        printf("Entrada inválida para custo.\n");
        while(getchar()!='\n');
        return;
    }
    while(getchar()!='\n');

    if (processarAtualizacaoMensal(&r) == 0) {
        printf("Atualização registrada com sucesso!\n");
    } else {
        printf("Erro ao registrar a atualização.\n");
    }

    pauseConsole("Pressione ENTER para continuar...");
}
