#include <stdio.h>
#include <stdlib.h>
#include "ui/funcionarios/ui_lista_funcionarios.h"

void ui_exibir_lista_funcionarios(void) {
    ui_limpar_tela();
    ui_exibir_titulo("Exibir Funcionários Cadastrados", NULL);
    ui_exibir_to_do("Exibir Lista de Funcionários aqui.");
    ui_prompt_voltar_menu_principal(NULL);
}