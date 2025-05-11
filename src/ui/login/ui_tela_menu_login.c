#include "ui/login/ui_tela_menu_login.h"
#include "ui/ui_comum.h"


void ui_desenhar_tela_menu_login(void) {
    
    // Desenha tela de menu login
    ui_desenhar_tela_padrao(
        UI_TITULO_PROGRAMA, 
        UI_SUBTITULO_PROGRAMA, 
        NULL, 
        0
    );

    ui_exibir_data_hora();
    
    ui_exibir_info("Bem-Vindo(a)! Por favor, fa�a login para mais op��es.");
    printf("\n");
}

/* C�digos devem bater com o enum em estados.h */
const opcao_t tela_menu_login_mapa[] = {
    { 1, "Login" },
    { 2, "Sobre o projeto" },
    { 3, "Sair" }
};

const size_t tela_menu_login_mapa_n =
    sizeof(tela_menu_login_mapa) / sizeof(tela_menu_login_mapa[0]);

const char *tela_menu_login_prompt = PROMPT_OPCOES(1, 3);

void ui_desenhar_tela_form_login(void) {
    
    // Desenha tela de menu login
    ui_desenhar_tela_padrao(
        UI_TITULO_PROGRAMA, 
        UI_SUBTITULO_PROGRAMA, 
        NULL, 
        0
    );
}

void ui_ler_matricula(int* matricula) {
    char buffer[20];
    //const char* prompt = ">> Digite sua matr�cula: ";
    const char* prompt = PROMPT_FORM("Digite sua matr�cula");

    while (1) {
        printf("%s", prompt);
        
        if (ui_ler_string(NULL, buffer, sizeof(buffer), true)) {
            char* endptr;
            *matricula = (int) strtol(buffer, &endptr, 10);
            
            if (*endptr != '\0' || *matricula <= 0) {
                ui_exibir_erro("Matr�cula inv�lida. Digite apenas n�meros.");
                continue;
            }
            return; // Sucesso
        } else {
            ui_exibir_erro("Entrada inv�lida");
            continue;
        }
    }
}

void ui_ler_senha_segura(char* senha_buffer, size_t tamanho) {
    const char* prompt = PROMPT_FORM("Digite sua senha");
    while (1) {
        printf("%s", prompt);
        
        // L� a entrada como string
        if (fgets(senha_buffer, tamanho, stdin) == NULL) {
            ui_exibir_erro("Erro na leitura da senha. Tente novamente.");
            continue;
        }
        
        // Remove o '\n' da entrada
        senha_buffer[strcspn(senha_buffer, "\n")] = '\0';
        
        // Verifica se a senha n�o est� vazia
        if (strlen(senha_buffer) == 0) {
            ui_exibir_erro("Senha n�o pode ficar vazia. Tente novamente.");
            continue;
        }
        
        return; // Senha v�lida lida com sucesso
    }
}

