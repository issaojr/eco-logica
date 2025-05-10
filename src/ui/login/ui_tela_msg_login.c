#include <stdlib.h>
#include <stdio.h>

#include "ui/login/ui_tela_msg_login.h"
#include "ui/ui_comum.h"

void ui_desenhar_tela_msg_login_sucesso(char* nome_funcionario, int matricula) {
    ui_exibir_titulo("Login Realizado", "Autenticação bem-sucedida");
    ui_exibir_sucesso("Login realizado com sucesso!");

    printf("\nBem-vindo(a), %s!\n", nome_funcionario);
    printf("Matrícula: %d\n\n", matricula);

    ui_pausar(NULL);

    return;
}

void ui_desenhar_tela_msg_login_falha(void) {
    ui_exibir_titulo("Falha na Autenticação", "Não foi possível realizar o login");    
    ui_exibir_erro("Usuário ou senha inválidos!");
    
    printf("\nAs credenciais fornecidas não são válidas.");
    printf("\nVerifique sua matrícula e senha e tente novamente.\n\n");
    
    ui_pausar(NULL);
    
    return;
}