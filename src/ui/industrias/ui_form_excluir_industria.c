#include <stdio.h>
#include <stdlib.h>
#include "ui/industrias/ui_form_excluir_industria.h"
#include "ui/ui_comum.h"

void ui_exibir_form_excluir_industria(void) {
    ui_limpar_tela();
    ui_exibir_titulo("Excluir Indústria", NULL);
    ui_exibir_to_do("Exibir formulário de exclusão de indústria aqui.");
    ui_prompt_voltar_menu_principal(NULL);
}