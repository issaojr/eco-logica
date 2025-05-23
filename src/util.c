#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>
#include "util.h"

#ifdef _WIN32
  #include <windows.h>
  #include <io.h>
  #include <fcntl.h>
#endif

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
// #ifdef _WIN32
//     SetConsoleCP(CP_UTF8);
//     SetConsoleOutputCP(CP_UTF8);
//     setlocale(LC_CTYPE, ".UTF-8");
// #else
//     setlocale(LC_CTYPE, "pt_BR.UTF-8");
// #endif

// #ifdef _WIN32
//     // Console em UTF-8
//     SetConsoleCP(CP_UTF8);
//     SetConsoleOutputCP(CP_UTF8);
//     // Se quiser imprimir wchars diretamente:
//     //_setmode(_fileno(stdout), _O_U16TEXT);
//     // faz o CRT usar UTF-8 para as funções multibyte
//     setlocale(LC_CTYPE, ".UTF-8");
// #else
//     setlocale(LC_CTYPE, "pt_BR.UTF-8");
// #endif

#ifdef _WIN32
      SetConsoleCP(CP_UTF8);
      SetConsoleOutputCP(CP_UTF8);
    #endif
    setlocale(LC_CTYPE, "pt_BR.UTF-8");
}