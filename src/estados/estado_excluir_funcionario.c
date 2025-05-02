#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estados/estado_excluir_funcionario.h"
#include "estados/estado_listar_funcionarios.h"
#include "funcionario.h"
#include "persistencia.h"
#include "ui/ui_comum.h"
#include "ui/ui_formulario.h"
#include "session.h"

// Contexto do estado
typedef struct {
    funcionario_t funcionario;
    int confirmacao_pendente; // Flag que indica se est� na etapa de confirma��o
    int erro; // C�digo de erro, se houver
} contexto_excluir_funcionario_t;

// Prot�tipos de fun��es internas
static void inicializar(void *ctx);
static void finalizar(void *ctx);
static estado_t* processar(void *ctx);
static void exibir_interface(const contexto_excluir_funcionario_t *ctx);

// Implementa��o da fun��o de cria��o do estado
estado_t* criar_estado_excluir_funcionario(void) {
    estado_t *estado = malloc(sizeof(estado_t));
    contexto_excluir_funcionario_t *ctx = malloc(sizeof(contexto_excluir_funcionario_t));
    
    if (!estado || !ctx) {
        free(estado);
        free(ctx);
        return NULL;
    }
    
    estado->inicializar = inicializar;
    estado->finalizar = finalizar;
    estado->processar = processar;
    estado->contexto = ctx;
    
    // Inicializar o contexto com valores padr�o
    memset(&ctx->funcionario, 0, sizeof(funcionario_t));
    ctx->confirmacao_pendente = 0;
    ctx->erro = 0;
    
    return estado;
}

// Fun��o para inicializar o estado
static void inicializar(void *ctx) {
    contexto_excluir_funcionario_t *contexto = (contexto_excluir_funcionario_t*)ctx;
    
    // Obter a matr�cula do funcion�rio a partir da sess�o
    int matricula = session_get_int("matricula_excluir", -1);
    if (matricula == -1 || !buscar_funcionario_csv(matricula, &contexto->funcionario)) {
        // Se n�o encontrou o funcion�rio, exibe mensagem de erro e volta para a lista
        ui_limpar_tela();
        desenhar_caixa_mensagem("Funcion�rio n�o encontrado!", 2); // tipo 2 = erro
        printf("\nPressione ENTER para continuar...");
        getchar();
        
        // Criar o pr�ximo estado e definir para ser retornado no processar
        session_set_ptr("proximo_estado", criar_estado_listar_funcionarios());
        
        // Definir confirmacao_pendente como -1 para indicar que houve erro
        contexto->confirmacao_pendente = -1;
    } else {
        // Inicializar o contexto para exclus�o do funcion�rio
        contexto->confirmacao_pendente = 1;
        contexto->erro = 0;
    }
    
    // Exibir a interface
    exibir_interface(contexto);
}

// Fun��o para finalizar o estado
static void finalizar(void *ctx) {
    // Nada a limpar espec�fico para este estado
}

// Fun��o para processar o estado
static estado_t* processar(void *ctx) {
    contexto_excluir_funcionario_t *contexto = (contexto_excluir_funcionario_t*)ctx;
    
    // Se houve erro na inicializa��o
    if (contexto->confirmacao_pendente == -1) {
        estado_t *proximo_estado = session_get_ptr("proximo_estado");
        session_set_ptr("proximo_estado", NULL);
        return proximo_estado;
    }
    
    // Confirmar exclus�o
    char opcao;
    printf("\nTem certeza que deseja excluir este funcion�rio? (S/N) ");
    opcao = getchar();
    getchar(); // Limpar o \n
    
    if (opcao == 'S' || opcao == 's') {
        // Tenta excluir o funcion�rio
        if (!excluir_funcionario_csv(contexto->funcionario.matricula)) {
            // Erro ao excluir
            ui_limpar_tela();
            desenhar_caixa_mensagem("Erro ao excluir o funcion�rio!", 2); // tipo 2 = erro
            printf("\nPressione ENTER para continuar...");
            getchar();
        } else {
            // Exclus�o bem sucedida
            ui_limpar_tela();
            desenhar_caixa_mensagem("Funcion�rio exclu�do com sucesso!", 1); // tipo 1 = sucesso
            printf("\nPressione ENTER para continuar...");
            getchar();
        }
    } else {
        // Cancelar opera��o
        ui_limpar_tela();
        desenhar_caixa_mensagem("Opera��o cancelada pelo usu�rio.", 3); // tipo 3 = informa��o
        printf("\nPressione ENTER para continuar...");
        getchar();
    }
    
    // Retornar para a listagem de funcion�rios
    return criar_estado_listar_funcionarios();
}

// Fun��o para exibir a interface
static void exibir_interface(const contexto_excluir_funcionario_t *ctx) {
    ui_limpar_tela();
    desenhar_cabecalho("EXCLUIR FUNCION�RIO");
    
    // Exibir erro, se houver
    if (ctx->erro > 0) {
        desenhar_caixa_mensagem("Ocorreu um erro ao tentar excluir o funcion�rio.", 2);
    }
    
    // Exibir dados do funcion�rio
    desenhar_linha_simples();
    printf("? %-53s ?\n", "Dados do funcion�rio a ser exclu�do:");
    desenhar_linha_simples();
    
    printf("? Matr�cula: %-43d ?\n", ctx->funcionario.matricula);
    printf("? Nome: %-48s ?\n", ctx->funcionario.nome);
    
    desenhar_rodape();
    
    // Aviso de confirma��o
    printf("\n");
    desenhar_caixa_mensagem("ATEN��O: Esta a��o n�o pode ser desfeita!", 2); // tipo 2 = alerta
}