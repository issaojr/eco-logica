#include "session.h"
#include <stdlib.h>


// Variável global para armazenar o usuário logado.
static Funcionario *usuarioLogado = NULL;

Funcionario* getUsuarioLogado(void) {
    return usuarioLogado;
}

void setUsuarioLogado(Funcionario *func) {
    usuarioLogado = func;
}

void logout(void) {
    if (getUsuarioLogado() != NULL) {
        free(getUsuarioLogado());
        setUsuarioLogado(NULL);
    }
}
