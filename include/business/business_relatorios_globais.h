#ifndef BUSINESS_RELATORIOS_GLOBAIS_H
#define BUSINESS_RELATORIOS_GLOBAIS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "persistencia/industria_dao.h"
#include "persistencia/residuo_dao.h"



/**
 * Exporta o relatório de resíduos por região para um arquivo CSV, XLS ou TXT.
 * @param void *relatorio - Ponteiro para a estrutura do relatório.
 * @param tipo_exportacao - Tipo de exportação (CSV, XLS, TXT).
 * @return true se a exportação foi bem-sucedida, false caso contrário.
 */
bool exportar_relatorio_residuos_por_regiao(void *relatorio, int tipo_exportacao);

/**
 * Exporta o relatório de indústrias com melhor desempenho ambiental para um arquivo CSV, XLS ou TXT.
 * @param void *relatorio - Ponteiro para a estrutura do relatório.
 * @param tipo_exportacao - Tipo de exportação (CSV, XLS, TXT).
 * @return true se a exportação foi bem-sucedida, false caso contrário.
 */
bool exportar_relatorio_industrias_melhor_desempenho(void *relatorio, int tipo_exportacao);

/**
 * Exporta o relatório de aporte financeiro semestral para um arquivo CSV, XLS ou TXT.
 * @param void *relatorio - Ponteiro para a estrutura do relatório.
 * @param tipo_exportacao - Tipo de exportação (CSV, XLS, TXT).
 * @return true se a exportação foi bem-sucedida, false caso contrário.
 */
bool exportar_relatorio_aporte_financeiro_semestral(void *relatorio, int tipo_exportacao);

#endif 