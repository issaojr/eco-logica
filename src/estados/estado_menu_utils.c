#include "estados/estado_menu_utils.h"

/**
 * Função utilitária para processar entrada de estados de menu.
 * 
 * @param mapa Array de opções do menu
 * @param mapa_n Tamanho do array de opções
 * @param prompt Texto do prompt para o usuário
 * @param estado_atual ID do estado atual (para fallback)
 * @return O próximo estado da aplicação
 */
estado_aplicacao estado_processar_estado_menu(const opcao_t *mapa, size_t mapa_n, 
                                       const char *prompt, estado_aplicacao estado_atual) {
    // Exibe o menu e coleta a entrada do usuário
    ui_imprimir_menu(mapa, mapa_n);
    codigo_opcao escolha = ui_ler_opcao(mapa, mapa_n, prompt);

    // Encontra o índice da opção selecionada
    size_t idx = 0;
    for (; idx < mapa_n; idx++) {
        if (mapa[idx].codigo == escolha) break;
    }

    // Se não encontrou, permanece no estado atual
    if (idx >= mapa_n) {
        return estado_atual;
    }

    // Retorna o próximo estado com base na opção selecionada
    return obter_proximo_estado(estado_atual, idx);
}