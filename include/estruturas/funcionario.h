#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

/**
 * Representa um funcionário autenticável.
 */
typedef struct
{
    char matricula[8]; /* 6 + '\n' + '\0' */
    char nome[100];
    char hash_senha[64];
} funcionario_t;

#endif /* FUNCIONARIO_H */
