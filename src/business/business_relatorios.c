#include "business/business_relatorios.h"

/*--------------------------RELATÓRIOS GLOBAIS-----------------------------*/
/**
 * Gera relatório de resíduos por região.
 * @param estrutura de dados para armazenar o relatório.
 * @return true se o relatório foi gerado com sucesso, false caso contrário.
 */
bool gerar_relatorio_residuos_por_regiao(relatorio_t *relatorio)
{
    ui_exibir_to_do("[TODO] Implementar geração de relatório de resíduos por região");
    return false; /* Placeholder, deve ser implementado */
}

/**
 * Gera relatório de indústrias com melhor desempenho ambiental.
 * @param estrutura de dados para armazenar o relatório.
 * @return true se o relatório foi gerado com sucesso, false caso contrário.
 */
bool gerar_relatorio_industrias_melhor_desempenho(relatorio_t *relatorio)
{
    ui_exibir_to_do("[TODO] Implementar geração de relatório de indústrias com melhor desempenho ambiental");
    return false; /* Placeholder, deve ser implementado */
}

/**
 * Gera relatório de aporte financeiro semestral.
 * @param estrutura de dados para armazenar o relatório.
 * @return true se o relatório foi gerado com sucesso, false caso contrário.
 */
bool gerar_relatorio_aporte_financeiro_semestral(relatorio_t *relatorio)
{
    ui_exibir_to_do("[TODO] Implementar geração de relatório de aporte financeiro semestral");
    return false; /* Placeholder, deve ser implementado */
}

/*---------------------------RELATÓRIOS POR INDÚSTRIA-----------------------------*/

/**
 * Gera relatório de resíduos semestrais para uma indústria específica.
 * @param industria_t *i - Ponteiro para a estrutura da indústria.
 * @param estrutura de dados para armazenar o relatório.
 * @return true se o relatório foi gerado com sucesso, false caso contrário.
 */
bool gerar_relatorio_residuos_semestral(industria_t *i, relatorio_t *relatorio)
{
    ui_exibir_to_do("[TODO] Implementar geração de relatório de resíduos semestrais para a indústria");
    return false; /* Placeholder, deve ser implementado */
}

/**
 * Gera relatório de gastos mensais para uma indústria específica.
 * @param industria_t *i - Ponteiro para a estrutura da indústria.
 * @param estrutura de dados para armazenar o relatório.
 * @return true se o relatório foi gerado com sucesso, false caso contrário.
 */
bool gerar_relatorio_gastos_mensais(industria_t *i, relatorio_t *relatorio)
{
    ui_exibir_to_do("[TODO] Implementar geração de relatório de gastos mensais para a indústria");
    return false; /* Placeholder, deve ser implementado */
}

/*----------------------------EXPORTAÇÃO DE RELATÓRIOS-----------------------------*/

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

/**
 * Exporta o relatório para um arquivo com o nome base e extensão especificados.
 * @param rel - Ponteiro para a estrutura do relatório.
 * @param nome_base - Nome base do arquivo (sem extensão).
 * @param extensao - Extensão do arquivo (ex: "csv", "txt").
 * @param separador - Separador a ser usado entre os campos (ex: ",", ";").
 * @return true se a exportação foi bem-sucedida, false caso contrário.
 */
bool relatorio_exportar(relatorio_t *rel, const char *nome_base, const char *extensao, const char *separador)
{
    char nome_local[256]; /* Mantém o nome local */
    snprintf(nome_local, sizeof(nome_local), "%s.%s", nome_base, extensao);

    if (arquivo_existe(nome_local))
    {
        gerar_nome_unico(nome_base, nome_local, sizeof(nome_local), extensao);
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
    printf("Relatório exportado para: %s (%zu linhas)\n", nome_local, rel->linhas);
    return true;
}
