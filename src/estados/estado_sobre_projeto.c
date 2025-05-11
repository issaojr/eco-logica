#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "estados/estado_sobre_projeto.h"
#include "ui/ui_tela_sobre_projeto.h"
#include "estados/estado_menu_utils.h"
#include "ui/ui_comum.h"

// Funções específicas deste estado
static int inicializar(void) {
    
    return 0; // sucesso
}

static estado_aplicacao processar(size_t entrada) {
    ui_desenhar_tela_sobre_projeto();
    return ESTADO_MENU_LOGIN;
}

static void finalizar(void) {
    // Não há recursos específicos para liberar neste estado
}

static estado_aplicacao obter_id(void) {
    return ESTADO_SOBRE_PROJETO;
}

estado_t* criar_estado_sobre_projeto(void) {
    estado_t* estado = (estado_t*) malloc(sizeof(estado_t));
    if (estado) {
        estado->inicializar = inicializar;
        estado->processar = processar;
        estado->finalizar = finalizar;
        estado->obter_id = obter_id;
    }
    return estado;
}
