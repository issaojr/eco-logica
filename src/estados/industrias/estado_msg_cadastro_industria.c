#include "estados/industrias/estado_msg_cadastro_industria.h"

/* funções internas do estado */
static int inicializar(void)
{
    return 0; // sucesso
}

static estado_aplicacao processar(size_t entrada)
{
    puts("[TODO] Implementar estado_msg_cadastro_industria()");
    ui_pausar("Pressione ENTER para continuar...");
    return ESTADO_CADASTRO_INDUSTRIAS;
}

static void finalizar(void)
{
    // TODO: liberar recursos alocados (se houver)
}

static estado_aplicacao obter_id(void)
{
    return ESTADO_MSG_CADASTRO_INDUSTRIA;
}

estado_t *criar_estado_msg_cadastro_industria(void)
{
    estado_t *estado = malloc(sizeof(estado_t));
    if (!estado)
        return NULL;

    estado->inicializar = inicializar;
    estado->processar = processar;
    estado->finalizar = finalizar;
    estado->obter_id = obter_id;
    return estado;
}