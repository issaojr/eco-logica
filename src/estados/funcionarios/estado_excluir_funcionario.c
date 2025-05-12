#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estados/funcionarios/estado_excluir_funcionario.h"
#include "ui/funcionarios/ui_tela_cadastro_funcionarios.h"
#include "ui/ui_formulario.h"
#include "ui/ui_comum.h"
#include "business/business_funcionario.h"
#include "session.h"

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

    /* Alocar memória para o funcionário selecionado */
    funcionario_t *funcionario_selecionado = malloc(sizeof(funcionario_t));

    if (!funcionario_selecionado) {
        /* [TODO] Criar tela de erro para alocação de memória */
        ui_exibir_erro("Erro ao alocar memória para funcionário.");
        return ESTADO_CADASTRO_FUNCIONARIOS;
    }

    /* Desenhar tela de busca para excluir funcionário */
    ui_desenhar_tela_excluir_buscar_funcionario(funcionario_selecionado);

    /* Busca o funcionário pelo número de matrícula */
    int resultado = buscar_funcionario_por_matricula(funcionario_selecionado->matricula, funcionario_selecionado);
    printf("\n");

    /* Verifica se o funcionário está logado, e, caso esteja, 
        não permitir a exclusão */
    if (funcionario_autenticado->matricula == funcionario_selecionado->matricula) {
        ui_desenhar_tela_erro("ERRO: EXCLUIR FUNCIONARIO","Funcionário logado não pode ser excluído.");
        free(funcionario_selecionado);
        return ESTADO_CADASTRO_FUNCIONARIOS;
    }

    /* Caso o funcionário não seja encontrado, mostrar tela de erro 
        e voltar ao menu anterior */
    if (resultado == 1) {
        ui_desenhar_tela_erro("ERRO: EXCLUIR FUNCIONARIO","Funcionário não encontrado.");
        free(funcionario_selecionado);
        return ESTADO_CADASTRO_FUNCIONARIOS;
    } 
    else if (resultado == 2) {
        ui_desenhar_tela_erro("ERRO: EXCLUIR FUNCIONARIO","Erro ao buscar funcionário.");
        free(funcionario_selecionado);
        return ESTADO_CADASTRO_FUNCIONARIOS;
    } 

    bool confirmar_exclusao = ui_desenhar_tela_excluir_confirmar_funcionario(
        funcionario_selecionado,
        funcionario_autenticado->nome,
        funcionario_autenticado->matricula
    );  
    
    if (confirmar_exclusao) {
        // Chama a função de exclusão do funcionário
        int resultado_exclusao = excluir_funcionario(funcionario_selecionado->matricula);

        if (resultado_exclusao == 0) {
            ui_desenhar_tela_sucesso("SUCESSO: EXCLUIR FUNCIONARIO","Funcionário excluído com sucesso.");
        } else {
            ui_desenhar_tela_erro("ERRO: EXCLUIR FUNCIONARIO","Erro ao excluir funcionário.");
        }
    } else {
        ui_desenhar_tela_erro("CANCELADO: EXCLUIR FUNCIONARIO","Exclusão cancelada pelo usuário.");
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