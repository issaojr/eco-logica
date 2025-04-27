#ifndef PERIODO_H
#define PERIODO_H

// Tipos de intervalo de relat�rio (conforme PIM IV: mensal, semestral, anual) 
#define PERIODO_MENSAL     1
#define PERIODO_SEMESTRAL  2
#define PERIODO_ANUAL      3

// Um �peda�o� de per�odo (m�s, semestre ou ano)
typedef struct {
    int ano;        // ex.: 2025
    int mes;        // 1�12 se MENSAL, 0 caso SEMESTRAL/ANUAL
    int semestre;   // 1�2 se SEMESTRAL, 0 caso MENSAL/ANUAL
} Periodo;

// Lista din�mica de per�odos
typedef struct {
    Periodo *itens; // vetor de per�odos
    int      qtd;   // elementos em itens[]
} PeriodoLista;

#endif // PERIODO_H