#ifndef RELATORIO_DAO_H
#define RELATORIO_DAO_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
#include <string.h>
#include "estruturas/relatorio.h"
#include "estruturas/industria.h"
#include "estruturas/residuo.h"
#include "ui/ui_comum.h"
#include "util.h"

bool inserir_rel_arquivo(
    relatorio_t *rel, 
    const char *nome_base,
    const char *ext,
    const char *separador);

/**
 * Verifica se um arquivo existe.
 * @param nome_arquivo - Nome do arquivo a ser verificado.
 * @return true se o arquivo existe, false caso contrário.
 */
bool arquivo_existe(const char *nome_arquivo);

/**
 * Gera um nome único para o arquivo de relatório, evitando sobrescritas.
 * @param nome_base - Nome base do arquivo.
 * @param saida - Buffer onde o nome único será armazenado.
 * @param tamanho - Tamanho do buffer de saída.
 * @param extensao - Extensão do arquivo (ex: "csv", "txt").
 */
void gerar_nome_unico(
    const char *nome_base, 
    char *saida, 
    size_t tamanho, 
    const char *extensao
);

#endif /* RELATORIO_DAO_H */