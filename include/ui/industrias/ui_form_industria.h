#ifndef UI_FORM_INDUSTRIA_H
#define UI_FORM_INDUSTRIA_H

#include <stdio.h>
#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include "ui/ui_comum.h"
#include "ui/ui_formulario.h"
#include "estruturas/industria.h"
#include "estruturas/funcionario.h"

#define CNPJ_DIGITOS       14
#define CEP_DIGITOS         8
#define ESTADO_DIGITOS      2
#define DATA_TAMANHO       10

/**
 * @brief L� o CNPJ da ind�stria (formato 00000000000000)
 * @param cnpj_buffer Buffer para armazenamento do CNPJ
 * @param tamanho Tamanho do buffer
 */
void ui_ler_cnpj_industria(char* cnpj_buffer, size_t tamanho);

/**
 * @brief L� a raz�o social da ind�stria
 * @param razao_social_buffer Buffer para armazenamento da raz�o social
 * @param tamanho Tamanho do buffer
 */
void ui_ler_razao_social_industria(char* razao_social_buffer, size_t tamanho);

/**
 * @brief L� o nome fantasia da ind�stria
 * @param nome_fantasia_buffer Buffer para armazenamento do nome fantasia
 * @param tamanho Tamanho do buffer
 */
void ui_ler_nome_fantasia_industria(char* nome_fantasia_buffer, size_t tamanho);

/**
 * @brief L� o telefone da ind�stria
 * @param telefone_buffer Buffer para armazenamento do telefone
 * @param tamanho Tamanho do buffer
 */
void ui_ler_telefone_industria(char* telefone_buffer, size_t tamanho);

/**
 * @brief L� o logradouro da ind�stria
 * @param logradouro_buffer Buffer para armazenamento do logradouro
 * @param tamanho Tamanho do buffer
 */
void ui_ler_logradouro_industria(char* logradouro_buffer, size_t tamanho);

/**
 * @brief L� o n�mero do endere�o da ind�stria
 * @param numero_buffer Buffer para armazenamento do n�mero
 * @param tamanho Tamanho do buffer
 */
void ui_ler_numero_industria(char* numero_buffer, size_t tamanho);

/**
 * @brief L� o bairro da ind�stria
 * @param bairro_buffer Buffer para armazenamento do bairro
 * @param tamanho Tamanho do buffer
 */
void ui_ler_bairro_industria(char* bairro_buffer, size_t tamanho);

/**
 * @brief L� a cidade da ind�stria
 * @param cidade_buffer Buffer para armazenamento da cidade
 * @param tamanho Tamanho do buffer
 */
void ui_ler_cidade_industria(char* cidade_buffer, size_t tamanho);

/**
 * @brief L� o estado da ind�stria (formato XX)
 * @param estado_buffer Buffer para armazenamento do estado
 * @param tamanho Tamanho do buffer
 */
void ui_ler_estado_industria(char* estado_buffer, size_t tamanho);

/**
 * @brief L� o CEP da ind�stria (formato 00000000)
 * @param cep_buffer Buffer para armazenamento do CEP
 * @param tamanho Tamanho do buffer
 */
void ui_ler_cep_industria(char* cep_buffer, size_t tamanho);

/**
 * @brief L� a data de abertura da ind�stria (formato dd/mm/aaaa)
 * @param data_buffer Buffer para armazenamento da data
 * @param tamanho Tamanho do buffer
 */
void ui_ler_data_abertura_industria(char* data_buffer, size_t tamanho);

/**
 * @brief L� o nome do respons�vel pela ind�stria
 * @param nome_buffer Buffer para armazenamento do nome
 * @param tamanho Tamanho do buffer
 */
void ui_ler_nome_responsavel_industria(char* nome_buffer, size_t tamanho);

/**
 * @brief L� o email do respons�vel pela ind�stria
 * @param email_buffer Buffer para armazenamento do email
 * @param tamanho Tamanho do buffer
 */
void ui_ler_email_responsavel_industria(char* email_buffer, size_t tamanho);

#endif /* UI_FORM_INDUSTRIA_H */