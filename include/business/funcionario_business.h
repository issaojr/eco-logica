#ifndef FUNCIONARIO_BUSINESS_H
#define FUNCIONARIO_BUSINESS_H

#include "persistencia/funcionario_dao.h" // Garante que funcionario_t está definido
#include <stddef.h>      // Para size_t

/**
 * Solicita e valida a matrícula de um funcionário para edição.
 * 
 * @return 1 se uma matrícula válida foi obtida e armazenada na sessão, 0 caso contrário
 */
int solicitar_matricula_edicao(void);

/**
 * Solicita e valida a matrícula de um funcionário para exclusão.
 * 
 * @return 1 se uma matrícula válida foi obtida e armazenada na sessão, 0 caso contrário
 */
int solicitar_matricula_exclusao(void);

/**
 * @brief Obtém a lista completa de todos os funcionários cadastrados.
 * 
 * @param funcionarios_out Ponteiro para o array onde os funcionários serão armazenados.
 * @param max_funcionarios O tamanho máximo do array funcionarios_out.
 * @param total_funcionarios_out Ponteiro para armazenar o número total de funcionários lidos.
 * @return int 1 se a leitura foi bem-sucedida (mesmo que vazia), 0 em caso de erro.
 */
int obter_todos_funcionarios(funcionario_t* funcionarios_out, size_t max_funcionarios, size_t* total_funcionarios_out);

#endif // FUNCIONARIO_BUSINESS_H