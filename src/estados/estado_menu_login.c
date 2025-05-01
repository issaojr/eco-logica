#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "estados/estado_menu_login.h"
#include "tela_menu_login_ui.h"
#include "estado_menu_utils.h"

// Fun��es espec�ficas deste estado
static int inicializar(void) {
    // Limpar a tela
    system("cls");
    
    // Obter data e hora atual
    time_t t = time(NULL);
    struct tm *tm_info = localtime(&t);
    char data_hora[64];
    strftime(data_hora, sizeof(data_hora), "%d/%m/%Y %H:%M", tm_info);
    
    // Cabe�alho com informa��es do sistema
    printf("EcoL�gica Solu��es Ambientais\n");
    printf("=============================\n");
    printf("Sistema de Gest�o Ambiental\n");
    printf("Data: %s\n\n", data_hora);
    
    printf("Bem-vindo! Por favor, selecione uma op��o:\n\n");
    
    return 0; // sucesso
}

static estado_aplicacao processar(size_t entrada) {
    // Usar a fun��o utilit�ria para processar o menu
    return processar_estado_menu(
        tela_menu_login_mapa,
        tela_menu_login_mapa_n,
        tela_menu_login_prompt,
        ESTADO_MENU_LOGIN
    );
}

static void finalizar(void) {
    // N�o h� recursos espec�ficos para liberar neste estado
}

static estado_aplicacao obter_id(void) {
    return ESTADO_MENU_LOGIN;
}

estado_t* criar_estado_menu_login(void) {
    estado_t* estado = (estado_t*) malloc(sizeof(estado_t));
    if (estado) {
        estado->inicializar = inicializar;
        estado->processar = processar;
        estado->finalizar = finalizar;
        estado->obter_id = obter_id;
    }
    return estado;
}