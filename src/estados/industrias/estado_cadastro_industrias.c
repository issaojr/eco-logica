#include "estados/industrias/estado_cadastro_industrias.h"

funcionario_t *funcionario_autenticado;

/* funções internas do estado */
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

    // Desenhar tela de menu de cadastro de indústrias
    ui_desenhar_tela_cadastro_industrias(
        funcionario_autenticado
    );

    return estado_processar_estado_menu(
        tela_menu_cadastro_industrias_mapa,
        tela_menu_cadastro_industrias_mapa_n,
        tela_menu_cadastro_industrias_prompt,
        ESTADO_CADASTRO_INDUSTRIAS
    );
}

static void finalizar(void) {
    // TODO: liberar recursos alocados (se houver)
}

static estado_aplicacao obter_id(void) {
    return ESTADO_CADASTRO_INDUSTRIAS;  
}

estado_t* criar_estado_cadastro_industrias(void) {
    estado_t *estado = malloc(sizeof(estado_t));
    if (!estado) return NULL;

    estado->inicializar = inicializar;
    estado->processar   = processar;
    estado->finalizar   = finalizar;
    estado->obter_id    = obter_id;
    return estado;
}