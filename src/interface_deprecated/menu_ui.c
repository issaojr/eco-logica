#include "menu_ui.h"

void menu_principal(void) {
    int opcao;
    
    do {
        clear_console(); // Limpa o console antes de exibir o menu
        opcao = OPCAO_INVALIDA; // Inicializa a op��o como inv�lida

        // Se nenhum usu�rio estiver logado, exibe menu com Login e Sair
        if (get_usuario_logado() == NULL) {
            mostrar_menu_login(); // Exibe o menu de login
            
            //opcao = ler_opcao(NULL, opcoes_menu_login, num_opcoes_menu_login); // L� a op��o do usu�rio

            switch(opcao) {
                case 1:
                    iniciar_login(); // Chama a fun��o de login
                    break;
                case 0:
                    break;
                default:
                    mostrar_msg_opcao_invalida(); // Exibe mensagem de op��o inv�lida
            }
        }else {
            // Menu para usu�rio autenticado
            // Cadastro de outro usu�rio (ou outras funcionalidades) pode ser acessado por usu�rio autenticado
            Funcionario *funcionario = get_usuario_logado();
            
            mostrar_menu_principal(funcionario->nome, funcionario->matricula); // Exibe o menu do usu�rio
            
            //opcao = ler_opcao(NULL, opcoes_menu_principal, num_opcoes_menu_principal); // L� a op��o do usu�rio

            switch (opcao) {
                case 1:
                    iniciar_interface_funcionario();
                    break;
                case 2:
                    iniciar_interface_industria();
                    break;
                case 3:
                    iniciar_interface_residuos();
                    break;
                case 4:
                    iniciarInterfaceRelatorios(POR_INDUSTRIA);
                    break;
                case 5:
                    iniciarInterfaceRelatorios(GLOBAL); // Chama a fun��o de relat�rios
                    break;
                case 9:
                    logout();
                    if(get_usuario_logado() == NULL) {
                        mostrar_msg_logout(); // Exibe mensagem de logout
                    } else {
                        mostrar_msg_opcao_invalida(); // Exibe mensagem de op��o inv�lida
                    }
                    break;
                case 0:
                    break;
                default:
                    mostrar_msg_opcao_invalida(); // Exibe mensagem de op��o inv�lida
            }
            
        }         
    } while (opcao != 0);

    mostrar_msg_saida(); // Exibe mensagem de encerramento
}

void mostrar_menu_login(void) {    
    clear_console(); // Limpa o console antes de exibir o menu
    // Exibe o t�tulo da tela de login
    mostrar_titulo(NOME_PROGRAMA);

    printf("1. Login\n");
    printf("0. Sair\n");
    printf("\n>> Op��o: ");        
}

void mostrar_msg_saida(void) {
    const char *msg = "Agradecemos por utilizar o EcoL�gica!";
    mostrar_dlg_info(msg); // Exibe mensagem de agradecimento
}

void mostrar_menu_principal(char *nome, int matricula) {
    mostrar_usuario_autenticado(); // Exibe o usu�rio logado

    // Exibe o t�tulo da tela de login
    mostrar_titulo("EcoL�gica Solu��es Ambientais");

    printf("Escolha uma op��o >>\n\n");
    // Itera sobre o mapa de op��es principais e imprime cada item
    // for (size_t i = 0; i < sizeof(opcao_principal_map) / sizeof(opcao_principal_map[0]); i++) {
    //     printf("%d. %s\n", opcao_principal_map[i].codigo, opcao_principal_map[i].msg);
    // }
    printf("\n>> Op��o: ");
}

void mostrar_msg_logout(void) {
    const char *msg = "Voc� foi desconectado com sucesso!";
    mostrar_dlg_info(msg); // Exibe mensagem de desconex�o
}

void mostrar_msg_opcao_invalida(void) {
    const char *msg = "Op��o inv�lida, por favor tente novamente.";
    mostrar_dlg_info(msg);
}
