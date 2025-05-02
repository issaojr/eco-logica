#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "persistencia.h"
#include "crypto.h"

#define FUNC_FILE "funcionarios.csv"
#define FUNC_FILE_TEMP "funcionarios_temp.csv"
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

bool buscar_funcionario_csv(int matricula, funcionario_t *out_funcionario) {
    FILE *f = fopen(FUNC_FILE, "r");
    if (!f) return false;
    
    char line[256];
    bool encontrado = false;
    
    while (fgets(line, sizeof(line), f)) {
        int mat;
        char nome[100], hash_senha[64];
        
        // Extrai a matrícula
        char *tok = strtok(line, ",");
        if (!tok) continue;
        mat = atoi(tok);
        
        // Se encontrou a matrícula procurada
        if (mat == matricula) {
            // Extrai o nome
            tok = strtok(NULL, ",");
            if (!tok) continue;
            strncpy(nome, tok, sizeof(nome));
            
            // Extrai o hash da senha
            tok = strtok(NULL, ",\n");
            if (!tok) continue;
            strncpy(hash_senha, tok, sizeof(hash_senha));
            
            // Preenche a estrutura de saída
            out_funcionario->matricula = mat;
            strncpy(out_funcionario->nome, nome, sizeof(out_funcionario->nome));
            strncpy(out_funcionario->hash_senha, hash_senha, sizeof(out_funcionario->hash_senha));
            
            encontrado = true;
            break;
        }
    }
    
    fclose(f);
    return encontrado;
}

bool listar_funcionarios_csv(funcionario_t *funcionarios, size_t tamanho_max, size_t *qtd_funcionarios) {
    FILE *f = fopen(FUNC_FILE, "r");
    if (!f) return false;
    
    char line[256];
    size_t count = 0;
    
    while (count < tamanho_max && fgets(line, sizeof(line), f)) {
        char *tok = strtok(line, ",");
        if (!tok) continue;
        funcionarios[count].matricula = atoi(tok);
        
        tok = strtok(NULL, ",");
        if (!tok) continue;
        strncpy(funcionarios[count].nome, tok, sizeof(funcionarios[count].nome));
        
        tok = strtok(NULL, ",\n");
        if (!tok) continue;
        strncpy(funcionarios[count].hash_senha, tok, sizeof(funcionarios[count].hash_senha));
        
        count++;
    }
    
    *qtd_funcionarios = count;
    fclose(f);
    return true;
}

bool atualizar_funcionario_csv(const funcionario_t *funcionario) {
    FILE *f_orig = fopen(FUNC_FILE, "r");
    FILE *f_temp = fopen(FUNC_FILE_TEMP, "w");
    
    if (!f_orig || !f_temp) {
        if (f_orig) fclose(f_orig);
        if (f_temp) fclose(f_temp);
        return false;
    }
    
    char line[256];
    bool atualizado = false;
    
    // Copiar todos os registros para o arquivo temporário, atualizando o registro desejado
    while (fgets(line, sizeof(line), f_orig)) {
        char linha_copia[256];
        strncpy(linha_copia, line, sizeof(linha_copia)); // Cópia da linha para extração
        
        char *tok = strtok(linha_copia, ",");
        if (!tok) continue;
        int mat = atoi(tok);
        
        // Se encontrou o funcionário a ser atualizado
        if (mat == funcionario->matricula) {
            // Escrever registro atualizado
            fprintf(f_temp, "%d,%s,%s\n", 
                funcionario->matricula, 
                funcionario->nome, 
                funcionario->hash_senha);
            atualizado = true;
        } else {
            // Manter o registro original
            fputs(line, f_temp);
        }
    }
    
    fclose(f_orig);
    fclose(f_temp);
    
    // Se o funcionário não foi encontrado, adicionar como novo registro
    if (!atualizado) {
        // Renomear arquivos
        remove(FUNC_FILE);
        rename(FUNC_FILE_TEMP, FUNC_FILE);
        
        // Adicionar o funcionário como um novo registro
        return inserir_funcionario_csv(funcionario);
    }
    
    // Substituir o arquivo original pelo arquivo temporário
    remove(FUNC_FILE);
    rename(FUNC_FILE_TEMP, FUNC_FILE);
    
    return true;
}

bool excluir_funcionario_csv(int matricula) {
    FILE *f_orig = fopen(FUNC_FILE, "r");
    FILE *f_temp = fopen(FUNC_FILE_TEMP, "w");
    
    if (!f_orig || !f_temp) {
        if (f_orig) fclose(f_orig);
        if (f_temp) fclose(f_temp);
        return false;
    }
    
    char line[256];
    bool encontrado = false;
    
    // Copiar todos os registros para o arquivo temporário, exceto o registro a ser excluído
    while (fgets(line, sizeof(line), f_orig)) {
        char linha_copia[256];
        strncpy(linha_copia, line, sizeof(linha_copia)); // Cópia da linha para extração
        
        char *tok = strtok(linha_copia, ",");
        if (!tok) continue;
        int mat = atoi(tok);
        
        // Se não for o funcionário a ser excluído, mantém no arquivo
        if (mat != matricula) {
            fputs(line, f_temp);
        } else {
            encontrado = true;
        }
    }
    
    fclose(f_orig);
    fclose(f_temp);
    
    // Se o funcionário não foi encontrado, não faz nada
    if (!encontrado) {
        remove(FUNC_FILE_TEMP);
        return false;
    }
    
    // Substituir o arquivo original pelo arquivo temporário
    remove(FUNC_FILE);
    rename(FUNC_FILE_TEMP, FUNC_FILE);
    
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