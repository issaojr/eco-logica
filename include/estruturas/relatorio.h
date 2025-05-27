#ifndef RELATORIO_H
#define RELATORIO_H

/**
 * Representa um relatório de dados tabulares.
 */
typedef struct
{
    size_t colunas;    /* Número de colunas */
    size_t linhas;     /* Número de linhas */
    char ***dados;     /* Matriz de strings [linhas][colunas] */
    char **cabecalhos; /* Vetor de strings com os nomes das colunas */
} relatorio_t;

#endif /* RELATORIO_H */