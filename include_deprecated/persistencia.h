#ifndef PERSISTENCIA_H
#define PERSISTENCIA_H

#include "funcionario.h"
#include "industria.h"
#include "residuos.h"

/**
 * @brief Salva os dados de um funcionÃ¡rio em um arquivo CSV.
 *
 * Esta funcao grava os dados do funcionario_t (matri­cula, nome e senha) no arquivo especificado.
 * Os dados sao gravados no formato CSV, utilizando vi­rgulas como delimitadores e aspas para
 * os campos de texto, garantindo que campos com vÃ­rgulas internas sejam tratados corretamente.
 *
 * @param func Ponteiro para a estrutura Funcionario a ser salvo.
 * @param nomeArquivo Nome do arquivo onde os dados serao gravados.
 * @return int Retorna 0 se a operacao foi bem-sucedida ou um valor negativo em caso de erro.
 */
int salvar_funcionario_csv(const Funcionario *func, const char *nomeArquivo);

/**
 * @brief Valida as credenciais de um funcionário pesquisando no arquivo CSV.
 *
 * Percorre o arquivo CSV em busca de um registro com a matrícula informada.
 * A senha digitada é criptografada (usando a mesma cifra XOR) e comparada com a senha armazenada.
 *
 * @param matricula Matrícula do usuário a ser validada.
 * @param senha Senha digitada pelo usuário (em texto claro).
 * @param funcEncontrado Ponteiro para uma estrutura Funcionario onde os dados do registro encontrado serão copiados.
 * @return int Retorna 0 se encontrar um usuário válido; caso contrário, retorna um valor negativo.
 */
int validarFuncionarioCSV(int matricula, const char *senha, Funcionario *funcEncontrado);

/**
 * @brief Salva os dados de uma indústria em um arquivo CSV.
 *
 * @param ind Ponteiro para a estrutura industria_t a ser salva.
 * @param nomeArquivo Nome do arquivo CSV onde os dados serão gravados.
 * @return int 0 se a operação for bem-sucedida; -1 em caso de erro.
 */
int salvarIndustriaCSV(const industria_t *ind, const char *nomeArquivo);

#endif // PERSISTENCIA_H

/**
 * @brief Salva uma atualização mensal de resíduos em CSV.
 */
int salvarResiduosCSV(const Residuos *r, const char *nomeArquivo);

