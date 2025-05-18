#ifndef BUSINESS_INDUSTRIA_H
#define BUSINESS_INDUSTRIA_H

#include <stddef.h> // Para size_t
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "ui/ui_comum.h"
#include "session.h"
#include "persistencia/industria_dao.h"

/**
 * Cadastra uma nova indústria se o CNPJ não existir.
 * @param industria Dados da indústria a cadastrar.
 * @return true se cadastrado com sucesso, false se CNPJ já existir ou falha de I/O.
 */
bool cadastrar_industria(const industria_t *industria);

/**
 * Adiciona uma nova indústria.
 * @param industria Dados da indústria a adicionar.
 * @return 0 se sucesso, 1 se erro, 2 se já existe.
 */
int adicionar_industria(industria_t *industria);

/**
 * Edita uma indústria existente.
 * @param industria Dados da indústria a editar.
 * @return 0 se sucesso, 1 se erro, 2 se não existe.
 */

int editar_industria(industria_t *industria);

/**
 * Exclui uma indústria existente.
 * @param cnpj CNPJ da indústria a excluir.
 * @return 0 se sucesso, 1 se erro, 2 se não existe.
 */

int excluir_industria(const char *cnpj);

/**
 * Busca uma indústria pelo CNPJ.
 * @param cnpj CNPJ da indústria a buscar.
 * @param industria_out Ponteiro para armazenar os dados da indústria encontrada.
 * @return 0 se sucesso, 1 se erro, 2 se não existe.
 */

int buscar_industria_por_cnpj(const char *cnpj, industria_t *industria_out);

/**
 * Obtém a lista completa de todas as indústrias cadastradas.
 * @param industrias_out Ponteiro para o array onde as indústrias serão armazenadas.
 * @param max_industrias Tamanho máximo do array industrias_out.
 * @param total_industrias_out Ponteiro para armazenar o número total de indústrias lidas.
 * @return 0 se sucesso, 1 se erro.
 */

int obter_todas_industrias(industria_t *industrias_out, size_t max_industrias, size_t *total_industrias_out);

#endif // BUSINESS_INDUSTRIA_H