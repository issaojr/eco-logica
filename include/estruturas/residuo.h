#ifndef RESIDUO_H
#define RESIDUO_H

/**
 * Representa um registro mensal de res�duos para uma ind�stria.
 */
typedef struct {
    char cnpj[18];  // formato 00.000.000/0000-00
    int mes;
    int ano;
    double quantidade;
    double custo;
} residuo_t;

#endif /* RESIDUO_H */