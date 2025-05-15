#include "estados/estado_menu_utils.h"

/**
 * Fun��o utilit�ria para processar entrada de estados de menu.
 * 
 * @param mapa Array de op��es do menu
 * @param mapa_n Tamanho do array de op��es
 * @param prompt Texto do prompt para o usu�rio
 * @param estado_atual ID do estado atual (para fallback)
 * @return O pr�ximo estado da aplica��o
 */
estado_aplicacao estado_processar_estado_menu(const opcao_t *mapa, size_t mapa_n, 
                                       const char *prompt, estado_aplicacao estado_atual) {
    // Exibe o menu e coleta a entrada do usu�rio
    ui_imprimir_menu(mapa, mapa_n);
    codigo_opcao escolha = ui_ler_opcao(mapa, mapa_n, prompt);

    // Encontra o �ndice da op��o selecionada
    size_t idx = 0;
    for (; idx < mapa_n; idx++) {
        if (mapa[idx].codigo == escolha) break;
    }

    // Se n�o encontrou, permanece no estado atual
    if (idx >= mapa_n) {
        return estado_atual;
    }

    // Retorna o pr�ximo estado com base na op��o selecionada
    return obter_proximo_estado(estado_atual, idx);
}