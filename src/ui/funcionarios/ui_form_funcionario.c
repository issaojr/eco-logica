#include "ui/funcionarios/ui_form_funcionario.h"

void ui_ler_matricula_cadastro_funcionario(int* matricula) {
    char buffer[20];
    //const char* prompt = ">> Digite sua matr�cula: ";
    const char* prompt = PROMPT_FORM("Digite a matr�cula do funcion�rio");

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

void ui_ler_nome_cadastro_funcionario(char* nome_buffer, size_t tamanho) {
    const char* prompt = PROMPT_FORM("Digite o nome do funcion�rio");
    while (1) {
        printf("%s", prompt);
        
        // L� a entrada como string
        if (ui_ler_string(NULL, nome_buffer, tamanho, true)) {
            ui_converter_para_maiusculo(nome_buffer);
            return; // Nome lido com sucesso
        } else {
            ui_exibir_erro("Entrada inv�lida. Tente novamente.");
            continue;
        }
    }
}

void ui_ler_senha_segura_cadastro_funcionario(char* senha_buffer, size_t tamanho) {
    const char* prompt = PROMPT_FORM("Digite a senha do funcion�rio");
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