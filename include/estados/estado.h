#ifndef ESTADO_H
#define ESTADO_H

#include "estados/estados.h"

/**
 * @brief Interface para estados da aplica��o
 * 
 * Esta estrutura define as opera��es que todos os estados devem implementar
 */
typedef struct {
    /**
     * Inicializa o estado atual
     * @return c�digo de erro (0 = sucesso)
     */
    int (*inicializar)(void);
    
    /**
     * Processa uma entrada do usu�rio no estado atual
     * @param entrada �ndice da op��o escolhida pelo usu�rio
     * @return pr�ximo estado da aplica��o
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
 * @brief F�brica de estados
 * 
 * Retorna uma implementa��o do estado correspondente ao ID
 * @param id ID do estado desejado
 * @return Ponteiro para estrutura estado_t ou NULL se o estado n�o existir
 */
estado_t* criar_estado(estado_aplicacao id);

/**
 * @brief Libera recursos alocados para o estado
 * @param estado Ponteiro para o estado a ser destru�do
 */
void destruir_estado(estado_t* estado);

#endif // ESTADO_H