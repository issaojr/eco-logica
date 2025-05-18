#ifndef ESTADO_MENU_UTILS_H
#define ESTADO_MENU_UTILS_H

#include <stdlib.h>
#include "estados/estado.h"
#include "ui/ui_menu.h"
#include "estados/estados.h"

/**
 * Função utilitária para processar entrada de estados de menu.
 *
 * @param mapa Array de opções do menu
 * @param mapa_n Tamanho do array de opções
 * @param prompt Texto do prompt para o usuário
 * @param estado_atual ID do estado atual (para fallback)
 * @return O próximo estado da aplicação
 */
estado_aplicacao estado_processar_estado_menu(
    const opcao_t *mapa,
    size_t mapa_n,
    const char *(*prompt_fn)(void),
    estado_aplicacao estado_atual);

#endif // ESTADO_MENU_UTILS_H