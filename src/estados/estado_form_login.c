#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "estados/estado_form_login.h"
#include "auth.h"

// Defini��o de tipos para tornar o c�digo mais sem�ntico
typedef enum {
    ENTRADA_MATRICULA,
    ENTRADA_SENHA,
    PROCESSAMENTO_AUTENTICACAO
} fase_form_login_t;

// Vari�veis espec�ficas deste estado
static int matricula;
static char senha[64];
static fase_form_login_t fase_entrada; // Fase atual do formul�rio
static int ja_inicializado = 0; // Flag para controlar se o estado j� foi inicializado

// Fun��es espec�ficas deste estado
static int inicializar(void) {
    // Verifica se j� foi inicializado antes - se sim, preserva o estado atual
    if (ja_inicializado) {
        return 0; // Sucesso, mas n�o reinicializa
    }
    
    // Primeira inicializa��o
    matricula = 0;
    memset(senha, 0, sizeof(senha));
    fase_entrada = ENTRADA_MATRICULA;
    ja_inicializado = 1; // Marca como inicializado
    
    printf(">> Digite sua matricula: ");
    return 0; // sucesso
}

static estado_aplicacao processar(size_t entrada) {
    // No estado de formul�rio, ignoramos o par�metro entrada
    // e usamos diretamente a entrada do usu�rio
    
    switch(fase_entrada) {
        case ENTRADA_MATRICULA: // Lendo matr�cula
            if (scanf("%d", &matricula) != 1) {
                // Limpar buffer de entrada
                while (getchar() != '\n');
                printf("Matr�cula inv�lida! Tente novamente: ");
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
            // Processar autentica��o agora
            if (autenticar(matricula, senha)) {
                ja_inicializado = 0; // Reseta o flag para o pr�ximo uso
                return ESTADO_MSG_LOGIN_SUCESSO;
            } else {
                ja_inicializado = 0; // Reseta o flag para o pr�ximo uso
                return ESTADO_MSG_LOGIN_FALHA;
            }
            
        case PROCESSAMENTO_AUTENTICACAO:
        default:
            // Fase inv�lida ou processamento conclu�do, voltar ao in�cio do formul�rio
            ja_inicializado = 0; // Reseta o flag para o pr�ximo uso
            return ESTADO_FORM_LOGIN;
    }
}

static void finalizar(void) {
    // Limpar dados sens�veis
    memset(senha, 0, sizeof(senha));
    // N�o resetamos ja_inicializado aqui para preservar o estado entre chamadas
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