#ifndef BUSINESS_AUTH_H
#define BUSINESS_AUTH_H

#include <stdbool.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "persistencia/funcionario_dao.h"
#include "session.h"

/**
 * Verifica se a combinação matrícula e senha é válida.
 * @param matricula Matrícula do funcionário.
 * @param senha Senha em texto claro.
 * @return true se credenciais válidas, false caso contrário.
 */
bool business_autenticar(int matricula, const char *senha);

#endif // BUSINESS_AUTH_H
