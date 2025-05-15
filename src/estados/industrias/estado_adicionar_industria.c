
#include "estados/industrias/estado_adicionar_industria.h"

/* fun��es internas do estado */
int inicializar(void) {
    return 0; // sucesso
}

estado_aplicacao processar(size_t entrada) {
    // Obter o funcion�rio logado
    funcionario_t *funcionario_autenticado = get_funcionario_logado();

    if (!funcionario_autenticado) {
        // [TODO] Criar estado de erro se n�o houver funcion�rio logado
        ui_exibir_erro("Nenhum funcion�rio logado. \nRedirecionando para a tela inicial..."); // [debug]
        ui_prompt_voltar_inicio("Pressione ENTER para continuar..."); // [debug]
        return ESTADO_MENU_LOGIN; // Redireciona para o login se n�o houver funcion�rio logado
    }

    ui_desenhar_tela_cadastro_industrias(
        funcionario_autenticado
    );

    industria_t *nova_industria = malloc(sizeof(industria_t));

    if (!nova_industria) {
        // [TODO] Criar estado de erro se n�o houver mem�ria dispon�vel
        ui_exibir_erro("Erro ao alocar mem�ria para nova ind�stria.");
        ui_prompt_voltar_inicio("Pressione ENTER para continuar...");
        return ESTADO_CADASTRO_INDUSTRIAS; // Retorna ao estado de cadastro de ind�strias
    }

    // Exibe o formul�rio de adicionar ind�stria
    ui_desenhar_form_adicionar_industria(nova_industria);

    /*
     * Regra de neg�cio:
     * Adicionar nova ind�stria
     */
    int resultado = adicionar_industria(nova_industria);

    free(nova_industria);

    if (resultado != 0) {
        // [TODO] Criar tela ui de erro se a adi��o falhar
        ui_exibir_erro("Erro ao adicionar nova ind�stria.");
        ui_prompt_voltar_inicio("Pressione ENTER para continuar...");
        return ESTADO_CADASTRO_INDUSTRIAS; // Retorna ao estado de cadastro de ind�strias
    }
    else {
        // [TODO] Criar tela ui de sucesso se a adi��o for bem-sucedida
        ui_exibir_sucesso("Ind�stria adicionada com sucesso.");
        ui_prompt_voltar_inicio("Pressione ENTER para continuar...");
    }
    return ESTADO_CADASTRO_INDUSTRIAS; 
}

void finalizar(void) {
    // TODO: liberar recursos alocados (se houver)
}

estado_aplicacao obter_id(void) {
    return ESTADO_ADICIONAR_INDUSTRIA;  
}

estado_t* criar_estado_adicionar_industria(void) {
    estado_t *estado = malloc(sizeof(estado_t));
    if (!estado) return NULL;

    estado->inicializar = inicializar;
    estado->processar   = processar;
    estado->finalizar   = finalizar;
    estado->obter_id    = obter_id;
    return estado;
}