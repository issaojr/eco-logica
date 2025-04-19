#include <stdio.h>
#include "menu_ui.h"
#include "funcionario_ui.h" // Placeholder para a funcao de cadastro
#include "utils.h"            // Placeholder para a funcao de limpeza de tela
#include "session.h"         // Placeholder para a funcao de sessao
#include "industria_ui.h"    // Placeholder para a funcao de cadastro de industria
#include "residuos_ui.h"     // Placeholder para a funcao de residuos
#include "relatorios_ui.h"   // Placeholder para a funcao de relatorios
#include "login_ui.h"
#include "logged_user_ui.h" // Placeholder para a funcao de usuario logado
#include "strings_globais.h" // Placeholder para a funcao de strings globais
#include "screen_title_ui.h" // Placeholder para a funcao de titulo da tela
#include "info_dialog_ui.h" // Placeholder para a funcao de dialogo de informacao

void showMainMenu(void) {
    int option;
    
    do {
        clearConsole(); // Limpa o console antes de exibir o menu
        option = -1; // Reinicia a opção a cada iteração

        // Se nenhum usuário estiver logado, exibe menu com Login e Sair
        if (getUsuarioLogado() == NULL) {
            showMenuLogin(); // Exibe o menu de login
            
            option = inputOption(); // Lê a opção do usuário

            switch(option) {
                case 1:
                    iniciarLogin(); // Chama a função de login
                    break;
                case 0:
                    break;
                default:
                    showInvalidOptionMessage(); // Exibe mensagem de opção inválida
            }
        }else {
            // Menu para usuário autenticado
            // Cadastro de outro usuário (ou outras funcionalidades) pode ser acessado por usuário autenticado
            Funcionario *usuario = getUsuarioLogado();
            
            showUserMenu(usuario->nome, usuario->matricula); // Exibe o menu do usuário
            
            option = inputOption(); // Lê a opção do usuário

            switch (option) {
                case 1:
                    iniciarInterfaceFuncionario();
                    break;
                case 2:
                    iniciarInterfaceIndustria();
                    break;
                case 3:
                    iniciarInterfaceResiduos();
                    break;
                case 4:
                    iniciarInterfaceRelatorios();
                    break;
                case 5:
                    logout();
                    if(getUsuarioLogado() == NULL) {
                        showUserLogoutMessage(); // Exibe mensagem de logout
                    } else {
                        showInvalidOptionMessage(); // Exibe mensagem de opção inválida
                    }
                    break;
                case 0:
                    break;
                default:
                    showInvalidOptionMessage(); // Exibe mensagem de opção inválida
            }
            
        }         
    } while (option != 0);

    showExitMessage(); // Exibe mensagem de encerramento
}

void showMenuLogin(void) {    
    clearConsole(); // Limpa o console antes de exibir o menu
    // Exibe o título da tela de login
    showTitleScreen(NOME_PROGRAMA);

    printf("1. Login\n");
    printf("0. Sair\n");
    printf("\n>> Opção: ");        
}

void showExitMessage(void) {
    const char *msg = "Agradecemos por utilizar o EcoLógica!";
    showInfoDialog(msg); // Exibe mensagem de agradecimento
}

void showUserMenu(char *nome, int matricula) {
    showLoggedUser(); // Exibe o usuário logado

    // Exibe o título da tela de login
    showTitleScreen("EcoLógica Soluções Ambientais");

    printf("Escolha uma opção >>\n\n");
    printf("1. Cadastro de usuário\n");
    printf("2. Cadastro de indústria\n");
    printf("3. Atualização Mensal de Resíduos\n");
    printf("4. Relatórios\n");
    printf("5. Logout\n");
    printf("0. Sair\n");
    printf("\n>> Opção: ");
}

void showUserLogoutMessage(void) {
    const char *msg = "Você foi desconectado com sucesso!";
    showInfoDialog(msg); // Exibe mensagem de desconexão
}

void showInvalidOptionMessage(void) {
    const char *msg = "Opção inválida, por favor tente novamente.";
    showInfoDialog(msg);
}