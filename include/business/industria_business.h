#ifndef INDUSTRIA_BUSINESS_H
#define INDUSTRIA_BUSINESS_H

#include <stdbool.h>
#include "persistencia/industria_dao.h" // Garante que industria_t est� definido

/**
 * Cadastra uma nova ind�stria se o CNPJ n�o existir.
 * @param industria Dados da ind�stria a cadastrar.
 * @return true se cadastrado com sucesso, false se CNPJ j� existir ou falha de I/O.
 */
bool cadastrar_industria(const industria_t *industria);

#endif // INDUSTRIA_BUSINESS_H