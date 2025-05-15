#include "business/business_industria.h"

bool cadastrar_industria(const industria_t* industria) {
	industria_t existente;
	// Se CNPJ já existe, não cadastra
	if (validar_industria_csv(industria->cnpj, &existente)) {
		return false;
	}
	// Insere nova indústria
	return inserir_industria_csv(industria);
}

int adicionar_industria(industria_t* industria) {
	if (!industria) return 1; // Erro: indústria inválida

	// Verifica se a indústria já existe
	bool existe = validar_industria_csv(industria->cnpj, industria);

	if (existe) {
		return 2; // Erro: indústria já existe
	}

	// Delega a chamada para a camada de persistência
	if (inserir_industria_csv(industria)) {
		return 0; // Sucesso
	} else {
		return 1; // Erro
	}
}