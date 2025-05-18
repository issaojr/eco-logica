
#include "estados/industrias/estado_adicionar_industria.h"

/* funções internas do estado */
int inicializar(void)
{
    return 0; // sucesso
}

estado_aplicacao processar(size_t entrada)
{
    // Obter o funcionário logado
    funcionario_t *funcionario_autenticado = get_funcionario_logado();

    if (!funcionario_autenticado)
    {
        // [TODO] Criar estado de erro se não houver funcionário logado
        ui_exibir_erro("Nenhum funcionário logado. \nRedirecionando para a tela inicial..."); 
        ui_prompt_voltar_inicio("Pressione ENTER para continuar...");                         
        return ESTADO_MENU_LOGIN;                                                             
    }

    ui_desenhar_tela_cadastro_industrias(
        funcionario_autenticado);

    industria_t *nova_industria = malloc(sizeof(industria_t));

    if (!nova_industria)
    {
        // [TODO] Criar estado de erro se não houver memória disponúvel
        ui_exibir_erro("Erro ao alocar memória para nova indústria.");
        ui_prompt_voltar_inicio("Pressione ENTER para continuar...");
        return ESTADO_CADASTRO_INDUSTRIAS; // Retorna ao estado de cadastro de indústrias
    }

    // Exibe o formulário de adicionar indústria
    ui_desenhar_form_adicionar_industria(nova_industria);

    /*
     * Regra de negócio:
     * Adicionar nova indústria
     */
    int resultado = adicionar_industria(nova_industria);

    free(nova_industria);

    if (resultado != 0)
    {
        // [TODO] Criar tela ui de erro se a adição falhar
        ui_exibir_erro("Erro ao adicionar nova indústria.");
        ui_prompt_voltar_inicio("Pressione ENTER para continuar...");
        return ESTADO_CADASTRO_INDUSTRIAS; // Retorna ao estado de cadastro de indústrias
    }
    else
    {
        // [TODO] Criar tela ui de sucesso se a adição for bem-sucedida
        ui_exibir_sucesso("Indústria adicionada com sucesso.");
        ui_prompt_voltar_inicio("Pressione ENTER para continuar...");
    }
    return ESTADO_CADASTRO_INDUSTRIAS;
}

void finalizar(void)
{
    // TODO: liberar recursos alocados (se houver)
}

estado_aplicacao obter_id(void)
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