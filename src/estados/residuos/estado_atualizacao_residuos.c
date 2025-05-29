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

    ui_desenhar_tela_inicial_residuos(f, i);

    bool industria_encontrada = buscar_industria_por_cnpj(i->cnpj, i);

    if (!industria_encontrada)
    {
        ui_desenhar_tela_erro("ERRO AO ATUALIZAR RESÍDUOS", "Indústria não encontrada.");
        free(r);
        free(i);
        return ESTADO_MENU_PRINCIPAL;
    }

    strncpy(r->cnpj, i->cnpj, sizeof(r->cnpj) - 1);
    r->cnpj[sizeof(r->cnpj) - 1] = '\0';

    ui_desenhar_tela_final_residuos(f, i, r);

    bool residuos_atualizados = atualizar_residuo(r);

    if (residuos_atualizados)
    {
        ui_desenhar_tela_sucesso("SUCESSO", "Resíduos atualizados com sucesso!");
    }
    else
    {
        ui_desenhar_tela_erro("ERRO AO ATUALIZAR RESÍDUOS", "Falha ao atualizar os resíduos.");
    }

    free(r);
    free(i);

    return ESTADO_MENU_PRINCIPAL;
}

static void finalizar(void)
{
}

static estado_aplicacao obter_id(void)
{
    return ESTADO_ATUALIZACAO_RESIDUOS;
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
