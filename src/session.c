#include "session.h"
#include <stdlib.h>


// Vari�vel global para armazenar o usu�rio logado.
static funcionario_t *funcionario_logado = NULL;

funcionario_t* get_funcionario_logado(void) {
    return funcionario_logado;
}

void set_funcionario_logado(funcionario_t *func) {
    funcionario_logado = func;
}

void logout(void) {
    if (get_funcionario_logado() != NULL) {
        free(get_funcionario_logado());
        set_funcionario_logado(NULL);
    }
}
