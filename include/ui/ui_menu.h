#ifndef UI_MENU_H
#define UI_MENU_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ui/ui_comum.h"

/* Código de opção genúrico; -1 para inválido */
typedef enum
{
    OPCAO_INVALIDA = -1
} codigo_opcao;

/* Par código ? mensagem de uma opção de menu */
typedef struct
{
    codigo_opcao codigo;
    const char *msg;
} opcao_t;

/**
 * Imprime no stdout todas as opções de 'mapa' (tamanho n):
 *   "%2d) %s\n"
 */
void ui_imprimir_menu(const opcao_t *mapa, size_t n);

/**
 * Lê do stdin até que o usuário escolha um código presente em 'mapa' (tamanho n).
 * Exibe o 'prompt' antes da leitura.
 * Retorna OPCAO_INVALIDA em caso de EOF.
 */
codigo_opcao ui_ler_opcao(const opcao_t *mapa,
                          size_t n,
                          const char *prompt);

#endif /* UI_MENU_H */
