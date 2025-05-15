#ifndef UI_MENU_H
#define UI_MENU_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ui/ui_comum.h"

/* C�digo de op��o gen�rico; -1 para inv�lido */
typedef enum {
    OPCAO_INVALIDA = -1
} codigo_opcao;

/* Par c�digo ? mensagem de uma op��o de menu */
typedef struct {
    codigo_opcao codigo;
    const char *msg;
} opcao_t;

/**
 * Imprime no stdout todas as op��es de 'mapa' (tamanho n):
 *   "%2d) %s\n"
 */
void ui_imprimir_menu(const opcao_t *mapa, size_t n);

/**
 * L� do stdin at� que o usu�rio escolha um c�digo presente em 'mapa' (tamanho n).
 * Exibe o 'prompt' antes da leitura.
 * Retorna OPCAO_INVALIDA em caso de EOF.
 */
codigo_opcao ui_ler_opcao(const opcao_t *mapa,
                       size_t n,
                       const char *prompt);

#endif /* UI_MENU_H */