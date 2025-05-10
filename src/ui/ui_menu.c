#include "ui/ui_menu.h"
#include "ui/ui_comum.h"

/* Macro para calcular o número de elementos de um array estático */
#define ARRAY_SIZE(a)  (sizeof(a)/sizeof((a)[0]))

int ui_opcoes_min(opcao_t *mapa, size_t n) {
    /* Retorna o menor código de opção do mapa. */
    int min = mapa[0].codigo;

    for (size_t i = 1; i < n; i++) {
        if (mapa[i].codigo < min) {
            min = mapa[i].codigo;
        }
    }
    return min;
}

int ui_opcoes_max(opcao_t *mapa, size_t n) {
    /* Retorna o maior código de opção do mapa. */
    int max = mapa[0].codigo;

    for (size_t i = 1; i < n; i++) {
        if (mapa[i].codigo > max) {
            max = mapa[i].codigo;
        }
    }

    return max;
}

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
            ui_exibir_erro("Entrada inválida: digite um número.");
            continue;
        }
        /* Verifica se o código lido existe no mapa */
        for (size_t i = 0; i < n; i++) {
            if ((long)mapa[i].codigo == val) {
                return mapa[i].codigo;
            }
        }
        ui_exibir_erro("Opção não existe. Tente novamente.");
    }
}
