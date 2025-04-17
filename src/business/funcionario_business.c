#include <stdio.h>
#include <string.h>
#include <stdlib.h>     // Para usar malloc e free
#include <ctype.h>     // Para usar toupper
#include "funcionario_business.h"
#include "funcionario.h"
#include "crypto.h"     // Para usar xorCipher
#include "persistencia.h"
#include "utils.h"     // Para usar safeStrCopy

#define CRYPTO_KEY 0x5A

// Funcao que processa o cadastro. 
// Ela invoca a interface para coletar os dados e entao aplica as operacoes da camada de negocio.
int processaCadastroFuncionario(int matricula, const char *nome, const char *senha) {  

    Funcionario *novoFuncionario = (Funcionario *)malloc(sizeof(Funcionario));

    // Verifica se o ponteiro e nulo
    if (novoFuncionario == NULL) {
        return -1; // Erro ao processar o cadastro
    }    

    // Preenche os dados do novo funcion�rio
    novoFuncionario->matricula = matricula;
    safeStrCopy(novoFuncionario->nome, nome, sizeof(novoFuncionario->nome));
    safeStrCopy(novoFuncionario->senha, senha, sizeof(novoFuncionario->senha));
    
    // Exibe os dados para confirma��o, apenas para teste
    printf("\nUsu�rio cadastrado com sucesso (dados com senha criptografada):\n");
    printf("Matr�cula: %d\n", novoFuncionario->matricula);
    printf("Nome: %s\n", novoFuncionario->nome);
    printf("Senha (n�o criptografada): %s\n", novoFuncionario->senha); // Exibe a senha n�o criptografada para teste
    // Criptografa a senha usando a fun��o xorCipher
    xorCipher(novoFuncionario->senha, CRYPTO_KEY); // Criptografa a senha
    printf("Senha (criptografada): %s\n", novoFuncionario->senha);

    // Salva os dados no arquivo CSV
    int ret = salvarFuncionarioCSV(novoFuncionario, "funcionarios.csv");
    if (ret == 0) {
        printf("Dados salvos com sucesso em 'funcionarios.csv'.\n");
    } else {
        printf("Erro ao salvar os dados.\n");
    }

    // Libera a mem�ria alocada para o novo funcion�rio
    free(novoFuncionario);

    // Por enquanto, apenas retornamos 0 para indicar sucesso.
    return 0;
}
