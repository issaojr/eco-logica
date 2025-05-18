#include "estados/relatorios/estado_relatorios_industria.h"

static int inicializar(void)
{
    return 0;
}

static estado_aplicacao processar(size_t entrada)
{
    // TODO: processar seleção de indústria e gerar relatório
    ui_exibir_to_do("[TODO] Implementar estado_relatorios_industria.c");
    ui_pausar("Pressione ENTER para continuar...");
    return ESTADO_MENU_PRINCIPAL;
}

static void finalizar(void)
{
    // TODO: liberar recursos (se houver)
}

static estado_aplicacao obter_id(void)
{
    return ESTADO_RELATORIOS_INDUSTRIA; // adicione ao seu enum em estado.h
}

estado_t *criar_estado_relatorios_industria(void)
{
    estado_t *e = malloc(sizeof(estado_t));
    if (!e)
        return NULL;
    e->inicializar = inicializar;
    e->processar = processar;
    e->finalizar = finalizar;
    e->obter_id = obter_id;
    return e;
}
