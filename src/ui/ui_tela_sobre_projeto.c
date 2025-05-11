#include <stdio.h>
#include <stdlib.h>
#include "ui/ui_tela_sobre_projeto.h"
#include "ui/ui_comum.h"

void ui_desenhar_tela_sobre_projeto(void) {

    ui_desenhar_tela_padrao(
        UI_TITULO_PROGRAMA, 
        UI_SUBTITULO_SOBRE, 
        NULL, 
        0
    );

    ui_desenhar_cabecalho("INFORMAÇÕES DO PROJETO");
    printf("\n");

    ui_exibir_sobre_projeto();
    printf("\n");

    ui_prompt_voltar_inicio(NULL);
}

void ui_exibir_sobre_projeto(void) {
    ui_exibir_info("EcoLógica Soluções Ambientais - versão acadêmica");
    ui_exibir_info("Autor: Issao Hanaoka Junior");
    ui_exibir_info("UNIP - Universidade Paulista");
    ui_exibir_info("PIM IV - Projeto Integrado Multidisciplinar");
    ui_exibir_info("2025 - 1o Semestre");
}
