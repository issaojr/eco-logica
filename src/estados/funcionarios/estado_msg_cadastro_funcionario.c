#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estados/funcionarios/estado_msg_cadastro_funcionario.h"
#include "ui/funcionarios/ui_tela_msg_funcionarios.h"
#include "ui/ui_comum.h"

/* fun��es internas do estado */
static int inicializar(void) {
    // TODO: limpar tela, exibir t�tulo, etc.
    return 0; // sucesso
}

static estado_aplicacao processar(size_t entrada) {
    if(entrada == 0) {
        ui_desenhar_tela_msg_adicionar_funcionario_sucesso();
    } else if (entrada == 1) {
        ui_desenhar_tela_msg_adicionar_funcionario_falha();
        
    } else if (entrada == 2) {
        ui_desenhar_tela_msg_adicionar_funcionario_ja_existe();
    } else {
        ui_desenhar_tela_msg_adicionar_funcionario_falha();
    }
    return ESTADO_CADASTRO_FUNCIONARIOS; 
}

static void finalizar(void) {
    // TODO: liberar recursos alocados (se houver)
}

static estado_aplicacao obter_id(void) {
    return ESTADO_MSG_CADASTRO_FUNCIONARIO;  
}

estado_t* criar_estado_msg_cadastro_funcionario(void) {
    estado_t *estado = malloc(sizeof(estado_t));
    if (!estado) return NULL;

    estado->inicializar = inicializar;
    estado->processar   = processar;
    estado->finalizar   = finalizar;
    estado->obter_id    = obter_id;
    return estado;
}