#include "estados/funcionarios/estado_cadastro_funcionarios.h"

funcionario_t *funcionario_autenticado;

static int inicializar(void)
{
    // Obter o funcionário logado
    funcionario_autenticado = get_funcionario_logado();

    return 0; // Sucesso
}

static estado_aplicacao processar(size_t entrada)
{
    if (!funcionario_autenticado)
    {
        // [TODO] Criar estado de erro se não houver funcionário logado
        ui_exibir_erro("Nenhum funcionário logado. \nRedirecionando para a tela inicial...");
        ui_prompt_voltar_inicio("Pressione ENTER para continuar...");
        return ESTADO_MENU_LOGIN;
    }

    // Desenhar tela de menu de cadastro de funcionários
    ui_desenhar_tela_cadastro_funcionarios(
        funcionario_autenticado->nome,
        funcionario_autenticado->matricula);

    /* Desenhar o menu de cadastro de funcionários (CRUD) */
    ui_desenhar_cabecalho("MENU DE CADASTRO DE FUNCIONÁRIOS");
    printf("\n");

    return estado_processar_estado_menu(
        ui_menu_cadastro_funcionarios_mapa,
        ui_menu_cadastro_funcionarios_mapa_n,
        ui_menu_cadastro_funcionarios_prompt,
        ESTADO_CADASTRO_FUNCIONARIOS);
}

static void finalizar(void)
{
    // Não há recursos específicos para liberar neste estado
}

static estado_aplicacao obter_id(void)
{
    return ESTADO_CADASTRO_FUNCIONARIOS;
}

estado_t *criar_estado_cadastro_funcionarios(void)
{
    estado_t *estado = malloc(sizeof(estado_t));

    if (!estado)
    {
        return NULL; // Falha ao alocar memória
    }

    estado->inicializar = inicializar;
    estado->processar = processar;
    estado->finalizar = finalizar;
    estado->obter_id = obter_id;

    return estado;
}
