// EcoLogica/src/utils.c
#include <stdlib.h>
#include <stdio.h>
#include "utils.h"

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
