
#include "estados/login/estado_logout.h"

static int inicializar(void)
{
    return 0;
}

static estado_aplicacao processar(size_t entrada)
{
    
    logout();

    if (get_funcionario_logado() != NULL)
    {
        ui_desenhar_tela_erro("LOGOUT FALHOU", "Erro ao desconectar o usuário.");
        return ESTADO_MENU_PRINCIPAL; 
    }

    
    ui_desenhar_tela_sucesso("LOGOUT REALIZADO", "Você foi desconectado com sucesso.");
    return ESTADO_MENU_LOGIN; 

}

static void finalizar(void)
{
    
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


