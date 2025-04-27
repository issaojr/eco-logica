
#include "entrada_ui.h"

/**
 * * @brief L� uma op��o do usu�rio, repetindo at� receber um valor v�lido.
 * * @param prompt Texto a exibir antes da leitura.
 * * @param opcoes_validas Array de op��es v�lidas.
 */
int ler_opcao(const char *prompt, const int *opcoes_validas, size_t num_opcoes) {
    char buf[32];
    long v;
    char *endptr;

    // Loop infinito para ler a op��o do usu�rio
    while (1) {
        if (prompt == NULL) {
            prompt = ">> Op��o: ";
        }
        printf("%s", prompt);

        // L� a entrada do usu�rio
        if (!fgets(buf, sizeof buf, stdin)) {
            // Ignora a leitura inv�lida e continua o loop
            continue;
        }

        // Remove o '\n' da entrada
        buf[strcspn(buf, "\n")] = '\0';

        // Converte a entrada para um n�mero
        v = strtol(buf, &endptr, 10);

        // Verifica se a entrada � um n�mero v�lido
        if (*endptr != '\0') {
            mostrar_msg_erro(erro_msg(ERR_OPCAO_INVALIDA_NUMERICA));
            continue;
        }

        // Verifica se o n�mero est� na lista de op��es v�lidas
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

        return (int)v; // Retorna a op��o v�lida
    }
}



/**
 * @brief L� a matr�cula do usu�rio, validando se � um n�mero inteiro de at� 6 d�gitos.
 * @return A matr�cula v�lida.
 */
int ler_matricula(const char *prompt) {
    int matricula;
    char buf[16]; // Buffer para entrada do usu�rio

    while (1) {
        printf(">> Digite a matr�cula do novo usu�rio (at� 6 d�gitos): ");
        
        // L� a entrada como string para valida��o
        if (!fgets(buf, sizeof(buf), stdin)) {
            mostrar_msg_erro(erro_msg(ERR_LEITURA_INVALIDA));
            continue;
        }

        // Remove o '\n' da entrada
        buf[strcspn(buf, "\n")] = '\0';

        // Verifica se a entrada � um n�mero v�lido
        char *endptr;
        matricula = strtol(buf, &endptr, 10);

        if (*endptr != '\0' || matricula < 0 || matricula > 999999) {
            mostrar_msg_erro(erro_msg(ERR_MATRICULA_INVALIDA));
            continue;
        }

        return matricula; // Retorna a matr�cula v�lida
    }
}

void ler_nome(const char *prompt, char *nome, size_t tamanho)
{
    while (1) {
        mostrar_prompt(prompt);
        
        // L� a entrada do usu�rio
        if (fgets(nome, tamanho, stdin) == NULL) {
            mostrar_msg_erro(erro_msg(ERR_LEITURA_NOME_INVALIDO));
            continue;
        }

        // Remove o '\n' da entrada
        nome[strcspn(nome, "\n")] = '\0';

        // Verifica se o nome n�o est� vazio
        if (strlen(nome) == 0) {
            mostrar_msg_erro(erro_msg(ERR_NOME_VAZIO));
            continue;
        }

        // Converte o nome para mai�sculas
        to_upper_case(nome);

        return; // Nome v�lido lido com sucesso
    }
}

void ler_senha(const char *prompt, char *senha, size_t tamanho) {
    while (1) {
        mostrar_prompt(prompt);

        // L� a entrada como string
        if (fgets(senha, tamanho, stdin) == NULL) {
            mostrar_msg_erro(erro_msg(ERR_LEITURA_SENHA_INVALIDA));
            continue;
        }

        // Remove o '\n' da entrada
        senha[strcspn(senha, "\n")] = '\0';

        // Verifica se a senha n�o est� vazia
        if (strlen(senha) == 0) {
            mostrar_msg_erro(erro_msg(ERR_SENHA_VAZIA));
            continue;
        }

        return; // Senha v�lida lida com sucesso
    }
}

void ler_email(const char *prompt, char *email, size_t tamanho) {
    while (1) {
        mostrar_prompt(prompt);

        // L� a entrada do usu�rio
        if (fgets(email, tamanho, stdin) == NULL) {
            mostrar_msg_erro(erro_msg(ERR_LEITURA_INVALIDA));
            continue;
        }

        // Remove o '\n' da entrada
        email[strcspn(email, "\n")] = '\0';

        // Verifica se o e-mail n�o est� vazio
        if (strlen(email) == 0) {
            mostrar_msg_erro(erro_msg(ERR_EMAIL_INVALIDO));
            continue;
        }

        // Valida o formato b�sico do e-mail (deve conter '@' e '.')
        if (strchr(email, '@') == NULL || strchr(email, '.') == NULL) {
            mostrar_msg_erro(erro_msg(ERR_EMAIL_INVALIDO));
            continue;
        }

        return; // E-mail v�lido lido com sucesso
    }
}

void ler_cnpj(const char *prompt, char *cnpj, size_t tamanho) {
    while (1) {
        mostrar_prompt(prompt);

        // L� a entrada do usu�rio
        if (fgets(cnpj, tamanho, stdin) == NULL) {
            mostrar_msg_erro(erro_msg(ERR_LEITURA_INVALIDA));
            continue;
        }

        // Remove o '\n' da entrada
        cnpj[strcspn(cnpj, "\n")] = '\0';

        // Verifica se o CNPJ n�o est� vazio
        if (strlen(cnpj) == 0) {
            mostrar_msg_erro(erro_msg(ERR_CNPJ_VAZIO));
            continue;
        }

        // Valida o comprimento do CNPJ (14 d�gitos sem formata��o)
        if (strlen(cnpj) != 14) {
            mostrar_msg_erro(erro_msg(ERR_CNPJ_COMPRIMENTO));
            continue;
        }

        // Verifica se todos os caracteres s�o d�gitos
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

        return; // CNPJ v�lido lido com sucesso
    }
}

void ler_razao_social(const char *prompt, char *razao_social, size_t tamanho) {
    while (1) {
        mostrar_prompt(prompt);

        // L� a entrada do usu�rio
        if (fgets(razao_social, tamanho, stdin) == NULL) {
            mostrar_msg_erro(erro_msg(ERR_LEITURA_RAZAO_SOCIAL_INVALIDA));
            continue;
        }

        // Remove o '\n' da entrada
        razao_social[strcspn(razao_social, "\n")] = '\0';

        // Verifica se a raz�o social n�o est� vazia
        if (strlen(razao_social) == 0) {
            mostrar_msg_erro(erro_msg(ERR_RAZAO_SOCIAL_VAZIO));
            continue;
        }

        // Converte a raz�o social para mai�sculas
        to_upper_case(razao_social); 

        return; // Raz�o social v�lida lida com sucesso
    }
}

void ler_nome_fantasia(const char *prompt, char *nome_fantasia, size_t tamanho) {
    while (1) {
        mostrar_prompt(prompt);

        // L� a entrada do usu�rio
        if (fgets(nome_fantasia, tamanho, stdin) == NULL) {
            mostrar_msg_erro(erro_msg(ERR_LEITURA_NOME_FANTASIA_INVALIDO));
            continue;
        }

        // Remove o '\n' da entrada
        nome_fantasia[strcspn(nome_fantasia, "\n")] = '\0';

        // Verifica se o nome fantasia n�o est� vazio
        if (strlen(nome_fantasia) == 0) {
            mostrar_msg_erro(erro_msg(ERR_NOME_FANTASIA_VAZIO));
            continue;
        }

        // Converte o nome fantasia para mai�sculas
        to_upper_case(nome_fantasia); 

        return; // Nome fantasia v�lido lido com sucesso
    }
}

void ler_telefone(const char *prompt, char *telefone, size_t tamanho) {
    while (1) {
        mostrar_prompt(prompt);

        // L� a entrada do usu�rio
        if (fgets(telefone, tamanho, stdin) == NULL) {
            mostrar_msg_erro(erro_msg(ERR_LEITURA_TELEFONE_INVALIDO));
            continue;
        }

        // Remove o '\n' da entrada
        telefone[strcspn(telefone, "\n")] = '\0';

        // Verifica se o telefone n�o est� vazio
        if (strlen(telefone) == 0) {
            mostrar_msg_erro(erro_msg(ERR_TELEFONE_VAZIO));
            continue;
        }

        // Verifica se o telefone cont�m apenas d�gitos
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

        return; // Telefone v�lido lido com sucesso
    }
}

void ler_logradouro(const char *prompt, char *logradouro, size_t tamanho) {
    while (1) {
        mostrar_prompt(prompt);

        // L� a entrada do usu�rio
        if (fgets(logradouro, tamanho, stdin) == NULL) {
            mostrar_msg_erro(erro_msg(ERR_LEITURA_LOGRADOURO_INVALIDO));
            continue;
        }

        // Remove o '\n' da entrada
        logradouro[strcspn(logradouro, "\n")] = '\0';

        // Verifica se o logradouro n�o est� vazio
        if (strlen(logradouro) == 0) {
            mostrar_msg_erro(erro_msg(ERR_LOGRADOURO_VAZIO));
            continue;
        }

        // Converte o logradouro para mai�sculas
        to_upper_case(logradouro); 

        return; // Logradouro v�lido lido com sucesso
    }
}

void ler_numero(const char *prompt, char *numero, size_t tamanho) {
    while (1) {
        mostrar_prompt(prompt);

        // L� a entrada do usu�rio
        if (fgets(numero, tamanho, stdin) == NULL) {
            mostrar_msg_erro(erro_msg(ERR_LEITURA_NUMERO_INVALIDO));
            continue;
        }

        // Remove o '\n' da entrada
        numero[strcspn(numero, "\n")] = '\0';

        // Verifica se o n�mero n�o est� vazio
        if (strlen(numero) == 0) {
            mostrar_msg_erro(erro_msg(ERR_NUMERO_VAZIO));
            continue;
        }

        // Verifica se o n�mero cont�m apenas d�gitos
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

        return; // N�mero v�lido lido com sucesso
    }
}

void ler_bairro(const char *prompt, char *bairro, size_t tamanho) {
    while (1) {
        mostrar_prompt(prompt);

        // L� a entrada do usu�rio
        if (fgets(bairro, tamanho, stdin) == NULL) {
            mostrar_msg_erro(erro_msg(ERR_LEITURA_BAIRRO_INVALIDO));
            continue;
        }
        // Remove o '\n' da entrada
        bairro[strcspn(bairro, "\n")] = '\0';

        // Verifica se o bairro n�o est� vazio
        if (strlen(bairro) == 0) {
            mostrar_msg_erro(erro_msg(ERR_BAIRRO_VAZIO));
            continue;
        }

        // Converte o bairro para mai�sculas

        to_upper_case(bairro);
        
        return; // Bairro v�lido lido com sucesso
    }
}
void ler_cidade(const char *prompt, char *cidade, size_t tamanho) {
    while (1) {
        mostrar_prompt(prompt);

        // L� a entrada do usu�rio
        if (fgets(cidade, tamanho, stdin) == NULL) {
            mostrar_msg_erro(erro_msg(ERR_LEITURA_CIDADE_INVALIDA));
            continue;
        }

        // Remove o '\n' da entrada
        cidade[strcspn(cidade, "\n")] = '\0';

        // Verifica se a cidade n�o est� vazia
        if (strlen(cidade) == 0) {
            mostrar_msg_erro(erro_msg(ERR_CIDADE_VAZIA));
            continue;
        }

        // Converte a cidade para mai�sculas
        to_upper_case(cidade); 

        return; // Cidade v�lida lida com sucesso
    }
}

void ler_estado(const char *prompt, char *estado, size_t tamanho) {
    while (1) {
        mostrar_prompt(prompt);

        // L� a entrada do usu�rio
        if (fgets(estado, tamanho, stdin) == NULL) {
            mostrar_msg_erro(erro_msg(ERR_LEITURA_ESTADO_INVALIDO));
            continue;
        }

        // Remove o '\n' da entrada
        estado[strcspn(estado, "\n")] = '\0';

        // Verifica se o estado n�o est� vazio
        if (strlen(estado) == 0) {
            mostrar_msg_erro(erro_msg(ERR_ESTADO_VAZIO));
            continue;
        }

        // Verifica se o estado tem exatamente 2 caracteres
        if (strlen(estado) != 2) {
            mostrar_msg_erro(erro_msg(ERR_ESTADO_COMPRIMENTO));
            continue;
        }

        // Converte o estado para mai�sculas
        to_upper_case(estado); 

        return; // Estado v�lido lido com sucesso
    }
}
void ler_cep(const char *prompt, char *cep, size_t tamanho) {
    while (1) {
        mostrar_prompt(prompt);

        // L� a entrada do usu�rio
        if (fgets(cep, tamanho, stdin) == NULL) {
            mostrar_msg_erro(erro_msg(ERR_LEITURA_CEP_INVALIDO));
            continue;
        }

        // Remove o '\n' da entrada
        cep[strcspn(cep, "\n")] = '\0';

        // Verifica se o CEP n�o est� vazio
        if (strlen(cep) == 0) {
            mostrar_msg_erro(erro_msg(ERR_CEP_VAZIO));
            continue;
        }

        // Verifica se o CEP cont�m apenas d�gitos
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

        return; // CEP v�lido lido com sucesso
    }
}
void ler_data_abertura(const char *prompt, char *data_abertura, size_t tamanho) {
    while (1) {
        mostrar_prompt(prompt);

        // L� a entrada do usu�rio
        if (fgets(data_abertura, tamanho, stdin) == NULL) {
            mostrar_msg_erro(erro_msg(ERR_LEITURA_INVALIDA));
            continue;
        }

        // Remove o '\n' da entrada
        data_abertura[strcspn(data_abertura, "\n")] = '\0';

        // Verifica se a entrada est� vazia
        if (strlen(data_abertura) == 0) {
            mostrar_msg_erro(erro_msg(ERR_DATA_INVALIDA));
            continue;
        }

        // Verifica o formato b�sico (dd/mm/aaaa)
        if (strlen(data_abertura) != 10 || data_abertura[2] != '/' || data_abertura[5] != '/') {
            mostrar_msg_erro(erro_msg(ERR_FORMATO_DATA));
            continue;
        }

        // Extrai o dia, m�s e ano da string
        int dia, mes, ano;
        if (sscanf(data_abertura, "%2d/%2d/%4d", &dia, &mes, &ano) != 3) {
            mostrar_msg_erro(erro_msg(ERR_FORMATO_DATA));
            continue;
        }

        // Valida o intervalo do m�s e do ano
        if (mes < 1 || mes > 12) {
            mostrar_msg_erro(erro_msg(ERR_DATA_INVALIDA_MES));
            continue;
        }
        if (ano < 1900 || ano > 2100) {
            mostrar_msg_erro(erro_msg(ERR_DATA_INVALIDA_ANO));
            continue;
        }

        // Valida o dia com base no m�s e ano (considera anos bissextos)
        struct tm data = {0};
        data.tm_mday = dia;
        data.tm_mon = mes - 1; // `tm_mon` vai de 0 a 11
        data.tm_year = ano - 1900; // `tm_year` � o n�mero de anos desde 1900

        // Usa `mktime` para validar a data
        if (mktime(&data) == -1 || data.tm_mday != dia || data.tm_mon != mes - 1 || data.tm_year != ano - 1900) {
            mostrar_msg_erro(erro_msg(ERR_DATA_INVALIDA));
            continue;
        }
        
        return; // Data v�lida lida com sucesso
    }
}

// Remove o '\n' da entrada, se existir
void remover_newline(char *str) {
    str[strcspn(str, "\n")] = '\0';
}

// Verifica se a string cont�m apenas d�gitos
int contem_apenas_digitos(const char *str) {
    for (size_t i = 0; i < strlen(str); i++) {
        if (!isdigit(str[i])) {
            return 0; // N�o � um d�gito
        }
    }
    return 1; // Apenas d�gitos
}

// Verifica se a string est� vazia
int entrada_vazia(const char *str) {
    return strlen(str) == 0;
}

int ler_string(const char *prompt, char *buffer, size_t tamanho) {
    while (1) {
        mostrar_prompt(prompt);

        // L� a entrada do usu�rio
        if (fgets(buffer, tamanho, stdin) == NULL) {
            mostrar_msg_erro(erro_msg(ERR_LEITURA_INVALIDA));
            continue;
        }

        // Remove o '\n' da entrada
        remover_newline(buffer);

        // Verifica se a entrada est� vazia
        if (entrada_vazia(buffer)) {
            mostrar_msg_erro(erro_msg(ERR_LEITURA_INVALIDA));
            continue;
        }

        return 1; // Entrada v�lida
    }
}
