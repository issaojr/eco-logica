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
    relatorio_t *r)
{

    const char *cabecalho = "LISTA DE FUNCIONÁRIOS";

    /* Desenha tela de lista de funcionários */
    ui_desenhar_cabecalho(cabecalho);
    printf("\n");

    /* Exibir lista de funcionarios */
    ui_exibir_relatorio(r);
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

void ui_desenhar_tela_adicionar_funcionario(funcionario_t *novo_funcionario_out)
{
    ui_desenhar_cabecalho("ADICIONAR NOVO FUNCIONÁRIO");
    printf("\n");
}

void ui_desenhar_form_buscar_funcionario(funcionario_t *novo_funcionario_out)
{
    ui_ler_matricula_funcionario(
        novo_funcionario_out->matricula,
        sizeof(novo_funcionario_out->matricula));
}

void ui_desenhar_form_adicionar_funcionario(funcionario_t *novo_funcionario_out)
{
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
    ui_desenhar_painel_funcionario_selecionado(funcionario_selecionado);

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

void ui_desenhar_painel_funcionario_selecionado(funcionario_t *f)
{
    size_t l = UI_LARGURA_QUADRO;
    ui_desenhar_linha_simples();
    ui_desenhar_linha_painel("=>", "Funcionário Selecionado", "|", "|", l);
    ui_desenhar_linha_simples();
    ui_desenhar_linha_painel("Matrícula:", f->matricula, "|", "|", l);
    ui_desenhar_linha_painel("Nome:", f->nome, "|", "|", l);
    ui_desenhar_linha_painel("Hash de Senha:", f->hash_senha, "|", "|", l);
    ui_desenhar_linha_simples();
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
    ui_desenhar_painel_funcionario_selecionado(funcionario_antes_out);

    ui_desenhar_cabecalho("EDIÇÃO DE FUNCIONÁRIO");
    printf("\n");

    ui_exibir_form_funcionario(funcionario_depois_out);
}
