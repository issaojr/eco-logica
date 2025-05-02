#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estados/estado_listar_funcionarios.h"
#include "estados/estado_adicionar_funcionario.h"
#include "estados/estado_editar_funcionario.h"
#include "estados/estado_excluir_funcionario.h"
#include "estados/estado_menu_principal.h"
#include "funcionario.h"
#include "persistencia.h"
#include "ui/ui_comum.h"
#include "estado_menu_utils.h"
#include "session.h"

// Definições de códigos de opção
#define OPC_VOLTAR    0
#define OPC_ADICIONAR 1
#define OPC_EDITAR    2
#define OPC_EXCLUIR   3

// Definições para controle de paginação
#define MAX_FUNCIONARIOS_POR_PAGINA 10
#define MAX_FUNCIONARIOS_TOTAL 100

// Contexto do estado
typedef struct {
    funcionario_t funcionarios[MAX_FUNCIONARIOS_TOTAL];
    size_t total_funcionarios;
    size_t pagina_atual;
    int opcao_selecionada;
    int matricula_selecionada;
} contexto_listar_funcionarios_t;

// Protótipos de funções internas
static void inicializar(void *ctx);
static void finalizar(void *ctx);
static estado_t* processar(void *ctx);
static void exibir_interface(const contexto_listar_funcionarios_t *ctx);
static void exibir_lista_funcionarios(const contexto_listar_funcionarios_t *ctx);

// Implementação da função de criação do estado
estado_t* criar_estado_listar_funcionarios(void) {
    estado_t *estado = malloc(sizeof(estado_t));
    contexto_listar_funcionarios_t *ctx = malloc(sizeof(contexto_listar_funcionarios_t));
    
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
    ctx->pagina_atual = 0;
    ctx->total_funcionarios = 0;
    ctx->opcao_selecionada = -1;
    ctx->matricula_selecionada = -1;
    
    return estado;
}

// Função para inicializar o estado
static void inicializar(void *ctx) {
    contexto_listar_funcionarios_t *contexto = (contexto_listar_funcionarios_t*)ctx;
    
    // Carregar a lista de funcionários
    if (!listar_funcionarios_csv(contexto->funcionarios, MAX_FUNCIONARIOS_TOTAL, &contexto->total_funcionarios)) {
        contexto->total_funcionarios = 0;
    }
    
    // Exibir a interface
    exibir_interface(contexto);
}

// Função para finalizar o estado
static void finalizar(void *ctx) {
    // Nada a fazer na finalização
    (void)ctx;
}

// Função para processar o estado
static estado_t* processar(void *ctx) {
    contexto_listar_funcionarios_t *contexto = (contexto_listar_funcionarios_t*)ctx;
    
    // Ler a opção do usuário
    printf("\nEscolha uma opção: ");
    int opcao;
    scanf("%d", &opcao);
    getchar(); // Consumir o \n
    
    // Processar a opção escolhida
    switch (opcao) {
        case OPC_VOLTAR:
            return criar_estado_menu_principal();
            
        case OPC_ADICIONAR:
            return criar_estado_adicionar_funcionario();
            
        case OPC_EDITAR: {
            printf("Digite a matrícula do funcionário a editar: ");
            int matricula;
            scanf("%d", &matricula);
            getchar(); // Consumir o \n
            
            // Verificar se o funcionário existe
            funcionario_t funcionario;
            if (!buscar_funcionario_csv(matricula, &funcionario)) {
                ui_limpar_tela();
                desenhar_caixa_mensagem("Funcionário não encontrado!", 2); // tipo 2 = erro
                printf("\nPressione ENTER para continuar...");
                getchar();
                exibir_interface(contexto);
                return NULL; // Continuar no estado atual
            }
            
            // Armazenar a matrícula na sessão para o próximo estado
            session_set_int("matricula_editar", matricula);
            return criar_estado_editar_funcionario();
        }
            
        case OPC_EXCLUIR: {
            printf("Digite a matrícula do funcionário a excluir: ");
            int matricula;
            scanf("%d", &matricula);
            getchar(); // Consumir o \n
            
            // Verificar se o funcionário existe
            funcionario_t funcionario;
            if (!buscar_funcionario_csv(matricula, &funcionario)) {
                ui_limpar_tela();
                desenhar_caixa_mensagem("Funcionário não encontrado!", 2); // tipo 2 = erro
                printf("\nPressione ENTER para continuar...");
                getchar();
                exibir_interface(contexto);
                return NULL; // Continuar no estado atual
            }
            
            // Armazenar a matrícula na sessão para o próximo estado
            session_set_int("matricula_excluir", matricula);
            return criar_estado_excluir_funcionario();
        }
        
        default:
            ui_limpar_tela();
            desenhar_caixa_mensagem("Opção inválida!", 2); // tipo 2 = erro
            printf("\nPressione ENTER para continuar...");
            getchar();
            exibir_interface(contexto);
            return NULL; // Continuar no estado atual
    }
}

// Função para exibir a interface
static void exibir_interface(const contexto_listar_funcionarios_t *ctx) {
    ui_limpar_tela();
    desenhar_cabecalho("GESTÃO DE FUNCIONÁRIOS");
    
    exibir_lista_funcionarios(ctx);
    
    desenhar_linha_simples();
    printf("? [1] Adicionar Funcionário                              ?\n");
    printf("? [2] Editar Funcionário                                 ?\n");
    printf("? [3] Excluir Funcionário                                ?\n");
    printf("? [0] Voltar                                             ?\n");
    desenhar_rodape();
}

// Função para exibir a lista de funcionários
static void exibir_lista_funcionarios(const contexto_listar_funcionarios_t *ctx) {
    // Título da tabela
    printf("? %-10s | %-40s ?\n", "MATRÍCULA", "NOME");
    desenhar_linha_simples();
    
    // Se não houver funcionários
    if (ctx->total_funcionarios == 0) {
        printf("? Nenhum funcionário cadastrado.                        ?\n");
        return;
    }
    
    // Calcular índices de início e fim para exibição paginada
    size_t inicio = ctx->pagina_atual * MAX_FUNCIONARIOS_POR_PAGINA;
    size_t fim = inicio + MAX_FUNCIONARIOS_POR_PAGINA;
    if (fim > ctx->total_funcionarios) {
        fim = ctx->total_funcionarios;
    }
    
    // Exibir funcionários
    for (size_t i = inicio; i < fim; i++) {
        printf("? %-10d | %-40s ?\n", 
               ctx->funcionarios[i].matricula, 
               ctx->funcionarios[i].nome);
    }
    
    // Exibir informações de paginação se necessário
    if (ctx->total_funcionarios > MAX_FUNCIONARIOS_POR_PAGINA) {
        desenhar_linha_simples();
        printf("? Página %zu de %zu (%zu funcionários)                   ?\n", 
               ctx->pagina_atual + 1, 
               (ctx->total_funcionarios + MAX_FUNCIONARIOS_POR_PAGINA - 1) / MAX_FUNCIONARIOS_POR_PAGINA, 
               ctx->total_funcionarios);
    }
}