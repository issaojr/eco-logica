// EcoLogica/src/interface/menu.c
#include <stdio.h>
#include "menu.h"
#include "auth.h"       // Placeholder para a funcao de login
// #include "cadastro.h" // (Descomentar quando existir a funcao de cadastro)
// #include "relatorios.h" // (Descomentar quando existir a funcao de geracao de relatorios)
#include "utils.h"            // Placeholder para a funcao de limpeza de tela
#include "session.h"         // Placeholder para a funcao de sessao

void showMainMenu(void) {
    int option = -1;
    
    do {
        clearConsole(); // Limpa o console antes de exibir o menu

        // Se nenhum usu�rio estiver logado, exibe menu com Login e Sair
        if (getUsuarioLogado() == NULL) {
            printf("Bem-vindo ao EcoL�gica!\n");
            printf("1. Login\n");
            printf("0. Sair\n");
            printf("Op��o: ");
            
            if (scanf("%d", &option) != 1) {
                while(getchar() != '\n'); // Limpa o buffer
                option = -1;
            } else {
                while(getchar() != '\n'); // Limpa o buffer
            }

            clearConsole(); // Limpa o console novamente para manter a interface limpa

            switch(option) {
                case 1:
                    performLogin();
                    break;
                case 0:
                    printf("Saindo do sistema...\n");
                    break;
                default:
                    printf("Op��o inv�lida, por favor, tente novamente.\n");
            }
        }else {
            // Menu para usu�rio autenticado
            // Cadastro de outro usu�rio (ou outras funcionalidades) pode ser acessado por usu�rio autenticado
            Funcionario *usuario = getUsuarioLogado();
            printf("Usu�rio logado: %s (Matr�cula: %d)\n", usuario->nome, usuario->matricula);
            printf("Escolha uma op��o:\n");
            printf("1. Cadastro de usu�rio\n");   
            printf("2. Relat�rios\n");
            printf("3. Logout\n");
            printf("0. Sair\n");
            printf("Op��o: ");
            
            if (scanf("%d", &option) != 1) {
                while(getchar() != '\n');
                option = -1;
            } else {
                while(getchar() != '\n');
            }

        
            // Limpa a tela ap�s a leitura da op��o
            clearConsole(); // Limpa o console novamente para manter a interface limpa

            switch(option) {
                case 1:
                    // Placeholder para cadastro
                    printf("Fun��o de cadastro ainda a ser implementada.\n");
                    break;
                case 2:
                    // Placeholder para gera��o de relat�rios
                    printf("Fun��o de relat�rios ainda a ser implementada.\n");
                    break;
                case 3:
                    logout();
                    printf("Logout realizado com sucesso.\n");
                    break;
                case 0:
                    printf("Saindo do sistema...\n");
                    break;
                default:
                    printf("Op��o inv�lida, por favor tente novamente.\n");
            }
            
        } 
        if (option != 0) {
            pauseConsole(NULL);  // Aguarda o usu�rio pressionar ENTER para continuar
        } else {
            // Se o usu�rio escolheu sair, exibe mensagem de encerramento
            clearConsole(); // Limpa o console antes de exibir a mensagem de encerramento
            pauseConsole("Obrigado por utilizar o EcoL�gica!\nPressione ENTER para fechar o console...\n");
        }
    } while (option != 0);
}
