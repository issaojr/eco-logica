#ifndef RESIDUO_DAO_H
#define RESIDUO_DAO_H

#define RES_FILE  "residuos.csv"

#include <stddef.h>
#include <stdbool.h>

/**
 * Representa um registro mensal de res�duos para uma ind�stria.
 */
typedef struct {
    char cnpj[18];  // formato 00.000.000/0000-00
    int mes;
    int ano;
    double quantidade;
    double custo;
} residuo_t;

/**
 * L�/atualiza registro de res�duos para CNPJ, m�s e ano.
 */
bool gravar_residuo_csv(const residuo_t *residuo);

#endif // RESIDUO_DAO_H