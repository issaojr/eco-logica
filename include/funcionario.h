#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

typedef struct {
    int matricula;      // N�mero de identifica��o �nico
    char senha[50];     // Senha do funcion�rio (armazenada em texto claro, mas que ser� criptografada para valida��o)
    char nome[100];     // Nome completo do funcion�rio
} Funcionario;

#endif // FUNCIONARIO_H
