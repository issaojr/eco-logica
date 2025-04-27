#ifndef CADASTRO_H
#define CADASTRO_H

#include "funcionario.h"
#include "erros.h" // Para usar codigo_erro

/**
 * @brief Realiza o cadastro de um novo usuário.
 *
 * Função para ler os dados do novo funcionário (matrícula, senha e nome)
 * e, por enquanto, exibe uma mensagem de sucesso. Em iterações futuras, 
 * a persistência poderá ser implementada.
 */
codigo_erro processa_cadastro_funcionario(int matricula, const char *nome, const char *senha);

#endif // CADASTRO_H
