#ifndef ESTADOS_H
#define ESTADOS_H

#include <stddef.h>

/* Estados da aplicação conforme o fluxograma de IU V2 */
typedef enum {
    ESTADO_MENU_LOGIN,                 // Tela inicial: [1] Login, [2] Sobre, [3] Sair
    ESTADO_SOBRE_PROJETO,              // Tela “Sobre o Projeto”
    ESTADO_FORM_LOGIN,                 // Tela de formulário de login (matrícula e senha)
    ESTADO_MSG_LOGIN_SUCESSO,          // Mensagem “Login realizado com sucesso”
    ESTADO_MSG_LOGIN_FALHA,            // Mensagem “Usuário ou senha inválidos”
    ESTADO_MSG_LOGOUT_SUCESSO,         // Mensagem “Logout realizado com sucesso”
    ESTADO_MENU_PRINCIPAL,             // Menu principal
    ESTADO_CADASTRO_FUNCIONARIO,       // Tela de cadastro de funcionário
    ESTADO_MSG_CADASTRO_FUNCIONARIO,   // Mensagem “Cadastro realizado com sucesso”
    ESTADO_CADASTRO_INDUSTRIA,         // Tela de cadastro de indústria
    ESTADO_MSG_CADASTRO_INDUSTRIA,     // Mensagem “Cadastro realizado com sucesso”
    ESTADO_ATUALIZACAO_RESIDUOS,       // Tela de atualização mensal de resíduos
    ESTADO_MSG_ATUALIZACAO_RESIDUOS,   // Mensagem “Atualização registrada com sucesso”
    ESTADO_RELATORIOS_INDUSTRIA,       // Tela “Relatórios por Indústria”
    ESTADO_SUBMENU_RELATORIOS_GLOBAIS, // Tela “Relatórios Globais” (sub-opções)
    ESTADO_REL_GLOBAIS_INS_TOT,        // Relatório: Insumos tratados por período
    ESTADO_REL_GLOBAIS_TOTAL_GASTOS,   // Relatório: Total de gastos por período
    ESTADO_REL_GLOBAIS_REGIAO_MAIOR,   // Relatório: Regiões com maior valor de resíduos
    ESTADO_REL_GLOBAIS_IND_MENOR,      // Relatório: Indústrias com menor volume
    ESTADO_REL_GLOBAIS_APORTE_FINANCEIRO, // Relatório: Aporte financeiro
    ESTADO_MSG_EXPORTAR_RELATORIO,     // Tela com opções de exportação do relatório
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
