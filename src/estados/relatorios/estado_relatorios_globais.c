#include "estados/relatorios/estado_relatorios_globais.h"

static int fase = 0;
static funcionario_t *f_aut = NULL;
static relatorio_t *relatorio = NULL;
static codigo_opcao opcao_relatorio = OPCAO_INVALIDA;
static codigo_opcao opcao_exportacao = OPCAO_INVALIDA;

static int inicializar(void)
{
    if (fase == 0)
    {
        f_aut = get_funcionario_logado();
        if (!f_aut)
        {
            /* Exibir mensagem de erro se não houver funcionário logado */
            ui_exibir_erro("Nenhum funcionário logado. \nRedirecionando para a tela inicial...");
            ui_prompt_voltar_inicio("Pressione ENTER para continuar...");
            return ESTADO_MENU_LOGIN;
        }

        if (!relatorio)
        {
            relatorio = malloc(sizeof(relatorio_t));
            if (!relatorio)
            {
                ui_exibir_erro("Erro ao alocar memória para o relatório.");
                reset_estado_rel_globais();
                ui_prompt_voltar_menu_principal("Pressione ENTER para voltar ao menu principal...");
                return ESTADO_MENU_PRINCIPAL;
            }
            memset(relatorio, 0, sizeof(relatorio_t));
        }

        fase = 1;
    }
    return 0;
}

static estado_aplicacao estado_rel_globais_f1(void)
{
    const opcao_t *mapa = tela_menu_relatorios_globais_mapa;
    size_t mapa_n = tela_menu_relatorios_globais_mapa_n;
    const char *prompt = tela_menu_relatorios_globais_prompt();

    /* Desenhar a tela de relatórios globais e ler a opção escolhida, fase 1 */
    ui_desenhar_tela_rel_glb_fase_1(f_aut, NULL);
    printf("\n");

    /* Exibir o menu de opções de relatórios */
    ui_imprimir_menu(mapa, mapa_n);

    /* Exibir o menu de opções de relatórios e Ler a opção escolhida pelo usuário */
    opcao_relatorio = ui_ler_opcao(mapa, mapa_n, prompt);

    if (opcao_relatorio == 4)
    {
        reset_estado_rel_globais();
        return ESTADO_MENU_PRINCIPAL;
    }

    fase = 2; /* Avançar para a próxima fase */
    return ESTADO_RELATORIOS_GLOBAIS;
}

static estado_aplicacao estado_rel_globais_f2(void)
{
    /* Gerar relatório com base na opção escolhida, fase 2 */
    char *cabecalho = NULL;
    bool sucesso = false;
    char nome_arquivo[256] = {0};
    char *diretorio = "relatorios_gerados/";

    const opcao_t *mapa = tela_menu_exportacao_relatorio_mapa;
    size_t mapa_n = tela_menu_exportacao_relatorio_mapa_n;
    const char *prompt = tela_menu_exportacao_relatorio_prompt();

    if (opcao_relatorio == 1)
    {
        /* Regiões com maior geração de resíduos */
        sucesso = gerar_relatorio_residuos_por_regiao(relatorio);
        cabecalho = "REGIÕES COM MAIOR GERAÇÃO DE RESÍDUOS";
        snprintf(nome_arquivo, sizeof(nome_arquivo), "%sregioes_maior_geracao_residuos", diretorio);
    }
    else if (opcao_relatorio == 2)
    {
        /* Indústrias com melhor desempenho ambiental */
        sucesso = gerar_relatorio_industrias_melhor_desempenho(relatorio);
        cabecalho = "INDÚSTRIAS COM MELHOR DESEMPENHO AMBIENTAL";
        snprintf(nome_arquivo, sizeof(nome_arquivo), "%sindustrias_melhor_desempenho", diretorio);
    }
    else if (opcao_relatorio == 3)
    {
        /* Aporte financeiro semestral */
        sucesso = gerar_relatorio_aporte_financeiro_semestral(relatorio);
        cabecalho = "APORTE FINANCEIRO SEMESTRAL";
        snprintf(nome_arquivo, sizeof(nome_arquivo), "%saporte_financeiro_semestral", diretorio);
    }
    else
    {
        ui_exibir_erro("Opção inválida. Tente novamente.");
        ui_pausar(NULL);
        reset_estado_rel_globais();
        return ESTADO_MENU_PRINCIPAL;
    }

    if (!sucesso)
    {
        ui_desenhar_tela_erro("Erro ao gerar relatório",
                              "Não foi possível gerar o relatório solicitado.");
        reset_estado_rel_globais();
        return ESTADO_MENU_PRINCIPAL;
    }

    /* Exibir opções de relatórios globais, fase 2 */
    ui_desenhar_tela_rel_glb_fase_2(f_aut, relatorio, cabecalho);

    if (!relatorio || !relatorio->dados || relatorio->linhas == 0 || relatorio->colunas == 0)
    {
        ui_exibir_erro("Relatório vazio ou inválido.");
        ui_pausar(NULL);
        reset_estado_rel_globais();
        return ESTADO_MENU_PRINCIPAL;
    }

    /* Exibir opções de exportação do relatório */
    ui_imprimir_menu(mapa, mapa_n);
    /* Ler a opção de exportação escolhida pelo usuário */
    opcao_exportacao = ui_ler_opcao(mapa, mapa_n, prompt);

    if (opcao_exportacao == 4) /* Voltar ao menu principal */
    {
        reset_estado_rel_globais();
        return ESTADO_MENU_PRINCIPAL;
    }

    bool sucesso_exportacao = false;
    char *extensao = NULL;
    char *separador = ",";

    /* Exportar o relatório de acordo com a opção escolhida */
    switch ((int)opcao_exportacao)
    {
    case 1: /* Exportar para CSV */
        extensao = "csv";
        break;
    case 2: /* Exportar para XLS */
        extensao = "xls";
        break;
    case 3: /* Exportar para TXT */
        extensao = "txt";
        separador = "\t"; /* Usar tabulação como separador para TXT */
        break;
    default:
        break;
    }

    sucesso_exportacao = relatorio_exportar(relatorio, nome_arquivo, extensao, separador);

    if (sucesso_exportacao)
    {
        ui_desenhar_tela_sucesso(
            "Exportação de Relatório",
            "Relatório exportado com sucesso!");
    }
    else
    {
        ui_desenhar_tela_erro(
            "Erro na Exportação",
            "Não foi possível exportar o relatório. Verifique os detalhes e tente novamente.");
    }

    reset_estado_rel_globais();

    return ESTADO_MENU_PRINCIPAL;
}

static estado_aplicacao processar(size_t entrada)
{
    if (!f_aut)
    {
        /* Exibir mensagem de erro se não houver funcionário logado */
        ui_exibir_erro("Nenhum funcionário logado. \nRedirecionando para a tela inicial...");
        ui_prompt_voltar_inicio("Pressione ENTER para continuar...");
        reset_estado_rel_globais();
        return ESTADO_MENU_LOGIN;
    }

    if (!relatorio)
    {
        ui_exibir_erro("Erro ao alocar memória para o relatório.");
        reset_estado_rel_globais();
        ui_prompt_voltar_menu_principal("Pressione ENTER para voltar ao menu principal...");
        return ESTADO_MENU_PRINCIPAL;
    }

    ui_desenhar_tela_padrao(
        UI_TITULO_PROGRAMA,
        UI_SUBTITULO_RELATORIOS_INDUSTRIA,
        f_aut->nome,
        f_aut->matricula);

    /* Processar as fases de acordo com o estado atual */
    switch (fase)
    {
    case 1:
        return estado_rel_globais_f1();
    case 2:
        return estado_rel_globais_f2();
    default:
        ui_exibir_erro("Estado inválido. Retornando ao menu principal.");
        reset_estado_rel_globais();
        return ESTADO_MENU_PRINCIPAL;
    }
}

static void finalizar(void)
{
    // TODO: liberar recursos (se houver)
}

static estado_aplicacao obter_id(void)
{
    return ESTADO_RELATORIOS_GLOBAIS;
}

estado_t *criar_estado_relatorios_globais(void)
{
    estado_t *e = malloc(sizeof(estado_t));
    if (!e)
        return NULL;
    e->inicializar = inicializar;
    e->processar = processar;
    e->finalizar = finalizar;
    e->obter_id = obter_id;
    return e;
}

void reset_estado_rel_globais(void)
{
    fase = 0;
    opcao_relatorio = OPCAO_INVALIDA;
    opcao_exportacao = OPCAO_INVALIDA;

    if (relatorio)
    {
        relatorio_liberar(relatorio);
        free(relatorio);
        relatorio = NULL;
    }
}