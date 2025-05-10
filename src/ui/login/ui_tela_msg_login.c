#include <stdlib.h>
#include <stdio.h>

#include "ui/login/ui_tela_msg_login.h"
#include "ui/ui_comum.h"

void ui_desenhar_tela_msg_login_sucesso(char* nome_funcionario, int matricula) {
    ui_exibir_titulo("Login Realizado", "Autentica��o bem-sucedida");
    ui_exibir_sucesso("Login realizado com sucesso!");

    printf("\nBem-vindo(a), %s!\n", nome_funcionario);
    printf("Matr�cula: %d\n\n", matricula);

    ui_pausar(NULL);

    return;
}

void ui_desenhar_tela_msg_login_falha(void) {
    ui_exibir_titulo("Falha na Autentica��o", "N�o foi poss�vel realizar o login");    
    ui_exibir_erro("Usu�rio ou senha inv�lidos!");
    
    printf("\nAs credenciais fornecidas n�o s�o v�lidas.");
    printf("\nVerifique sua matr�cula e senha e tente novamente.\n\n");
    
    ui_pausar(NULL);
    
    return;
}