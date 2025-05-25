#ifndef ESTADOS_H
#define ESTADOS_H

#include <stddef.h>

typedef enum
{
    ESTADO_MENU_LOGIN,
    ESTADO_SOBRE_PROJETO,
    ESTADO_FORM_LOGIN,
    ESTADO_MSG_LOGIN,
    ESTADO_MSG_LOGIN_FALHA,
    ESTADO_LOGOUT,
    ESTADO_MSG_LOGOUT_FALHA,
    ESTADO_MSG_LOGOUT_SUCESSO,
    ESTADO_MENU_PRINCIPAL,
    ESTADO_CADASTRO_FUNCIONARIOS,
    ESTADO_LISTAR_FUNCIONARIOS,
    ESTADO_ADICIONAR_FUNCIONARIO,
    ESTADO_EDITAR_FUNCIONARIO,
    ESTADO_EXCLUIR_FUNCIONARIO,
    ESTADO_MSG_OPERACAO_FUNCIONARIO,
    ESTADO_MSG_CADASTRO_FUNCIONARIO,
    ESTADO_CADASTRO_INDUSTRIAS,
    ESTADO_LISTAR_INDUSTRIAS,
    ESTADO_ADICIONAR_INDUSTRIA,
    ESTADO_EDITAR_INDUSTRIA,
    ESTADO_EXCLUIR_INDUSTRIA,
    ESTADO_MSG_OPERACAO_INDUSTRIA,
    ESTADO_MSG_CADASTRO_INDUSTRIA,
    ESTADO_ATUALIZACAO_RESIDUOS,
    ESTADO_RELATORIOS_GLOBAIS,
    ESTADO_MSG_RELATORIOS_GLOBAIS,
    ESTADO_RELATORIOS_INDUSTRIA,
    ESTADO_MSG_RELATORIOS_INDUSTRIA,
    ESTADO_MSG_ENCERRAMENTO,
    ESTADO_SAIR
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
