#ifndef PERSISTENCIA_H
#define PERSISTENCIA_H

#include <stdbool.h>
#include "funcionario.h"
#include "industria.h"
#include "residuos.h"

/**
 * Valida se existe um funcionário com matrícula e senha hash na base CSV.
 * @param matricula Matrícula buscada.
 * @param senha Texto claro a ser validado.
 * @param out_funcionario Preenchido com dados se encontrado.
 * @return true se válido, false caso contrário.
 */
bool validar_funcionario_csv(int matricula, const char *senha, funcionario_t *out_funcionario);

/**
 * Insere um novo funcionário na base CSV.
 * @param funcionario Ponteiro para o funcionário a ser inserido
 * @return true se foi inserido com sucesso, false caso contrário
 */
bool inserir_funcionario_csv(const funcionario_t *funcionario);

/**
 * Busca um funcionário por matrícula na base CSV.
 * @param matricula Matrícula do funcionário a ser buscado
 * @param out_funcionario Estrutura onde serão armazenados os dados do funcionário 
 * @return true se encontrado, false caso contrário
 */
bool buscar_funcionario_csv(int matricula, funcionario_t *out_funcionario);

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
bool excluir_funcionario_csv(int matricula);

/**
 * Valida se uma indústria com dado CNPJ existe na base CSV.
 */
bool validar_industria_csv(const char *cnpj, industria_t *out_industria);

/**
 * Insere uma nova indústria na base CSV.
 */
bool inserir_industria_csv(const industria_t *industria);

/**
 * Lê/atualiza registro de resíduos para CNPJ, mês e ano.
 */
bool gravar_residuo_csv(const residuo_t *residuo);

#endif // PERSISTENCIA_H
