#include <stdio.h>
#include <string.h>
#include "cadastro_ui.h"
#include "funcionario.h"
#include "crypto.h"     // Para usar xorCipher
#include "cadastro.h"   // Para usar processaCadastro
#include "utils.h"     // Para usar clearConsole

void iniciarInterfaceCadastro() {
    
    int matricula;
    char nome[150];
    char senha[50];

    printf("=== Cadastro de Usu�rio ===\n");

    // Coleta a matr�cula
    printf("Digite a matr�cula do novo usu�rio: ");
    if (scanf("%d", &matricula) != 1) {
        printf("Entrada inv�lida para matr�cula.\n");
        while(getchar() != '\n'); // Limpa o buffer
        return;
    }
    while(getchar() != '\n'); // Limpa o buffer
    
    // Coleta o nome do novo usu�rio
    printf("Digite o nome do novo usu�rio: ");
    if (fgets(nome, sizeof(nome), stdin) == NULL) {
        printf("Erro na entrada do nome.\n");
        return;
    }
    nome[strcspn(nome, "\n")] = '\0';  // Remove a nova linha

    // Coleta a senha do novo usu�rio
    printf("Digite a senha do novo usu�rio: ");
    if (scanf("%49s", senha) != 1) {
        printf("Entrada inv�lida para senha.\n");
        while(getchar() != '\n');
        return;
    }
    while(getchar() != '\n'); // Limpa o buffer

    int resultado = processaCadastro(matricula, nome, senha);

    // Verifica se o resultado do cadastro foi bem-sucedido
    if (resultado == 0) {
        printf("Usu�rio cadastrado com sucesso!\n");
    } else {
        printf("Erro ao cadastrar o usu�rio.\n");
    }
    
}
