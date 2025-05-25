#ifndef UI_FORM_H
#define UI_FORM_H

#define UI_TAMANHO_MAX_PROMPT 256

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <time.h>
#include <wchar.h>
#include <locale.h>
#include <wctype.h>
#include "ui/ui_comum.h"
#include "estruturas/industria.h"
#include "estruturas/funcionario.h"
#include "business/business_crypto.h"
#include "persistencia/funcionario_dao.h"

void strip_newline(char *s);
char *ui_prompt_form_str(const char *prompt_str);
void transformar_maiusculo(char *s);
void transformar_minusculo(char *s);
bool validar_nao_vazio(const char *s);
bool validar_cnpj(const char *cnpj);
bool validar_cep(const char *cep);
bool validar_uf(const char *uf);
bool validar_telefone(const char *tel);
bool validar_email(const char *e);
bool validar_data(const char *data);
void ui_ler_campo(const char *prompt,
                  char *buf,
                  size_t sz,
                  bool (*validador)(const char *),
                  const char *msg_erro,
                  void (*transformar)(char *));

void ui_ler_matricula_funcionario(char *matricula, size_t tamanho);
void ui_ler_nome_funcionario(char *nome, size_t tamanho);
void ui_ler_senha_funcionario(char *senha, size_t tamanho);
void ui_converter_str_hash(char *senha, size_t tamanho);
void ui_exibir_form_funcionario(funcionario_t *novo_funcionario_out);
void ui_ler_cnpj_industria(char *b, size_t s);
void ui_ler_razao_social_industria(char *b, size_t s);
void ui_ler_nome_fantasia_industria(char *b, size_t s);
void ui_ler_telefone_industria(char *b, size_t s);
void ui_ler_logradouro_industria(char *b, size_t s);
void ui_ler_numero_industria(char *b, size_t s);
void ui_ler_bairro_industria(char *b, size_t s);
void ui_ler_cidade_industria(char *b, size_t s);
void ui_ler_estado_industria(char *b, size_t s);
void ui_ler_cep_industria(char *b, size_t s);
void ui_ler_data_abertura_industria(char *b, size_t s);
void ui_ler_nome_responsavel_industria(char *b, size_t s);
void ui_ler_email_responsavel_industria(char *b, size_t s);
void ui_exibir_form_industria(industria_t *i);

#endif // UI_FORM_H
