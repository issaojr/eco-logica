#ifndef RELATORIOS_H
#define RELATORIOS_H

/**
 * @brief Gera relatório de insumos tratados semestralmente para uma indústria.
 *
 * @param cnpj      CNPJ da indústria
 * @param anoIni    Ano inicial do semestre (ex: 2025 para primeiro semestre de 2025)
 * @param anoFim    Ano final do semestre ou mesmo anoIni
 */
void gerarRelatorioInsumosSemestre(const char *cnpj, int anoIni, int anoFim);

/**
 * @brief Gera relatório de gastos mensais para uma indústria.
 *
 * @param cnpj      CNPJ da indústria
 * @param mes       Mês (1-12)
 * @param ano       Ano
 */
void gerarRelatorioGastosMensais(const char *cnpj, int mes, int ano);

/**
 * @brief Gera relatório global de regiões com maior volume de resíduos.
 */
void gerarRelatorioGlobalRegioes(void);

/**
 * @brief Gera relatório global das indústrias com menor produção no período.
 *
 * @param anoIni    Ano inicial do período
 * @param anoFim    Ano final do período
 */
void gerarRelatorioGlobalMenorProducao(int anoIni, int anoFim);

/**
 * @brief Gera relatório global de aporte financeiro semestral.
 *
 * @param anoIni    Ano inicial
 * @param anoFim    Ano final
 */
void gerarRelatorioGlobalAporteFinanceiro(int anoIni, int anoFim);

#endif // RELATORIOS_H