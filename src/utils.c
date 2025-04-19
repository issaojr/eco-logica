#include <stdlib.h>
#include <stdio.h>
#include "utils.h"
#include <string.h> // Para strlen
#include <ctype.h> // Para toupper

void clearConsole(void) {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void pauseConsole(const char *msg) {
    // Exibe a mensagem personalizada. Se msg for NULL, usa uma mensagem padr�o.
    if (msg && msg[0] != '\0') {
        printf("\n%s", msg);
    } else {
        printf("\nPressione ENTER para continuar...");
    }
    getchar();
}

void toUpperCase(char *str) {
    if (str == NULL) return;
    size_t len = strlen(str);
    for (size_t i = 0; i < len; i++) {
        str[i] = (char)toupper((unsigned char)str[i]);
    }
    // Garante explicitamente o terminador
    str[len] = '\0';
}

void safeStrCopy(char *dest, const char *src, size_t size) {
    if (!dest || !src || size == 0) return;
    // Copia at� size-1 bytes e garante '\\0'
    strncpy(dest, src, size - 1);
    dest[size - 1] = '\0';
}

int inputOption() {
    int option = -1;
    if (scanf("%d", &option) != 1) {
        while(getchar() != '\n'); // Limpa o buffer
        option = -1;
    } else {
        while(getchar() != '\n'); // Limpa o buffer
    }
    return option;
}

/**
 * Cria e retorna uma nova string centralizada num espa�o de width colunas.
 * @param msg      Mensagem de entrada (n�o modificada).
 * @param width    Comprimento total do campo (colunas).
 * @return         Ponteiro para buffer alocado (chamador faz free), ou NULL se erro.
 */
char *centerMessage(const char *msg, size_t width) {
    if (!msg || width == 0) return NULL;

    size_t len = strlen(msg);
    size_t spaces = (width > len) ? (width - len) / 2 : 0;

    // +1 para o terminador '\0'
    char *padded = malloc(width + 1);
    if (!padded) return NULL;

    // "%*s" imprime 'spaces' espa�os; "%-*s" garante preenchimento � esquerda se for maior
    snprintf(padded, width + 1, "%*s%s%*s",
             (int)spaces, "", msg, (int)spaces, "");

    return padded;
}

/**
 * Vers�o �default�: centraliza msg num campo de 48 colunas.
 * @param msg      Mensagem de entrada.
 * @return         Ponteiro para buffer alocado (chamador faz free), ou NULL se erro.
 */
char *centerMessageDefault(const char *msg) {
    const size_t DEFAULT_WIDTH = 48;
    
    return centerMessage(msg, DEFAULT_WIDTH);
}

/**
 * Libera um buffer de string e retorna NULL para facilitar atribui��o.
 * @param s        Ponteiro para buffer alocado.
 * @return         NULL
 */
char *freeString(char *s) {
    free(s);
    return NULL;
}

/**
 * Alinha uma mensagem � direita em um campo de width colunas.
 * @param msg     Mensagem de entrada (n�o modificada).
 * @param width   Largura total do campo (colunas).
 * @return        Ponteiro para buffer alocado (+ '\0'); chamador deve free().
 */
char *rightAlignMessage(const char *msg, size_t width) {
    if (!msg || width == 0) return NULL;

    size_t len = strlen(msg);
    size_t spaces = (width > len) ? (width - len) : 0;

    char *padded = malloc(width + 1);
    if (!padded) return NULL;

    // "%*s" imprime 'spaces' espa�os antes de msg
    snprintf(padded, width + 1, "%*s%s", (int)spaces, "", msg);
    return padded;
}

/**
 * Vers�o �default�: alinha msg � direita num campo de 50 colunas.
 * @param msg     Mensagem de entrada.
 * @return        Ponteiro para buffer alocado; chamador deve free().
 */
char *rightAlignMessageDefault(const char *msg) {
    const size_t DEFAULT_WIDTH = 50;
    return rightAlignMessage(msg, DEFAULT_WIDTH);
}