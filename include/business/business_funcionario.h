#ifndef BUSINESS_FUNCIONARIO_H
#define BUSINESS_FUNCIONARIO_H

#define TAM_MAX_FUNCIONARIOS 256

#include <stddef.h> // Para size_t
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "ui/ui_comum.h"
#include "session.h"
#include "persistencia/funcionario_dao.h"
#include "persistencia/relatorio_dao.h"

/**
 * @brief Obtém a lista completa de todos os funcionários cadastrados.
 *
 * @param funcionarios_out Ponteiro para o array onde os funcionários serão armazenados.
 * @param max_funcionarios O tamanho máximo do array funcionarios_out.
 * @param total_funcionarios_out Ponteiro para armazenar o número total de funcionários lidos.
 * @return int 1 se a leitura foi bem-sucedida (mesmo que vazia), 0 em caso de erro.
 */
bool obter_todos_funcionarios(funcionario_t *funcionarios_out, size_t max_funcionarios, size_t *total_funcionarios_out);
int adicionar_funcionario(funcionario_t *funcionario);
int editar_funcionario(funcionario_t *funcionario);
int excluir_funcionario(char *matricula);

/**
 * @brief Busca um funcionário pelo número de matrícula.
 *
 * @param matricula Número de matrícula do funcionário a ser buscado.
 * @param funcionario_out Ponteiro para a estrutura onde os dados do funcionário serão armazenados.
 * @return true se o funcionário foi encontrado, false caso contrário.
 */
bool buscar_funcionario_por_matricula(char *matricula, funcionario_t *funcionario_out);

bool gerar_relatorio_lista_funcionarios(relatorio_t *rel);

#endif // BUSINESS_FUNCIONARIO_H
