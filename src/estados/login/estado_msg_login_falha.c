#include <stdlib.h>
#include <stdio.h>
#include "estados/login/estado_msg_login_falha.h"
#include "ui/ui_comum.h"

// Fun��es espec�ficas deste estado
static int inicializar(void) {
    // Exibir t�tulo e mensagem de erro usando nossos componentes de UI
    ui_exibir_titulo("Falha na Autentica��o", "N�o foi poss�vel realizar o login");
    
    ui_exibir_erro("Usu�rio ou senha inv�lidos!");
    
    printf("\nAs credenciais fornecidas n�o s�o v�lidas.");
    printf("\nVerifique sua matr�cula e senha e tente novamente.\n\n");
    
    // Usar nosso componente para pausar e aguardar o ENTER
    ui_pausar(NULL);
    
    return 0; // sucesso
}

static estado_aplicacao processar(size_t entrada) {
    // Este estado sempre transita para o menu de login ap�s inicializa��o
    return ESTADO_MENU_LOGIN;
}

static void finalizar(void) {
    // N�o h� recursos espec�ficos para liberar neste estado
}

static estado_aplicacao obter_id(void) {
    return ESTADO_MSG_LOGIN_FALHA;
}

estado_t* criar_estado_msg_login_falha(void) {
    estado_t* estado = (estado_t*) malloc(sizeof(estado_t));
    if (estado) {
        estado->inicializar = inicializar;
        estado->processar = processar;
        estado->finalizar = finalizar;
        estado->obter_id = obter_id;
    }
    return estado;
}