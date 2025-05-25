#include "estados/industrias/estado_editar_industria.h"

#include "business/business_industria.h"

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
    ui_desenhar_tela_cadastro_industrias(
        funcionario_autenticado);

    industria_t *industria_antes = malloc(sizeof(industria_t));
    industria_t *industria_depois = malloc(sizeof(industria_t));

    /*
     * Apresenta primeiro form apenas para leitura de CNPJ
     * Somente prossegue para o form completo, caso a indústria já
     * exista no cadastro.
     */
    ui_desenhar_tela_editar_buscar_industria(industria_antes);

    const bool industria_existe = buscar_industria_por_cnpj(industria_antes->cnpj, industria_antes);

    printf("\n");

    /* Caso a indústria não seja encontrada, mostrar tela de erro e voltar ao menu anterior */
    if (!industria_existe)
    {
        ui_desenhar_tela_erro("ERRO AO EDITAR INDÚSTRIA",
                              "Indústria não encontrada.");
        free(industria_antes);
        free(industria_depois);
        return ESTADO_CADASTRO_FUNCIONARIOS;
    }

    /* Exibe nova tela base, agora com o restante do form - Fase 2 */
    ui_desenhar_form_editar_industria(funcionario_autenticado, industria_antes, industria_antes);

    /* Copia a matrícula do industria encontrada para a nova industria */
    strncpy(industria_depois->cnpj, industria_antes->cnpj,
            sizeof(industria_depois->cnpj) - 1);
    industria_depois->cnpj[sizeof(industria_depois->cnpj) - 1] = '\0';

    /* Exibe o form para editar indústria */
    ui_desenhar_form_editar_industria(
        funcionario_autenticado,
        industria_antes,
        industria_depois);

    /* Caso esteja tudo certo, substituir a antiga entrada pela nova */
    const int resultado = editar_industria(industria_depois);

    /* Limpa a memória alocada */
    free(industria_antes);
    free(industria_depois);

    if (resultado == 0)
    {
        // Edição bem-sucedida
        ui_desenhar_tela_sucesso("EDIÇÃO DE INDÚSTRIA BEM-SUCEDIDA", "Indústria editada com sucesso.");
    }
    else
    {
        // Erro ao editar
        ui_desenhar_tela_erro("EDIÇÃO DE INDÚSTRIA FALHOU", "Erro ao editar indústria.");
    }

    return ESTADO_CADASTRO_INDUSTRIAS;
}

static void finalizar(void)
{
    // TODO: liberar recursos alocados (se houver)
}

static estado_aplicacao obter_id(void)
{
    return ESTADO_EDITAR_INDUSTRIA;
}

estado_t *criar_estado_editar_industria(void)
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
