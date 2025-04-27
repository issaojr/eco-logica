#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "screen_title_ui.h"
#include "utils.h" // Para clearConsole



void mostrar_titulo(const char* titulo) {
    const size_t TITLE_WIDTH = 50; // Largura total do título (colunas)

    char *titulo_centralizado = centralizar_msg(titulo, TITLE_WIDTH); // Centraliza o título

    if (!titulo_centralizado) {
        // Se falhar, usa o título original
        titulo_centralizado = strdup(titulo);
    }

    printf("\n%s", titulo_centralizado); // Exibe o título centralizado
    printf("\n\n==================================================\n\n");

    titulo_centralizado = libera_mem_str(titulo_centralizado); // Libera a memória alocada para o título    
}