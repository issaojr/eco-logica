#ifndef BUSINESS_INDUSTRIA_H
#define BUSINESS_INDUSTRIA_H

#include <stdbool.h>
#include "persistencia/industria_dao.h" // Garante que industria_t está definido

/**
 * Cadastra uma nova indústria se o CNPJ não existir.
 * @param industria Dados da indústria a cadastrar.
 * @return true se cadastrado com sucesso, false se CNPJ já existir ou falha de I/O.
 */
bool cadastrar_industria(const industria_t* industria);

#endif // BUSINESS_INDUSTRIA_H