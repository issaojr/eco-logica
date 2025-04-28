#ifndef INDUSTRIA_BUSINESS_H
#define INDUSTRIA_BUSINESS_H

#include <stdbool.h>
#include "industria.h"

/**
 * Cadastra uma nova indústria se o CNPJ não existir.
 * @param industria Dados da indústria a cadastrar.
 * @return true se cadastrado com sucesso, false se CNPJ já existir ou falha de I/O.
 */
bool cadastrar_industria(const industria_t *industria);

#endif // INDUSTRIA_BUSINESS_H