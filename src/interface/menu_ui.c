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
        option = -1; // Reinicia a op��o a cada itera��o

        // Se nenhum usu�rio estiver logado, exibe menu com Login e Sair
        if (getUsuarioLogado() == NULL) {
            showMenuLogin(); // Exibe o menu de login
            
            option = inputOption(); // L� a op��o do usu�rio

            switch(option) {
                case 1:
                    iniciarLogin(); // Chama a fun��o de login
                    break;
                case 0:
                    break;
                default:
                    showInvalidOptionMessage(); // Exibe mensagem de op��o inv�lida
            }
        }else {
            // Menu para usu�rio autenticado
            // Cadastro de outro usu�rio (ou outras funcionalidades) pode ser acessado por usu�rio autenticado
            Funcionario *usuario = getUsuarioLogado();
            
            showUserMenu(usuario->nome, usuario->matricula); // Exibe o menu do usu�rio
            
            option = inputOption(); // L� a op��o do usu�rio

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
                        showInvalidOptionMessage(); // Exibe mensagem de op��o inv�lida
                    }
                    break;
                case 0:
                    break;
                default:
                    showInvalidOptionMessage(); // Exibe mensagem de op��o inv�lida
            }
            
        }         
    } while (option != 0);

    showExitMessage(); // Exibe mensagem de encerramento
}

void showMenuLogin(void) {    
    clearConsole(); // Limpa o console antes de exibir o menu
    // Exibe o t�tulo da tela de login
    showTitleScreen(NOME_PROGRAMA);

    printf("1. Login\n");
    printf("0. Sair\n");
    printf("\n>> Op��o: ");        
}

void showExitMessage(void) {
    const char *msg = "Agradecemos por utilizar o EcoL�gica!";
    showInfoDialog(msg); // Exibe mensagem de agradecimento
}

void showUserMenu(char *nome, int matricula) {
    showLoggedUser(); // Exibe o usu�rio logado

    // Exibe o t�tulo da tela de login
    showTitleScreen("EcoL�gica Solu��es Ambientais");

    printf("Escolha uma op��o >>\n\n");
    printf("1. Cadastro de usu�rio\n");
    printf("2. Cadastro de ind�stria\n");
    printf("3. Atualiza��o Mensal de Res�duos\n");
    printf("4. Relat�rios\n");
    printf("5. Logout\n");
    printf("0. Sair\n");
    printf("\n>> Op��o: ");
}

void showUserLogoutMessage(void) {
    const char *msg = "Voc� foi desconectado com sucesso!";
    showInfoDialog(msg); // Exibe mensagem de desconex�o
}

void showInvalidOptionMessage(void) {
    const char *msg = "Op��o inv�lida, por favor tente novamente.";
    showInfoDialog(msg);
}