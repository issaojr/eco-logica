#include "util.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

static char *get_data_hora_atual(void) {
    // Obter data e hora atual
    time_t t = time(NULL);
    struct tm *tm_info = localtime(&t);

    char data_hora[64];
    strftime(data_hora, sizeof(data_hora), "%d/%m/%Y %H:%M", tm_info);
    
    return data_hora;
}