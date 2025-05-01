#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "estados/estado_form_login.h"
#include "auth.h"
#include "ui/ui_comum.h"
#include "ui/ui_formulario.h"

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

// Fun��o auxiliar para ler senha de forma robusta (baseada no c�digo deprecated)
static void ler_senha_segura(const char* prompt, char* senha_buffer, size_t tamanho) {
    while (1) {
        printf("%s", prompt);
        
        // L� a entrada como string
        if (fgets(senha_buffer, tamanho, stdin) == NULL) {
            printf("Erro na leitura da senha. Tente novamente.\n");
            continue;
        }
        
        // Remove o '\n' da entrada
        senha_buffer[strcspn(senha_buffer, "\n")] = '\0';
        
        // Verifica se a senha n�o est� vazia
        if (strlen(senha_buffer) == 0) {
            printf("Senha n�o pode ficar vazia. Tente novamente.\n");
            continue;
        }
        
        return; // Senha v�lida lida com sucesso
    }
}

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
    
    // Exibe o t�tulo de login usando o componente padronizado
    ui_exibir_titulo("Login do Sistema", "Informe seus dados de acesso");
    
    return 0; // sucesso
}

static estado_aplicacao processar(size_t entrada) {
    // No estado de formul�rio, ignoramos o par�metro entrada
    // e usamos diretamente a entrada do usu�rio
    
    switch(fase_entrada) {
        case ENTRADA_MATRICULA: {
            // Usar o componente de UI para ler a matr�cula
            char buffer[20];
            printf("Digite sua matr�cula: ");
            if (ui_ler_string(NULL, buffer, sizeof(buffer), true)) {
                // Converter para inteiro
                char* endptr;
                matricula = strtol(buffer, &endptr, 10);
                
                // Verificar se a convers�o foi bem-sucedida
                if (*endptr != '\0' || matricula <= 0) {
                    ui_exibir_erro("Matr�cula inv�lida. Digite apenas n�meros.");
                    return ESTADO_FORM_LOGIN; // permanece no mesmo estado
                }
                
                fase_entrada = ENTRADA_SENHA;
                printf("\n");
                
                return ESTADO_FORM_LOGIN; // permanece no mesmo estado
            } else {
                ui_exibir_erro("Entrada inv�lida");
                return ESTADO_FORM_LOGIN;
            }
        }
            
        case ENTRADA_SENHA: {
            // Usar nossa fun��o auxiliar para ler a senha de forma robusta
            ler_senha_segura("Digite sua senha: ", senha, sizeof(senha));
            fase_entrada = PROCESSAMENTO_AUTENTICACAO;
            return ESTADO_FORM_LOGIN; // permanece no mesmo estado
        }
            
        case PROCESSAMENTO_AUTENTICACAO:
            // Processar autentica��o agora
            if (autenticar(matricula, senha)) {
                ja_inicializado = 0; // Reseta o flag para o pr�ximo uso
                return ESTADO_MSG_LOGIN_SUCESSO;
            } else {
                ja_inicializado = 0; // Reseta o flag para o pr�ximo uso
                return ESTADO_MSG_LOGIN_FALHA;
            }
            
        default:
            // Fase inv�lida, voltar ao in�cio do formul�rio
            ja_inicializado = 0; // Reseta o flag para o pr�ximo uso
            return ESTADO_FORM_LOGIN;
    }
}

static void finalizar(void) {
    // A limpeza da senha feita ao reinicializar o estado (ja_inicializado = 0)
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