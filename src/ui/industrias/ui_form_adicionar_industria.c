#include <stdio.h>
#include <stdlib.h>
#include "ui/industrias/ui_form_adicionar_industria.h"
#include "ui/ui_comum.h"

void ui_exibir_form_adicionar_industria(void) {
    ui_limpar_tela();
    ui_exibir_titulo("Adicionar Nova Ind�stria", NULL);
    ui_exibir_to_do("Exibir formul�rio de adi��o de ind�stria aqui.");
    ui_prompt_voltar_menu_principal(NULL);
}