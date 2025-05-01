#include <stdlib.h>
#include <stdio.h>
#include "estados/estado_msg_login_falha.h"

// Funções específicas deste estado
static int inicializar(void) {
    // Limpar a tela
    system("cls");
    
    printf("\n\n");
    puts("+================================================+");
    puts("|    Erro! Usuário ou Senha Inválidos            |");
    puts("+================================================+");
    
    printf("\nAs credenciais fornecidas não são válidas.");
    printf("\nVerifique sua matrícula e senha e tente novamente.");
    
    printf("\n\nPressione ENTER para voltar à tela de login...");
    
    // Aguarda o usuário pressionar ENTER
    getchar();
    
    return 0; // sucesso
}

static estado_aplicacao processar(size_t entrada) {
    // Este estado sempre transita para o menu de login após inicialização
    return ESTADO_MENU_LOGIN;
}

static void finalizar(void) {
    // Não há recursos específicos para liberar neste estado
}

static estado_aplicacao obter_id(void) {
    return ESTADO_MSG_LOGIN_FALHA;
}

estado_t* criar_estado_msg_login_falha(void) {
    estado_t* estado = (estado_t*) malloc(sizeof(estado_t));
    if (estado) {
        estado->inicializar = inicializar;
        estado->processar = processar;
        estado->finalizar = finalizar;
        estado->obter_id = obter_id;
    }
    return estado;
}