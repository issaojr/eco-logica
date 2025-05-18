#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "util.h"

char *get_data_hora_atual(void)
{
    time_t t = time(NULL);
    struct tm *tm_info = localtime(&t);

    size_t buf_size = 64;
    char *data_hora = malloc(buf_size);
    if (!data_hora)
        return NULL;
    strftime(data_hora, buf_size, "%d/%m/%Y %H:%M", tm_info);
    return data_hora;
}

char *util_strdup(const char *s)
{
    if (!s)
        return NULL;
    size_t len = strlen(s) + 1;
    char *d = malloc(len);
    if (d)
        memcpy(d, s, len);
    return d;
}

void set_locale_utf8(void)
{
#ifdef _WIN32
    system("chcp 65001 > nul");
#else
    setlocale(LC_ALL, "pt_BR.UTF-8");
#endif
}