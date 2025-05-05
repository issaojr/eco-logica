// src/maquina_estados.c

#include "estados/estados.h"

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
        [0] = ESTADO_FORM_LOGIN,          // 1. Formul�rio de Login
        [1] = ESTADO_SOBRE_PROJETO,       // 2. Sobre
        [2] = ESTADO_SAIR                 // 3. Sair
    },

    [ESTADO_SOBRE_PROJETO] = {
        [0] = ESTADO_MENU_LOGIN           // ENTER volta para o menu de login
    },

    // Estado de formul�rio de login: tratar credenciais
    [ESTADO_FORM_LOGIN] = { },

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
        [0] = ESTADO_CADASTRO_FUNCIONARIOS,    // 1. Cadastro de Funcion�rio
        [1] = ESTADO_CADASTRO_INDUSTRIAS,      // 2. Cadastro de Ind�stria
        [2] = ESTADO_ATUALIZACAO_RESIDUOS,    // 3. Atualiza��o Mensal de Res�duos
        [3] = ESTADO_RELATORIOS_INDUSTRIA,    // 4. Relat�rios por Ind�stria
        [4] = ESTADO_RELATORIOS_GLOBAIS, // 5. Relat�rios Globais
        [5] = ESTADO_LOGOUT      // 6. Logout
    },

    [ESTADO_CADASTRO_FUNCIONARIOS] = {
        [0] = ESTADO_LISTAR_FUNCIONARIOS,     // 1. Listar Funcion�rios
        [1] = ESTADO_ADICIONAR_FUNCIONARIO,   // 2. Adicionar Funcion�rio
        [2] = ESTADO_EDITAR_FUNCIONARIO,      // 3. Editar Funcion�rio
        [3] = ESTADO_EXCLUIR_FUNCIONARIO,     // 4. Excluir Funcion�rio
        [4] = ESTADO_MENU_PRINCIPAL           // 5. Voltar ao Menu Principal
    },

    [ESTADO_LISTAR_FUNCIONARIOS] = {
        [0] = ESTADO_CADASTRO_FUNCIONARIOS // ENTER ap�s listar funcion�rios
    },

    [ESTADO_ADICIONAR_FUNCIONARIO] = {
        [0] = ESTADO_MSG_OPERACAO_FUNCIONARIO // ENTER ap�s adicionar funcion�rio
    },

    [ESTADO_EDITAR_FUNCIONARIO] = {
        [0] = ESTADO_MSG_OPERACAO_FUNCIONARIO // ENTER ap�s editar funcion�rio
    },

    [ESTADO_EXCLUIR_FUNCIONARIO] = {
        [0] = ESTADO_MSG_OPERACAO_FUNCIONARIO // ENTER ap�s excluir funcion�rio
    },

    [ESTADO_MSG_OPERACAO_FUNCIONARIO] = {
        [0] = ESTADO_CADASTRO_FUNCIONARIOS // ENTER ap�s opera��o com funcion�rio
    },

    [ESTADO_MSG_CADASTRO_FUNCIONARIO] = {
        [0] = ESTADO_MENU_PRINCIPAL           // ENTER volta ao menu principal
    },

    [ESTADO_CADASTRO_INDUSTRIAS] = {
        [0] = ESTADO_LISTAR_INDUSTRIAS,     // 1. Listar Ind�strias
        [1] = ESTADO_ADICIONAR_INDUSTRIA,   // 2. Adicionar Ind�stria
        [2] = ESTADO_EDITAR_INDUSTRIA,      // 3. Editar Ind�stria
        [3] = ESTADO_EXCLUIR_INDUSTRIA,     // 4. Excluir Ind�stria
        [4] = ESTADO_MENU_PRINCIPAL         // 5. Voltar ao Menu Principal
    },

    [ESTADO_LISTAR_INDUSTRIAS] = {
        [0] = ESTADO_CADASTRO_INDUSTRIAS // ENTER ap�s listar ind�strias
    },

    [ESTADO_ADICIONAR_INDUSTRIA] = {
        [0] = ESTADO_MSG_OPERACAO_INDUSTRIA // ENTER ap�s preencher formul�rio
    },

    [ESTADO_EDITAR_INDUSTRIA] = {
        [0] = ESTADO_MSG_OPERACAO_INDUSTRIA // ENTER ap�s editar ind�stria
    },

    [ESTADO_EXCLUIR_INDUSTRIA] = {
        [0] = ESTADO_MSG_OPERACAO_INDUSTRIA // ENTER ap�s excluir ind�stria
    },

    [ESTADO_MSG_OPERACAO_INDUSTRIA] = {
        [0] = ESTADO_CADASTRO_INDUSTRIAS // ENTER ap�s opera��o com ind�stria
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
        [0] = ESTADO_MSG_RELATORIOS_INDUSTRIA // ENTER ap�s gerar relat�rio
    },

    [ESTADO_MSG_RELATORIOS_INDUSTRIA] = {
        [0] = ESTADO_MENU_PRINCIPAL // ENTER ap�s gerar relat�rio
    },

    [ESTADO_RELATORIOS_GLOBAIS] = {
        [0] = ESTADO_MSG_RELATORIOS_GLOBAIS // ENTER ap�s gerar relat�rio
    },

    [ESTADO_MSG_RELATORIOS_GLOBAIS] = {
        [0] = ESTADO_MENU_PRINCIPAL // ENTER ap�s gerar relat�rio
    },

    [ESTADO_LOGOUT] = {
        [0] = ESTADO_MSG_LOGOUT_SUCESSO // ENTER ap�s logout
    },

    [ESTADO_MSG_LOGOUT_FALHA] = {
        [0] = ESTADO_MENU_PRINCIPAL // ENTER ap�s falha no logout
    },

    [ESTADO_SAIR] = {
        [0] = ESTADO_SAIR // ENTER para sair
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
