#include "ui/funcionarios/ui_tela_cadastro_funcionarios.h"

void ui_desenhar_tela_cadastro_funcionarios(
    const char *nome_funcionario,
    const char *matricula)
{

    // Desenha tela de menu de cadastro de funcionários
    ui_desenhar_tela_padrao(
        UI_TITULO_PROGRAMA,
        UI_SUBTITULO_CADASTRO_FUNCIONARIOS,
        nome_funcionario,
        matricula);
}

opcao_t ui_menu_cadastro_funcionarios_mapa[] = {
    {1, "Listar Funcionários"},
    {2, "Adicionar Funcionário"},
    {3, "Editar Funcionário"},
    {4, "Excluir Funcionário"},
    {5, "Voltar"}};

size_t ui_menu_cadastro_funcionarios_mapa_n =
    sizeof(ui_menu_cadastro_funcionarios_mapa) / sizeof(ui_menu_cadastro_funcionarios_mapa[0]);

// char *ui_menu_cadastro_funcionarios_prompt = ui_prompt_opcao(1, 5);

const char *ui_menu_cadastro_funcionarios_prompt(void)
{
    return ui_prompt_opcao(1, ui_menu_cadastro_funcionarios_mapa_n);
}

void ui_desenhar_lista_funcionarios(
    funcionario_t *funcionarios_out,
    size_t max_funcionarios,
    size_t *total_funcionarios_out)
{
    ui_limpar_tela();

    const char *cabecalho = "LISTA DE FUNCIONÁRIOS";

    /* Desenha tela de lista de funcionários */
    ui_desenhar_cabecalho(cabecalho);
    printf("\n");

    /* Exibir lista de funcionarios */
    ui_exibir_lista_funcionarios(
        funcionarios_out,
        max_funcionarios,
        total_funcionarios_out);
    printf("\n");

    /* Prompt para retornar ao menu anterior */
    ui_prompt_voltar_menu_anterior(NULL);
}

/**
 * @brief Exibe a lista de funcionários
 * @param funcionarios_out Array de funcionários
 * @param max_funcionarios Tamanho máximo do array
 * @param total_funcionarios_out Ponteiro para o total de funcionários
 * @note A função exibe a lista de funcionários formatada no console.
 */
void ui_exibir_lista_funcionarios(
    funcionario_t *funcionarios_out,
    size_t max_funcionarios,
    size_t *total_funcionarios_out)
{

    printf(UI_COR_NEGRITO "Matrícula   Nome\n" UI_COR_RESET);
    printf("-------------------------------\n");
    for (size_t i = 0; i < *total_funcionarios_out; i++)
    {
        printf("%s      %s\n", funcionarios_out[i].matricula, funcionarios_out[i].nome);
    }
    printf("-------------------------------\n");
}

void ui_desenhar_form_adicionar_funcionario(funcionario_t *novo_funcionario_out)
{
    ui_desenhar_cabecalho("ADICIONAR NOVO FUNCIONÁRIO");
    printf("\n");
    ui_exibir_form_funcionario(novo_funcionario_out);
}

void ui_desenhar_tela_excluir_buscar_funcionario(
    funcionario_t *funcionario_antes_out)
{
    ui_desenhar_cabecalho("INFORME A MATRÍCULA DO FUNCIONÁRIO A SER EXCLUÍDO");
    printf("\n");

    /**
     * Fase 1 - Formulário para buscar funcionário por matrícula
     * Apresentar prompt para número de matrícula
     * Ler matrícula do funcionário
     * */
    ui_ler_matricula_funcionario(
        funcionario_antes_out->matricula,
        sizeof(funcionario_antes_out->matricula));
}

bool ui_desenhar_tela_excluir_confirmar_funcionario(
    funcionario_t *funcionario_selecionado,
    const char *nome_funcionario_autenticado,
    const char *matricula_funcionario_autenticado)
{
    ui_desenhar_tela_cadastro_funcionarios(
        nome_funcionario_autenticado,
        matricula_funcionario_autenticado);

    ui_desenhar_cabecalho("CONFIRMAÇÃO DE EXCLUSÃO DE FUNCIONÁRIO");
    printf("\n");

    /* Exibe o painel do funcionário encontrado */
    ui_desenhar_painel_funcionario_selecionado(
        funcionario_selecionado->nome,
        funcionario_selecionado->matricula);

    printf("\n");
    /* Pergunta se o usuário deseja realmente excluir o funcionário */
    return ui_confirmar("Deseja realmente excluir este funcionário?");
}

void ui_desenhar_tela_editar_buscar_funcionario(
    funcionario_t *funcionario_antes_out)
{
    ui_desenhar_cabecalho("EDIÇÃO: BUSCA DE FUNCIONÁRIO");
    printf("\n");

    /**
     * Fase 1 - Formulário para buscar funcionário por matrícula
     * Apresentar prompt para número de matrícula
     * Ler matrícula do funcionário
     * */
    ui_ler_matricula_funcionario(
        funcionario_antes_out->matricula,
        sizeof(funcionario_antes_out->matricula));
}

void ui_desenhar_form_editar_funcionario(
    const char *nome_funcionario_autenticado,
    const char *matricula_funcionario_autenticado,
    funcionario_t *funcionario_antes_out,
    funcionario_t *funcionario_depois_out)
{

    /* Fase 2 - Formulário para editar funcionário */

    /* Redesenhar tela */
    ui_desenhar_tela_cadastro_funcionarios(
        nome_funcionario_autenticado,
        matricula_funcionario_autenticado);

    /* Desenhar painel funcionario para funcionario selecionado */
    ui_desenhar_painel_funcionario_selecionado(
        funcionario_antes_out->nome,
        funcionario_antes_out->matricula);

    ui_desenhar_cabecalho("EDIÇÃO DE FUNCIONÁRIO");
    printf("\n");

    ui_ler_nome_funcionario(
        funcionario_depois_out->nome,
        sizeof(funcionario_depois_out->nome));

    // Primeiro vamos ler a senha em um buffer temporário
    char senha_temp[100];
    ui_ler_senha_funcionario(
        senha_temp,
        sizeof(senha_temp));

    // Aplica-se o hash na senha antes de armazenar
    hash_senha(senha_temp, funcionario_depois_out->hash_senha, HASH_KEY);
}

void ui_exibir_form_funcionario(funcionario_t *novo_funcionario_out)
{
    ui_ler_matricula_funcionario(
        novo_funcionario_out->matricula,
        sizeof(novo_funcionario_out->matricula));
    ui_ler_nome_funcionario(
        novo_funcionario_out->nome,
        sizeof(novo_funcionario_out->nome));

    char senha_temp[100];
    ui_ler_senha_funcionario(
        senha_temp,
        sizeof(senha_temp));

    // Aplica-se o hash na senha antes de armazenar
    hash_senha(senha_temp, novo_funcionario_out->hash_senha, HASH_KEY);
}
