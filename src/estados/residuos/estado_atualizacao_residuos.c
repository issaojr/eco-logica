#include <stdlib.h>
#include "estados/residuos/estado_atualizacao_residuos.h"

static int inicializar(void) {
    // TODO: limpar tela, exibir título “Atualização de Resíduos”, etc.
    return 0;
}

static estado_aplicacao processar(size_t entrada) {
    // TODO: processar dados coletados e atualizar resíduos
    puts("[TODO] Implementar estado_atualizacao_residuos.c");
    ui_pausar("Pressione ENTER para continuar...");
    return ESTADO_MENU_PRINCIPAL;
}

static void finalizar(void) {
    // TODO: liberar recursos (se houver)
}

static estado_aplicacao obter_id(void) {
    return ESTADO_ATUALIZACAO_RESIDUOS;  // adicione ao seu enum em estado.h
}

estado_t* criar_estado_atualizacao_residuos(void) {
    estado_t *e = malloc(sizeof(estado_t));
    if (!e) return NULL;
    e->inicializar = inicializar;
    e->processar   = processar;
    e->finalizar   = finalizar;
    e->obter_id    = obter_id;
    return e;
}