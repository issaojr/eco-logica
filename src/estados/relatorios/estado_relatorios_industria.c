#include "estados/relatorios/estado_relatorios_industria.h"

static int inicializar(void)
{
    return 0;
}

static estado_aplicacao processar(size_t entrada)
{
    // TODO: Desenhar a tela básica (UI)

    // TODO: Form para ler CNPJ da indústria (UI)

    ui_desenhar_tela_rel_ind_fase_1(NULL, NULL);

    // TODO: Chamar função de (business) para obter a indústria pelo CNPJ
    // - Se a indústria não for encontrada, exibir mensagem de erro,
    // desalocar recursos e voltar ao menu principal
    // - Se a indústria for encontrada, armazenar em uma variável

    // TODO: Mostrar em painel resumo da indústria

    // TODO: Mostrar menu de opções de relatórios (UI):
    // 1. Listar resíduos por semestralmente
    // 2. Listar totais de gastos mensais
    // 3. Voltar para o menu principal

    // TODO: Ler opção escolhida pelo usuário (UI)
    // - caso opção 1 ou 2, chamar a função de (business) correspondente
    // para obter a estrutura de dados adequada e exibir o relatório,
    // enviando a indústria como parâmetro
    // - caso opção 3, desalocar recursos e retornar ao menu principal
    ui_desenhar_tela_rel_ind_fase_2(NULL, NULL, NULL);

    // TODO: Apresentar menu de opções:
    // 1. Exportar relatório para CSV
    // 2. Exportar relatório para XLS
    // 3. Exportar relatório para TXT
    // 4. Voltar para o menu principal

    // TODO: Ler opção escolhida pelo usuário (UI)
    // - caso opção 1, 2 ou 3, chamar a função de (business) correspondente
    // para exportar o relatório
    // - caso opção 4, desalocar recursos e retornar ao menu principal
    ui_desenhar_tela_rel_ind_fase_3(NULL, NULL, NULL, NULL);

    ui_prompt_continuar(NULL);

    return ESTADO_MENU_PRINCIPAL;
}

static void finalizar(void)
{
    // TODO: liberar recursos (se houver)
}

static estado_aplicacao obter_id(void)
{
    return ESTADO_RELATORIOS_INDUSTRIA;
}

estado_t *criar_estado_relatorios_industria(void)
{
    estado_t *e = malloc(sizeof(estado_t));
    if (!e)
        return NULL;
    e->inicializar = inicializar;
    e->processar = processar;
    e->finalizar = finalizar;
    e->obter_id = obter_id;
    return e;
}
