#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estados/funcionarios/estado_cadastro_funcionarios.h"
#include "ui/funcionarios/ui_tela_menu_cadastro_funcionarios.h"
#include "ui/ui_comum.h"
#include "estados/estado_menu_utils.h"
#include "session.h"


static int inicializar(void) {
    // Limpar a tela
    ui_limpar_tela();

    ui_exibir_titulo("EcoLógica Soluções Ambientais", "Cadastro de Funcionários");

    // Exibe painel de informações do funcionário logado
    funcionario_t *funcionario = get_funcionario_logado();
    if (funcionario) {
        char mat_str[32];
        snprintf(mat_str, sizeof(mat_str), "%d", funcionario->matricula);
        desenhar_painel_funcionario(funcionario->nome, mat_str);
    }

    // Desenhar cabeçalho padrão
    desenhar_cabecalho("MENU DE CADASTRO DE FUNCIONÁRIOS");
    
    printf("\n");

    return 0; // Sucesso
}

static estado_aplicacao processar(size_t entrada) {
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

