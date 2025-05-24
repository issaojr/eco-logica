#include "estados/login/estado_menu_login.h"

funcionario_t *funcionario_autenticado;

// Funções específicas deste estado
static int inicializar(void)
{
    // Obter o funcionário logado
    funcionario_autenticado = get_funcionario_logado();

    return 0; // sucesso
}

static estado_aplicacao processar(size_t entrada)
{
    if (funcionario_autenticado)
    {
        return ESTADO_MENU_PRINCIPAL; // Redireciona para o menu principal se já estiver logado
    }

    ui_desenhar_tela_menu_login();

    // Usar a função utilitária para processar o menu
    return estado_processar_estado_menu(
        tela_menu_login_mapa,
        tela_menu_login_mapa_n,
        tela_menu_login_prompt,
        ESTADO_MENU_LOGIN);
}

static void finalizar(void)
{
    // Não há recursos específicos para liberar neste estado
}

static estado_aplicacao obter_id(void)
{
    return ESTADO_MENU_LOGIN;
}

estado_t *criar_estado_menu_login(void)
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
