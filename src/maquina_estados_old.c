// src/maquina_estados.c

#include "estados/estados.h"
// debug
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
        [0] = ESTADO_FORM_LOGIN,          // 1. Formulário de Login
        [1] = ESTADO_SOBRE_PROJETO,       // 2. Sobre
        [2] = ESTADO_SAIR                 // 3. Sair
    },

    [ESTADO_SOBRE_PROJETO] = {
        [0] = ESTADO_MENU_LOGIN           // ENTER volta para o menu de login
    },

    // Estado de formulário de login: tratar credenciais
    [ESTADO_FORM_LOGIN] = {
        [0] = ESTADO_MSG_LOGIN,   // 1. Login realizado com sucesso
        [1] = ESTADO_MSG_LOGIN_FALHA       // 2. Login falhou
    },

    //[ESTADO_LOGIN_CREDENCIAIS] = { },

    [ESTADO_MSG_LOGIN] = {
        [0] = ESTADO_MENU_PRINCIPAL       // ENTER vai para menu principal
    },

    [ESTADO_MSG_LOGIN_FALHA] = {
        [0] = ESTADO_MENU_LOGIN           // ENTER volta para menu de login
    },

    [ESTADO_MSG_LOGOUT_SUCESSO] = {
        [0] = ESTADO_MENU_LOGIN           // ENTER volta para menu de login
    },

    [ESTADO_MENU_PRINCIPAL] = {
        [0] = ESTADO_CADASTRO_FUNCIONARIOS,    // 1. Cadastro de Funcionário
        [1] = ESTADO_CADASTRO_INDUSTRIAS,      // 2. Cadastro de Indústria
        [2] = ESTADO_ATUALIZACAO_RESIDUOS,    // 3. Atualização Mensal de Resíduos
        [3] = ESTADO_RELATORIOS_INDUSTRIA,    // 4. Relatórios por Indústria
        [4] = ESTADO_RELATORIOS_GLOBAIS, // 5. Relatórios Globais
        [5] = ESTADO_LOGOUT      // 6. Logout
    },

    [ESTADO_CADASTRO_FUNCIONARIOS] = {
        [0] = ESTADO_LISTAR_FUNCIONARIOS,     // 1. Listar Funcionários
        [1] = ESTADO_ADICIONAR_FUNCIONARIO,   // 2. Adicionar Funcionário
        [2] = ESTADO_EDITAR_FUNCIONARIO,      // 3. Editar Funcionário
        [3] = ESTADO_EXCLUIR_FUNCIONARIO,     // 4. Excluir Funcionário
        [4] = ESTADO_MENU_PRINCIPAL           // 5. Voltar ao Menu Principal
    },

    [ESTADO_LISTAR_FUNCIONARIOS] = {
        [0] = ESTADO_CADASTRO_FUNCIONARIOS // ENTER após listar funcionários
    },

    [ESTADO_ADICIONAR_FUNCIONARIO] = {
        [0] = ESTADO_MSG_OPERACAO_FUNCIONARIO // ENTER após adicionar funcionário
    },

    [ESTADO_EDITAR_FUNCIONARIO] = {
        [0] = ESTADO_MSG_OPERACAO_FUNCIONARIO // ENTER após editar funcionário
    },

    [ESTADO_EXCLUIR_FUNCIONARIO] = {
        [0] = ESTADO_MSG_OPERACAO_FUNCIONARIO // ENTER após excluir funcionário
    },

    [ESTADO_MSG_OPERACAO_FUNCIONARIO] = {
        [0] = ESTADO_CADASTRO_FUNCIONARIOS // ENTER após operação com funcionário
    },

    [ESTADO_MSG_CADASTRO_FUNCIONARIO] = {
        [0] = ESTADO_MENU_PRINCIPAL           // ENTER volta ao menu principal
    },

    [ESTADO_CADASTRO_INDUSTRIAS] = {
        [0] = ESTADO_LISTAR_INDUSTRIAS,     // 1. Listar Indústrias
        [1] = ESTADO_ADICIONAR_INDUSTRIA,   // 2. Adicionar Indústria
        [2] = ESTADO_EDITAR_INDUSTRIA,      // 3. Editar Indústria
        [3] = ESTADO_EXCLUIR_INDUSTRIA,     // 4. Excluir Indústria
        [4] = ESTADO_MENU_PRINCIPAL         // 5. Voltar ao Menu Principal
    },

    [ESTADO_LISTAR_INDUSTRIAS] = {
        [0] = ESTADO_CADASTRO_INDUSTRIAS // ENTER após listar indústrias
    },

    [ESTADO_ADICIONAR_INDUSTRIA] = {
        [0] = ESTADO_MSG_OPERACAO_INDUSTRIA // ENTER após preencher formulário
    },

    [ESTADO_EDITAR_INDUSTRIA] = {
        [0] = ESTADO_MSG_OPERACAO_INDUSTRIA // ENTER após editar indústria
    },

    [ESTADO_EXCLUIR_INDUSTRIA] = {
        [0] = ESTADO_MSG_OPERACAO_INDUSTRIA // ENTER após excluir indústria
    },

    [ESTADO_MSG_OPERACAO_INDUSTRIA] = {
        [0] = ESTADO_CADASTRO_INDUSTRIAS // ENTER após operação com indústria
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
        [0] = ESTADO_MSG_RELATORIOS_INDUSTRIA // ENTER após gerar relatório
    },

    [ESTADO_MSG_RELATORIOS_INDUSTRIA] = {
        [0] = ESTADO_MENU_PRINCIPAL // ENTER após gerar relatório
    },

    [ESTADO_RELATORIOS_GLOBAIS] = {
        [0] = ESTADO_MSG_RELATORIOS_GLOBAIS // ENTER após gerar relatório
    },

    [ESTADO_MSG_RELATORIOS_GLOBAIS] = {
        [0] = ESTADO_MENU_PRINCIPAL // ENTER após gerar relatório
    },

    [ESTADO_LOGOUT] = {
        [0] = ESTADO_MSG_LOGOUT_SUCESSO // ENTER após logout
    },

    [ESTADO_MSG_LOGOUT_FALHA] = {
        [0] = ESTADO_MENU_PRINCIPAL // ENTER após falha no logout
    },

    [ESTADO_SAIR] = {
        [0] = ESTADO_SAIR // ENTER para sair
    }

};

/**
 * Retorna o próximo estado baseado no estado atual e no índice da opção.
 * Se índice_opcao >= MAX_OPCOES_MENU, retorna o próprio estado_atual.
 */
estado_aplicacao obter_proximo_estado(estado_aplicacao estado_atual,
                                      size_t indice_opcao)
{
    ui_exibir_debug("maquina_estados_old => obter_proximo_estado()");

    if (indice_opcao >= MAX_OPCOES_MENU)
        return estado_atual;
    return transicoes[estado_atual][indice_opcao];
}
