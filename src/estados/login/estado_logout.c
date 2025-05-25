
#include "estados/login/estado_logout.h"

static int inicializar(void)
{
    return 0;
}

static estado_aplicacao processar(size_t entrada)
{
    // Limpar a sessão do usuário
    logout();

    if (get_funcionario_logado() != NULL)
    {
        ui_desenhar_tela_erro("LOGOUT FALHOU", "Erro ao desconectar o usuário.");
        return ESTADO_MENU_PRINCIPAL; 
    }

    // Desenhar a tela de logout
    ui_desenhar_tela_sucesso("LOGOUT REALIZADO", "Você foi desconectado com sucesso.");
    return ESTADO_MENU_LOGIN; // Redireciona para o menu de login

}

static void finalizar(void)
{
    // Não há recursos específicos para liberar neste estado
}

static estado_aplicacao obter_id(void)
{
    return ESTADO_LOGOUT;
}

estado_t *criar_estado_logout(void)
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

// Fim do arquivo
