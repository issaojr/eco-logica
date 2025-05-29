#include "estados/industrias/estado_adicionar_industria.h"

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

    industria_t *nova_industria = malloc(sizeof(industria_t));

    if (!nova_industria)
    {
        ui_exibir_erro("Erro ao alocar memória para nova indústria.");
        ui_prompt_voltar_inicio("Pressione ENTER para continuar...");
        return ESTADO_CADASTRO_INDUSTRIAS; 
    }

    
    ui_desenhar_form_adicionar_industria(nova_industria);

    /* Deve verificar se a indústria já existe no cadastro */
    bool industria_existe = buscar_industria_por_cnpj(nova_industria->cnpj, nova_industria);

    if (industria_existe)
    {
        free(nova_industria);
        ui_exibir_erro("Este CNPJ já está cadastrado.");
        ui_prompt_voltar_menu_anterior(NULL);
        return ESTADO_CADASTRO_INDUSTRIAS; 
    }

    /* Exibe restante do formulário, caso CNPJ não esteja cadastrado */
    ui_exibir_form_industria(nova_industria);

    /*
     * Regra de negócio:
     * Adicionar nova indústria
     */
    int resultado = adicionar_industria(nova_industria);

    free(nova_industria);

    if (resultado != 0)
    {
        ui_exibir_erro("Erro ao adicionar nova indústria.");
        ui_prompt_voltar_inicio("Pressione ENTER para continuar...");
        return ESTADO_CADASTRO_INDUSTRIAS; 
    }
    else
    {
        ui_exibir_sucesso("Indústria adicionada com sucesso.");
        ui_prompt_voltar_inicio("Pressione ENTER para continuar...");
    }
    return ESTADO_CADASTRO_INDUSTRIAS;
}

static void finalizar(void)
{
}

static estado_aplicacao obter_id(void)
{
    return ESTADO_ADICIONAR_INDUSTRIA;
}

estado_t *criar_estado_adicionar_industria(void)
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
