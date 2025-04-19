
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "login_ui.h"
#include "auth.h"        // Para performLogin
#include "utils.h"       // Para clearConsole e pauseConsole
#include "screen_title_ui.h" // Para showTitleScreen
#include "strings_globais.h" // Para strings globais
#include "info_dialog_ui.h" // Para showInfoDialog

void iniciarLogin(void) {
    clearConsole();

    int matricula;
    char senhaInput[50];
    int resultadoLogin;

    const char *loginTitle = "EcoLógica: Login";

    // Exibe o título da tela de login 
    showTitleScreen(loginTitle); 

    printf(">> Digite sua matrícula: ");
    if (scanf("%d", &matricula) != 1) {        
        while(getchar() != '\n');
        showInvalidInputMessage(); // Exibe mensagem de entrada inválida
        return;
    }
    while(getchar() != '\n'); // Limpa o buffer

    printf(">> Digite sua senha: ");
    if (scanf("%49s", senhaInput) != 1) {        
        while(getchar() != '\n');
        showInvalidInputMessage(); // Exibe mensagem de entrada inválida
        return;
    }
    while(getchar() != '\n'); // Limpa o buffer

    resultadoLogin = performLogin(matricula, senhaInput);

    if (resultadoLogin == 0) {
        showLoginSuccessMessage(); // Exibe mensagem de sucesso
    } else if (resultadoLogin == -2) {
        showLoginErrorMessage(); // Exibe mensagem de erro de login
    } else if (resultadoLogin == -1) {
        showMemoryErrorMessage(); // Exibe mensagem de erro de memória
    } else {
        showOtherErrorMessage(); // Exibe mensagem de erro genérico
    }
}

void showLoginSuccessMessage(void) {
    const char *msg = "Login realizado com sucesso!";
    showInfoDialog(msg); // Exibe mensagem de sucesso
}

void showLoginErrorMessage(void) {
    const char *msg = "Erro de login! Matrícula ou senha incorretas.";
    showErrorDialog(msg); // Exibe mensagem de erro de login
}

void showMemoryErrorMessage(void) {
    const char *msg = "Erro de memória! Por favor, reinicie o programa.";
    showErrorDialog(msg); // Exibe mensagem de erro de memória
}

void showOtherErrorMessage(void) {
    const char *msg = "Desculpe! Ocorreu um erro interno.";
    showErrorDialog(msg); // Exibe mensagem de erro genérico
}

void showInvalidInputMessage(void) {
    const char *msg = "Entrada inválida! Por favor, tente novamente.";
    showErrorDialog(msg);
}