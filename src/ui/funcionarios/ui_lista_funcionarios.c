#include <stdio.h>
#include <stdlib.h>
#include "ui/funcionarios/ui_lista_funcionarios.h"

void ui_desenhar_tela_lista_funcionarios(void) {
    
    const char *titulo = "EcoL�gica Solu��es Ambientais";
    const char *subtitulo = "Sistema de Gest�o Ambiental";
    const char *cabecalho = "LISTA DE FUNCION�RIOS";
    
    /* Desenha tela de lista de funcion�rios */
    ui_desenhar_tela_relatorio_padrao(
        titulo, 
        subtitulo, 
        cabecalho
    );

    printf("\n");
}

/**
 * @brief Exibe a lista de funcion�rios
 * @param funcionarios_out Array de funcion�rios
 * @param max_funcionarios Tamanho m�ximo do array
 * @param total_funcionarios_out Ponteiro para o total de funcion�rios
 * @note A fun��o exibe a lista de funcion�rios formatada no console.
 */
void ui_exibir_lista_funcionarios(
    funcionario_t* funcionarios_out, 
    size_t max_funcionarios, 
    size_t* total_funcionarios_out) {
     

    printf(UI_COR_NEGRITO "Matr�cula   Nome\n" UI_COR_RESET);
    printf("-------------------------------\n");
    for (size_t i = 0; i < *total_funcionarios_out; i++) {
        printf("%-10d  %s\n", funcionarios_out[i].matricula, funcionarios_out[i].nome);
    }
    printf("-------------------------------\n");

    printf("\n");
    ui_prompt_voltar_menu_anterior(NULL);
}