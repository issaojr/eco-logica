#ifndef ESTADO_MSG_LOGIN_SUCESSO_H
#define ESTADO_MSG_LOGIN_SUCESSO_H

#include <stdlib.h>
#include <stdio.h>
#include "estados/estado.h"
#include "ui/login/ui_tela_msg_login.h"
#include "session.h"
#include "ui/ui_comum.h"

/**
 * Cria uma instância do estado de mensagem de login bem-sucedido
 * @return Ponteiro para o estado criado ou NULL em caso de falha
 */
estado_t *criar_estado_msg_login_sucesso(void);

#endif // ESTADO_MSG_LOGIN_SUCESSO_H
