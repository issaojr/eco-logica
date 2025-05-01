#ifndef UI_COMUM_H
#define UI_COMUM_H

#include <stdio.h>
#include <stdbool.h>

/**
 * @brief Limpa a tela do console
 */
void ui_limpar_tela(void);

/**
 * @brief Exibe um t�tulo padronizado para uma tela
 * @param titulo Texto do t�tulo
 * @param subtitulo Texto do subt�tulo (pode ser NULL)
 */
void ui_exibir_titulo(const char* titulo, const char* subtitulo);

/**
 * @brief Exibe uma linha separadora horizontal
 * @param caractere Caractere usado para formar a linha
 * @param largura Largura da linha
 */
void ui_exibir_separador(char caractere, int largura);

/**
 * @brief Exibe uma mensagem de erro formatada
 * @param mensagem Texto da mensagem de erro
 */
void ui_exibir_erro(const char* mensagem);

/**
 * @brief Exibe uma mensagem de sucesso formatada
 * @param mensagem Texto da mensagem de sucesso
 */
void ui_exibir_sucesso(const char* mensagem);

/**
 * @brief Exibe uma mensagem informativa formatada
 * @param mensagem Texto da mensagem informativa
 */
void ui_exibir_info(const char* mensagem);

/**
 * @brief Pausa a execu��o e aguarda o usu�rio pressionar ENTER
 * @param mensagem Texto opcional a ser exibido (pode ser NULL para usar mensagem padr�o)
 */
void ui_pausar(const char* mensagem);

/**
 * @brief L� uma string da entrada padr�o com valida��o de tamanho
 * @param prompt Texto do prompt
 * @param buffer Buffer para armazenar a string
 * @param tamanho Tamanho m�ximo da string
 * @param obrigatorio Se true, n�o aceita entrada vazia
 * @return true se a leitura foi bem-sucedida
 */
bool ui_ler_string(const char* prompt, char* buffer, size_t tamanho, bool obrigatorio);

/**
 * @brief L� um n�mero inteiro da entrada padr�o com valida��o
 * @param prompt Texto do prompt
 * @param min Valor m�nimo permitido
 * @param max Valor m�ximo permitido
 * @param padrao Valor padr�o caso a entrada seja vazia
 * @param obrigatorio Se true, n�o aceita entrada vazia
 * @return O n�mero lido, ou o valor padr�o
 */
int ui_ler_inteiro(const char* prompt, int min, int max, int padrao, bool obrigatorio);

/**
 * @brief L� uma data no formato DD/MM/AAAA com valida��o
 * @param prompt Texto do prompt
 * @param buffer Buffer para armazenar a data
 * @param tamanho Tamanho do buffer
 * @param obrigatorio Se true, n�o aceita entrada vazia
 * @return true se a data for v�lida
 */
bool ui_ler_data(const char* prompt, char* buffer, size_t tamanho, bool obrigatorio);

/**
 * @brief L� um CNPJ com valida��o
 * @param prompt Texto do prompt
 * @param buffer Buffer para armazenar o CNPJ
 * @param tamanho Tamanho do buffer
 * @param obrigatorio Se true, n�o aceita entrada vazia
 * @return true se o CNPJ for v�lido
 */
bool ui_ler_cnpj(const char* prompt, char* buffer, size_t tamanho, bool obrigatorio);

/**
 * @brief Exibe uma interface para confirma��o sim/n�o
 * @param mensagem Pergunta a ser exibida
 * @return true para sim, false para n�o
 */
bool ui_confirmar(const char* mensagem);

#endif // UI_COMUM_H