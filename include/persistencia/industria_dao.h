#ifndef INDUSTRIA_DAO_H
#define INDUSTRIA_DAO_H

#define IND_FILE  "industrias.csv"

#include <stddef.h>
#include <stdbool.h>

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


/**
 * Valida se uma indústria com dado CNPJ existe na base CSV.
 */
bool validar_industria_csv(const char *cnpj, industria_t *out_industria);

/**
 * Insere uma nova indústria na base CSV.
 */
bool inserir_industria_csv(const industria_t *industria);

#endif // INDUSTRIA_DAO_H