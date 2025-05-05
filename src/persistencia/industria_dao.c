#include <stdio.h>
#include <stdlib.h>
#include "persistencia/industria_dao.h"

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