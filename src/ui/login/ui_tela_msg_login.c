#include <stdlib.h>
#include <stdio.h>

#include "ui/login/ui_tela_msg_login.h"
#include "ui/login/ui_tela_menu_login.h"
#include "ui/ui_comum.h"

void ui_desenhar_tela_msg_login_sucesso(const char *nome_funcionario, const int matricula) {
    ui_desenhar_tela_padrao(
        UI_TITULO_PROGRAMA,
        UI_SUBTITULO_LOGIN_SUCESSO,
        NULL,
        0
    );

    printf("\n");
    ui_exibir_separador('*', UI_LARGURA_PADRAO);
    ui_exibir_sucesso("Login realizado com sucesso!");
    printf("\n");
    ui_exibir_separador('*', UI_LARGURA_PADRAO);
    printf("\n");

    printf("Bem-vindo(a), %s!\n", nome_funcionario);
    printf("Matrícula: %d\n", matricula);

    printf("\n");
    ui_prompt_continuar(NULL);

    return;
}

void ui_desenhar_tela_msg_login_falha(void) {
    ui_desenhar_tela_padrao(
        UI_TITULO_PROGRAMA,
        UI_SUBTITULO_LOGIN_FALHA,
        NULL,
        0
    );

    printf("\n");
    ui_exibir_separador('*', UI_LARGURA_PADRAO);
    ui_exibir_erro("Login falhou. Verifique suas credenciais.");
    printf("\n");
    ui_exibir_separador('*', UI_LARGURA_PADRAO);
    printf("\n");

    ui_prompt_voltar_inicio(NULL);
    
    return;
}

void ui_desenhar_msg_logout_sucesso(void) {
    ui_desenhar_tela_padrao(
        UI_TITULO_PROGRAMA,
        UI_SUBTITULO_LOGIN_SUCESSO,
        NULL,
        0
    );

    printf("\n");
    ui_exibir_separador('*', UI_LARGURA_PADRAO);
    ui_exibir_sucesso("Logout realizado com sucesso!");
    printf("\n");
    ui_exibir_separador('*', UI_LARGURA_PADRAO);
    printf("\n");

    ui_prompt_voltar_inicio(NULL);
    
    return;
}

void ui_desenhar_tela_msg_logout_falha(void) {
    ui_desenhar_tela_padrao(
        UI_TITULO_PROGRAMA,
        UI_SUBTITULO_LOGIN_FALHA,
        NULL,
        0
    );

    printf("\n");
    ui_exibir_separador('*', UI_LARGURA_PADRAO);
    ui_exibir_erro("Logout falhou. Tente novamente.");
    printf("\n");
    ui_exibir_separador('*', UI_LARGURA_PADRAO);
    printf("\n");

    ui_prompt_voltar_menu_anterior(NULL);
    
    return;
}