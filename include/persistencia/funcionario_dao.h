#ifndef FUNCIONARIO_DAO_H
#define FUNCIONARIO_DAO_H

#define FUNC_FILE "funcionarios.csv"
#define FUNC_FILE_TEMP "funcionarios_temp.csv"
#define HASH_KEY ((char)0xAA)

#define TAMANHO_LINHA_FUNC 256

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
#include "estruturas/funcionario.h"
#include "business/business_crypto.h"
#include "ui/ui_comum.h"

/**
 * Valida se existe um funcionário com matrícula e senha hash na base CSV.
 * @param matricula Matrícula buscada.
 * @param senha Texto claro a ser validado.
 * @param out_funcionario Preenchido com dados se encontrado.
 * @return true se válido, false caso contrário.
 */
bool validar_funcionario_csv(const char *matricula_str, const char *senha, funcionario_t *out_funcionario);

/**
 * Insere um novo funcionário na base CSV.
 * @param funcionario Ponteiro para o funcionário a ser inserido
 * @return true se foi inserido com sucesso, false caso contrário
 */
bool inserir_funcionario_csv(const funcionario_t *funcionario);

/**
 * Busca um funcionário por matrícula na base CSV.
 * @param matricula_str Matrícula do funcionário a ser buscado como string
 * @param out_funcionario Estrutura onde serão armazenados os dados do funcionário
 * @return true se encontrado, false caso contrário
 */
bool buscar_funcionario_csv(const char *matricula_str, funcionario_t *out_funcionario);

/**
 * Lista todos os funcionários cadastrados na base CSV.
 * @param funcionarios Array onde serão armazenados os funcionários
 * @param tamanho_max Tamanho máximo do array
 * @param qtd_funcionarios Ponteiro para variável onde será armazenada a quantidade de funcionários encontrados
 * @return true se a leitura foi realizada com sucesso, false caso contrário
 */
bool listar_funcionarios_csv(funcionario_t *funcionarios, size_t tamanho_max, size_t *qtd_funcionarios);

/**
 * Atualiza os dados de um funcionário na base CSV.
 * @param funcionario Ponteiro para o funcionário com os dados atualizados
 * @return true se foi atualizado com sucesso, false caso contrário
 */
bool atualizar_funcionario_csv(const funcionario_t *funcionario);

/**
 * Exclui um funcionário da base CSV.
 * @param matricula Matrícula do funcionário a ser excluído
 * @return true se foi excluído com sucesso, false caso contrário
 */
bool excluir_funcionario_csv(const char *matricula_str);

/**
 * Verifica e corrige problemas nos arquivos CSV de funcionários
 * @return true se a verificação foi bem sucedida, false caso contrário
 */
bool verificar_csv_funcionario(void);

#endif // FUNCIONARIO_DAO_H
