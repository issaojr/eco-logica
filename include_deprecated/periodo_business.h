#ifndef PERIODO_BUSINESS_H
#define PERIODO_BUSINESS_H

#include "periodo.h"

/**
 * Monta a sequência de períodos entre (anoIni/mesIni) e (anoFim/mesFim),
 * de acordo com tipo (MENSAL, SEMESTRAL ou ANUAL).
 * @retorna NULL em falha de alocação; em caso de sucesso caller deve chamar liberarPeriodos().
 */
PeriodoLista *montarPeriodos(int tipoPeriodo,
                             int anoInicial, int mesInicial,
                             int anoFinal,   int mesFinal);

/**
 * Libera toda a memória alocada por montarPeriodos().
 */
void liberarPeriodos(PeriodoLista *pl);

#endif // PERIODO_BUSINESS_H
