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

        // Se nenhum usuário estiver logado, exibe menu com Login e Sair
        if (getUsuarioLogado() == NULL) {
            printf("Bem-vindo ao EcoLógica!\n");
            printf("1. Login\n");
            printf("0. Sair\n");
            printf("Opção: ");
            
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
                    printf("Opção inválida, por favor, tente novamente.\n");
            }
        }else {
            // Menu para usuário autenticado
            // Cadastro de outro usuário (ou outras funcionalidades) pode ser acessado por usuário autenticado
            Funcionario *usuario = getUsuarioLogado();
            printf("Usuário logado: %s (Matrícula: %d)\n", usuario->nome, usuario->matricula);
            printf("Escolha uma opção:\n");
            printf("1. Cadastro de usuário\n");   
            printf("2. Relatórios\n");
            printf("3. Logout\n");
            printf("0. Sair\n");
            printf("Opção: ");
            
            if (scanf("%d", &option) != 1) {
                while(getchar() != '\n');
                option = -1;
            } else {
                while(getchar() != '\n');
            }

        
            // Limpa a tela após a leitura da opção
            clearConsole(); // Limpa o console novamente para manter a interface limpa

            switch(option) {
                case 1:
                    // Placeholder para cadastro
                    printf("Função de cadastro ainda a ser implementada.\n");
                    break;
                case 2:
                    // Placeholder para geração de relatórios
                    printf("Função de relatórios ainda a ser implementada.\n");
                    break;
                case 3:
                    logout();
                    printf("Logout realizado com sucesso.\n");
                    break;
                case 0:
                    printf("Saindo do sistema...\n");
                    break;
                default:
                    printf("Opção inválida, por favor tente novamente.\n");
            }
            
        } 
        if (option != 0) {
            pauseConsole(NULL);  // Aguarda o usuário pressionar ENTER para continuar
        } else {
            // Se o usuário escolheu sair, exibe mensagem de encerramento
            clearConsole(); // Limpa o console antes de exibir a mensagem de encerramento
            pauseConsole("Obrigado por utilizar o EcoLógica!\nPressione ENTER para fechar o console...\n");
        }
    } while (option != 0);
}
