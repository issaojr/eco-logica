#include "estados/funcionarios/estado_editar_funcionario.h"

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

    /* Tela base - Fase 1 */
    ui_desenhar_tela_cadastro_funcionarios(
        funcionario_autenticado->nome,
        funcionario_autenticado->matricula);

    funcionario_t *funcionario_antes = malloc(sizeof(funcionario_t));
    funcionario_t *funcionario_depois = malloc(sizeof(funcionario_t));
    if (!funcionario_antes || !funcionario_depois)
    {
        ui_desenhar_tela_erro("ERRO AO EDITAR FUNCIONÁRIO", "Erro ao alocar memória.");
        free(funcionario_antes);
        free(funcionario_depois);
        return ESTADO_CADASTRO_FUNCIONARIOS;
    }
    memset(funcionario_antes, 0, sizeof(funcionario_t));
    memset(funcionario_depois, 0, sizeof(funcionario_t));

    /*
     * Apresenta primeiro form apenas para leitura de matrícula
     * Somente prossegue para o form completo, caso o funcionário já
     * exista no cadastro.
     */
    ui_desenhar_tela_editar_buscar_funcionario(funcionario_antes);

    // Busca o funcionário pelo número de matrícula
    bool funcionario_encontrado = buscar_funcionario_por_matricula(funcionario_antes->matricula, funcionario_antes);

    printf("\n");

    /* Caso o funcionário não seja encontrado, mostrar tela de erro
        e voltar ao menu anterior */
    if (!funcionario_encontrado)
    {
        ui_desenhar_tela_erro("ERRO AO EDITAR FUNCIONARIO",
                              "Funcionário não encontrado.");
        free(funcionario_antes);
        free(funcionario_depois);
        return ESTADO_CADASTRO_FUNCIONARIOS;
    }
    else
    {
        // Exibe o painel do funcionário encontrado
        ui_desenhar_painel_funcionario_selecionado(funcionario_antes);
    }

    /* Copia a matrícula do funcionário encontrado para o novo funcionário */
    strncpy(funcionario_depois->matricula, funcionario_antes->matricula,
            sizeof(funcionario_depois->matricula) - 1);
    funcionario_depois->matricula[sizeof(funcionario_depois->matricula) - 1] = '\0';

    // Exibe o formulário de editar funcionário
    ui_desenhar_form_editar_funcionario(
        funcionario_autenticado->nome,
        funcionario_autenticado->matricula,
        funcionario_antes,
        funcionario_depois);

    /* Caso esteja tudo certo, substituir a antiga entrada pela nova */
    const int resultado = editar_funcionario(funcionario_depois);

    /* Verifica se a edição foi bem-sucedida */
    if (resultado == 0)
    {
        // Edição bem-sucedida
        // caso a matrícula do funcionario atualizado seja a mesma do funcionario autenticado
        // atualiza a sessão
        if (strcmp(funcionario_autenticado->matricula, funcionario_depois->matricula) == 0)
        {
            /* Copias os novos dados, para atualizar adequadamente o funcionario autenticado na sessão */
            memcpy(funcionario_autenticado, funcionario_depois, sizeof(funcionario_t));
        }
        ui_desenhar_tela_sucesso("EDIÇÃO DE FUNCIONÁRIO BEM-SUCEDIDA", "Funcionário editado com sucesso.");
    }
    else
    {
        // Erro ao editar
        ui_desenhar_tela_erro("EDIÇÃO DE FUNCIONÁRIO FALHOU", "Erro ao editar funcionário.");
    }

    /* Limpa a memória alocada */
    free(funcionario_antes);
    free(funcionario_depois);

    return ESTADO_CADASTRO_FUNCIONARIOS;
}

static void finalizar(void)
{
    // TODO: liberar recursos alocados (se houver)
}

static estado_aplicacao obter_id(void)
{
    return ESTADO_EDITAR_FUNCIONARIO;
}

estado_t *criar_estado_editar_funcionario(void)
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
