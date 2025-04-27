#include <stdio.h>
#include <string.h>
#include "residuos_business.h"
#include "persistencia.h"
#include "erros.h"

int processar_atualizacao_mensal(const char *cnpj, struct tm *data_ref,
     double quantidadeTratada, double custoEstimado) {
    
    // Residuos *residuosAtualizados = (Residuos *)malloc(sizeof(Residuos));
    // if (residuosAtualizados == NULL) {
    //     printf("Erro ao alocar memória para resíduos.\n");
    //     return ERR_ALOC_MEMORIA;
    // }
    
    // // Processar data_ref

    // // Preenche os dados do resíduo
    // strncpy(residuosAtualizados->cnpj, cnpj, sizeof(residuosAtualizados->cnpj) - 1);
    // residuosAtualizados->cnpj[sizeof(residuosAtualizados->cnpj) - 1] = '\0';

    // // Persiste no CSV
    // int resultado = salvarResiduosCSV(residuosAtualizados, "residuos.csv");
    // if (resultado != 0) {
    //     printf("Erro ao salvar os dados no arquivo CSV.\n");
    //     free(residuosAtualizados);
    //     return ERR_SQLITE;
    // }
    return -1; // Implementar lógica de processamento
}

double calculaVolumePorIndustria(const char *cnpj,
    int tipoPeriodo,
    int anoInicial, int mesInicial,
    int anoFinal,   int mesFinal)
{
    double soma = 0.0;
    // FILE *fp = fopen("residuos.csv", "r");
    // if (!fp) {
    //     perror("Erro ao abrir residuos.csv");
    //     return 0.0;
    // }

    // // Cada linha do CSV: CNPJ,ano,mes,quantidadeTratada,custoEstimado
    // // Ex.: "12.345.678/0001-90,2025,3,1234.56,7890.12"
    // char linha[256];
    // // pula o header
    // if (!fgets(linha, sizeof(linha), fp)) {
    //     fclose(fp);
    //     return 0.0;
    // }

    // while (fgets(linha, sizeof(linha), fp)) {
    //     char recCnpj[32];
    //     int ano, mes;
    //     double quantidade, custo;
    //     if (sscanf(linha, "%31[^,],%d,%d,%lf,%lf",
    //                recCnpj, &ano, &mes, &quantidade, &custo) != 5) {
    //         continue; // linha mal?formatada
    //     }

    //     // só interessa esta indústria
    //     if (strcmp(recCnpj, cnpj) != 0) continue;

    //     // verifica se (ano,mes) cai no intervalo definido por tipoPeriodo
    //     int inclui = 0;
    //     if (tipoPeriodo == PERIODO_MENSAL) {
    //         inclui = (ano == anoInicial && mes == mesInicial);
    //     }
    //     else if (tipoPeriodo == PERIODO_SEMESTRAL) {
    //         // semestre 1: meses 1–6; semestre 2: meses 7–12
    //         int semInicio = (mesInicial <= 6 ? 1 : 2);
    //         int semFim    = (mesFinal   <= 6 ? 1 : 2);
    //         int semRec    = (mes <= 6 ? 1 : 2);

    //         if (ano == anoInicial && semRec == semInicio) {
    //             inclui = 1;
    //         }
    //         else if (ano == anoFinal && semRec == semFim) {
    //             inclui = 1;
    //         }
    //         // (não suportamos range de semestres em anos diferentes)
    //     }
    //     else if (tipoPeriodo == PERIODO_ANUAL) {
    //         inclui = (ano >= anoInicial && ano <= anoFinal);
    //     }

    //     if (inclui) {
    //         soma += quantidade;
    //     }
    // }

    // fclose(fp);
    return soma;
}

double calculaCustoPorIndustria(const char *cnpj, 
    int tipoPeriodo,
    int anoInicial, int mesInicial,
    int anoFinal,   int mesFinal)
{
    return 0.0; // Implementar lógica de cálculo de custo
}
