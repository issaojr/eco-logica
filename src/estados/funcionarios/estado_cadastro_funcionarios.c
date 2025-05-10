#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estados/funcionarios/estado_cadastro_funcionarios.h"
#include "ui/funcionarios/ui_tela_menu_cadastro_funcionarios.h"
#include "ui/ui_comum.h"
#include "estados/estado_menu_utils.h"
#include "session.h"

funcionario_t *funcionario_autenticado;

static int inicializar(void) {
    // Obter o funcionário logado
    funcionario_autenticado = get_funcionario_logado();

    return 0; // Sucesso
}

static estado_aplicacao processar(size_t entrada) {
    if (!funcionario_autenticado) {
        // [TODO] Criar estado de erro se não houver funcionário logado
        ui_exibir_erro("Nenhum funcionário logado. \nRedirecionando para a tela inicial..."); // [debug]
        ui_prompt_voltar_inicio("Pressione ENTER para continuar..."); // [debug]
        return ESTADO_MENU_LOGIN; // Redireciona para o login se não houver funcionário logado
    }

    // Desenhar tela de menu de cadastro de funcionários
    ui_desenhar_tela_menu_cadastro_funcionarios(
        funcionario_autenticado->nome,
        funcionario_autenticado->matricula
    );
    
    return processar_estado_menu(
        tela_menu_cadastro_funcionarios_mapa,
        tela_menu_cadastro_funcionarios_mapa_n,
        tela_menu_cadastro_funcionarios_prompt,
        ESTADO_CADASTRO_FUNCIONARIOS
    );
}


static void finalizar(void) {
    // Não há recursos específicos para liberar neste estado
}

static estado_aplicacao obter_id(void) {
    return ESTADO_CADASTRO_FUNCIONARIOS;
}

estado_t* criar_estado_cadastro_funcionarios(void) {
    estado_t *estado = malloc(sizeof(estado_t));
    
    if (!estado) {
        return NULL; // Falha ao alocar memória
    }
    
    estado->inicializar = inicializar;
    estado->processar = processar;
    estado->finalizar = finalizar;
    estado->obter_id = obter_id;
    
    return estado;
}

