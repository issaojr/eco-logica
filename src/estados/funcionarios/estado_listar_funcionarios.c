#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estados/funcionarios/estado_listar_funcionarios.h"
#include "ui/funcionarios/ui_lista_funcionarios.h"
#include "ui/ui_comum.h"

/* fun��es internas do estado */
static int inicializar(void) {
    // TODO: limpar tela, exibir t�tulo, etc.
    return 0; // sucesso
}

static estado_aplicacao processar(size_t entrada) {
    ui_exibir_lista_funcionarios(); // Exibe a lista de funcion�rios cadastrados
    return ESTADO_CADASTRO_FUNCIONARIOS; 
}

static void finalizar(void) {
    // TODO: liberar recursos alocados (se houver)
}

static estado_aplicacao obter_id(void) {
    return ESTADO_LISTAR_FUNCIONARIOS;  
}

estado_t* criar_estado_listar_funcionarios(void) {
    estado_t *estado = malloc(sizeof(estado_t));
    if (!estado) return NULL;

    estado->inicializar = inicializar;
    estado->processar   = processar;
    estado->finalizar   = finalizar;
    estado->obter_id    = obter_id;
    return estado;
}