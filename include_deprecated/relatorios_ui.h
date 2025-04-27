#ifndef RELATORIOS_UI_H
#define RELATORIOS_UI_H

#define POR_INDUSTRIA 1
#define GLOBAL 2
#define MENSAL 3
#define SEMESTRAL 4
#define ANUAL 5

/**
 * @brief Inicia a interface de relatório, permitindo ao usuário escolher
 *        tipo de relatório, parâmetros e exportação.
 */
void iniciarInterfaceRelatorios(int tipoRelatorio);
void showExportMenu(void);
void showRelatoriosPorIndustriaMenu(void);
void showRelatoriosGlobaisMenu(void);

#endif // RELATORIOS_UI_H
