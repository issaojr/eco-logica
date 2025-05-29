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
    printf("\n");
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
    ui_desenhar_cabecalho("MENU DE RELATÓRIOS GLOBAIS");
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

/*--------------------- Menu da tela de relatórios globais --------------------------*/

const opcao_t tela_menu_relatorios_globais_mapa[] = {
    {1, "Listar resíduos por semestre"},
    {2, "Listar totais de gastos mensais"},
    {3, "Listar aporte financeiro semestral"},
    {4, "Voltar ao menu principal"}};

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

void ui_exibir_relatorio(relatorio_t *rel)
{

    if (!rel || !rel->dados || rel->linhas == 0 || rel->colunas == 0)
    {
        ui_exibir_erro("Relatório vazio ou inválido.");
        return;
    }

    // Calcular larguras reais de cada coluna
    size_t *larguras = calloc(rel->colunas, sizeof(size_t));
    if (!larguras)
    {
        ui_exibir_erro("Erro de memória ao calcular larguras.");
        return;
    }

    for (size_t j = 0; j < rel->colunas; j++)
    {
        larguras[j] = ui_tamanho_str_utf8(rel->cabecalhos[j]);
        for (size_t i = 0; i < rel->linhas; i++)
        {
            size_t tam = ui_tamanho_str_utf8(rel->dados[i][j]);
            if (tam > larguras[j])
                larguras[j] = tam;
        }
    }

    // Exibir cabeçalhos
    for (size_t j = 0; j < rel->colunas; j++)
    {
        const char *str = rel->cabecalhos[j];
        size_t tam_real = ui_tamanho_str_utf8(str);
        size_t espacos = larguras[j] - tam_real;

        printf("%s", str);
        for (size_t k = 0; k < espacos + 2; k++) putchar(' ');
    }
    putchar('\n');

    // Linha separadora
    for (size_t j = 0; j < rel->colunas; j++)
    {
        for (size_t k = 0; k < larguras[j]; k++) putchar('-');
        printf("  ");
    }
    putchar('\n');

    // Exibir os dados
    for (size_t i = 0; i < rel->linhas; i++)
    {
        for (size_t j = 0; j < rel->colunas; j++)
        {
            const char *str = rel->dados[i][j];
            size_t tam_real = ui_tamanho_str_utf8(str);
            size_t espacos = larguras[j] - tam_real;

            printf("%s", str);
            for (size_t k = 0; k < espacos + 2; k++) putchar(' ');
        }
        putchar('\n');
    }

    free(larguras);
}
