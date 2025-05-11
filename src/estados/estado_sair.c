#include <stdlib.h>
#include <stdio.h>
#include "estados/estado_sair.h"
#include "ui/ui_tela_sair.h"
#include "session.h"

// Funções específicas deste estado
static int inicializar(void) {
    // [TODO] Apresentar tela de encerramento
    printf("DEBUG: Tela de saída\n");
    getchar(); // Aguarda o usuário pressionar uma tecla
    return 0; // sucesso
}

static estado_aplicacao processar(size_t entrada) {
    // esvaziar a sessão
    //logout();

    // Desenhar tela de saída
    printf("DEBUG: Tela de saída\n");
    getchar(); // Aguarda o usuário pressionar uma tecla
    ui_desenhar_tela_sair();


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