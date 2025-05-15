#ifndef ESTADO_MENU_UTILS_H
#define ESTADO_MENU_UTILS_H

#include <stdlib.h>
#include "estados/estado.h"
#include "ui/ui_menu.h"
#include "estados/estados.h"

/**
 * Fun��o utilit�ria para processar entrada de estados de menu.
 * 
 * @param mapa Array de op��es do menu
 * @param mapa_n Tamanho do array de op��es
 * @param prompt Texto do prompt para o usu�rio
 * @param estado_atual ID do estado atual (para fallback)
 * @return O pr�ximo estado da aplica��o
 */
estado_aplicacao estado_processar_estado_menu(const opcao_t *mapa, size_t mapa_n, 
                                      const char *prompt, estado_aplicacao estado_atual);

#endif // ESTADO_MENU_UTILS_H