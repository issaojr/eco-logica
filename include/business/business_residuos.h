#ifndef RESIDUOS_BUSINESS_H
#define RESIDUOS_BUSINESS_H

#include <stdbool.h>
#include "persistencia/residuo_dao.h" // Garante que residuo_t está definido

/**
 * Registra ou atualiza os dados de resíduos mensais de uma indústria.
 * @param residuo Ponteiro para a estrutura com dados de CNPJ, mês, ano, quantidade e custo.
 * @return true em caso de sucesso, false em caso de falha.
 */
bool registrar_residuo(const residuo_t* residuo);

#endif // RESIDUOS_BUSINESS_H
