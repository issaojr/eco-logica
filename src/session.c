#include "session.h"
#include <stdlib.h>


// Vari�vel global para armazenar o usu�rio logado.
static Funcionario *usuarioLogado = NULL;

Funcionario* getUsuarioLogado(void) {
    return usuarioLogado;
}

void setUsuarioLogado(Funcionario *func) {
    usuarioLogado = func;
}

void logout(void) {
    usuarioLogado = NULL;
}
