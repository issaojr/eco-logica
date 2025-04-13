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

void pauseConsole(void) {
    printf("\nPressione ENTER para continuar...");
    getchar();
}
