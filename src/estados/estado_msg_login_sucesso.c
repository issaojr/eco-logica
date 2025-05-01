#include <stdlib.h>
#include <stdio.h>
#include "estados/estado_msg_login_sucesso.h"
#include "session.h"

// Fun��es espec�ficas deste estado
static int inicializar(void) {
    // Limpar a tela
    system("cls");
    
    // Obter informa��es do usu�rio logado para personalizar a mensagem
    funcionario_t *usuario = get_usuario_logado();
    
    printf("\n\n");
    puts("+================================================+");
    puts("|          Login realizado com sucesso!          |");
    puts("+================================================+");
    
    if (usuario) {
        printf("\nBem-vindo(a), %s!\n", usuario->nome);
    }
    
    printf("\nPressione ENTER para continuar...");
    
    // Aguarda o usu�rio pressionar ENTER
    getchar();
    
    return 0; // sucesso
}

static estado_aplicacao processar(size_t entrada) {
    // Este estado sempre transita para o menu principal ap�s inicializa��o
    return ESTADO_MENU_PRINCIPAL;
}

static void finalizar(void) {
    // N�o h� recursos espec�ficos para liberar neste estado
}

static estado_aplicacao obter_id(void) {
    return ESTADO_MSG_LOGIN_SUCESSO;
}

estado_t* criar_estado_msg_login_sucesso(void) {
    estado_t* estado = (estado_t*) malloc(sizeof(estado_t));
    if (estado) {
        estado->inicializar = inicializar;
        estado->processar = processar;
        estado->finalizar = finalizar;
        estado->obter_id = obter_id;
    }
    return estado;
}