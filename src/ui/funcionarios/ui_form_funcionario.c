#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "ui/funcionarios/ui_form_funcionario.h"
#include "ui/ui_comum.h"


void ui_ler_matricula_cadastro_funcionario(int* matricula) {
    char buffer[20];
    //const char* prompt = ">> Digite sua matrícula: ";
    const char* prompt = PROMPT_FORM("Digite a matrícula do funcionário");

    while (1) {
        printf("%s", prompt);
        
        if (ui_ler_string(NULL, buffer, sizeof(buffer), true)) {
            char* endptr;
            *matricula = (int) strtol(buffer, &endptr, 10);
            
            if (*endptr != '\0' || *matricula <= 0) {
                ui_exibir_erro("Matrícula inválida. Digite apenas números.");
                continue;
            }
            return; // Sucesso
        } else {
            ui_exibir_erro("Entrada inválida");
            continue;
        }
    }
}

void ui_ler_nome_cadastro_funcionario(char* nome_buffer, size_t tamanho) {
    const char* prompt = PROMPT_FORM("Digite o nome do funcionário");
    while (1) {
        printf("%s", prompt);
        
        // Lê a entrada como string
        if (ui_ler_string(NULL, nome_buffer, tamanho, true)) {
            ui_converter_para_maiusculo(nome_buffer);
            return; // Nome lido com sucesso
        } else {
            ui_exibir_erro("Entrada inválida. Tente novamente.");
            continue;
        }
    }
}

void ui_ler_senha_segura_cadastro_funcionario(char* senha_buffer, size_t tamanho) {
    const char* prompt = PROMPT_FORM("Digite a senha do funcionário");
    while (1) {
        printf("%s", prompt);
        
        // Lê a entrada como string
        if (fgets(senha_buffer, tamanho, stdin) == NULL) {
            ui_exibir_erro("Erro na leitura da senha. Tente novamente.");
            continue;
        }
        
        // Remove o '\n' da entrada
        senha_buffer[strcspn(senha_buffer, "\n")] = '\0';
        
        // Verifica se a senha não está vazia
        if (strlen(senha_buffer) == 0) {
            ui_exibir_erro("Senha não pode ficar vazia. Tente novamente.");
            continue;
        }
        
        return; // Senha válida lida com sucesso
    }
}