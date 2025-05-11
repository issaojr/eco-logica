#include "ui/ui_menu.h"
#include "ui/ui_comum.h"

/* Macro para calcular o n�mero de elementos de um array est�tico */
#define ARRAY_SIZE(a)  (sizeof(a)/sizeof((a)[0]))

int ui_opcoes_min(opcao_t *mapa, size_t n) {
    /* Retorna o menor c�digo de op��o do mapa. */
    int min = mapa[0].codigo;

    for (size_t i = 1; i < n; i++) {
        if (mapa[i].codigo < min) {
            min = mapa[i].codigo;
        }
    }
    return min;
}

int ui_opcoes_max(opcao_t *mapa, size_t n) {
    /* Retorna o maior c�digo de op��o do mapa. */
    int max = mapa[0].codigo;

    for (size_t i = 1; i < n; i++) {
        if (mapa[i].codigo > max) {
            max = mapa[i].codigo;
        }
    }

    return max;
}

void ui_imprimir_menu(const opcao_t *mapa, size_t n) {
    for (size_t i = 0; i < n; i++) {
        /* Exibe: " 1) Login" etc. */
        printf("%2d) %s\n", (int)mapa[i].codigo, mapa[i].msg);
    }
}

codigo_opcao ui_ler_opcao(const opcao_t *mapa, size_t n, const char *prompt) {
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
            ui_exibir_erro("Entrada inv�lida: digite um n�mero.");
            continue;
        }
        /* Verifica se o c�digo lido existe no mapa */
        for (size_t i = 0; i < n; i++) {
            if ((long)mapa[i].codigo == val) {
                return mapa[i].codigo;
            }
        }
        ui_exibir_erro("Op��o n�o existe. Tente novamente.");
    }
}
