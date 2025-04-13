// EcoLogica/src/business/auth.c
#include <stdio.h>
#include <string.h>
#include "crypto.h"
#include "auth.h"

#define CRYPTO_KEY 0x5A  // Chave exemplo para a cifra XOR

void performLogin(void) {
    char senha[100];

    printf("Digite a senha: ");
    scanf("%99s", senha);
    while(getchar() != '\n'); // Limpa o buffer

    // Criptografa a senha
    xorCipher(senha, CRYPTO_KEY);

    // Mostrar senha para fins de teste
    printf("Senha criptografada: %s\n", senha);
    
    // Descriptografar e mostrar a senha para fins de teste
    xorCipher(senha, CRYPTO_KEY);
    printf("Senha descriptografada: %s\n", senha);
}

