#include <stdlib.h>
#include <stdio.h>
#include "estados/login/estado_msg_login_sucesso.h"
#include "session.h"
#include "ui/ui_comum.h"

// Funções específicas deste estado
static int inicializar(void) {
    // Obter informações do usuário logado para personalizar a mensagem
    funcionario_t *usuario = get_funcionario_logado();
    
    // Exibir título e mensagem de sucesso usando nossos componentes de UI
    ui_exibir_titulo("Login Realizado", "Autenticação bem-sucedida");
    
    ui_exibir_sucesso("Login realizado com sucesso!");
    
    if (usuario) {
        printf("\nBem-vindo(a), %s!\n", usuario->nome);
        printf("Matrícula: %d\n\n", usuario->matricula);
    }
    
    // Usar nosso componente para pausar e aguardar o ENTER
    ui_pausar(NULL);
    
    return 0; // sucesso
}

static estado_aplicacao processar(size_t entrada) {
    // Este estado sempre transita para o menu principal após inicialização
    return ESTADO_MENU_PRINCIPAL;
}

static void finalizar(void) {
    // Não há recursos específicos para liberar neste estado
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