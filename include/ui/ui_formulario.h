#ifndef UI_FORMULARIO_H
#define UI_FORMULARIO_H

#include <stdbool.h>
#include <stddef.h>

/**
 * @brief Define os tipos de campos suportados em um formulário
 */
typedef enum {
    CAMPO_STRING,        // Campo de texto simples
    CAMPO_INTEIRO,       // Campo numérico inteiro
    CAMPO_DATA,          // Campo de data (DD/MM/AAAA)
    CAMPO_CNPJ,          // Campo de CNPJ (XX.XXX.XXX/XXXX-XX)
    CAMPO_SENHA,         // Campo de senha (texto não exibido)
    CAMPO_EMAIL,         // Campo de e-mail (validação específica)
    CAMPO_TELEFONE       // Campo de telefone (validação específica)
} tipo_campo_t;

/**
 * @brief Define um campo de formulário
 */
typedef struct {
    const char* rotulo;      // Texto exibido ao usuário
    tipo_campo_t tipo;       // Tipo do campo
    void* valor;             // Ponteiro para onde o valor será armazenado
    size_t tamanho;          // Tamanho do buffer (relevante para strings)
    bool obrigatorio;        // Se o campo é de preenchimento obrigatório
    int min;                 // Valor mínimo (para campos numéricos)
    int max;                 // Valor máximo (para campos numéricos)
    int padrao;              // Valor padrão (para campos numéricos)
} campo_formulario_t;

/**
 * @brief Exibe um formulário e coleta os dados do usuário
 * 
 * @param titulo Título do formulário
 * @param subtitulo Subtítulo opcional (pode ser NULL)
 * @param campos Array de definições de campos
 * @param num_campos Número de campos no array
 * @return true se o formulário foi preenchido com sucesso
 */
bool ui_exibir_formulario(
    const char* titulo,
    const char* subtitulo,
    campo_formulario_t* campos,
    size_t num_campos
);

/**
 * @brief Cria uma definição de campo de texto
 */
campo_formulario_t ui_criar_campo_string(
    const char* rotulo, 
    char* buffer, 
    size_t tamanho, 
    bool obrigatorio
);

/**
 * @brief Cria uma definição de campo numérico inteiro
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
 * @brief Cria uma definição de campo de data
 */
campo_formulario_t ui_criar_campo_data(
    const char* rotulo, 
    char* buffer, 
    size_t tamanho, 
    bool obrigatorio
);

/**
 * @brief Cria uma definição de campo de CNPJ
 */
campo_formulario_t ui_criar_campo_cnpj(
    const char* rotulo, 
    char* buffer, 
    size_t tamanho, 
    bool obrigatorio
);

/**
 * @brief Cria uma definição de campo de senha
 */
campo_formulario_t ui_criar_campo_senha(
    const char* rotulo, 
    char* buffer, 
    size_t tamanho, 
    bool obrigatorio
);

/**
 * @brief Cria uma definição de campo de e-mail
 */
campo_formulario_t ui_criar_campo_email(
    const char* rotulo, 
    char* buffer, 
    size_t tamanho, 
    bool obrigatorio
);

/**
 * @brief Cria uma definição de campo de telefone
 */
campo_formulario_t ui_criar_campo_telefone(
    const char* rotulo, 
    char* buffer, 
    size_t tamanho, 
    bool obrigatorio
);

#endif // UI_FORMULARIO_H