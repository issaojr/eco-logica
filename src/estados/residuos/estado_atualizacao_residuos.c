#include "estados/residuos/estado_atualizacao_residuos.h"

static int inicializar(void)
{
    return 0;
}

static estado_aplicacao processar(size_t entrada)
{
    funcionario_t *f = get_funcionario_logado();
    if (!f)
    {
        // [TODO] Criar estado de erro se não houver funcionário logado
        ui_exibir_erro("Nenhum funcionário logado. \nRedirecionando para a tela inicial...");
        ui_prompt_voltar_inicio("Pressione ENTER para continuar...");
        return ESTADO_MENU_LOGIN;
    }

    /* Alocar memória para resíduos  */
    residuo_t *r = malloc(sizeof(residuo_t));
    industria_t *i = malloc(sizeof(industria_t));
    if (!r || !i)
    {
        ui_exibir_erro("Erro ao alocar memória para resíduos ou indústria.");
        ui_prompt_voltar_inicio("Pressione ENTER para continuar...");
        return ESTADO_MENU_PRINCIPAL;
    }
    memset(r, 0, sizeof(residuo_t));
    memset(i, 0, sizeof(industria_t));

    /**
     * TODO: UI inicial (Fase 1) para leitura do dado:
     * - CNPJ da indústria
     */
    ui_desenhar_tela_inicial_residuos(f, i);

    /**
     * TODO: Chamar função da camada business para buscar indústria, por CNPJ
     */
    bool industria_encontrada = buscar_industria_por_cnpj(i->cnpj, i);

    /**
     * TODO: UI para prosseguimento.
     * - Caso a indústria não seja encontrada, exibir mensagem de erro e
     * voltar ao menu anterior
     */
    if (!industria_encontrada)
    {
        ui_desenhar_tela_erro("ERRO AO ATUALIZAR RESÍDUOS", "Indústria não encontrada.");
        free(r);
        free(i);
        return ESTADO_MENU_PRINCIPAL;
    }

    /**
     * TODO: Copia CNPJ da indústria encontrada para a estrutura de resíduos
     * (para que seja possível associar os resíduos à indústria)
     */
    strncpy(r->cnpj, i->cnpj, sizeof(r->cnpj) - 1);
    r->cnpj[sizeof(r->cnpj) - 1] = '\0';

    /**
     * TODO: Caso a indústria seja encontrada, recarregar a tela para mostrar o painel
     * resumido da indústria selecionada e o formulário para atualização de resíduos
     * Campos do formulário:
     * - Mês da atualização (int)
     * - Ano da atualização (int)
     * - Quantidade de resíduos (double)
     * - Custos (double)
     */
    ui_desenhar_tela_final_residuos(f, i, r);

    /**
     * TODO: Chamar função da camada business para atualizar resíduos
     */
    bool residuos_atualizados = atualizar_residuo(r);

    /**
     * TODO: UI para exibir mensagem de sucesso ou erro
     */
    if (residuos_atualizados)
    {
        ui_desenhar_tela_sucesso("SUCESSO", "Resíduos atualizados com sucesso!");
    }
    else
    {
        ui_desenhar_tela_erro("ERRO AO ATUALIZAR RESÍDUOS", "Falha ao atualizar os resíduos.");
    }
    /**
     * TODO: Desalocar memória alocada para resíduos e indústria e voltar
     * ao menu principal
     */
    free(r);
    free(i);

    return ESTADO_MENU_PRINCIPAL;
}

static void finalizar(void)
{
    // TODO: liberar recursos (se houver)
}

static estado_aplicacao obter_id(void)
{
    return ESTADO_ATUALIZACAO_RESIDUOS; // adicione ao seu enum em estado.h
}

estado_t *criar_estado_atualizacao_residuos(void)
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
