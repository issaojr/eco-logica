#ifndef ESTADOS_H
#define ESTADOS_H

#include <stddef.h>

/* Estados da aplicação conforme o fluxograma de IU V2 */
typedef enum {
    ESTADO_MENU_LOGIN,                 // Tela inicial: [1] Login, [2] Sobre, [3] Sair
    ESTADO_SOBRE_PROJETO,              // Tela “Sobre o Projeto”
    ESTADO_FORM_LOGIN,                 // Tela de formulário de login (matrícula e senha)
    ESTADO_MSG_LOGIN,          // Mensagem “Login realizado com sucesso”
    ESTADO_MSG_LOGIN_FALHA,            // Mensagem “Usuário ou senha inválidos”
    ESTADO_LOGOUT,                    // Tela de logout (opção 6 do menu principal)
    ESTADO_MSG_LOGOUT_FALHA,           // Mensagem “Logout não realizado”
    ESTADO_MSG_LOGOUT_SUCESSO,         // Mensagem “Logout realizado com sucesso”
    ESTADO_MENU_PRINCIPAL,             // Menu principal
    ESTADO_CADASTRO_FUNCIONARIOS,       // Tela de cadastro de funcionário
    ESTADO_LISTAR_FUNCIONARIOS,        // Tela de listagem de funcionários
    ESTADO_ADICIONAR_FUNCIONARIO,      // Tela de adição de funcionário
    ESTADO_EDITAR_FUNCIONARIO,         // Tela de edição de funcionário
    ESTADO_EXCLUIR_FUNCIONARIO,        // Tela de exclusão de funcionário
    ESTADO_MSG_OPERACAO_FUNCIONARIO,   // Mensagem de resultado da operação com funcionário
    ESTADO_MSG_CADASTRO_FUNCIONARIO,   // Mensagem “Cadastro realizado com sucesso”
    ESTADO_CADASTRO_INDUSTRIAS,         // Tela de cadastro de indústria
    ESTADO_LISTAR_INDUSTRIAS,         // Tela de listagem de indústrias
    ESTADO_ADICIONAR_INDUSTRIA,       // Tela de adição de indústria
    ESTADO_EDITAR_INDUSTRIA,          // Tela de edição de indústria
    ESTADO_EXCLUIR_INDUSTRIA,         // Tela de exclusão de indústria
    ESTADO_MSG_OPERACAO_INDUSTRIA,     // Mensagem de resultado da operação com indústria
    ESTADO_MSG_CADASTRO_INDUSTRIA,     // Mensagem “Cadastro realizado com sucesso”
    ESTADO_ATUALIZACAO_RESIDUOS,       // Tela de atualização mensal de resíduos
    ESTADO_MSG_ATUALIZACAO_RESIDUOS,   // Mensagem “Atualização registrada com sucesso”
    ESTADO_RELATORIOS_GLOBAIS,         // Tela “Relatórios Globais”
    ESTADO_MSG_RELATORIOS_GLOBAIS,     // Mensagem “Relatório gerado com sucesso”
    ESTADO_RELATORIOS_INDUSTRIA,       // Tela “Relatórios por Indústria”
    ESTADO_MSG_RELATORIOS_INDUSTRIA,   // Mensagem “Relatório gerado com sucesso”
    ESTADO_SAIR                        // Estado de saída da aplicação
} estado_aplicacao;

/* Número máximo de opções em qualquer menu (deve cobrir o maior submenu) */
#define MAX_OPCOES_MENU 6

/**
 * transicoes[estado_atual][índice_opcao] = próximo estado
 * Será definido em maquina_estados.c
 */
extern const estado_aplicacao transicoes[][MAX_OPCOES_MENU];

/**
 * Retorna o próximo estado dado o estado atual e o índice da opção escolhida.
 * Se o índice for inválido, retorna o próprio estado_atual.
 */
estado_aplicacao obter_proximo_estado(estado_aplicacao estado_atual,
                                      size_t indice_opcao);

#endif /* ESTADOS_H */
