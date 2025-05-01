#include <stdlib.h>
#include <stdio.h>
#include "estados/estado_msg_login_falha.h"
#include "ui/ui_comum.h"

// Funções específicas deste estado
static int inicializar(void) {
    // Exibir título e mensagem de erro usando nossos componentes de UI
    ui_exibir_titulo("Falha na Autenticação", "Não foi possível realizar o login");
    
    ui_exibir_erro("Usuário ou senha inválidos!");
    
    printf("\nAs credenciais fornecidas não são válidas.");
    printf("\nVerifique sua matrícula e senha e tente novamente.\n\n");
    
    // Usar nosso componente para pausar e aguardar o ENTER
    ui_pausar(NULL);
    
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