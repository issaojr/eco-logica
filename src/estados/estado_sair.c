#include "estados/estado_sair.h"

static int inicializar(void)
{
    return 0;
}

static estado_aplicacao processar(size_t entrada)
{
    ui_desenhar_tela_sair();

    return ESTADO_SAIR;
}

static void finalizar(void)
{
    return;
}

static estado_aplicacao obter_id(void)
{
    return ESTADO_SAIR;
}

estado_t *criar_estado_sair(void)
{
    estado_t *estado = (estado_t*)malloc(sizeof(estado_t));
    if (estado)
    {
        estado->inicializar = inicializar;
        estado->processar = processar;
        estado->finalizar = finalizar;
        estado->obter_id = obter_id;
    }
    return estado;
}
