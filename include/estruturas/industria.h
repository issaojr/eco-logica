#ifndef INDUSTRIA_H
#define INDUSTRIA_H

/**
 * Representa uma indústria cliente.
 */
typedef struct
{
    char cnpj[16]; /* 14 + '\n' + '\0'                  */
    char razao_social[128];
    char nome_fantasia[128];
    char telefone[32];
    char logradouro[128];
    char numero[16];
    char bairro[64];
    char cidade[64];
    char estado[4]; /* 2 + '\n' + '\0'                   */
    char cep[10]; /* 8 + '\n' + '\0'                   */
    char data_abertura[11]; 
    char nome_responsavel[128];
    char email_responsavel[128];
} industria_t;

#endif /* INDUSTRIA_H */
