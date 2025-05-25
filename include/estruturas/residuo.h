#ifndef RESIDUO_H
#define RESIDUO_H

/**
 * Representa um registro mensal de resíduos para uma indústria.
 */
typedef struct
{
    char cnpj[16]; /* 14 + '\n' + '\0' */
    int mes;
    int ano;
    double quantidade;
    double custo;
} residuo_t;

#endif /* RESIDUO_H */
