#include "session.h"
#include <stdlib.h>


// Variável global para armazenar o usuário logado.
static Funcionario *usuarioLogado = NULL;

Funcionario* get_usuario_logado(void) {
    return usuarioLogado;
}

void set_usuario_logado(Funcionario *func) {
    usuarioLogado = func;
}

void logout(void) {
    if (get_usuario_logado() != NULL) {
        free(get_usuario_logado());
        set_usuario_logado(NULL);
    }
}
