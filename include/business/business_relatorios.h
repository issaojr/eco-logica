#ifndef BUSINESS_RELATORIOS_H
#define BUSINESS_RELATORIOS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "persistencia/industria_dao.h"
#include "persistencia/residuo_dao.h"
#include "persistencia/relatorio_dao.h"
#include "estruturas/relatorio.h"
#include "ui/ui_comum.h"
#include "util.h"

/*--------------------------RELATÓRIOS GLOBAIS-----------------------------*/
/**
 * Gera relatório de resíduos por região.
 * @param estrutura de dados para armazenar o relatório.
 * @return true se o relatório foi gerado com sucesso, false caso contrário.
 */
bool gerar_relatorio_residuos_por_regiao(relatorio_t *relatorio);

/**
 * Gera relatório de indústrias com melhor desempenho ambiental.
 * @param estrutura de dados para armazenar o relatório.
 * @return true se o relatório foi gerado com sucesso, false caso contrário.
 */
bool gerar_relatorio_industrias_melhor_desempenho(relatorio_t *relatorio);

/**
 * Gera relatório de aporte financeiro semestral.
 * @param estrutura de dados para armazenar o relatório.
 * @return true se o relatório foi gerado com sucesso, false caso contrário.
 */
bool gerar_relatorio_aporte_financeiro_semestral(relatorio_t *relatorio);

/*---------------------------RELATÓRIOS POR INDÚSTRIA-----------------------------*/

/**
 * Gera relatório de resíduos semestrais para uma indústria específica.
 * @param industria_t *i - Ponteiro para a estrutura da indústria.
 * @param estrutura de dados para armazenar o relatório.
 * @return true se o relatório foi gerado com sucesso, false caso contrário.
 */
bool gerar_relatorio_residuos_semestral(industria_t *i, relatorio_t *relatorio);

/**
 * Gera relatório de gastos mensais para uma indústria específica.
 * @param industria_t *i - Ponteiro para a estrutura da indústria.
 * @param estrutura de dados para armazenar o relatório.
 * @return true se o relatório foi gerado com sucesso, false caso contrário.
 */
bool gerar_relatorio_gastos_mensais(industria_t *i, relatorio_t *relatorio);

/*----------------------------EXPORTAÇÃO DE RELATÓRIOS-----------------------------*/

/**
 * Exporta um relatório para um arquivo com a extensão e separador especificados.
 * @param rel - Ponteiro para a estrutura do relatório.
 * @param nome_base - Nome base do arquivo (sem extensão).
 * @param extensao - Extensão do arquivo (ex: "csv", "txt").
 * @param separador - Separador de campos (ex: ",", ";").
 * @return true se a exportação foi bem-sucedida, false caso contrário.
 */
bool relatorio_exportar(
    relatorio_t *rel,
    const char *nome_base,
    const char *extensao,
    const char *separador);

void relatorio_liberar(relatorio_t *rel);


#endif // BUSINESS_RELATORIOS_H
