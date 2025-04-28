#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "persistencia.h"
#include "crypto.h"

#define FUNC_FILE "funcionarios.csv"
#define IND_FILE  "industrias.csv"
#define RES_FILE  "residuos.csv"
#define HASH_KEY 0xAA

bool validar_funcionario_csv(int matricula, const char *senha, funcionario_t *out_funcionario) {
    FILE *f = fopen(FUNC_FILE, "r");
    if (!f) return false;
    char line[256];
    while (fgets(line, sizeof(line), f)) {
        int mat;
        char nome[100], storedHash[64];
        char *tok = strtok(line, ","); // matricula
        if (!tok) continue;
        mat = atoi(tok);
        if (mat != matricula) continue;
        tok = strtok(NULL, ","); // nome
        if (!tok) continue;
        strncpy(nome, tok, sizeof(nome));
        tok = strtok(NULL, ",\n"); // storedHash
        if (!tok) continue;
        strncpy(storedHash, tok, sizeof(storedHash));
        
        // compute hash of input senha
        char hash[64];
        hash_senha(senha, hash, HASH_KEY);
        
        if (strcmp(hash, storedHash) == 0) {
            // valid
            out_funcionario->matricula = mat;
            strncpy(out_funcionario->nome, nome, sizeof(out_funcionario->nome));
            strncpy(out_funcionario->hash_senha, storedHash, sizeof(out_funcionario->hash_senha));
            fclose(f);
            return true;
        }
    }
    fclose(f);
    return false;
}

bool inserir_funcionario_csv(const funcionario_t *funcionario) {
    FILE *f = fopen(FUNC_FILE, "a");
    if (!f) return false;
    fprintf(f, "%d,%s,%s\n", funcionario->matricula, funcionario->nome, funcionario->hash_senha);
    fclose(f);
    return true;
}

bool validar_industria_csv(const char *cnpj, industria_t *out_industria) {
    FILE *f = fopen(IND_FILE, "r");
    if (!f) return false;
    char line[512];
    // Ignorar cabeçalho
    fgets(line, sizeof(line), f);
    while (fgets(line, sizeof(line), f)) {
        char *tok = strtok(line, ",");
        if (!tok) continue;
        if (strcmp(tok, cnpj) != 0) continue;
        strncpy(out_industria->cnpj, tok, sizeof(out_industria->cnpj));
        tok = strtok(NULL, ","); if (!tok) break; strncpy(out_industria->razao_social, tok, sizeof(out_industria->razao_social));
        tok = strtok(NULL, ","); if (!tok) break; strncpy(out_industria->nome_fantasia, tok, sizeof(out_industria->nome_fantasia));
        tok = strtok(NULL, ","); if (!tok) break; strncpy(out_industria->telefone, tok, sizeof(out_industria->telefone));
        tok = strtok(NULL, ","); if (!tok) break; strncpy(out_industria->endereco, tok, sizeof(out_industria->endereco));
        tok = strtok(NULL, ","); if (!tok) break; strncpy(out_industria->email, tok, sizeof(out_industria->email));
        tok = strtok(NULL, ",\n"); if (!tok) break; strncpy(out_industria->data_abertura, tok, sizeof(out_industria->data_abertura));
        fclose(f);
        return true;
    }
    fclose(f);
    return false;
}

bool inserir_industria_csv(const industria_t *industria) {
    FILE *f = fopen(IND_FILE, "a");
    if (!f) return false;
    fprintf(f, "%s,%s,%s,%s,%s,%s,%s\n", industria->cnpj,
            industria->razao_social,
            industria->nome_fantasia,
            industria->telefone,
            industria->endereco,
            industria->email,
            industria->data_abertura);
    fclose(f);
    return true;
}

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