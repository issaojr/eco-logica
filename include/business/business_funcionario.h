#ifndef BUSINESS_FUNCIONARIO_H
#define BUSINESS_FUNCIONARIO_H

#include "persistencia/funcionario_dao.h" // Garante que funcionario_t est� definido
#include <stddef.h>      // Para size_t

/**
 * Solicita e valida a matr�cula de um funcion�rio para edi��o.
 *
 * @return 1 se uma matr�cula v�lida foi obtida e armazenada na sess�o, 0 caso contr�rio
 */
int solicitar_matricula_edicao(void);

/**
 * Solicita e valida a matr�cula de um funcion�rio para exclus�o.
 *
 * @return 1 se uma matr�cula v�lida foi obtida e armazenada na sess�o, 0 caso contr�rio
 */
int solicitar_matricula_exclusao(void);

/**
 * @brief Obt�m a lista completa de todos os funcion�rios cadastrados.
 *
 * @param funcionarios_out Ponteiro para o array onde os funcion�rios ser�o armazenados.
 * @param max_funcionarios O tamanho m�ximo do array funcionarios_out.
 * @param total_funcionarios_out Ponteiro para armazenar o n�mero total de funcion�rios lidos.
 * @return int 1 se a leitura foi bem-sucedida (mesmo que vazia), 0 em caso de erro.
 */
int obter_todos_funcionarios(funcionario_t* funcionarios_out, size_t max_funcionarios, size_t* total_funcionarios_out);

#endif // BUSINESS_FUNCIONARIO_H