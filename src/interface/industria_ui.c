#include <stdio.h>
#include <string.h>
#include "industria_ui.h"
#include "industria.h"
#include "utils.h"               // Para clearConsole e pauseConsole
#include "industria_business.h"  // Para processar o cadastro de ind�stria

void iniciarInterfaceIndustria(void) {
    Industria novaIndustria;
    
    clearConsole();
    printf("=== Cadastro de Ind�stria ===\n");
    
    // Coleta o nome da ind�stria
    printf("Digite o nome da ind�stria: ");
    if (fgets(novaIndustria.nome, sizeof(novaIndustria.nome), stdin) == NULL) {
        printf("Erro na entrada do nome.\n");
        return;
    }
    novaIndustria.nome[strcspn(novaIndustria.nome, "\n")] = '\0';
    
    // Coleta o CNPJ
    printf("Digite o CNPJ: ");
    if (scanf("%19s", novaIndustria.cnpj) != 1) {
        printf("Entrada inv�lida para CNPJ.\n");
        while(getchar() != '\n');
        return;
    }
    while(getchar() != '\n');
    
    // Coleta a Raz�o Social
    printf("Digite a Raz�o Social: ");
    if (fgets(novaIndustria.razaoSocial, sizeof(novaIndustria.razaoSocial), stdin) == NULL) {
        printf("Erro na entrada da Raz�o Social.\n");
        return;
    }
    novaIndustria.razaoSocial[strcspn(novaIndustria.razaoSocial, "\n")] = '\0';
    
    // Coleta o Nome Fantasia
    printf("Digite o Nome Fantasia: ");
    if (fgets(novaIndustria.nomeFantasia, sizeof(novaIndustria.nomeFantasia), stdin) == NULL) {
        printf("Erro na entrada do Nome Fantasia.\n");
        return;
    }
    novaIndustria.nomeFantasia[strcspn(novaIndustria.nomeFantasia, "\n")] = '\0';
    
    // Coleta o Telefone
    printf("Digite o Telefone: ");
    if (scanf("%19s", novaIndustria.telefone) != 1) {
        printf("Entrada inv�lida para Telefone.\n");
        while(getchar() != '\n');
        return;
    }
    while(getchar() != '\n');
    
    // Coleta o Endere�o
    printf("Digite o Endere�o: ");
    if (fgets(novaIndustria.endereco, sizeof(novaIndustria.endereco), stdin) == NULL) {
        printf("Erro na entrada do Endere�o.\n");
        return;
    }
    novaIndustria.endereco[strcspn(novaIndustria.endereco, "\n")] = '\0';
    
    // Coleta o E-mail
    printf("Digite o E-mail: ");
    if (scanf("%99s", novaIndustria.email) != 1) {
        printf("Entrada inv�lida para E-mail.\n");
        while(getchar() != '\n');
        return;
    }
    while(getchar() != '\n');
    
    // Coleta a Data de Abertura
    printf("Digite a Data de Abertura (dd/mm/yyyy): ");
    if (scanf("%19s", novaIndustria.dataAbertura) != 1) {
        printf("Entrada inv�lida para a Data de Abertura.\n");
        while(getchar() != '\n');
        return;
    }
    while(getchar() != '\n');
    
    // Processa o cadastro por meio da camada de neg�cio
    if (processarCadastroIndustria(&novaIndustria) == 0) {
        printf("Ind�stria cadastrada com sucesso!\n");
    } else {
        printf("Erro ao cadastrar a ind�stria.\n");
    }
    
    pauseConsole("Pressione ENTER para continuar...");
}
