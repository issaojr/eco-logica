#include <stdio.h>
#include <stdlib.h>
#include "ui/industrias/ui_form_adicionar_industria.h"

void ui_exibir_form_adicionar_industria(void) {
    ui_limpar_tela();
    ui_exibir_titulo("Adicionar Nova Indústria", NULL);
    ui_exibir_to_do("Exibir formulário de adição de indústria aqui.");
    ui_prompt_voltar_menu_principal(NULL);
}