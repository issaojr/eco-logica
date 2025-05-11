#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "estados/login/estado_form_login.h"
#include "business/business_auth.h"
#include "ui/ui_comum.h"
#include "ui/ui_formulario.h"
#include "ui/login/ui_tela_menu_login.h"

// Variáveis específicas deste estado
static int matricula;
static char senha[64];

// Funções específicas deste estado
static int inicializar(void) {
    
    matricula = 0;
    memset(senha, 0, sizeof(senha));
    
    
    
    return 0; // sucesso
}

static estado_aplicacao processar(size_t entrada) {
    // Desenha a tela de login
    ui_desenhar_tela_form_login();

    ui_desenhar_cabecalho("INFORME SUAS CREDENCIAIS");

    // Apresenta formulário de login.
    // Matrícula e senha são lidas pelas funções de UI
    ui_ler_matricula(&matricula);
    ui_ler_senha_segura(senha, sizeof(senha));

    // O processamento das credenciais é delegado à função de autenticação
    // na camada business (auth.h)
    // Se a autenticação for bem-sucedida, o funcionário é armazenado na sessão
    business_autenticar(matricula, senha);

    // O ESTADO_MSG_LOGIN verifica se o funcionário está logado na sessão
    // e exibe a mensagem apropriada, seja sucesso ou falha, redirecionando
    // para o menu principal ou de login, respectivamente.
    return ESTADO_MSG_LOGIN;
}

static void finalizar(void) {
    // Limpa a senha após o uso
    memset(senha, 0, sizeof(senha));
}

static estado_aplicacao obter_id(void) {
    return ESTADO_FORM_LOGIN;
}

estado_t* criar_estado_form_login(void) {
    estado_t* estado = (estado_t*) malloc(sizeof(estado_t));
    if (estado) {
        estado->inicializar = inicializar;
        estado->processar = processar;
        estado->finalizar = finalizar;
        estado->obter_id = obter_id;
    }
    return estado;
}