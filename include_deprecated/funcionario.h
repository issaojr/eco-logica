#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H



typedef struct {
    int matricula;      // Número de identificação único
    char senha[50];     // Senha do funcionário (armazenada em texto claro, mas que será criptografada para validação)
    char nome[100];     // Nome completo do funcionário
} Funcionario;

#endif // FUNCIONARIO_H
