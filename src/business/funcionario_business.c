#include <stdio.h>
#include <stdlib.h>
#include "persistencia/funcionario_dao.h"
#include "ui/ui_comum.h"
#include "session.h"
#include "business/funcionario_business.h"

/**
 * Solicita e valida a matr�cula de um funcion�rio para edi��o.
 * 
 * @return 1 se uma matr�cula v�lida foi obtida e armazenada na sess�o, 0 caso contr�rio
 */
int solicitar_matricula_edicao(void) {
    int matricula;
    printf("Digite a matr�cula do funcion�rio a editar: ");
    if (scanf("%d", &matricula) != 1) {
        getchar(); // Limpar o buffer
        ui_limpar_tela();
        desenhar_caixa_mensagem("Matr�cula inv�lida!", 2);
        printf("\nPressione ENTER para continuar...");
        getchar();
        return 0;
    }
    getchar(); // Consumir o \n
    
    // Verificar se o funcion�rio existe
    funcionario_t funcionario;
    if (!buscar_funcionario_csv(matricula, &funcionario)) {
        ui_limpar_tela();
        desenhar_caixa_mensagem("Funcion�rio n�o encontrado!", 2);
        printf("\nPressione ENTER para continuar...");
        getchar();
        return 0;
    }
    
    // Armazenar a matr�cula na sess�o para o pr�ximo estado
    session_set_int("matricula_editar", matricula);
    return 1;
}

/**
 * Solicita e valida a matr�cula de um funcion�rio para exclus�o.
 * 
 * @return 1 se uma matr�cula v�lida foi obtida e armazenada na sess�o, 0 caso contr�rio
 */
int solicitar_matricula_exclusao(void) {
    int matricula;
    printf("Digite a matr�cula do funcion�rio a excluir: ");
    if (scanf("%d", &matricula) != 1) {
        getchar(); // Limpar o buffer
        ui_limpar_tela();
        desenhar_caixa_mensagem("Matr�cula inv�lida!", 2);
        printf("\nPressione ENTER para continuar...");
        getchar();
        return 0;
    }
    getchar(); // Consumir o \n
    
    // Verificar se o funcion�rio existe
    funcionario_t funcionario;
    if (!buscar_funcionario_csv(matricula, &funcionario)) {
        ui_limpar_tela();
        desenhar_caixa_mensagem("Funcion�rio n�o encontrado!", 2);
        printf("\nPressione ENTER para continuar...");
        getchar();
        return 0;
    }
    
    // Armazenar a matr�cula na sess�o para o pr�ximo estado
    session_set_int("matricula_excluir", matricula);
    return 1;
}

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
    return listar_funcionarios_csv(funcionarios_out, max_funcionarios, total_funcionarios_out);
}