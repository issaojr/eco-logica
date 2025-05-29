#include "estados/relatorios/estado_relatorios_industria.h"

static int fase = 0;
static funcionario_t *f_aut = NULL;
static industria_t *i = NULL;
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
            // Exibir mensagem de erro se não houver funcionário logado
            ui_exibir_erro("Nenhum funcionário logado. \nRedirecionando para a tela inicial...");
            ui_prompt_voltar_inicio("Pressione ENTER para continuar...");
            return ESTADO_MENU_LOGIN;
        }

        i = malloc(sizeof(industria_t));
        if (!i)
        {
            ui_exibir_erro("Erro ao alocar memória para a indústria.");
            ui_prompt_voltar_menu_principal("Pressione ENTER para voltar ao menu principal...");
            return ESTADO_MENU_PRINCIPAL;
        }
        memset(i, 0, sizeof(industria_t));

        if (!relatorio)
        {
            relatorio = malloc(sizeof(relatorio_t));
            if (!relatorio)
            {
                ui_exibir_erro("Erro ao alocar memória para o relatório.");
                reset_estado_rel_ind();
                ui_prompt_voltar_menu_principal("Pressione ENTER para voltar ao menu principal...");
                return ESTADO_MENU_PRINCIPAL;
            }
            memset(relatorio, 0, sizeof(relatorio_t));
        }

        fase = 1;
    }
    return 0;
}

static estado_aplicacao estado_rel_ind_f1(void)
{
    /* Desenhar a tela de relatórios por indústria e ler cnpj, fase 1 */
    ui_desenhar_tela_rel_ind_fase_1(f_aut, i);

    bool industria_encontrada = buscar_industria_por_cnpj(i->cnpj, i);
    if (!industria_encontrada)
    {
        // Exibir mensagem de erro se a indústria não for encontrada
        ui_exibir_erro("Indústria não encontrada. Verifique o CNPJ e tente novamente.");
        reset_estado_rel_ind();
        ui_prompt_voltar_menu_anterior("Pressione ENTER para voltar ao menu principal...");
        return ESTADO_MENU_PRINCIPAL;
    }
    fase = 2; /* Avançar para a próxima fase */

    return ESTADO_RELATORIOS_INDUSTRIA;
}

static estado_aplicacao estado_rel_ind_f2(void)
{
    const opcao_t *mapa = tela_menu_relatorios_industria_mapa;
    size_t mapa_n = tela_menu_relatorios_industria_mapa_n;
    const char *prompt = tela_menu_relatorios_industria_prompt();

    /* Exibir resumo da indústria e opções de relatórios, fase 2 */
    ui_desenhar_tela_rel_ind_fase_2(f_aut, i, NULL);

    /* Exibir o menu de opções de relatórios */
    ui_imprimir_menu(mapa, mapa_n);

    /* Ler opção escolhida pelo usuário */
    opcao_relatorio = ui_ler_opcao(mapa, mapa_n, prompt);

    if (opcao_relatorio == 3) /* Voltar ao menu principal */
    {
        reset_estado_rel_ind();
        return ESTADO_MENU_PRINCIPAL;
    }

    fase = 3; /* Avançar para a próxima fase */
    return ESTADO_RELATORIOS_INDUSTRIA;
}

static estado_aplicacao estado_rel_ind_f3(void)
{
    /* Gerar relatório com base na opção escolhida, fase 3 */
    char *cabecalho = NULL;
    bool sucesso = false;
    char nome_arquivo[256] = {0};
    char *diretorio = "relatorios_gerados/";

    const opcao_t *mapa = tela_menu_exportacao_relatorio_mapa;
    size_t mapa_n = tela_menu_exportacao_relatorio_mapa_n;
    const char *prompt = tela_menu_exportacao_relatorio_prompt();

    if (opcao_relatorio == 1)
    {
        sucesso = gerar_relatorio_residuos_semestral(i, relatorio);
        cabecalho = "RELATÓRIO DE RESÍDUOS POR SEMESTRE";
        snprintf(nome_arquivo, sizeof(nome_arquivo), "%s%s_relatorio_residuos_por_semestre", diretorio, i->cnpj);
    }
    else if (opcao_relatorio == 2)
    {
        sucesso = gerar_relatorio_gastos_mensais(i, relatorio);
        cabecalho = "RELATÓRIO DE TOTAIS DE GASTOS MENSAIS";
        snprintf(nome_arquivo, sizeof(nome_arquivo), "%s%s_relatorio_gastos_mensais", diretorio, i->cnpj);
    }
    else
    {
        ui_exibir_erro("Opção inválida. Tente novamente.");
        ui_pausar(NULL);
        reset_estado_rel_ind();
        return ESTADO_MENU_PRINCIPAL;
    }

    if (!sucesso)
    {
        ui_desenhar_tela_erro("Erro ao gerar relatório",
                              "Não foi possível gerar o relatório solicitado.");
        reset_estado_rel_ind();
        return ESTADO_MENU_PRINCIPAL;
    }

    ui_desenhar_tela_rel_ind_fase_3(
        f_aut,
        i,
        relatorio,
        cabecalho);

    if (!relatorio || !relatorio->dados || relatorio->linhas == 0 || relatorio->colunas == 0)
    {
        ui_exibir_erro("Relatório vazio ou inválido.");
        ui_pausar(NULL);
        reset_estado_rel_ind();
        return ESTADO_MENU_PRINCIPAL;
    }

    /* Exibir opções de exportação do relatório */
    ui_imprimir_menu(mapa, mapa_n);
    /* Ler a opção de exportação escolhida pelo usuário */
    opcao_exportacao = ui_ler_opcao(mapa, mapa_n, prompt);

    if (opcao_exportacao == 4) /* Voltar ao menu principal */
    {
        reset_estado_rel_ind();
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
            "Não foi possível exportar o relatório.");
    }

    reset_estado_rel_ind();

    return ESTADO_MENU_PRINCIPAL;
}

static estado_aplicacao processar(size_t entrada)
{
    if (!f_aut)
    {
        // Exibir mensagem de erro se não houver funcionário logado
        ui_exibir_erro("Nenhum funcionário logado. \nRedirecionando para a tela inicial...");
        ui_prompt_voltar_inicio("Pressione ENTER para continuar...");
        reset_estado_rel_ind();
        return ESTADO_MENU_LOGIN;
    }

    if (!i)
    {
        ui_exibir_erro("Erro ao alocar memória para a indústria.");
        reset_estado_rel_ind();
        ui_prompt_voltar_menu_principal("Pressione ENTER para voltar ao menu principal...");
        return ESTADO_MENU_PRINCIPAL;
    }

    if (!relatorio)
    {
        ui_exibir_erro("Erro ao alocar memória para o relatório.");
        reset_estado_rel_ind();
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
        return estado_rel_ind_f1();
    case 2:
        return estado_rel_ind_f2();
    case 3:
        return estado_rel_ind_f3();
    default:
        ui_exibir_erro("Estado inválido. Retornando ao menu principal.");
        reset_estado_rel_ind();
        return ESTADO_MENU_PRINCIPAL;
    }
}

static void finalizar(void)
{
    // TODO: liberar recursos (se houver)
}

static estado_aplicacao obter_id(void)
{
    return ESTADO_RELATORIOS_INDUSTRIA;
}

estado_t *criar_estado_relatorios_industria(void)
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

void reset_estado_rel_ind(void)
{
    if (i)
    {
        free(i);
        i = NULL;
    }

    if (relatorio)
    {
        relatorio_liberar(relatorio);
        free(relatorio);
        relatorio = NULL;
    }

    opcao_relatorio = OPCAO_INVALIDA;
    opcao_exportacao = OPCAO_INVALIDA;
    fase = 0;
}

