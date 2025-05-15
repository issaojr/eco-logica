#ifndef RESIDUO_DAO_H
#define RESIDUO_DAO_H

#define RES_FILE  "residuos.csv"

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
#include <string.h>
#include "estruturas/residuo.h"

/**
 * L�/atualiza registro de res�duos para CNPJ, m�s e ano.
 */
bool gravar_residuo_csv(const residuo_t *residuo);

#endif // RESIDUO_DAO_H