#include <stdio.h>
#include <stdlib.h>
#include "persistencia/residuo_dao.h"

bool gravar_residuo_csv(const residuo_t *residuo) {
    // lê todos os registros existentes
    residuo_t *arr = NULL; size_t cap = 0, cnt = 0;
    FILE *f = fopen(RES_FILE, "r");
    if (f) {
        char line[256];
        // Ignorar cabeçalho
        fgets(line, sizeof(line), f);
        while (fgets(line, sizeof(line), f)) {
            residuo_t temp;
            char *tok = strtok(line, ",");
            if (!tok) {
                continue;
            }
            strncpy(temp.cnpj, tok, sizeof(temp.cnpj));
            tok = strtok(NULL, ",");
            if (!tok) {
                continue;
            }
            temp.mes = atoi(tok);
            tok = strtok(NULL, ",");
            if (!tok) {
                continue;
            }
            temp.ano = atoi(tok);
            tok = strtok(NULL, ",");
            if (!tok) {
                continue;
            }
            temp.quantidade = atof(tok);
            tok = strtok(NULL, ",\n");
            if (!tok) {
                continue;
            }
            temp.custo = atof(tok);
            // atualizar se corresponder
            if (strcmp(temp.cnpj, residuo->cnpj)==0 && temp.mes==residuo->mes && temp.ano==residuo->ano) {
                temp.quantidade = residuo->quantidade;
                temp.custo = residuo->custo;
            }
            // empacotar
            if (cnt >= cap) { cap = cap ? cap*2 : 8; arr = realloc(arr, cap * sizeof(residuo_t)); }
            arr[cnt++] = temp;
        }
        fclose(f);
    }
    // se não encontrou, adiciona novo
    bool found = false;
    for (size_t i = 0; i < cnt; ++i) {
        if (strcmp(arr[i].cnpj, residuo->cnpj)==0 && arr[i].mes==residuo->mes && arr[i].ano==residuo->ano) { found = true; break; }
    }
    if (!found) {
        if (cnt >= cap) { cap = cap ? cap*2 : 8; arr = realloc(arr, cap * sizeof(residuo_t)); }
        arr[cnt++] = *residuo;
    }
    // reescreve arquivo
    f = fopen(RES_FILE, "w");
    if (!f) { free(arr); return false; }
    // Escrever cabeçalho
    fprintf(f, "cnpj,mes,ano,quantidade,custo\n");
    for (size_t i = 0; i < cnt; ++i) {
        fprintf(f, "%s,%d,%d,%.2f,%.2f\n",
            arr[i].cnpj, arr[i].mes, arr[i].ano,
            arr[i].quantidade, arr[i].custo);
    }
    fclose(f);
    free(arr);
    return true;
}