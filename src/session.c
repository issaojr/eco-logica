#include "session.h"
#include <stdlib.h>


// Variável global para armazenar o usuário logado.
static funcionario_t *usuarioLogado = NULL;

funcionario_t* get_usuario_logado(void) {
    return usuarioLogado;
}

void set_usuario_logado(funcionario_t *func) {
    usuarioLogado = func;
}

void logout(void) {
    if (get_usuario_logado() != NULL) {
        free(get_usuario_logado());
        set_usuario_logado(NULL);
    }
}
