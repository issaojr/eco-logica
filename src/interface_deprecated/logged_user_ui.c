#include <stdio.h>
#include "logged_user_ui.h"
#include "funcionario.h"
#include "session.h"
#include "utils.h" // Para clearConsole

void mostrar_usuario_autenticado(void) {
    Funcionario *usuario = get_usuario_logado();
    clear_console(); // Limpa o console antes de exibir o usuário logado
    if (usuario != NULL) {
        printf("Usuário: %s (Matr: %d)\n", usuario->nome, usuario->matricula);
    } else {
        printf("Nenhum usuário logado.\n");        
    }
    printf("__________________________________________________\n");
}