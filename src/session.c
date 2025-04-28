#include "session.h"
#include <stdlib.h>


// Vari�vel global para armazenar o usu�rio logado.
static funcionario_t *usuario_logado = NULL;

funcionario_t* get_usuario_logado(void) {
    return usuario_logado;
}

void set_usuario_logado(funcionario_t *func) {
    usuario_logado = func;
}

void logout(void) {
    if (get_usuario_logado() != NULL) {
        free(get_usuario_logado());
        set_usuario_logado(NULL);
    }
}
