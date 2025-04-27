#ifndef INDUSTRIA_BUSINESS_H
#define INDUSTRIA_BUSINESS_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "industria_business.h"
#include "industria.h"
#include "persistencia.h" // Usaremos uma fun��o para salvar em CSV

/**
 * @brief Processa os dados coletados para o cadastro de uma ind�stria,
 * realizando valida��es e integrando com a camada de persist�ncia.
 * 
 * @param ind Ponteiro para a ind�stria a ser processada.
 * @return int 0 se o cadastro for bem-sucedido, ou outro valor em caso de erro.
 */
int processarCadastroIndustria(char *nomeResponsavel, char *emailResponsavel, char *cnpj, char *razaoSocial, char *nomeFantasia,
    char *telefone, char *logradouro, char *numero, char *bairro, char *cidade, char *estado, char *cep, char *email,
    char *dataAbertura
);

#endif // INDUSTRIA_BUSINESS_H
