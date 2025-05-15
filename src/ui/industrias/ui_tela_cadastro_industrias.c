#include "ui/industrias/ui_tela_cadastro_industrias.h"

void ui_desenhar_tela_cadastro_industrias(
    const funcionario_t* funcionario_autenticado
) {
    // Desenha tela de menu de cadastro de ind�strias
    ui_desenhar_tela_padrao(
        UI_TITULO_PROGRAMA, 
        UI_SUBTITULO_CADASTRO_INDUSTRIAS, 
        funcionario_autenticado->nome, 
        funcionario_autenticado->matricula 
    );
}


/* Cada c�digo aqui corresponde � posi��o l�gica, mas o �ndice usado pela m�quina
   de estados ser� a ordem em tela (1..5). */
const opcao_t tela_menu_cadastro_industrias_mapa[] = {
    { 1, "Listar Ind�strias" },
    { 2, "Adicionar Ind�stria" },
    { 3, "Editar Ind�stria" },
    { 4, "Excluir Ind�stria" },
    { 5, "Voltar" }
};

const size_t tela_menu_cadastro_industrias_mapa_n =
    sizeof(tela_menu_cadastro_industrias_mapa) / sizeof(tela_menu_cadastro_industrias_mapa[0]);

const char *tela_menu_cadastro_industrias_prompt = PROMPT_OPCOES(1, 5);

void ui_desenhar_lista_industrias(
    industria_t* industrias_out, 
    size_t max_industrias, 
    size_t* total_industrias_out
) {
    ui_limpar_tela();
    
    const char *cabecalho = "LISTA DE IND�STRIAS";
    
    /* Desenha tela de lista de ind�strias */
    ui_desenhar_cabecalho(cabecalho);
    printf("\n");

    /* Exibir lista de industrias */
    ui_exibir_lista_industrias(
        industrias_out, 
        max_industrias, 
        total_industrias_out
    );
    printf("\n");

    /* Prompt para retornar ao menu anterior */
    ui_prompt_voltar_menu_anterior(NULL);
}

void ui_exibir_form_adicionar_industria(void) {
    ui_limpar_tela();
    ui_exibir_titulo("Adicionar Nova Ind�stria", NULL);
    ui_exibir_to_do("Exibir formul�rio de adi��o de ind�stria aqui.");
    ui_prompt_voltar_menu_principal(NULL);
}

void ui_exibir_form_editar_industria(void) {
    ui_limpar_tela();
    ui_exibir_titulo("Editar Ind�stria", NULL);
    ui_exibir_to_do("Exibir formul�rio de edi��o de ind�stria aqui.");
    ui_prompt_voltar_menu_principal(NULL);
}

void ui_exibir_form_excluir_industria(void) {
    ui_limpar_tela();
    ui_exibir_titulo("Excluir Ind�stria", NULL);
    ui_exibir_to_do("Exibir formul�rio de exclus�o de ind�stria aqui.");
    ui_prompt_voltar_menu_principal(NULL);
}

void ui_exibir_lista_industrias(
    industria_t *industrias_out, 
    size_t max_industrias,
    size_t *total_industrias_out
) {
    printf(UI_COR_NEGRITO "CNPJ   Raz�o Social   Nome Fantasia   Telefone  Logradouro   N�mero   Bairro   Cidade   Estado   CEP   Data Abertura   Nome Respons�vel  Email Respons�vel\n" UI_COR_RESET);
    printf("-------------------------------\n");
    for (size_t i = 0; i < *total_industrias_out; i++) {
        printf("%s  %s  %s  %s  %s  %s  %s  %s  %s  %s  %s  %s  %s\n", 
            industrias_out[i].cnpj, 
            industrias_out[i].razao_social, 
            industrias_out[i].nome_fantasia, 
            industrias_out[i].telefone, 
            industrias_out[i].logradouro, 
            industrias_out[i].numero, 
            industrias_out[i].bairro, 
            industrias_out[i].cidade, 
            industrias_out[i].estado, 
            industrias_out[i].cep, 
            industrias_out[i].data_abertura, 
            industrias_out[i].nome_responsavel,
            industrias_out[i].email_responsavel);
    }
    printf("-------------------------------\n");
}

void ui_desenhar_form_ler_cnpj_industria(industria_t *nova_industria_out) {
    ui_ler_cnpj_industria(nova_industria_out->cnpj, sizeof(nova_industria_out->cnpj));
}

void ui_desenhar_form_adicionar_industria(industria_t *nova_industria_out) {
    ui_desenhar_cabecalho("ADICIONAR IND�STRIA");
    printf("\n");

    
    ui_exibir_form_industria(nova_industria_out);
}