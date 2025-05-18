#ifndef ESTADO_MENU_LOGIN_H
#define ESTADO_MENU_LOGIN_H

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "estados/estado.h"
#include "ui/login/ui_tela_menu_login.h"
#include "estados/estado_menu_utils.h"
#include "ui/ui_comum.h"
#include "session.h"

/**
 * Cria uma instância do estado de menu de login
 * @return Ponteiro para o estado criado ou NULL em caso de falha
 */
estado_t *criar_estado_menu_login(void);

#endif // ESTADO_MENU_LOGIN_H