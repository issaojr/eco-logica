// EcoLogica/src/business/auth.c
#include <stdio.h>
#include <string.h>
#include "crypto.h"
#include "auth.h"
#include "funcionario.h"
#include "session.h"

#define CRYPTO_KEY 0x5A  // Chave exemplo para a cifra XOR

// Funcion�rio padr�o para valida��o (dados em plain text, para teste).
static Funcionario funcionarioPadrao = {12345, "senha123", "Jo�o Silva"};

void performLogin(void) {
    Funcionario funcionarioInput;
    char senhaInput[50];

    printf("Digite sua matr�cula: ");
    if(scanf("%d", &funcionarioInput.matricula) != 1) {
        printf("Entrada inv�lida!\n");
        return;
    }
    while(getchar() != '\n'); // Limpa o buffer

    printf("Digite sua senha: ");
    if(scanf("%49s", senhaInput) != 1) {
        printf("Entrada inv�lida!\n");
        return;
    }
    while(getchar() != '\n'); // Limpa o buffer

    // Copia a senha digitada para o campo da estrutura
    strcpy(funcionarioInput.senha, senhaInput);
    // Criptografa a senha digitada utilizando a cifra XOR
    xorCipher(funcionarioInput.senha, CRYPTO_KEY);

    // Para compara��o, criptografamos tamb�m a senha padr�o
    char senhaCifradaPadrao[50];
    strcpy(senhaCifradaPadrao, funcionarioPadrao.senha);
    xorCipher(senhaCifradaPadrao, CRYPTO_KEY);

    // Valida��o: compara matr�cula e senha (criptografada)
    if (funcionarioInput.matricula == funcionarioPadrao.matricula &&
        strcmp(funcionarioInput.senha, senhaCifradaPadrao) == 0) {
        printf("Login realizado com sucesso. Bem-vindo, %s!\n", funcionarioPadrao.nome);

        setUsuarioLogado(&funcionarioPadrao); // Armazena o usu�rio logado na sess�o
    } else {
        printf("Matr�cula ou senha incorretas.\n");
    }
}

