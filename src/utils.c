// EcoLogica/src/utils.c
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
    // Exibe a mensagem personalizada. Se msg for NULL, usa uma mensagem padrão.
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
    // Copia até size-1 bytes e garante '\\0'
    strncpy(dest, src, size - 1);
    dest[size - 1] = '\0';
}