#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "ui/ui_comum.h"
#include "session.h"
#include "business/business_funcionario.h"


/**
 * Solicita e valida a matrícula de um funcionário para edição.
 *
 * @return 1 se uma matrícula válida foi obtida e armazenada na sessão, 0 caso contrário
 */
int solicitar_matricula_edicao(void) {
	int matricula;
	printf("Digite a matrícula do funcionário a editar: ");
	if (scanf("%d", &matricula) != 1) {
		getchar(); // Limpar o buffer
		ui_limpar_tela();
		desenhar_caixa_mensagem("Matrícula inválida!", 2);
		printf("\nPressione ENTER para continuar...");
		getchar();
		return 0;
	}
	getchar(); // Consumir o \n

	// Verificar se o funcionário existe
	funcionario_t funcionario;
	if (!buscar_funcionario_csv(matricula, &funcionario)) {
		ui_limpar_tela();
		desenhar_caixa_mensagem("Funcionário não encontrado!", 2);
		printf("\nPressione ENTER para continuar...");
		getchar();
		return 0;
	}

	// Armazenar a matrícula na sessão para o próximo estado
	session_set_int("matricula_editar", matricula);
	return 1;
}

/**
 * Solicita e valida a matrícula de um funcionário para exclusão.
 *
 * @return 1 se uma matrícula válida foi obtida e armazenada na sessão, 0 caso contrário
 */
int solicitar_matricula_exclusao(void) {
	int matricula;
	printf("Digite a matrícula do funcionário a excluir: ");
	if (scanf("%d", &matricula) != 1) {
		getchar(); // Limpar o buffer
		ui_limpar_tela();
		desenhar_caixa_mensagem("Matrícula inválida!", 2);
		printf("\nPressione ENTER para continuar...");
		getchar();
		return 0;
	}
	getchar(); // Consumir o \n

	// Verificar se o funcionário existe
	funcionario_t funcionario;
	if (!buscar_funcionario_csv(matricula, &funcionario)) {
		ui_limpar_tela();
		desenhar_caixa_mensagem("Funcionário não encontrado!", 2);
		printf("\nPressione ENTER para continuar...");
		getchar();
		return 0;
	}

	// Armazenar a matrícula na sessão para o próximo estado
	session_set_int("matricula_excluir", matricula);
	return 1;
}

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