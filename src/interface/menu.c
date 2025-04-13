// EcoLogica/src/interface/menu.c
#include <stdio.h>
#include "menu.h"
#include "auth.h"       // Placeholder para a funùùo de login
// #include "cadastro.h" // (Descomentar quando existir a funùùo de cadastro)
// #include "relatorios.h" // (Descomentar quando existir a funùùo de geraùùo de relatùrios)
#include "utils.h"            // Placeholder para a funùùo de limpeza de tela

void showMainMenu(void) {
    int option = -1;
    
    do {
        clearConsole(); // Limpa o console antes de exibir o menu
        printf("\nBem-vindo ao EcoLÛgica!\n");
        printf("Escolha uma opÁ„o:\n");
        printf("1. Login\n");
        printf("2. Cadastro\n");
        printf("3. RelatÛrios\n");
        printf("0. Sair\n");
        printf("OpÁ„o: ");
        
        if (scanf("%d", &option) != 1) {
            // Se a leitura falhar, limpar o buffer de entrada
            while(getchar() != '\n');
            option = -1;
        } else {
            while(getchar() != '\n'); // Limpar o buffer
        }
        
        // Limpa a tela apÛs a leitura da opÁ„o
        clearConsole(); // Limpa o console novamente para manter a interface limpa

        switch(option) {
            case 1:
                // Chamar a funÁ„o de login (placeholder)
                performLogin();
                break;
            case 2:
                // Placeholder para cadastro
                printf("FunÁ„o de cadastro ainda a ser implementada.\n");
                break;
            case 3:
                // Placeholder para geraÁ„o de relatÛrios
                printf("FunÁ„o de relatÛrios ainda a ser implementada.\n");
                break;
            case 0:
                printf("Saindo do sistema...\n");
                break;
            default:
                printf("OpÁ„o inv·lida, por favor tente novamente.\n");
        }
        pauseConsole(); // Pausa o console para o usu·rio ler a mensagem
    } while (option != 0);
}
