#include <stdio.h>
#include <string.h> 
#include <stdlib.h>
#include "persistencia/funcionario_dao.h"
#include "business/business_crypto.h"
#include "ui/ui_comum.h"

/**
 * Fun��o auxiliar para extrair dados de funcion�rio de uma linha CSV.
 * @param linha A linha do arquivo CSV
 * @param funcionario Estrutura onde os dados extra�dos ser�o armazenados
 * @return true se extra��o foi bem sucedida, false caso contr�rio
 */
static bool extrair_dados_funcionario_csv(char* linha, funcionario_t* funcionario) {
    if (!linha || !funcionario) return false;
    
    // Fazer uma c�pia da linha para evitar problemas com strtok
    char linha_backup[256];
    strncpy(linha_backup, linha, sizeof(linha_backup) - 1);
    linha_backup[sizeof(linha_backup) - 1] = '\0';
    
    // Extra��o segura dos dados
    char *tok = strtok(linha_backup, ",");
    if (!tok) return false;
    funcionario->matricula = atoi(tok);
    
    tok = strtok(NULL, ",");
    if (!tok) return false;
    // Garantir termina��o nula
    strncpy(funcionario->nome, tok, sizeof(funcionario->nome) - 1);
    funcionario->nome[sizeof(funcionario->nome) - 1] = '\0';
    
    tok = strtok(NULL, ",\n");
    if (!tok) return false;
    // Garantir termina��o nula
    strncpy(funcionario->hash_senha, tok, sizeof(funcionario->hash_senha) - 1);
    funcionario->hash_senha[sizeof(funcionario->hash_senha) - 1] = '\0';
      return true;
}


bool validar_funcionario_csv(int matricula, const char *senha, funcionario_t *out_funcionario) {
    FILE *f = fopen(FUNC_FILE, "r");
    if (!f) return false;
    
    char line[256];
    funcionario_t funcionario_temp;
    bool autenticado = false;
    
    // Pular a primeira linha (cabe�alho)
    fgets(line, sizeof(line), f);
    
    while (fgets(line, sizeof(line), f)) {
        if (!extrair_dados_funcionario_csv(line, &funcionario_temp)) {
            continue;
        }
        
        if (funcionario_temp.matricula != matricula) {
            continue;
        }
        
        // Compute hash of input senha
        char hash[64];
        hash_senha(senha, hash, HASH_KEY);
        
        if (strcmp(hash, funcionario_temp.hash_senha) == 0) {
            // Credenciais v�lidas
            if (out_funcionario) {
                *out_funcionario = funcionario_temp;
            }
            autenticado = true;
            break;
        }
    }
    
    fclose(f);
    return autenticado;
}

bool inserir_funcionario_csv(const funcionario_t *funcionario) {
    // Verificar se o funcion�rio � v�lido
    if (!funcionario) return false;
    
    // Primeiro, verificamos se o arquivo existe e se termina com uma quebra de linha
    FILE *f_read = fopen(FUNC_FILE, "r");
    if (f_read) {
        // Vai para o fim do arquivo
        fseek(f_read, 0, SEEK_END);
        long size = ftell(f_read);
        
        // Se o arquivo n�o est� vazio, verificar o �ltimo caractere
        if (size > 0) {
            // Volta uma posi��o para ler o �ltimo caractere
            fseek(f_read, -1, SEEK_END);
            char last_char = fgetc(f_read);
            fclose(f_read);
            
            // Se o �ltimo caractere n�o for quebra de linha, abrir em modo a+ para adicionar quebra de linha
            if (last_char != '\n') {
                FILE *f_append_nl = fopen(FUNC_FILE, "a");
                if (!f_append_nl) return false;
                fprintf(f_append_nl, "\n");
                fclose(f_append_nl);
            }
        } else {
            fclose(f_read);
        }
    }
    
    // Agora abrimos o arquivo para adicionar o funcion�rio
    FILE *f = fopen(FUNC_FILE, "a");
    if (!f) return false;
    fprintf(f, "%d,%s,%s\n", funcionario->matricula, funcionario->nome, funcionario->hash_senha);
    fclose(f);
    return true;
}

bool buscar_funcionario_csv(int matricula, funcionario_t *out_funcionario) {
    if (!out_funcionario) return false;
    
    FILE *f = fopen(FUNC_FILE, "r");
    if (!f) return false;
    
    char line[256];
    bool encontrado = false;
    funcionario_t funcionario_temp;
    
    // Pular a primeira linha (cabe�alho)
    fgets(line, sizeof(line), f);
    
    while (fgets(line, sizeof(line), f)) {
        if (!extrair_dados_funcionario_csv(line, &funcionario_temp)) {
            continue;
        }
        
        if (funcionario_temp.matricula == matricula) {
            *out_funcionario = funcionario_temp;
            encontrado = true;
            break;
        }
    }
    
    fclose(f);
    return encontrado;
}

/* Fun��o movida para o in�cio do arquivo */

bool listar_funcionarios_csv(funcionario_t *funcionarios, size_t tamanho_max, size_t *qtd_funcionarios) {
    // Verifica��o de par�metros
    if (!funcionarios || !qtd_funcionarios) return false;
    *qtd_funcionarios = 0; // Inicializa com zero para seguran�a

    // Abrir arquivo com verifica��o
    FILE *f = fopen(FUNC_FILE, "r");
    if (!f) {
        return false;
    }
    
    char line[256];
    size_t count = 0;

    // Pular a primeira linha (cabe�alho)
    fgets(line, sizeof(line), f);

    // Processamento de linha por linha
    while (count < tamanho_max && fgets(line, sizeof(line), f)) {
        if (extrair_dados_funcionario_csv(line, &funcionarios[count])) {
            count++;
        }
    }
    
    *qtd_funcionarios = count;
    
    // Fechar o arquivo
    fclose(f);
    
    return true;
}

bool atualizar_funcionario_csv(const funcionario_t *funcionario) {
    if (!funcionario) return false;

    FILE *f_orig = fopen(FUNC_FILE, "r");
    FILE *f_temp = fopen(FUNC_FILE_TEMP, "w");
    
    if (!f_orig || !f_temp) {
        if (f_orig) fclose(f_orig);
        if (f_temp) fclose(f_temp);
        return false;
    }
    
    char line[256];
    bool atualizado = false;
    funcionario_t funcionario_temp;
    
    // Copiar cabe�alho para o arquivo tempor�rio
    if (fgets(line, sizeof(line), f_orig)) {
        fputs(line, f_temp);
    }
    
    // Copiar todos os registros para o arquivo tempor�rio, atualizando o registro desejado
    while (fgets(line, sizeof(line), f_orig)) {
        char linha_copia[256];
        strncpy(linha_copia, line, sizeof(linha_copia) - 1);
        linha_copia[sizeof(linha_copia) - 1] = '\0';
        
        // Usar a fun��o auxiliar para extrair dados
        if (!extrair_dados_funcionario_csv(linha_copia, &funcionario_temp)) {
            fputs(line, f_temp);
            continue;
        }
        
        // Se encontrou o funcion�rio a ser atualizado
        if (funcionario_temp.matricula == funcionario->matricula) {
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
    
    // Se o funcion�rio n�o foi encontrado, adicionar como novo registro
    if (!atualizado) {
        // Renomear arquivos
        remove(FUNC_FILE);
        rename(FUNC_FILE_TEMP, FUNC_FILE);
        
        // Adicionar o funcion�rio como um novo registro
        return inserir_funcionario_csv(funcionario);
    }
    
    // Substituir o arquivo original pelo arquivo tempor�rio
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
    funcionario_t funcionario_temp;
    
    // Copiar cabe�alho para o arquivo tempor�rio
    if (fgets(line, sizeof(line), f_orig)) {
        fputs(line, f_temp);
    }
      // Copiar todos os registros para o arquivo tempor�rio, exceto o registro a ser exclu�do
    while (fgets(line, sizeof(line), f_orig)) {
        char linha_copia[256];
        strncpy(linha_copia, line, sizeof(linha_copia) - 1);
        linha_copia[sizeof(linha_copia) - 1] = '\0';
        
        // Tenta extrair os dados da linha para verificar se � v�lida
        bool linha_valida = extrair_dados_funcionario_csv(linha_copia, &funcionario_temp);
        
        // Se a linha n�o for v�lida, ignora-a (op��o mais segura)
        if (!linha_valida) {
            continue; // Linha inv�lida, n�o copiar para o arquivo tempor�rio
        }
        
        // Se n�o for o funcion�rio a ser exclu�do, mant�m no arquivo
        if (funcionario_temp.matricula != matricula) {
            fputs(line, f_temp);
        } else {
            encontrado = true;
        }
    }
    
    fclose(f_orig);
    fclose(f_temp);
    
    // Se o funcion�rio n�o foi encontrado, n�o faz nada
    if (!encontrado) {
        remove(FUNC_FILE_TEMP);
        return false;
    }
    
    // Substituir o arquivo original pelo arquivo tempor�rio
    remove(FUNC_FILE);
    rename(FUNC_FILE_TEMP, FUNC_FILE);
    
    return true;
}