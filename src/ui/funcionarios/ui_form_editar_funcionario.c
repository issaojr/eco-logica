#include <stdio.h>
#include <stdlib.h>
#include "ui/funcionarios/ui_form_editar_funcionario.h"

void ui_exibir_form_editar_funcionario(void) {
    ui_limpar_tela();
    ui_exibir_titulo("Editar Funcion�rio Cadastrado", NULL);
    ui_exibir_to_do("Exibir formul�rio de EDI��O de funcion�rio aqui.");
    ui_prompt_voltar_menu_principal(NULL);
}