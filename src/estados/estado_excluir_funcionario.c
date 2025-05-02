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
    int confirmacao_pendente; // Flag que indica se está na etapa de confirmação
    int erro; // Código de erro, se houver
} contexto_excluir_funcionario_t;

// Protótipos de funções internas
static void inicializar(void *ctx);
static void finalizar(void *ctx);
static estado_t* processar(void *ctx);
static void exibir_interface(const contexto_excluir_funcionario_t *ctx);

// Implementação da função de criação do estado
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
    
    // Inicializar o contexto com valores padrão
    memset(&ctx->funcionario, 0, sizeof(funcionario_t));
    ctx->confirmacao_pendente = 0;
    ctx->erro = 0;
    
    return estado;
}

// Função para inicializar o estado
static void inicializar(void *ctx) {
    contexto_excluir_funcionario_t *contexto = (contexto_excluir_funcionario_t*)ctx;
    
    // Obter a matrícula do funcionário a partir da sessão
    int matricula = session_get_int("matricula_excluir", -1);
    if (matricula == -1 || !buscar_funcionario_csv(matricula, &contexto->funcionario)) {
        // Se não encontrou o funcionário, exibe mensagem de erro e volta para a lista
        ui_limpar_tela();
        desenhar_caixa_mensagem("Funcionário não encontrado!", 2); // tipo 2 = erro
        printf("\nPressione ENTER para continuar...");
        getchar();
        
        // Criar o próximo estado e definir para ser retornado no processar
        session_set_ptr("proximo_estado", criar_estado_listar_funcionarios());
        
        // Definir confirmacao_pendente como -1 para indicar que houve erro
        contexto->confirmacao_pendente = -1;
    } else {
        // Inicializar o contexto para exclusão do funcionário
        contexto->confirmacao_pendente = 1;
        contexto->erro = 0;
    }
    
    // Exibir a interface
    exibir_interface(contexto);
}

// Função para finalizar o estado
static void finalizar(void *ctx) {
    // Nada a limpar específico para este estado
}

// Função para processar o estado
static estado_t* processar(void *ctx) {
    contexto_excluir_funcionario_t *contexto = (contexto_excluir_funcionario_t*)ctx;
    
    // Se houve erro na inicialização
    if (contexto->confirmacao_pendente == -1) {
        estado_t *proximo_estado = session_get_ptr("proximo_estado");
        session_set_ptr("proximo_estado", NULL);
        return proximo_estado;
    }
    
    // Confirmar exclusão
    char opcao;
    printf("\nTem certeza que deseja excluir este funcionário? (S/N) ");
    opcao = getchar();
    getchar(); // Limpar o \n
    
    if (opcao == 'S' || opcao == 's') {
        // Tenta excluir o funcionário
        if (!excluir_funcionario_csv(contexto->funcionario.matricula)) {
            // Erro ao excluir
            ui_limpar_tela();
            desenhar_caixa_mensagem("Erro ao excluir o funcionário!", 2); // tipo 2 = erro
            printf("\nPressione ENTER para continuar...");
            getchar();
        } else {
            // Exclusão bem sucedida
            ui_limpar_tela();
            desenhar_caixa_mensagem("Funcionário excluído com sucesso!", 1); // tipo 1 = sucesso
            printf("\nPressione ENTER para continuar...");
            getchar();
        }
    } else {
        // Cancelar operação
        ui_limpar_tela();
        desenhar_caixa_mensagem("Operação cancelada pelo usuário.", 3); // tipo 3 = informação
        printf("\nPressione ENTER para continuar...");
        getchar();
    }
    
    // Retornar para a listagem de funcionários
    return criar_estado_listar_funcionarios();
}

// Função para exibir a interface
static void exibir_interface(const contexto_excluir_funcionario_t *ctx) {
    ui_limpar_tela();
    desenhar_cabecalho("EXCLUIR FUNCIONÁRIO");
    
    // Exibir erro, se houver
    if (ctx->erro > 0) {
        desenhar_caixa_mensagem("Ocorreu um erro ao tentar excluir o funcionário.", 2);
    }
    
    // Exibir dados do funcionário
    desenhar_linha_simples();
    printf("? %-53s ?\n", "Dados do funcionário a ser excluído:");
    desenhar_linha_simples();
    
    printf("? Matrícula: %-43d ?\n", ctx->funcionario.matricula);
    printf("? Nome: %-48s ?\n", ctx->funcionario.nome);
    
    desenhar_rodape();
    
    // Aviso de confirmação
    printf("\n");
    desenhar_caixa_mensagem("ATENÇÃO: Esta ação não pode ser desfeita!", 2); // tipo 2 = alerta
}