#include "ui/ui_tela_sair.h"

void ui_desenhar_tela_sair(void) {
    const char *titulo = UI_TITULO_PROGRAMA;
    const char *subtitulo = UI_SUBTITULO_PROGRAMA;

    ui_desenhar_tela_padrao(
        titulo, 
        subtitulo, 
        NULL, 
        0
    );

    ui_exibir_agradecimento();
    printf("\n");

    ui_prompt_sair(NULL);
}

void ui_exibir_agradecimento(void) {
    printf("Obrigado por usar o nosso sistema!\n");
}