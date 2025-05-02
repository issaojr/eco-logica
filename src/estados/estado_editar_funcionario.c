#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estados/estado_editar_funcionario.h"
#include "estados/estado_listar_funcionarios.h"
#include "funcionario.h"
#include "persistencia.h"
#include "crypto.h"
#include "ui/ui_comum.h"
#include "ui/ui_formulario.h"
#include "session.h"

#define HASH_KEY 0xAA

// Contexto do estado
typedef struct {
    funcionario_t funcionario;
    char nova_senha[64]; // Nova senha em texto claro para posterior hash
    int etapa_atual; // Controla a etapa do formul�rio
    int erro; // C�digo de erro, se houver
    int alterar_senha; // Flag que indica se a senha ser� alterada
} contexto_editar_funcionario_t;

// Prot�tipos de fun��es internas
static void inicializar(void *ctx);
static void finalizar(void *ctx);
static estado_t* processar(void *ctx);
static void exibir_interface(const contexto_editar_funcionario_t *ctx);

// Implementa��o da fun��o de cria��o do estado
estado_t* criar_estado_editar_funcionario(void) {
    estado_t *estado = malloc(sizeof(estado_t));
    contexto_editar_funcionario_t *ctx = malloc(sizeof(contexto_editar_funcionario_t));
    
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
    memset(ctx->nova_senha, 0, sizeof(ctx->nova_senha));
    ctx->etapa_atual = 0;
    ctx->erro = 0;
    ctx->alterar_senha = 0;
    
    return estado;
}

// Fun��o para inicializar o estado
static void inicializar(void *ctx) {
    contexto_editar_funcionario_t *contexto = (contexto_editar_funcionario_t*)ctx;
    
    // Obter a matr�cula do funcion�rio a partir da sess�o
    int matricula = session_get_int("matricula_editar", -1);
    if (matricula == -1 || !buscar_funcionario_csv(matricula, &contexto->funcionario)) {
        // Se n�o encontrou o funcion�rio, exibe mensagem de erro e volta para a lista
        ui_limpar_tela();
        desenhar_caixa_mensagem("Funcion�rio n�o encontrado!", 2); // tipo 2 = erro
        printf("\nPressione ENTER para continuar...");
        getchar();
        
        // Criar o pr�ximo estado e definir para ser retornado no processar
        session_set_ptr("proximo_estado", criar_estado_listar_funcionarios());
        
        // Definir etapa_atual como -1 para indicar que houve erro
        contexto->etapa_atual = -1;
    } else {
        // Inicializar o contexto para edi��o do funcion�rio
        contexto->etapa_atual = 0;
        contexto->erro = 0;
        contexto->alterar_senha = 0;
    }
    
    // Exibir a interface
    exibir_interface(contexto);
}

// Fun��o para finalizar o estado
static void finalizar(void *ctx) {
    // Limpar dados sens�veis
    contexto_editar_funcionario_t *contexto = (contexto_editar_funcionario_t*)ctx;
    memset(contexto->nova_senha, 0, sizeof(contexto->nova_senha));
}

// Fun��o para processar o estado
static estado_t* processar(void *ctx) {
    contexto_editar_funcionario_t *contexto = (contexto_editar_funcionario_t*)ctx;
    
    // Se houve erro na inicializa��o
    if (contexto->etapa_atual == -1) {
        estado_t *proximo_estado = session_get_ptr("proximo_estado");
        session_set_ptr("proximo_estado", NULL);
        return proximo_estado;
    }
    
    // Processar de acordo com a etapa atual do formul�rio
    switch (contexto->etapa_atual) {
        case 0: { // Nome
            char nome[100];
            printf("Digite o novo nome do funcion�rio [%s]: ", contexto->funcionario.nome);
            if (!fgets(nome, sizeof(nome), stdin)) {
                contexto->erro = 1; // Erro: entrada inv�lida
                exibir_interface(contexto);
                return NULL;
            }
            
            // Remover o \n do final
            size_t len = strlen(nome);
            if (len > 0 && nome[len-1] == '\n') {
                nome[len-1] = '\0';
            }
            
            // Se n�o digitou nada, mant�m o nome original
            if (strlen(nome) > 0) {
                strncpy(contexto->funcionario.nome, nome, sizeof(contexto->funcionario.nome));
            }
            
            contexto->etapa_atual++;
            break;
        }
        
        case 1: { // Pergunta se quer alterar a senha
            char opcao;
            printf("Deseja alterar a senha (S/N)? ");
            opcao = getchar();
            getchar(); // Limpar o \n
            
            if (opcao == 'S' || opcao == 's') {
                contexto->alterar_senha = 1;
                contexto->etapa_atual++;
            } else {
                contexto->alterar_senha = 0;
                contexto->etapa_atual += 2; // Pula a etapa de altera��o de senha
            }
            break;
        }
        
        case 2: { // Nova senha (apenas se alterar_senha == 1)
            if (!contexto->alterar_senha) {
                contexto->etapa_atual++;
                break;
            }
            
            char senha[64];
            printf("Digite a nova senha: ");
            if (!fgets(senha, sizeof(senha), stdin)) {
                contexto->erro = 1; // Erro: entrada inv�lida
                exibir_interface(contexto);
                return NULL;
            }
            
            // Remover o \n do final
            size_t len = strlen(senha);
            if (len > 0 && senha[len-1] == '\n') {
                senha[len-1] = '\0';
            }
            
            // Validar se a senha n�o est� vazia e tem pelo menos 4 caracteres
            if (strlen(senha) < 4) {
                contexto->erro = 4; // Erro: senha muito curta
                exibir_interface(contexto);
                return NULL;
            }
            
            strncpy(contexto->nova_senha, senha, sizeof(contexto->nova_senha));
            contexto->etapa_atual++;
            break;
        }
        
        case 3: { // Confirma��o
            char opcao;
            printf("Confirmar altera��es (S/N)? ");
            opcao = getchar();
            getchar(); // Limpar o \n
            
            if (opcao == 'S' || opcao == 's') {
                // Se for alterar a senha, gera novo hash
                if (contexto->alterar_senha) {
                    hash_senha(contexto->nova_senha, contexto->funcionario.hash_senha, HASH_KEY);
                }
                
                // Salvar funcion�rio
                if (!atualizar_funcionario_csv(&contexto->funcionario)) {
                    contexto->erro = 5; // Erro ao salvar
                    exibir_interface(contexto);
                    return NULL;
                }
                
                // Exibir mensagem de sucesso
                ui_limpar_tela();
                desenhar_caixa_mensagem("Funcion�rio atualizado com sucesso!", 1); // tipo 1 = sucesso
                printf("\nPressione ENTER para continuar...");
                getchar();
                
                // Retornar para a listagem de funcion�rios
                return criar_estado_listar_funcionarios();
            } else {
                // Cancelar opera��o
                ui_limpar_tela();
                desenhar_caixa_mensagem("Opera��o cancelada pelo usu�rio.", 3); // tipo 3 = informa��o
                printf("\nPressione ENTER para continuar...");
                getchar();
                
                // Retornar para a listagem de funcion�rios
                return criar_estado_listar_funcionarios();
            }
        }
        
        default:
            // Se chegou aqui, h� um erro na l�gica do programa
            return criar_estado_listar_funcionarios();
    }
    
    // Atualizar a interface para a pr�xima etapa
    exibir_interface(contexto);
    return NULL;
}

// Fun��o para exibir a interface
static void exibir_interface(const contexto_editar_funcionario_t *ctx) {
    ui_limpar_tela();
    desenhar_cabecalho("EDITAR FUNCION�RIO");
    
    // Exibir erro, se houver
    if (ctx->erro > 0) {
        switch (ctx->erro) {
            case 1:
                desenhar_caixa_mensagem("Entrada inv�lida. Por favor, tente novamente.", 2);
                break;
            case 4:
                desenhar_caixa_mensagem("A senha deve ter pelo menos 4 caracteres.", 2);
                break;
            case 5:
                desenhar_caixa_mensagem("Erro ao salvar o funcion�rio. Tente novamente.", 2);
                break;
            default:
                desenhar_caixa_mensagem("Ocorreu um erro desconhecido.", 2);
        }
    }
    
    // Exibir o formul�rio de acordo com a etapa atual
    desenhar_linha_simples();
    printf("? %-53s ?\n", "Edi��o do funcion�rio:");
    desenhar_linha_simples();
    
    printf("? Matr�cula: %-43d ?\n", ctx->funcionario.matricula);
    
    if (ctx->etapa_atual >= 1) {
        printf("? Nome: %-48s ?\n", ctx->funcionario.nome);
    }
    
    if (ctx->etapa_atual >= 3 && ctx->alterar_senha) {
        printf("? Senha: %-48s ?\n", "********");
    }
    
    desenhar_rodape();
}