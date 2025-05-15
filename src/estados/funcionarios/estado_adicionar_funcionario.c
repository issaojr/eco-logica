#include "estados/funcionarios/estado_adicionar_funcionario.h"

funcionario_t *funcionario_autenticado;

/* funções internas do estado */
static int inicializar(void) {
    funcionario_autenticado = get_funcionario_logado();

    return 0; // sucesso
}

static estado_aplicacao processar(size_t entrada) {
    if (!funcionario_autenticado) {
        // [TODO] Criar estado de erro se não houver funcionário logado
        ui_exibir_erro("Nenhum funcionário logado. \nRedirecionando para a tela inicial..."); // [debug]
        ui_prompt_voltar_inicio("Pressione ENTER para continuar..."); // [debug]
        return ESTADO_MENU_LOGIN; // Redireciona para o login se não houver funcionário logado
    }    
    
    ui_desenhar_tela_cadastro_funcionarios(
        funcionario_autenticado->nome,
        funcionario_autenticado->matricula
    );

    funcionario_t *novo_funcionario = malloc(sizeof(funcionario_t));

    // Exibe o formulário de adicionar funcionário
    ui_desenhar_form_adicionar_funcionario(novo_funcionario);
    
    int resultado = adicionar_funcionario(novo_funcionario);

    /* limpa a memória alocada */
    free(novo_funcionario);

    estado_t* novo_estado = criar_estado(ESTADO_MSG_CADASTRO_FUNCIONARIO);
    estado_aplicacao proximo = novo_estado->processar(resultado);

    return proximo; 
}

static void finalizar(void) {
    // TODO: liberar recursos alocados (se houver)
}

static estado_aplicacao obter_id(void) {
    return ESTADO_ADICIONAR_FUNCIONARIO;  
}

estado_t* criar_estado_adicionar_funcionario(void) {
    estado_t *estado = malloc(sizeof(estado_t));
    if (!estado) return NULL;

    estado->inicializar = inicializar;
    estado->processar   = processar;
    estado->finalizar   = finalizar;
    estado->obter_id    = obter_id;
    return estado;
}