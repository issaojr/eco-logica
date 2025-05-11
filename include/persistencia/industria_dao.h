#ifndef INDUSTRIA_DAO_H
#define INDUSTRIA_DAO_H

#define IND_FILE  "industrias.csv"

#include <stddef.h>
#include <stdbool.h>
#include "estruturas/industria.h"


/**
 * Valida se uma indústria com dado CNPJ existe na base CSV.
 */
bool validar_industria_csv(const char *cnpj, industria_t *out_industria);

/**
 * Insere uma nova indústria na base CSV.
 */
bool inserir_industria_csv(const industria_t *industria);

#endif // INDUSTRIA_DAO_H