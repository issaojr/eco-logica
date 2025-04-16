#ifndef PERSISTENCIA_H
#define PERSISTENCIA_H

#include "funcionario.h"
#include "industria.h"

/**
 * @brief Salva os dados de um funcion√°rio em um arquivo CSV.
 *
 * Esta fun√ß√£o grava os dados do funcion√°rio (matr√≠cula, nome e senha) no arquivo especificado.
 * Os dados s√£o gravados no formato CSV, utilizando v√≠rgulas como delimitadores e aspas para
 * os campos de texto, garantindo que campos com v√≠rgulas internas sejam tratados corretamente.
 *
 * @param func Ponteiro para a estrutura Funcionario a ser salvo.
 * @param nomeArquivo Nome do arquivo onde os dados ser√£o gravados.
 * @return int Retorna 0 se a opera√ß√£o foi bem-sucedida ou um valor negativo em caso de erro.
 */
int salvarFuncionarioCSV(const Funcionario *func, const char *nomeArquivo);

/**
 * @brief Valida as credenciais de um funcion·rio pesquisando no arquivo CSV.
 *
 * Percorre o arquivo CSV em busca de um registro com a matrÌcula informada.
 * A senha digitada È criptografada (usando a mesma cifra XOR) e comparada com a senha armazenada.
 *
 * @param matricula MatrÌcula do usu·rio a ser validada.
 * @param senha Senha digitada pelo usu·rio (em texto claro).
 * @param funcEncontrado Ponteiro para uma estrutura Funcionario onde os dados do registro encontrado ser„o copiados.
 * @return int Retorna 0 se encontrar um usu·rio v·lido; caso contr·rio, retorna um valor negativo.
 */
int validarFuncionarioCSV(int matricula, const char *senha, Funcionario *funcEncontrado);

/**
 * @brief Salva os dados de uma ind˙stria em um arquivo CSV.
 *
 * @param ind Ponteiro para a estrutura Industria a ser salva.
 * @param nomeArquivo Nome do arquivo CSV onde os dados ser„o gravados.
 * @return int 0 se a operaÁ„o for bem-sucedida; -1 em caso de erro.
 */
int salvarIndustriaCSV(const Industria *ind, const char *nomeArquivo);

#endif // PERSISTENCIA_H
