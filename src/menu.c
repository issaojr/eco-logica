#include "menu.h"

/* Macro para calcular o n�mero de elementos de um array est�tico */
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
        /* Verifica se restou algo n�o-num�rico */
        if (endptr == buf || (*endptr != '\n' && *endptr != '\0')) {
            puts("Entrada inv�lida: digite um n�mero.");
            continue;
        }
        /* Verifica se o c�digo lido existe no mapa */
        for (size_t i = 0; i < n; i++) {
            if ((long)mapa[i].codigo == val) {
                return mapa[i].codigo;
            }
        }
        puts("Op��o n�o existe. Tente novamente.");
    }
}
