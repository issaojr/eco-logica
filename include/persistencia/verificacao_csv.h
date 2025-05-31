#ifndef VERIFICACAO_CSV_H
#define VERIFICACAO_CSV_H

#include <stdbool.h>

/**
 * Verifica se o diretório de dados existe e é acessível
 * @param erro_out Ponteiro para string onde serão armazenadas mensagens de erro, se necessário
 * @return true se o diretório existe e é acessível, false caso contrário
 */
bool verificar_diretorio_dados(char *erro_out);
/**
 * Verifica e corrige a integridade de todos os arquivos CSV do sistema
 * @param erro_out Ponteiro para string onde serão armazenadas mensagens de erro, se necessário
 * @return true se todas as verificações foram bem sucedidas, false caso contrário
 */
bool verificar_arquivos_csv(char *erro_out);

#endif 
