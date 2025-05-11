#ifndef UI_TELA_MENU_CADASTRO_INDUSTRIAS_H
#define UI_TELA_MENU_CADASTRO_INDUSTRIAS_H

#include "ui/ui_menu.h"

/* mapa de op��es e prompt da tela de cadastro de funcion�rios */
extern const opcao_t tela_menu_cadastro_industrias_mapa[];
extern const size_t   tela_menu_cadastro_industrias_mapa_n;
extern const char    *tela_menu_cadastro_industrias_prompt;


/**
 * @brief Exibe a lista de ind�strias cadastradas.
 */
void ui_exibir_lista_industrias(void);

/**
 * @brief Exibe o formul�rio para EXCLUIR uma ind�stria.
 */
void ui_exibir_form_excluir_industria(void);

/**
 * @brief Exibe o formul�rio para EDITAR uma ind�stria.
 */
void ui_exibir_form_editar_industria(void);

/**
 * @brief Exibe o formul�rio para ADICIONAR uma ind�stria.
 */
void ui_exibir_form_adicionar_industria(void);

#endif /* UI_TELA_MENU_CADASTRO_INDUSTRIAS_H */