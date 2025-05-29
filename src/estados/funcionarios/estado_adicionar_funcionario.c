#include "estados/funcionarios/estado_adicionar_funcionario.h"

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

    ui_desenhar_tela_cadastro_funcionarios(
        funcionario_autenticado->nome,
        funcionario_autenticado->matricula);

    funcionario_t *novo_funcionario = malloc(sizeof(funcionario_t));
    if (!novo_funcionario)
    {
        ui_exibir_erro("Erro ao alocar memória para funcionário.");
        return ESTADO_CADASTRO_FUNCIONARIOS;
    }
    /* preenche a estrutura com valores padrão */
    memset(novo_funcionario, 0, sizeof(funcionario_t));

    /* Exibe o formulário de adicionar funcionário */
    ui_desenhar_tela_adicionar_funcionario(novo_funcionario);
    ui_desenhar_form_buscar_funcionario(novo_funcionario);

    /* Faz a busca pela matrícula, para garantir que não há funcionário
    anteriormente cadastrado */
    bool funcionario_encontrado = buscar_funcionario_por_matricula(
        novo_funcionario->matricula,
        novo_funcionario);
    
    if (funcionario_encontrado)
    {
        ui_desenhar_tela_erro("ERRO AO ADICIONAR FUNCIONÁRIO", "Funcionário já cadastrado.");
        free(novo_funcionario);
        return ESTADO_CADASTRO_FUNCIONARIOS;
    }

    /* Caso não seja encontrada a matrícula no cadastro, o form prossegue */
    ui_desenhar_form_adicionar_funcionario(novo_funcionario);
    
    int resultado = adicionar_funcionario(novo_funcionario);

    /* limpa a memória alocada */
    free(novo_funcionario);

    if (resultado == 0)
    {
        /* Cadastro bem-sucedido */
        ui_desenhar_tela_sucesso("CADASTRO DE FUNCIONÁRIO BEM-SUCEDIDO", "Funcionário cadastrado com sucesso.");
    }
    else
    {
        /* Erro ao cadastrar */
        ui_desenhar_tela_erro("CADASTRO DE FUNCIONÁRIO FALHOU", "Erro ao cadastrar funcionário.");
    }

    return ESTADO_CADASTRO_FUNCIONARIOS;
}

static void finalizar(void)
{
}

static estado_aplicacao obter_id(void)
{
    return ESTADO_ADICIONAR_FUNCIONARIO;
}

estado_t *criar_estado_adicionar_funcionario(void)
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
