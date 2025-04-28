#ifndef AUTH_H
#define AUTH_H

#include <stdbool.h>

/**
 * Verifica se a combina��o matr�cula e senha � v�lida.
 * @param matricula Matr�cula do funcion�rio.
 * @param senha Senha em texto claro.
 * @return true se credenciais v�lidas, false caso contr�rio.
 */
bool autenticar(int matricula, const char *senha);

#endif // AUTH_H
