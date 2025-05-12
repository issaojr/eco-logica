#include "ui/funcionarios/ui_tela_cadastro_funcionarios.h"
#include "ui/ui_menu.h"
#include "ui/ui_comum.h"
#include "ui/funcionarios/ui_form_funcionario.h"
#include "business/business_crypto.h"
#include "persistencia/funcionario_dao.h"

void ui_desenhar_tela_cadastro_funcionarios(
    const char *nome_funcionario, 
    const int matricula) {

    // Desenha tela de menu de cadastro de funcion�rios
    ui_desenhar_tela_padrao(
        UI_TITULO_PROGRAMA, 
        UI_SUBTITULO_CADASTRO_FUNCIONARIOS, 
        nome_funcionario, 
        matricula 
    );
}

opcao_t ui_menu_cadastro_funcionarios_mapa[] = {
    { 1, "Listar Funcion�rios" },
    { 2, "Adicionar Funcion�rio" },
    { 3, "Editar Funcion�rio" },
    { 4, "Excluir Funcion�rio" },
    { 5, "Voltar" }
};

size_t ui_menu_cadastro_funcionarios_mapa_n =
    sizeof(ui_menu_cadastro_funcionarios_mapa) / sizeof(ui_menu_cadastro_funcionarios_mapa[0]);

char *ui_menu_cadastro_funcionarios_prompt = PROMPT_OPCOES(1, 5);

void ui_desenhar_lista_funcionarios(
    funcionario_t* funcionarios_out, 
    size_t max_funcionarios, 
    size_t* total_funcionarios_out
) {
    ui_limpar_tela();
    
    const char *cabecalho = "LISTA DE FUNCION�RIOS";
    
    /* Desenha tela de lista de funcion�rios */
    ui_desenhar_cabecalho(cabecalho);
    printf("\n");

    /* Exibir lista de funcionarios */
    ui_exibir_lista_funcionarios(
        funcionarios_out, 
        max_funcionarios, 
        total_funcionarios_out
    );
    printf("\n");

    /* Prompt para retornar ao menu anterior */
    ui_prompt_voltar_menu_anterior(NULL);

}

/**
 * @brief Exibe a lista de funcion�rios
 * @param funcionarios_out Array de funcion�rios
 * @param max_funcionarios Tamanho m�ximo do array
 * @param total_funcionarios_out Ponteiro para o total de funcion�rios
 * @note A fun��o exibe a lista de funcion�rios formatada no console.
 */
void ui_exibir_lista_funcionarios(
    funcionario_t* funcionarios_out, 
    size_t max_funcionarios, 
    size_t* total_funcionarios_out) {    

    printf(UI_COR_NEGRITO "Matr�cula   Nome\n" UI_COR_RESET);
    printf("-------------------------------\n");
    for (size_t i = 0; i < *total_funcionarios_out; i++) {
        printf("%-10d  %s\n", funcionarios_out[i].matricula, funcionarios_out[i].nome);
    }
    printf("-------------------------------\n");
}

void ui_desenhar_form_adicionar_funcionario(funcionario_t *novo_funcionario_out) {
    ui_desenhar_cabecalho("ADICIONAR NOVO FUNCION�RIO");
    printf("\n");
    ui_exibir_form_funcionario(novo_funcionario_out);
    
    //printf("\n");
    //ui_prompt_voltar_menu_principal(NULL);
}

void ui_desenhar_tela_editar_buscar_funcionario(
    funcionario_t *funcionario_antes_out
) {
    ui_desenhar_cabecalho("EDI��O: BUSCA DE FUNCION�RIO");
    
    /**
     * Fase 1 - Formulario para buscar funcionario por matr�cula
     * Apresentar prompt para n�mero de matr�cula
     * Ler matr�cula do funcion�rio 
     * */
    ui_ler_matricula_cadastro_funcionario(
        &funcionario_antes_out->matricula
    );
}

void ui_desenhar_form_editar_funcionario(
    const char *nome_funcionario_autenticado, 
    const int matricula_funcionario_autenticado,
    funcionario_t *funcionario_antes_out,
    funcionario_t *funcionario_depois_out
) {

    /* Fase 2 - Formul�rio para editar funcion�rio */

    /* Redesenhar tela */
    ui_desenhar_tela_cadastro_funcionarios(
        nome_funcionario_autenticado, 
        matricula_funcionario_autenticado
    );

    /* Desenhar painel funcionario para funcionario selecionado */
    ui_desenhar_painel_funcionario_selecionado(
        funcionario_antes_out->nome, 
        funcionario_antes_out->matricula
    );

    ui_desenhar_cabecalho("EDI��O DE FUNCION�RIO");

    ui_ler_nome_cadastro_funcionario(
        funcionario_depois_out->nome, 
        sizeof(funcionario_depois_out->nome)
    );
    
    // Primeiro vamos ler a senha em um buffer tempor�rio
    char senha_temp[100];
    ui_ler_senha_segura_cadastro_funcionario(
        senha_temp, 
        sizeof(senha_temp)
    );

    // Aplica-se o hash na senha antes de armazenar
    hash_senha(senha_temp, funcionario_depois_out->hash_senha, HASH_KEY);

}

void ui_desenhar_form_excluir_funcionario(void) {
    ui_desenhar_cabecalho("EXCLUS�O DE FUNCION�RIO");
    printf("\n");
    ui_exibir_form_excluir_funcionario();
    printf("\n");
    ui_prompt_voltar_menu_principal(NULL);
}

void ui_exibir_form_editar_funcionario(void) {
    ui_exibir_to_do("Exibir formul�rio de EDI��O de funcion�rio aqui.");
}

void ui_exibir_form_funcionario(funcionario_t *novo_funcionario_out) {
    ui_ler_matricula_cadastro_funcionario(
        &novo_funcionario_out->matricula
    );
    ui_ler_nome_cadastro_funcionario(
        novo_funcionario_out->nome, 
        sizeof(novo_funcionario_out->nome)
    );
    
    // Primeiro vamos ler a senha em um buffer tempor�rio
    char senha_temp[100];
    ui_ler_senha_segura_cadastro_funcionario(
        senha_temp, 
        sizeof(senha_temp)
    );
    
    // Aplica-se o hash na senha antes de armazenar
    hash_senha(senha_temp, novo_funcionario_out->hash_senha, HASH_KEY);
}

void ui_exibir_form_excluir_funcionario(void) {
    ui_exibir_to_do("Exibir formul�rio de EXCLUS�O de funcion�rio aqui.");
}