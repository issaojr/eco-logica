#ifndef RELATORIO_H
#define RELATORIO_H

// Relatório genérico em formato tabular
typedef struct {
    int    linhas;             // número de linhas usadas
    int    colunas;            // número de colunas
    char **cabecalhos;         // array de strings
    char ***celulas;           // matriz [linhas][colunas] de strings
} Relatorio;

#endif // RELATORIO_H
