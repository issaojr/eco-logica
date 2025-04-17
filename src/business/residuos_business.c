#include <stdio.h>
#include <string.h>
#include "residuos_business.h"
#include "persistencia.h"

int processarAtualizacaoMensal(const Residuos *r) {
    if (r == NULL) return -1;

    // Valida��es b�sicas
    if (r->mes < 1 || r->mes > 12) {
        printf("M�s inv�lido: deve estar entre 1 e 12.\n");
        return -1;
    }
    if (r->quantidadeTratada < 0 || r->custoEstimado < 0) {
        printf("Valores n�o podem ser negativos.\n");
        return -1;
    }

    // Persiste no CSV
    if (salvarResiduosCSV(r, "residuos.csv") == 0) {
        printf("Dados gravados em 'residuos.csv'.\n");
        return 0;
    } else {
        printf("Falha ao gravar dados de res�duos.\n");
        return -1;
    }
}
