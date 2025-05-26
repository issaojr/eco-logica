#ifndef RESIDUOS_BUSINESS_H
#define RESIDUOS_BUSINESS_H

#include <stddef.h> // Para size_t
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "ui/ui_comum.h"
#include "session.h"
#include "persistencia/industria_dao.h"
#include "persistencia/residuo_dao.h" // Garante que residuo_t está definido

/**
 * Registra ou atualiza os dados de resíduos mensais de uma indústria.
 * Procura por (cnpj, mes e ano) e, se encontrado, atualiza quantidade e custo, substituindo
 * os valores anteriores.
 * Se não encontrado, insere um novo registro.
 * @param residuo Ponteiro para a estrutura com dados de CNPJ, mês, ano, quantidade e custo.
 * @return true em caso de sucesso, false em caso de falha.
 */
bool atualizar_residuo(const residuo_t *residuo);

#endif // RESIDUOS_BUSINESS_H
