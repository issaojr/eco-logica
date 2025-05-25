
#include "util.h"

void trim_crlf(char *s)
{
    size_t len = strlen(s);
    while (len > 0 && (s[len - 1] == '\n' || s[len - 1] == '\r'))
        s[--len] = '\0';
}

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
    // No Windows, configuramos o console para UTF-8
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    // Tentamos configurar o locale, mas não é crítico se falhar
    // pois nossa função transformar_maiusculo não depende do locale
    setlocale(LC_ALL, ".UTF-8");

    // Tentamos outros locales UTF-8 possíveis no Windows
    if (strcmp(setlocale(LC_ALL, NULL), "C") == 0)
    {
        setlocale(LC_ALL, "en_US.UTF-8");
    }

    // Não usamos fallback para CP1252, pois queremos manter UTF-8
#else
    // Em sistemas Unix/Linux
    if (setlocale(LC_ALL, "pt_BR.UTF-8") == NULL) {
        setlocale(LC_ALL, "");
    }
#endif
}
