#include "estados/login/estado_msg_login.h"

funcionario_t *funcionario_autenticado;

// Funções específicas deste estado
static int inicializar(void)
{
    return 0; // sucesso
}

static estado_aplicacao processar(size_t entrada)
{
    // Obter informações do usuário logado para personalizar a mensagem
    funcionario_autenticado = get_funcionario_logado();

    if (funcionario_autenticado)
    {
        // Desenha a tela de mensagem de login com sucesso
        ui_desenhar_tela_msg_login_sucesso(funcionario_autenticado->nome, funcionario_autenticado->matricula);
        return ESTADO_MENU_PRINCIPAL;
    }
    else
    {
        // Se não houver funcionário logado, exibe mensagem de falha
        ui_desenhar_tela_msg_login_falha();
        return ESTADO_MENU_LOGIN;
    }
}

static void finalizar(void)
{
    // Não há recursos específicos para liberar neste estado
}

static estado_aplicacao obter_id(void)
{
    return ESTADO_MSG_LOGIN;
}

estado_t *criar_estado_msg_login_sucesso(void)
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
