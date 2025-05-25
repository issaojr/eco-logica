#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "session.h"
#include "util.h"

static funcionario_t *funcionario_autenticado = NULL;

funcionario_t *get_funcionario_logado(void)
{
    return funcionario_autenticado;
}

void set_funcionario_logado(funcionario_t *func)
{
    funcionario_autenticado = func;
}

void logout(void)
{
    if (get_funcionario_logado() != NULL)
    {
        free(get_funcionario_logado());
        set_funcionario_logado(NULL);
    }
}
