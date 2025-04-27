#include "info_dialog_ui.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"
#include "strings_globais.h"

static const struct {
    codigo_info codigo;
    const char *msg;
} info_map[] = {
    { INFO_CADASTRO_FUNCIONARIO_SUCESSO, "Cadastro de funcion�rio realizado com sucesso!" },
    { INFO_CADASTRO_INDUSTRIA_SUCESSO, "Cadastro de ind�stria realizado com sucesso!" },
    { TITULO_CADASTRO_FUNCIONARIO, "EcoL�gica: Cadastro de Funcion�rio" },
    { TITULO_CADASTRO_INDUSTRIA, "EcoL�gica: Cadastro de Ind�stria" },
    { TITULO_CADASTRO_RESIDUOS, "EcoL�gica: Cadastro de Res�duos" },
};

const char *info_msg(codigo_info codigo) {
    for (size_t i = 0; i < sizeof(info_map)/sizeof(info_map[0]); i++) {
        if (info_map[i].codigo == codigo)
            return info_map[i].msg;
    }
    return "Erro desconhecido.";
}


/*
static const struct {
    codigo_opcao_login codigo;
    const char *msg;
} opcao_login_map[] = {
    { OPCAO_INVALIDA, "Op��o inv�lida." },
    { OPCAO_LOGIN, "Login" },
    { OPCAO_SOBRE, "Sobre" },
    { OPCAO_SAIR, "Sair" },
};

const char *opcao_login_msg(codigo_opcao_login codigo) {
    for (size_t i = 0; i < sizeof(opcao_login_map)/sizeof(opcao_login_map[0]); i++) {
        if (opcao_login_map[i].codigo == codigo)
            return opcao_login_map[i].msg;
    }
    return "Op��o inv�lida.";
}

static const struct {
    codigo_opcao_principal codigo;
    const char *msg;
} opcao_principal_map[] = {
    { PRINCIPAL_OPCAO_INVALIDA, "Op��o inv�lida." },
    { OPCAO_CADASTRO_FUNCIONARIO, "Cadastro de Funcion�rio" },
    { OPCAO_CADASTRO_INDUSTRIA, "Cadastro de Ind�stria" },
    { OPCAO_CADASTRO_RESIDUOS, "Cadastro de Res�duos" },
    { OPCAO_RELATORIOS_INDUSTRIA, "Relat�rios por Ind�stria" },
    { OPCAO_RELATORIOS_GLOBAIS, "Relat�rios Globais" },
    { OPCAO_LOGOUT, "Logout" },
};

const char *opcao_principal_msg(codigo_opcao_principal codigo) {
    for (size_t i = 0; i < sizeof(opcao_principal_map)/sizeof(opcao_principal_map[0]); i++) {
        if (opcao_principal_map[i].codigo == codigo)
            return opcao_principal_map[i].msg;
    }
    return "Op��o inv�lida.";
}
*/



/**
 * Exibe uma mensagem informativa.
 * @param msg Mensagem a ser exibida. Deve possuir 48 caracteres, no m�ximo.
 */
void mostrar_dlg_info(const char * msg) {
    clear_console(); // Limpa o console antes de exibir a mensagem
    
    // cria uma c�pia centralizada (48 cols)  
    char *aligned = centerMessageDefault(msg);

    if (!aligned) {
        // fallback: s� imprime a msg original
        aligned = strdup(msg);
    }

    printf("+================================================+\n");
    printf("|%s|\n", aligned);
    printf("+================================================+\n\n");

    aligned = libera_mem_str(aligned); // Libera a mem�ria alocada para a mensagem

    mostrar_msg_pausa(); // Pausa o console com a mensagem
}

/**
 * Centraliza uma mensagem em um espa�o de 50 caracteres.
 * @param msg Mensagem a ser centralizada. Deve possuir 48 caracteres, no m�ximo.
 * @param len Comprimento da mensagem original.
 * @param totalLen Comprimento total do espa�o dispon�vel (50).
 */
void mostrar_dlg_erro(const char * msg) {
    clear_console(); // Limpa o console antes de exibir a mensagem de erro

    // se vier NULL, usa a mensagem padr�o
    const char *base = msg ? msg : "Desculpe! Ocorreu um Erro interno.";

    char *aligned = centerMessageDefault(base);
    if (!aligned) {
        aligned = strdup(base);
    }

    printf("+================================================+\n");
    printf("|%s|\n", aligned);
    printf("+================================================+\n\n");

    aligned = libera_mem_str(aligned);

    mostrar_msg_pausa();
}

void mostrar_msg_pausa(void) {

    // obt�m buffer alocado j� alinhado � direita
    char *aligned = rightAlignMessageDefault(MSG_ENTER_CONTINUAR);
    if (!aligned) {
        aligned = strdup(MSG_ENTER_CONTINUAR);
    }

    // exibe e aguarda ENTER
    pauseConsole(aligned);

    aligned = libera_mem_str(aligned);
}

void mostrar_msg_erro(const char *msg) {
    printf("\n**ERRO: %s\n", msg);
}