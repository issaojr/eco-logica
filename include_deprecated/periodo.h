#ifndef PERIODO_H
#define PERIODO_H

// Tipos de intervalo de relatório (conforme PIM IV: mensal, semestral, anual) 
#define PERIODO_MENSAL     1
#define PERIODO_SEMESTRAL  2
#define PERIODO_ANUAL      3

// Um “pedaço” de período (mês, semestre ou ano)
typedef struct {
    int ano;        // ex.: 2025
    int mes;        // 1–12 se MENSAL, 0 caso SEMESTRAL/ANUAL
    int semestre;   // 1–2 se SEMESTRAL, 0 caso MENSAL/ANUAL
} Periodo;

// Lista dinâmica de períodos
typedef struct {
    Periodo *itens; // vetor de períodos
    int      qtd;   // elementos em itens[]
} PeriodoLista;

#endif // PERIODO_H