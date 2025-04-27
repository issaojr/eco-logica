#ifndef TESTE_MENU_H
#define TESTE_MENU_H

#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
/**
typedef enum {
    OPCAO_INVALIDA_TESTE = -1,
    OPCAO_LOGIN_TESTE = 1,
    OPCAO_SOBRE_TESTE = 2,
    OPCAO_SAIR_TESTE = 0,
    OPCAO_CADASTRO_FUNCIONARIO_TESTE = 1,
    OPCAO_CADASTRO_INDUSTRIA_TESTE = 2,
    OPCAO_CADASTRO_RESIDUOS_TESTE = 3,
    OPCAO_RELATORIOS_INDUSTRIA_TESTE = 4,
    OPCAO_RELATORIOS_GLOBAIS_TESTE = 5,
    OPCAO_LOGOUT_TESTE = 9,    
} codigo_opcao;


typedef struct {
    codigo_opcao codigo;
    const char *msg;
} opcao_t;

void teste_menu(void);
void mostrar_menu_login_teste(void);
void mostrar_menu_principal_teste(void);
int ler_opcao_menu_teste(void);
void imprimir_menu_teste(const opcao_t *mapa, size_t n);
codigo_opcao ler_opcao_teste(const opcao_t *mapa, size_t n, const char *prompt);
*/

#endif // TESTE_MENU_H