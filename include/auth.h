// EcoLogica/src/business/auth.h
#ifndef AUTH_H
#define AUTH_H

/**
 * @brief Realiza o processo de autenticação do funcionário.
 * Lê a matrícula e a senha do usuário, criptografa a senha digitada
 * utilizando a cifra XOR, e compara com os dados armazenados.
 */
void performLogin(void);

#endif // AUTH_H
