#include <stdio.h>
#include <string.h>
#include "industria_ui.h"
#include "industria.h"
#include "utils.h"               // Para clearConsole e pauseConsole
#include "industria_business.h"  // Para processar o cadastro de ind�stria
#include "logged_user_ui.h"      // Para mostrar o usu�rio logado
#include "screen_title_ui.h"     // Para mostrar o t�tulo da tela
#include "info_dialog_ui.h"     // Para mostrar mensagens de sucesso e erro

void iniciarInterfaceIndustria(void) {
    Industria novaIndustria;

    // Strings de t�tulo e mensagens
    const char *cadastroTitle = "EcoL�gica: Cadastro de Ind�stria";
    const char *msgCadastroSuccess = "Cadastro realizado com sucesso!";
    const char *msgCadastroError = "Erro ao cadastrar ind�stria!";
    const char *msgCnpjError = "Erro: CNPJ j� cadastrado!";
    const char *msgNomeInputError = "Erro: Nome da ind�stria inv�lido!";
    const char *msgRazaoSocialInputError = "Erro: Raz�o Social inv�lida!";
    const char *msgNomeFantasiaInputError = "Erro: Nome Fantasia inv�lido!";
    const char *msgTelefoneInputError = "Erro: Telefone inv�lido!";
    const char *msgEnderecoInputError = "Erro: Endere�o inv�lido!";
    const char *msgEmailInputError = "Erro: E-mail inv�lido!";
    const char *msgDataAberturaInputError = "Erro: Data de Abertura inv�lida!";
    const char *msgCnpjInputError = "Erro: CNPJ inv�lido!";

    
    showLoggedUser(); // Exibe o usu�rio logado, se houver

    showTitleScreen(cadastroTitle); // Exibe o t�tulo da tela de cadastro
    
    // Coleta o nome da ind�stria
    printf(">> Digite o nome da ind�stria: ");
    if (fgets(novaIndustria.nome, sizeof(novaIndustria.nome), stdin) == NULL) {
        //showCadastroErrorMessage("Erro na entrada do nome.");
        showErrorDialog(msgNomeInputError);
        return;
    }
    novaIndustria.nome[strcspn(novaIndustria.nome, "\n")] = '\0';
    
    // Coleta o CNPJ
    printf(">> Digite o CNPJ: ");
    if (scanf("%19s", novaIndustria.cnpj) != 1) {
        while(getchar() != '\n');
        //showCadastroErrorMessage("Erro na entrada do CNPJ.");
        showErrorDialog(msgCnpjInputError);
        return;
    }
    while(getchar() != '\n');
    
    // Coleta a Raz�o Social
    printf(">> Digite a Raz�o Social: ");
    if (fgets(novaIndustria.razaoSocial, sizeof(novaIndustria.razaoSocial), stdin) == NULL) {
        //showCadastroErrorMessage("Erro na entrada da Raz�o Social.");
        showErrorDialog(msgRazaoSocialInputError);
        return;
    }
    novaIndustria.razaoSocial[strcspn(novaIndustria.razaoSocial, "\n")] = '\0';
    
    // Coleta o Nome Fantasia
    printf(">> Digite o Nome Fantasia: ");
    if (fgets(novaIndustria.nomeFantasia, sizeof(novaIndustria.nomeFantasia), stdin) == NULL) {
        //showCadastroErrorMessage("Erro na entrada do Nome Fantasia.");
        showErrorDialog(msgNomeFantasiaInputError);
        return;
    }
    novaIndustria.nomeFantasia[strcspn(novaIndustria.nomeFantasia, "\n")] = '\0';
    
    // Coleta o Telefone
    printf(">> Digite o Telefone: ");
    if (scanf("%19s", novaIndustria.telefone) != 1) {
        while(getchar() != '\n');
        //showCadastroErrorMessage("Erro na entrada do Telefone.");
        showErrorDialog(msgTelefoneInputError);
        return;
    }
    while(getchar() != '\n');
    
    // Coleta o Endere�o
    printf(">> Digite o Endere�o: ");
    if (fgets(novaIndustria.endereco, sizeof(novaIndustria.endereco), stdin) == NULL) {
        //showCadastroErrorMessage("Erro na entrada do Endere�o.");
        showErrorDialog(msgEnderecoInputError);
        return;
    }
    novaIndustria.endereco[strcspn(novaIndustria.endereco, "\n")] = '\0';
    
    // Coleta o E-mail
    printf(">> Digite o E-mail: ");
    if (scanf("%99s", novaIndustria.email) != 1) {
        while(getchar() != '\n');
        //showCadastroErrorMessage("Erro na entrada do E-mail.");
        showErrorDialog(msgEmailInputError);
        return;
    }
    while(getchar() != '\n');
    
    // Coleta a Data de Abertura
    printf(">> Digite a Data de Abertura (dd/mm/yyyy): ");
    if (scanf("%19s", novaIndustria.dataAbertura) != 1) {
        while(getchar() != '\n');
        //showCadastroErrorMessage("Erro na entrada da Data de Abertura.");
        showErrorDialog(msgDataAberturaInputError);
        return;
    }
    while(getchar() != '\n');
    
    // Processa o cadastro por meio da camada de neg�cio
    if (processarCadastroIndustria(&novaIndustria) == 0) {
        showInfoDialog(msgCadastroSuccess); // Exibe mensagem de sucesso
    } else if (processarCadastroIndustria(&novaIndustria) == -1) {
        showErrorDialog(msgCnpjError); // Exibe mensagem de erro de CNPJ
    } else if (processarCadastroIndustria(&novaIndustria) == -2) {
        showErrorDialog(msgCadastroError);
    }
}
