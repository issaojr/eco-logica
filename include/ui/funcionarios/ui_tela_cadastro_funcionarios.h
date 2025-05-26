#ifndef UI_TELA_CADASTRO_FUNCIONARIOS_H
#define UI_TELA_CADASTRO_FUNCIONARIOS_H

#include "estruturas/funcionario.h"
#include "ui/ui_menu.h"
#include "ui/ui_comum.h"
#include "ui/ui_form.h"
#include "business/business_crypto.h"
#include "persistencia/funcionario_dao.h"

/* mapa de opções e prompt da tela de cadastro de funcionários */
extern opcao_t ui_menu_cadastro_funcionarios_mapa[];
extern size_t ui_menu_cadastro_funcionarios_mapa_n;
extern const char *ui_menu_cadastro_funcionarios_prompt(void);

void ui_desenhar_tela_cadastro_funcionarios(
    const char *nome_funcionario,
    const char *matricula);

void ui_desenhar_lista_funcionarios(
    funcionario_t *funcionarios_out,
    size_t max_funcionarios,
    size_t *total_funcionarios_out);

void ui_exibir_lista_funcionarios(
    funcionario_t *funcionarios_out,
    size_t max_funcionarios,
    size_t *total_funcionarios_out);

void ui_desenhar_tela_adicionar_funcionario(
    funcionario_t *novo_funcionario_out);

void ui_desenhar_form_buscar_funcionario(funcionario_t *novo_funcionario_out);

void ui_desenhar_form_adicionar_funcionario(
    funcionario_t *novo_funcionario_out);

void ui_desenhar_tela_excluir_buscar_funcionario(
    funcionario_t *funcionario_antes_out);
bool ui_desenhar_tela_excluir_confirmar_funcionario(
    funcionario_t *funcionario_selecionado,
    const char *nome_funcionario_autenticado,
    const char *matricula_funcionario_autenticado);
void ui_desenhar_tela_editar_buscar_funcionario(
    funcionario_t *funcionario_antes_out);
void ui_desenhar_form_editar_funcionario(
    const char *nome_funcionario_autenticado,
    const char *matricula_funcionario_autenticado,
    funcionario_t *funcionario_antes_out,
    funcionario_t *funcionario_depois_out);

void ui_desenhar_painel_funcionario_selecionado(funcionario_t *f);

void ui_exibir_form_funcionario(
    funcionario_t *novo_funcionario_out);

#endif /* UI_TELA_CADASTRO_FUNCIONARIOS_H */

