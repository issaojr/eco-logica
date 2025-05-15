#include "estados/login/estado_msg_logout_sucesso.h"

// Funções específicas deste estado
static int inicializar(void) {
    
    return 0; // sucesso
}

static estado_aplicacao processar(size_t entrada) {
    ui_desenhar_msg_logout_sucesso();
    return ESTADO_MENU_LOGIN;
}

static void finalizar(void) {
    // Não há recursos específicos para liberar neste estado
}

static estado_aplicacao obter_id(void) {
    return ESTADO_MSG_LOGOUT_SUCESSO;
}

estado_t* criar_estado_msg_logout_sucesso(void) {
    estado_t* estado = (estado_t*) malloc(sizeof(estado_t));
    if (estado) {
        estado->inicializar = inicializar;
        estado->processar = processar;
        estado->finalizar = finalizar;
        estado->obter_id = obter_id;
    }
    return estado;
}