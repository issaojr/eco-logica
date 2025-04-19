#include <stdio.h>
#include <string.h>
#include "funcionario_ui.h"
#include "funcionario.h"
#include "crypto.h"     // Para usar xorCipher
#include "funcionario_business.h"   // Para usar processaCadastro
#include "utils.h"     // Para usar clearConsole
#include "logged_user_ui.h" // Para usar showLoggedUser
#include "screen_title_ui.h" // Para usar showTitleScreen
#include "info_dialog_ui.h" // Para usar showCadastroSuccessMessage e showCadastroErrorMessage

void iniciarInterfaceFuncionario() {
    
    int matricula;
    char nome[150];
    char senha[50];

    const char *cadastroTitle = "EcoLógica: Cadastro de Funcionário";
    const char *msgCadastroSuccess = "Cadastro realizado com sucesso!";
    const char *msgCadastroError = "Erro ao cadastrar funcionário!";

    showLoggedUser(); // Exibe o usuário logado, se houver
    showTitleScreen(cadastroTitle); // Exibe o título da tela de cadastro

    // Coleta a matrícula
    printf(">> Digite a matrícula do novo usuário: ");
    if (scanf("%d", &matricula) != 1) {
        printf("Entrada inválida para matrícula.\n");
        while(getchar() != '\n'); // Limpa o buffer
        return;
    }
    while(getchar() != '\n'); // Limpa o buffer
    
    // Coleta o nome do novo usuário
    printf(">> Digite o nome do novo usuário: ");
    if (fgets(nome, sizeof(nome), stdin) == NULL) {
        printf("Erro na entrada do nome.\n");
        return;
    }
    nome[strcspn(nome, "\n")] = '\0';  // Remove a nova linha
    toUpperCase(nome); // Converte o nome para maiúsculas

    // Coleta a senha do novo usuário
    printf(">> Digite a senha do novo usuário: ");
    if (scanf("%49s", senha) != 1) {
        printf("Entrada inválida para senha.\n");
        while(getchar() != '\n');
        return;
    }
    while(getchar() != '\n'); // Limpa o buffer

    int resultado = processaCadastroFuncionario(matricula, nome, senha);

    // Verifica se o resultado do cadastro foi bem-sucedido
    if (resultado == 0) {
        showInfoDialog(msgCadastroSuccess); // Exibe mensagem de sucesso
    } else {
        showErrorDialog(msgCadastroError); // Exibe mensagem de erro
    }
    
}
