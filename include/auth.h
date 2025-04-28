#ifndef AUTH_H
#define AUTH_H

#include <stdbool.h>

/**
 * Verifica se a combinação matrícula e senha é válida.
 * @param matricula Matrícula do funcionário.
 * @param senha Senha em texto claro.
 * @return true se credenciais válidas, false caso contrário.
 */
bool autenticar(int matricula, const char *senha);

#endif // AUTH_H
