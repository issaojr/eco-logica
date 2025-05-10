#include "session.h"
#include "util.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// Estrutura para um item da sessão
typedef struct session_item {
    char *chave;
    union {
        int valor_int;
        void *valor_ptr;
    } valor;
    int tipo; // 0 = inteiro, 1 = ponteiro
    struct session_item *proximo;
} session_item_t;

// Variável global para armazenar o usuário logado.
static funcionario_t *funcionario_autenticado = NULL;

// Lista encadeada para armazenar os itens da sessão
static session_item_t *sessao_items = NULL;

// Função interna para procurar um item na sessão
static session_item_t* encontrar_item(const char *chave) {
    session_item_t *atual = sessao_items;
    while (atual) {
        if (strcmp(atual->chave, chave) == 0) {
            return atual;
        }
        atual = atual->proximo;
    }
    return NULL;
}

funcionario_t* get_funcionario_logado(void) {
    return funcionario_autenticado;
}

void set_funcionario_logado(funcionario_t *func) {
    funcionario_autenticado = func;
}

void logout(void) {
    if (get_funcionario_logado() != NULL) {
        free(get_funcionario_logado());
        set_funcionario_logado(NULL);
    }
    
    // Limpar todos os itens da sessão
    session_item_t *atual = sessao_items;
    while (atual) {
        session_item_t *proximo = atual->proximo;
        free(atual->chave);
        free(atual);
        atual = proximo;
    }
    sessao_items = NULL;
}

void session_set_int(const char *chave, int valor) {
    // Procurar se o item já existe
    session_item_t *item = encontrar_item(chave);
    
    if (item) {
        // Atualizar o valor
        item->valor.valor_int = valor;
        item->tipo = 0; // inteiro
    } else {
        // Criar um novo item
        item = malloc(sizeof(session_item_t));
        if (!item) return;
        
        item->chave = util_strdup(chave);
        item->valor.valor_int = valor;
        item->tipo = 0; // inteiro
        item->proximo = sessao_items;
        sessao_items = item;
    }
}

int session_get_int(const char *chave, int padrao) {
    session_item_t *item = encontrar_item(chave);
    if (item && item->tipo == 0) {
        return item->valor.valor_int;
    }
    return padrao;
}

void session_set_ptr(const char *chave, void *ptr) {
    // Procurar se o item já existe
    session_item_t *item = encontrar_item(chave);
    
    if (item) {
        // Atualizar o valor
        item->valor.valor_ptr = ptr;
        item->tipo = 1; // ponteiro
    } else {
        // Criar um novo item
        item = malloc(sizeof(session_item_t));
        if (!item) return;
        
        item->chave = util_strdup(chave);
        item->valor.valor_ptr = ptr;
        item->tipo = 1; // ponteiro
        item->proximo = sessao_items;
        sessao_items = item;
    }
}

void* session_get_ptr(const char *chave) {
    session_item_t *item = encontrar_item(chave);
    if (item && item->tipo == 1) {
        return item->valor.valor_ptr;
    }
    return NULL;
}
