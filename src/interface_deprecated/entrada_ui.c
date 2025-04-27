
#include "entrada_ui.h"

/**
 * * @brief Lê uma opção do usuário, repetindo até receber um valor válido.
 * * @param prompt Texto a exibir antes da leitura.
 * * @param opcoes_validas Array de opções válidas.
 */
int ler_opcao(const char *prompt, const int *opcoes_validas, size_t num_opcoes) {
    char buf[32];
    long v;
    char *endptr;

    // Loop infinito para ler a opção do usuário
    while (1) {
        if (prompt == NULL) {
            prompt = ">> Opção: ";
        }
        printf("%s", prompt);

        // Lê a entrada do usuário
        if (!fgets(buf, sizeof buf, stdin)) {
            // Ignora a leitura inválida e continua o loop
            continue;
        }

        // Remove o '\n' da entrada
        buf[strcspn(buf, "\n")] = '\0';

        // Converte a entrada para um número
        v = strtol(buf, &endptr, 10);

        // Verifica se a entrada é um número válido
        if (*endptr != '\0') {
            mostrar_msg_erro(erro_msg(ERR_OPCAO_INVALIDA_NUMERICA));
            continue;
        }

        // Verifica se o número está na lista de opções válidas
        int valido = 0;
        for (size_t i = 0; i < num_opcoes; i++) {
            if (v == opcoes_validas[i]) {
                valido = 1;
                break;
            }
        }

        if (!valido) {
            mostrar_msg_erro(erro_msg(ERR_OPCAO_INVALIDA));
            continue;
        }

        return (int)v; // Retorna a opção válida
    }
}



/**
 * @brief Lê a matrícula do usuário, validando se é um número inteiro de até 6 dígitos.
 * @return A matrícula válida.
 */
int ler_matricula(const char *prompt) {
    int matricula;
    char buf[16]; // Buffer para entrada do usuário

    while (1) {
        printf(">> Digite a matrícula do novo usuário (até 6 dígitos): ");
        
        // Lê a entrada como string para validação
        if (!fgets(buf, sizeof(buf), stdin)) {
            mostrar_msg_erro(erro_msg(ERR_LEITURA_INVALIDA));
            continue;
        }

        // Remove o '\n' da entrada
        buf[strcspn(buf, "\n")] = '\0';

        // Verifica se a entrada é um número válido
        char *endptr;
        matricula = strtol(buf, &endptr, 10);

        if (*endptr != '\0' || matricula < 0 || matricula > 999999) {
            mostrar_msg_erro(erro_msg(ERR_MATRICULA_INVALIDA));
            continue;
        }

        return matricula; // Retorna a matrícula válida
    }
}

void ler_nome(const char *prompt, char *nome, size_t tamanho)
{
    while (1) {
        mostrar_prompt(prompt);
        
        // Lê a entrada do usuário
        if (fgets(nome, tamanho, stdin) == NULL) {
            mostrar_msg_erro(erro_msg(ERR_LEITURA_NOME_INVALIDO));
            continue;
        }

        // Remove o '\n' da entrada
        nome[strcspn(nome, "\n")] = '\0';

        // Verifica se o nome não está vazio
        if (strlen(nome) == 0) {
            mostrar_msg_erro(erro_msg(ERR_NOME_VAZIO));
            continue;
        }

        // Converte o nome para maiúsculas
        to_upper_case(nome);

        return; // Nome válido lido com sucesso
    }
}

void ler_senha(const char *prompt, char *senha, size_t tamanho) {
    while (1) {
        mostrar_prompt(prompt);

        // Lê a entrada como string
        if (fgets(senha, tamanho, stdin) == NULL) {
            mostrar_msg_erro(erro_msg(ERR_LEITURA_SENHA_INVALIDA));
            continue;
        }

        // Remove o '\n' da entrada
        senha[strcspn(senha, "\n")] = '\0';

        // Verifica se a senha não está vazia
        if (strlen(senha) == 0) {
            mostrar_msg_erro(erro_msg(ERR_SENHA_VAZIA));
            continue;
        }

        return; // Senha válida lida com sucesso
    }
}

void ler_email(const char *prompt, char *email, size_t tamanho) {
    while (1) {
        mostrar_prompt(prompt);

        // Lê a entrada do usuário
        if (fgets(email, tamanho, stdin) == NULL) {
            mostrar_msg_erro(erro_msg(ERR_LEITURA_INVALIDA));
            continue;
        }

        // Remove o '\n' da entrada
        email[strcspn(email, "\n")] = '\0';

        // Verifica se o e-mail não está vazio
        if (strlen(email) == 0) {
            mostrar_msg_erro(erro_msg(ERR_EMAIL_INVALIDO));
            continue;
        }

        // Valida o formato básico do e-mail (deve conter '@' e '.')
        if (strchr(email, '@') == NULL || strchr(email, '.') == NULL) {
            mostrar_msg_erro(erro_msg(ERR_EMAIL_INVALIDO));
            continue;
        }

        return; // E-mail válido lido com sucesso
    }
}

void ler_cnpj(const char *prompt, char *cnpj, size_t tamanho) {
    while (1) {
        mostrar_prompt(prompt);

        // Lê a entrada do usuário
        if (fgets(cnpj, tamanho, stdin) == NULL) {
            mostrar_msg_erro(erro_msg(ERR_LEITURA_INVALIDA));
            continue;
        }

        // Remove o '\n' da entrada
        cnpj[strcspn(cnpj, "\n")] = '\0';

        // Verifica se o CNPJ não está vazio
        if (strlen(cnpj) == 0) {
            mostrar_msg_erro(erro_msg(ERR_CNPJ_VAZIO));
            continue;
        }

        // Valida o comprimento do CNPJ (14 dígitos sem formatação)
        if (strlen(cnpj) != 14) {
            mostrar_msg_erro(erro_msg(ERR_CNPJ_COMPRIMENTO));
            continue;
        }

        // Verifica se todos os caracteres são dígitos
        int valido = 1;
        for (size_t i = 0; i < strlen(cnpj); i++) {
            if (!isdigit(cnpj[i])) {
                valido = 0;
                break;
            }
        }

        if (!valido) {
            mostrar_msg_erro(erro_msg(ERR_CNPJ_DIGITOS));
            continue;
        }

        return; // CNPJ válido lido com sucesso
    }
}

void ler_razao_social(const char *prompt, char *razao_social, size_t tamanho) {
    while (1) {
        mostrar_prompt(prompt);

        // Lê a entrada do usuário
        if (fgets(razao_social, tamanho, stdin) == NULL) {
            mostrar_msg_erro(erro_msg(ERR_LEITURA_RAZAO_SOCIAL_INVALIDA));
            continue;
        }

        // Remove o '\n' da entrada
        razao_social[strcspn(razao_social, "\n")] = '\0';

        // Verifica se a razão social não está vazia
        if (strlen(razao_social) == 0) {
            mostrar_msg_erro(erro_msg(ERR_RAZAO_SOCIAL_VAZIO));
            continue;
        }

        // Converte a razão social para maiúsculas
        to_upper_case(razao_social); 

        return; // Razão social válida lida com sucesso
    }
}

void ler_nome_fantasia(const char *prompt, char *nome_fantasia, size_t tamanho) {
    while (1) {
        mostrar_prompt(prompt);

        // Lê a entrada do usuário
        if (fgets(nome_fantasia, tamanho, stdin) == NULL) {
            mostrar_msg_erro(erro_msg(ERR_LEITURA_NOME_FANTASIA_INVALIDO));
            continue;
        }

        // Remove o '\n' da entrada
        nome_fantasia[strcspn(nome_fantasia, "\n")] = '\0';

        // Verifica se o nome fantasia não está vazio
        if (strlen(nome_fantasia) == 0) {
            mostrar_msg_erro(erro_msg(ERR_NOME_FANTASIA_VAZIO));
            continue;
        }

        // Converte o nome fantasia para maiúsculas
        to_upper_case(nome_fantasia); 

        return; // Nome fantasia válido lido com sucesso
    }
}

void ler_telefone(const char *prompt, char *telefone, size_t tamanho) {
    while (1) {
        mostrar_prompt(prompt);

        // Lê a entrada do usuário
        if (fgets(telefone, tamanho, stdin) == NULL) {
            mostrar_msg_erro(erro_msg(ERR_LEITURA_TELEFONE_INVALIDO));
            continue;
        }

        // Remove o '\n' da entrada
        telefone[strcspn(telefone, "\n")] = '\0';

        // Verifica se o telefone não está vazio
        if (strlen(telefone) == 0) {
            mostrar_msg_erro(erro_msg(ERR_TELEFONE_VAZIO));
            continue;
        }

        // Verifica se o telefone contém apenas dígitos
        int valido = 1;
        for (size_t i = 0; i < strlen(telefone); i++) {
            if (!isdigit(telefone[i])) {
                valido = 0;
                break;
            }
        }

        if (!valido) {
            mostrar_msg_erro(erro_msg(ERR_TELEFONE_DIGITOS));
            continue;
        }

        return; // Telefone válido lido com sucesso
    }
}

void ler_logradouro(const char *prompt, char *logradouro, size_t tamanho) {
    while (1) {
        mostrar_prompt(prompt);

        // Lê a entrada do usuário
        if (fgets(logradouro, tamanho, stdin) == NULL) {
            mostrar_msg_erro(erro_msg(ERR_LEITURA_LOGRADOURO_INVALIDO));
            continue;
        }

        // Remove o '\n' da entrada
        logradouro[strcspn(logradouro, "\n")] = '\0';

        // Verifica se o logradouro não está vazio
        if (strlen(logradouro) == 0) {
            mostrar_msg_erro(erro_msg(ERR_LOGRADOURO_VAZIO));
            continue;
        }

        // Converte o logradouro para maiúsculas
        to_upper_case(logradouro); 

        return; // Logradouro válido lido com sucesso
    }
}

void ler_numero(const char *prompt, char *numero, size_t tamanho) {
    while (1) {
        mostrar_prompt(prompt);

        // Lê a entrada do usuário
        if (fgets(numero, tamanho, stdin) == NULL) {
            mostrar_msg_erro(erro_msg(ERR_LEITURA_NUMERO_INVALIDO));
            continue;
        }

        // Remove o '\n' da entrada
        numero[strcspn(numero, "\n")] = '\0';

        // Verifica se o número não está vazio
        if (strlen(numero) == 0) {
            mostrar_msg_erro(erro_msg(ERR_NUMERO_VAZIO));
            continue;
        }

        // Verifica se o número contém apenas dígitos
        int valido = 1;
        for (size_t i = 0; i < strlen(numero); i++) {
            if (!isdigit(numero[i])) {
                valido = 0;
                break;
            }
        }

        if (!valido) {
            mostrar_msg_erro(erro_msg(ERR_NUMERO_DIGITOS));
            continue;
        }

        return; // Número válido lido com sucesso
    }
}

void ler_bairro(const char *prompt, char *bairro, size_t tamanho) {
    while (1) {
        mostrar_prompt(prompt);

        // Lê a entrada do usuário
        if (fgets(bairro, tamanho, stdin) == NULL) {
            mostrar_msg_erro(erro_msg(ERR_LEITURA_BAIRRO_INVALIDO));
            continue;
        }
        // Remove o '\n' da entrada
        bairro[strcspn(bairro, "\n")] = '\0';

        // Verifica se o bairro não está vazio
        if (strlen(bairro) == 0) {
            mostrar_msg_erro(erro_msg(ERR_BAIRRO_VAZIO));
            continue;
        }

        // Converte o bairro para maiúsculas

        to_upper_case(bairro);
        
        return; // Bairro válido lido com sucesso
    }
}
void ler_cidade(const char *prompt, char *cidade, size_t tamanho) {
    while (1) {
        mostrar_prompt(prompt);

        // Lê a entrada do usuário
        if (fgets(cidade, tamanho, stdin) == NULL) {
            mostrar_msg_erro(erro_msg(ERR_LEITURA_CIDADE_INVALIDA));
            continue;
        }

        // Remove o '\n' da entrada
        cidade[strcspn(cidade, "\n")] = '\0';

        // Verifica se a cidade não está vazia
        if (strlen(cidade) == 0) {
            mostrar_msg_erro(erro_msg(ERR_CIDADE_VAZIA));
            continue;
        }

        // Converte a cidade para maiúsculas
        to_upper_case(cidade); 

        return; // Cidade válida lida com sucesso
    }
}

void ler_estado(const char *prompt, char *estado, size_t tamanho) {
    while (1) {
        mostrar_prompt(prompt);

        // Lê a entrada do usuário
        if (fgets(estado, tamanho, stdin) == NULL) {
            mostrar_msg_erro(erro_msg(ERR_LEITURA_ESTADO_INVALIDO));
            continue;
        }

        // Remove o '\n' da entrada
        estado[strcspn(estado, "\n")] = '\0';

        // Verifica se o estado não está vazio
        if (strlen(estado) == 0) {
            mostrar_msg_erro(erro_msg(ERR_ESTADO_VAZIO));
            continue;
        }

        // Verifica se o estado tem exatamente 2 caracteres
        if (strlen(estado) != 2) {
            mostrar_msg_erro(erro_msg(ERR_ESTADO_COMPRIMENTO));
            continue;
        }

        // Converte o estado para maiúsculas
        to_upper_case(estado); 

        return; // Estado válido lido com sucesso
    }
}
void ler_cep(const char *prompt, char *cep, size_t tamanho) {
    while (1) {
        mostrar_prompt(prompt);

        // Lê a entrada do usuário
        if (fgets(cep, tamanho, stdin) == NULL) {
            mostrar_msg_erro(erro_msg(ERR_LEITURA_CEP_INVALIDO));
            continue;
        }

        // Remove o '\n' da entrada
        cep[strcspn(cep, "\n")] = '\0';

        // Verifica se o CEP não está vazio
        if (strlen(cep) == 0) {
            mostrar_msg_erro(erro_msg(ERR_CEP_VAZIO));
            continue;
        }

        // Verifica se o CEP contém apenas dígitos
        int valido = 1;
        for (size_t i = 0; i < strlen(cep); i++) {
            if (!isdigit(cep[i])) {
                valido = 0;
                break;
            }
        }

        if (!valido) {
            mostrar_msg_erro(erro_msg(ERR_CEP_DIGITOS));
            continue;
        }

        return; // CEP válido lido com sucesso
    }
}
void ler_data_abertura(const char *prompt, char *data_abertura, size_t tamanho) {
    while (1) {
        mostrar_prompt(prompt);

        // Lê a entrada do usuário
        if (fgets(data_abertura, tamanho, stdin) == NULL) {
            mostrar_msg_erro(erro_msg(ERR_LEITURA_INVALIDA));
            continue;
        }

        // Remove o '\n' da entrada
        data_abertura[strcspn(data_abertura, "\n")] = '\0';

        // Verifica se a entrada está vazia
        if (strlen(data_abertura) == 0) {
            mostrar_msg_erro(erro_msg(ERR_DATA_INVALIDA));
            continue;
        }

        // Verifica o formato básico (dd/mm/aaaa)
        if (strlen(data_abertura) != 10 || data_abertura[2] != '/' || data_abertura[5] != '/') {
            mostrar_msg_erro(erro_msg(ERR_FORMATO_DATA));
            continue;
        }

        // Extrai o dia, mês e ano da string
        int dia, mes, ano;
        if (sscanf(data_abertura, "%2d/%2d/%4d", &dia, &mes, &ano) != 3) {
            mostrar_msg_erro(erro_msg(ERR_FORMATO_DATA));
            continue;
        }

        // Valida o intervalo do mês e do ano
        if (mes < 1 || mes > 12) {
            mostrar_msg_erro(erro_msg(ERR_DATA_INVALIDA_MES));
            continue;
        }
        if (ano < 1900 || ano > 2100) {
            mostrar_msg_erro(erro_msg(ERR_DATA_INVALIDA_ANO));
            continue;
        }

        // Valida o dia com base no mês e ano (considera anos bissextos)
        struct tm data = {0};
        data.tm_mday = dia;
        data.tm_mon = mes - 1; // `tm_mon` vai de 0 a 11
        data.tm_year = ano - 1900; // `tm_year` é o número de anos desde 1900

        // Usa `mktime` para validar a data
        if (mktime(&data) == -1 || data.tm_mday != dia || data.tm_mon != mes - 1 || data.tm_year != ano - 1900) {
            mostrar_msg_erro(erro_msg(ERR_DATA_INVALIDA));
            continue;
        }
        
        return; // Data válida lida com sucesso
    }
}

// Remove o '\n' da entrada, se existir
void remover_newline(char *str) {
    str[strcspn(str, "\n")] = '\0';
}

// Verifica se a string contém apenas dígitos
int contem_apenas_digitos(const char *str) {
    for (size_t i = 0; i < strlen(str); i++) {
        if (!isdigit(str[i])) {
            return 0; // Não é um dígito
        }
    }
    return 1; // Apenas dígitos
}

// Verifica se a string está vazia
int entrada_vazia(const char *str) {
    return strlen(str) == 0;
}

int ler_string(const char *prompt, char *buffer, size_t tamanho) {
    while (1) {
        mostrar_prompt(prompt);

        // Lê a entrada do usuário
        if (fgets(buffer, tamanho, stdin) == NULL) {
            mostrar_msg_erro(erro_msg(ERR_LEITURA_INVALIDA));
            continue;
        }

        // Remove o '\n' da entrada
        remover_newline(buffer);

        // Verifica se a entrada está vazia
        if (entrada_vazia(buffer)) {
            mostrar_msg_erro(erro_msg(ERR_LEITURA_INVALIDA));
            continue;
        }

        return 1; // Entrada válida
    }
}
