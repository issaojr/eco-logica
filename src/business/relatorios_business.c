#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "relatorios_business.h"
#include "residuos.h"

#define CSV_FILE_RESIDUOS "residuos.csv"
#define MAX_LINE_LEN 512

/**
 * L� o arquivo de res�duos e calcula total de insumos tratados no semestre.
 */
void gerarRelatorioInsumosSemestre(const char *cnpj, int anoIni, int anoFim) {
    FILE *f = fopen(CSV_FILE_RESIDUOS, "r");
    if (!f) {
        perror("Erro ao abrir res�duos.csv");
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

    printf("Relat�rio de Insumos Tratados - Semestre %d:\n", anoIni);
    printf("  Total 1� semestre: %.2f\n", total1);
    printf("  Total 2� semestre: %.2f\n", total2);
}

/**
 * Stub para relat�rio de gastos mensais; implementar similar a insumos.
 */
void gerarRelatorioGastosMensais(const char *cnpj, int mes, int ano) {
    // TODO: implementar leitura e soma de custos mensais
    printf("Relat�rio de Gastos Mensais para %s em %02d/%04d...\n", cnpj, mes, ano);
}

void gerarRelatorioGlobalRegioes(void) {
    // TODO: agrupar residuo por regi�o (usando dados de industrias.csv)
    printf("Relat�rio Global: Regi�es com Maior Volume...\n");
}

void gerarRelatorioGlobalMenorProducao(int anoIni, int anoFim) {
    // TODO: identificar ind�strias com menor soma de quantidade no per�odo
    printf("Relat�rio Global: Ind�strias com Menor Produ��o de %d a %d...\n", anoIni, anoFim);
}

void gerarRelatorioGlobalAporteFinanceiro(int anoIni, int anoFim) {
    // TODO: calcular soma de custos no per�odo
    printf("Relat�rio Global: Aporte Financeiro de %d a %d...\n", anoIni, anoFim);
}
