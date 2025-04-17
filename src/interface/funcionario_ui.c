#include <stdio.h>
#include <string.h>
#include "funcionario_ui.h"
#include "funcionario.h"
#include "crypto.h"     // Para usar xorCipher
#include "funcionario_business.h"   // Para usar processaCadastro
#include "utils.h"     // Para usar clearConsole

void iniciarInterfaceCadastro() {
    
    int matricula;
    char nome[150];
    char senha[50];

    printf("=== Cadastro de Usuário ===\n");

    // Coleta a matrícula
    printf("Digite a matrícula do novo usuário: ");
    if (scanf("%d", &matricula) != 1) {
        printf("Entrada inválida para matrícula.\n");
        while(getchar() != '\n'); // Limpa o buffer
        return;
    }
    while(getchar() != '\n'); // Limpa o buffer
    
    // Coleta o nome do novo usuário
    printf("Digite o nome do novo usuário: ");
    if (fgets(nome, sizeof(nome), stdin) == NULL) {
        printf("Erro na entrada do nome.\n");
        return;
    }
    nome[strcspn(nome, "\n")] = '\0';  // Remove a nova linha
    toUpperCase(nome); // Converte o nome para maiúsculas

    // Coleta a senha do novo usuário
    printf("Digite a senha do novo usuário: ");
    if (scanf("%49s", senha) != 1) {
        printf("Entrada inválida para senha.\n");
        while(getchar() != '\n');
        return;
    }
    while(getchar() != '\n'); // Limpa o buffer

    int resultado = processaCadastroFuncionario(matricula, nome, senha);

    // Verifica se o resultado do cadastro foi bem-sucedido
    if (resultado == 0) {
        printf("Usuário cadastrado com sucesso!\n");
    } else {
        printf("Erro ao cadastrar o usuário.\n");
    }
    
}
