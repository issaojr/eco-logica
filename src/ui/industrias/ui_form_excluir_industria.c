#include <stdio.h>
#include <stdlib.h>
#include "ui/industrias/ui_form_excluir_industria.h"

void ui_exibir_form_excluir_industria(void) {
    ui_limpar_tela();
    ui_exibir_titulo("Excluir Ind�stria", NULL);
    ui_exibir_to_do("Exibir formul�rio de exclus�o de ind�stria aqui.");
    ui_prompt_voltar_menu_principal(NULL);
}