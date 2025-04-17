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

    // Preenche os dados do novo funcionário
    novoFuncionario->matricula = matricula;
    safeStrCopy(novoFuncionario->nome, nome, sizeof(novoFuncionario->nome));
    safeStrCopy(novoFuncionario->senha, senha, sizeof(novoFuncionario->senha));
    
    // Exibe os dados para confirmação, apenas para teste
    printf("\nUsuário cadastrado com sucesso (dados com senha criptografada):\n");
    printf("Matrícula: %d\n", novoFuncionario->matricula);
    printf("Nome: %s\n", novoFuncionario->nome);
    printf("Senha (não criptografada): %s\n", novoFuncionario->senha); // Exibe a senha não criptografada para teste
    // Criptografa a senha usando a função xorCipher
    xorCipher(novoFuncionario->senha, CRYPTO_KEY); // Criptografa a senha
    printf("Senha (criptografada): %s\n", novoFuncionario->senha);

    // Salva os dados no arquivo CSV
    int ret = salvarFuncionarioCSV(novoFuncionario, "funcionarios.csv");
    if (ret == 0) {
        printf("Dados salvos com sucesso em 'funcionarios.csv'.\n");
    } else {
        printf("Erro ao salvar os dados.\n");
    }

    // Libera a memória alocada para o novo funcionário
    free(novoFuncionario);

    // Por enquanto, apenas retornamos 0 para indicar sucesso.
    return 0;
}
