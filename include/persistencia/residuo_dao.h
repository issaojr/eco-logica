#ifndef RESIDUO_DAO_H
#define RESIDUO_DAO_H

#define RES_FILE  "residuos.csv"

#include <stddef.h>
#include <stdbool.h>
#include "estruturas/residuo.h"

/**
 * Lê/atualiza registro de resíduos para CNPJ, mês e ano.
 */
bool gravar_residuo_csv(const residuo_t *residuo);

#endif // RESIDUO_DAO_H