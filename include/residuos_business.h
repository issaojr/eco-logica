#ifndef RESIDUOS_BUSINESS_H
#define RESIDUOS_BUSINESS_H

#include "residuos.h"

/**
 * @brief Processa e valida uma atualiza��o mensal, chamando a persist�ncia.
 * @return 0 em sucesso; -1 em erro de valida��o ou grava��o.
 */
int processarAtualizacaoMensal(const Residuos *r);

#endif // RESIDUOS_BUSINESS_H
