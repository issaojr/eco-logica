#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estados/industrias/estado_cadastro_industrias.h"
#include "ui/industrias/ui_tela_cadastro_industrias.h"
#include "ui/ui_comum.h"
#include "estados/estado_menu_utils.h"
#include "session.h"

/* fun��es internas do estado */
static int inicializar(void) {
    // Limpar a tela
    ui_limpar_tela();

    ui_exibir_titulo("EcoL�gica Solu��es Ambientais", "Cadastro de Ind�strias");

    // Exibe painel de informa��es do funcion�rio logado
    funcionario_t *funcionario = get_funcionario_logado();
    if (funcionario) {
        char mat_str[32];
        snprintf(mat_str, sizeof(mat_str), "%d", funcionario->matricula);
        ui_desenhar_painel_funcionario(funcionario->nome, mat_str);
    }

    // Desenhar cabe�alho padr�o
    ui_desenhar_cabecalho("MENU DE CADASTRO DE IND�STRIAS");

    printf("\n");

    return 0; // sucesso
}

static estado_aplicacao processar(size_t entrada) {
    return processar_estado_menu(
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