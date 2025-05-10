#include <stdio.h>
#include <stdlib.h>
#include "ui/industrias/ui_lista_industrias.h"
#include "ui/ui_comum.h"

void ui_exibir_lista_industrias(void) {
    ui_limpar_tela();
    ui_exibir_titulo("Lista de Indústrias", NULL);
    ui_exibir_to_do("Exibir lista de indústrias cadastradas aqui.");
    ui_prompt_voltar_menu_principal(NULL);
}