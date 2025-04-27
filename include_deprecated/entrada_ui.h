#ifndef ENTRADA_UI_H
#define ENTRADA_UI_H

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "info_dialog_ui.h"
#include "erros.h"
#include "utils.h" // Para usar clearConsole
#include "strings_globais.h" // Para usar NOME_PROGRAMA
#include "prompt_ui.h" // Para usar prompt_msg

int ler_opcao(const char *prompt, const int *opcoesValidas, size_t numOpcoes);

void ler_nome(const char *prompt, char *nome, size_t tamanho);

int ler_matricula(const char *prompt);

void ler_senha(const char *prompt, char *senha, size_t tamanho);

void ler_email(const char *prompt, char *email, size_t tamanho);

void ler_cnpj(const char *prompt, char *cnpj, size_t tamanho);

void ler_razao_social(const char *prompt, char *razao_social, size_t tamanho);

void ler_nome_fantasia(const char *prompt, char *nome_fantasia, size_t tamanho);

void ler_telefone(const char *prompt, char *telefone, size_t tamanho);

void ler_logradouro(const char *prompt, char *logradouro, size_t tamanho);

void ler_numero(const char *prompt, char *numero, size_t tamanho);

void ler_bairro(const char *prompt, char *bairro, size_t tamanho);

void ler_cidade(const char *prompt, char *cidade, size_t tamanho);

void ler_estado(const char *prompt, char *estado, size_t tamanho);

void ler_cep(const char *prompt, char *cep, size_t tamanho);

void ler_data_abertura(const char *prompt, char *data_abertura, size_t tamanho);

#endif // ENTRADA_UI_H
