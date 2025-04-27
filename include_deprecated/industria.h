#ifndef INDUSTRIA_H
#define INDUSTRIA_H

typedef struct {
    char nomeResponsavel[150];           // Nome da indústria
    char emailResponsavel[100];         // E-mail do responsável
    char cnpj[20];            // CNPJ
    char razaoSocial[150];    // Razão Social
    char nomeFantasia[150];   // Nome Fantasia
    char telefone[20];        // Telefone
    char logradouro[200];       // Endereço (rua, número, bairro, cidade, estado, CEP)
    char numero[10];         // Número do endereço
    char bairro[100];        // Bairro
    char cidade[100];       // Cidade
    char estado[3];        // Estado (sigla de 2 letras)
    char cep[10];          // CEP
    char email[100];          // E-mail
    char dataAbertura[20];    // Data de abertura (ex.: dd/mm/yyyy)
} Industria;

#endif // INDUSTRIA_H
