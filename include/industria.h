#ifndef INDUSTRIA_H
#define INDUSTRIA_H

typedef struct {
    char nome[150];           // Nome da indústria
    char cnpj[20];            // CNPJ
    char razaoSocial[150];    // Razão Social
    char nomeFantasia[150];   // Nome Fantasia
    char telefone[20];        // Telefone
    char endereco[200];       // Endereço (rua, número, bairro, cidade, estado, CEP)
    char email[100];          // E-mail
    char dataAbertura[20];    // Data de abertura (ex.: dd/mm/yyyy)
} Industria;

#endif // INDUSTRIA_H
