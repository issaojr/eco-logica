#include <stdlib.h>
#include <stdio.h>
#include "estados/estado_menu_principal.h"
#include "estados/estado_menu_utils.h"
#include "session.h"
#include "ui/ui_comum.h"
#include "ui/ui_tela_menu_principal.h"

// Fun��es espec�ficas deste estado
static int inicializar(void) {
    // Limpar a tela
    ui_limpar_tela();

    ui_exibir_titulo("EcoL�gica Solu��es Ambientais", "Sistema de Gest�o Ambiental");
    
    // Exibe painel de informa��es do funcion�rio logado
    funcionario_t *funcionario = get_funcionario_logado();
    if (funcionario) {
        char mat_str[32];
        snprintf(mat_str, sizeof(mat_str), "%d", funcionario->matricula);
        desenhar_painel_funcionario(funcionario->nome, mat_str);
    }

    // Desenhar cabe�alho padr�o
    desenhar_cabecalho("MENU PRINCIPAL");
    
    printf("\n");
    
    return 0; // sucesso
}

static estado_aplicacao processar(size_t entrada) {
    // Usar a fun��o utilit�ria para processar o menu
    return processar_estado_menu(
        tela_menu_principal_mapa,
        tela_menu_principal_mapa_n,
        tela_menu_principal_prompt,
        ESTADO_MENU_PRINCIPAL
    );
}

static void finalizar(void) {
    // N�o h� recursos espec�ficos para liberar neste estado
}

static estado_aplicacao obter_id(void) {
    return ESTADO_MENU_PRINCIPAL;
}

estado_t* criar_estado_menu_principal(void) {
    estado_t* estado = (estado_t*) malloc(sizeof(estado_t));

    if (!estado) {
        return NULL; // Falha ao alocar mem�ria
    }

    if (estado) {
        estado->inicializar = inicializar;
        estado->processar = processar;
        estado->finalizar = finalizar;
        estado->obter_id = obter_id;
    }
    return estado;
}