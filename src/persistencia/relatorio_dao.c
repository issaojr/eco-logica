#include "persistencia/relatorio_dao.h"

bool inserir_rel_arquivo(
    relatorio_t *rel, 
    const char *nome_base,
    const char *ext,
    const char *separador)
{
    char nome_local[256]; /* Mantém o nome local */
    snprintf(nome_local, sizeof(nome_local), "relatorios/%s.%s", nome_base, ext);

    if (arquivo_existe(nome_local))
    {
        gerar_nome_unico(nome_base, nome_local, sizeof(nome_local), ext);
    }

    FILE *fp = fopen(nome_local, "w");
    if (!fp)
        return false;

    /* Escreve cabeçalho */
    for (size_t i = 0; i < rel->colunas; i++)
    {
        fprintf(fp, "%s", rel->cabecalhos[i]);
        if (i < rel->colunas - 1)
            fprintf(fp, "%s", separador);
    }
    fprintf(fp, "\n");

    /* Escreve dados */
    for (size_t i = 0; i < rel->linhas; i++)
    {
        for (size_t j = 0; j < rel->colunas; j++)
        {
            fprintf(fp, "%s", rel->dados[i][j]);
            if (j < rel->colunas - 1)
                fprintf(fp, "%s", separador);
        }
        fprintf(fp, "\n");
    }

    fclose(fp);
    return true;
}

/**
 * Verifica se um arquivo existe.
 * @param nome_arquivo - Nome do arquivo a ser verificado.
 * @return true se o arquivo existir, false caso contrário.
 */
bool arquivo_existe(const char *nome_arquivo)
{
    FILE *fp = fopen(nome_arquivo, "r");
    if (fp)
    {
        fclose(fp);
        return true;
    }
    return false;
}

/**
 * Gera um nome único para o arquivo de relatório, evitando sobrescritas.
 * @param nome_base - Nome base do arquivo.
 * @param saida - Buffer onde o nome único será armazenado.
 * @param tamanho - Tamanho do buffer de saída.
 * @param extensao - Extensão do arquivo (ex: "csv", "txt").
 */
void gerar_nome_unico(const char *nome_base, char *saida, size_t tamanho, const char *extensao)
{
    int contador = 1;
    snprintf(saida, tamanho, "%s.%s", nome_base, extensao);

    while (arquivo_existe(saida))
    {
        snprintf(saida, tamanho, "%s_%d.%s", nome_base, contador, extensao);
        contador++;
    }
}