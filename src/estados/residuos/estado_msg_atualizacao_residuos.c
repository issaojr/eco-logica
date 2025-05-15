#include "estados/residuos/estado_msg_atualizacao_residuos.h"

static int inicializar(void) {
    // TODO: exibir mensagem de sucesso/erro da atualização
    return 0;
}

static estado_aplicacao processar(size_t entrada) {
    // após exibir a mensagem, retorna ao menu principal ou outro estado
    ui_exibir_to_do("[TODO] Implementar estado_msg_atualizacao_residuos.c");
    ui_pausar("Pressione ENTER para continuar...");
    return ESTADO_MENU_PRINCIPAL;  // ajuste conforme sua navegação
}

static void finalizar(void) {
    // TODO: limpar tela ou liberar recursos
}

static estado_aplicacao obter_id(void) {
    return ESTADO_MSG_ATUALIZACAO_RESIDUOS;  // adicione ao seu enum em estado.h
}

estado_t* criar_estado_msg_atualizacao_residuos(void) {
    estado_t *e = malloc(sizeof(estado_t));
    if (!e) return NULL;
    e->inicializar = inicializar;
    e->processar   = processar;
    e->finalizar   = finalizar;
    e->obter_id    = obter_id;
    return e;
}