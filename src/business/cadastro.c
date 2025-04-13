#include <stdio.h>
#include <string.h>
#include <stdlib.h>     // Para usar malloc e free
#include <ctype.h>     // Para usar toupper
#include "cadastro.h"
#include "funcionario.h"
#include "crypto.h"     // Para usar xorCipher

#define CRYPTO_KEY 0x5A

// Função que processa o cadastro. 
// Ela invoca a interface para coletar os dados e então aplica as operações da camada de negócio.
int processaCadastro(int matricula, const char *nome, const char *senha) {  

    Funcionario *novoFuncionario = (Funcionario *)malloc(sizeof(Funcionario));

    // Verifica se o ponteiro é nulo
    if (novoFuncionario == NULL) {
        return -1; // Erro ao processar o cadastro
    }    

    // Converte o nome para caixa alta
    char nomeMaiusculo[sizeof(novoFuncionario->nome)];
    for (size_t i = 0; i < sizeof(novoFuncionario->nome) - 1 && nome[i] != '\0'; i++) {
        nomeMaiusculo[i] = toupper((unsigned char)nome[i]);
    }
    nomeMaiusculo[sizeof(novoFuncionario->nome) - 1] = '\0'; // Garante que a string esteja terminada

    // Preenche os dados do novo funcionário
    novoFuncionario->matricula = matricula;
    strncpy(novoFuncionario->nome, nomeMaiusculo, sizeof(novoFuncionario->nome) - 1);
    novoFuncionario->nome[sizeof(novoFuncionario->nome) - 1] = '\0'; // Garante que a string esteja terminada
    strncpy(novoFuncionario->senha, senha, sizeof(novoFuncionario->senha) - 1);
    novoFuncionario->senha[sizeof(novoFuncionario->senha) - 1] = '\0'; // Garante que a string esteja terminada

    // Exibe os dados para confirmação, apenas para teste
    printf("\nUsuário cadastrado com sucesso (dados com senha criptografada):\n");
    printf("Matrícula: %d\n", novoFuncionario->matricula);
    printf("Nome: %s\n", novoFuncionario->nome);
    printf("Senha (não criptografada): %s\n", novoFuncionario->senha); // Exibe a senha não criptografada para teste
    // Criptografa a senha usando a função xorCipher
    xorCipher(novoFuncionario->senha, CRYPTO_KEY); // Criptografa a senha
    printf("Senha (criptografada): %s\n", novoFuncionario->senha);

    // Aqui será adicionada a lógica para persistir os dados.

    // Libera a memória alocada para o novo funcionário
    free(novoFuncionario);

    // Por enquanto, apenas retornamos 0 para indicar sucesso.
    return 0;
}
