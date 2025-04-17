#ifndef CADASTRO_H
#define CADASTRO_H

#include "funcionario.h"

/**
 * @brief Realiza o cadastro de um novo usu�rio.
 *
 * Fun��o para ler os dados do novo funcion�rio (matr�cula, senha e nome)
 * e, por enquanto, exibe uma mensagem de sucesso. Em itera��es futuras, 
 * a persist�ncia poder� ser implementada.
 */
int processaCadastroFuncionario(int matricula, const char *nome, const char *senha);

#endif // CADASTRO_H
