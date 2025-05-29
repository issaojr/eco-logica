#ifndef INDUSTRIA_DAO_H
#define INDUSTRIA_DAO_H

#define IND_FILE "industrias.csv"
#define IND_FILE_TEMP "industrias_temp.csv"

#define TAMANHO_LINHA_IND 1024

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
#include <string.h>
#include "estruturas/industria.h"
#include "ui/ui_comum.h"
#include "util.h"

/**
 * Valida se uma indústria com dado CNPJ existe na base CSV.
 */
bool validar_industria_csv(const char *cnpj, industria_t *out_industria);

/**
 * Insere uma nova indústria na base CSV.
 */
bool inserir_industria_csv(const industria_t *industria);

/**
 * Busca uma indústria por CNPJ na base CSV.
 */
bool buscar_industria_csv(const char *cnpj, industria_t *out_industria);

/**
 * Lista todas as indústrias cadastradas na base CSV.
 */
bool listar_industrias_csv(industria_t *industrias, size_t tamanho_max, size_t *qtd_industrias);

/**
 * Atualiza os dados de uma indústria na base CSV.
 */
bool atualizar_industria_csv(const industria_t *industria);

/**
 * Exclui uma indústria da base CSV.
 */
bool excluir_industria_csv(const char *cnpj);

/**
 * Verifica e corrige problemas nos arquivos CSV de indústrias
 * @return true se a verificação foi bem sucedida, false caso contrário
 */
bool verificar_csv_industria(void);

#endif 
