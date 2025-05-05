#include <stdio.h>
#include "persistencia/funcionario_dao.h"
#include "crypto.h"

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