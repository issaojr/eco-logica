// src/maquina_estados.c

#include "estados.h"

#define UNUSED(x) (void)(x)

/*
 * Tabela de transi��es:
 *   transicoes[estado_atual][�ndice_da_opcao] = pr�ximo_estado
 *
 * Cada linha foi inicializada com designated initializers. Se voc� passar um �ndice
 * maior que o n�mero de op��es v�lidas para aquele menu, obter_proximo_estado()
 * retornar� o pr�prio estado_atual (fallback seguro).
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
        [0] = ESTADO_CADASTRO_FUNCIONARIO,    // 1. Cadastro de Funcion�rio
        [1] = ESTADO_CADASTRO_INDUSTRIA,      // 2. Cadastro de Ind�stria
        [2] = ESTADO_ATUALIZACAO_RESIDUOS,    // 3. Atualiza��o Mensal de Res�duos
        [3] = ESTADO_RELATORIOS_INDUSTRIA,    // 4. Relat�rios por Ind�stria
        [4] = ESTADO_SUBMENU_RELATORIOS_GLOBAIS, // 5. Relat�rios Globais
        [5] = ESTADO_MSG_LOGOUT_SUCESSO       // 6. Logout
    },

    [ESTADO_CADASTRO_FUNCIONARIO] = {
        [0] = ESTADO_MSG_CADASTRO_FUNCIONARIO // ENTER ap�s preencher formul�rio
    },
    [ESTADO_MSG_CADASTRO_FUNCIONARIO] = {
        [0] = ESTADO_MENU_PRINCIPAL           // ENTER volta ao menu principal
    },

    [ESTADO_CADASTRO_INDUSTRIA] = {
        [0] = ESTADO_MSG_CADASTRO_INDUSTRIA   // ENTER ap�s preencher formul�rio
    },
    [ESTADO_MSG_CADASTRO_INDUSTRIA] = {
        [0] = ESTADO_MENU_PRINCIPAL
    },

    [ESTADO_ATUALIZACAO_RESIDUOS] = {
        [0] = ESTADO_MSG_ATUALIZACAO_RESIDUOS // ENTER ap�s atualizar dados
    },
    [ESTADO_MSG_ATUALIZACAO_RESIDUOS] = {
        [0] = ESTADO_MENU_PRINCIPAL
    },

    [ESTADO_RELATORIOS_INDUSTRIA] = {
        [0] = ESTADO_REL_GLOBAIS_INS_TOT,     // 1. Insumos Tratados por Per�odo
        [1] = ESTADO_REL_GLOBAIS_TOTAL_GASTOS, // 2. Total de Gastos por Per�odo
        [2] = ESTADO_MENU_PRINCIPAL          // 3. Voltar ao Menu Principal
    },

    [ESTADO_SUBMENU_RELATORIOS_GLOBAIS] = {
        [0] = ESTADO_REL_GLOBAIS_REGIAO_MAIOR,   // 1. Regi�es c/ Maior Valor de Res�duos
        [1] = ESTADO_REL_GLOBAIS_IND_MENOR,      // 2. Ind�strias c/ Menor Volume
        [2] = ESTADO_REL_GLOBAIS_APORTE_FINANCEIRO, // 3. Aporte Financeiro
        [3] = ESTADO_MENU_PRINCIPAL              // 4. Voltar ao Menu Principal
    },

    /* Estados de exibi��o de relat�rio + prompt de exporta��o:
     *  1-3 reexibem o mesmo relat�rio
     *  4 voltam ao menu de relat�rios correspondente
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
 * Retorna o pr�ximo estado baseado no estado atual e no �ndice da op��o.
 * Se �ndice_opcao >= MAX_OPCOES_MENU, retorna o pr�prio estado_atual.
 */
estado_aplicacao obter_proximo_estado(estado_aplicacao estado_atual,
                                      size_t indice_opcao)
{
    if (indice_opcao >= MAX_OPCOES_MENU)
        return estado_atual;
    return transicoes[estado_atual][indice_opcao];
}
