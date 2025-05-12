#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estados/funcionarios/estado_editar_funcionario.h"
#include "business/business_funcionario.h"
#include "ui/funcionarios/ui_tela_cadastro_funcionarios.h"
#include "ui/ui_comum.h"
#include "session.h"

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

    funcionario_t *funcionario_antes = malloc(sizeof(funcionario_t));
    funcionario_t *funcionario_depois = malloc(sizeof(funcionario_t));

    ui_desenhar_tela_editar_buscar_funcionario(funcionario_antes);

    // Busca o funcion�rio pelo n�mero de matr�cula
    int resultado = buscar_funcionario_por_matricula(funcionario_antes->matricula, funcionario_antes);

    printf("\n");

    /* Caso o funcion�rio n�o seja encontrado, mostrar tela de erro 
        e voltar ao menu anterior */
    if (resultado == 1) {
        ui_desenhar_tela_erro("ERRO: EDITAR FUNCIONARIO","Funcion�rio n�o encontrado.");
        free(funcionario_antes);
        free(funcionario_depois);
        return ESTADO_CADASTRO_FUNCIONARIOS;
    } 
    else if (resultado == 2) {
        ui_desenhar_tela_erro("ERRO: EDITAR FUNCIONARIO","Erro ao buscar funcion�rio.");
        free(funcionario_antes);
        free(funcionario_depois);
        return ESTADO_CADASTRO_FUNCIONARIOS;
    } else {
        // Exibe o painel do funcion�rio encontrado
        ui_desenhar_painel_funcionario_selecionado(
            funcionario_antes->nome, 
            funcionario_antes->matricula
        );
    }

    /* Copia a matr�cula do funcion�rio encontrado para o novo funcion�rio */
    funcionario_depois->matricula = funcionario_antes->matricula;

    // Exibe o formul�rio de editar funcion�rio
    ui_desenhar_form_editar_funcionario(
        funcionario_autenticado->nome,
        funcionario_autenticado->matricula,
        funcionario_antes,
        funcionario_depois
    );

    /* Caso esteja tudo certo, substituir a antiga entrada pela nova */
    resultado = editar_funcionario(funcionario_depois);

    /* Limpa a mem�ria alocada */
    free(funcionario_antes);
    free(funcionario_depois);

    /* Verifica se a edi��o foi bem-sucedida */
    if (resultado == 0) {
        // Edi��o bem-sucedida
        // caso a matr�cula do funcionario atualizado seja a mesma do funcionario autenticado
        // atualiza a sess�o
        if (funcionario_autenticado->matricula == funcionario_depois->matricula) {
            set_funcionario_logado(funcionario_depois);
        }
        ui_desenhar_tela_sucesso("EDI��O DE FUNCION�RIO BEM-SUCEDIDA","Funcion�rio editado com sucesso.");
    } else if (resultado == 1) {
        // Erro ao editar
        ui_desenhar_tela_erro("EDI��O DE FUNCION�RIO FALHOU","Erro ao editar funcion�rio.");
    } else if (resultado == 2) {
        // Funcion�rio n�o encontrado
        ui_desenhar_tela_erro("EDI��O DE FUNCION�RIO FALHOU","Funcion�rio n�o encontrado.");
    }

    return ESTADO_CADASTRO_FUNCIONARIOS; 
}

static void finalizar(void) {
    // TODO: liberar recursos alocados (se houver)
}

static estado_aplicacao obter_id(void) {
    return ESTADO_EDITAR_FUNCIONARIO;  
}

estado_t* criar_estado_editar_funcionario(void) {
    estado_t *estado = malloc(sizeof(estado_t));
    if (!estado) return NULL;

    estado->inicializar = inicializar;
    estado->processar   = processar;
    estado->finalizar   = finalizar;
    estado->obter_id    = obter_id;
    return estado;
}