#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>
#include "estados/estados.h"
#include "estados/estado.h"
#include "session.h"
#include "menu.h"

// Estrutura para armazenar informa��es de entrada para o estado atual
typedef struct {
    size_t indice_opcao;  // �ndice da op��o selecionada em estados de menu
    void* dados_extras;   // Dados espec�ficos que alguns estados podem precisar
} entrada_estado_t;

int main(void) {
    // Configura��o de ambiente
    system("chcp 1252 > nul");  // For�a o console a usar code page 1252
    setlocale(LC_ALL, "Portuguese_Brazil.1252");

    // Estado inicial da aplica��o
    estado_aplicacao id_estado_atual = ESTADO_MENU_LOGIN;
    estado_aplicacao id_proximo_estado;
    estado_t *estado_atual = NULL;
    entrada_estado_t entrada = {0, NULL};
    
    // Loop principal do programa usando a f�brica de estados
    while (id_estado_atual != ESTADO_SAIR) {
        // Cria o estado atual usando a f�brica
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
        
        // Processa o estado e obt�m o pr�ximo estado
        entrada.indice_opcao = 0; // Reset para cada novo estado
        id_proximo_estado = estado_atual->processar(entrada.indice_opcao);
        
        // Limpa o estado atual
        if (estado_atual->finalizar) {
            estado_atual->finalizar();
        }
        
        // Libera a mem�ria do estado atual
        destruir_estado(estado_atual);
        
        // Atualiza para o pr�ximo estado
        id_estado_atual = id_proximo_estado;
    }

    // Garante que a sess�o do usu�rio seja encerrada corretamente
    logout();
    
    puts("Saindo do sistema...");
    return 0;
}
