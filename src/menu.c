#include "menu.h"

/* Macro para calcular o número de elementos de um array estático */
#define ARRAY_SIZE(a)  (sizeof(a)/sizeof((a)[0]))

void imprimir_menu(const opcao_t *mapa, size_t n) {
    for (size_t i = 0; i < n; i++) {
        /* Exibe: " 1) Login" etc. */
        printf("%2d) %s\n", (int)mapa[i].codigo, mapa[i].msg);
    }
}

codigo_opcao ler_opcao(const opcao_t *mapa, size_t n, const char *prompt) {
    char buf[64];
    long val;
    char *endptr;

    while (1) {
        /* Exibe prompt */
        printf("%s", prompt);
        if (!fgets(buf, sizeof buf, stdin)) {
            /* EOF ou erro de leitura */
            return OPCAO_INVALIDA;
        }
        /* Converte para inteiro */
        val = strtol(buf, &endptr, 10);
        /* Verifica se restou algo não-numérico */
        if (endptr == buf || (*endptr != '\n' && *endptr != '\0')) {
            puts("Entrada inválida: digite um número.");
            continue;
        }
        /* Verifica se o código lido existe no mapa */
        for (size_t i = 0; i < n; i++) {
            if ((long)mapa[i].codigo == val) {
                return mapa[i].codigo;
            }
        }
        puts("Opção não existe. Tente novamente.");
    }
}
