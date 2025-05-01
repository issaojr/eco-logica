#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "estados/estado_form_login.h"
#include "auth.h"

// Definição de tipos para tornar o código mais semântico
typedef enum {
    ENTRADA_MATRICULA,
    ENTRADA_SENHA,
    PROCESSAMENTO_AUTENTICACAO
} fase_form_login_t;

// Variáveis específicas deste estado
static int matricula;
static char senha[64];
static fase_form_login_t fase_entrada; // Fase atual do formulário
static int ja_inicializado = 0; // Flag para controlar se o estado já foi inicializado

// Funções específicas deste estado
static int inicializar(void) {
    // Verifica se já foi inicializado antes - se sim, preserva o estado atual
    if (ja_inicializado) {
        return 0; // Sucesso, mas não reinicializa
    }
    
    // Primeira inicialização
    matricula = 0;
    memset(senha, 0, sizeof(senha));
    fase_entrada = ENTRADA_MATRICULA;
    ja_inicializado = 1; // Marca como inicializado
    
    printf(">> Digite sua matricula: ");
    return 0; // sucesso
}

static estado_aplicacao processar(size_t entrada) {
    // No estado de formulário, ignoramos o parâmetro entrada
    // e usamos diretamente a entrada do usuário
    
    switch(fase_entrada) {
        case ENTRADA_MATRICULA: // Lendo matrícula
            if (scanf("%d", &matricula) != 1) {
                // Limpar buffer de entrada
                while (getchar() != '\n');
                printf("Matrícula inválida! Tente novamente: ");
                return ESTADO_FORM_LOGIN; // permanece no mesmo estado
            }
            // Limpar buffer de entrada
            while (getchar() != '\n');
            fase_entrada = ENTRADA_SENHA;
            printf(">> Digite sua senha: ");
            return ESTADO_FORM_LOGIN; // permanece no mesmo estado
            
        case ENTRADA_SENHA: // Lendo senha
            scanf("%63s", senha);
            // Limpar buffer de entrada
            while (getchar() != '\n');
            fase_entrada = PROCESSAMENTO_AUTENTICACAO;
            // Processar autenticação agora
            if (autenticar(matricula, senha)) {
                ja_inicializado = 0; // Reseta o flag para o próximo uso
                return ESTADO_MSG_LOGIN_SUCESSO;
            } else {
                ja_inicializado = 0; // Reseta o flag para o próximo uso
                return ESTADO_MSG_LOGIN_FALHA;
            }
            
        case PROCESSAMENTO_AUTENTICACAO:
        default:
            // Fase inválida ou processamento concluído, voltar ao início do formulário
            ja_inicializado = 0; // Reseta o flag para o próximo uso
            return ESTADO_FORM_LOGIN;
    }
}

static void finalizar(void) {
    // Limpar dados sensíveis
    memset(senha, 0, sizeof(senha));
    // Não resetamos ja_inicializado aqui para preservar o estado entre chamadas
}

static estado_aplicacao obter_id(void) {
    return ESTADO_FORM_LOGIN;
}

estado_t* criar_estado_form_login(void) {
    estado_t* estado = (estado_t*) malloc(sizeof(estado_t));
    if (estado) {
        estado->inicializar = inicializar;
        estado->processar = processar;
        estado->finalizar = finalizar;
        estado->obter_id = obter_id;
    }
    return estado;
}