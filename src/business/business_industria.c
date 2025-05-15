#include "business/business_industria.h"

bool cadastrar_industria(const industria_t* industria) {
	industria_t existente;
	// Se CNPJ j� existe, n�o cadastra
	if (validar_industria_csv(industria->cnpj, &existente)) {
		return false;
	}
	// Insere nova ind�stria
	return inserir_industria_csv(industria);
}

int adicionar_industria(industria_t* industria) {
	if (!industria) return 1; // Erro: ind�stria inv�lida

	// Verifica se a ind�stria j� existe
	bool existe = validar_industria_csv(industria->cnpj, industria);

	if (existe) {
		return 2; // Erro: ind�stria j� existe
	}

	// Delega a chamada para a camada de persist�ncia
	if (inserir_industria_csv(industria)) {
		return 0; // Sucesso
	} else {
		return 1; // Erro
	}
}