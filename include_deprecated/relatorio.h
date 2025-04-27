#ifndef RELATORIO_H
#define RELATORIO_H

// Relat�rio gen�rico em formato tabular
typedef struct {
    int    linhas;             // n�mero de linhas usadas
    int    colunas;            // n�mero de colunas
    char **cabecalhos;         // array de strings
    char ***celulas;           // matriz [linhas][colunas] de strings
} Relatorio;

#endif // RELATORIO_H
