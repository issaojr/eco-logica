#include <stdbool.h>
#include "industria_business.h"
#include "persistencia.h"

bool cadastrar_industria(const industria_t *industria) {
    industria_t existente;
    // Se CNPJ j� existe, n�o cadastra
    if (validar_industria_csv(industria->cnpj, &existente)) {
        return false;
    }
    // Insere nova ind�stria
    return inserir_industria_csv(industria);
}