#include <string.h>
#include <stdlib.h>
#include "periodo_ui.h"
#include "erros.h"

// Lê do stdin uma string “mm/aaaa”, valida e preenche tm (dia=1)
int ler_mes_ano(const char *prompt, struct tm *out) {
    
    char buf[16];
    printf("%s", prompt);
    if (!fgets(buf, sizeof(buf), stdin)) return -1;
    // remove \n
    buf[strcspn(buf, "\n")] = '\0';

    int mm, aa;
    if (sscanf(buf, "%2d/%4d", &mm, &aa) != 2) {        
        return ERR_DATA_INVALIDA;
    }
    if (mm < 1 || mm > 12 || aa < 1900) {
        return ERR_DATA_INVALIDA_INTERVALO;
    }
    // preenche tm com 1º dia do mês
    memset(out, 0, sizeof *out);
    out->tm_year = aa - 1900;
    out->tm_mon  = mm - 1;
    out->tm_mday = 1;
    // mktime normaliza e retorna -1 se inválido
    if (mktime(out) == (time_t)-1) {
        return ERR_DATA_INVALIDA;
    }
    return 0;
}
