#include "info_dialog_ui.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"
#include "strings_globais.h"

/**
 * Exibe uma mensagem informativa.
 * @param msg Mensagem a ser exibida. Deve possuir 48 caracteres, no máximo.
 */
void showInfoDialog(const char * msg) {
    clearConsole(); // Limpa o console antes de exibir a mensagem
    
    // cria uma cópia centralizada (48 cols)  
    char *aligned = centerMessageDefault(msg);

    if (!aligned) {
        // fallback: só imprime a msg original
        aligned = strdup(msg);
    }

    printf("+================================================+\n");
    printf("|%s|\n", aligned);
    printf("+================================================+\n\n");

    aligned = freeString(aligned); // Libera a memória alocada para a mensagem

    showPauseMessage(); // Pausa o console com a mensagem
}

/**
 * Centraliza uma mensagem em um espaço de 50 caracteres.
 * @param msg Mensagem a ser centralizada. Deve possuir 48 caracteres, no máximo.
 * @param len Comprimento da mensagem original.
 * @param totalLen Comprimento total do espaço disponível (50).
 */
void showErrorDialog(const char * msg) {
    clearConsole(); // Limpa o console antes de exibir a mensagem de erro

    // se vier NULL, usa a mensagem padrão
    const char *base = msg ? msg : "Desculpe! Ocorreu um Erro interno.";

    char *aligned = centerMessageDefault(base);
    if (!aligned) {
        aligned = strdup(base);
    }

    printf("+================================================+\n");
    printf("|%s|\n", aligned);
    printf("+================================================+\n\n");

    aligned = freeString(aligned);

    showPauseMessage();
}

void showPauseMessage(void) {

    // obtém buffer alocado já alinhado à direita
    char *aligned = rightAlignMessageDefault(MSG_ENTER_CONTINUAR);
    if (!aligned) {
        aligned = strdup(MSG_ENTER_CONTINUAR);
    }

    // exibe e aguarda ENTER
    pauseConsole(aligned);

    aligned = freeString(aligned);
}