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

/* mapa de op��es e prompt da tela de cadastro de funcion�rios */
extern const opcao_t tela_menu_cadastro_industrias_mapa[];
extern const size_t   tela_menu_cadastro_industrias_mapa_n;
extern const char    *tela_menu_cadastro_industrias_prompt;

/**
 * @brief Desenha a tela de cadastro de ind�strias.
 * @param nome_funcionario Nome do funcion�rio autenticado
 * @param matricula Matr�cula do funcion�rio autenticado
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
 * @brief Exibe a lista de ind�strias cadastradas.
 */
void ui_exibir_lista_industrias(
    industria_t* industrias_out, 
    size_t max_industrias, 
    size_t* total_industrias_out
);

/**
 * @brief Exibe o formul�rio para listar ind�strias.
 * @param industrias_out Array de ind�strias
 * @param max_industrias Tamanho m�ximo do array
 * @param total_industrias_out Ponteiro para o total de ind�strias
 */
//void ui_exibir_form_industria(industria_t *nova_industria_out);

/**
 * @brief Exibe o formul�rio para EXCLUIR uma ind�stria.
 */
void ui_exibir_form_excluir_industria(void);

/**
 * @brief Exibe o formul�rio para EDITAR uma ind�stria.
 */
void ui_exibir_form_editar_industria(void);

/**
 * @brief Exibe o formul�rio para ADICIONAR uma ind�stria.
 */
void ui_exibir_form_adicionar_industria(void);



#endif /* UI_TELA_MENU_CADASTRO_INDUSTRIAS_H */