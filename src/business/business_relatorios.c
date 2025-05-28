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
 * @param relatorio - estrutura de dados para armazenar o relatório.
 * @return true se o relatório foi gerado com sucesso, false caso contrário.
 */
bool gerar_relatorio_industrias_melhor_desempenho(relatorio_t *relatorio)
{
    ui_exibir_to_do("[TODO] Implementar geração de relatório de indústrias com melhor desempenho ambiental");
    return false; /* Placeholder, deve ser implementado */
}

/**
 * Gera relatório de aporte financeiro semestral.
 * @param relatorio - estrutura de dados para armazenar o relatório.
 * @return true se o relatório foi gerado com sucesso, false caso contrário.
 */
bool gerar_relatorio_aporte_financeiro_semestral(relatorio_t *relatorio)
{
    ui_exibir_to_do("[TODO] Implementar geração de relatório de aporte financeiro semestral");
    return false; /* Placeholder, deve ser implementado */
}

/*---------------------------RELATÓRIOS POR INDÚSTRIA-----------------------------*/

/* Estrutura para agrupar dados semestrais */
typedef struct
{
    int ano;
    int semestre; // 1 ou 2
    double quantidade_total;
} semestre_resumo_t;

/**
 * Gera relatório de resíduos semestrais para uma indústria específica.
 * @param i - Ponteiro para a estrutura da indústria.
 * @param relatorio - estrutura de dados para armazenar o relatório.
 * @return true se o relatório foi gerado com sucesso, false caso contrário.
 */
bool gerar_relatorio_residuos_semestral(industria_t *i, relatorio_t *relatorio)
{
    if (!i || !relatorio)
        return false;

    residuo_t *registros = NULL;
    size_t total_registros = 0;

    if (!buscar_residuos_por_cnpj(i->cnpj, &registros, &total_registros))
        return false;

    if (total_registros == 0)
    {
        liberar_registros_residuos(registros);
        return false;
    }

    typedef struct {
        int ano;
        int semestre;
        double quantidade_total;
    } semestre_resumo_t;

    semestre_resumo_t *semestres = NULL;
    size_t capacidade = 0, contador_semestres = 0;

    for (size_t idx = 0; idx < total_registros; idx++)
    {
        residuo_t *reg = &registros[idx];
        int semestre = (reg->mes <= 6) ? 1 : 2;

        bool encontrado = false;
        for (size_t j = 0; j < contador_semestres; j++)
        {
            if (semestres[j].ano == reg->ano && semestres[j].semestre == semestre)
            {
                semestres[j].quantidade_total += reg->quantidade;
                encontrado = true;
                break;
            }
        }

        if (!encontrado)
        {
            if (contador_semestres >= capacidade)
            {
                capacidade = capacidade ? capacidade * 2 : 8;
                void *novo_ptr = realloc(semestres, capacidade * sizeof(semestre_resumo_t));
                if (!novo_ptr)
                {
                    free(semestres);
                    liberar_registros_residuos(registros);
                    return false;
                }
                semestres = novo_ptr;
            }

            semestres[contador_semestres].ano = reg->ano;
            semestres[contador_semestres].semestre = semestre;
            semestres[contador_semestres].quantidade_total = reg->quantidade;
            contador_semestres++;
        }
    }

    liberar_registros_residuos(registros);

    if (contador_semestres == 0)
    {
        free(semestres);
        return false;
    }

    qsort(semestres, contador_semestres, sizeof(semestre_resumo_t), comparar_semestres);


    relatorio->colunas = 3;  // ✅ Agora só 3 colunas
    relatorio->linhas = contador_semestres;

    relatorio->cabecalhos = (char **)malloc(relatorio->colunas * sizeof(char *));
    if (!relatorio->cabecalhos)
    {
        free(semestres);
        return false;
    }

    relatorio->cabecalhos[0] = _util_strdup("Ano");
    relatorio->cabecalhos[1] = _util_strdup("Período");
    relatorio->cabecalhos[2] = _util_strdup("Quantidade (kg)");

    for (size_t k = 0; k < relatorio->colunas; k++)
    {
        if (!relatorio->cabecalhos[k])
        {
            for (size_t j = 0; j < k; j++) free(relatorio->cabecalhos[j]);
            free(relatorio->cabecalhos);
            free(semestres);
            return false;
        }
    }

    relatorio->dados = (char ***)malloc(relatorio->linhas * sizeof(char **));
    if (!relatorio->dados)
    {
        for (size_t k = 0; k < relatorio->colunas; k++) free(relatorio->cabecalhos[k]);
        free(relatorio->cabecalhos);
        free(semestres);
        return false;
    }

    for (size_t idx = 0; idx < relatorio->linhas; idx++)
    {
        relatorio->dados[idx] = (char **)malloc(relatorio->colunas * sizeof(char *));
        if (!relatorio->dados[idx])
        {
            for (size_t j = 0; j < idx; j++)
            {
                for (size_t k = 0; k < relatorio->colunas; k++) free(relatorio->dados[j][k]);
                free(relatorio->dados[j]);
            }
            free(relatorio->dados);
            for (size_t k = 0; k < relatorio->colunas; k++) free(relatorio->cabecalhos[k]);
            free(relatorio->cabecalhos);
            free(semestres);
            return false;
        }

        char buffer[50];

        snprintf(buffer, sizeof(buffer), "%d", semestres[idx].ano);
        relatorio->dados[idx][0] = _util_strdup(buffer);

        snprintf(buffer, sizeof(buffer), "%dº Semestre", semestres[idx].semestre);
        relatorio->dados[idx][1] = _util_strdup(buffer);

        snprintf(buffer, sizeof(buffer), "%.2f", semestres[idx].quantidade_total);
        relatorio->dados[idx][2] = _util_strdup(buffer);

        for (size_t k = 0; k < relatorio->colunas; k++)
        {
            if (!relatorio->dados[idx][k])
            {
                for (size_t l = 0; l < k; l++) free(relatorio->dados[idx][l]);
                free(relatorio->dados[idx]);
                for (size_t j = 0; j < idx; j++)
                {
                    for (size_t l = 0; l < relatorio->colunas; l++) free(relatorio->dados[j][l]);
                    free(relatorio->dados[j]);
                }
                free(relatorio->dados);
                for (size_t k = 0; k < relatorio->colunas; k++) free(relatorio->cabecalhos[k]);
                free(relatorio->cabecalhos);
                free(semestres);
                return false;
            }
        }
    }

    free(semestres);
    return true;
}

// bool gerar_relatorio_residuos_semestral(industria_t *i, relatorio_t *relatorio)
// {
//     if (!i || !relatorio)
//     {
//         return false;
//     }

//     // Buscar todos os registros de resíduos da indústria usando DAO
//     residuo_t *registros = NULL;
//     size_t total_registros = 0;

//     if (!buscar_residuos_por_cnpj(i->cnpj, &registros, &total_registros))
//     {
//         return false;
//     }

//     // Se não há registros, criar relatório vazio
//     if (total_registros == 0)
//     {
//         liberar_registros_residuos(registros);
//         return false;
//     }

//     // Array para armazenar dados semestrais agrupados
//     semestre_resumo_t *semestres = NULL;
//     size_t capacidade = 0, contador_semestres = 0;

//     // Processar todos os registros e agrupar por semestre
//     for (size_t i = 0; i < total_registros; i++)
//     {
//         residuo_t *reg = &registros[i];

//         // Determinar semestre (1º: jan-jun, 2º: jul-dez)
//         int semestre = (reg->mes <= 6) ? 1 : 2;

//         // Procurar se já existe um registro para este ano/semestre
//         bool encontrado = false;
//         for (size_t j = 0; j < contador_semestres; j++)
//         {
//             if (semestres[j].ano == reg->ano && semestres[j].semestre == semestre)
//             {
//                 semestres[j].quantidade_total += reg->quantidade;
//                 semestres[j].custo_total += reg->custo;
//                 encontrado = true;
//                 break;
//             }
//         }

//         // Se não encontrou, criar novo registro semestral
//         if (!encontrado)
//         {
//             if (contador_semestres >= capacidade)
//             {
//                 capacidade = capacidade ? capacidade * 2 : 8;
//                 void *novo_ptr = realloc(semestres, capacidade * sizeof(semestre_resumo_t));
//                 if (!novo_ptr)
//                 {
//                     free(semestres);
//                     liberar_registros_residuos(registros);
//                     return false;
//                 }
//                 semestres = novo_ptr;
//             }

//             semestres[contador_semestres].ano = reg->ano;
//             semestres[contador_semestres].semestre = semestre;
//             semestres[contador_semestres].quantidade_total = reg->quantidade;
//             semestres[contador_semestres].custo_total = reg->custo;
//             contador_semestres++;
//         }
//     }

//     // Liberar registros originais (não precisamos mais)
//     liberar_registros_residuos(registros);

//     // Se não há dados agrupados, retornar erro
//     if (contador_semestres == 0)
//     {
//         free(semestres);
//         return false;
//     }

//     // Configurar estrutura do relatório
//     relatorio->colunas = 4;
//     relatorio->linhas = contador_semestres;

//     // Alocar cabeçalhos
//     relatorio->cabecalhos = (char **)malloc(relatorio->colunas * sizeof(char *));
//     if (!relatorio->cabecalhos)
//     {
//         free(semestres);
//         return false;
//     }

//     // Definir cabeçalhos
//     relatorio->cabecalhos[0] = _util_strdup("Ano");
//     relatorio->cabecalhos[1] = _util_strdup("Período");
//     relatorio->cabecalhos[2] = _util_strdup("Quantidade (kg)");
//     relatorio->cabecalhos[3] = _util_strdup("Custo (R$)"); // Verificar se a alocação dos cabeçalhos foi bem-sucedida
//     for (size_t i = 0; i < relatorio->colunas; i++)
//     {
//         if (!relatorio->cabecalhos[i])
//         {
//             // Liberar cabeçalhos já alocados
//             for (size_t j = 0; j < i; j++)
//             {
//                 free(relatorio->cabecalhos[j]);
//             }
//             free(relatorio->cabecalhos);
//             free(semestres);
//             return false;
//         }
//     }

//     // Alocar matriz de dados
//     relatorio->dados = (char ***)malloc(relatorio->linhas * sizeof(char **));
//     if (!relatorio->dados)
//     {
//         for (size_t i = 0; i < relatorio->colunas; i++)
//         {
//             free(relatorio->cabecalhos[i]);
//         }
//         free(relatorio->cabecalhos);
//         free(semestres);
//         return false;
//     }

//     // Alocar e preencher cada linha
//     for (size_t i = 0; i < relatorio->linhas; i++)
//     {
//         relatorio->dados[i] = (char **)malloc(relatorio->colunas * sizeof(char *));
//         if (!relatorio->dados[i])
//         { // Liberar linhas já alocadas
//             for (size_t j = 0; j < i; j++)
//             {
//                 for (size_t k = 0; k < relatorio->colunas; k++)
//                 {
//                     free(relatorio->dados[j][k]);
//                 }
//                 free(relatorio->dados[j]);
//             }
//             free(relatorio->dados);
//             for (size_t j = 0; j < relatorio->colunas; j++)
//             {
//                 free(relatorio->cabecalhos[j]);
//             }
//             free(relatorio->cabecalhos);
//             free(semestres);
//             return false;
//         }

//         // Alocar e preencher cada célula
//         char buffer[50];

//         // Ano
//         snprintf(buffer, sizeof(buffer), "%d", semestres[i].ano);
//         relatorio->dados[i][0] = _util_strdup(buffer);

//         // Período
//         snprintf(buffer, sizeof(buffer), "%dº Semestre", semestres[i].semestre);
//         relatorio->dados[i][1] = _util_strdup(buffer);

//         // Quantidade
//         snprintf(buffer, sizeof(buffer), "%.2f", semestres[i].quantidade_total);
//         relatorio->dados[i][2] = _util_strdup(buffer);

//         // Custo
//         snprintf(buffer, sizeof(buffer), "%.2f", semestres[i].custo_total);
//         relatorio->dados[i][3] = _util_strdup(buffer); // Verificar se todas as alocações foram bem-sucedidas
//         for (size_t j = 0; j < relatorio->colunas; j++)
//         {
//             if (!relatorio->dados[i][j])
//             {
//                 // Liberar células já alocadas nesta linha
//                 for (size_t k = 0; k < j; k++)
//                 {
//                     free(relatorio->dados[i][k]);
//                 }
//                 free(relatorio->dados[i]);

//                 // Liberar linhas já alocadas anteriormente
//                 for (size_t k = 0; k < i; k++)
//                 {
//                     for (size_t l = 0; l < relatorio->colunas; l++)
//                     {
//                         free(relatorio->dados[k][l]);
//                     }
//                     free(relatorio->dados[k]);
//                 }
//                 free(relatorio->dados);

//                 // Liberar cabeçalhos
//                 for (size_t k = 0; k < relatorio->colunas; k++)
//                 {
//                     free(relatorio->cabecalhos[k]);
//                 }
//                 free(relatorio->cabecalhos);
//                 free(semestres);
//                 return false;
//             }
//         }
//     } // Liberar dados temporários
//     free(semestres);

//     return true;
// }

typedef struct {
    int ano;
    int mes;
    double custo_total;
} mes_resumo_t;

/**
 * Gera relatório de gastos mensais para uma indústria específica.
 * @param i - Ponteiro para a estrutura da indústria.
 * @param relatorio - estrutura de dados para armazenar o relatório.
 * @return true se o relatório foi gerado com sucesso, false caso contrário.
 */
bool gerar_relatorio_gastos_mensais(industria_t *i, relatorio_t *relatorio)
{
    if (!i || !relatorio)
        return false;

    residuo_t *registros = NULL;
    size_t total_registros = 0;

    if (!buscar_residuos_por_cnpj(i->cnpj, &registros, &total_registros))
        return false;

    if (total_registros == 0)
    {
        liberar_registros_residuos(registros);
        return false;
    }

    typedef struct {
        int ano;
        int mes;
        double custo_total;
    } mes_resumo_t;

    mes_resumo_t *meses = NULL;
    size_t capacidade = 0, contador_meses = 0;

    for (size_t idx = 0; idx < total_registros; idx++)
    {
        residuo_t *reg = &registros[idx];

        bool encontrado = false;
        for (size_t j = 0; j < contador_meses; j++)
        {
            if (meses[j].ano == reg->ano && meses[j].mes == reg->mes)
            {
                meses[j].custo_total += reg->custo;
                encontrado = true;
                break;
            }
        }

        if (!encontrado)
        {
            if (contador_meses >= capacidade)
            {
                capacidade = capacidade ? capacidade * 2 : 8;
                void *novo_ptr = realloc(meses, capacidade * sizeof(mes_resumo_t));
                if (!novo_ptr)
                {
                    free(meses);
                    liberar_registros_residuos(registros);
                    return false;
                }
                meses = novo_ptr;
            }

            meses[contador_meses].ano = reg->ano;
            meses[contador_meses].mes = reg->mes;
            meses[contador_meses].custo_total = reg->custo;
            contador_meses++;
        }
    }

    liberar_registros_residuos(registros);

    if (contador_meses == 0)
    {
        free(meses);
        return false;
    }

    // Ordenar meses por ano e mês
    qsort(meses, contador_meses, sizeof(mes_resumo_t), comparar_meses);

    relatorio->colunas = 3;
    relatorio->linhas = contador_meses;

    relatorio->cabecalhos = (char **)malloc(relatorio->colunas * sizeof(char *));
    if (!relatorio->cabecalhos)
    {
        free(meses);
        return false;
    }

    relatorio->cabecalhos[0] = _util_strdup("Ano");
    relatorio->cabecalhos[1] = _util_strdup("Mês");
    relatorio->cabecalhos[2] = _util_strdup("Custo (R$)");

    for (size_t k = 0; k < relatorio->colunas; k++)
    {
        if (!relatorio->cabecalhos[k])
        {
            for (size_t j = 0; j < k; j++) free(relatorio->cabecalhos[j]);
            free(relatorio->cabecalhos);
            free(meses);
            return false;
        }
    }

    relatorio->dados = (char ***)malloc(relatorio->linhas * sizeof(char **));
    if (!relatorio->dados)
    {
        for (size_t k = 0; k < relatorio->colunas; k++) free(relatorio->cabecalhos[k]);
        free(relatorio->cabecalhos);
        free(meses);
        return false;
    }

    for (size_t idx = 0; idx < relatorio->linhas; idx++)
    {
        relatorio->dados[idx] = (char **)malloc(relatorio->colunas * sizeof(char *));
        if (!relatorio->dados[idx])
        {
            for (size_t j = 0; j < idx; j++)
            {
                for (size_t k = 0; k < relatorio->colunas; k++) free(relatorio->dados[j][k]);
                free(relatorio->dados[j]);
            }
            free(relatorio->dados);
            for (size_t k = 0; k < relatorio->colunas; k++) free(relatorio->cabecalhos[k]);
            free(relatorio->cabecalhos);
            free(meses);
            return false;
        }

        char buffer[50];

        snprintf(buffer, sizeof(buffer), "%d", meses[idx].ano);
        relatorio->dados[idx][0] = _util_strdup(buffer);

        snprintf(buffer, sizeof(buffer), "%02d", meses[idx].mes);
        relatorio->dados[idx][1] = _util_strdup(buffer);

        snprintf(buffer, sizeof(buffer), "%.2f", meses[idx].custo_total);
        relatorio->dados[idx][2] = _util_strdup(buffer);

        for (size_t k = 0; k < relatorio->colunas; k++)
        {
            if (!relatorio->dados[idx][k])
            {
                for (size_t l = 0; l < k; l++) free(relatorio->dados[idx][l]);
                free(relatorio->dados[idx]);
                for (size_t j = 0; j < idx; j++)
                {
                    for (size_t l = 0; l < relatorio->colunas; l++) free(relatorio->dados[j][l]);
                    free(relatorio->dados[j]);
                }
                free(relatorio->dados);
                for (size_t k = 0; k < relatorio->colunas; k++) free(relatorio->cabecalhos[k]);
                free(relatorio->cabecalhos);
                free(meses);
                return false;
            }
        }
    }

    free(meses);
    return true;
}

/*----------------------------EXPORTAÇÃO DE RELATÓRIOS-----------------------------*/

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
    bool sucesso = inserir_rel_arquivo(rel, nome_base, extensao, separador);
    return sucesso;
}

/**
 * Libera a memória alocada para o relatório.
 * @param rel - Ponteiro para a estrutura do relatório.
 */
void relatorio_liberar(relatorio_t *rel)
{
    if (!rel)
        return;

    // Liberar cabeçalhos
    for (size_t i = 0; i < rel->colunas; i++)
    {
        free(rel->cabecalhos[i]);
    }
    free(rel->cabecalhos);

    // Liberar dados
    for (size_t i = 0; i < rel->linhas; i++)
    {
        for (size_t j = 0; j < rel->colunas; j++)
        {
            free(rel->dados[i][j]);
        }
        free(rel->dados[i]);
    }
    free(rel->dados);
}

/*-------------------- Auxiliares --------------------*/

int comparar_semestres(const void *a, const void *b)
{
    const semestre_resumo_t *sa = (const semestre_resumo_t *)a;
    const semestre_resumo_t *sb = (const semestre_resumo_t *)b;

    if (sa->ano != sb->ano)
        return sa->ano - sb->ano;
    
    return sa->semestre - sb->semestre;
}

int comparar_meses(const void *a, const void *b)
{
    const mes_resumo_t *ma = (const mes_resumo_t *)a;
    const mes_resumo_t *mb = (const mes_resumo_t *)b;

    if (ma->ano != mb->ano)
        return ma->ano - mb->ano;
    
    return ma->mes - mb->mes;
}
