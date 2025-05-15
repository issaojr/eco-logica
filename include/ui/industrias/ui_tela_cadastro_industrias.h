#ifndef UI_TELA_MENU_CADASTRO_INDUSTRIAS_H
#define UI_TELA_MENU_CADASTRO_INDUSTRIAS_H

#include <stdio.h>
#include <stdlib.h>
#include "ui/ui_comum.h"
#include "ui/ui_menu.h"
#include "ui/ui_form.h"
#include "ui/industrias/ui_form_industria.h"
#include "estruturas/industria.h"
#include "estruturas/funcionario.h"
#include "session.h"

/* mapa de opções e prompt da tela de cadastro de funcionários */
extern const opcao_t tela_menu_cadastro_industrias_mapa[];
extern const size_t   tela_menu_cadastro_industrias_mapa_n;
extern const char    *tela_menu_cadastro_industrias_prompt;

/**
 * @brief Desenha a tela de cadastro de indústrias.
 * @param nome_funcionario Nome do funcionário autenticado
 * @param matricula Matrícula do funcionário autenticado
 */
void ui_desenhar_tela_cadastro_industrias(
    const funcionario_t* funcionario_autenticado
);

void ui_desenhar_form_ler_cnpj_industria(
    industria_t *nova_industria_out    
);

void ui_desenhar_form_adicionar_industria(
    industria_t *nova_industria_out
);

/**
 * @brief Exibe a lista de indústrias cadastradas.
 */
void ui_exibir_lista_industrias(
    industria_t* industrias_out, 
    size_t max_industrias, 
    size_t* total_industrias_out
);

/**
 * @brief Exibe o formulário para listar indústrias.
 * @param industrias_out Array de indústrias
 * @param max_industrias Tamanho máximo do array
 * @param total_industrias_out Ponteiro para o total de indústrias
 */
//void ui_exibir_form_industria(industria_t *nova_industria_out);

/**
 * @brief Exibe o formulário para EXCLUIR uma indústria.
 */
void ui_exibir_form_excluir_industria(void);

/**
 * @brief Exibe o formulário para EDITAR uma indústria.
 */
void ui_exibir_form_editar_industria(void);

/**
 * @brief Exibe o formulário para ADICIONAR uma indústria.
 */
void ui_exibir_form_adicionar_industria(void);



#endif /* UI_TELA_MENU_CADASTRO_INDUSTRIAS_H */