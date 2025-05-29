#include "persistencia/industria_dao.h"

static bool extrair_dados_industria_csv(char *linha, industria_t *industria)
{
    if (!linha || !industria)
        return false;

    /* Fazer uma cópia da linha para evitar problemas com strtok */
    char linha_backup[TAMANHO_LINHA_IND];
    strncpy(linha_backup, linha, sizeof(linha_backup) - 1);
    linha_backup[sizeof(linha_backup) - 1] = '\0';

    /* Extração segura dos dados */
    char *tok = strtok(linha_backup, ",");
    if (!tok)
        return false;
    trim_crlf(tok); /* tira CR/LF e copia para o struct */
    strncpy(industria->cnpj, tok, sizeof(industria->cnpj) - 1);
    industria->cnpj[sizeof(industria->cnpj) - 1] = '\0';

    tok = strtok(NULL, ",");
    if (!tok)
        return false;
    trim_crlf(tok);

    strncpy(industria->razao_social, tok, sizeof(industria->razao_social) - 1);
    industria->razao_social[sizeof(industria->razao_social) - 1] = '\0';

    tok = strtok(NULL, ",");
    if (!tok)
        return false;
    trim_crlf(tok);
    strncpy(industria->nome_fantasia, tok, sizeof(industria->nome_fantasia) - 1);
    industria->nome_fantasia[sizeof(industria->nome_fantasia) - 1] = '\0';

    tok = strtok(NULL, ",");
    if (!tok)
        return false;
    trim_crlf(tok);
    strncpy(industria->telefone, tok, sizeof(industria->telefone) - 1);
    industria->telefone[sizeof(industria->telefone) - 1] = '\0';

    tok = strtok(NULL, ",");
    if (!tok)
        return false;
    trim_crlf(tok);
    strncpy(industria->logradouro, tok, sizeof(industria->logradouro) - 1);
    industria->logradouro[sizeof(industria->logradouro) - 1] = '\0';

    tok = strtok(NULL, ",");
    if (!tok)
        return false;
    trim_crlf(tok);
    strncpy(industria->numero, tok, sizeof(industria->numero) - 1);
    industria->numero[sizeof(industria->numero) - 1] = '\0';

    tok = strtok(NULL, ",");
    if (!tok)
        return false;
    trim_crlf(tok);
    strncpy(industria->bairro, tok, sizeof(industria->bairro) - 1);
    industria->bairro[sizeof(industria->bairro) - 1] = '\0';

    tok = strtok(NULL, ",");
    if (!tok)
        return false;
    trim_crlf(tok);

    strncpy(industria->cidade, tok, sizeof(industria->cidade) - 1);
    industria->cidade[sizeof(industria->cidade) - 1] = '\0';
    tok = strtok(NULL, ",");
    if (!tok)
        return false;
    trim_crlf(tok);

    strncpy(industria->estado, tok, sizeof(industria->estado) - 1);
    industria->estado[sizeof(industria->estado) - 1] = '\0';
    tok = strtok(NULL, ",");

    if (!tok)
        return false;
    trim_crlf(tok);

    strncpy(industria->cep, tok, sizeof(industria->cep) - 1);
    industria->cep[sizeof(industria->cep) - 1] = '\0';
    tok = strtok(NULL, ",");

    if (!tok)
        return false;
    trim_crlf(tok);

    strncpy(industria->data_abertura, tok, sizeof(industria->data_abertura) - 1);
    industria->data_abertura[sizeof(industria->data_abertura) - 1] = '\0';
    tok = strtok(NULL, ",");

    if (!tok)
        return false;
    trim_crlf(tok);

    strncpy(industria->nome_responsavel, tok, sizeof(industria->nome_responsavel) - 1);
    industria->nome_responsavel[sizeof(industria->nome_responsavel) - 1] = '\0';
    tok = strtok(NULL, ",");
    if (!tok)
        return false;
    trim_crlf(tok);
    strncpy(industria->email_responsavel, tok, sizeof(industria->email_responsavel) - 1);
    industria->email_responsavel[sizeof(industria->email_responsavel) - 1] = '\0';
    return true;
}

bool validar_industria_csv(const char *cnpj, industria_t *out_industria)
{
    FILE *f = fopen(IND_FILE, "r");
    if (!f)
        return false;
    char line[TAMANHO_LINHA_IND];

    if (!fgets(line, sizeof(line), f))
    {
        fclose(f);
        return false;
    }

    if (strstr(line, "CNPJ") == NULL)
    {
        rewind(f);
    }

    while (fgets(line, sizeof(line), f))
    {
        size_t len = strlen(line);
        if (len > 0 && (line[len - 1] == '\n' || line[len - 1] == '\r'))
        {
            line[--len] = '\0';
        }
        if (len > 0 && (line[len - 1] == '\n' || line[len - 1] == '\r'))
        {
            line[--len] = '\0';
        }

        char *tok = strtok(line, ",");
        if (!tok)
            continue;
        if (strcmp(tok, cnpj) != 0)
            continue;

        strncpy(out_industria->cnpj, tok, sizeof(out_industria->cnpj) - 1);
        out_industria->cnpj[sizeof(out_industria->cnpj) - 1] = '\0';

        tok = strtok(NULL, ",");
        if (!tok)
            break;
        strncpy(out_industria->razao_social, tok, sizeof(out_industria->razao_social) - 1);
        out_industria->razao_social[sizeof(out_industria->razao_social) - 1] = '\0';

        tok = strtok(NULL, ",");
        if (!tok)
            break;
        strncpy(out_industria->nome_fantasia, tok, sizeof(out_industria->nome_fantasia) - 1);
        out_industria->nome_fantasia[sizeof(out_industria->nome_fantasia) - 1] = '\0';

        tok = strtok(NULL, ",");
        if (!tok)
            break;
        strncpy(out_industria->telefone, tok, sizeof(out_industria->telefone) - 1);
        out_industria->telefone[sizeof(out_industria->telefone) - 1] = '\0';

        tok = strtok(NULL, ",");
        if (!tok)
            break;
        strncpy(out_industria->logradouro, tok, sizeof(out_industria->logradouro) - 1);
        out_industria->logradouro[sizeof(out_industria->logradouro) - 1] = '\0';

        tok = strtok(NULL, ",");
        if (!tok)
            break;
        strncpy(out_industria->numero, tok, sizeof(out_industria->numero) - 1);
        out_industria->numero[sizeof(out_industria->numero) - 1] = '\0';

        tok = strtok(NULL, ",");
        if (!tok)
            break;
        strncpy(out_industria->bairro, tok, sizeof(out_industria->bairro) - 1);
        out_industria->bairro[sizeof(out_industria->bairro) - 1] = '\0';

        tok = strtok(NULL, ",");
        if (!tok)
            break;
        strncpy(out_industria->cidade, tok, sizeof(out_industria->cidade) - 1);
        out_industria->cidade[sizeof(out_industria->cidade) - 1] = '\0';

        tok = strtok(NULL, ",");
        if (!tok)
            break;
        strncpy(out_industria->estado, tok, sizeof(out_industria->estado) - 1);
        out_industria->estado[sizeof(out_industria->estado) - 1] = '\0';

        tok = strtok(NULL, ",");
        if (!tok)
            break;
        strncpy(out_industria->cep, tok, sizeof(out_industria->cep) - 1);
        out_industria->cep[sizeof(out_industria->cep) - 1] = '\0';

        tok = strtok(NULL, ",");
        if (!tok)
            break;
        strncpy(out_industria->data_abertura, tok, sizeof(out_industria->data_abertura) - 1);
        out_industria->data_abertura[sizeof(out_industria->data_abertura) - 1] = '\0';

        tok = strtok(NULL, ",");
        if (!tok)
            break;
        strncpy(out_industria->nome_responsavel, tok, sizeof(out_industria->nome_responsavel) - 1);
        out_industria->nome_responsavel[sizeof(out_industria->nome_responsavel) - 1] = '\0';

        tok = strtok(NULL, ",");
        if (!tok)
            break;
        strncpy(out_industria->email_responsavel, tok, sizeof(out_industria->email_responsavel) - 1);
        out_industria->email_responsavel[sizeof(out_industria->email_responsavel) - 1] = '\0';

        fclose(f);
        return true;
    }
    fclose(f);
    return false;
}

bool inserir_industria_csv(const industria_t *industria)
{
    if (!industria)
        return false;

    
    FILE *f_read = fopen(IND_FILE, "r");
    if (f_read)
    {
        
        fseek(f_read, 0, SEEK_END);
        long size = ftell(f_read);

        
        if (size > 0)
        {
            
            fseek(f_read, -1, SEEK_END);
            int last_char = fgetc(f_read);
            fclose(f_read);

            
            if (last_char != '\n')
            {
                FILE *f_append_nl = fopen(IND_FILE, "a");
                if (!f_append_nl)
                    return false;
                
                fputc('\n', f_append_nl);
                fclose(f_append_nl);
            }
        }
        else
        {
            fclose(f_read);
        }
    }
    FILE *f = fopen(IND_FILE, "a");

    if (!f)
        return false;

    
    if (!f_read)
    {
        
        if (fprintf(
                f,
                "CNPJ,RAZAO_SOCIAL,NOME_FANTASIA,TELEFONE,LOGRADOURO,NUMERO,BAIRRO,CIDADE,ESTADO,CEP,DATA_ABERTURA,NOME_RESPONSAVEL,EMAIL_RESPONSAVEL\n")
            < 0)
        {
            
            fclose(f);
            return false;
        }
    }

    
    if (fprintf(f, "%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s\n",
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
                industria->email_responsavel) < 0)
    {
        
        fclose(f);
        return false;
    }

    fclose(f_read);
    return true;
}

bool buscar_industria_csv(const char *cnpj, industria_t *out_industria)
{
    if (!cnpj || !out_industria)
        return false;

    FILE *f = fopen(IND_FILE, "r");
    if (!f)
        return false;

    char line[TAMANHO_LINHA_IND];
    bool encontrado = false;
    industria_t industria_temp;

    fgets(line, sizeof(line), f);

    while (fgets(line, sizeof(line), f))
    {
        if (extrair_dados_industria_csv(line, &industria_temp))
        {
            if (strcmp(industria_temp.cnpj, cnpj) == 0)
            {
                *out_industria = industria_temp;
                encontrado = true;
                break;
            }
        }
    }

    fclose(f);
    return encontrado;
}

bool listar_industrias_csv(industria_t *industrias, size_t tamanho_max, size_t *qtd_industrias)
{
    if (!industrias || !qtd_industrias)
        return false;
    *qtd_industrias = 0;

    FILE *f = fopen(IND_FILE, "r");
    if (!f)
    {
        return false;
    }

    char line[TAMANHO_LINHA_IND];
    size_t count = 0;

    fgets(line, sizeof(line), f);

    while (count < tamanho_max && fgets(line, sizeof(line), f))
    {
        if (extrair_dados_industria_csv(line, &industrias[count]))
        {
            count++;
        }
    }

    *qtd_industrias = count;

    fclose(f);

    return true;
}

bool atualizar_industria_csv(const industria_t *industria)
{
    if (!industria)
        return false;

    FILE *f_orig = fopen(IND_FILE, "r");
    FILE *f_temp = fopen(IND_FILE_TEMP, "w");

    if (!f_orig || !f_temp)
    {
        if (f_orig)
            fclose(f_orig);
        if (f_temp)
            fclose(f_temp);
        return false;
    }

    char line[TAMANHO_LINHA_IND];
    bool atualizado = false;
    industria_t industria_temp;

    
    if (fgets(line, sizeof(line), f_orig))
    {
        if (fputs(line, f_temp) == EOF)
        {
            fclose(f_orig);
            fclose(f_temp);
            return false;
        }
    }

    while (fgets(line, sizeof(line), f_orig))
    {
        if (extrair_dados_industria_csv(line, &industria_temp))
        {
            
            if (strcmp(industria_temp.cnpj, industria->cnpj) == 0)
            {
                industria_temp = *industria;
                atualizado = true;
            }
            
            if (fprintf(f_temp, "%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s\n",
                        industria_temp.cnpj,
                        industria_temp.razao_social,
                        industria_temp.nome_fantasia,
                        industria_temp.telefone,
                        industria_temp.logradouro,
                        industria_temp.numero,
                        industria_temp.bairro,
                        industria_temp.cidade,
                        industria_temp.estado,
                        industria_temp.cep,
                        industria_temp.data_abertura,
                        industria_temp.nome_responsavel,
                        industria_temp.email_responsavel) < 0)
            {
                fclose(f_orig);
                fclose(f_temp);
                return false;
            }
        }
        else
        {
            
            if (fputs(line, f_temp) == EOF)
            {
                fclose(f_orig);
                fclose(f_temp);
                return false;
            }
        }
    }

    fclose(f_orig);
    fclose(f_temp);

    
    if (!atualizado)
    {
        
        remove(IND_FILE);
        rename(IND_FILE_TEMP, IND_FILE);

        return false;
    }
    
    remove(IND_FILE);
    rename(IND_FILE_TEMP, IND_FILE);
    return true;
}

bool excluir_industria_csv(const char *cnpj)
{
    if (!cnpj)
        return false;

    FILE *f_orig = fopen(IND_FILE, "r");
    FILE *f_temp = fopen(IND_FILE_TEMP, "w");

    if (!f_orig || !f_temp)
    {
        if (f_orig)
            fclose(f_orig);
        if (f_temp)
            fclose(f_temp);
        return false;
    }

    char line[TAMANHO_LINHA_IND];
    bool encontrado = false;
    industria_t industria_temp;

    
    if (fgets(line, sizeof(line), f_orig))
    {
        if (fputs(line, f_temp) == EOF)
        {
            fclose(f_orig);
            fclose(f_temp);
            return false;
        }
    }

    while (fgets(line, sizeof(line), f_orig))
    {
        if (extrair_dados_industria_csv(line, &industria_temp))
        {
            
            if (strcmp(industria_temp.cnpj, cnpj) != 0)
            {
                if (fprintf(f_temp, "%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s\n",
                            industria_temp.cnpj,
                            industria_temp.razao_social,
                            industria_temp.nome_fantasia,
                            industria_temp.telefone,
                            industria_temp.logradouro,
                            industria_temp.numero,
                            industria_temp.bairro,
                            industria_temp.cidade,
                            industria_temp.estado,
                            industria_temp.cep,
                            industria_temp.data_abertura,
                            industria_temp.nome_responsavel,
                            industria_temp.email_responsavel) < 0)
                {
                    fclose(f_orig);
                    fclose(f_temp);
                    return false;
                }
            }
            else
            {
                encontrado = true;
            }
        }
        else
        {
            
            if (fputs(line, f_temp) == EOF)
            {
                fclose(f_orig);
                fclose(f_temp);
                return false;
            }
        }
    }

    fclose(f_orig);
    fclose(f_temp);

    
    if (!encontrado)
    {
        remove(IND_FILE_TEMP);
        return false;
    }
    
    remove(IND_FILE);
    rename(IND_FILE_TEMP, IND_FILE);
    return true;
}

bool verificar_csv_industria(void)
{
    /* Verificações de integridade do arquivo:
       - Verificar se o arquivo existe
       - Verificar se há cabeçalho
       - Verificar se o arquivo termina com quebra de linha
       - Verificar formato das linhas
       Se encontrar problemas, tenta corrigir */

    FILE *f_orig = fopen(IND_FILE, "r");

    
    if (!f_orig)
    {
        FILE *f_new = fopen(IND_FILE, "w");
        if (!f_new)
        {
            return false; 
        }

        
        if (fprintf(
                f_new,
                "CNPJ,RAZAO_SOCIAL,NOME_FANTASIA,TELEFONE,LOGRADOURO,NUMERO,BAIRRO,CIDADE,ESTADO,CEP,DATA_ABERTURA,NOME_RESPONSAVEL,EMAIL_RESPONSAVEL\n")
            < 0)
        {
            fclose(f_new);
            return false;
        }

        fclose(f_new);
        return true;
    }

    
    char line[TAMANHO_LINHA_IND];
    bool tem_cabecalho = false;

    if (fgets(line, sizeof(line), f_orig))
    {
        if (strstr(line, "CNPJ,RAZAO_SOCIAL") != NULL)
        {
            tem_cabecalho = true;
        }
    }

    /* Ler todo o arquivo para um buffer e fazer correções necessárias */
    fseek(f_orig, 0, SEEK_END);
    long file_size = ftell(f_orig);
    rewind(f_orig);

    /* Se o arquivo for muito grande, não tenta carregar tudo na memória */
    if (file_size > 1024 * 1024 * 10)
    {
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

    /* Se não tiver cabeçalho, prepara para adicionar */
    bool arquivo_modificado = false;
    char *novo_conteudo = NULL;

    if (!tem_cabecalho && bytes_read > 0)
    {
        const char *cabecalho =
            "CNPJ,RAZAO_SOCIAL,NOME_FANTASIA,TELEFONE,LOGRADOURO,NUMERO,BAIRRO,CIDADE,ESTADO,CEP,DATA_ABERTURA,NOME_RESPONSAVEL,EMAIL_RESPONSAVEL\n";
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

    /* Verificar se o arquivo termina com quebra de linha */
    if (bytes_read > 0 && buffer[bytes_read - 1] != '\n')
    {
        if (novo_conteudo)
        {
            /* Temos um buffer novo com cabeçalho, adicionar quebra de linha */
            size_t len = strlen(novo_conteudo);
            novo_conteudo[len] = '\n';
            novo_conteudo[len + 1] = '\0';
        }
        else
        {
            /* Criar um novo buffer apenas para adicionar quebra de linha */
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

    /* Se o arquivo foi modificado, reescrever */
    if (arquivo_modificado)
    {
        FILE *f_write = fopen(IND_FILE, "w");
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
