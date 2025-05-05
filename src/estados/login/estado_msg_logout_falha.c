#include <stdlib.h>
#include <stdio.h>
#include "estados/login/estado_msg_logout_falha.h"
#include "ui/ui_comum.h"
#include "session.h"

// Funções específicas deste estado
static int inicializar(void) {
    // Exibir título e mensagem de erro usando nossos componentes de UI
    ui_exibir_titulo("Erro no Logout", "Falha durante o logout");
    
    ui_exibir_erro("Logout não realizado! Tente novamente.");
    
    // Usar nosso componente para pausar e aguardar o ENTER
    ui_prompt_voltar_menu_principal(NULL);
    
    return 0; // sucesso
}

static estado_aplicacao processar(size_t entrada) {
    // Este estado sempre transita para o menu de login após inicialização
    return ESTADO_MENU_PRINCIPAL;
}

static void finalizar(void) {
    // Não há recursos específicos para liberar neste estado
}

static estado_aplicacao obter_id(void) {
    return ESTADO_MSG_LOGOUT_FALHA;
}

estado_t* criar_estado_msg_logout_falha(void) {
    estado_t* estado = (estado_t*) malloc(sizeof(estado_t));
    if (estado) {
        estado->inicializar = inicializar;
        estado->processar = processar;
        estado->finalizar = finalizar;
        estado->obter_id = obter_id;
    }
    return estado;
}