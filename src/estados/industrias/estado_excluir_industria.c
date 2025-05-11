#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estados/industrias/estado_excluir_industria.h"
#include "ui/industrias/ui_tela_cadastro_industrias.h"
#include "ui/ui_comum.h"

/* fun��es internas do estado */
static int inicializar(void) {
    // TODO: limpar tela, exibir t�tulo, etc.
    return 0; // sucesso
}

static estado_aplicacao processar(size_t entrada) {
    ui_exibir_form_excluir_industria(); // exibe o formul�rio de excluir ind�stria
    return ESTADO_CADASTRO_INDUSTRIAS; 
}

static void finalizar(void) {
    // TODO: liberar recursos alocados (se houver)
}

static estado_aplicacao obter_id(void) {
    return ESTADO_EXCLUIR_INDUSTRIA;  
}

estado_t* criar_estado_excluir_industria(void) {
    estado_t *estado = malloc(sizeof(estado_t));
    if (!estado) return NULL;

    estado->inicializar = inicializar;
    estado->processar   = processar;
    estado->finalizar   = finalizar;
    estado->obter_id    = obter_id;
    return estado;
}