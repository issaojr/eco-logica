// src/maquina_estados.c

#include "estados.h"

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
        [0] = ESTADO_LOGIN_CREDENCIAIS,   // 1. Login
        [1] = ESTADO_SOBRE_PROJETO,       // 2. Sobre
        [2] = ESTADO_SAIR                 // 3. Sair
    },

    [ESTADO_SOBRE_PROJETO] = {
        [0] = ESTADO_MENU_LOGIN           // ENTER volta para o menu de login
    },

    //[ESTADO_LOGIN_CREDENCIAIS] = { },

    [ESTADO_MSG_LOGIN_SUCESSO] = {
        [0] = ESTADO_MENU_PRINCIPAL       // ENTER vai para menu principal
    },

    [ESTADO_MSG_LOGIN_FALHA] = {
        [0] = ESTADO_MENU_LOGIN           // ENTER volta para menu de login
    },

    [ESTADO_MSG_LOGOUT_SUCESSO] = {
        [0] = ESTADO_MENU_LOGIN           // ENTER volta para menu de login
    },

    [ESTADO_MENU_PRINCIPAL] = {
        [0] = ESTADO_CADASTRO_FUNCIONARIO,    // 1. Cadastro de Funcionário
        [1] = ESTADO_CADASTRO_INDUSTRIA,      // 2. Cadastro de Indústria
        [2] = ESTADO_ATUALIZACAO_RESIDUOS,    // 3. Atualização Mensal de Resíduos
        [3] = ESTADO_RELATORIOS_INDUSTRIA,    // 4. Relatórios por Indústria
        [4] = ESTADO_SUBMENU_RELATORIOS_GLOBAIS, // 5. Relatórios Globais
        [5] = ESTADO_MSG_LOGOUT_SUCESSO       // 6. Logout
    },

    [ESTADO_CADASTRO_FUNCIONARIO] = {
        [0] = ESTADO_MSG_CADASTRO_FUNCIONARIO // ENTER após preencher formulário
    },
    [ESTADO_MSG_CADASTRO_FUNCIONARIO] = {
        [0] = ESTADO_MENU_PRINCIPAL           // ENTER volta ao menu principal
    },

    [ESTADO_CADASTRO_INDUSTRIA] = {
        [0] = ESTADO_MSG_CADASTRO_INDUSTRIA   // ENTER após preencher formulário
    },
    [ESTADO_MSG_CADASTRO_INDUSTRIA] = {
        [0] = ESTADO_MENU_PRINCIPAL
    },

    [ESTADO_ATUALIZACAO_RESIDUOS] = {
        [0] = ESTADO_MSG_ATUALIZACAO_RESIDUOS // ENTER após atualizar dados
    },
    [ESTADO_MSG_ATUALIZACAO_RESIDUOS] = {
        [0] = ESTADO_MENU_PRINCIPAL
    },

    [ESTADO_RELATORIOS_INDUSTRIA] = {
        [0] = ESTADO_REL_GLOBAIS_INS_TOT,     // 1. Insumos Tratados por Período
        [1] = ESTADO_REL_GLOBAIS_TOTAL_GASTOS, // 2. Total de Gastos por Período
        [2] = ESTADO_MENU_PRINCIPAL          // 3. Voltar ao Menu Principal
    },

    [ESTADO_SUBMENU_RELATORIOS_GLOBAIS] = {
        [0] = ESTADO_REL_GLOBAIS_REGIAO_MAIOR,   // 1. Regiões c/ Maior Valor de Resíduos
        [1] = ESTADO_REL_GLOBAIS_IND_MENOR,      // 2. Indústrias c/ Menor Volume
        [2] = ESTADO_REL_GLOBAIS_APORTE_FINANCEIRO, // 3. Aporte Financeiro
        [3] = ESTADO_MENU_PRINCIPAL              // 4. Voltar ao Menu Principal
    },

    /* Estados de exibição de relatório + prompt de exportação:
     *  1-3 reexibem o mesmo relatório
     *  4 voltam ao menu de relatórios correspondente
     *  5 voltam ao menu principal
     */
    [ESTADO_REL_GLOBAIS_INS_TOT] = {
        [0] = ESTADO_REL_GLOBAIS_INS_TOT,
        [1] = ESTADO_REL_GLOBAIS_INS_TOT,
        [2] = ESTADO_REL_GLOBAIS_INS_TOT,
        [3] = ESTADO_SUBMENU_RELATORIOS_GLOBAIS,
        [4] = ESTADO_MENU_PRINCIPAL
    },
    [ESTADO_REL_GLOBAIS_TOTAL_GASTOS] = {
        [0] = ESTADO_REL_GLOBAIS_TOTAL_GASTOS,
        [1] = ESTADO_REL_GLOBAIS_TOTAL_GASTOS,
        [2] = ESTADO_REL_GLOBAIS_TOTAL_GASTOS,
        [3] = ESTADO_SUBMENU_RELATORIOS_GLOBAIS,
        [4] = ESTADO_MENU_PRINCIPAL
    },
    [ESTADO_REL_GLOBAIS_REGIAO_MAIOR] = {
        [0] = ESTADO_REL_GLOBAIS_REGIAO_MAIOR,
        [1] = ESTADO_REL_GLOBAIS_REGIAO_MAIOR,
        [2] = ESTADO_REL_GLOBAIS_REGIAO_MAIOR,
        [3] = ESTADO_SUBMENU_RELATORIOS_GLOBAIS,
        [4] = ESTADO_MENU_PRINCIPAL
    },
    [ESTADO_REL_GLOBAIS_IND_MENOR] = {
        [0] = ESTADO_REL_GLOBAIS_IND_MENOR,
        [1] = ESTADO_REL_GLOBAIS_IND_MENOR,
        [2] = ESTADO_REL_GLOBAIS_IND_MENOR,
        [3] = ESTADO_SUBMENU_RELATORIOS_GLOBAIS,
        [4] = ESTADO_MENU_PRINCIPAL
    },
    [ESTADO_REL_GLOBAIS_APORTE_FINANCEIRO] = {
        [0] = ESTADO_REL_GLOBAIS_APORTE_FINANCEIRO,
        [1] = ESTADO_REL_GLOBAIS_APORTE_FINANCEIRO,
        [2] = ESTADO_REL_GLOBAIS_APORTE_FINANCEIRO,
        [3] = ESTADO_SUBMENU_RELATORIOS_GLOBAIS,
        [4] = ESTADO_MENU_PRINCIPAL
    }
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
