#include "menu_ui.h"

void menu_principal(void) {
    int opcao;
    
    do {
        clear_console(); // Limpa o console antes de exibir o menu
        opcao = OPCAO_INVALIDA; // Inicializa a opção como inválida

        // Se nenhum usuário estiver logado, exibe menu com Login e Sair
        if (get_usuario_logado() == NULL) {
            mostrar_menu_login(); // Exibe o menu de login
            
            //opcao = ler_opcao(NULL, opcoes_menu_login, num_opcoes_menu_login); // Lê a opção do usuário

            switch(opcao) {
                case 1:
                    iniciar_login(); // Chama a função de login
                    break;
                case 0:
                    break;
                default:
                    mostrar_msg_opcao_invalida(); // Exibe mensagem de opção inválida
            }
        }else {
            // Menu para usuário autenticado
            // Cadastro de outro usuário (ou outras funcionalidades) pode ser acessado por usuário autenticado
            Funcionario *funcionario = get_usuario_logado();
            
            mostrar_menu_principal(funcionario->nome, funcionario->matricula); // Exibe o menu do usuário
            
            //opcao = ler_opcao(NULL, opcoes_menu_principal, num_opcoes_menu_principal); // Lê a opção do usuário

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
                    iniciarInterfaceRelatorios(GLOBAL); // Chama a função de relatórios
                    break;
                case 9:
                    logout();
                    if(get_usuario_logado() == NULL) {
                        mostrar_msg_logout(); // Exibe mensagem de logout
                    } else {
                        mostrar_msg_opcao_invalida(); // Exibe mensagem de opção inválida
                    }
                    break;
                case 0:
                    break;
                default:
                    mostrar_msg_opcao_invalida(); // Exibe mensagem de opção inválida
            }
            
        }         
    } while (opcao != 0);

    mostrar_msg_saida(); // Exibe mensagem de encerramento
}

void mostrar_menu_login(void) {    
    clear_console(); // Limpa o console antes de exibir o menu
    // Exibe o título da tela de login
    mostrar_titulo(NOME_PROGRAMA);

    printf("1. Login\n");
    printf("0. Sair\n");
    printf("\n>> Opção: ");        
}

void mostrar_msg_saida(void) {
    const char *msg = "Agradecemos por utilizar o EcoLógica!";
    mostrar_dlg_info(msg); // Exibe mensagem de agradecimento
}

void mostrar_menu_principal(char *nome, int matricula) {
    mostrar_usuario_autenticado(); // Exibe o usuário logado

    // Exibe o título da tela de login
    mostrar_titulo("EcoLógica Soluções Ambientais");

    printf("Escolha uma opção >>\n\n");
    // Itera sobre o mapa de opções principais e imprime cada item
    // for (size_t i = 0; i < sizeof(opcao_principal_map) / sizeof(opcao_principal_map[0]); i++) {
    //     printf("%d. %s\n", opcao_principal_map[i].codigo, opcao_principal_map[i].msg);
    // }
    printf("\n>> Opção: ");
}

void mostrar_msg_logout(void) {
    const char *msg = "Você foi desconectado com sucesso!";
    mostrar_dlg_info(msg); // Exibe mensagem de desconexão
}

void mostrar_msg_opcao_invalida(void) {
    const char *msg = "Opção inválida, por favor tente novamente.";
    mostrar_dlg_info(msg);
}
