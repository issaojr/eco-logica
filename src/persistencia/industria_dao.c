#include "persistencia/industria_dao.h"


bool validar_industria_csv(const char *cnpj, industria_t *out_industria) {
    FILE *f = fopen(IND_FILE, "r");
    if (!f) return false;
    char line[512];
    
    // Se o arquivo está vazio ou não existe, não há indústria cadastrada
    if (!fgets(line, sizeof(line), f)) {
        fclose(f);
        return false;
    }
    
    // Verificar se é o cabeçalho, se não for, voltar ao início do arquivo
    if (strstr(line, "CNPJ") == NULL) {
        rewind(f);
    }
    
    while (fgets(line, sizeof(line), f)) {
        // Remover quebras de linha
        size_t len = strlen(line);
        if (len > 0 && (line[len-1] == '\n' || line[len-1] == '\r')) {
            line[--len] = '\0';
        }
        if (len > 0 && (line[len-1] == '\n' || line[len-1] == '\r')) {
            line[--len] = '\0';
        }
        
        char *tok = strtok(line, ",");
        if (!tok) continue;
        if (strcmp(tok, cnpj) != 0) continue;
        
        // CNPJ encontrado, preencher a estrutura
        strncpy(out_industria->cnpj, tok, sizeof(out_industria->cnpj) - 1);
        out_industria->cnpj[sizeof(out_industria->cnpj) - 1] = '\0';
        
        tok = strtok(NULL, ","); 
        if (!tok) break; 
        strncpy(out_industria->razao_social, tok, sizeof(out_industria->razao_social) - 1);
        out_industria->razao_social[sizeof(out_industria->razao_social) - 1] = '\0';
        
        tok = strtok(NULL, ","); 
        if (!tok) break; 
        strncpy(out_industria->nome_fantasia, tok, sizeof(out_industria->nome_fantasia) - 1);
        out_industria->nome_fantasia[sizeof(out_industria->nome_fantasia) - 1] = '\0';
        
        tok = strtok(NULL, ","); 
        if (!tok) break; 
        strncpy(out_industria->telefone, tok, sizeof(out_industria->telefone) - 1);
        out_industria->telefone[sizeof(out_industria->telefone) - 1] = '\0';
        
        tok = strtok(NULL, ","); 
        if (!tok) break; 
        strncpy(out_industria->logradouro, tok, sizeof(out_industria->logradouro) - 1);
        out_industria->logradouro[sizeof(out_industria->logradouro) - 1] = '\0';
        
        tok = strtok(NULL, ","); 
        if (!tok) break; 
        strncpy(out_industria->numero, tok, sizeof(out_industria->numero) - 1);
        out_industria->numero[sizeof(out_industria->numero) - 1] = '\0';
        
        tok = strtok(NULL, ","); 
        if (!tok) break; 
        strncpy(out_industria->bairro, tok, sizeof(out_industria->bairro) - 1);
        out_industria->bairro[sizeof(out_industria->bairro) - 1] = '\0';
        
        tok = strtok(NULL, ","); 
        if (!tok) break; 
        strncpy(out_industria->cidade, tok, sizeof(out_industria->cidade) - 1);
        out_industria->cidade[sizeof(out_industria->cidade) - 1] = '\0';
        
        tok = strtok(NULL, ","); 
        if (!tok) break; 
        strncpy(out_industria->estado, tok, sizeof(out_industria->estado) - 1);
        out_industria->estado[sizeof(out_industria->estado) - 1] = '\0';
        
        tok = strtok(NULL, ","); 
        if (!tok) break; 
        strncpy(out_industria->cep, tok, sizeof(out_industria->cep) - 1);
        out_industria->cep[sizeof(out_industria->cep) - 1] = '\0';
        
        tok = strtok(NULL, ","); 
        if (!tok) break; 
        strncpy(out_industria->data_abertura, tok, sizeof(out_industria->data_abertura) - 1);
        out_industria->data_abertura[sizeof(out_industria->data_abertura) - 1] = '\0';
        
        tok = strtok(NULL, ","); 
        if (!tok) break; 
        strncpy(out_industria->nome_responsavel, tok, sizeof(out_industria->nome_responsavel) - 1);
        out_industria->nome_responsavel[sizeof(out_industria->nome_responsavel) - 1] = '\0';
        
        tok = strtok(NULL, ","); 
        if (!tok) break; 
        strncpy(out_industria->email_responsavel, tok, sizeof(out_industria->email_responsavel) - 1);
        out_industria->email_responsavel[sizeof(out_industria->email_responsavel) - 1] = '\0';
        
        fclose(f);
        return true;
    }
    fclose(f);
    return false;
}

bool inserir_industria_csv(const industria_t *industria) {
    FILE *f;
    bool arquivo_existe = false;
    
    // Verificar se o arquivo já existe
    f = fopen(IND_FILE, "r");
    if (f != NULL) {
        arquivo_existe = true;
        fclose(f);
    }
    
    // Abrir arquivo para escrita
    f = fopen(IND_FILE, "a");
    if (!f) return false;
    
    // Se arquivo não existir, adicionar cabeçalho
    if (!arquivo_existe) {
        fprintf(f, "CNPJ,RAZAO_SOCIAL,NOME_FANTASIA,TELEFONE,LOGRADOURO,NUMERO,BAIRRO,CIDADE,ESTADO,CEP,DATA_ABERTURA,NOME_RESPONSAVEL,EMAIL_RESPONSAVEL\n");
    }
    
    // Escrever dados da indústria
    fprintf(f, "%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s\n", 
            industria->cnpj,
            industria->razao_social,
            industria->nome_fantasia,
            industria->telefone,
            industria->logradouro,
            industria->numero,
            industria->bairro,
            industria->cidade,
            industria->estado,
            industria->cep,
            industria->data_abertura,
            industria->nome_responsavel,
            industria->email_responsavel);
    
    fclose(f);
    return true;
}