#include "ui/ui_form.h"

/* ---------- utilidades ------------------------------------------- */
void strip_newline(char *s)
{
    size_t n = strlen(s);
    if (n && s[n - 1] == '\n')
        s[n - 1] = '\0';
}

/* ---------- prompt ----------------------------------------------- */
char *ui_prompt_form_str(const char *prompt_str)
{
    static char prompt[UI_TAMANHO_MAX_MSG];
    snprintf(prompt, sizeof(prompt), "%s>> %s: %s", UI_COR_PROMPT_FORM, prompt_str, UI_COR_RESET);
    return prompt;
}

/* ---------- transformadores--------------------------------------- */
void transformar_maiusculo(char *s)
{
    // for (; *s; s++)
    //     *s = toupper((unsigned char)*s);

    // size_t bufsize = sizeof(s);

    // // 1) Descobre quantos wchar_t cabem (sem buffer, só pra medir)
    // size_t wlen = mbstowcs(NULL, s, 0);
    // if (wlen == (size_t)-1) return;

    // // 2) Aloca buffer wide
    // wchar_t *wbuf = malloc((wlen + 1) * sizeof(wchar_t));
    // if (!wbuf) return;

    // // 3) Converte UTF-8 → wchar_t[]
    // if (mbstowcs(wbuf, s, wlen + 1) == (size_t)-1) {
    //     free(wbuf);
    //     return;
    // }

    // // 4) Maiúsculiza cada wchar_t
    // for (size_t i = 0; i < wlen; i++) {
    //     wbuf[i] = towupper(wbuf[i]);
    // }

    // // 5) Re-encoda wchar_t[] → UTF-8 num buffer temporário
    // char *tmp = malloc(bufsize);
    // if (!tmp) { free(wbuf); return; }

    // size_t mblen = wcstombs(tmp, wbuf, bufsize);
    // if (mblen == (size_t)-1) {
    //     free(wbuf);
    //     free(tmp);
    //     return;
    // }

    // // 6) Copia de volta para s
    // memcpy(s, tmp, mblen + 1);
    // free(wbuf);
    // free(tmp);
    // return;

    // 1) Descobre o tamanho do buffer UTF-8 (incluindo '\0'):
    size_t buflen = strlen(s) + 1;

    // 2) Mede quantos wchar_t cabem (sem buffer, só pra contar):
    size_t wlen = mbstowcs(NULL, s, 0);
    if (wlen == (size_t)-1) 
        return;  // falha de conversão

    // 3) Aloca buffer wide:
    wchar_t *wbuf = malloc((wlen + 1) * sizeof(wchar_t));
    if (!wbuf) 
        return;

    // 4) Converte UTF-8 → wchar_t[]:
    mbstowcs(wbuf, s, wlen + 1);

    // 5) Maiúsculiza cada ponto-de-código:
    for (size_t i = 0; i < wlen; ++i) {
        wbuf[i] = towupper(wbuf[i]);
    }

    // 6) Re-converte wchar_t[] → UTF-8 num buffer temporário:
    char *tmp = malloc(buflen);
    if (!tmp) {
        free(wbuf);
        return;
    }
    wcstombs(tmp, wbuf, buflen);

    // 7) Copia de volta para o buffer original:
    memcpy(s, tmp, buflen);

    free(tmp);
    free(wbuf);

}

void transformar_minusculo(char *s)
{
    for (; *s; s++)
        *s = tolower((unsigned char)*s);
}

/* ---------- validadores ------------------------------------------ */
bool validar_matricula(const char *matricula)
{
    if (strlen(matricula) != 6)
        return false;
    for (int i = 0; i < 6; ++i)
        if (!isdigit((unsigned char)matricula[i]))
            return false;
    return true;
}

bool validar_nome(const char *nome)
{
    // if (strlen(nome) < 3)
    //     return false;
    // for (int i = 0; nome[i]; ++i)
    //     if (!isalpha((unsigned char)nome[i]) && nome[i] != ' ')
    //         return false;
    // return true;
    // if (strlen(nome) < 3) return false;

    // const char *p = nome;
    // wchar_t wc;
    // int tam;

    // while ((tam = mblen(p, MB_CUR_MAX)) > 0) {
    //     if ((tam = mbtowc(&wc, p, MB_CUR_MAX)) <= 0) {
    //         printf("Erro UTF-8 em %.8s\n", p);
    //         return false;
    //     }
    //     if (iswalpha(wc) || wc==' '||wc=='-'||wc=='.'||wc=='\'') {
    //         p += tam;
    //         continue;
    //     }
    //     printf("Inválido: '%lc' (U+%04X)\n", wc, wc);
    //     return false;
    // }
    // return tam == 0;

    int count_letras = 0;
    size_t i = 0, n = strlen(nome);

    while (i < n) {
        unsigned char c = (unsigned char)nome[i];

        if (c < 0x80) {
            // ASCII
            if (isalpha(c)) {
                count_letras++;
            }
            else if (c==' ' || c=='-' || c=='\'') {
                // ok
            }
            else {
                return false;  // dígito ou pontuação proibida
            }
            i++;
        }
        else {
            // possível início de multibyte UTF-8
            int seqlen;
            if ((c & 0xE0) == 0xC0)      seqlen = 2;
            else if ((c & 0xF0) == 0xE0) seqlen = 3;
            else if ((c & 0xF8) == 0xF0) seqlen = 4;
            else return false;  // byte inválido

            // verifica bytes de continuação: 10xxxxxx
            for (int j = 1; j < seqlen; j++) {
                if (i + j >= n || ( (nome[i+j] & 0xC0) != 0x80 ))
                    return false;
            }
            // conta como uma letra “qualquer” (você pode filtrar códigos específicos se quiser)
            count_letras++;
            i += seqlen;
        }
    }

    return (count_letras >= 3);
}

bool validar_senha(const char *senha)
{
    if (strlen(senha) < 6)
        return false;
    for (int i = 0; senha[i]; ++i)
        if (!isalnum((unsigned char)senha[i]))
            return false;
    return true;
}

bool validar_nao_vazio(const char *s)
{
    return *s != '\0';
}

bool validar_cnpj(const char *cnpj)
{
    if (strlen(cnpj) != 14)
        return false;
    for (int i = 0; i < 14; ++i)
        if (!isdigit((unsigned char)cnpj[i]))
            return false;
    return true;
}

bool validar_cep(const char *cep)
{
    if (strlen(cep) != 8)
        return false;
    for (int i = 0; i < 8; ++i)
        if (!isdigit((unsigned char)cep[i]))
            return false;
    return true;
}

bool validar_uf(const char *uf)
{
    return strlen(uf) == 2 &&
           isalpha((unsigned char)uf[0]) &&
           isalpha((unsigned char)uf[1]);
}

bool validar_telefone(const char *tel)
{
    size_t n = 0;
    for (const char *p = tel; *p; ++p)
        if (isdigit((unsigned char)*p))
            ++n;
    return n >= 8;
}

bool validar_email(const char *e)
{
    const char *arroba = strchr(e, '@');
    const char *ponto = strrchr(e, '.');
    return arroba && ponto && arroba < ponto && ponto[1] != '\0';
}

bool validar_data(const char *data) /* dd/mm/aaaa */
{
    if (strlen(data) != 10 || data[2] != '/' || data[5] != '/')
        return false;
    int d = atoi(data);
    int m = atoi(data + 3);
    int y = atoi(data + 6);
    if (d < 1 || d > 31 || m < 1 || m > 12 || y < 1900)
        return false;

    struct tm t = {.tm_mday = d, .tm_mon = m - 1, .tm_year = y - 1900};
    return mktime(&t) != -1 && t.tm_mday == d && t.tm_mon == m - 1;
}

/* ---------- leitor genérico com descarte de "resto de linha" ------ */
void ui_ler_campo(
    const char *prompt,
    char *buf,
    size_t sz,
    bool (*validador)(const char *),
    const char *msg_erro,
    void (*transformar)(char *))
{
    // do
    // {
    //     printf("%s", ui_prompt_form_str(prompt));

    //     if (fgets(buf, (int)sz, stdin) == NULL)
    //         exit(EXIT_FAILURE);

    //     /* verifica se a linha coube inteira; se não, limpa stdin       */
    //     size_t len = strlen(buf);
    //     bool linha_completa = (len > 0 && buf[len - 1] == '\n');
    //     if (!linha_completa)
    //         ui_limpar_entrada(); /* descarta até '\n' pendente        */

    //     /* transforma o campo, se necessário */
    //     if (transformar)
    //         transformar(buf);

    //     strip_newline(buf);

    //     if (validador(buf))
    //         return;

    //     ui_exibir_erro(msg_erro);
    // } while (true);

    do
    {
        printf("%s", ui_prompt_form_str(prompt));

        if (fgets(buf, (int)sz, stdin) == NULL)
            exit(EXIT_FAILURE);

        // se não coube tudo, limpa o restante da linha
        size_t len = strlen(buf);
        if (len > 0 && buf[len - 1] != '\n')
            ui_limpar_entrada();

        // 1) tira o '\n' que sobrou
        strip_newline(buf);

        // 2) maiúsculiza via Unicode (sua versão multibyte)
        if (transformar)
            transformar(buf);

        // 3) valida já em maiúsculas
        if (validador(buf))
            return;

        ui_exibir_erro(msg_erro);
    } while (true);
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
        "UF deve conter 2 letras",
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
    ui_ler_cnpj_industria(i->cnpj, sizeof i->cnpj);
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
