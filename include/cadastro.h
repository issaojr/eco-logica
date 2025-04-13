// EcoLogica/src/business/cadastro.h
#ifndef CADASTRO_H
#define CADASTRO_H

#include "funcionario.h"

/**
 * @brief Realiza o cadastro de um novo usuário.
 *
 * Função para ler os dados do novo funcionário (matrícula, senha e nome)
 * e, por enquanto, exibe uma mensagem de sucesso. Em iterações futuras, 
 * a persistência poderá ser implementada.
 */
int processaCadastro(int matricula, const char *nome, const char *senha);

#endif // CADASTRO_H
