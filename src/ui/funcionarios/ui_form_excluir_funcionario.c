#include <stdio.h>
#include <stdlib.h>
#include "ui/funcionarios/ui_form_excluir_funcionario.h"

void ui_exibir_form_excluir_funcionario(void) {
    ui_limpar_tela();
    ui_exibir_titulo("Excluir Funcionário Cadastrado", NULL);
    ui_exibir_to_do("Exibir formulário de exclusão de funcionário aqui.");
    ui_prompt_voltar_menu_principal(NULL);
}