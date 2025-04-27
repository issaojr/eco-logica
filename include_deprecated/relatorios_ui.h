#ifndef RELATORIOS_UI_H
#define RELATORIOS_UI_H

#define POR_INDUSTRIA 1
#define GLOBAL 2
#define MENSAL 3
#define SEMESTRAL 4
#define ANUAL 5

/**
 * @brief Inicia a interface de relat�rio, permitindo ao usu�rio escolher
 *        tipo de relat�rio, par�metros e exporta��o.
 */
void iniciarInterfaceRelatorios(int tipoRelatorio);
void showExportMenu(void);
void showRelatoriosPorIndustriaMenu(void);
void showRelatoriosGlobaisMenu(void);

#endif // RELATORIOS_UI_H
