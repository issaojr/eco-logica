#include "estados/funcionarios/estado_listar_funcionarios.h"

/* funções internas do estado */
static int inicializar(void)
{
    return 0; 
}

static estado_aplicacao processar(size_t entrada)
{
    funcionario_t *funcionario_autenticado = get_funcionario_logado();

    if (!funcionario_autenticado)
    {
        ui_exibir_erro("Nenhum funcionário logado. \nRedirecionando para a tela inicial...");
        ui_prompt_voltar_inicio("Pressione ENTER para continuar...");
        return ESTADO_MENU_LOGIN;
    }

    relatorio_t *r = malloc(sizeof(relatorio_t));
    if (!r)
    {
        ui_exibir_erro("Erro ao alocar memória para o relatório.");
        ui_prompt_voltar_inicio("Pressione ENTER para continuar...");
        return ESTADO_CADASTRO_FUNCIONARIOS;
    }
    memset(r, 0, sizeof(relatorio_t));

    bool sucesso = gerar_relatorio_lista_funcionarios(r);
    if (!sucesso)
    {
        ui_exibir_erro("Erro ao gerar relatório de funcionários.");
        free(r);
        ui_prompt_voltar_inicio("Pressione ENTER para continuar...");
        return ESTADO_CADASTRO_FUNCIONARIOS;
    }

    ui_desenhar_tela_padrao(
        UI_TITULO_PROGRAMA,
        UI_SUBTITULO_CADASTRO_INDUSTRIAS,
        funcionario_autenticado->nome,
        funcionario_autenticado->matricula);

    ui_desenhar_lista_funcionarios(r);

    free(r);

    return ESTADO_CADASTRO_FUNCIONARIOS;
}

static void finalizar(void)
{
}

static estado_aplicacao obter_id(void)
{
    return ESTADO_LISTAR_FUNCIONARIOS;
}

estado_t *criar_estado_listar_funcionarios(void)
{
    estado_t *estado = malloc(sizeof(estado_t));
    if (!estado)
        return NULL;

    estado->inicializar = inicializar;
    estado->processar = processar;
    estado->finalizar = finalizar;
    estado->obter_id = obter_id;
    return estado;
}
