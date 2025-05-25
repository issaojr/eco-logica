#include "estados/estados.h"
#include "ui/ui_comum.h"

#define UNUSED(x) (void)(x)

/*
 * Tabela de transições:
 *   transicoes[estado_atual][índice_da_opcao] = próximo_estado
 *
 * Cada linha foi inicializada com designated initializers. Se você passar um índice
 * maior que o número de opções válidas para aquele menu, obter_proximo_estado()
 * retornará o próprio estado_atual (fallback seguro).
 */
const estado_aplicacao transicoes[][MAX_OPCOES_MENU] = {
    [ESTADO_MENU_LOGIN] = {
        [0] = ESTADO_FORM_LOGIN,
        [1] = ESTADO_SOBRE_PROJETO,
        [2] = ESTADO_SAIR
    },

    [ESTADO_SOBRE_PROJETO] = {[0] = ESTADO_MENU_LOGIN},

    [ESTADO_FORM_LOGIN] = {[0] = ESTADO_MSG_LOGIN, [1] = ESTADO_MSG_LOGIN_FALHA},

    [ESTADO_MSG_LOGIN] = {[0] = ESTADO_MENU_PRINCIPAL},

    [ESTADO_MSG_LOGIN_FALHA] = {[0] = ESTADO_MENU_LOGIN},

    [ESTADO_MSG_LOGOUT_SUCESSO] = {[0] = ESTADO_MENU_LOGIN},

    [ESTADO_MENU_PRINCIPAL] = {
        [0] = ESTADO_CADASTRO_FUNCIONARIOS, [1] = ESTADO_CADASTRO_INDUSTRIAS, [2] = ESTADO_ATUALIZACAO_RESIDUOS,
        [3] = ESTADO_RELATORIOS_INDUSTRIA, [4] = ESTADO_RELATORIOS_GLOBAIS, [5] = ESTADO_LOGOUT
    },

    [ESTADO_CADASTRO_FUNCIONARIOS] = {
        [0] = ESTADO_LISTAR_FUNCIONARIOS, [1] = ESTADO_ADICIONAR_FUNCIONARIO, [2] = ESTADO_EDITAR_FUNCIONARIO,
        [3] = ESTADO_EXCLUIR_FUNCIONARIO, [4] = ESTADO_MENU_PRINCIPAL
    },

    [ESTADO_LISTAR_FUNCIONARIOS] = {[0] = ESTADO_CADASTRO_FUNCIONARIOS},

    [ESTADO_ADICIONAR_FUNCIONARIO] = {[0] = ESTADO_MSG_OPERACAO_FUNCIONARIO},

    [ESTADO_EDITAR_FUNCIONARIO] = {[0] = ESTADO_MSG_OPERACAO_FUNCIONARIO},

    [ESTADO_EXCLUIR_FUNCIONARIO] = {[0] = ESTADO_MSG_OPERACAO_FUNCIONARIO},

    [ESTADO_MSG_OPERACAO_FUNCIONARIO] = {[0] = ESTADO_CADASTRO_FUNCIONARIOS},

    [ESTADO_MSG_CADASTRO_FUNCIONARIO] = {[0] = ESTADO_MENU_PRINCIPAL},

    [ESTADO_CADASTRO_INDUSTRIAS] = {
        [0] = ESTADO_LISTAR_INDUSTRIAS, [1] = ESTADO_ADICIONAR_INDUSTRIA, [2] = ESTADO_EDITAR_INDUSTRIA,
        [3] = ESTADO_EXCLUIR_INDUSTRIA, [4] = ESTADO_MENU_PRINCIPAL
    },

    [ESTADO_LISTAR_INDUSTRIAS] = {[0] = ESTADO_CADASTRO_INDUSTRIAS},

    [ESTADO_ADICIONAR_INDUSTRIA] = {[0] = ESTADO_MSG_OPERACAO_INDUSTRIA},

    [ESTADO_EDITAR_INDUSTRIA] = {[0] = ESTADO_MSG_OPERACAO_INDUSTRIA},

    [ESTADO_EXCLUIR_INDUSTRIA] = {[0] = ESTADO_MSG_OPERACAO_INDUSTRIA},

    [ESTADO_MSG_OPERACAO_INDUSTRIA] = {[0] = ESTADO_CADASTRO_INDUSTRIAS},

    [ESTADO_MSG_CADASTRO_INDUSTRIA] = {[0] = ESTADO_MENU_PRINCIPAL},

    [ESTADO_ATUALIZACAO_RESIDUOS] = {[0] = ESTADO_MENU_PRINCIPAL},

    [ESTADO_RELATORIOS_INDUSTRIA] = {[0] = ESTADO_MSG_RELATORIOS_INDUSTRIA},

    [ESTADO_MSG_RELATORIOS_INDUSTRIA] = {[0] = ESTADO_MENU_PRINCIPAL},

    [ESTADO_RELATORIOS_GLOBAIS] = {[0] = ESTADO_MSG_RELATORIOS_GLOBAIS},

    [ESTADO_MSG_RELATORIOS_GLOBAIS] = {[0] = ESTADO_MENU_PRINCIPAL},

    [ESTADO_LOGOUT] = {[0] = ESTADO_MSG_LOGOUT_SUCESSO},

    [ESTADO_MSG_LOGOUT_FALHA] = {[0] = ESTADO_MENU_PRINCIPAL},

    [ESTADO_SAIR] = {[0] = ESTADO_SAIR}
};

/**
 * Retorna o próximo estado baseado no estado atual e no índice da opção.
 * Se índice_opcao >= MAX_OPCOES_MENU, retorna o próprio estado_atual.
 */
estado_aplicacao obter_proximo_estado(estado_aplicacao estado_atual,
                                      size_t indice_opcao)
{
    if (indice_opcao >= MAX_OPCOES_MENU)
        return estado_atual;
    return transicoes[estado_atual][indice_opcao];
}
