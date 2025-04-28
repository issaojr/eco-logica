#ifndef PERSISTENCIA_H
#define PERSISTENCIA_H

#include <stdbool.h>
#include "funcionario.h"
#include "industria.h"
#include "residuos.h"

/**
 * Valida se existe um funcionário com matrícula e senha hash na base CSV.
 * @param matricula Matrícula buscada.
 * @param senha Texto claro a ser validado.
 * @param out_funcionario Preenchido com dados se encontrado.
 * @return true se válido, false caso contrário.
 */
bool validar_funcionario_csv(int matricula, const char *senha, funcionario_t *out_funcionario);

/**
 * Insere um novo funcionário na base CSV.
 */
bool inserir_funcionario_csv(const funcionario_t *funcionario);

/**
 * Valida se uma indústria com dado CNPJ existe na base CSV.
 */
bool validar_industria_csv(const char *cnpj, industria_t *out_industria);

/**
 * Insere uma nova indústria na base CSV.
 */
bool inserir_industria_csv(const industria_t *industria);

/**
 * Lê/atualiza registro de resíduos para CNPJ, mês e ano.
 */
bool gravar_residuo_csv(const residuo_t *residuo);

#endif // PERSISTENCIA_H
