#include "ui/relatorios/ui_relatorios.h"

/*------------- Fases de desenho da tela de relatórios por indústria ------------------*/

/**
 * Desenha a tela básica, inicialmente, com usuário logado, tela padrão,
 * cabeçalho e form para ler cnpj da indústria.
 */
void ui_desenhar_tela_rel_ind_fase_1(
    funcionario_t *f,
    industria_t *i)
{
    ui_exibir_to_do("Implementar desenho da tela de relatórios por indústria fase 1");
}

/**
 * Redesenha a tela de relatórios por indústria,
 * exibindo o resumo da indústria
 * e opções de relatórios disponíveis.
 */
void ui_desenhar_tela_rel_ind_fase_2(
    funcionario_t *f,
    industria_t *i,
    int *opcao_menu)
{
    ui_exibir_to_do("Implementar desenho da tela de relatórios por indústria fase 2");
}

/**
 * Redesenha a tela de relatórios por indústria,
 * exibindo o resumo da indústria, o relatório solicitado
 * e o menu de opções de exportação do relatório e retorno ao menu principal.
 */
void ui_desenhar_tela_rel_ind_fase_3(
    funcionario_t *f,
    industria_t *i,
    relatorio_t *relatorio,
    const char *cabecalho)
{
    ui_exibir_to_do("Implementar desenho da tela de relatórios por indústria fase 3");
}

/*----------------- Fases de desenho da tela de relatórios globais ------------------*/
/**
 * Desenha a tela básica, inicialmente, com usuário logado, tela padrão,
 * cabeçalho e opções de relatórios globais.
 */
void ui_desenhar_tela_rel_glb_fase_1(
    funcionario_t *f,
    int *opcao_menu)
{
    ui_exibir_to_do("Implementar desenho da tela de relatórios globais fase 1");
}

/**
 * Redesenha a tela de relatórios globais, exibindo o menu de opções
 * e o relatório solicitado.
 */
void ui_desenhar_tela_rel_glb_fase_2(
    funcionario_t *f,
    relatorio_t *relatorio,
    const char *cabecalho)
{
    ui_exibir_to_do("Implementar desenho da tela de relatórios globais fase 2");
}

/**
 * Redesenha a tela de relatórios globais, o relatório solicitado,
 * e menu de opções de exportação do relatório
 * e retorno ao menu principal.
 */
void ui_desenhar_tela_rel_glb_fase_3(
    funcionario_t *f,
    relatorio_t *relatorio,
    const char *cabecalho,
    int *opcao_menu)
{
    ui_exibir_to_do("Implementar desenho da tela de relatórios globais fase 3");
}
