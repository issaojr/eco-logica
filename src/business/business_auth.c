#include "business/business_auth.h"

/**
 * @brief Autentica um funcionário com base na matrícula e senha, e inicia a sessão.
 * @param matricula Matrícula do funcionário.
 * @param senha Senha em texto claro.
 * @return true se as credenciais forem válidas, false caso contrário.
 */
bool business_autenticar(char *matricula, const char *senha)
{
	funcionario_t temp;
	if (validar_funcionario_csv(matricula, senha, &temp))
	{
		funcionario_t *user = malloc(sizeof(funcionario_t));
		if (!user)
			return false;
		*user = temp;
		set_funcionario_logado(user);
		return true;
	}
	return false;
}
