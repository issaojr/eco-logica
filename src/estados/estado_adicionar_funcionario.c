#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estados/estado_adicionar_funcionario.h"
#include "estados/estado_listar_funcionarios.h"
#include "funcionario.h"
#include "persistencia.h"
#include "crypto.h"
#include "ui/ui_comum.h"
#include "ui/ui_formulario.h"

#define HASH_KEY 0xAA

// Contexto do estado
typedef struct {
    funcionario_t novo_funcionario;
    char senha[64]; // Senha em texto claro para posterior hash
    int etapa_atual; // Controla a etapa do formulário
    int erro; // Código de erro, se houver
} contexto_adicionar_funcionario_t;

// Protótipos de funções internas
static void inicializar(void *ctx);
static void finalizar(void *ctx);
static estado_t* processar(void *ctx);
static void exibir_interface(const contexto_adicionar_funcionario_t *ctx);
static int validar_dados(contexto_adicionar_funcionario_t *ctx);

// Implementação da função de criação do estado
estado_t* criar_estado_adicionar_funcionario(void) {
    estado_t *estado = malloc(sizeof(estado_t));
    contexto_adicionar_funcionario_t *ctx = malloc(sizeof(contexto_adicionar_funcionario_t));
    
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
    memset(&ctx->novo_funcionario, 0, sizeof(funcionario_t));
    memset(ctx->senha, 0, sizeof(ctx->senha));
    ctx->etapa_atual = 0;
    ctx->erro = 0;
    
    return estado;
}

// Função para inicializar o estado
static void inicializar(void *ctx) {
    contexto_adicionar_funcionario_t *contexto = (contexto_adicionar_funcionario_t*)ctx;
    
    // Inicializar o contexto para um novo funcionário
    memset(&contexto->novo_funcionario, 0, sizeof(funcionario_t));
    memset(contexto->senha, 0, sizeof(contexto->senha));
    contexto->etapa_atual = 0;
    contexto->erro = 0;
    
    // Exibir a interface
    exibir_interface(contexto);
}

// Função para finalizar o estado
static void finalizar(void *ctx) {
    // Limpar dados sensíveis
    contexto_adicionar_funcionario_t *contexto = (contexto_adicionar_funcionario_t*)ctx;
    memset(contexto->senha, 0, sizeof(contexto->senha));
}

// Função para processar o estado
static estado_t* processar(void *ctx) {
    contexto_adicionar_funcionario_t *contexto = (contexto_adicionar_funcionario_t*)ctx;
    
    // Processar de acordo com a etapa atual do formulário
    switch (contexto->etapa_atual) {
        case 0: { // Matrícula
            int matricula;
            printf("Digite a matrícula do funcionário: ");
            if (scanf("%d", &matricula) != 1) {
                getchar(); // Limpar o buffer de entrada
                contexto->erro = 1; // Erro: entrada inválida
                exibir_interface(contexto);
                return NULL;
            }
            getchar(); // Limpar o \n
            
            // Verificar se a matrícula já existe
            funcionario_t funcionario_existente;
            if (buscar_funcionario_csv(matricula, &funcionario_existente)) {
                contexto->erro = 2; // Erro: matrícula já existe
                exibir_interface(contexto);
                return NULL;
            }
            
            contexto->novo_funcionario.matricula = matricula;
            contexto->etapa_atual++;
            break;
        }
        
        case 1: { // Nome
            char nome[100];
            printf("Digite o nome do funcionário: ");
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
            
            // Validar se o nome não está vazio
            if (strlen(nome) == 0) {
                contexto->erro = 3; // Erro: nome vazio
                exibir_interface(contexto);
                return NULL;
            }
            
            strncpy(contexto->novo_funcionario.nome, nome, sizeof(contexto->novo_funcionario.nome));
            contexto->etapa_atual++;
            break;
        }
        
        case 2: { // Senha
            char senha[64];
            printf("Digite a senha do funcionário: ");
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
            
            strncpy(contexto->senha, senha, sizeof(contexto->senha));
            contexto->etapa_atual++;
            break;
        }
        
        case 3: { // Confirmação
            char opcao;
            printf("Confirmar cadastro (S/N)? ");
            opcao = getchar();
            getchar(); // Limpar o \n
            
            if (opcao == 'S' || opcao == 's') {
                // Gerar hash da senha
                hash_senha(contexto->senha, contexto->novo_funcionario.hash_senha, HASH_KEY);
                
                // Salvar funcionário
                if (!inserir_funcionario_csv(&contexto->novo_funcionario)) {
                    contexto->erro = 5; // Erro ao salvar
                    exibir_interface(contexto);
                    return NULL;
                }
                
                // Exibir mensagem de sucesso
                ui_limpar_tela();
                desenhar_caixa_mensagem("Funcionário cadastrado com sucesso!", 1); // tipo 1 = sucesso
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
static void exibir_interface(const contexto_adicionar_funcionario_t *ctx) {
    ui_limpar_tela();
    desenhar_cabecalho("ADICIONAR FUNCIONÁRIO");
    
    // Exibir erro, se houver
    if (ctx->erro > 0) {
        switch (ctx->erro) {
            case 1:
                desenhar_caixa_mensagem("Entrada inválida. Por favor, tente novamente.", 2);
                break;
            case 2:
                desenhar_caixa_mensagem("Matrícula já existe. Escolha outra matrícula.", 2);
                break;
            case 3:
                desenhar_caixa_mensagem("O nome não pode estar vazio.", 2);
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
    printf("? %-53s ?\n", "Preencha os dados do novo funcionário:");
    desenhar_linha_simples();
    
    if (ctx->etapa_atual >= 1) {
        printf("? Matrícula: %-43d ?\n", ctx->novo_funcionario.matricula);
    }
    
    if (ctx->etapa_atual >= 2) {
        printf("? Nome: %-48s ?\n", ctx->novo_funcionario.nome);
    }
    
    if (ctx->etapa_atual >= 3) {
        printf("? Senha: %-48s ?\n", "********");
    }
    
    desenhar_rodape();
}