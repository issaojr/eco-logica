#include "estados/estado_menu_principal.h"

funcionario_t *funcionario_autenticado;

// Funções específicas deste estado
static int inicializar(void) {
    // Obter o funcionário logado
    funcionario_autenticado = get_funcionario_logado();

    return 0; // sucesso
}

static estado_aplicacao processar(size_t entrada) {
    if (!funcionario_autenticado) {
        // [TODO] Criar estado de erro se não houver funcionário logado
        ui_exibir_erro("Nenhum funcionário logado. \nRedirecionando para a tela inicial..."); // [debug]
        ui_prompt_voltar_inicio("Pressione ENTER para continuar..."); // [debug]
        return ESTADO_MENU_LOGIN; // Redireciona para o login se não houver funcionário logado
    }

    // Desenhar tela de menu principal
    ui_desenhar_tela_menu_principal(
        funcionario_autenticado->nome,
        funcionario_autenticado->matricula
    );

    /* Desenhar cabecalho de menu principal */
    ui_desenhar_cabecalho_menu_principal();

    // Usar a função utilitária para processar o menu
    return estado_processar_estado_menu(
        tela_menu_principal_mapa,
        tela_menu_principal_mapa_n,
        tela_menu_principal_prompt,
        ESTADO_MENU_PRINCIPAL
    );
}

static void finalizar(void) {
    // Não há recursos específicos para liberar neste estado
}

static estado_aplicacao obter_id(void) {
    return ESTADO_MENU_PRINCIPAL;
}

estado_t* criar_estado_menu_principal(void) {
    estado_t* estado = (estado_t*) malloc(sizeof(estado_t));

    if (!estado) {
        return NULL; // Falha ao alocar memória
    }

    if (estado) {
        estado->inicializar = inicializar;
        estado->processar = processar;
        estado->finalizar = finalizar;
        estado->obter_id = obter_id;
    }
    return estado;
}