// EcoLogica/src/business/auth.c
#include <stdio.h>
#include <string.h>
#include "crypto.h"
#include "auth.h"
#include "funcionario.h"
#include "session.h"

#define CRYPTO_KEY 0x5A  // Chave exemplo para a cifra XOR

// Funcionário padrão para validação (dados em plain text, para teste).
static Funcionario funcionarioPadrao = {12345, "senha123", "João Silva"};

void performLogin(void) {
    Funcionario funcionarioInput;
    char senhaInput[50];

    printf("Digite sua matrícula: ");
    if(scanf("%d", &funcionarioInput.matricula) != 1) {
        printf("Entrada inválida!\n");
        return;
    }
    while(getchar() != '\n'); // Limpa o buffer

    printf("Digite sua senha: ");
    if(scanf("%49s", senhaInput) != 1) {
        printf("Entrada inválida!\n");
        return;
    }
    while(getchar() != '\n'); // Limpa o buffer

    // Copia a senha digitada para o campo da estrutura
    strcpy(funcionarioInput.senha, senhaInput);
    // Criptografa a senha digitada utilizando a cifra XOR
    xorCipher(funcionarioInput.senha, CRYPTO_KEY);

    // Para comparação, criptografamos também a senha padrão
    char senhaCifradaPadrao[50];
    strcpy(senhaCifradaPadrao, funcionarioPadrao.senha);
    xorCipher(senhaCifradaPadrao, CRYPTO_KEY);

    // Validação: compara matrícula e senha (criptografada)
    if (funcionarioInput.matricula == funcionarioPadrao.matricula &&
        strcmp(funcionarioInput.senha, senhaCifradaPadrao) == 0) {
        printf("Login realizado com sucesso. Bem-vindo, %s!\n", funcionarioPadrao.nome);

        setUsuarioLogado(&funcionarioPadrao); // Armazena o usuário logado na sessão
    } else {
        printf("Matrícula ou senha incorretas.\n");
    }
}

