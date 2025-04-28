#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>
//#include "utils.h"
//#include "menu_ui.h"
#include "menu.h"
//#include "tests/teste_menu.h"
#include "estados.h"
#include "tela_menu_login_ui.h"
#include "tela_menu_principal_ui.h"
// Incluídos para suportar cadastro de funcionário
#include "persistencia.h"
#include "funcionario.h"
#include "crypto.h"
#include "auth.h"
#include "session.h"  // Para get_usuario_logado

int main(void) {
    system("chcp 1252 > nul");  // Força o console a usar code page 1252

    // Define o locale para português do Brasil com CP-1252
    setlocale(LC_ALL, "Portuguese_Brazil.1252");    

    // Exibe o menu principal
    //menu_principal();   
    
    estado_aplicacao estado = ESTADO_MENU_LOGIN;
    while (estado != ESTADO_SAIR) {
        const opcao_t *mapa;
        size_t mapa_n;
        const char *prompt;

        /* 1) seleciona o menu conforme o estado */
        switch (estado) {
            case ESTADO_MENU_LOGIN:
                mapa   = tela_menu_login_mapa;
                mapa_n = tela_menu_login_mapa_n;
                prompt = tela_menu_login_prompt;
                
                break;

            case ESTADO_SOBRE_PROJETO:
                puts("Ainda não implementado!");
                estado = ESTADO_MENU_LOGIN;  // Retorna para o menu de login
                continue;  // Volta para o loop principal
                //mapa   = tela_sobre_mapa;
                //mapa_n = tela_sobre_mapa_n;
                //prompt = tela_sobre_prompt;
                //break;

            case ESTADO_MSG_LOGIN_SUCESSO:
                puts("+================================================+");
                puts("|          Login realizado com sucesso!          |");
                puts("+================================================+");
                printf("Pressione ENTER para continuar..."); getchar();
                estado = ESTADO_MENU_PRINCIPAL;
                continue;

            case ESTADO_MSG_LOGIN_FALHA:
                puts("+================================================+");
                puts("|    Erro! Usuário ou Senha Inválidos            |");
                puts("+================================================+");
                printf("Pressione ENTER para continuar..."); getchar();
                estado = ESTADO_MENU_LOGIN;
                continue;

            case ESTADO_MENU_PRINCIPAL:
                mapa   = tela_menu_principal_mapa;
                mapa_n = tela_menu_principal_mapa_n;
                prompt = tela_menu_principal_prompt;
                { // Cabeçalho com usuário autenticado
                    funcionario_t *u = get_usuario_logado();
                    if (u) {
                        printf("Usuário: %s (Matr: %d)\n", u->nome, u->matricula);
                        printf("__________________________________________________\n");
                    }
                }
                break;

            /* ... demais casos para cada estado que exiba opções ... */

            default:
                /* estados “de ação” (login, cadastros, etc.) são tratados aqui */
                switch (estado) {
                    case ESTADO_FORM_LOGIN: {
                        int matricula;
                        char senha[64];
                        printf(">> Digite sua matricula: ");
                        if (scanf("%d", &matricula) != 1) {
                            while (getchar() != '\n');
                            estado = ESTADO_MSG_LOGIN_FALHA;
                            continue;
                        }
                        printf(">> Digite sua senha: ");
                        scanf("%63s", senha);
                        while (getchar() != '\n');
                        bool ok = autenticar(matricula, senha);
                        estado = ok ? ESTADO_MSG_LOGIN_SUCESSO
                                    : ESTADO_MSG_LOGIN_FALHA;
                        continue;
                    }
                    case ESTADO_CADASTRO_FUNCIONARIO: {
                        puts("+================================================+");
                        puts("|        Cadastro de Funcionário               |");
                        puts("+================================================+");
                        printf("Funcionalidade de cadastro ainda não implementada.\n");
                        printf("Pressione ENTER para continuar..."); getchar();
                        estado = ESTADO_MENU_PRINCIPAL;
                        continue;
                    }
                    /* adicionar tratamentos para outros “estados de ação” */
                    default:
                        estado = ESTADO_SAIR;
                        continue;
                }
        }

        /* 2) imprime o menu genérico e lê escolha */
        imprimir_menu(mapa, mapa_n);
        codigo_opcao escolha = ler_opcao(mapa, mapa_n, prompt);

        /* 3) encontra o índice selecionado em mapa[] */
        size_t idx = 0;
        for (; idx < mapa_n; idx++) {
            if (mapa[idx].codigo == escolha) break;
        }

        /* 4) avança para o próximo estado */
        estado = obter_proximo_estado(estado, idx);
    }

    puts("Saindo do sistema...");
    return 0;
}
