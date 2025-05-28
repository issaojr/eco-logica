#include "ui/residuos/ui_tela_atualizacao_residuos.h"

void ui_desenhar_tela_inicial_residuos(
    funcionario_t *f,
    industria_t *i)
{
    ui_desenhar_tela_padrao(
        UI_TITULO_PROGRAMA,
        UI_SUBTITULO_ATUALIZACAO_RESIDUOS,
        f->nome,
        f->matricula);

    ui_exibir_form_inicial_residuos(i);
}

void ui_desenhar_tela_final_residuos(
    funcionario_t *f,
    industria_t *i,
    residuo_t *r)
{
    ui_desenhar_tela_padrao(
        UI_TITULO_PROGRAMA,
        UI_SUBTITULO_ATUALIZACAO_RESIDUOS,
        f->nome,
        f->matricula);

    ui_desenhar_painel_ind_resumido(i);
    ui_exibir_form_final_residuos(r);
}

void ui_exibir_form_inicial_residuos(industria_t *i)
{
    ui_desenhar_cabecalho("SELECIONE A INDÚSTRIA PARA ATUALIZAÇÃO DE RESÍDUOS");
    printf("\n");
    ui_ler_cnpj_industria(i->cnpj, sizeof(i->cnpj));
}

void ui_exibir_form_final_residuos(residuo_t *r)
{
    ui_desenhar_cabecalho("FORMULÁRIO PARA ATUALIZAÇÃO DE RESÍDUOS");
    printf("\n");
    ui_exibir_form_residuos(r);
}