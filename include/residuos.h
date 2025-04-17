#ifndef RESIDUOS_H
#define RESIDUOS_H

/**
 * @brief Representa a atualiza��o mensal de res�duos e custos de uma ind�stria.
 */
typedef struct {
    char cnpj[20];            // CNPJ da ind�stria
    int ano;                  // Ano da atualiza��o
    int mes;                  // M�s (1�12)
    double quantidadeTratada; // Quantidade de res�duos tratados
    double custoEstimado;     // Custo estimado em R$
} Residuos;

#endif // RESIDUOS_H
