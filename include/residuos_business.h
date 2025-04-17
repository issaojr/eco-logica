#ifndef RESIDUOS_BUSINESS_H
#define RESIDUOS_BUSINESS_H

#include "residuos.h"

/**
 * @brief Processa e valida uma atualização mensal, chamando a persistência.
 * @return 0 em sucesso; -1 em erro de validação ou gravação.
 */
int processarAtualizacaoMensal(const Residuos *r);

#endif // RESIDUOS_BUSINESS_H
