// #include 

// "teste_menu.h"

// static const opcao_t opcao_login_map[] = {
//     { OPCAO_LOGIN_TESTE, "Login" },
//     { OPCAO_SOBRE_TESTE, "Sobre" },
//     { OPCAO_SAIR_TESTE, "Sair" },
// };

// static const opcao_t opcao_principal_map[] = {
//     { OPCAO_CADASTRO_FUNCIONARIO_TESTE, "Cadastro de Funcionário" },
//     { OPCAO_CADASTRO_INDUSTRIA_TESTE, "Cadastro de Indústria" },
//     { OPCAO_CADASTRO_RESIDUOS_TESTE, "Cadastro de Resíduos" },
//     { OPCAO_RELATORIOS_INDUSTRIA_TESTE, "Relatórios por Indústria" },
//     { OPCAO_RELATORIOS_GLOBAIS_TESTE, "Relatórios Globais" },
//     { OPCAO_LOGOUT_TESTE, "Logout" },
// };

// void teste_menu(void) {
//     char *titulo_str = "Menu";
//     codigo_opcao opcao = OPCAO_INVALIDA_TESTE; // Inicializa a opção como inválida   

//     while(1) {
//         // Limpa o console antes de exibir o menu
//         system("clear"); // Limpa o console (Linux/Unix)

//         printf("Ambiente de teste: %s\n", titulo_str);

//         mostrar_menu_login_teste(); // Exibe o menu de login para teste
        
//         printf("\n>> Opção: ");
//         opcao = ler_opcao_teste(opcao_login_map, TAMANHO_ARRAY(opcao_login_map), "Escolha uma opção: "); // Lê a opção do usuário
//         printf("Opção selecionada: %d\n", opcao); // Exibe a opção selecionada

//         if(opcao == OPCAO_INVALIDA_TESTE) {
//             printf("Opção inválida. Tente novamente.\n");
//         } else if (opcao == OPCAO_LOGIN_TESTE) {
//             mostrar_menu_principal_teste(); // Exibe o menu principal para teste
//             printf("\n>> Opção: ");
//             opcao = ler_opcao_teste(opcao_principal_map, TAMANHO_ARRAY(opcao_principal_map), "Escolha uma opção: "); // Lê a opção do usuário
//             printf("Opção selecionada: %d\n", opcao); // Exibe a opção selecionada
//         } else if (opcao == OPCAO_SOBRE_TESTE) {
//             printf("Você escolheu a opção Sobre.\n");
//         } else if (opcao == OPCAO_SAIR_TESTE) {
//             printf("Você escolheu a opção Sair.\n");
//             // pause
//             printf("Pressione Enter para Sair...\n");
//             getchar(); // Aguarda o usuário pressionar Enter
//             break; // Sai do loop e encerra o programa
//         } else {
//             printf("Opção desconhecida.\n");
//         }
//         // pause
//         printf("Pressione Enter para continuar...\n");
//         getchar(); // Aguarda o usuário pressionar Enter

//     }

    
// }

// void mostrar_menu_login_teste(void) {
//     imprimir_menu_teste(opcao_login_map, TAMANHO_ARRAY(opcao_login_map)); // Exibe o menu de login
// }

// void mostrar_menu_principal_teste(void) {
//     imprimir_menu_teste(opcao_principal_map, TAMANHO_ARRAY(opcao_principal_map)); // Exibe o menu principal
// }

// int ler_opcao_menu_teste(void) {
//     int opcao = -1;
//     char buffer[10]; // Buffer para armazenar a entrada do usuário

//     // Lê a opção do usuário
//     if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
//         opcao = atoi(buffer); // Converte a entrada para inteiro
//     }

//     return opcao; // Retorna a opção lida
// }

// /* imprime o menu (pode usar a função que você já tem) */
// void imprimir_menu_teste(const opcao_t *mapa, size_t n) {
//     for (size_t i = 0; i < n; i++)
//         printf("%2d) %s\n", mapa[i].codigo, mapa[i].msg);
// }

// /* retorna 1 se o código estiver no mapa */
// static int codigo_valido_teste(const opcao_t *mapa, size_t n, codigo_opcao c) {
//     for (size_t i = 0; i < n; i++)
//         if (mapa[i].codigo == c)
//             return 1;
//     return 0;
// }

// /* lê e retorna uma opção válida do mapa */
// codigo_opcao ler_opcao_teste(const opcao_t *mapa, size_t n, const char *prompt) {
//     int tmp;
//     char buf[32];
//     while (1) {
//         imprimir_menu_teste(mapa, n);
//         printf("%s", prompt);
//         if (!fgets(buf, sizeof buf, stdin)) {
//             /* EOF, trate como sair ou siga sua lógica */
//             return OPCAO_INVALIDA_TESTE;
//         }
//         char *endptr;
//         tmp = strtol(buf, &endptr, 10);
//         if (endptr == buf || *endptr != '\n') {
//             puts("Entrada inválida: digite um número.");
//             continue;
//         }
//         if (codigo_valido_teste(mapa, n, (codigo_opcao)tmp))
//             return (codigo_opcao)tmp;
//         puts("Opção não existe. Tente novamente.");
//     }
// }


