#ifndef UI_TELA_MSG_LOGIN_H
#define UI_TELA_MSG_LOGIN_H
#include "ui/ui_comum.h"
#include "session.h"

void ui_desenhar_tela_msg_login_sucesso(const char *nome_funcionario, const int matricula);
void ui_desenhar_tela_msg_login_falha(void);
void ui_desenhar_msg_logout_sucesso(void);
void ui_desenhar_tela_msg_logout_falha(void);

#endif // UI_TELA_MSG_LOGIN_H