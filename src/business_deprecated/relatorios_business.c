#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "relatorios_business.h"
#include "residuos.h"
#include "industria.h"
#include "utils.h"
#include "periodo.h"
#include "periodo_business.h"

int gerarRelatorioPorIndustria(const char *cnpj,
    int periodo,
    int anoInicial, int mesInicial,
    int anoFinal,   int mesFinal,
    Relatorio **relatorio_out)
{
    printf("Relat�rio por ind�stria ainda n�o implementado.\n");
    return -1;
}

int gerarRelatorioGlobal(int periodo,
    int anoI, int mesI,
    int anoF, int mesF,
    Relatorio **out)
{
    printf("Relat�rio global ainda n�o implementado.\n");
    return -1;
}


