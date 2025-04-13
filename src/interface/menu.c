// EcoLogica/src/interface/menu.c
#include <stdio.h>
#include "menu.h"
#include "auth.h"       // Placeholder para a função de login
// #include "cadastro.h" // (Descomentar quando existir a função de cadastro)
// #include "relatorios.h" // (Descomentar quando existir a função de geração de relatórios)
#include "utils.h"            // Placeholder para a função de limpeza de tela

void showMainMenu(void) {
    int option = -1;
    
    do {
        clearConsole(); // Limpa o console antes de exibir o menu
        printf("\nBem-vindo ao EcoLógica!\n");
        printf("Escolha uma opção:\n");
        printf("1. Login\n");
        printf("2. Cadastro\n");
        printf("3. Relatórios\n");
        printf("0. Sair\n");
        printf("Opção: ");
        
        if (scanf("%d", &option) != 1) {
            // Se a leitura falhar, limpar o buffer de entrada
            while(getchar() != '\n');
            option = -1;
        } else {
            while(getchar() != '\n'); // Limpar o buffer
        }
        
        // Limpa a tela após a leitura da opção
        clearConsole(); // Limpa o console novamente para manter a interface limpa

        switch(option) {
            case 1:
                // Chamar a função de login (placeholder)
                performLogin();
                break;
            case 2:
                // Placeholder para cadastro
                printf("Função de cadastro ainda a ser implementada.\n");
                break;
            case 3:
                // Placeholder para geração de relatórios
                printf("Função de relatórios ainda a ser implementada.\n");
                break;
            case 0:
                printf("Saindo do sistema...\n");
                break;
            default:
                printf("Opção inválida, por favor tente novamente.\n");
        }
        pauseConsole(); // Pausa o console para o usuário ler a mensagem
    } while (option != 0);
}
