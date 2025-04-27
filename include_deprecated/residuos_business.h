#ifndef RESIDUOS_BUSINESS_H
#define RESIDUOS_BUSINESS_H

#include "residuos.h"
#include "periodo.h"
#include "time.h"

/**
 * @brief Processa e valida uma atualização mensal, chamando a persistência.
 * @return 0 em sucesso; -1 em erro de validação ou gravação.
 */
int processar_atualizacao_mensal(const char *cnpj, struct tm *data_ref,
    double quantidadeTratada, double custoEstimado);

double calculaVolumePorIndustria(const char *cnpj,
    int tipoPeriodo,
    int anoInicial, int mesInicial,
    int anoFinal,   int mesFinal);

double calculaCustoPorIndustria(const char *cnpj, 
    int tipoPeriodo,
    int anoInicial, int mesInicial,
    int anoFinal,   int mesFinal);

#endif // RESIDUOS_BUSINESS_H
