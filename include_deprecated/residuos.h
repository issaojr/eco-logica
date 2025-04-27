#ifndef RESIDUOS_H
#define RESIDUOS_H

/**
 * @brief Representa a atualização mensal de resíduos e custos de uma indústria.
 */
typedef struct {
    char cnpj[20];            // CNPJ da indústria
    char data_ref[8];        ///< Data de referência "MM/YYYY"
    double quantidadeTratada; // Quantidade de resíduos tratados
    double custoEstimado;     // Custo estimado em R$
} Residuos;

#endif // RESIDUOS_H
