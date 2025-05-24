
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "persistencia/verificacao_csv.h"
#include "persistencia/funcionario_dao.h"
#include "persistencia/industria_dao.h"
#include "persistencia/residuo_dao.h"
#include "ui/ui_comum.h"
#include "util.h"

void criar_arquivo_corrompido(const char *nome_arquivo, const char *conteudo)
{
    FILE *f = fopen(nome_arquivo, "w");
    if (f)
    {
        fputs(conteudo, f);
        fclose(f);
    }
}

int main()
{
    void set_locale_utf8();

    printf("Iniciando testes de verificação CSV...\n\n");

    // Teste 1: Arquivo não existe, deve criar com cabeçalho
    remove("test_industrias.csv");
    printf("Teste 1: Criar arquivo indústrias com cabeçalho...\n");
    if (verificar_csv_industria())
    {
        printf("SUCESSO: Arquivo criado com sucesso.\n");
    }
    else
    {
        printf("FALHA: Não foi possível criar o arquivo.\n");
    }

    // Teste 2: Arquivo sem cabeçalho, deve adicionar cabeçalho
    printf("\nTeste 2: Adicionar cabeçalho em arquivo sem cabeçalho...\n");
    criar_arquivo_corrompido("test_funcionarios.csv",
                             "123456,NOME TESTE,ABCDEF\n");
    if (verificar_csv_funcionario())
    {
        printf("SUCESSO: Cabeçalho adicionado com sucesso.\n");
    }
    else
    {
        printf("FALHA: Não foi possível adicionar cabeçalho.\n");
    }

    // Teste 3: Arquivo sem quebra de linha no final
    printf("\nTeste 3: Adicionar quebra de linha no final...\n");
    criar_arquivo_corrompido("test_residuos.csv",
                             "CNPJ,MES,ANO,QUANTIDADE,CUSTO\n"
                             "12345678901234,5,2023,100.50,200.75");
    if (verificar_csv_residuo())
    {
        printf("SUCESSO: Quebra de linha adicionada com sucesso.\n");
    }
    else
    {
        printf("FALHA: Não foi possível adicionar quebra de linha.\n");
    }

    printf("\nTestes concluídos.\n");

    return 0;
}
