#include "business/business_industria.h"

int obter_todas_industrias(
	industria_t *industrias_out,
	size_t max_industrias,
	size_t *total_industrias_out)
{
	// Delega a chamada para a camada de persistência
	if (listar_industrias_csv(
			industrias_out,
			max_industrias,
			total_industrias_out))
	{
		return 0; // Sucesso
	}
	else
	{
		return 1; // Erro
	}
}

bool cadastrar_industria(const industria_t *industria)
{
	industria_t existente;
	// Se CNPJ já existe, não cadastra
	if (validar_industria_csv(industria->cnpj, &existente))
	{
		return false;
	}
	// Insere nova indústria
	return inserir_industria_csv(industria);
}

int adicionar_industria(industria_t *industria)
{
	if (!industria)
		return 1; // Erro: indústria inválida

	// Verifica se a indústria já existe
	bool existe = buscar_industria_csv(industria->cnpj, industria);

	if (existe)
	{
		return 2; // Erro: indústria já existe
	}

	// Delega a chamada para a camada de persistência
	if (inserir_industria_csv(industria))
	{
		return 0; // Sucesso
	}
	else
	{
		return 1; // Erro
	}
}

int editar_industria(industria_t *industria)
{
	if (!industria)
		return 1; // Erro: indústria inválida

	// Delega a chamada para a camada de persistência
	if (atualizar_industria_csv(industria))
	{
		return 0; // Sucesso
	}
	else
	{
		return 1; // Erro
	}
}

int excluir_industria(const char *cnpj)
{
	// Delega a chamada para a camada de persistência
	if (excluir_industria_csv(cnpj))
	{
		return 0; // Sucesso
	}
	else
	{
		return 1; // Erro
	}
}

int buscar_industria_por_cnpj(const char *cnpj, industria_t *industria_out)
{
	if (!cnpj || !industria_out)
		return 1; // Erro: CNPJ ou ponteiro inválido

	// Delega a chamada para a camada de persistência
	if (buscar_industria_csv(cnpj, industria_out))
	{
		return 0; // Sucesso
	}
	else
	{
		return 2; // Erro: indústria não encontrada
	}
}