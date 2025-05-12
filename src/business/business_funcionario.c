#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "ui/ui_comum.h"
#include "session.h"
#include "business/business_funcionario.h"
#include "persistencia/funcionario_dao.h"

/**
 * @brief Obtém a lista completa de todos os funcionários cadastrados.
 *
 * @param funcionarios_out Ponteiro para o array onde os funcionários serão armazenados.
 * @param max_funcionarios O tamanho máximo do array funcionarios_out.
 * @param total_funcionarios_out Ponteiro para armazenar o número total de funcionários lidos.
 * @return int 1 se a leitura foi bem-sucedida (mesmo que vazia), 0 em caso de erro.
 */
int obter_todos_funcionarios(funcionario_t* funcionarios_out, size_t max_funcionarios, size_t* total_funcionarios_out) {
	// Delega a chamada para a camada de persistência
	if (listar_funcionarios_csv(funcionarios_out, max_funcionarios, total_funcionarios_out)) {
		return 0; // Sucesso
	} else {
		return 1; // Erro
	}
}

int adicionar_funcionario(funcionario_t* funcionario) {
	if (!funcionario) return 1; // Erro: funcionário inválido

	// Verifica se o funcionário já existe
	bool existe = buscar_funcionario_csv(funcionario->matricula, funcionario);

	if (existe) {
		return 2; // Erro: funcionário já existe
	}

	// Delega a chamada para a camada de persistência
	if (inserir_funcionario_csv(funcionario)) {
		return 0; // Sucesso
	} else {
		return 1; // Erro
	}
}

int editar_funcionario(funcionario_t* funcionario) {
	if (!funcionario) return 1; // Erro: funcionário inválido

	// Delega a chamada para a camada de persistência
	if (atualizar_funcionario_csv(funcionario)) {
		return 0; // Sucesso
	} else {
		return 1; // Erro
	}
}

int excluir_funcionario(int matricula) {
	// Delega a chamada para a camada de persistência
	if (excluir_funcionario_csv(matricula)) {
		return 0; // Sucesso
	} else {
		return 1; // Erro
	}
}

int buscar_funcionario_por_matricula(int matricula, funcionario_t* funcionario_out) {
	if (!funcionario_out) return 2; // Erro: ponteiro inválido
	
	// Delega a chamada para a camada de persistência
	if (buscar_funcionario_csv(matricula, funcionario_out)) {
		return 0; // Sucesso: funcionário encontrado
	} else {
		return 1; // Funcionário não encontrado
	}
}