#ifndef PERSISTENCIA_H
#define PERSISTENCIA_H

#include "funcionario.h"
#include "industria.h"
#include "residuos.h"

/**
 * @brief Salva os dados de um funcionário em um arquivo CSV.
 *
 * Esta funcao grava os dados do funcionario (matri�cula, nome e senha) no arquivo especificado.
 * Os dados sao gravados no formato CSV, utilizando vi�rgulas como delimitadores e aspas para
 * os campos de texto, garantindo que campos com vírgulas internas sejam tratados corretamente.
 *
 * @param func Ponteiro para a estrutura Funcionario a ser salvo.
 * @param nomeArquivo Nome do arquivo onde os dados serao gravados.
 * @return int Retorna 0 se a operacao foi bem-sucedida ou um valor negativo em caso de erro.
 */
int salvar_funcionario_csv(const Funcionario *func, const char *nomeArquivo);

/**
 * @brief Valida as credenciais de um funcion�rio pesquisando no arquivo CSV.
 *
 * Percorre o arquivo CSV em busca de um registro com a matr�cula informada.
 * A senha digitada � criptografada (usando a mesma cifra XOR) e comparada com a senha armazenada.
 *
 * @param matricula Matr�cula do usu�rio a ser validada.
 * @param senha Senha digitada pelo usu�rio (em texto claro).
 * @param funcEncontrado Ponteiro para uma estrutura Funcionario onde os dados do registro encontrado ser�o copiados.
 * @return int Retorna 0 se encontrar um usu�rio v�lido; caso contr�rio, retorna um valor negativo.
 */
int validarFuncionarioCSV(int matricula, const char *senha, Funcionario *funcEncontrado);

/**
 * @brief Salva os dados de uma ind�stria em um arquivo CSV.
 *
 * @param ind Ponteiro para a estrutura Industria a ser salva.
 * @param nomeArquivo Nome do arquivo CSV onde os dados ser�o gravados.
 * @return int 0 se a opera��o for bem-sucedida; -1 em caso de erro.
 */
int salvarIndustriaCSV(const Industria *ind, const char *nomeArquivo);

#endif // PERSISTENCIA_H

/**
 * @brief Salva uma atualiza��o mensal de res�duos em CSV.
 */
int salvarResiduosCSV(const Residuos *r, const char *nomeArquivo);

