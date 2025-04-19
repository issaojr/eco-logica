#ifndef AUTH_H
#define AUTH_H

/**
 * @brief Realiza o processo de autenticação do funcionário.
 * Lê a matrícula e a senha do usuário, criptografa a senha digitada
 * utilizando a cifra XOR, e compara com os dados armazenados.
 */
int performLogin(int matricula, const char *senhaInput);

#endif // AUTH_H
