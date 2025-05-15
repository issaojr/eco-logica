// /* industria_form.c  –  formulário em console (C ANSI C99)           */
// /* versão corrigida: trata “enter” pendente e buffers têm espaço extra */

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <ctype.h>
// #include <stdbool.h>
// #include <time.h>

// /* ---------- utilidades ------------------------------------------- */
// static void strip_newline(char *s)
// {
//     size_t n = strlen(s);
//     if (n && s[n - 1] == '\n')
//         s[n - 1] = '\0';
// }

// static void limpar_entrada(void)           /* descarta até próximo '\n' */
// {
//     int c;
//     while ((c = getchar()) != '\n' && c != EOF) { }
// }

// /* ---------- validadores ------------------------------------------ */
// static bool validar_nao_vazio(const char *s) { return *s != '\0'; }

// static bool validar_cnpj(const char *cnpj)
// {
//     if (strlen(cnpj) != 14) return false;
//     for (int i = 0; i < 14; ++i)
//         if (!isdigit((unsigned char)cnpj[i])) return false;
//     return true;            /* sem cálculo de dígitos verificadores     */
// }

// static bool validar_cep(const char *cep)
// {
//     if (strlen(cep) != 8) return false;
//     for (int i = 0; i < 8; ++i)
//         if (!isdigit((unsigned char)cep[i])) return false;
//     return true;
// }

// static bool validar_uf(const char *uf)
// {
//     return strlen(uf) == 2 &&
//            isalpha((unsigned char)uf[0]) &&
//            isalpha((unsigned char)uf[1]);
// }

// static bool validar_telefone(const char *tel)
// {
//     size_t n = 0;
//     for (const char *p = tel; *p; ++p)
//         if (isdigit((unsigned char)*p)) ++n;
//     return n >= 8;
// }

// static bool validar_email(const char *e)
// {
//     const char *arroba = strchr(e, '@');
//     const char *ponto  = strrchr(e, '.');
//     return arroba && ponto && arroba < ponto && ponto[1] != '\0';
// }

// static bool validar_data(const char *data)          /* dd/mm/aaaa */
// {
//     if (strlen(data) != 10 || data[2] != '/' || data[5] != '/') return false;
//     int d = atoi(data);
//     int m = atoi(data + 3);
//     int y = atoi(data + 6);
//     if (d < 1 || d > 31 || m < 1 || m > 12 || y < 1900) return false;

//     struct tm t = { .tm_mday = d, .tm_mon = m - 1, .tm_year = y - 1900 };
//     return mktime(&t) != -1 && t.tm_mday == d && t.tm_mon == m - 1;
// }

// /* ---------- leitor genérico com descarte de “resto de linha” ------ */
// static void ui_ler_campo(const char *prompt,
//                          char       *buf,
//                          size_t      sz,
//                          bool      (*validador)(const char *),
//                          const char *msg_erro)
// {
//     do {
//         printf("%s: ", prompt);

//         if (fgets(buf, (int)sz, stdin) == NULL)
//             exit(EXIT_FAILURE);

//         /* verifica se a linha coube inteira; se não, limpa stdin       */
//         size_t len = strlen(buf);
//         bool linha_completa = (len > 0 && buf[len - 1] == '\n');
//         if (!linha_completa)
//             limpar_entrada();     /* descarta até '\n' pendente        */

//         strip_newline(buf);

//         if (validador(buf))
//             return;

//         printf("Erro – %s\n", msg_erro);
//     } while (true);
// }

// /* ---------- estrutura principal ---------------------------------- */
// typedef struct {
//     char cnpj[16];               /* 14 + '\n' + '\0'                  */
//     char razao_social[128];
//     char nome_fantasia[128];
//     char telefone[32];
//     char logradouro[128];
//     char numero[16];
//     char bairro[64];
//     char cidade[64];
//     char estado[4];              /* 2 + '\n' + '\0'                   */
//     char cep[10];                /* 8 + '\n' + '\0'                   */
//     char data_abertura[11];
//     char nome_responsavel[128];
//     char email_responsavel[128];
// } industria_t;

// /* ---------- leitores específicos --------------------------------- */
// static void ui_ler_cnpj_industria          (char *b, size_t s) { ui_ler_campo("CNPJ                 ", b, s, validar_cnpj,   "CNPJ deve ter 14 dígitos"); }
// static void ui_ler_razao_social_industria  (char *b, size_t s) { ui_ler_campo("Razão social         ", b, s, validar_nao_vazio,"Campo obrigatório"); }
// static void ui_ler_nome_fantasia_industria (char *b, size_t s) { ui_ler_campo("Nome fantasia        ", b, s, validar_nao_vazio,"Campo obrigatório"); }
// static void ui_ler_telefone_industria      (char *b, size_t s) { ui_ler_campo("Telefone             ", b, s, validar_telefone,"Informe ao menos 8 dígitos"); }
// static void ui_ler_logradouro_industria    (char *b, size_t s) { ui_ler_campo("Logradouro           ", b, s, validar_nao_vazio,"Campo obrigatório"); }
// static void ui_ler_numero_industria        (char *b, size_t s) { ui_ler_campo("Número               ", b, s, validar_nao_vazio,"Campo obrigatório"); }
// static void ui_ler_bairro_industria        (char *b, size_t s) { ui_ler_campo("Bairro               ", b, s, validar_nao_vazio,"Campo obrigatório"); }
// static void ui_ler_cidade_industria        (char *b, size_t s) { ui_ler_campo("Cidade               ", b, s, validar_nao_vazio,"Campo obrigatório"); }

// static void ui_ler_estado_industria(char *b, size_t s)
// {
//     ui_ler_campo("UF (ex: SP)          ", b, s, validar_uf, "UF deve conter 2 letras");
//     b[0] = (char)toupper((unsigned char)b[0]);
//     b[1] = (char)toupper((unsigned char)b[1]);
// }

// static void ui_ler_cep_industria           (char *b, size_t s) { ui_ler_campo("CEP                  ", b, s, validar_cep,      "CEP deve ter 8 dígitos"); }
// static void ui_ler_data_abertura_industria (char *b, size_t s) { ui_ler_campo("Data de abertura     ", b, s, validar_data,     "Formato DD/MM/AAAA inválido"); }
// static void ui_ler_nome_responsavel_industria (char *b,size_t s){ ui_ler_campo("Responsável          ", b, s, validar_nao_vazio,"Campo obrigatório"); }
// static void ui_ler_email_responsavel_industria(char *b,size_t s){ ui_ler_campo("E-mail responsável   ", b, s, validar_email,    "E-mail inválido"); }

// /* ---------- formulário completo ---------------------------------- */
// void ui_exibir_form_industria(industria_t *i)
// {
//     printf("== Cadastro de Indústria ==\n");
//     ui_ler_cnpj_industria              (i->cnpj,             sizeof i->cnpj);
//     ui_ler_razao_social_industria      (i->razao_social,     sizeof i->razao_social);
//     ui_ler_nome_fantasia_industria     (i->nome_fantasia,    sizeof i->nome_fantasia);
//     ui_ler_telefone_industria          (i->telefone,         sizeof i->telefone);
//     ui_ler_logradouro_industria        (i->logradouro,       sizeof i->logradouro);
//     ui_ler_numero_industria            (i->numero,           sizeof i->numero);
//     ui_ler_bairro_industria            (i->bairro,           sizeof i->bairro);
//     ui_ler_cidade_industria            (i->cidade,           sizeof i->cidade);
//     ui_ler_estado_industria            (i->estado,           sizeof i->estado);
//     ui_ler_cep_industria               (i->cep,              sizeof i->cep);
//     ui_ler_data_abertura_industria     (i->data_abertura,    sizeof i->data_abertura);
//     ui_ler_nome_responsavel_industria  (i->nome_responsavel, sizeof i->nome_responsavel);
//     ui_ler_email_responsavel_industria (i->email_responsavel,sizeof i->email_responsavel);
// }

// /* ---------- demonstração ----------------------------------------- */
// static void imprimir_industria(const industria_t *i)
// {
//     puts("\n== Dados capturados ==");
//     printf("CNPJ:               %s\n", i->cnpj);
//     printf("Razão social:       %s\n", i->razao_social);
//     printf("Nome fantasia:      %s\n", i->nome_fantasia);
//     printf("Telefone:           %s\n", i->telefone);
//     printf("Logradouro:         %s, %s\n", i->logradouro, i->numero);
//     printf("Bairro:             %s\n", i->bairro);
//     printf("Cidade/UF:          %s/%s\n", i->cidade, i->estado);
//     printf("CEP:                %s\n", i->cep);
//     printf("Data abertura:      %s\n", i->data_abertura);
//     printf("Responsável:        %s\n", i->nome_responsavel);
//     printf("E-mail responsável: %s\n", i->email_responsavel);
// }

// int main(void)
// {
//     industria_t ind = {0};
//     ui_exibir_form_industria(&ind);
//     imprimir_industria(&ind);
//     return 0;
// }
