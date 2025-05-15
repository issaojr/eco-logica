#ifndef BUSINESS_INDUSTRIA_H
#define BUSINESS_INDUSTRIA_H

#include <stdbool.h>
#include <stdbool.h>
#include "persistencia/industria_dao.h"

/**
 * Cadastra uma nova ind�stria se o CNPJ n�o existir.
 * @param industria Dados da ind�stria a cadastrar.
 * @return true se cadastrado com sucesso, false se CNPJ j� existir ou falha de I/O.
 */
bool cadastrar_industria(const industria_t* industria);

/**
 * Adiciona uma nova ind�stria.
 * @param industria Dados da ind�stria a adicionar.
 * @return 0 se sucesso, 1 se erro, 2 se j� existe.
 */
int adicionar_industria(industria_t* industria);

/**
 * Edita uma ind�stria existente.
 * @param industria Dados da ind�stria a editar.
 * @return 0 se sucesso, 1 se erro, 2 se n�o existe.
 */

int editar_industria(industria_t* industria);

/**
 * Exclui uma ind�stria existente.
 * @param cnpj CNPJ da ind�stria a excluir.
 * @return 0 se sucesso, 1 se erro, 2 se n�o existe.
 */

int excluir_industria(const char* cnpj);

/**
 * Busca uma ind�stria pelo CNPJ.
 * @param cnpj CNPJ da ind�stria a buscar.
 * @param industria_out Ponteiro para armazenar os dados da ind�stria encontrada.
 * @return 0 se sucesso, 1 se erro, 2 se n�o existe.
 */

int buscar_industria_por_cnpj(const char* cnpj, industria_t* industria_out);

/**
 * Obt�m a lista completa de todas as ind�strias cadastradas.
 * @param industrias_out Ponteiro para o array onde as ind�strias ser�o armazenadas.
 * @param max_industrias Tamanho m�ximo do array industrias_out.
 * @param total_industrias_out Ponteiro para armazenar o n�mero total de ind�strias lidas.
 * @return 0 se sucesso, 1 se erro.
 */

int obter_todas_industrias(industria_t* industrias_out, size_t max_industrias, size_t* total_industrias_out);

#endif // BUSINESS_INDUSTRIA_H