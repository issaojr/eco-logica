// EcoLogica/src/main.c
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "utils.h"
#include "menu.h"

int main(void) {
    system("chcp 1252 > nul");  // Força o console a usar code page 1252

    // Define o locale para português do Brasil com CP-1252
    setlocale(LC_ALL, "Portuguese_Brazil.1252");    

    // Exibe o menu principal
    showMainMenu();
    
    return 0;
}
