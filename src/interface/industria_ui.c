#include <stdio.h>
#include <string.h>
#include "industria_ui.h"
#include "industria.h"
#include "utils.h"               // Para clearConsole e pauseConsole
#include "industria_business.h"  // Para processar o cadastro de indústria

void iniciarInterfaceIndustria(void) {
    Industria novaIndustria;
    
    clearConsole();
    printf("=== Cadastro de Indústria ===\n");
    
    // Coleta o nome da indústria
    printf("Digite o nome da indústria: ");
    if (fgets(novaIndustria.nome, sizeof(novaIndustria.nome), stdin) == NULL) {
        printf("Erro na entrada do nome.\n");
        return;
    }
    novaIndustria.nome[strcspn(novaIndustria.nome, "\n")] = '\0';
    
    // Coleta o CNPJ
    printf("Digite o CNPJ: ");
    if (scanf("%19s", novaIndustria.cnpj) != 1) {
        printf("Entrada inválida para CNPJ.\n");
        while(getchar() != '\n');
        return;
    }
    while(getchar() != '\n');
    
    // Coleta a Razão Social
    printf("Digite a Razão Social: ");
    if (fgets(novaIndustria.razaoSocial, sizeof(novaIndustria.razaoSocial), stdin) == NULL) {
        printf("Erro na entrada da Razão Social.\n");
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
        printf("Entrada inválida para Telefone.\n");
        while(getchar() != '\n');
        return;
    }
    while(getchar() != '\n');
    
    // Coleta o Endereço
    printf("Digite o Endereço: ");
    if (fgets(novaIndustria.endereco, sizeof(novaIndustria.endereco), stdin) == NULL) {
        printf("Erro na entrada do Endereço.\n");
        return;
    }
    novaIndustria.endereco[strcspn(novaIndustria.endereco, "\n")] = '\0';
    
    // Coleta o E-mail
    printf("Digite o E-mail: ");
    if (scanf("%99s", novaIndustria.email) != 1) {
        printf("Entrada inválida para E-mail.\n");
        while(getchar() != '\n');
        return;
    }
    while(getchar() != '\n');
    
    // Coleta a Data de Abertura
    printf("Digite a Data de Abertura (dd/mm/yyyy): ");
    if (scanf("%19s", novaIndustria.dataAbertura) != 1) {
        printf("Entrada inválida para a Data de Abertura.\n");
        while(getchar() != '\n');
        return;
    }
    while(getchar() != '\n');
    
    // Processa o cadastro por meio da camada de negócio
    if (processarCadastroIndustria(&novaIndustria) == 0) {
        printf("Indústria cadastrada com sucesso!\n");
    } else {
        printf("Erro ao cadastrar a indústria.\n");
    }
    
    pauseConsole("Pressione ENTER para continuar...");
}
