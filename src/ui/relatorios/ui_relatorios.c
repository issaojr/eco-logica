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
    ui_desenhar_cabecalho("SELECIONE A INDÚSTRIA");

    ui_ler_cnpj_industria(i->cnpj, sizeof(i->cnpj));
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
    ui_desenhar_painel_ind_resumido(i);

    ui_desenhar_cabecalho("MENU DE RELATÓRIOS POR INDÚSTRIA");
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
    ui_desenhar_painel_ind_resumido(i);
    ui_desenhar_cabecalho(cabecalho);
    printf("\n");
    if (relatorio)
    {
        ui_exibir_relatorio(relatorio);
    }
    else
    {
        ui_exibir_erro("Nenhum relatório disponível.");
    }
    printf("\n");
    ui_exibir_separador('-', UI_LARGURA_PADRAO);
    printf("\n");
}

/*------------------ Menu da tela de relatórios por indústria -----------------------*/

const opcao_t tela_menu_relatorios_industria_mapa[] = {
    {1, "Listar resíduos por semestre"},
    {2, "Listar totais de gastos mensais"},
    {3, "Voltar ao menu principal"}};

const size_t tela_menu_relatorios_industria_mapa_n =
    sizeof(tela_menu_relatorios_industria_mapa) / sizeof(tela_menu_relatorios_industria_mapa[0]);

const char *tela_menu_relatorios_industria_prompt(void)
{
    return ui_prompt_opcao(1, tela_menu_relatorios_industria_mapa_n);
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

/*--------------------- Menu da tela de relatórios globais --------------------------*/

const opcao_t tela_menu_relatorios_globais_mapa[] = {
    {1, "Listar resíduos por semestre"},
    {2, "Listar totais de gastos mensais"},
    {3, "Voltar ao menu principal"}};

const size_t tela_menu_relatorios_globais_mapa_n =
    sizeof(tela_menu_relatorios_globais_mapa) / sizeof(tela_menu_relatorios_globais_mapa[0]);

const char *tela_menu_relatorios_globais_prompt(void)
{
    return ui_prompt_opcao(1, tela_menu_relatorios_globais_mapa_n);
}

/*----------------------- Menu de exportação de relatório ---------------------------*/

const opcao_t tela_menu_exportacao_relatorio_mapa[] = {
    {1, "Exportar para CSV"},
    {2, "Exportar para XLS"},
    {3, "Exportar para TXT"},
    {4, "Voltar ao menu principal"}};

const size_t tela_menu_exportacao_relatorio_mapa_n =
    sizeof(tela_menu_exportacao_relatorio_mapa) / sizeof(tela_menu_exportacao_relatorio_mapa[0]);
const char *tela_menu_exportacao_relatorio_prompt(void)
{
    return ui_prompt_opcao(1, tela_menu_exportacao_relatorio_mapa_n);
}

/*-------------------------- Exibição de de relatório -------------------------------*/

void ui_exibir_relatorio(
    relatorio_t *rel)
{
    if (!rel || !rel->dados || rel->linhas == 0 || rel->colunas == 0)
    {
        ui_exibir_erro("Relatório vazio ou inválido.");
        return;
    }

    for (size_t i = 0; i < rel->colunas; i++)
    {
        printf("%-20s", rel->cabecalhos[i]);
    }
    printf("\n");

    for (size_t i = 0; i < rel->linhas; i++)
    {
        for (size_t j = 0; j < rel->colunas; j++)
        {
            printf("%-20s", rel->dados[i][j]);
        }
        printf("\n");
    }
}
