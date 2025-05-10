#include <stdbool.h>
#include "business/business_industria.h"
#include "persistencia/industria_dao.h"

bool cadastrar_industria(const industria_t* industria) {
	industria_t existente;
	// Se CNPJ já existe, não cadastra
	if (validar_industria_csv(industria->cnpj, &existente)) {
		return false;
	}
	// Insere nova indústria
	return inserir_industria_csv(industria);
}