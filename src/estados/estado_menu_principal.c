#include "estados/estado_menu_principal.h"


static int inicializar(void)
{
    return 0; 
}

static estado_aplicacao processar(size_t entrada)
{
    funcionario_t *funcionario_autenticado = get_funcionario_logado();
    if (!funcionario_autenticado)
    {
        ui_exibir_erro("Nenhum funcionário logado. \nRedirecionando para a tela inicial...");
        ui_prompt_voltar_inicio("Pressione ENTER para continuar...");
        return ESTADO_MENU_LOGIN;
    }

    
    ui_desenhar_tela_menu_principal(
        funcionario_autenticado->nome,
        funcionario_autenticado->matricula);

    /* Desenhar cabecalho de menu principal */
    ui_desenhar_cabecalho_menu_principal();

    
    return estado_processar_estado_menu(
        tela_menu_principal_mapa,
        tela_menu_principal_mapa_n,
        tela_menu_principal_prompt,
        ESTADO_MENU_PRINCIPAL);
}

static void finalizar(void)
{
    
}

static estado_aplicacao obter_id(void)
{
    return ESTADO_MENU_PRINCIPAL;
}

estado_t *criar_estado_menu_principal(void)
{
    estado_t *estado = (estado_t*)malloc(sizeof(estado_t));

    if (!estado)
    {
        return NULL; 
    }

    if (estado)
    {
        estado->inicializar = inicializar;
        estado->processar = processar;
        estado->finalizar = finalizar;
        estado->obter_id = obter_id;
    }
    return estado;
}
