#include "estados/industrias/estado_msg_operacao_industria.h"

/* fun��es internas do estado */
static int inicializar(void) {
    // TODO: limpar tela, exibir t�tulo, etc.
    return 0; // sucesso
}

static estado_aplicacao processar(size_t entrada) {
    puts("[TODO] Implementar estado_msg_operacao_industria()");
    ui_pausar("Pressione ENTER para continuar...");
    return ESTADO_CADASTRO_INDUSTRIAS; 
}

static void finalizar(void) {
    // TODO: liberar recursos alocados (se houver)
}

static estado_aplicacao obter_id(void) {
    return ESTADO_MSG_OPERACAO_INDUSTRIA;  
}

estado_t* criar_estado_msg_operacao_industria(void) {
    estado_t *estado = malloc(sizeof(estado_t));
    if (!estado) return NULL;

    estado->inicializar = inicializar;
    estado->processar   = processar;
    estado->finalizar   = finalizar;
    estado->obter_id    = obter_id;
    return estado;
}