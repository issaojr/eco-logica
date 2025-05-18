#include "estados/industrias/estado_listar_industrias.h"

/* funções internas do estado */
static int inicializar(void)
{
    return 0; // sucesso
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

    industria_t industrias[MAX_INDUSTRIAS];
    size_t total_industrias = 0;

    if (!obter_todas_industrias(industrias, MAX_INDUSTRIAS, &total_industrias) == 0)
    {
        ui_exibir_erro("Erro ao listar indústrias.");
        ui_prompt_voltar_inicio("Pressione ENTER para continuar...");
        return ESTADO_CADASTRO_INDUSTRIAS;
    }
    if (total_industrias == 0)
    {
        ui_exibir_erro("Nenhuma indústria cadastrada.");
        ui_prompt_voltar_inicio("Pressione ENTER para continuar...");
        return ESTADO_CADASTRO_INDUSTRIAS;
    }

    ui_desenhar_lista_industrias(
        industrias,
        MAX_INDUSTRIAS,
        &total_industrias);

    return ESTADO_CADASTRO_INDUSTRIAS;
}

static void finalizar(void)
{
}

static estado_aplicacao obter_id(void)
{
    return ESTADO_LISTAR_INDUSTRIAS;
}

estado_t *criar_estado_listar_industrias(void)
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