#include "estados/login/estado_msg_logout_falha.h"


// Fun��es espec�ficas deste estado
static int inicializar(void) {
    
    return 0; // sucesso
}

static estado_aplicacao processar(size_t entrada) {
    // Desenha a tela de mensagem de logout falha
    ui_desenhar_tela_msg_logout_falha();
    return ESTADO_MENU_PRINCIPAL;
}

static void finalizar(void) {
    // N�o h� recursos espec�ficos para liberar neste estado
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