#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estados/funcionarios/estado_msg_cadastro_funcionario.h"
#include "ui/ui_comum.h"

/* funções internas do estado */
static int inicializar(void) {
    // TODO: limpar tela, exibir título, etc.
    return 0; // sucesso
}

static estado_aplicacao processar(size_t entrada) {
    puts("[TODO] Implementar estado_msg_cadastro_funcionario()");
    ui_pausar("Pressione ENTER para continuar...");
    return ESTADO_CADASTRO_FUNCIONARIOS; 
}

static void finalizar(void) {
    // TODO: liberar recursos alocados (se houver)
}

static estado_aplicacao obter_id(void) {
    return ESTADO_MSG_CADASTRO_FUNCIONARIO;  
}

estado_t* criar_estado_msg_cadastro_funcionario(void) {
    estado_t *estado = malloc(sizeof(estado_t));
    if (!estado) return NULL;

    estado->inicializar = inicializar;
    estado->processar   = processar;
    estado->finalizar   = finalizar;
    estado->obter_id    = obter_id;
    return estado;
}