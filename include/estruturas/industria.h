#ifndef INDUSTRIA_H
#define INDUSTRIA_H

/**
 * Representa uma indústria cliente.
 */
typedef struct {
    char cnpj[18];         // formato 00.000.000/0000-00
    char razao_social[100];
    char nome_fantasia[100];
    char telefone[20];
    char endereco[150];    // rua, número, bairro, cidade, estado e CEP
    char email[100];
    char data_abertura[11]; // dd/mm/aaaa
} industria_t;

#endif /* INDUSTRIA_H */