#ifndef RESIDUOS_H
#define RESIDUOS_H

/**
 * @brief Representa a atualiza��o mensal de res�duos e custos de uma ind�stria.
 */
typedef struct {
    char cnpj[20];            // CNPJ da ind�stria
    char data_ref[8];        ///< Data de refer�ncia "MM/YYYY"
    double quantidadeTratada; // Quantidade de res�duos tratados
    double custoEstimado;     // Custo estimado em R$
} Residuos;

#endif // RESIDUOS_H
