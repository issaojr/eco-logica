#ifndef ESTADOS_H
#define ESTADOS_H

#include <stddef.h>

/* Estados da aplica��o conforme o fluxograma de IU V2 */
typedef enum {
    ESTADO_MENU_LOGIN,                 // Tela inicial: [1] Login, [2] Sobre, [3] Sair
    ESTADO_SOBRE_PROJETO,              // Tela �Sobre o Projeto�
    ESTADO_LOGIN_CREDENCIAIS,          // Tela de digitar matr�cula e senha
    ESTADO_MSG_LOGIN_SUCESSO,          // Mensagem �Login realizado com sucesso�
    ESTADO_MSG_LOGIN_FALHA,            // Mensagem �Usu�rio ou senha inv�lidos�
    ESTADO_MSG_LOGOUT_SUCESSO,         // Mensagem �Logout realizado com sucesso�
    ESTADO_MENU_PRINCIPAL,             // Menu principal
    ESTADO_CADASTRO_FUNCIONARIO,       // Tela de cadastro de funcion�rio
    ESTADO_MSG_CADASTRO_FUNCIONARIO,   // Mensagem �Cadastro realizado com sucesso�
    ESTADO_CADASTRO_INDUSTRIA,         // Tela de cadastro de ind�stria
    ESTADO_MSG_CADASTRO_INDUSTRIA,     // Mensagem �Cadastro realizado com sucesso�
    ESTADO_ATUALIZACAO_RESIDUOS,       // Tela de atualiza��o mensal de res�duos
    ESTADO_MSG_ATUALIZACAO_RESIDUOS,   // Mensagem �Atualiza��o registrada com sucesso�
    ESTADO_RELATORIOS_INDUSTRIA,       // Tela �Relat�rios por Ind�stria�
    ESTADO_SUBMENU_RELATORIOS_GLOBAIS, // Tela �Relat�rios Globais� (sub-op��es)
    ESTADO_REL_GLOBAIS_INS_TOT,        // Relat�rio: Insumos tratados por per�odo
    ESTADO_REL_GLOBAIS_TOTAL_GASTOS,   // Relat�rio: Total de gastos por per�odo
    ESTADO_REL_GLOBAIS_REGIAO_MAIOR,   // Relat�rio: Regi�es com maior valor de res�duos
    ESTADO_REL_GLOBAIS_IND_MENOR,      // Relat�rio: Ind�strias com menor volume
    ESTADO_REL_GLOBAIS_APORTE_FINANCEIRO, // Relat�rio: Aporte financeiro
    ESTADO_MSG_EXPORTAR_RELATORIO,     // Tela com op��es de exporta��o do relat�rio
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
