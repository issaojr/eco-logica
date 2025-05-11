#ifndef UI_TELA_CADASTRO_FUNCIONARIOS_H
#define UI_TELA_CADASTRO_FUNCIONARIOS_H

#include "estruturas/funcionario.h"
#include "ui/ui_menu.h"
#include "ui/ui_comum.h"

/* mapa de op��es e prompt da tela de cadastro de funcion�rios */
extern opcao_t ui_menu_cadastro_funcionarios_mapa[];
extern size_t   ui_menu_cadastro_funcionarios_mapa_n;
extern char    *ui_menu_cadastro_funcionarios_prompt;


void ui_desenhar_tela_cadastro_funcionarios(
    const char *nome_funcionario, 
    const int matricula);

void ui_desenhar_lista_funcionarios(
    funcionario_t* funcionarios_out, 
    size_t max_funcionarios, 
    size_t* total_funcionarios_out
);

void ui_exibir_lista_funcionarios(
    funcionario_t* funcionarios_out, 
    size_t max_funcionarios, 
    size_t* total_funcionarios_out
);

void ui_desenhar_form_adicionar_funcionario(funcionario_t *novo_funcionario_out);
void ui_desenhar_form_editar_funcionario(void);
void ui_desenhar_form_excluir_funcionario(void);

void ui_exibir_form_funcionario(funcionario_t *novo_funcionario_out);
void ui_exibir_form_editar_funcionario(void);
void ui_exibir_form_excluir_funcionario(void);


#endif /* UI_TELA_CADASTRO_FUNCIONARIOS_H */