#include "persistencia/funcionario_dao.h"

/**
 * Função auxiliar para extrair dados de funcionário de uma linha CSV.
 * @param linha A linha do arquivo CSV
 * @param funcionario Estrutura onde os dados extraídos serão armazenados
 * @return true se extração foi bem sucedida, false caso contrário
 */
static bool extrair_dados_funcionario_csv(char *linha, funcionario_t *funcionario)
{
    if (!linha || !funcionario)
        return false;

    char linha_backup[TAMANHO_LINHA_FUNC];
    strncpy(linha_backup, linha, sizeof(linha_backup) - 1);
    linha_backup[sizeof(linha_backup) - 1] = '\0';

    char *tok = strtok(linha_backup, ",");
    if (!tok)
        return false;
    trim_crlf(tok);

    strncpy(funcionario->matricula, tok, sizeof(funcionario->matricula) - 1);
    funcionario->matricula[sizeof(funcionario->matricula) - 1] = '\0';

    tok = strtok(NULL, ",");
    if (!tok)
        return false;
    trim_crlf(tok);

    strncpy(funcionario->nome, tok, sizeof(funcionario->nome) - 1);
    funcionario->nome[sizeof(funcionario->nome) - 1] = '\0';

    tok = strtok(NULL, ",\n");
    if (!tok)
        return false;
    trim_crlf(tok);

    strncpy(funcionario->hash_senha, tok, sizeof(funcionario->hash_senha) - 1);
    funcionario->hash_senha[sizeof(funcionario->hash_senha) - 1] = '\0';
    return true;
}

bool validar_funcionario_csv(const char *matricula_str, const char *hash_senha, funcionario_t *out_funcionario)
{
    if (!matricula_str || !hash_senha)
        return false;
    FILE *f = fopen(FUNC_FILE, "r");
    if (!f)
        return false;

    char line[TAMANHO_LINHA_FUNC];
    funcionario_t funcionario_temp;
    bool autenticado = false;

    fgets(line, sizeof(line), f);

    while (fgets(line, sizeof(line), f))
    {
        if (!extrair_dados_funcionario_csv(line, &funcionario_temp))
        {
            continue;
        }

        if (strcmp(funcionario_temp.matricula, matricula_str) != 0)
        {
            continue;
        }

        if (strcmp(hash_senha, funcionario_temp.hash_senha) == 0)
        {

            if (out_funcionario)
            {
                *out_funcionario = funcionario_temp;
            }
            autenticado = true;
            break;
        }
    }

    fclose(f);
    return autenticado;
}

bool inserir_funcionario_csv(const funcionario_t *funcionario)
{

    if (!funcionario)
        return false;

    FILE *f_read = fopen(FUNC_FILE, "r");
    if (f_read)
    {

        fseek(f_read, 0, SEEK_END);
        long size = ftell(f_read);

        if (size > 0)
        {

            fseek(f_read, -1, SEEK_END);
            char last_char = fgetc(f_read);
            fclose(f_read);

            if (last_char != '\n')
            {
                FILE *f_append_nl = fopen(FUNC_FILE, "a");
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
    FILE *f = fopen(FUNC_FILE, "a");
    if (!f)
        return false;

    if (!f_read)
    {

        if (fprintf(f, "MATRICULA,NOME,HASH_SENHA\n") < 0)
        {

            fclose(f);
            return false;
        }
    }

    if (fprintf(f, "%s,%s,%s\n", funcionario->matricula, funcionario->nome, funcionario->hash_senha) < 0)
    {

        fclose(f);
        return false;
    }

    fclose(f);
    return true;
}

bool buscar_funcionario_csv(const char *matricula_str, funcionario_t *out_funcionario)
{
    if (!matricula_str || !out_funcionario)
        return false;

    FILE *f = fopen(FUNC_FILE, "r");
    if (!f)
        return false;

    char line[TAMANHO_LINHA_FUNC];
    bool encontrado = false;
    funcionario_t funcionario_temp;

    fgets(line, sizeof(line), f);

    while (fgets(line, sizeof(line), f))
    {
        if (extrair_dados_funcionario_csv(line, &funcionario_temp))
        {
            if (strcmp(funcionario_temp.matricula, matricula_str) == 0)
            {
                *out_funcionario = funcionario_temp;
                encontrado = true;
                break;
            }
        }
    }

    fclose(f);
    return encontrado;
}

/* Função movida para o inúcio do arquivo */

bool listar_funcionarios_csv(funcionario_t *funcionarios, size_t tamanho_max, size_t *qtd_funcionarios)
{
    if (!funcionarios || !qtd_funcionarios)
        return false;
    *qtd_funcionarios = 0;

    FILE *f = fopen(FUNC_FILE, "r");
    if (!f)
    {
        return false;
    }

    char line[TAMANHO_LINHA_FUNC];
    size_t count = 0;

    fgets(line, sizeof(line), f);

    while (count < tamanho_max && fgets(line, sizeof(line), f))
    {
        if (extrair_dados_funcionario_csv(line, &funcionarios[count]))
        {
            count++;
        }
    }

    *qtd_funcionarios = count;

    fclose(f);

    return true;
}

bool atualizar_funcionario_csv(const funcionario_t *funcionario)
{
    if (!funcionario)
        return false;

    FILE *f_orig = fopen(FUNC_FILE, "r");
    FILE *f_temp = fopen(FUNC_FILE_TEMP, "w");

    if (!f_orig || !f_temp)
    {
        if (f_orig)
            fclose(f_orig);
        if (f_temp)
            fclose(f_temp);
        return false;
    }

    char line[TAMANHO_LINHA_FUNC];
    bool atualizado = false;
    funcionario_t funcionario_temp;

    /* Copiar cabeçalho para o arquivo temporário */
    if (fgets(line, sizeof(line), f_orig))
    {
        if (fputs(line, f_temp) == EOF)
        {
            fclose(f_orig);
            fclose(f_temp);
            return false;
        }
    }

    /* Copiar todos os registros para o arquivo temporário, atualizando o registro desejado */
    while (fgets(line, sizeof(line), f_orig))
    {
        char linha_copia[TAMANHO_LINHA_FUNC];
        strncpy(linha_copia, line, sizeof(linha_copia) - 1);
        linha_copia[sizeof(linha_copia) - 1] = '\0';

        if (!extrair_dados_funcionario_csv(linha_copia, &funcionario_temp))
        {
            fputs(line, f_temp);
            continue;
        }

        if (strcmp(funcionario_temp.matricula, funcionario->matricula) == 0)
        {

            if (fprintf(f_temp, "%s,%s,%s\n",
                        funcionario->matricula,
                        funcionario->nome,
                        funcionario->hash_senha) < 0)
            {
                fclose(f_orig);
                fclose(f_temp);
                return false;
            }
            atualizado = true;
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

        remove(FUNC_FILE);
        rename(FUNC_FILE_TEMP, FUNC_FILE);

        return false;
    }

    remove(FUNC_FILE);
    rename(FUNC_FILE_TEMP, FUNC_FILE);

    return true;
}

bool excluir_funcionario_csv(const char *matricula_str)
{
    if (!matricula_str)
        return false;

    FILE *f_orig = fopen(FUNC_FILE, "r");
    FILE *f_temp = fopen(FUNC_FILE_TEMP, "w");

    if (!f_orig || !f_temp)
    {
        if (f_orig)
            fclose(f_orig);
        if (f_temp)
            fclose(f_temp);
        return false;
    }

    char line[TAMANHO_LINHA_FUNC];
    bool encontrado = false;
    funcionario_t funcionario_temp;

    if (fgets(line, sizeof(line), f_orig))
    {
        if (fputs(line, f_temp) == EOF)
        {
            fclose(f_orig);
            fclose(f_temp);
            return false;
        }
    }
    /* Copiar todos os registros para o arquivo temporário, exceto o registro a ser excluído */
    while (fgets(line, sizeof(line), f_orig))
    {
        char linha_copia[TAMANHO_LINHA_FUNC];
        strncpy(linha_copia, line, sizeof(linha_copia) - 1);
        linha_copia[sizeof(linha_copia) - 1] = '\0';

        bool linha_valida = extrair_dados_funcionario_csv(linha_copia, &funcionario_temp);

        if (!linha_valida)
        {
            continue;
        }

        if (strcmp(funcionario_temp.matricula, matricula_str) != 0)
        {
            if (fputs(line, f_temp) == EOF)
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

    fclose(f_orig);
    fclose(f_temp);

    if (!encontrado)
    {
        remove(FUNC_FILE_TEMP);
        return false;
    }

    remove(FUNC_FILE);
    rename(FUNC_FILE_TEMP, FUNC_FILE);

    return true;
}

bool verificar_csv_funcionario(char *erro_out)
{
    FILE *f_orig = fopen(FUNC_FILE, "r");

    if (!f_orig)
    {
        FILE *f_new = fopen(FUNC_FILE, "w");
        if (!f_new)
        {
            if (erro_out)
                strcpy(erro_out, "Erro ao criar o arquivo de funcionários.");
            return false;
        }

        if (fprintf(f_new, "MATRICULA,NOME,HASH_SENHA\n123456,ADMINISTRADOR,9B98999E9F9C\n") < 0)
        {
            if (erro_out)
                strcpy(erro_out, "Erro ao escrever cabeçalho padrão e ADMINISTRADOR.");
            fclose(f_new);
            return false;
        }

        fclose(f_new);
        return true;
    }

    char line[TAMANHO_LINHA_FUNC];
    bool tem_cabecalho = false;

    if (fgets(line, sizeof(line), f_orig))
    {
        if (strstr(line, "MATRICULA,NOME") != NULL)
        {
            tem_cabecalho = true;
        }
    }

    fseek(f_orig, 0, SEEK_END);
    long file_size = ftell(f_orig);
    rewind(f_orig);

    if (file_size > 1024 * 1024 * 10)
    {
        if (erro_out)
            strcpy(erro_out, "O arquivo de funcionários é muito grande para ser processado.");
        fclose(f_orig);
        return false;
    }

    char *buffer = (char *)malloc(file_size + 1);
    if (!buffer)
    {
        if (erro_out)
            strcpy(erro_out, "Erro ao alocar memória para leitura do arquivo de funcionários.");
        fclose(f_orig);
        return false;
    }

    size_t bytes_read = fread(buffer, 1, file_size, f_orig);
    fclose(f_orig);
    buffer[bytes_read] = '\0';

    bool arquivo_modificado = false;
    char *novo_conteudo = NULL;

    // Inserção de cabeçalho (caso falte)
    if (!tem_cabecalho && bytes_read > 0)
    {
        const char *cabecalho = "MATRICULA,NOME,HASH_SENHA\n";
        size_t novo_tamanho = strlen(cabecalho) + bytes_read + 1;

        novo_conteudo = (char *)malloc(novo_tamanho);
        if (!novo_conteudo)
        {
            if (erro_out)
                strcpy(erro_out, "Erro ao alocar memória para inserir o cabeçalho.");
            free(buffer);
            return false;
        }

        strcpy(novo_conteudo, cabecalho);
        strcat(novo_conteudo, buffer);
        arquivo_modificado = true;
    }

    // Verificação de ADMINISTRADOR
    const char *linha_admin = "123456,ADMINISTRADOR,9B98999E9F9C\n";
    const char *conteudo_base = novo_conteudo ? novo_conteudo : buffer;

    if (!strstr(conteudo_base, "123456,ADMINISTRADOR"))
    {
        const char *cabecalho = "MATRICULA,NOME,HASH_SENHA\n";
        char *dados = strstr(conteudo_base, cabecalho);

        if (dados)
        {
            dados += strlen(cabecalho);
            size_t novo_tam = strlen(cabecalho) + strlen(linha_admin) + strlen(dados) + 1;

            char *conteudo_com_admin = (char *)malloc(novo_tam);
            if (!conteudo_com_admin)
            {
                if (erro_out)
                    strcpy(erro_out, "Erro ao alocar memória para adicionar ADMINISTRADOR.");
                free(buffer);
                if (novo_conteudo)
                    free(novo_conteudo);
                return false;
            }

            strcpy(conteudo_com_admin, cabecalho);
            strcat(conteudo_com_admin, linha_admin);
            strcat(conteudo_com_admin, dados);

            if (novo_conteudo)
                free(novo_conteudo);
            novo_conteudo = conteudo_com_admin;
            arquivo_modificado = true;
        }
    }

    // Verificação de quebra de linha ao final
    const char *final = novo_conteudo ? novo_conteudo : buffer;
    size_t len_final = strlen(final);
    if (len_final > 0 && final[len_final - 1] != '\n')
    {
        char *conteudo_corrigido = (char *)malloc(len_final + 2);
        if (!conteudo_corrigido)
        {
            if (erro_out)
                strcpy(erro_out, "Erro ao alocar memória para adicionar quebra de linha.");
            free(buffer);
            if (novo_conteudo)
                free(novo_conteudo);
            return false;
        }

        memcpy(conteudo_corrigido, final, len_final);
        conteudo_corrigido[len_final] = '\n';
        conteudo_corrigido[len_final + 1] = '\0';

        if (novo_conteudo)
            free(novo_conteudo);
        novo_conteudo = conteudo_corrigido;
        arquivo_modificado = true;
    }

    // Reescrever, se necessário
    if (arquivo_modificado)
    {
        FILE *f_write = fopen(FUNC_FILE, "w");
        if (!f_write)
        {
            if (erro_out)
                strcpy(erro_out, "Erro ao abrir o arquivo de funcionários para sobrescrita.");
            free(buffer);
            if (novo_conteudo)
                free(novo_conteudo);
            return false;
        }

        const char *conteudo_final = novo_conteudo ? novo_conteudo : buffer;
        size_t tamanho_final = strlen(conteudo_final);

        if (fwrite(conteudo_final, 1, tamanho_final, f_write) != tamanho_final)
        {
            if (erro_out)
                strcpy(erro_out, "Erro ao regravar o arquivo de funcionários.");
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