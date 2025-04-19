#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "screen_title_ui.h"
#include "utils.h" // Para clearConsole



void showTitleScreen(const char* title) {
    const size_t TITLE_WIDTH = 50; // Largura total do título (colunas)

    char *centeredTitle = centerMessage(title, TITLE_WIDTH); // Centraliza o título

    if (!centeredTitle) {
        // Se falhar, usa o título original
        centeredTitle = strdup(title);
    }

    printf("\n%s", centeredTitle); // Exibe o título centralizado
    printf("\n\n==================================================\n\n");

    centeredTitle = freeString(centeredTitle); // Libera a memória alocada para o título    
}