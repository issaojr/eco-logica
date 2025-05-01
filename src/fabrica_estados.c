#include <stdlib.h>
#include "estado.h"
#include "fabrica_estados.h"

// Incluir cabeçalhos dos estados implementados
#include "estados/estado_menu_login.h"
#include "estados/estado_form_login.h"
#include "estados/estado_menu_principal.h"
#include "estados/estado_msg_login_sucesso.h"
#include "estados/estado_msg_login_falha.h"
#include "estados/estado_sair.h"

/**
 * Implementação da fábrica de estados
 */
estado_t* criar_estado(estado_aplicacao id) {
    switch (id) {
        case ESTADO_MENU_LOGIN:
            return criar_estado_menu_login();
        case ESTADO_FORM_LOGIN:
            return criar_estado_form_login();
        case ESTADO_SOBRE_PROJETO:
            return criar_estado_sobre_projeto();
        case ESTADO_MSG_LOGIN_SUCESSO:
            return criar_estado_msg_login_sucesso();
        case ESTADO_MSG_LOGIN_FALHA:
            return criar_estado_msg_login_falha();
        case ESTADO_MSG_LOGOUT_SUCESSO:
            return criar_estado_msg_logout_sucesso();
        case ESTADO_MENU_PRINCIPAL:
            return criar_estado_menu_principal();
        case ESTADO_CADASTRO_FUNCIONARIO:
            return criar_estado_cadastro_funcionario();
        case ESTADO_MSG_CADASTRO_FUNCIONARIO:
            return criar_estado_msg_cadastro_funcionario();
        case ESTADO_CADASTRO_INDUSTRIA:
            return criar_estado_cadastro_industria();
        case ESTADO_MSG_CADASTRO_INDUSTRIA:
            return criar_estado_msg_cadastro_industria();
        case ESTADO_ATUALIZACAO_RESIDUOS:
            return criar_estado_atualizacao_residuos();
        case ESTADO_MSG_ATUALIZACAO_RESIDUOS:
            return criar_estado_msg_atualizacao_residuos();
        case ESTADO_RELATORIOS_INDUSTRIA:
            return criar_estado_relatorios_industria();
        case ESTADO_SUBMENU_RELATORIOS_GLOBAIS:
            return criar_estado_submenu_relatorios_globais();
        case ESTADO_REL_GLOBAIS_INS_TOT:
            return criar_estado_rel_globais_ins_tot();
        case ESTADO_REL_GLOBAIS_TOTAL_GASTOS:
            return criar_estado_rel_globais_total_gastos();
        case ESTADO_REL_GLOBAIS_REGIAO_MAIOR:
            return criar_estado_rel_globais_regiao_maior();
        case ESTADO_REL_GLOBAIS_IND_MENOR:
            return criar_estado_rel_globais_ind_menor();
        case ESTADO_REL_GLOBAIS_APORTE_FINANCEIRO:
            return criar_estado_rel_globais_aporte_financeiro();
        case ESTADO_SAIR:
            return criar_estado_sair();
        default:
            return NULL;
    }
}

/**
 * Implementação do destrutor de estados
 */
void destruir_estado(estado_t* estado) {
    if (estado) {
        // Chamar a função de finalização do estado, se existir
        if (estado->finalizar) {
            estado->finalizar();
        }
        free(estado);
    }
}