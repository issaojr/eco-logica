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

void ui_desenhar_painel_ind_resumido(industria_t *i)
{
    const size_t l = UI_LARGURA_QUADRO;
    ui_desenhar_linha_simples();
    ui_desenhar_linha_painel("=>", "Indústria Selecionada (Resíduos / Custos)", "|", "|", l);
    ui_desenhar_linha_simples();
    ui_desenhar_linha_painel("CNPJ:", i->cnpj, "|", "|", l);
    ui_desenhar_linha_painel("Razão Social:", i->razao_social, "|", "|", l);
    ui_desenhar_linha_painel("Nome Fantasia:", i->nome_fantasia, "|", "|", l);
    ui_desenhar_linha_painel("Cidade:", i->cidade, "|", "|", l);
    ui_desenhar_linha_painel("Estado:", i->estado, "|", "|", l);
    ui_desenhar_rodape();
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