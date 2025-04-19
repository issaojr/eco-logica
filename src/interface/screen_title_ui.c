#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "screen_title_ui.h"
#include "utils.h" // Para clearConsole



void showTitleScreen(const char* title) {
    const size_t TITLE_WIDTH = 50; // Largura total do t�tulo (colunas)

    char *centeredTitle = centerMessage(title, TITLE_WIDTH); // Centraliza o t�tulo

    if (!centeredTitle) {
        // Se falhar, usa o t�tulo original
        centeredTitle = strdup(title);
    }

    printf("\n%s", centeredTitle); // Exibe o t�tulo centralizado
    printf("\n\n==================================================\n\n");

    centeredTitle = freeString(centeredTitle); // Libera a mem�ria alocada para o t�tulo    
}