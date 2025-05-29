#include "persistencia/residuo_dao.h"

// static bool extrair_dados_residuo_csv(char *linha, residuo_t *residuo)
// {
//     if (!linha || !residuo)
//         return false;

//     /* Fazer uma cópia da linha para evitar problemas com strtok */
//     char linha_backup[TAMANHO_LINHA_RES];
//     strncpy(linha_backup, linha, sizeof(linha_backup) - 1);
//     linha_backup[sizeof(linha_backup) - 1] = '\0';

//     /* Extração segura dos dados */
//     char *tok = strtok(linha_backup, ",");
//     if (!tok)
//         return false;
//     trim_crlf(tok); /* tira CR/LF e copia para o struct */
//     strncpy(residuo->cnpj, tok, sizeof(residuo->cnpj) - 1);
//     residuo->cnpj[sizeof(residuo->cnpj) - 1] = '\0';

//     tok = strtok(NULL, ",");
//     if (!tok)
//         return false;
//     trim_crlf(tok);
//     residuo->mes = atoi(tok);

//     tok = strtok(NULL, ",");
//     if (!tok)
//         return false;
//     trim_crlf(tok);
//     residuo->ano = atoi(tok);

//     tok = strtok(NULL, ",");
//     if (!tok)
//         return false;
//     trim_crlf(tok);
//     char *endptr;
//     residuo->quantidade = strtod(tok, &endptr);
//     if (endptr == tok) return false; // Conversão falhou    tok = strtok(NULL, ",\n\r");
//     if (!tok)
//         return false;
//     trim_crlf(tok);
//     residuo->custo = strtod(tok, &endptr);
//     if (endptr == tok) return false; // Conversão falhou
    
//     return true;
// }

static bool extrair_dados_residuo_csv(char *linha, residuo_t *residuo)
{
    if (!linha || !residuo)
        return false;

    // Fazer uma cópia da linha para evitar problemas com strtok
    char linha_backup[TAMANHO_LINHA_RES];
    strncpy(linha_backup, linha, sizeof(linha_backup) - 1);
    linha_backup[sizeof(linha_backup) - 1] = '\0';

    char *tok = strtok(linha_backup, ",");
    if (!tok)
        return false;
    trim_crlf(tok);
    strncpy(residuo->cnpj, tok, sizeof(residuo->cnpj) - 1);
    residuo->cnpj[sizeof(residuo->cnpj) - 1] = '\0';

    tok = strtok(NULL, ",");
    if (!tok)
        return false;
    trim_crlf(tok);
    residuo->mes = atoi(tok);

    tok = strtok(NULL, ",");
    if (!tok)
        return false;
    trim_crlf(tok);
    residuo->ano = atoi(tok);

    tok = strtok(NULL, ",");
    if (!tok)
        return false;
    trim_crlf(tok);
    char *endptr;
    residuo->quantidade = strtod(tok, &endptr);
    if (endptr == tok)
        return false; // Conversão falhou

    tok = strtok(NULL, ",");  // ✅ CORREÇÃO AQUI
    if (!tok)
        return false;
    trim_crlf(tok);
    residuo->custo = strtod(tok, &endptr);
    if (endptr == tok)
        return false; // Conversão falhou

    return true;
}

bool inserir_residuo_csv(const residuo_t *residuo)
{
    if (!residuo)
        return false;

    // Primeiro, verificamos se o arquivo existe e se termina com uma quebra de linha
    FILE *f_read = fopen(RES_FILE, "r");
    if (f_read)
    {
        // Vai até o final do arquivo
        fseek(f_read, 0, SEEK_END);
        long size = ftell(f_read);

        // Se o arquivo não estiver vazio, verifica se termina com uma quebra de linha
        if (size > 0)
        {
            // Volta uma posição para ler o último caractere
            fseek(f_read, -1, SEEK_END);
            int last_char = fgetc(f_read);
            fclose(f_read);

            // Se o último caractere não for quebra de linha, abrir em modo a+ para adicionar quebra de linha
            if (last_char != '\n')
            {
                FILE *f_append_nl = fopen(RES_FILE, "a");
                if (!f_append_nl)
                    return false;
                // Adicionar quebra de linha
                fputc('\n', f_append_nl);
                fclose(f_append_nl);
            }
        }
        else
        {
            fclose(f_read);
        }
    }

    FILE *f = fopen(RES_FILE, "a");
    if (!f)
        return false;

    // Se arquivo estava vazio ou não existia, escreve o cabeçalho
    if (!f_read)
    {
        // Escrever cabeçalho e verificar se foi escrito corretamente
        if (fprintf(f, "CNPJ,MES,ANO,QUANTIDADE,CUSTO\n") < 0)
        {
            // Erro ao escrever cabeçalho
            fclose(f);
            return false;
        }
    }

    // Escrever dados do resíduo e verificar se foi escrito corretamente
    if (fprintf(f, "%s,%d,%d,%.2f,%.2f\n",
                residuo->cnpj,
                residuo->mes,
                residuo->ano,
                residuo->quantidade,
                residuo->custo) < 0)
    {
        // Erro ao escrever dados
        fclose(f);
        return false;
    }    fclose(f);
    return true;
}

bool buscar_residuo_csv(const char *cnpj, int mes, int ano, residuo_t *out_residuo)
{
    if (!cnpj || !out_residuo)
        return false;

    FILE *f = fopen(RES_FILE, "r");
    if (!f)
        return false;

    char line[TAMANHO_LINHA_RES];
    bool encontrado = false;
    residuo_t residuo_temp;

    // Pular cabeçalho
    fgets(line, sizeof(line), f);

    while (fgets(line, sizeof(line), f))
    {
        if (extrair_dados_residuo_csv(line, &residuo_temp))
        {
            if (strcmp(residuo_temp.cnpj, cnpj) == 0 && 
                residuo_temp.mes == mes && 
                residuo_temp.ano == ano)
            {
                *out_residuo = residuo_temp;
                encontrado = true;
                break;
            }
        }
    }

    fclose(f);
    return encontrado;
}

bool listar_residuos_por_cnpj_csv(const char *cnpj, residuo_t *residuos, size_t tamanho_max, size_t *qtd_residuos)
{
    if (!cnpj || !residuos || !qtd_residuos)
        return false;
    *qtd_residuos = 0;

    FILE *f = fopen(RES_FILE, "r");
    if (!f)
        return false;

    char line[TAMANHO_LINHA_RES];
    size_t count = 0;
    residuo_t residuo_temp;

    // Pular cabeçalho
    fgets(line, sizeof(line), f);

    while (count < tamanho_max && fgets(line, sizeof(line), f))
    {
        if (extrair_dados_residuo_csv(line, &residuo_temp))
        {
            if (strcmp(residuo_temp.cnpj, cnpj) == 0)
            {
                residuos[count] = residuo_temp;
                count++;
            }
        }
    }

    *qtd_residuos = count;
    fclose(f);
    return true;
}

bool atualizar_residuo_csv(const residuo_t *residuo)
{
    if (!residuo)
    {
        return false;
    }

    residuo_t *registros = NULL;
    size_t capacidade = 0, contador = 0;
    bool encontrado = false;

    // Lê todos os registros do arquivo
    FILE *arquivo = fopen(RES_FILE, "r");
    if (arquivo)
    {
        char linha[256];
        // Ignora o cabeçalho
        if (fgets(linha, sizeof(linha), arquivo))
        {            while (fgets(linha, sizeof(linha), arquivo))
            {
                residuo_t temp;
                char *token = strtok(linha, ",");
                if (!token) continue;
                
                // Limpa e copia o CNPJ
                strncpy(temp.cnpj, token, sizeof(temp.cnpj) - 1);
                temp.cnpj[sizeof(temp.cnpj) - 1] = '\0';
                
                // Remove possíveis espaços em branco do CNPJ
                char *src = temp.cnpj;
                char *dst = temp.cnpj;
                while (*src)
                {
                    if (*src != ' ' && *src != '\t' && *src != '\n' && *src != '\r')
                    {
                        *dst++ = *src;
                    }
                    src++;
                }
                *dst = '\0';
                
                token = strtok(NULL, ",");
                if (!token) continue;
                temp.mes = atoi(token);
                
                token = strtok(NULL, ",");
                if (!token) continue;
                temp.ano = atoi(token);
                
                token = strtok(NULL, ",");
                if (!token) continue;
                char *endptr;
                temp.quantidade = strtod(token, &endptr);
                if (endptr == token) continue; // Conversão falhou
                
                token = strtok(NULL, ",\n\r");
                if (!token) continue;
                temp.custo = strtod(token, &endptr);
                if (endptr == token) continue; // Conversão falhou
                
                // Verifica se é o registro que deve ser atualizado
                if (strcmp(temp.cnpj, residuo->cnpj) == 0 && 
                    temp.mes == residuo->mes && 
                    temp.ano == residuo->ano)
                {
                    temp.quantidade = residuo->quantidade;
                    temp.custo = residuo->custo;
                    encontrado = true;
                }
                
                // Expande o array se necessário
                if (contador >= capacidade)
                {
                    capacidade = capacidade ? capacidade * 2 : 8;
                    void *novo_ptr = realloc(registros, capacidade * sizeof(residuo_t));
                    if (!novo_ptr)
                    {
                        free(registros);
                        fclose(arquivo);
                        return false;
                    }
                    registros = novo_ptr;
                }
                
                registros[contador++] = temp;
            }
        }
        fclose(arquivo);
    }
    
    // Se não encontrou o registro, adiciona um novo
    if (!encontrado)
    {
        if (contador >= capacidade)
        {
            capacidade = capacidade ? capacidade * 2 : 8;
            void *novo_ptr = realloc(registros, capacidade * sizeof(residuo_t));
            if (!novo_ptr)
            {
                free(registros);
                return false;
            }
            registros = novo_ptr;
        }
        registros[contador++] = *residuo;
    }
    
    // Reescreve o arquivo com todos os registros
    arquivo = fopen(RES_FILE, "w");
    if (!arquivo)
    {
        free(registros);
        return false;
    }
    
    // Escreve o cabeçalho
    if (fprintf(arquivo, "CNPJ,MES,ANO,QUANTIDADE,CUSTO\n") < 0)
    {
        fclose(arquivo);
        free(registros);
        return false;
    }    // Escreve todos os registros
    for (size_t i = 0; i < contador; i++)
    {
        if (fprintf(arquivo, "%s,%d,%d,%.2f,%.2f\n",
                    registros[i].cnpj, registros[i].mes, registros[i].ano,
                    registros[i].quantidade, registros[i].custo) < 0)
        {
            fclose(arquivo);
            free(registros);
            return false;
        }
    }
    
    fclose(arquivo);
    free(registros);
    return true;
}

bool verificar_csv_residuo(void)
{
    /* Verificações de integridade do arquivo:
       - Verificar se o arquivo existe
       - Verificar se há cabeçalho
       - Verificar se o arquivo termina com quebra de linha
       - Verificar formato das linhas
       Se encontrar problemas, tenta corrigir */

    FILE *f_orig = fopen(RES_FILE, "r");

    // Se o arquivo não existir, cria um novo com cabeçalho
    if (!f_orig)
    {
        FILE *f_new = fopen(RES_FILE, "w");
        if (!f_new)
        {
            return false; // Não conseguiu criar o arquivo
        }

        // Escrever cabeçalho
        if (fprintf(f_new, "CNPJ,MES,ANO,QUANTIDADE,CUSTO\n") < 0)
        {
            fclose(f_new);
            return false;
        }

        fclose(f_new);
        return true;
    }

    // Verificar se há cabeçalho
    char line[256];
    bool tem_cabecalho = false;

    if (fgets(line, sizeof(line), f_orig))
    {
        if (strstr(line, "CNPJ,MES,ANO") != NULL)
        {
            tem_cabecalho = true;
        }
    }

    // Ler todo o arquivo para um buffer e fazer correções necessárias
    fseek(f_orig, 0, SEEK_END);
    long file_size = ftell(f_orig);
    rewind(f_orig);

    // Se o arquivo for muito grande, não tenta carregar tudo na memória
    if (file_size > 1024 * 1024 * 10)
    {
        // 10MB
        fclose(f_orig);
        return false;
    }

    char *buffer = (char*)malloc(file_size + 1);
    if (!buffer)
    {
        fclose(f_orig);
        return false;
    }

    size_t bytes_read = fread(buffer, 1, file_size, f_orig);
    fclose(f_orig);

    buffer[bytes_read] = '\0';

    // Se não tiver cabeçalho, prepara para adicionar
    bool arquivo_modificado = false;
    char *novo_conteudo = NULL;

    if (!tem_cabecalho && bytes_read > 0)
    {
        const char *cabecalho = "CNPJ,MES,ANO,QUANTIDADE,CUSTO\n";
        size_t novo_tamanho = strlen(cabecalho) + bytes_read + 1;

        novo_conteudo = (char*)malloc(novo_tamanho);
        if (!novo_conteudo)
        {
            free(buffer);
            return false;
        }

        strcpy(novo_conteudo, cabecalho);
        strcat(novo_conteudo, buffer);
        arquivo_modificado = true;
    }

    // Verificar se o arquivo termina com quebra de linha
    if (bytes_read > 0 && buffer[bytes_read - 1] != '\n')
    {
        if (novo_conteudo)
        {
            // Temos um buffer novo com cabeçalho, adicionar quebra de linha
            size_t len = strlen(novo_conteudo);
            novo_conteudo[len] = '\n';
            novo_conteudo[len + 1] = '\0';
        }
        else
        {
            // Criar um novo buffer apenas para adicionar quebra de linha
            novo_conteudo = (char*)malloc(bytes_read + 2);
            if (!novo_conteudo)
            {
                free(buffer);
                return false;
            }

            memcpy(novo_conteudo, buffer, bytes_read);
            novo_conteudo[bytes_read] = '\n';
            novo_conteudo[bytes_read + 1] = '\0';
        }
        arquivo_modificado = true;
    }

    // Se o arquivo foi modificado, reescrever
    if (arquivo_modificado)
    {
        FILE *f_write = fopen(RES_FILE, "w");
        if (!f_write)
        {
            free(buffer);
            if (novo_conteudo)
                free(novo_conteudo);
            return false;
        }

        const char *conteudo_final = novo_conteudo ? novo_conteudo : buffer;
        size_t tamanho_final = strlen(conteudo_final);

        if (fwrite(conteudo_final, 1, tamanho_final, f_write) != tamanho_final)
        {
            fclose(f_write);
            free(buffer);
            if (novo_conteudo)
                free(novo_conteudo);
            return false;
        }

        fclose(f_write);
    }

    free(buffer);
    if (novo_conteudo)
        free(novo_conteudo);

    return true;
}

bool buscar_residuos_por_cnpj(const char *cnpj, residuo_t **registros, size_t *total)
{
    if (!cnpj || !registros || !total)
        return false;

    *registros = NULL;
    *total = 0;

    FILE *arquivo = fopen(RES_FILE, "r");
    if (!arquivo)
        return false;

    char linha[TAMANHO_LINHA_RES];
    size_t capacidade = 0;
    size_t contador = 0;

    // Pula o cabeçalho
    if (!fgets(linha, sizeof(linha), arquivo))
    {
        fclose(arquivo);
        return false;
    }

    // Lê todos os registros do arquivo
    while (fgets(linha, sizeof(linha), arquivo))
    {
        residuo_t temp;
        if (extrair_dados_residuo_csv(linha, &temp))
        {
            // Verifica se o CNPJ corresponde ao procurado
            if (strcmp(temp.cnpj, cnpj) == 0)
            {
                // Expande o array se necessário
                if (contador >= capacidade)
                {
                    capacidade = capacidade ? capacidade * 2 : 8;
                    void *novo_ptr = realloc(*registros, capacidade * sizeof(residuo_t));
                    if (!novo_ptr)
                    {
                        free(*registros);
                        *registros = NULL;
                        fclose(arquivo);
                        return false;
                    }
                    *registros = novo_ptr;
                }

                (*registros)[contador++] = temp;
            }
        }
    }

    fclose(arquivo);
    *total = contador;
    return true;
}

void liberar_registros_residuos(residuo_t *registros)
{
    if (registros)
    {
        free(registros);
    }
}
