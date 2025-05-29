#ifndef UI_RELATORIOS_H
#define UI_RELATORIOS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "ui/ui_comum.h"
#include "ui/ui_menu.h"
#include "ui/ui_form.h"
#include "ui/industrias/ui_tela_cadastro_industrias.h"
#include "estruturas/industria.h"
#include "estruturas/residuo.h"
#include "estruturas/relatorio.h"
#include "estruturas/funcionario.h"

/* mapa de opções e prompt da tela de relatórios por indústria */
extern const opcao_t tela_menu_relatorios_industria_mapa[];
extern const size_t tela_menu_relatorios_industria_mapa_n;
extern const char *tela_menu_relatorios_industria_prompt(void);
/* mapa de opções e prompt da tela de relatórios globais */
extern const opcao_t tela_menu_relatorios_globais_mapa[];
extern const size_t tela_menu_relatorios_globais_mapa_n;
extern const char *tela_menu_relatorios_globais_prompt(void);
/* mapa de opções de exportação de relatórios */
extern const opcao_t tela_menu_exportacao_relatorio_mapa[];
extern const size_t tela_menu_exportacao_relatorio_mapa_n;
extern const char *tela_menu_exportacao_relatorio_prompt(void);

/*------------- Fases de desenho da tela de relatórios por indústria ------------------*/

/**
 * Desenha a tela básica, inicialmente, com usuário logado, tela padrão,
 * cabeçalho e form para ler cnpj da indústria.
 */
void ui_desenhar_tela_rel_ind_fase_1(
    funcionario_t *f,
    industria_t *i);

/**
 * Redesenha a tela de relatórios por indústria,
 * exibindo o resumo da indústria
 * e opções de relatórios disponíveis.
 */
void ui_desenhar_tela_rel_ind_fase_2(
    funcionario_t *f,
    industria_t *i,
    int *opcao_menu);

/**
 * Redesenha a tela de relatórios por indústria,
 * exibindo o resumo da indústria, o relatório solicitado
 * e o menu de opções de exportação do relatório e retorno ao menu principal.
 */
void ui_desenhar_tela_rel_ind_fase_3(
    funcionario_t *f,
    industria_t *i,
    relatorio_t *relatorio,
    const char *cabecalho);

/*----------------- Fases de desenho da tela de relatórios globais ------------------*/

/**
 * Desenha a tela básica, inicialmente, com usuário logado, tela padrão,
 * cabeçalho e opções de relatórios globais.
 */
void ui_desenhar_tela_rel_glb_fase_1(
    funcionario_t *f,
    int *opcao_menu);

/**
 * Redesenha a tela de relatórios globais, exibindo o menu de opções
 * e o relatório solicitado.
 */
void ui_desenhar_tela_rel_glb_fase_2(
    funcionario_t *f,
    relatorio_t *relatorio,
    const char *cabecalho);

/**
 * Exibe o relatório formatado na tela.
 * @param rel Relatório a ser exibido
 */
void ui_exibir_relatorio(
    relatorio_t *rel);

#endif // UI_RELATORIOS_H