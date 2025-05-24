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

    // Fazer uma cópia da linha para evitar problemas com strtok
    char linha_backup[TAMANHO_LINHA_FUNC];
    strncpy(linha_backup, linha, sizeof(linha_backup) - 1);
    linha_backup[sizeof(linha_backup) - 1] = '\0';

    // Extração segura dos dados
    char *tok = strtok(linha_backup, ",");
    if (!tok)
        return false;
    // Armazenar matrícula como string
    strncpy(funcionario->matricula, tok, sizeof(funcionario->matricula) - 1);
    funcionario->matricula[sizeof(funcionario->matricula) - 1] = '\0';

    tok = strtok(NULL, ",");
    if (!tok)
        return false;
    // Garantir terminação nula
    strncpy(funcionario->nome, tok, sizeof(funcionario->nome) - 1);
    funcionario->nome[sizeof(funcionario->nome) - 1] = '\0';

    tok = strtok(NULL, ",\n");
    if (!tok)
        return false;
    // Garantir terminação nula
    strncpy(funcionario->hash_senha, tok, sizeof(funcionario->hash_senha) - 1);
    funcionario->hash_senha[sizeof(funcionario->hash_senha) - 1] = '\0';
    return true;
}

bool validar_funcionario_csv(const char *matricula_str, const char *senha, funcionario_t *out_funcionario)
{
    if (!matricula_str || !senha)
        return false;
    FILE *f = fopen(FUNC_FILE, "r");
    if (!f)
        return false;

    char line[TAMANHO_LINHA_FUNC];
    funcionario_t funcionario_temp;
    bool autenticado = false;

    // Pular a primeira linha (cabeçalho)
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

        // Compute hash of input senha
        char hash[64];
        hash_senha(senha, hash, HASH_KEY);

        if (strcmp(hash, funcionario_temp.hash_senha) == 0)
        {
            // Credenciais válidas
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
    // Verificar se o funcionário é válido
    if (!funcionario)
        return false;

    // Primeiro, verificamos se o arquivo existe e se termina com uma quebra de linha
    FILE *f_read = fopen(FUNC_FILE, "r");
    if (f_read)
    {
        // Vai para o fim do arquivo
        fseek(f_read, 0, SEEK_END);
        long size = ftell(f_read);

        // Se o arquivo não está vazio, verificar o último caractere
        if (size > 0)
        {
            // Volta uma posição para ler o último caractere
            fseek(f_read, -1, SEEK_END);
            char last_char = fgetc(f_read);
            fclose(f_read);

            // Se o último caractere não for quebra de linha, abrir em modo a+ para adicionar quebra de linha
            if (last_char != '\n')
            {
                FILE *f_append_nl = fopen(FUNC_FILE, "a");
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
    FILE *f = fopen(FUNC_FILE, "a");
    if (!f)
        return false;

    // Se arquivo estava vazio ou não existia, escreve o cabeçalho
    if (!f_read)
    {
        // Escrever cabeçalho e verificar se foi escrito corretamente
        if (fprintf(f, "MATRICULA,NOME,HASH_SENHA\n") < 0)
        {
            // Erro ao escrever cabeçalho
            fclose(f);
            return false;
        }
    }

    // Escrever dados do funcionário e verificar se foi escrito corretamente
    if (fprintf(f, "%s,%s,%s\n", funcionario->matricula, funcionario->nome, funcionario->hash_senha) < 0)
    {
        // Erro ao escrever dados
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

    // Copiar cabeçalho para o arquivo temporário
    if (fgets(line, sizeof(line), f_orig))
    {
        if (fputs(line, f_temp) == EOF)
        {
            fclose(f_orig);
            fclose(f_temp);
            return false;
        }
    }

    // Copiar todos os registros para o arquivo temporário, atualizando o registro desejado
    while (fgets(line, sizeof(line), f_orig))
    {
        char linha_copia[TAMANHO_LINHA_FUNC];
        strncpy(linha_copia, line, sizeof(linha_copia) - 1);
        linha_copia[sizeof(linha_copia) - 1] = '\0';

        // Usar a função auxiliar para extrair dados
        if (!extrair_dados_funcionario_csv(linha_copia, &funcionario_temp))
        {
            fputs(line, f_temp);
            continue;
        }
        // Se encontrou o funcionário a ser atualizado
        if (strcmp(funcionario_temp.matricula, funcionario->matricula) == 0)
        {
            // Escrever registro atualizado
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
            // Manter o registro original
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

    // Se o funcionário não foi encontrado, retorna falso
    if (!atualizado)
    {
        // Renomear arquivos
        remove(FUNC_FILE);
        rename(FUNC_FILE_TEMP, FUNC_FILE);

        return false;
    }

    // Substituir o arquivo original pelo arquivo temporário
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
    // Copiar cabeçalho para o arquivo temporário
    if (fgets(line, sizeof(line), f_orig))
    {
        if (fputs(line, f_temp) == EOF)
        {
            fclose(f_orig);
            fclose(f_temp);
            return false;
        }
    }
    // Copiar todos os registros para o arquivo temporário, exceto o registro a ser excluído
    while (fgets(line, sizeof(line), f_orig))
    {
        char linha_copia[TAMANHO_LINHA_FUNC];
        strncpy(linha_copia, line, sizeof(linha_copia) - 1);
        linha_copia[sizeof(linha_copia) - 1] = '\0';

        // Tenta extrair os dados da linha para verificar se é válida
        bool linha_valida = extrair_dados_funcionario_csv(linha_copia, &funcionario_temp);

        // Se a linha não for válida, ignora-a (opção mais segura)
        if (!linha_valida)
        {
            continue; // Linha inválida, não copiar para o arquivo temporário
        }
        // Se não for o funcionário a ser excluído, mantém no arquivo
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

    // Se o funcionário não foi encontrado, retorna falso
    if (!encontrado)
    {
        remove(FUNC_FILE_TEMP);
        return false;
    }

    // Substituir o arquivo original pelo arquivo temporário
    remove(FUNC_FILE);
    rename(FUNC_FILE_TEMP, FUNC_FILE);

    return true;
}

bool verificar_csv_funcionario(void)
{
    /* Verificações de integridade do arquivo:
       - Verificar se o arquivo existe
       - Verificar se há cabeçalho
       - Verificar se o arquivo termina com quebra de linha
       - Verificar formato das linhas
       Se encontrar problemas, tenta corrigir */

    FILE *f_orig = fopen(FUNC_FILE, "r");

    // Se o arquivo não existir, cria um novo com cabeçalho
    if (!f_orig)
    {
        FILE *f_new = fopen(FUNC_FILE, "w");
        if (!f_new)
        {
            return false; // Não conseguiu criar o arquivo
        }

        // Escrever cabeçalho
        if (fprintf(f_new, "MATRICULA,NOME,HASH_SENHA\n") < 0)
        {
            fclose(f_new);
            return false;
        }

        fclose(f_new);
        return true;
    }

    // Verificar se há cabeçalho
    char line[TAMANHO_LINHA_FUNC];
    bool tem_cabecalho = false;

    if (fgets(line, sizeof(line), f_orig))
    {
        if (strstr(line, "MATRICULA,NOME") != NULL)
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
        const char *cabecalho = "MATRICULA,NOME,HASH_SENHA\n";
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
        FILE *f_write = fopen(FUNC_FILE, "w");
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
