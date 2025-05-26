#include "estados/relatorios/estado_relatorios_industria.h"

static industria_t *i;
static residuo_t *r;

static int inicializar(void)
{
    return 0;
}

static estado_aplicacao processar(size_t entrada)
{
    // TODO: Desenhar a tela básica

    // TODO: Form para ler CNPJ da indústria

    // TODO: Validar CNPJ e armazenar em 'i'

    // TODO: Mostrar em painel resumo da indústria

    // TODO: Mostrar menu de opções de relatórios:
    // 1. Listar resíduos por semestralmente
    // 2. Listar totais de gastos mensais

    // TODO: Dependendo da opção escolhida, chamar a função correspondente
    // Caso 1: Listar resíduos semestralmente
    // - Recuperar lista de resíduos da indústria
    // - Exibir relatório com resíduos por semestre
    // Caso 2: Listar totais de gastos mensais
    // - Recuperar lista de resíduos da indústria
    // - Exibir relatório com totais de gastos mensais

    // TODO: Apresentar menu de opções:
    // 1. Exportar relatório para CSV
    // 2. Exportar relatório para XLS
    // 3. Exportar relatório para TXT
    // 4. Voltar para o menu principal


    return ESTADO_MENU_PRINCIPAL;
}

static void finalizar(void)
{
    // TODO: liberar recursos (se houver)
}

static estado_aplicacao obter_id(void)
{
    return ESTADO_RELATORIOS_INDUSTRIA; // adicione ao seu enum em estado.h
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
