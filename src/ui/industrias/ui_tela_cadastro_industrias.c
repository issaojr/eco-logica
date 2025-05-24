#include "ui/industrias/ui_tela_cadastro_industrias.h"

const size_t TAMANHO_SEPARADOR_TAB_INDUSTRIA = 188;

void ui_desenhar_tela_cadastro_industrias(
    const funcionario_t *funcionario_autenticado)
{
    ui_desenhar_tela_padrao(
        UI_TITULO_PROGRAMA,
        UI_SUBTITULO_CADASTRO_INDUSTRIAS,
        funcionario_autenticado->nome,
        funcionario_autenticado->matricula);
}

const opcao_t tela_menu_cadastro_industrias_mapa[] = {
    {1, "Listar Indústrias"},
    {2, "Adicionar Indústria"},
    {3, "Editar Indústria"},
    {4, "Excluir Indústria"},
    {5, "Voltar"}
};

const size_t tela_menu_cadastro_industrias_mapa_n =
    sizeof(tela_menu_cadastro_industrias_mapa) / sizeof(tela_menu_cadastro_industrias_mapa[0]);

const char *tela_menu_cadastro_industrias_prompt()
{
    return ui_prompt_opcao(1, tela_menu_cadastro_industrias_mapa_n);
}

void ui_desenhar_lista_industrias(
    industria_t *industrias_out,
    size_t max_industrias,
    size_t *total_industrias_out)
{
    ui_limpar_tela();

    const char *cabecalho = "LISTA DE INDÚSTRIAS";

    /* Desenha tela de lista de indústrias */
    ui_desenhar_cabecalho(cabecalho);
    printf("\n");

    /* Exibir lista de industrias */
    ui_exibir_lista_industrias(
        industrias_out,
        max_industrias,
        total_industrias_out);
    printf("\n");

    /* Prompt para retornar ao menu anterior */
    ui_prompt_voltar_menu_anterior(NULL);
}

void ui_exibir_form_adicionar_industria(void)
{
    ui_limpar_tela();
    ui_exibir_titulo("Adicionar Nova Indústria", NULL);
    ui_exibir_to_do("Exibir formulário de adição de indústria aqui.");
    ui_prompt_voltar_menu_principal(NULL);
}

void ui_exibir_form_editar_industria(void)
{
    ui_limpar_tela();
    ui_exibir_titulo("Editar Indústria", NULL);
    ui_exibir_to_do("Exibir formulário de edição de indústria aqui.");
    ui_prompt_voltar_menu_principal(NULL);
}

void ui_exibir_form_excluir_industria(void)
{
    ui_limpar_tela();
    ui_exibir_titulo("Excluir Indústria", NULL);
    ui_exibir_to_do("Exibir formulário de exclusão de indústria aqui.");
    ui_prompt_voltar_menu_principal(NULL);
}

void ui_exibir_lista_industrias(
    industria_t *industrias_out,
    size_t max_industrias,
    size_t *total_industrias_out)
{
    /* Definindo larguras para cada coluna da tabela */
    /* printf(UI_COR_NEGRITO "%-15s %-25s %-25s %-15s %-25s %-8s %-20s %-20s %-8s %-10s %-15s %-25s %-30s\n" UI_COR_RESET,
           "CNPJ", "Razão Social", "Nome Fantasia", "Telefone", "Logradouro", "Número", 
           "Bairro", "Cidade", "Estado", "CEP", "Data Abertura", "Nome Responsável", "Email Responsável");*/

    printf("%-15s %-31s %-30s %-30s %-8s %-15s %-31s %-20s\n",
           "CNPJ", "Razão Social", "Nome Fantasia",
           "Cidade", "Estado", "Data Abertura", "Nome Responsável", "Email Responsável");

    /* Linha separadora com comprimento adequado */
    ui_exibir_separador('-', TAMANHO_SEPARADOR_TAB_INDUSTRIA);

    /* Exibição dos dados com formatação alinhada */
    for (size_t i = 0; i < *total_industrias_out; i++)
    {
        printf("%-15s %-30s %-30s %-30s %-8s %-15s %-30s %-20s\n",
               industrias_out[i].cnpj,
               industrias_out[i].razao_social,
               industrias_out[i].nome_fantasia,
               //industrias_out[i].telefone,
               //industrias_out[i].logradouro,
               //industrias_out[i].numero,
               //industrias_out[i].bairro,
               industrias_out[i].cidade,
               industrias_out[i].estado,
               //industrias_out[i].cep,
               industrias_out[i].data_abertura,
               industrias_out[i].nome_responsavel,
               industrias_out[i].email_responsavel);
    }

    /* Linha separadora de fechamento */
    ui_exibir_separador('-', TAMANHO_SEPARADOR_TAB_INDUSTRIA);
}

void ui_desenhar_form_ler_cnpj_industria(industria_t *nova_industria_out)
{
    ui_ler_cnpj_industria(nova_industria_out->cnpj, sizeof(nova_industria_out->cnpj));
}

void ui_desenhar_form_adicionar_industria(industria_t *nova_industria_out)
{
    ui_desenhar_cabecalho("ADICIONAR INDÚSTRIA");
    printf("\n");

    ui_exibir_form_industria(nova_industria_out);
}
