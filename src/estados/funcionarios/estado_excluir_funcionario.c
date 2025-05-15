#include "estados/funcionarios/estado_excluir_funcionario.h"

funcionario_t *funcionario_autenticado;

/* fun��es internas do estado */
static int inicializar(void) {
    funcionario_autenticado = get_funcionario_logado();

    return 0; // sucesso
}

static estado_aplicacao processar(size_t entrada) {
    if (!funcionario_autenticado) {
        // [TODO] Criar estado de erro se n�o houver funcion�rio logado
        ui_exibir_erro("Nenhum funcion�rio logado. \nRedirecionando para a tela inicial..."); // [debug]
        ui_prompt_voltar_inicio("Pressione ENTER para continuar..."); // [debug]
        return ESTADO_MENU_LOGIN; // Redireciona para o login se n�o houver funcion�rio logado
    } 
    
    ui_desenhar_tela_cadastro_funcionarios(
        funcionario_autenticado->nome,
        funcionario_autenticado->matricula
    );

    /* Alocar mem�ria para o funcion�rio selecionado */
    funcionario_t *funcionario_selecionado = malloc(sizeof(funcionario_t));

    if (!funcionario_selecionado) {
        /* [TODO] Criar tela de erro para aloca��o de mem�ria */
        ui_exibir_erro("Erro ao alocar mem�ria para funcion�rio.");
        return ESTADO_CADASTRO_FUNCIONARIOS;
    }

    /* Desenhar tela de busca para excluir funcion�rio */
    ui_desenhar_tela_excluir_buscar_funcionario(funcionario_selecionado);

    /* Busca o funcion�rio pelo n�mero de matr�cula */
    int resultado = buscar_funcionario_por_matricula(funcionario_selecionado->matricula, funcionario_selecionado);
    printf("\n");

    /* Verifica se o funcion�rio est� logado, e, caso esteja, 
        n�o permitir a exclus�o */
    if (funcionario_autenticado->matricula == funcionario_selecionado->matricula) {
        ui_desenhar_tela_erro("ERRO: EXCLUIR FUNCIONARIO","Funcion�rio logado n�o pode ser exclu�do.");
        free(funcionario_selecionado);
        return ESTADO_CADASTRO_FUNCIONARIOS;
    }

    /* Caso o funcion�rio n�o seja encontrado, mostrar tela de erro 
        e voltar ao menu anterior */
    if (resultado == 1) {
        ui_desenhar_tela_erro("ERRO: EXCLUIR FUNCIONARIO","Funcion�rio n�o encontrado.");
        free(funcionario_selecionado);
        return ESTADO_CADASTRO_FUNCIONARIOS;
    } 
    else if (resultado == 2) {
        ui_desenhar_tela_erro("ERRO: EXCLUIR FUNCIONARIO","Erro ao buscar funcion�rio.");
        free(funcionario_selecionado);
        return ESTADO_CADASTRO_FUNCIONARIOS;
    } 

    bool confirmar_exclusao = ui_desenhar_tela_excluir_confirmar_funcionario(
        funcionario_selecionado,
        funcionario_autenticado->nome,
        funcionario_autenticado->matricula
    );  
    
    if (confirmar_exclusao) {
        // Chama a fun��o de exclus�o do funcion�rio
        int resultado_exclusao = excluir_funcionario(funcionario_selecionado->matricula);

        if (resultado_exclusao == 0) {
            ui_desenhar_tela_sucesso("SUCESSO: EXCLUIR FUNCIONARIO","Funcion�rio exclu�do com sucesso.");
        } else {
            ui_desenhar_tela_erro("ERRO: EXCLUIR FUNCIONARIO","Erro ao excluir funcion�rio.");
        }
    } else {
        ui_desenhar_tela_erro("CANCELADO: EXCLUIR FUNCIONARIO","Exclus�o cancelada pelo usu�rio.");
    }
    
    return ESTADO_CADASTRO_FUNCIONARIOS; 
}

static void finalizar(void) {
    // TODO: liberar recursos alocados (se houver)
}

static estado_aplicacao obter_id(void) {
    return ESTADO_EXCLUIR_FUNCIONARIO;  
}

estado_t* criar_estado_excluir_funcionario(void) {
    estado_t *estado = malloc(sizeof(estado_t));
    if (!estado) return NULL;

    estado->inicializar = inicializar;
    estado->processar   = processar;
    estado->finalizar   = finalizar;
    estado->obter_id    = obter_id;
    return estado;
}