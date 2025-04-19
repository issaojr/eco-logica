#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "relatorios_business.h"
#include "residuos.h"

#define CSV_FILE_RESIDUOS "residuos.csv"
#define MAX_LINE_LEN 512

/**
 * Lê o arquivo de resíduos e calcula total de insumos tratados no semestre.
 */
void gerarRelatorioInsumosSemestre(const char *cnpj, int anoIni, int anoFim) {
    FILE *f = fopen(CSV_FILE_RESIDUOS, "r");
    if (!f) {
        perror("Erro ao abrir resíduos.csv");
        return;
    }

    double total1 = 0.0, total2 = 0.0;
    char line[MAX_LINE_LEN];

    while (fgets(line, sizeof(line), f)) {
        // Formato CSV: "CNPJ",YYYY-MM,quantidade,custo
        char *p = line;
        // Extrai CNPJ entre aspas
        if (*p != '"') continue;
        p++;
        char fileCNPJ[32] = {0};
        char *q = strchr(p, '"');
        if (!q) continue;
        strncpy(fileCNPJ, p, q - p);
        p = q + 2; // p aponta para YYYY-MM

        if (strcmp(fileCNPJ, cnpj) != 0) continue;

        int ano, mes;
        if (sscanf(p, "%4d-%2d", &ano, &mes) != 2) continue;
        p = strchr(p, ',');
        if (!p) continue;
        p++;
        double qtd = atof(p);

        // Soma no semestre correto
        if (ano == anoIni) {
            if (mes >= 1 && mes <= 6)
                total1 += qtd;
            else if (mes >= 7 && mes <= 12)
                total2 += qtd;
        }
    }
    fclose(f);

    printf("Relatório de Insumos Tratados - Semestre %d:\n", anoIni);
    printf("  Total 1º semestre: %.2f\n", total1);
    printf("  Total 2º semestre: %.2f\n", total2);
}

/**
 * Stub para relatório de gastos mensais; implementar similar a insumos.
 */
void gerarRelatorioGastosMensais(const char *cnpj, int mes, int ano) {
    // TODO: implementar leitura e soma de custos mensais
    printf("Relatório de Gastos Mensais para %s em %02d/%04d...\n", cnpj, mes, ano);
}

void gerarRelatorioGlobalRegioes(void) {
    // TODO: agrupar residuo por região (usando dados de industrias.csv)
    printf("Relatório Global: Regiões com Maior Volume...\n");
}

void gerarRelatorioGlobalMenorProducao(int anoIni, int anoFim) {
    // TODO: identificar indústrias com menor soma de quantidade no período
    printf("Relatório Global: Indústrias com Menor Produção de %d a %d...\n", anoIni, anoFim);
}

void gerarRelatorioGlobalAporteFinanceiro(int anoIni, int anoFim) {
    // TODO: calcular soma de custos no período
    printf("Relatório Global: Aporte Financeiro de %d a %d...\n", anoIni, anoFim);
}
