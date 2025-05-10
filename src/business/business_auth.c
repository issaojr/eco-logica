#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "business/business_auth.h"
#include "persistencia/funcionario_dao.h"
#include "session.h"

/**
 * @brief Autentica um funcion�rio com base na matr�cula e senha, e inicia a sess�o.
 * @param matricula Matr�cula do funcion�rio.
 * @param senha Senha em texto claro.
 * @return true se as credenciais forem v�lidas, false caso contr�rio.
 */
bool business_autenticar(int matricula, const char* senha) {
	funcionario_t temp;
	if (validar_funcionario_csv(matricula, senha, &temp)) {
		funcionario_t* user = malloc(sizeof(funcionario_t));
		if (!user) return false;
		*user = temp;
		set_funcionario_logado(user);
		return true;
	}
	return false;
}