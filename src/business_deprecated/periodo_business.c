#include <stdlib.h>
#include "periodo_business.h"

static void adicionaPeriodo(PeriodoLista *pl, Periodo p) {
    Periodo *novo = realloc(pl->itens, sizeof(Periodo)*(pl->qtd+1));
    if (!novo) return;        // em caso de erro, aborta a adição
    pl->itens = novo;
    pl->itens[pl->qtd++] = p;
}

PeriodoLista *montarPeriodos(int tipoPeriodo,
                             int anoInicial, int mesInicial,
                             int anoFinal,   int mesFinal)
{
    PeriodoLista *pl = malloc(sizeof *pl);
    if (!pl) return NULL;
    pl->itens = NULL;
    pl->qtd   = 0;

    if (tipoPeriodo == PERIODO_MENSAL) {
        int ano = anoInicial, mes = mesInicial;
        while (ano < anoFinal || (ano == anoFinal && mes <= mesFinal)) {
            adicionaPeriodo(pl, (Periodo){ .ano=ano, .mes=mes, .semestre=0 });
            if (++mes > 12) { mes = 1; ano++; }
        }
    }
    else if (tipoPeriodo == PERIODO_SEMESTRAL) {
        int semIni = (mesInicial <= 6 ? 1 : 2);
        int semFim = (mesFinal   <= 6 ? 1 : 2);
        for (int ano = anoInicial; ano <= anoFinal; ano++) {
            for (int sem = 1; sem <= 2; sem++) {
                if (ano == anoInicial && sem < semIni) continue;
                if (ano == anoFinal   && sem > semFim) break;
                adicionaPeriodo(pl, (Periodo){ .ano=ano, .mes=0, .semestre=sem });
            }
        }
    }
    else if (tipoPeriodo == PERIODO_ANUAL) {
        for (int ano = anoInicial; ano <= anoFinal; ano++) {
            adicionaPeriodo(pl, (Periodo){ .ano=ano, .mes=0, .semestre=0 });
        }
    }

    return pl;
}

void liberarPeriodos(PeriodoLista *pl) {
    if (!pl) return;
    free(pl->itens);
    free(pl);
}
