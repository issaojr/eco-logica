#include <stdlib.h>
#include <stdbool.h>
#include "auth.h"
#include "persistencia.h"
#include "session.h"

bool autenticar(int matricula, const char *senha) {
    funcionario_t temp;
    if (validar_funcionario_csv(matricula, senha, &temp)) {
        funcionario_t *user = malloc(sizeof(funcionario_t));
        if (!user) return false;
        *user = temp;
        set_usuario_logado(user);
        return true;
    }
    return false;
}