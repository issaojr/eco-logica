
#include "estados/login/estado_logout.h"


static int inicializar(void) {
    return 0;
}

static estado_aplicacao processar(size_t entrada) {
    // Limpar a sess�o do usu�rio
    logout();
    
    if(get_funcionario_logado() != NULL) {
        // Se o logout falhar, exibir mensagem de erro
        return ESTADO_MSG_LOGOUT_FALHA; // Retorna o estado de falha
    } 
    
    return ESTADO_MSG_LOGOUT_SUCESSO; // Retorna o estado de sucesso
}

static void finalizar(void) {
    // N�o h� recursos espec�ficos para liberar neste estado
}

static estado_aplicacao obter_id(void) {
    return ESTADO_LOGOUT;
}

estado_t* criar_estado_logout(void) {
    estado_t* estado = (estado_t*) malloc(sizeof(estado_t));
    if (estado) {
        estado->inicializar = inicializar;
        estado->processar = processar;
        estado->finalizar = finalizar;
        estado->obter_id = obter_id;
    }
    return estado;
}

// Fim do arquivo

