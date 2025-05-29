#ifndef RESIDUO_DAO_H
#define RESIDUO_DAO_H

#define RES_FILE "residuos.csv"
#define RES_FILE_TEMP "residuos_temp.csv"

#define TAMANHO_LINHA_RES 256
#define MAX_RESIDUOS 99999

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
#include <string.h>
#include "estruturas/residuo.h"
#include "ui/ui_comum.h"
#include "util.h"

/**
 * Insere um novo registro de resíduo na base CSV.
 */
bool inserir_residuo_csv(const residuo_t *residuo);

/**
 * Busca um registro específico de resíduo por CNPJ, mês e ano.
 */
bool buscar_residuo_csv(const char *cnpj, int mes, int ano, residuo_t *out_residuo);

/**
 * Lista todos os registros de resíduos de uma indústria específica.
 */
bool listar_residuos_por_cnpj_csv(const char *cnpj, residuo_t *residuos, size_t tamanho_max, size_t *qtd_residuos);

/**
 * Atualiza os dados de um registro de resíduo na base CSV.
 */
bool atualizar_residuo_csv(const residuo_t *residuo);

/**
 * Exclui um registro de resíduo da base CSV.
 */
bool excluir_residuo_csv(const char *cnpj, int mes, int ano);

/**
 * Busca todos os registros de resíduos de uma indústria específica (alocação dinâmica)
 * @param cnpj CNPJ da indústria
 * @param registros ponteiro para array que receberá os registros (será alocado pela função)
 * @param total ponteiro para receber o número total de registros encontrados
 * @return true se a busca foi bem sucedida, false caso contrário
 */
bool buscar_residuos_por_cnpj(const char *cnpj, residuo_t **registros, size_t *total);

/**
 * Libera a memória alocada para array de registros
 * @param registros array de registros para liberar
 */
void liberar_registros_residuos(residuo_t *registros);

bool buscar_residuos_csv(residuo_t **registros, size_t *total);

/**
 * Verifica e corrige problemas nos arquivos CSV de resíduos
 * @return true se a verificação foi bem sucedida, false caso contrário
 */
bool verificar_csv_residuo(void);

#endif // RESIDUO_DAO_H
