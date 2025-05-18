#ifndef ESTADO_H
#define ESTADO_H

#include "estados.h"

/**
 * @brief Interface para estados da aplicação
 *
 * Esta estrutura define as operações que todos os estados devem implementar
 */
typedef struct
{
    /**
     * Inicializa o estado atual
     * @return código de erro (0 = sucesso)
     */
    int (*inicializar)(void);

    /**
     * Processa uma entrada do usuário no estado atual
     * @param entrada índice da opção escolhida pelo usuário
     * @return próximo estado da aplicação
     */
    estado_aplicacao (*processar)(size_t entrada);

    /**
     * Limpa recursos utilizados pelo estado
     */
    void (*finalizar)(void);

    /**
     * Retorna o ID do estado
     */
    estado_aplicacao (*obter_id)(void);
} estado_t;

/**
 * @brief Fábrica de estados
 *
 * Retorna uma implementação do estado correspondente ao ID
 * @param id ID do estado desejado
 * @return Ponteiro para estrutura estado_t ou NULL se o estado não existir
 */
estado_t *criar_estado(estado_aplicacao id);

/**
 * @brief Libera recursos alocados para o estado
 * @param estado Ponteiro para o estado a ser destruído
 */
void destruir_estado(estado_t *estado);

#endif // ESTADO_H