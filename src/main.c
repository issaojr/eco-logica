#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>
#include "estados/estados.h"
#include "estados/estado.h"
#include "session.h"
#include "menu.h"

// Estrutura para armazenar informações de entrada para o estado atual
typedef struct {
    size_t indice_opcao;  // Índice da opção selecionada em estados de menu
    void* dados_extras;   // Dados específicos que alguns estados podem precisar
} entrada_estado_t;

int main(void) {
    // Configuração de ambiente
    system("chcp 1252 > nul");  // Força o console a usar code page 1252
    setlocale(LC_ALL, "Portuguese_Brazil.1252");

    // Estado inicial da aplicação
    estado_aplicacao id_estado_atual = ESTADO_MENU_LOGIN;
    estado_aplicacao id_proximo_estado;
    estado_t *estado_atual = NULL;
    entrada_estado_t entrada = {0, NULL};
    
    // Loop principal do programa usando a fábrica de estados
    while (id_estado_atual != ESTADO_SAIR) {
        // Cria o estado atual usando a fábrica
        estado_atual = criar_estado(id_estado_atual);
        if (!estado_atual) {
            fprintf(stderr, "Erro ao criar estado %d\n", id_estado_atual);
            return 1;
        }
        
        // Inicializa o estado
        if (estado_atual->inicializar) {
            if (estado_atual->inicializar() != 0) {
                fprintf(stderr, "Erro ao inicializar estado %d\n", id_estado_atual);
                destruir_estado(estado_atual);
                return 1;
            }
        }
        
        // Processa o estado e obtém o próximo estado
        entrada.indice_opcao = 0; // Reset para cada novo estado
        id_proximo_estado = estado_atual->processar(entrada.indice_opcao);
        
        // Limpa o estado atual
        if (estado_atual->finalizar) {
            estado_atual->finalizar();
        }
        
        // Libera a memória do estado atual
        destruir_estado(estado_atual);
        
        // Atualiza para o próximo estado
        id_estado_atual = id_proximo_estado;
    }

    // Garante que a sessão do usuário seja encerrada corretamente
    logout();
    
    puts("Saindo do sistema...");
    return 0;
}
