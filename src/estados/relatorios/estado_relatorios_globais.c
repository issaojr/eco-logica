#include <stdlib.h>
#include "estados/relatorios/estado_relatorios_globais.h"

static int inicializar(void) {
    // TODO: limpar tela, exibir título “Relatórios Globais”, etc.
    return 0;
}

static estado_aplicacao processar(size_t entrada) {
    // TODO: processar opções de relatório
    puts("[TODO] Implementar estado_relatorios_globais.c");
    ui_pausar("Pressione ENTER para continuar...");
    return ESTADO_MENU_PRINCIPAL;
}

static void finalizar(void) {
    // TODO: liberar recursos (se houver)
}

static estado_aplicacao obter_id(void) {
    return ESTADO_RELATORIOS_GLOBAIS;  // adicione ao seu enum em estado.h
}

estado_t* criar_estado_relatorios_globais(void) {
    estado_t *e = malloc(sizeof(estado_t));
    if (!e) return NULL;
    e->inicializar = inicializar;
    e->processar   = processar;
    e->finalizar   = finalizar;
    e->obter_id    = obter_id;
    return e;
}