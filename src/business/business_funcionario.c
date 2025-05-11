#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "ui/ui_comum.h"
#include "session.h"
#include "business/business_funcionario.h"
#include "persistencia/funcionario_dao.h"

/**
 * @brief Obt�m a lista completa de todos os funcion�rios cadastrados.
 *
 * @param funcionarios_out Ponteiro para o array onde os funcion�rios ser�o armazenados.
 * @param max_funcionarios O tamanho m�ximo do array funcionarios_out.
 * @param total_funcionarios_out Ponteiro para armazenar o n�mero total de funcion�rios lidos.
 * @return int 1 se a leitura foi bem-sucedida (mesmo que vazia), 0 em caso de erro.
 */
int obter_todos_funcionarios(funcionario_t* funcionarios_out, size_t max_funcionarios, size_t* total_funcionarios_out) {
	// Delega a chamada para a camada de persist�ncia
	if (listar_funcionarios_csv(funcionarios_out, max_funcionarios, total_funcionarios_out)) {
		return 0; // Sucesso
	} else {
		return 1; // Erro
	}
}

int adicionar_funcionario(funcionario_t* funcionario) {
	if (!funcionario) return 1; // Erro: funcion�rio inv�lido

	// Verifica se o funcion�rio j� existe
	bool existe = buscar_funcionario_csv(funcionario->matricula, funcionario);

	if (existe) {
		return 2; // Erro: funcion�rio j� existe
	}

	// Delega a chamada para a camada de persist�ncia
	if (inserir_funcionario_csv(funcionario)) {
		return 0; // Sucesso
	} else {
		return 1; // Erro
	}
}

int editar_funcionario(funcionario_t* funcionario) {
	if (!funcionario) return 1; // Erro: funcion�rio inv�lido

	// Delega a chamada para a camada de persist�ncia
	if (atualizar_funcionario_csv(funcionario)) {
		return 0; // Sucesso
	} else {
		return 1; // Erro
	}
}

int excluir_funcionario(int matricula) {
	// Delega a chamada para a camada de persist�ncia
	if (excluir_funcionario_csv(matricula)) {
		return 0; // Sucesso
	} else {
		return 1; // Erro
	}
}