#include <stdio.h>
#include "logged_user_ui.h"
#include "funcionario.h"
#include "session.h"
#include "utils.h" // Para clearConsole

void showLoggedUser(void) {
    Funcionario *usuario = getUsuarioLogado();
    clearConsole(); // Limpa o console antes de exibir o usu�rio logado
    if (usuario != NULL) {
        printf("Usu�rio: %s (Matr: %d)\n", usuario->nome, usuario->matricula);
    } else {
        printf("Nenhum usu�rio logado.\n");        
    }
    printf("__________________________________________________\n");
}