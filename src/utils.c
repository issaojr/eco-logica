#include <stdlib.h>
#include <stdio.h>
#include "utils.h"
#include <string.h> // Para strlen
#include <ctype.h> // Para toupper

void clear_console(void) {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void pause_console(const char *msg) {
    // Exibe a mensagem personalizada. Se msg for NULL, usa uma mensagem padrão.
    if (msg && msg[0] != '\0') {
        printf("\n%s", msg);
    } else {
        printf("\nPressione ENTER para continuar...");
    }
    getchar();
}

void to_upper_case(char *str) {
    if (str == NULL) return;
    size_t len = strlen(str);
    for (size_t i = 0; i < len; i++) {
        str[i] = (char)toupper((unsigned char)str[i]);
    }
    // Garante explicitamente o terminador
    str[len] = '\0';
}

void safe_str_copy(char *dest, const char *src, size_t size) {
    if (!dest || !src || size == 0) return;
    // Copia até size-1 bytes e garante '\\0'
    strncpy(dest, src, size - 1);
    dest[size - 1] = '\0';
}

/**
 * Cria e retorna uma nova string centralizada num espaço de width colunas.
 * @param msg      Mensagem de entrada (não modificada).
 * @param width    Comprimento total do campo (colunas).
 * @return         Ponteiro para buffer alocado (chamador faz free), ou NULL se erro.
 */
char *centralizar_msg(const char *msg, size_t width) {
    if (!msg || width == 0) return NULL;

    size_t len = strlen(msg);
    size_t spaces = (width > len) ? (width - len) / 2 : 0;

    // +1 para o terminador '\0'
    char *padded = malloc(width + 1);
    if (!padded) return NULL;

    // "%*s" imprime 'spaces' espaços; "%-*s" garante preenchimento à esquerda se for maior
    snprintf(padded, width + 1, "%*s%s%*s",
             (int)spaces, "", msg, (int)spaces, "");

    return padded;
}

/**
 * Versão “default”: centraliza msg num campo de 48 colunas.
 * @param msg      Mensagem de entrada.
 * @return         Ponteiro para buffer alocado (chamador faz free), ou NULL se erro.
 */
char *center_message_default(const char *msg) {
    const size_t DEFAULT_WIDTH = 48;
    
    return centralizar_msg(msg, DEFAULT_WIDTH);
}

/**
 * Libera um buffer de string e retorna NULL para facilitar atribuição.
 * @param s        Ponteiro para buffer alocado.
 * @return         NULL
 */
char *libera_mem_str(char *s) {
    free(s);
    return NULL;
}

/**
 * Alinha uma mensagem à direita em um campo de width colunas.
 * @param msg     Mensagem de entrada (não modificada).
 * @param width   Largura total do campo (colunas).
 * @return        Ponteiro para buffer alocado (+ '\0'); chamador deve free().
 */
char *right_align_message(const char *msg, size_t width) {
    if (!msg || width == 0) return NULL;

    size_t len = strlen(msg);
    size_t spaces = (width > len) ? (width - len) : 0;

    char *padded = malloc(width + 1);
    if (!padded) return NULL;

    // "%*s" imprime 'spaces' espaços antes de msg
    snprintf(padded, width + 1, "%*s%s", (int)spaces, "", msg);
    return padded;
}

/**
 * Versão “default”: alinha msg à direita num campo de 50 colunas.
 * @param msg     Mensagem de entrada.
 * @return        Ponteiro para buffer alocado; chamador deve free().
 */
char *right_align_message_default(const char *msg) {
    const size_t DEFAULT_WIDTH = 50;
    return right_align_message(msg, DEFAULT_WIDTH);
}

