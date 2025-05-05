#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "estados/estado_sobre_projeto.h"
#include "ui/ui_tela_sobre_projeto.h"
#include "estados/estado_menu_utils.h"
#include "ui/ui_comum.h"

// Fun��es espec�ficas deste estado
static int inicializar(void) {
    // Obter data e hora atual
    time_t t = time(NULL);
    struct tm *tm_info = localtime(&t);
    char data_hora[64];
    strftime(data_hora, sizeof(data_hora), "%d/%m/%Y %H:%M", tm_info);
    
    // Usar nossos componentes de UI para exibir o cabe�alho
    ui_exibir_titulo("EcoL�gica Solu��es Ambientais", "Sistema de Gest�o Ambiental");
    
    ui_exibir_data_hora(data_hora);
    
    ui_exibir_sobre_projeto();
    printf("\n");
    
    return 0; // sucesso
}

static estado_aplicacao processar(size_t entrada) {
    // Este estado n�o processa entradas do usu�rio, apenas exibe informa��es
    // e aguarda o usu�rio pressionar ENTER para voltar ao menu anterior.
    ui_prompt_voltar_menu_anterior(NULL);
    return ESTADO_MENU_LOGIN;
}

static void finalizar(void) {
    // N�o h� recursos espec�ficos para liberar neste estado
}

static estado_aplicacao obter_id(void) {
    return ESTADO_SOBRE_PROJETO;
}

estado_t* criar_estado_sobre_projeto(void) {
    estado_t* estado = (estado_t*) malloc(sizeof(estado_t));
    if (estado) {
        estado->inicializar = inicializar;
        estado->processar = processar;
        estado->finalizar = finalizar;
        estado->obter_id = obter_id;
    }
    return estado;
}
