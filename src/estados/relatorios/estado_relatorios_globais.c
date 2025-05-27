#include "estados/relatorios/estado_relatorios_globais.h"

static int inicializar(void)
{
    return 0;
}

static estado_aplicacao processar(size_t entrada)
{
    // TODO: Desenhar a tela básica (UI)

    // TODO: Desenhar menu com opções: (UI)
    // 1. Regiões com maior geração de resíduos
    // 2. Indústrias com melhor desempenho ambiental
    // 3. Aporte financeiro semestral
    // 4. Voltar para o menu principal

    // TODO: Ler opção escolhida pelo usuário (UI)
    // - caso opção 1, 2 ou 3, chamar a função de (business) correspondente
    // para obter a estrutura de dados adequada e exibir o relatório
    // - caso opção 4, desalocar recursos e retornar ao menu principal
    ui_desenhar_tela_rel_glb_fase_1(NULL, NULL);

    // TODO: Uma vez que os dados forem obtidos, chamar a função de (UI)
    // para redesenhar tela e exibir o relatório correspondente
    ui_desenhar_tela_rel_glb_fase_2(NULL, NULL, NULL);

    // TODO: Apresentar menu de opções: (UI)
    // 1. Exportar relatório para CSV
    // 2. Exportar relatório para XLS
    // 3. Exportar relatório para TXT
    // 4. Voltar para o menu principal

    // TODO: Ler opção escolhida pelo usuário (UI)
    // - caso opção 1, 2 ou 3, chamar a função de (business) correspondente 
    // para exportar o relatório
    // - caso opção 4, desalocar recursos e retornar ao menu principal
    ui_desenhar_tela_rel_glb_fase_3(NULL, NULL, NULL, NULL);

    ui_prompt_continuar(NULL);

    return ESTADO_MENU_PRINCIPAL;
}

static void finalizar(void)
{
    // TODO: liberar recursos (se houver)
}

static estado_aplicacao obter_id(void)
{
    return ESTADO_RELATORIOS_GLOBAIS;
}

estado_t *criar_estado_relatorios_globais(void)
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
