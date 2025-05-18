#include "persistencia/residuo_dao.h"

bool gravar_residuo_csv(const residuo_t *residuo)
{
    residuo_t *arr = NULL;
    size_t cap = 0, cnt = 0;
    FILE *f = fopen(RES_FILE, "r");
    if (f)
    {
        char line[256];
        // Ignorar cabeçalho
        fgets(line, sizeof(line), f);
        while (fgets(line, sizeof(line), f))
        {
            residuo_t temp;
            char *tok = strtok(line, ",");
            if (!tok)
            {
                continue;
            }
            strncpy(temp.cnpj, tok, sizeof(temp.cnpj));
            tok = strtok(NULL, ",");
            if (!tok)
            {
                continue;
            }
            temp.mes = atoi(tok);
            tok = strtok(NULL, ",");
            if (!tok)
            {
                continue;
            }
            temp.ano = atoi(tok);
            tok = strtok(NULL, ",");
            if (!tok)
            {
                continue;
            }
            temp.quantidade = atof(tok);
            tok = strtok(NULL, ",\n");
            if (!tok)
            {
                continue;
            }
            temp.custo = atof(tok);
            // atualizar se corresponder
            if (strcmp(temp.cnpj, residuo->cnpj) == 0 && temp.mes == residuo->mes && temp.ano == residuo->ano)
            {
                temp.quantidade = residuo->quantidade;
                temp.custo = residuo->custo;
            }
            // empacotar
            if (cnt >= cap)
            {
                cap = cap ? cap * 2 : 8;
/*
                Alteração sugerida:

-                 arr = realloc(arr, cap * sizeof(residuo_t));
+                 void *temp_ptr = realloc(arr, cap * sizeof(residuo_t));
+                 if (!temp_ptr)
+                 {
+                     free(arr);
+                     fclose(f);
+                     return false;
+                 }
+                 arr = temp_ptr;
*/
                arr = realloc(arr, cap * sizeof(residuo_t));
            }
            arr[cnt++] = temp;
        }
        fclose(f);
    }
    // se não encontrou, adiciona novo
    bool found = false;
    for (size_t i = 0; i < cnt; ++i)
    {
        if (strcmp(arr[i].cnpj, residuo->cnpj) == 0 && arr[i].mes == residuo->mes && arr[i].ano == residuo->ano)
        {
            found = true;
            break;
        }
    }
    if (!found)
    {
        if (cnt >= cap)
        {
            cap = cap ? cap * 2 : 8;
            arr = realloc(arr, cap * sizeof(residuo_t));
        }
        arr[cnt++] = *residuo;
    }
    // reescreve arquivo
    f = fopen(RES_FILE, "w");
    if (!f)
    {
        free(arr);
        return false;
    }

    // Escrever cabeçalho e verificar se foi escrito corretamente
    if (fprintf(f, "CNPJ,MES,ANO,QUANTIDADE,CUSTO\n") < 0)
    {
        // Erro ao escrever cabeçalho
        fclose(f);
        free(arr);
        return false;
    }
    // Escrever registros
    for (size_t i = 0; i < cnt; ++i)
    {
        if (fprintf(f, "%s,%d,%d,%.2f,%.2f\n",
                    arr[i].cnpj, arr[i].mes, arr[i].ano,
                    arr[i].quantidade, arr[i].custo) < 0)
        {
            // Erro ao escrever registro
            fclose(f);
            free(arr);
            return false;
        }
    }

    // Fechar o arquivo - o sistema operacional se encarregará de garantir
    // que os dados sejam efetivamente gravados no disco
    fclose(f);
    free(arr);
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
    { // 10MB
        fclose(f_orig);
        return false;
    }

    char *buffer = (char *)malloc(file_size + 1);
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

        novo_conteudo = (char *)malloc(novo_tamanho);
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
            novo_conteudo = (char *)malloc(bytes_read + 2);
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