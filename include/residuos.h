#ifndef RESIDUOS_H
#define RESIDUOS_H

/**
 * @brief Representa a atualização mensal de resíduos e custos de uma indústria.
 */
typedef struct {
    char cnpj[20];            // CNPJ da indústria
    int ano;                  // Ano da atualização
    int mes;                  // Mês (1–12)
    double quantidadeTratada; // Quantidade de resíduos tratados
    double custoEstimado;     // Custo estimado em R$
} Residuos;

#endif // RESIDUOS_H
