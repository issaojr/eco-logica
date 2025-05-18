#ifndef UI_TELA_LOGIN_H
#define UI_TELA_LOGIN_H

#include "ui/ui_menu.h"

/* mapa de opções e prompt da tela de login */
extern const opcao_t tela_menu_login_mapa[];
extern const size_t tela_menu_login_mapa_n;
extern const char *tela_menu_login_prompt(void);

void ui_desenhar_tela_menu_login(void);
void ui_desenhar_tela_form_login(void);

#endif /* UI_TELA_LOGIN_H */
