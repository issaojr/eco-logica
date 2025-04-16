#ifndef INDUSTRIA_BUSINESS_H
#define INDUSTRIA_BUSINESS_H

#include "industria.h"

/**
 * @brief Processa os dados coletados para o cadastro de uma ind�stria,
 * realizando valida��es e integrando com a camada de persist�ncia.
 * 
 * @param ind Ponteiro para a ind�stria a ser processada.
 * @return int 0 se o cadastro for bem-sucedido, ou outro valor em caso de erro.
 */
int processarCadastroIndustria(Industria *ind);

#endif // INDUSTRIA_BUSINESS_H
