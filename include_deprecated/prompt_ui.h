#ifndef PROMPT_UI_H
#define PROMPT_UI_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    PROMPT_CNPJ,                       ///< Prompt para entrada de CNPJ
    PROMPT_NOME_RESPONSAVEL,             ///< Prompt para entrada do nome da indústria
    PROMPT_EMAIL_RESPONSAVEL,          ///< Prompt para entrada do e-mail do responsável
    PROMPT_RAZAO_SOCIAL,               ///< Prompt para entrada da razão social
    PROMPT_NOME_FANTASIA,              ///< Prompt para entrada do nome fantasia
    PROMPT_TELEFONE,                   ///< Prompt para entrada do telefone
    PROMPT_ENDERECO,                   ///< Prompt para entrada do endereço
    PROMPT_DATA_ABERTURA,              ///< Prompt para entrada da data de abertura
    PROMPT_LOGRADOURO,                 ///< Prompt para entrada do logradouro
    PROMPT_NUMERO,                     ///< Prompt para entrada do número
    PROMPT_BAIRRO,                     ///< Prompt para entrada do bairro
    PROMPT_CIDADE,                     ///< Prompt para entrada da cidade
    PROMPT_ESTADO,                     ///< Prompt para entrada do estado
    PROMPT_CEP,                         ///< Prompt para entrada do CEP
    PROMPT_EMAIL_INDUSTRIA,           ///< Prompt para entrada do e-mail da indústria
} codigo_prompt;

const char *prompt_msg(codigo_prompt code);

void mostrar_prompt(const char* prompt);

#endif // PROMPT_UI_H