#include <stdio.h>
#include <stdlib.h>
#include "ui/industrias/ui_form_editar_industria.h"

void ui_exibir_form_editar_industria(void) {
    ui_limpar_tela();
    ui_exibir_titulo("Editar Ind�stria", NULL);
    ui_exibir_to_do("Exibir formul�rio de edi��o de ind�stria aqui.");
    ui_prompt_voltar_menu_principal(NULL);
}