#ifndef RELATORIOS_BUSINESS_H
#define RELATORIOS_BUSINESS_H

#include "relatorio.h"    // struct Relatorio
#include "periodo.h"     // struct PeriodoLista

/**
 * Gera um relatório para uma única indústria no período [anoInicial/mesInicial … anoFinal/mesFinal].
 * @param cnpj            CNPJ da indústria alvo.
 * @param periodo         PERIODO_MENSAL | PERIODO_SEMESTRAL | PERIODO_ANUAL
 * @param anoInicial      ano de início
 * @param mesInicial      mês de início (1–12; ignorar se ANUAL)
 * @param anoFinal        ano de fim
 * @param mesFinal        mês de fim (1–12; ignorar se ANUAL)
 * @param relatorio_out   saída: aponta para Relatorio* alocado
 * @return 0 em sucesso, <0 em erro
 */
int gerarRelatorioPorIndustria(const char *cnpj,
    int periodo,
    int anoInicial, int mesInicial,
    int anoFinal,   int mesFinal,
    Relatorio **relatorio_out);

int gerarRelatorioGlobal(
    int periodo,
    int anoInicial, int mesInicial,
    int anoFinal,   int mesFinal,
    Relatorio **relatorio_out);

#endif // RELATORIOS_BUSINESS_H
