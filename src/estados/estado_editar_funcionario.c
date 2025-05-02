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
    int etapa_atual; // Controla a etapa do formulário
    int erro; // Código de erro, se houver
    int alterar_senha; // Flag que indica se a senha será alterada
} contexto_editar_funcionario_t;

// Protótipos de funções internas
static void inicializar(void *ctx);
static void finalizar(void *ctx);
static estado_t* processar(void *ctx);
static void exibir_interface(const contexto_editar_funcionario_t *ctx);

// Implementação da função de criação do estado
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
    
    // Inicializar o contexto com valores padrão
    memset(&ctx->funcionario, 0, sizeof(funcionario_t));
    memset(ctx->nova_senha, 0, sizeof(ctx->nova_senha));
    ctx->etapa_atual = 0;
    ctx->erro = 0;
    ctx->alterar_senha = 0;
    
    return estado;
}

// Função para inicializar o estado
static void inicializar(void *ctx) {
    contexto_editar_funcionario_t *contexto = (contexto_editar_funcionario_t*)ctx;
    
    // Obter a matrícula do funcionário a partir da sessão
    int matricula = session_get_int("matricula_editar", -1);
    if (matricula == -1 || !buscar_funcionario_csv(matricula, &contexto->funcionario)) {
        // Se não encontrou o funcionário, exibe mensagem de erro e volta para a lista
        ui_limpar_tela();
        desenhar_caixa_mensagem("Funcionário não encontrado!", 2); // tipo 2 = erro
        printf("\nPressione ENTER para continuar...");
        getchar();
        
        // Criar o próximo estado e definir para ser retornado no processar
        session_set_ptr("proximo_estado", criar_estado_listar_funcionarios());
        
        // Definir etapa_atual como -1 para indicar que houve erro
        contexto->etapa_atual = -1;
    } else {
        // Inicializar o contexto para edição do funcionário
        contexto->etapa_atual = 0;
        contexto->erro = 0;
        contexto->alterar_senha = 0;
    }
    
    // Exibir a interface
    exibir_interface(contexto);
}

// Função para finalizar o estado
static void finalizar(void *ctx) {
    // Limpar dados sensíveis
    contexto_editar_funcionario_t *contexto = (contexto_editar_funcionario_t*)ctx;
    memset(contexto->nova_senha, 0, sizeof(contexto->nova_senha));
}

// Função para processar o estado
static estado_t* processar(void *ctx) {
    contexto_editar_funcionario_t *contexto = (contexto_editar_funcionario_t*)ctx;
    
    // Se houve erro na inicialização
    if (contexto->etapa_atual == -1) {
        estado_t *proximo_estado = session_get_ptr("proximo_estado");
        session_set_ptr("proximo_estado", NULL);
        return proximo_estado;
    }
    
    // Processar de acordo com a etapa atual do formulário
    switch (contexto->etapa_atual) {
        case 0: { // Nome
            char nome[100];
            printf("Digite o novo nome do funcionário [%s]: ", contexto->funcionario.nome);
            if (!fgets(nome, sizeof(nome), stdin)) {
                contexto->erro = 1; // Erro: entrada inválida
                exibir_interface(contexto);
                return NULL;
            }
            
            // Remover o \n do final
            size_t len = strlen(nome);
            if (len > 0 && nome[len-1] == '\n') {
                nome[len-1] = '\0';
            }
            
            // Se não digitou nada, mantém o nome original
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
                contexto->etapa_atual += 2; // Pula a etapa de alteração de senha
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
                contexto->erro = 1; // Erro: entrada inválida
                exibir_interface(contexto);
                return NULL;
            }
            
            // Remover o \n do final
            size_t len = strlen(senha);
            if (len > 0 && senha[len-1] == '\n') {
                senha[len-1] = '\0';
            }
            
            // Validar se a senha não está vazia e tem pelo menos 4 caracteres
            if (strlen(senha) < 4) {
                contexto->erro = 4; // Erro: senha muito curta
                exibir_interface(contexto);
                return NULL;
            }
            
            strncpy(contexto->nova_senha, senha, sizeof(contexto->nova_senha));
            contexto->etapa_atual++;
            break;
        }
        
        case 3: { // Confirmação
            char opcao;
            printf("Confirmar alterações (S/N)? ");
            opcao = getchar();
            getchar(); // Limpar o \n
            
            if (opcao == 'S' || opcao == 's') {
                // Se for alterar a senha, gera novo hash
                if (contexto->alterar_senha) {
                    hash_senha(contexto->nova_senha, contexto->funcionario.hash_senha, HASH_KEY);
                }
                
                // Salvar funcionário
                if (!atualizar_funcionario_csv(&contexto->funcionario)) {
                    contexto->erro = 5; // Erro ao salvar
                    exibir_interface(contexto);
                    return NULL;
                }
                
                // Exibir mensagem de sucesso
                ui_limpar_tela();
                desenhar_caixa_mensagem("Funcionário atualizado com sucesso!", 1); // tipo 1 = sucesso
                printf("\nPressione ENTER para continuar...");
                getchar();
                
                // Retornar para a listagem de funcionários
                return criar_estado_listar_funcionarios();
            } else {
                // Cancelar operação
                ui_limpar_tela();
                desenhar_caixa_mensagem("Operação cancelada pelo usuário.", 3); // tipo 3 = informação
                printf("\nPressione ENTER para continuar...");
                getchar();
                
                // Retornar para a listagem de funcionários
                return criar_estado_listar_funcionarios();
            }
        }
        
        default:
            // Se chegou aqui, há um erro na lógica do programa
            return criar_estado_listar_funcionarios();
    }
    
    // Atualizar a interface para a próxima etapa
    exibir_interface(contexto);
    return NULL;
}

// Função para exibir a interface
static void exibir_interface(const contexto_editar_funcionario_t *ctx) {
    ui_limpar_tela();
    desenhar_cabecalho("EDITAR FUNCIONÁRIO");
    
    // Exibir erro, se houver
    if (ctx->erro > 0) {
        switch (ctx->erro) {
            case 1:
                desenhar_caixa_mensagem("Entrada inválida. Por favor, tente novamente.", 2);
                break;
            case 4:
                desenhar_caixa_mensagem("A senha deve ter pelo menos 4 caracteres.", 2);
                break;
            case 5:
                desenhar_caixa_mensagem("Erro ao salvar o funcionário. Tente novamente.", 2);
                break;
            default:
                desenhar_caixa_mensagem("Ocorreu um erro desconhecido.", 2);
        }
    }
    
    // Exibir o formulário de acordo com a etapa atual
    desenhar_linha_simples();
    printf("? %-53s ?\n", "Edição do funcionário:");
    desenhar_linha_simples();
    
    printf("? Matrícula: %-43d ?\n", ctx->funcionario.matricula);
    
    if (ctx->etapa_atual >= 1) {
        printf("? Nome: %-48s ?\n", ctx->funcionario.nome);
    }
    
    if (ctx->etapa_atual >= 3 && ctx->alterar_senha) {
        printf("? Senha: %-48s ?\n", "********");
    }
    
    desenhar_rodape();
}