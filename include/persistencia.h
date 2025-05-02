#ifndef PERSISTENCIA_H
#define PERSISTENCIA_H

#include <stdbool.h>
#include "funcionario.h"
#include "industria.h"
#include "residuos.h"

/**
 * Valida se existe um funcion�rio com matr�cula e senha hash na base CSV.
 * @param matricula Matr�cula buscada.
 * @param senha Texto claro a ser validado.
 * @param out_funcionario Preenchido com dados se encontrado.
 * @return true se v�lido, false caso contr�rio.
 */
bool validar_funcionario_csv(int matricula, const char *senha, funcionario_t *out_funcionario);

/**
 * Insere um novo funcion�rio na base CSV.
 * @param funcionario Ponteiro para o funcion�rio a ser inserido
 * @return true se foi inserido com sucesso, false caso contr�rio
 */
bool inserir_funcionario_csv(const funcionario_t *funcionario);

/**
 * Busca um funcion�rio por matr�cula na base CSV.
 * @param matricula Matr�cula do funcion�rio a ser buscado
 * @param out_funcionario Estrutura onde ser�o armazenados os dados do funcion�rio 
 * @return true se encontrado, false caso contr�rio
 */
bool buscar_funcionario_csv(int matricula, funcionario_t *out_funcionario);

/**
 * Lista todos os funcion�rios cadastrados na base CSV.
 * @param funcionarios Array onde ser�o armazenados os funcion�rios
 * @param tamanho_max Tamanho m�ximo do array
 * @param qtd_funcionarios Ponteiro para vari�vel onde ser� armazenada a quantidade de funcion�rios encontrados
 * @return true se a leitura foi realizada com sucesso, false caso contr�rio
 */
bool listar_funcionarios_csv(funcionario_t *funcionarios, size_t tamanho_max, size_t *qtd_funcionarios);

/**
 * Atualiza os dados de um funcion�rio na base CSV.
 * @param funcionario Ponteiro para o funcion�rio com os dados atualizados
 * @return true se foi atualizado com sucesso, false caso contr�rio
 */
bool atualizar_funcionario_csv(const funcionario_t *funcionario);

/**
 * Exclui um funcion�rio da base CSV.
 * @param matricula Matr�cula do funcion�rio a ser exclu�do
 * @return true se foi exclu�do com sucesso, false caso contr�rio
 */
bool excluir_funcionario_csv(int matricula);

/**
 * Valida se uma ind�stria com dado CNPJ existe na base CSV.
 */
bool validar_industria_csv(const char *cnpj, industria_t *out_industria);

/**
 * Insere uma nova ind�stria na base CSV.
 */
bool inserir_industria_csv(const industria_t *industria);

/**
 * L�/atualiza registro de res�duos para CNPJ, m�s e ano.
 */
bool gravar_residuo_csv(const residuo_t *residuo);

#endif // PERSISTENCIA_H
