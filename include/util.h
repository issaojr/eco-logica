#ifndef UTIL_H
#define UTIL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>
#include <ctype.h>
#ifdef _WIN32
#include <windows.h>
#include <io.h>
#include <fcntl.h>
#endif

void trim_crlf(char *s);
char *trim(char *s);
void colapsar_espacos(char *s);
char *get_data_hora_atual(void);
char *util_strdup(const char *s);
void set_locale_utf8(void);

#endif // UTIL_H
