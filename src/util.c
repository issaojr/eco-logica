
#include "util.h"

/* Funções para trim de strings - início */
void trim_crlf(char *s)
{
    if (!s)
        return;
    size_t len = strlen(s);
    while (len > 0 && (s[len - 1] == '\n' || s[len - 1] == '\r'))
        s[--len] = '\0';
}

char *trim(char *s)
{
    if (!s)
        return NULL;
    char *inicio = s;
    char *fim;

    /* 1) ltrim: avança até o primeiro não‐espaço */
    while (*inicio && isspace((unsigned char)*inicio))
    {
        inicio++;
    }

    /* 2) se houver deslocamento, move o texto para o início */
    if (inicio != s)
    {
        memmove(s, inicio, strlen(inicio) + 1);
    }

    /* 3) rtrim: remove espaços do fim */
    fim = s + strlen(s) - 1;
    while (fim >= s && isspace((unsigned char)*fim))
    {
        *fim-- = '\0';
    }

    return s;
}

void colapsar_espacos(char *s)
{
    if (!s)
        return;

    char *dst = s;
    char *src = s;
    int antes_era_espaco = 0;

    while (*src)
    {
        if (isspace((unsigned char)*src))
        {
            if (!antes_era_espaco)
            {
                *dst++ = ' ';
                antes_era_espaco = 1;
            }
        }
        else
        {
            *dst++ = *src;
            antes_era_espaco = 0;
        }
        src++;
    }
    *dst = '\0';
}
/* Funções para trim de strings - fim */

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

char *_util_strdup(const char *s)
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
    if (setlocale(LC_ALL, "pt_BR.UTF-8") == NULL)
    {
        setlocale(LC_ALL, "");
    }
#endif
}
