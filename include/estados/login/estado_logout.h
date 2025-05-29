#ifndef ESTADO_FORM_LOGOUT_H
#define ESTADO_FORM_LOGOUT_H

#include <stdlib.h>
#include <stdio.h>
#include "estados/estado.h"
#include "session.h"
#include "ui/ui_comum.h"

/**
 * Cria uma instância do estado de formulário de login
 * @return Ponteiro para o estado criado ou NULL em caso de falha
 */
estado_t *criar_estado_logout(void);

#endif 
