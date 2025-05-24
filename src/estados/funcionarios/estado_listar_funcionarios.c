#include "estados/funcionarios/estado_listar_funcionarios.h"

/* funções internas do estado */
static int inicializar(void)
{
    return 0; // sucesso
}

static estado_aplicacao processar(size_t entrada)
{
    funcionario_t *funcionario_autenticado = get_funcionario_logado();
    // Verifica se o funcionário está logado
    if (!funcionario_autenticado)
    {
        // [TODO] Criar estado de erro se não houver funcionário logado
        ui_exibir_erro("Nenhum funcionário logado. \nRedirecionando para a tela inicial...");
        ui_prompt_voltar_inicio("Pressione ENTER para continuar...");
        return ESTADO_MENU_LOGIN;
    }

    funcionario_t funcionarios[MAX_FUNCIONARIOS];
    size_t total_funcionarios = 0;

    // Chamada para business para recuperar a lista de funcionários
    if (!obter_todos_funcionarios(funcionarios, MAX_FUNCIONARIOS, &total_funcionarios))
    {
        ui_exibir_debug("Erro ao obter todos os funcionários.");
        ui_exibir_erro("Erro ao listar funcionários.");
        ui_prompt_voltar_inicio("Pressione ENTER para continuar...");
        return ESTADO_CADASTRO_FUNCIONARIOS;
    }

    if (total_funcionarios == 0)
    {
        ui_exibir_erro("Nenhum funcionário cadastrado.");
        ui_prompt_voltar_inicio("Pressione ENTER para continuar...");
        return ESTADO_CADASTRO_FUNCIONARIOS;
    }

    ui_desenhar_lista_funcionarios(
        funcionarios,
        MAX_FUNCIONARIOS,
        &total_funcionarios);

    return ESTADO_CADASTRO_FUNCIONARIOS;
}

static void finalizar(void)
{
    // TODO: liberar recursos alocados (se houver)
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
