#ifndef ESTADO_FORM_LOGIN_H
#define ESTADO_FORM_LOGIN_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "estados/estado.h"
#include "business/business_auth.h"
#include "ui/ui_comum.h"
#include "ui/ui_formulario.h"
#include "ui/login/ui_tela_menu_login.h"

/**
 * Cria uma instância do estado de formulário de login
 * @return Ponteiro para o estado criado ou NULL em caso de falha
 */
estado_t* criar_estado_form_login(void);

#endif // ESTADO_FORM_LOGIN_H