#include <stdbool.h>
#include "industria_business.h"
#include "persistencia.h"

bool cadastrar_industria(const industria_t *industria) {
    industria_t existente;
    // Se CNPJ já existe, não cadastra
    if (validar_industria_csv(industria->cnpj, &existente)) {
        return false;
    }
    // Insere nova indústria
    return inserir_industria_csv(industria);
}