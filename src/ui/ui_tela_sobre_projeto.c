#include <stdio.h>
#include <stdlib.h>
#include "ui/ui_tela_sobre_projeto.h"

void ui_exibir_sobre_projeto(void) {
    ui_limpar_tela();
    ui_exibir_titulo("Sobre o Projeto", NULL);
    ui_exibir_info("EcoLógica Soluções Ambientais - versão acadêmica");
    ui_exibir_info("Autor: Issao Hanaoka Junior");
    ui_exibir_info("UNIP - Universidade Paulista");
    ui_exibir_info("PIM IV - Projeto Integrado Multidisciplinar");
    ui_exibir_info("2025 - 1o Semestre");
}
