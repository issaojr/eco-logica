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
int processa_cadastro_funcionario(int matricula, const char *nome, const char *senha) {  

    Funcionario *novo_funcionario = (Funcionario *)malloc(sizeof(Funcionario));

    // Verifica se o ponteiro e nulo
    if (novo_funcionario == NULL) {
        return -1; // Erro ao processar o cadastro
    }    

    // Preenche os dados do novo funcionário
    novo_funcionario->matricula = matricula;
    safeStrCopy(novo_funcionario->nome, nome, sizeof(novo_funcionario->nome));
    safeStrCopy(novo_funcionario->senha, senha, sizeof(novo_funcionario->senha));

    // Salva os dados no arquivo CSV
    int ret = salvar_funcionario_csv(novo_funcionario, "funcionarios.csv");

    // Libera a memória alocada para o novo funcionário
    free(novo_funcionario);

    return ret;
}
