// EcoLogica/src/interface/menu.c
#include <stdio.h>
#include "menu.h"
#include "auth.h"       // Placeholder para a fun��o de login
// #include "cadastro.h" // (Descomentar quando existir a fun��o de cadastro)
// #include "relatorios.h" // (Descomentar quando existir a fun��o de gera��o de relat�rios)
#include "utils.h"            // Placeholder para a fun��o de limpeza de tela

void showMainMenu(void) {
    int option = -1;
    
    do {
        clearConsole(); // Limpa o console antes de exibir o menu
        printf("\nBem-vindo ao EcoL�gica!\n");
        printf("Escolha uma op��o:\n");
        printf("1. Login\n");
        printf("2. Cadastro\n");
        printf("3. Relat�rios\n");
        printf("0. Sair\n");
        printf("Op��o: ");
        
        if (scanf("%d", &option) != 1) {
            // Se a leitura falhar, limpar o buffer de entrada
            while(getchar() != '\n');
            option = -1;
        } else {
            while(getchar() != '\n'); // Limpar o buffer
        }
        
        // Limpa a tela ap�s a leitura da op��o
        clearConsole(); // Limpa o console novamente para manter a interface limpa

        switch(option) {
            case 1:
                // Chamar a fun��o de login (placeholder)
                performLogin();
                break;
            case 2:
                // Placeholder para cadastro
                printf("Fun��o de cadastro ainda a ser implementada.\n");
                break;
            case 3:
                // Placeholder para gera��o de relat�rios
                printf("Fun��o de relat�rios ainda a ser implementada.\n");
                break;
            case 0:
                printf("Saindo do sistema...\n");
                break;
            default:
                printf("Op��o inv�lida, por favor tente novamente.\n");
        }
        pauseConsole(); // Pausa o console para o usu�rio ler a mensagem
    } while (option != 0);
}
