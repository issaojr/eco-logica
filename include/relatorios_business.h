#ifndef RELATORIOS_H
#define RELATORIOS_H

/**
 * @brief Gera relat�rio de insumos tratados semestralmente para uma ind�stria.
 *
 * @param cnpj      CNPJ da ind�stria
 * @param anoIni    Ano inicial do semestre (ex: 2025 para primeiro semestre de 2025)
 * @param anoFim    Ano final do semestre ou mesmo anoIni
 */
void gerarRelatorioInsumosSemestre(const char *cnpj, int anoIni, int anoFim);

/**
 * @brief Gera relat�rio de gastos mensais para uma ind�stria.
 *
 * @param cnpj      CNPJ da ind�stria
 * @param mes       M�s (1-12)
 * @param ano       Ano
 */
void gerarRelatorioGastosMensais(const char *cnpj, int mes, int ano);

/**
 * @brief Gera relat�rio global de regi�es com maior volume de res�duos.
 */
void gerarRelatorioGlobalRegioes(void);

/**
 * @brief Gera relat�rio global das ind�strias com menor produ��o no per�odo.
 *
 * @param anoIni    Ano inicial do per�odo
 * @param anoFim    Ano final do per�odo
 */
void gerarRelatorioGlobalMenorProducao(int anoIni, int anoFim);

/**
 * @brief Gera relat�rio global de aporte financeiro semestral.
 *
 * @param anoIni    Ano inicial
 * @param anoFim    Ano final
 */
void gerarRelatorioGlobalAporteFinanceiro(int anoIni, int anoFim);

#endif // RELATORIOS_H