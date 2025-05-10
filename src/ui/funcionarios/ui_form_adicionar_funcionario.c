#include <stdio.h>
#include <stdlib.h>
#include "ui/funcionarios/ui_form_adicionar_funcionario.h"
#include "ui/ui_comum.h"

void ui_exibir_form_adicionar_funcionario(void) {
    ui_limpar_tela();
    ui_exibir_titulo("Adicionar Novo Funcionário", NULL);
    ui_exibir_to_do("Exibir formulário de adição de funcionário aqui.");
    ui_prompt_voltar_menu_principal(NULL);
}