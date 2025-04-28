#ifndef PERSISTENCIA_H
#define PERSISTENCIA_H

#include <stdbool.h>
#include "funcionario.h"
#include "industria.h"
#include "residuos.h"

/**
 * Valida se existe um funcion�rio com matr�cula e senha hash na base CSV.
 * @param matricula Matr�cula buscada.
 * @param senha Texto claro a ser validado.
 * @param out_funcionario Preenchido com dados se encontrado.
 * @return true se v�lido, false caso contr�rio.
 */
bool validar_funcionario_csv(int matricula, const char *senha, funcionario_t *out_funcionario);

/**
 * Insere um novo funcion�rio na base CSV.
 */
bool inserir_funcionario_csv(const funcionario_t *funcionario);

/**
 * Valida se uma ind�stria com dado CNPJ existe na base CSV.
 */
bool validar_industria_csv(const char *cnpj, industria_t *out_industria);

/**
 * Insere uma nova ind�stria na base CSV.
 */
bool inserir_industria_csv(const industria_t *industria);

/**
 * L�/atualiza registro de res�duos para CNPJ, m�s e ano.
 */
bool gravar_residuo_csv(const residuo_t *residuo);

#endif // PERSISTENCIA_H
