#ifndef ESTADOS_H
#define ESTADOS_H

#include <stddef.h>

/* Estados da aplica��o conforme o fluxograma de IU V2 */
typedef enum {
    ESTADO_MENU_LOGIN,                 // Tela inicial: [1] Login, [2] Sobre, [3] Sair
    ESTADO_SOBRE_PROJETO,              // Tela �Sobre o Projeto�
    ESTADO_FORM_LOGIN,                 // Tela de formul�rio de login (matr�cula e senha)
    ESTADO_MSG_LOGIN_SUCESSO,          // Mensagem �Login realizado com sucesso�
    ESTADO_MSG_LOGIN_FALHA,            // Mensagem �Usu�rio ou senha inv�lidos�
    ESTADO_LOGOUT,                    // Tela de logout (op��o 6 do menu principal)
    ESTADO_MSG_LOGOUT_FALHA,           // Mensagem �Logout n�o realizado�
    ESTADO_MSG_LOGOUT_SUCESSO,         // Mensagem �Logout realizado com sucesso�
    ESTADO_MENU_PRINCIPAL,             // Menu principal
    ESTADO_CADASTRO_FUNCIONARIOS,       // Tela de cadastro de funcion�rio
    ESTADO_LISTAR_FUNCIONARIOS,        // Tela de listagem de funcion�rios
    ESTADO_ADICIONAR_FUNCIONARIO,      // Tela de adi��o de funcion�rio
    ESTADO_EDITAR_FUNCIONARIO,         // Tela de edi��o de funcion�rio
    ESTADO_EXCLUIR_FUNCIONARIO,        // Tela de exclus�o de funcion�rio
    ESTADO_MSG_OPERACAO_FUNCIONARIO,   // Mensagem de resultado da opera��o com funcion�rio
    ESTADO_MSG_CADASTRO_FUNCIONARIO,   // Mensagem �Cadastro realizado com sucesso�
    ESTADO_CADASTRO_INDUSTRIAS,         // Tela de cadastro de ind�stria
    ESTADO_LISTAR_INDUSTRIAS,         // Tela de listagem de ind�strias
    ESTADO_ADICIONAR_INDUSTRIA,       // Tela de adi��o de ind�stria
    ESTADO_EDITAR_INDUSTRIA,          // Tela de edi��o de ind�stria
    ESTADO_EXCLUIR_INDUSTRIA,         // Tela de exclus�o de ind�stria
    ESTADO_MSG_OPERACAO_INDUSTRIA,     // Mensagem de resultado da opera��o com ind�stria
    ESTADO_MSG_CADASTRO_INDUSTRIA,     // Mensagem �Cadastro realizado com sucesso�
    ESTADO_ATUALIZACAO_RESIDUOS,       // Tela de atualiza��o mensal de res�duos
    ESTADO_MSG_ATUALIZACAO_RESIDUOS,   // Mensagem �Atualiza��o registrada com sucesso�
    ESTADO_RELATORIOS_GLOBAIS,         // Tela �Relat�rios Globais�
    ESTADO_MSG_RELATORIOS_GLOBAIS,     // Mensagem �Relat�rio gerado com sucesso�
    ESTADO_RELATORIOS_INDUSTRIA,       // Tela �Relat�rios por Ind�stria�
    ESTADO_MSG_RELATORIOS_INDUSTRIA,   // Mensagem �Relat�rio gerado com sucesso�
    ESTADO_SAIR                        // Estado de sa�da da aplica��o
} estado_aplicacao;

/* N�mero m�ximo de op��es em qualquer menu (deve cobrir o maior submenu) */
#define MAX_OPCOES_MENU 6

/**
 * transicoes[estado_atual][�ndice_opcao] = pr�ximo estado
 * Ser� definido em maquina_estados.c
 */
extern const estado_aplicacao transicoes[][MAX_OPCOES_MENU];

/**
 * Retorna o pr�ximo estado dado o estado atual e o �ndice da op��o escolhida.
 * Se o �ndice for inv�lido, retorna o pr�prio estado_atual.
 */
estado_aplicacao obter_proximo_estado(estado_aplicacao estado_atual,
                                      size_t indice_opcao);

#endif /* ESTADOS_H */
