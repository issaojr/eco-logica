#ifndef UI_FORMULARIO_H
#define UI_FORMULARIO_H

#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ui/ui_comum.h"

/**
 * @brief Define os tipos de campos suportados em um formul�rio
 */
typedef enum {
    CAMPO_STRING,        // Campo de texto simples
    CAMPO_INTEIRO,       // Campo num�rico inteiro
    CAMPO_DATA,          // Campo de data (DD/MM/AAAA)
    CAMPO_CNPJ,          // Campo de CNPJ (XX.XXX.XXX/XXXX-XX)
    CAMPO_SENHA,         // Campo de senha (texto n�o exibido)
    CAMPO_EMAIL,         // Campo de e-mail (valida��o espec�fica)
    CAMPO_TELEFONE       // Campo de telefone (valida��o espec�fica)
} tipo_campo_t;

/**
 * @brief Define um campo de formul�rio
 */
typedef struct {
    const char* rotulo;      // Texto exibido ao usu�rio
    tipo_campo_t tipo;       // Tipo do campo
    void* valor;             // Ponteiro para onde o valor ser� armazenado
    size_t tamanho;          // Tamanho do buffer (relevante para strings)
    bool obrigatorio;        // Se o campo � de preenchimento obrigat�rio
    int min;                 // Valor m�nimo (para campos num�ricos)
    int max;                 // Valor m�ximo (para campos num�ricos)
    int padrao;              // Valor padr�o (para campos num�ricos)
} campo_formulario_t;

/**
 * @brief Exibe um formul�rio e coleta os dados do usu�rio
 * 
 * @param titulo T�tulo do formul�rio
 * @param subtitulo Subt�tulo opcional (pode ser NULL)
 * @param campos Array de defini��es de campos
 * @param num_campos N�mero de campos no array
 * @return true se o formul�rio foi preenchido com sucesso
 */
bool ui_exibir_formulario(
    const char* titulo,
    const char* subtitulo,
    campo_formulario_t* campos,
    size_t num_campos
);

/**
 * @brief Cria uma defini��o de campo de texto
 */
campo_formulario_t ui_criar_campo_string(
    const char* rotulo, 
    char* buffer, 
    size_t tamanho, 
    bool obrigatorio
);

/**
 * @brief Cria uma defini��o de campo num�rico inteiro
 */
campo_formulario_t ui_criar_campo_inteiro(
    const char* rotulo, 
    int* valor, 
    int min, 
    int max, 
    int padrao, 
    bool obrigatorio
);

/**
 * @brief Cria uma defini��o de campo de data
 */
campo_formulario_t ui_criar_campo_data(
    const char* rotulo, 
    char* buffer, 
    size_t tamanho, 
    bool obrigatorio
);

/**
 * @brief Cria uma defini��o de campo de CNPJ
 */
campo_formulario_t ui_criar_campo_cnpj(
    const char* rotulo, 
    char* buffer, 
    size_t tamanho, 
    bool obrigatorio
);

/**
 * @brief Cria uma defini��o de campo de senha
 */
campo_formulario_t ui_criar_campo_senha(
    const char* rotulo, 
    char* buffer, 
    size_t tamanho, 
    bool obrigatorio
);

/**
 * @brief Cria uma defini��o de campo de e-mail
 */
campo_formulario_t ui_criar_campo_email(
    const char* rotulo, 
    char* buffer, 
    size_t tamanho, 
    bool obrigatorio
);

/**
 * @brief Cria uma defini��o de campo de telefone
 */
campo_formulario_t ui_criar_campo_telefone(
    const char* rotulo, 
    char* buffer, 
    size_t tamanho, 
    bool obrigatorio
);

#endif // UI_FORMULARIO_H