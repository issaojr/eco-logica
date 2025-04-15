// EcoLogica/src/business/auth.c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>     // Para usar malloc e free
#include "crypto.h"
#include "auth.h"
#include "funcionario.h"
#include "session.h"
#include "persistencia.h"

/*
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
    */

    void performLogin(void) {
        int matricula;
        char senhaInput[50];
        Funcionario temp;
    
        printf("Digite sua matr�cula: ");
        if (scanf("%d", &matricula) != 1) {
            printf("Entrada inv�lida!\n");
            while(getchar() != '\n');
            return;
        }
        while(getchar() != '\n'); // Limpa o buffer
    
        printf("Digite sua senha: ");
        if (scanf("%49s", senhaInput) != 1) {
            printf("Entrada inv�lida!\n");
            while(getchar() != '\n');
            return;
        }
        while(getchar() != '\n'); // Limpa o buffer
    
        // Valida o funcion�rio utilizando os dados persistidos no CSV
        if (validarFuncionarioCSV(matricula, senhaInput, &temp) == 0) {
            // Aloca dinamicamente a mem�ria para salvar o usu�rio logado
            Funcionario *usuarioLogado = (Funcionario *)malloc(sizeof(Funcionario));
            if (usuarioLogado == NULL) {
                printf("Erro na aloca��o de mem�ria.\n");
                return;
            }
            // Copia os dados do funcion�rio validado para a nova mem�ria
            *usuarioLogado = temp;
            //printf("Login realizado com sucesso. Bem-vindo, %s!\n", usuarioLogado->nome);
            printf("Login realizado com sucesso. Bem-vindo, %d %s %s!\n", usuarioLogado->matricula, usuarioLogado->nome, usuarioLogado->senha);
            setUsuarioLogado(usuarioLogado); // Armazena o usu�rio logado na sess�o
        } else {
            printf("Matr�cula ou senha incorretas.\n");
        }
    }

