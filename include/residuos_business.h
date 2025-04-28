#ifndef RESIDUOS_BUSINESS_H
#define RESIDUOS_BUSINESS_H

#include <stdbool.h>
#include "residuos.h"

/**
 * Registra ou atualiza os dados de res�duos mensais de uma ind�stria.
 * @param residuo Ponteiro para a estrutura com dados de CNPJ, m�s, ano, quantidade e custo.
 * @return true em caso de sucesso, false em caso de falha.
 */
bool registrar_residuo(const residuo_t *residuo);

#endif // RESIDUOS_BUSINESS_H
