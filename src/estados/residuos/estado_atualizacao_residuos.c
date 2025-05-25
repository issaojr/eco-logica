#include "estados/residuos/estado_atualizacao_residuos.h"

static int inicializar(void)
{
    return 0;
}

static estado_aplicacao processar(size_t entrada)
{
    funcionario_t *funcionario_autenticado = get_funcionario_logado();
    if (!funcionario_autenticado)
    {
        // [TODO] Criar estado de erro se não houver funcionário logado
        ui_exibir_erro("Nenhum funcionário logado. \nRedirecionando para a tela inicial...");
        ui_prompt_voltar_inicio("Pressione ENTER para continuar...");
        return ESTADO_MENU_LOGIN;
    }

    /* Tela base para atualização de resíduos */

    /* Alocar memória para resíduos */

    /**
     * TODO: UI para leitura do dado: 
     * - CNPJ da indústria
     */

    /**
     * TODO: Chamar função da camada business para buscar indústria, por CNPJ
     */

    /**
     * TODO: UI para prosseguimento. 
     * - Caso a indústria não seja encontrada, exibir mensagem de erro e 
     * voltar ao menu anterior
     * - Caso a indústria seja encontrada, recarregar a tela para mostrar o painel
     * resumido da indústria selecionada e o formulário para atualização de resíduos
     * Campos do formulário:
     * - Mês da atualização (int)
     * - Ano da atualização (int)
     * - Quantidade de resíduos (double)
     * - Custos (double)
     */

    /**
     * TODO: Chamar função da camada business para atualizar resíduos
     */

    /**
     * TODO: UI para exibir mensagem de sucesso ou erro
     */

    /**
     * TODO: Desalocar memória alocada para resíduos e indústria e voltar 
     * ao menu principal
     */

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
