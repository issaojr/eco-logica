#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

/**
 * Representa um funcionário autenticável.
 */
typedef struct {
    int matricula;
    char nome[100];
    char hash_senha[64];
} funcionario_t;

#endif /* FUNCIONARIO_H */