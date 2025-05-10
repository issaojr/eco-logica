#include <stdio.h>
#include <stdlib.h>
#include "ui/funcionarios/ui_lista_funcionarios.h"

void ui_desenhar_tela_lista_funcionarios(void) {
    
    const char *titulo = "EcoLógica Soluções Ambientais";
    const char *subtitulo = "Sistema de Gestão Ambiental";
    const char *cabecalho = "LISTA DE FUNCIONÁRIOS";
    
    /* Desenha tela de lista de funcionários */
    ui_desenhar_tela_relatorio_padrao(
        titulo, 
        subtitulo, 
        cabecalho
    );

    printf("\n");
}

/**
 * @brief Exibe a lista de funcionários
 * @param funcionarios_out Array de funcionários
 * @param max_funcionarios Tamanho máximo do array
 * @param total_funcionarios_out Ponteiro para o total de funcionários
 * @note A função exibe a lista de funcionários formatada no console.
 */
void ui_exibir_lista_funcionarios(
    funcionario_t* funcionarios_out, 
    size_t max_funcionarios, 
    size_t* total_funcionarios_out) {
     

    printf(UI_COR_NEGRITO "Matrícula   Nome\n" UI_COR_RESET);
    printf("-------------------------------\n");
    for (size_t i = 0; i < *total_funcionarios_out; i++) {
        printf("%-10d  %s\n", funcionarios_out[i].matricula, funcionarios_out[i].nome);
    }
    printf("-------------------------------\n");

    printf("\n");
    ui_prompt_voltar_menu_anterior(NULL);
}