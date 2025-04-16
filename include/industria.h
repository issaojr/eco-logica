#ifndef INDUSTRIA_H
#define INDUSTRIA_H

typedef struct {
    char nome[150];           // Nome da ind�stria
    char cnpj[20];            // CNPJ
    char razaoSocial[150];    // Raz�o Social
    char nomeFantasia[150];   // Nome Fantasia
    char telefone[20];        // Telefone
    char endereco[200];       // Endere�o (rua, n�mero, bairro, cidade, estado, CEP)
    char email[100];          // E-mail
    char dataAbertura[20];    // Data de abertura (ex.: dd/mm/yyyy)
} Industria;

#endif // INDUSTRIA_H
