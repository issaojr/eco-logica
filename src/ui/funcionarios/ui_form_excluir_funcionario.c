#include <stdio.h>
#include <stdlib.h>
#include "ui/funcionarios/ui_form_excluir_funcionario.h"
#include "ui/ui_comum.h"

void ui_exibir_form_excluir_funcionario(void) {
    ui_limpar_tela();
    ui_exibir_titulo("Excluir Funcion�rio Cadastrado", NULL);
    ui_exibir_to_do("Exibir formul�rio de exclus�o de funcion�rio aqui.");
    ui_prompt_voltar_menu_principal(NULL);
}