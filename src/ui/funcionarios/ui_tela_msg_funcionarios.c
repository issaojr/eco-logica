#include "ui/funcionarios/ui_tela_msg_funcionarios.h"

void ui_desenhar_tela_msg_adicionar_funcionario_sucesso(void)
{
    ui_desenhar_tela_padrao(
        UI_TITULO_PROGRAMA,
        UI_SUBTITULO_ADICIONAR_FUNCIONARIO_SUCESSO,
        NULL,
        0);

    printf("\n");
    ui_exibir_separador('*', UI_LARGURA_PADRAO);
    ui_exibir_sucesso("Funcionário adicionado com sucesso!");
    printf("\n");
    ui_exibir_separador('*', UI_LARGURA_PADRAO);
    printf("\n");

    printf("\n");
    ui_prompt_voltar_menu_anterior(NULL);

    return;
}

void ui_desenhar_tela_msg_adicionar_funcionario_falha(void)
{
    ui_desenhar_tela_padrao(
        UI_TITULO_PROGRAMA,
        UI_SUBTITULO_ADICIONAR_FUNCIONARIO_FALHA,
        NULL,
        0);

    printf("\n");
    ui_exibir_separador('*', UI_LARGURA_PADRAO);
    ui_exibir_erro("Falha ao adicionar funcionário.");
    printf("\n");
    ui_exibir_separador('*', UI_LARGURA_PADRAO);
    printf("\n");

    ui_prompt_voltar_inicio(NULL);

    return;
}

void ui_desenhar_tela_msg_adicionar_funcionario_ja_existe(void)
{
    ui_desenhar_tela_padrao(
        UI_TITULO_PROGRAMA,
        UI_SUBTITULO_ADICIONAR_FUNCIONARIO_JA_EXISTE,
        NULL,
        0);

    printf("\n");
    ui_exibir_separador('*', UI_LARGURA_PADRAO);
    ui_exibir_erro("Funcionário já cadastrado.");
    printf("\n");
    ui_exibir_separador('*', UI_LARGURA_PADRAO);
    printf("\n");

    ui_prompt_voltar_inicio(NULL);

    return;
}
