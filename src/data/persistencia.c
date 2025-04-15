#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "persistencia.h"
#include "crypto.h"

// Definindo a chave de criptografia usada em outros m�dulos
#define CRYPTO_KEY 0x5A

int validarFuncionarioCSV(int matricula, const char *senha, Funcionario *funcEncontrado) {
    if (senha == NULL || funcEncontrado == NULL) {
        return -1;
    }

    FILE *arquivo = fopen("funcionarios.csv", "r");
    if (arquivo == NULL) {
        return -1; // Erro ao abrir o arquivo
    }

    int retorno = -1;
    char linha[256];
    int m;
    char nome[150];
    char senhaArmazenada[50];

    // Ler o arquivo linha a linha
    while (fgets(linha, sizeof(linha), arquivo)) {
        // Espera-se que a linha esteja no formato: matricula,"nome","senha"
        if (sscanf(linha, "%d,\"%149[^\"]\",\"%49[^\"]\"", &m, nome, senhaArmazenada) == 3) {
            if (m == matricula) {
                // Criptografa a senha digitada para compar�-la com a senha armazenada
                char senhaCifrada[50];
                strncpy(senhaCifrada, senha, sizeof(senhaCifrada) - 1);
                senhaCifrada[sizeof(senhaCifrada) - 1] = '\0';
                xorCipher(senhaCifrada, CRYPTO_KEY);
                
                if (strcmp(senhaCifrada, senhaArmazenada) == 0) {
                    // Registro v�lido; preenche os dados encontrados
                    funcEncontrado->matricula = m;
                    strncpy(funcEncontrado->nome, nome, sizeof(funcEncontrado->nome) - 1);
                    funcEncontrado->nome[sizeof(funcEncontrado->nome) - 1] = '\0';
                    strncpy(funcEncontrado->senha, senhaArmazenada, sizeof(funcEncontrado->senha) - 1);
                    funcEncontrado->senha[sizeof(funcEncontrado->senha) - 1] = '\0';
                    retorno = 0;
                    break;
                }
            }
        }
    }

    fclose(arquivo);
    return retorno;
}

int salvarFuncionarioCSV(const Funcionario *func, const char *nomeArquivo) {
    if (func == NULL || nomeArquivo == NULL) {
        return -1;
    }

    // Abre o arquivo no modo "append" para n�o sobrescrever dados anteriores.
    FILE *arquivo = fopen(nomeArquivo, "a");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo para escrita");
        return -1;
    }

    // Grava os dados do funcion�rio no formato CSV.
    // Os campos de texto s�o envolvidos por aspas para evitar conflito com o delimitador (v�rgula).
    // Exemplo de registro: 12345,"JO�O SILVA","SENHACRIPTOGRAFADA"
    int resultado = fprintf(arquivo, "%d,\"%s\",\"%s\"\n", func->matricula, func->nome, func->senha);
    fclose(arquivo);

    return (resultado > 0) ? 0 : -1;
}
