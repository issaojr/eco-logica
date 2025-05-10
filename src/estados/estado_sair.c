#include <stdlib.h>
#include "estados/estado_sair.h"

// Funções específicas deste estado
static int inicializar(void) {
    // [TODO] Apresentar tela de encerramento
    return 0; // sucesso
}

static estado_aplicacao processar(size_t entrada) {
    // Este estado sempre retorna ele mesmo, garantindo a saída do programa
    return ESTADO_SAIR;
}

static void finalizar(void) {
    // Não há recursos para liberar neste estado
}

static estado_aplicacao obter_id(void) {
    return ESTADO_SAIR;
}

estado_t* criar_estado_sair(void) {
    estado_t* estado = (estado_t*) malloc(sizeof(estado_t));
    if (estado) {
        estado->inicializar = inicializar;
        estado->processar = processar;
        estado->finalizar = finalizar;
        estado->obter_id = obter_id;
    }
    return estado;
}