#include "estados/industrias/estado_excluir_industria.h"

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

    ui_desenhar_tela_cadastro_industrias(
        funcionario_autenticado);

    /* Alocar memória para a indústria selecionada */
    industria_t *industria_selecionada = malloc(sizeof(industria_t));

    if (!industria_selecionada)
    {
        ui_exibir_erro("Erro ao alocar memória para indústria.");
        return ESTADO_CADASTRO_INDUSTRIAS;
    }

    /* Desenhar tela de busca para excluir indústria */
    ui_desenhar_tela_excluir_buscar_industria(industria_selecionada);

    /* Busca a indústria pelo CNPJ */
    bool industria_encontrada = buscar_industria_por_cnpj(industria_selecionada->cnpj, industria_selecionada);
    printf("\n");

    /* Caso a indústria não seja encontrada, mostrar tela de erro
        e voltar ao menu anterior */
    if (!industria_encontrada)
    {
        ui_desenhar_tela_erro("ERRO AO EXCLUIR INDÚSTRIA", "Indústria não encontrada.");
        free(industria_selecionada);
        return ESTADO_CADASTRO_INDUSTRIAS;
    }

    bool confirmar_exclusao = ui_desenhar_tela_excluir_confirmar_industria(
        industria_selecionada,
        funcionario_autenticado);
        
    if (confirmar_exclusao)
    {
        int resultado = excluir_industria(industria_selecionada->cnpj);
        if (resultado == 0)
        {
            ui_desenhar_tela_sucesso("SUCESSO", "Indústria excluída com sucesso.");
        }
        else
        {
            ui_desenhar_tela_erro("ERRO AO EXCLUIR INDÚSTRIA", "Erro ao excluir a indústria.");
        }
    }
    else
    {
        ui_desenhar_tela_erro("EXCLUSÃO CANCELADA", "Operação cancelada pelo usuário.");
    }

    return ESTADO_CADASTRO_INDUSTRIAS;
}

static void finalizar(void)
{
}

static estado_aplicacao obter_id(void)
{
    return ESTADO_EXCLUIR_INDUSTRIA;
}

estado_t *criar_estado_excluir_industria(void)
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
