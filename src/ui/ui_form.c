#include "ui/ui_form.h"

/* ---------- utilidades ------------------------------------------- */
void strip_newline(char *s)
{
    size_t n = strlen(s);
    if (n && s[n - 1] == '\n')
        s[n - 1] = '\0';
}

/* ---------- prompt ----------------------------------------------- */
char *ui_prompt_form_str(char *prompt_str)
{
    static char prompt[UI_TAMANHO_MAX_MSG];
    snprintf(prompt, sizeof(prompt), "%s>> %s: %s", UI_COR_PROMPT_FORM, prompt_str, UI_COR_RESET);
    return prompt;
}

/* ---------- transformadores--------------------------------------- */

/* Esta função manipula diretamente bytes UTF-8 para converter para maiúsculas,
 * sem depender das configurações de locale do sistema. Isso garante funcionamento
 * consistente em diferentes ambientes Windows e Linux.
 */
void transformar_maiusculo(char *s)
{
    if (!s) return;

    unsigned char *p = (unsigned char*)s;

    while (*p)
    {
        // Caracteres ASCII simples
        if (*p < 128)
        {
            *p = toupper(*p);
            p++;
            continue;
        }

        // UTF-8: primeiro byte de uma sequência multibyte
        if ((*p & 0xE0) == 0xC0)
        {
            // 2 bytes (110xxxxx)
            if (p[0] == 0xC3)
            {
                // Latin-1 Supplement em UTF-8
                switch (p[1])
                {
                // Minúsculas para maiúsculas
                case 0xA1: p[1] = 0x81;
                    break; // á -> Á
                case 0xA0: p[1] = 0x80;
                    break; // à -> À
                case 0xA2: p[1] = 0x82;
                    break; // â -> Â
                case 0xA3: p[1] = 0x83;
                    break; // ã -> Ã
                case 0xA9: p[1] = 0x89;
                    break; // é -> É
                case 0xA8: p[1] = 0x88;
                    break; // è -> È
                case 0xAA: p[1] = 0x8A;
                    break; // ê -> Ê
                case 0xAD: p[1] = 0x8D;
                    break; // í -> Í
                case 0xAC: p[1] = 0x8C;
                    break; // ì -> Ì
                case 0xB3: p[1] = 0x93;
                    break; // ó -> Ó
                case 0xB2: p[1] = 0x92;
                    break; // ò -> Ò
                case 0xB4: p[1] = 0x94;
                    break; // ô -> Ô
                case 0xB5: p[1] = 0x95;
                    break; // õ -> Õ
                case 0xBA: p[1] = 0x9A;
                    break; // ú -> Ú
                case 0xB9: p[1] = 0x99;
                    break; // ù -> Ù
                case 0xBB: p[1] = 0x9B;
                    break; // û -> Û
                case 0xA7: p[1] = 0x87;
                    break; // ç -> Ç
                }
            }
            p += 2; // Avança 2 bytes
        }
        else if ((*p & 0xF0) == 0xE0)
        {
            // 3 bytes (1110xxxx)
            p += 3;
        }
        else if ((*p & 0xF8) == 0xF0)
        {
            // 4 bytes (11110xxx)
            p += 4;
        }
        else
        {
            // Byte inválido, avança com segurança
            p++;
        }
    }
}

void transformar_minusculo(char *s)
{
    for (; *s; s++)
        *s = tolower((unsigned char)*s);
}

/* ---------- validadores ------------------------------------------ */
bool validar_matricula(char *matricula)
{
    if (strlen(matricula) != 6)
        return false;
    for (int i = 0; i < 6; ++i)
        if (!isdigit((unsigned char)matricula[i]))
            return false;
    return true;
}

bool validar_nome(char *nome)
{
    int count_letras = 0;
    size_t i = 0, n = strlen(nome);

    while (i < n)
    {
        unsigned char c = (unsigned char)nome[i];

        if (c < 0x80)
        {
            // ASCII
            if (isalpha(c))
            {
                count_letras++;
            }
            else if (c == ' ' || c == '-' || c == '\'')
            {
                // ok
            }
            else
            {
                return false; // dígito ou pontuação proibida
            }
            i++;
        }
        else
        {
            // possível início de multibyte UTF-8
            int seqlen;
            if ((c & 0xE0) == 0xC0) seqlen = 2;
            else if ((c & 0xF0) == 0xE0) seqlen = 3;
            else if ((c & 0xF8) == 0xF0) seqlen = 4;
            else return false; // byte inválido

            // verifica bytes de continuação: 10xxxxxx
            for (int j = 1; j < seqlen; j++)
            {
                if (i + j >= n || ((nome[i + j] & 0xC0) != 0x80))
                    return false;
            }
            // conta como uma letra “qualquer” (você pode filtrar códigos específicos se quiser)
            count_letras++;
            i += seqlen;
        }
    }

    return (count_letras >= 3);
}

bool validar_senha(char *senha)
{
    if (strlen(senha) < 6)
        return false;
    for (int i = 0; senha[i]; ++i)
        if (!isalnum((unsigned char)senha[i]))
            return false;
    return true;
}

bool validar_nao_vazio(char *s)
{
    return *s != '\0';
}

bool validar_cnpj(char *cnpj)
{
    if (strlen(cnpj) != 14)
        return false;
    for (int i = 0; i < 14; ++i)
        if (!isdigit((unsigned char)cnpj[i]))
            return false;
    return true;
}

bool validar_cep(char *cep)
{
    if (strlen(cep) != 8)
        return false;
    for (int i = 0; i < 8; ++i)
        if (!isdigit((unsigned char)cep[i]))
            return false;
    return true;
}

bool validar_uf(char *uf)
{
    /* precisa ter exatamente 2 chars */
    if (strlen(uf) != 2)
        return false;

    const char s[3] = { uf[0], uf[1], '\0' };

    /* lista de UFs válidas */
    static const char *lista_ufs[] = {
        "AC","AL","AP","AM","BA","CE","DF","ES","GO","MA","MT","MS",
        "MG","PA","PB","PR","PE","PI","RJ","RN","RS","RO","RR","SC",
        "SP","SE","TO"
    };

    /* busca na lista */
    for (size_t i = 0; i < sizeof(lista_ufs)/sizeof(lista_ufs[0]); i++) {
        if (strcmp(s, lista_ufs[i]) == 0)
            return true;
    }

    return false;
}

bool validar_telefone(char *tel)
{
    size_t n = 0;
    for (const char *p = tel; *p; ++p)
        if (isdigit((unsigned char)*p))
            ++n;
    return n >= 8;
}

bool validar_email(char *e)
{
    char *arroba = strchr(e, '@');
    char *ponto = strrchr(e, '.');
    return arroba && ponto && arroba < ponto && ponto[1] != '\0';
}

static bool is_bissexto(int y)
{
    return (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0));
}

bool validar_data(char *data) /* dd/mm/aaaa */
{
    if (strlen(data) != 10 || data[2] != '/' || data[5] != '/')
        return false;

    int d = atoi(data);
    int m = atoi(data + 3);
    int y = atoi(data + 6);

    if (d < 1 || m < 1 || m > 12 || y < 1900)
        return false;

    /* dias máximos por mês */
    static const int dias_no_mes[] = {
        0, 31, /* jan */
        28, /* fev */
        31, /* mar */
        30, /* abr */
        31, /* mai */
        30, /* jun */
        31, /* jul */
        31, /* ago */
        30, /* set */
        31, /* out */
        30, /* nov */
        31 /* dez */
    };

    int max = dias_no_mes[m];
    if (m == 2 && is_bissexto(y))
        max = 29;

    return d <= max;
}

bool validar_mes(char *mes_str)
{
    if (strlen(mes_str) == 0 || strlen(mes_str) > 2)
        return false;
    
    for (size_t i = 0; i < strlen(mes_str); i++)
        if (!isdigit((unsigned char)mes_str[i]))
            return false;
    
    int mes = atoi(mes_str);
    return mes >= 1 && mes <= 12;
}

bool validar_ano(char *ano_str)
{
    if (strlen(ano_str) != 4)
        return false;
    
    for (int i = 0; i < 4; i++)
        if (!isdigit((unsigned char)ano_str[i]))
            return false;
    
    int ano = atoi(ano_str);
    return ano >= 1900 && ano <= 2100;
}

bool validar_quantidade(char *quantidade_str)
{
    if (strlen(quantidade_str) == 0)
        return false;
    
    char *endptr;
    double valor = strtod(quantidade_str, &endptr);
    
    // Verifica se a conversão foi bem-sucedida e se o valor é positivo
    return (endptr != quantidade_str && *endptr == '\0' && valor >= 0.0);
}

bool validar_custo(char *custo_str)
{
    if (strlen(custo_str) == 0)
        return false;
    
    char *endptr;
    double valor = strtod(custo_str, &endptr);
    
    // Verifica se a conversão foi bem-sucedida e se o valor é positivo
    return (endptr != custo_str && *endptr == '\0' && valor >= 0.0);
}

/* ---------- leitor genérico com descarte de "resto de linha" ------ */
void ui_ler_campo(
    char *prompt,
    char *buf,
    size_t sz,
    bool (*validador)(char *),
    char *msg_erro,
    void (*transformar)(char *))
{
    do
    {
        printf("%s", ui_prompt_form_str(prompt));

        if (fgets(buf, (int)sz, stdin) == NULL)
            exit(EXIT_FAILURE);

        size_t len = strlen(buf);
        if (len > 0 && buf[len - 1] != '\n')
            ui_limpar_entrada();

        strip_newline(buf);

        trim(buf);

        colapsar_espacos(buf);

        if (transformar)
            transformar(buf);

        if (validador(buf))
            return;

        ui_exibir_erro(msg_erro);
    }
    while (true);
}

void ui_ler_matricula_funcionario(char *matricula, size_t tamanho)
{
    ui_ler_campo(
        "Matrícula",
        matricula,
        tamanho,
        validar_matricula,
        "Matrícula deve ter 6 dígitos",
        NULL);
}

void ui_ler_nome_funcionario(char *nome, size_t tamanho)
{
    ui_ler_campo(
        "Nome",
        nome,
        tamanho,
        validar_nome,
        "Nome deve ter pelo menos 3 letras e não pode conter números",
        transformar_maiusculo);
}

void ui_ler_senha_funcionario(char *senha, size_t tamanho)
{
    ui_ler_campo(
        "Senha",
        senha,
        tamanho,
        validar_senha,
        "Senha deve ter pelo menos 6 caracteres alfanuméricos",
        NULL);

    ui_converter_str_hash(senha, tamanho);
}

void ui_converter_str_hash(char *senha, size_t tamanho)
{
    char hash[64];
    hash_senha(senha, hash, HASH_KEY);
    
    strncpy(senha, hash, tamanho);
    senha[tamanho - 1] = '\0'; /* Garantir terminação nula */
}

void ui_exibir_form_funcionario(funcionario_t *f)
{
    //ui_ler_matricula_funcionario(f->matricula, sizeof(f->matricula));
    ui_ler_nome_funcionario(f->nome, sizeof(f->nome));

    ui_ler_senha_funcionario(f->hash_senha, sizeof(f->hash_senha));
}

/* ---------- leitores específicos de industria ----------------------- */
void ui_ler_cnpj_industria(char *b, size_t s)
{
    ui_ler_campo(
        "CNPJ",
        b,
        s,
        validar_cnpj,
        "CNPJ deve ter 14 dígitos",
        transformar_maiusculo);
}

void ui_ler_razao_social_industria(char *b, size_t s)
{
    ui_ler_campo(
        "Razão social",
        b,
        s,
        validar_nome,
        "Campo obrigatório",
        transformar_maiusculo);
}

void ui_ler_nome_fantasia_industria(char *b, size_t s)
{
    ui_ler_campo(
        "Nome fantasia",
        b,
        s,
        validar_nome,
        "Campo obrigatório",
        transformar_maiusculo);
}

void ui_ler_telefone_industria(char *b, size_t s)
{
    ui_ler_campo(
        "Telefone",
        b,
        s,
        validar_telefone,
        "Informe ao menos 8 dígitos",
        transformar_maiusculo);
}

void ui_ler_logradouro_industria(char *b, size_t s)
{
    ui_ler_campo(
        "Logradouro",
        b,
        s,
        validar_nao_vazio,
        "Campo obrigatório",
        transformar_maiusculo);
}

void ui_ler_numero_industria(char *b, size_t s)
{
    ui_ler_campo(
        "Número",
        b,
        s,
        validar_nao_vazio,
        "Campo obrigatório",
        transformar_maiusculo);
}

void ui_ler_bairro_industria(char *b, size_t s)
{
    ui_ler_campo(
        "Bairro",
        b,
        s,
        validar_nome,
        "Campo obrigatório",
        transformar_maiusculo);
}

void ui_ler_cidade_industria(char *b, size_t s)
{
    ui_ler_campo(
        "Cidade",
        b,
        s,
        validar_nome,
        "Campo obrigatório",
        transformar_maiusculo);
}

void ui_ler_estado_industria(char *b, size_t s)
{
    ui_ler_campo(
        "UF (ex: SP)",
        b,
        s,
        validar_uf,
        "UF inválida",
        transformar_maiusculo);
    b[0] = (char)toupper((unsigned char)b[0]);
    b[1] = (char)toupper((unsigned char)b[1]);
}

void ui_ler_cep_industria(char *b, size_t s)
{
    ui_ler_campo(
        "CEP",
        b,
        s,
        validar_cep,
        "CEP deve ter 8 dígitos",
        transformar_maiusculo);
}

void ui_ler_data_abertura_industria(char *b, size_t s)
{
    ui_ler_campo(
        "Data de abertura",
        b,
        s,
        validar_data,
        "Formato DD/MM/AAAA inválido",
        transformar_maiusculo);
}

void ui_ler_nome_responsavel_industria(char *b, size_t s)
{
    ui_ler_campo(
        "Responsável",
        b,
        s,
        validar_nao_vazio,
        "Campo obrigatório",
        transformar_maiusculo);
}

void ui_ler_email_responsavel_industria(char *b, size_t s)
{
    ui_ler_campo(
        "E-mail responsável",
        b,
        s,
        validar_email,
        "E-mail inválido",
        transformar_minusculo);
}

/* ---------- formulário completo ---------------------------------- */
void ui_exibir_form_industria(industria_t *i)
{
    /* O CNPJ deve ser lido à parte */
    ui_ler_razao_social_industria(i->razao_social, sizeof i->razao_social);
    ui_ler_nome_fantasia_industria(i->nome_fantasia, sizeof i->nome_fantasia);
    ui_ler_telefone_industria(i->telefone, sizeof i->telefone);
    ui_ler_logradouro_industria(i->logradouro, sizeof i->logradouro);
    ui_ler_numero_industria(i->numero, sizeof i->numero);
    ui_ler_bairro_industria(i->bairro, sizeof i->bairro);
    ui_ler_cidade_industria(i->cidade, sizeof i->cidade);
    ui_ler_estado_industria(i->estado, sizeof i->estado);
    ui_ler_cep_industria(i->cep, sizeof i->cep);
    ui_ler_data_abertura_industria(i->data_abertura, sizeof i->data_abertura);
    ui_ler_nome_responsavel_industria(i->nome_responsavel, sizeof i->nome_responsavel);
    ui_ler_email_responsavel_industria(i->email_responsavel, sizeof i->email_responsavel);
}

/* ---------- leitores específicos de resíduos ---------------------- */

void ui_ler_mes_residuos(int *mes, size_t tamanho)
{
    char mes_str[4];
    ui_ler_campo(
        "Mês (1-12)",
        mes_str,
        sizeof(mes_str),
        validar_mes,
        "Mês deve ser um número entre 1 e 12",
        NULL);
    
    *mes = atoi(mes_str);
}

void ui_ler_ano_residuos(int *ano, size_t tamanho)
{
    char ano_str[6];
    ui_ler_campo(
        "Ano (AAAA)",
        ano_str,
        sizeof(ano_str),
        validar_ano,
        "Ano deve ter 4 dígitos (ex: 2024)",
        NULL);
    
    *ano = atoi(ano_str);
}

void ui_ler_quantidade_residuos(double *quantidade, size_t tamanho)
{
    char quantidade_str[32];
    ui_ler_campo(
        "Quantidade (kg)",
        quantidade_str,
        sizeof(quantidade_str),
        validar_quantidade,
        "Quantidade deve ser um valor numérico positivo",
        NULL);
    
    *quantidade = strtod(quantidade_str, NULL);
}

void ui_ler_custo_residuos(double *custo, size_t tamanho)
{
    char custo_str[32];
    ui_ler_campo(
        "Custo (R$)",
        custo_str,
        sizeof(custo_str),
        validar_custo,
        "Custo deve ser um valor numérico positivo",
        NULL);
    
    *custo = strtod(custo_str, NULL);
}

/* ---------- formulário completo - resíduos ---------------------- */

void ui_exibir_form_residuos(residuo_t *r)
{
    /* O CNPJ deve ser lido à parte */
    ui_ler_mes_residuos(&r->mes, sizeof(r->mes));
    ui_ler_ano_residuos(&r->ano, sizeof(r->ano));
    ui_ler_quantidade_residuos(&r->quantidade, sizeof(r->quantidade));
    ui_ler_custo_residuos(&r->custo, sizeof(r->custo));
}