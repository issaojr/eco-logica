#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ui/ui_formulario.h"
#include "ui/ui_comum.h"

// Função auxiliar para validar e-mail
static bool validar_email(const char* email) {
    // Verificação básica: deve conter @ e pelo menos um ponto após @
    const char* at = strchr(email, '@');
    if (!at) return false;
    
    // Deve haver pelo menos um caractere antes do @
    if (at == email) return false;
    
    // Deve haver pelo menos um ponto após o @
    const char* dot = strchr(at, '.');
    if (!dot) return false;
    
    // Deve haver pelo menos um caractere entre @ e .
    if (dot == at + 1) return false;
    
    // Deve haver pelo menos um caractere após o .
    if (dot[1] == '\0') return false;
    
    return true;
}

// Função auxiliar para validar telefone (formato básico)
static bool validar_telefone(const char* telefone) {
    size_t len = strlen(telefone);
    
    // Formatos aceitos: XXXXXXXXXX, (XX)XXXXXXXX, (XX) XXXXXXXX, etc.
    // Por simplicidade, apenas verificamos se contém 10-11 dígitos
    
    int digitos = 0;
    for (size_t i = 0; i < len; i++) {
        if (isdigit(telefone[i])) digitos++;
    }
    
    return (digitos >= 10 && digitos <= 11);
}

// Funções para criar definições de campos
campo_formulario_t ui_criar_campo_string(const char* rotulo, char* buffer, size_t tamanho, bool obrigatorio) {
    campo_formulario_t campo;
    campo.rotulo = rotulo;
    campo.tipo = CAMPO_STRING;
    campo.valor = buffer;
    campo.tamanho = tamanho;
    campo.obrigatorio = obrigatorio;
    campo.min = 0;
    campo.max = 0;
    campo.padrao = 0;
    return campo;
}

campo_formulario_t ui_criar_campo_inteiro(const char* rotulo, int* valor, int min, int max, int padrao, bool obrigatorio) {
    campo_formulario_t campo;
    campo.rotulo = rotulo;
    campo.tipo = CAMPO_INTEIRO;
    campo.valor = valor;
    campo.tamanho = sizeof(int);
    campo.obrigatorio = obrigatorio;
    campo.min = min;
    campo.max = max;
    campo.padrao = padrao;
    return campo;
}

campo_formulario_t ui_criar_campo_data(const char* rotulo, char* buffer, size_t tamanho, bool obrigatorio) {
    campo_formulario_t campo;
    campo.rotulo = rotulo;
    campo.tipo = CAMPO_DATA;
    campo.valor = buffer;
    campo.tamanho = tamanho;
    campo.obrigatorio = obrigatorio;
    campo.min = 0;
    campo.max = 0;
    campo.padrao = 0;
    return campo;
}

campo_formulario_t ui_criar_campo_cnpj(const char* rotulo, char* buffer, size_t tamanho, bool obrigatorio) {
    campo_formulario_t campo;
    campo.rotulo = rotulo;
    campo.tipo = CAMPO_CNPJ;
    campo.valor = buffer;
    campo.tamanho = tamanho;
    campo.obrigatorio = obrigatorio;
    campo.min = 0;
    campo.max = 0;
    campo.padrao = 0;
    return campo;
}

campo_formulario_t ui_criar_campo_senha(const char* rotulo, char* buffer, size_t tamanho, bool obrigatorio) {
    campo_formulario_t campo;
    campo.rotulo = rotulo;
    campo.tipo = CAMPO_SENHA;
    campo.valor = buffer;
    campo.tamanho = tamanho;
    campo.obrigatorio = obrigatorio;
    campo.min = 0;
    campo.max = 0;
    campo.padrao = 0;
    return campo;
}

campo_formulario_t ui_criar_campo_email(const char* rotulo, char* buffer, size_t tamanho, bool obrigatorio) {
    campo_formulario_t campo;
    campo.rotulo = rotulo;
    campo.tipo = CAMPO_EMAIL;
    campo.valor = buffer;
    campo.tamanho = tamanho;
    campo.obrigatorio = obrigatorio;
    campo.min = 0;
    campo.max = 0;
    campo.padrao = 0;
    return campo;
}

campo_formulario_t ui_criar_campo_telefone(const char* rotulo, char* buffer, size_t tamanho, bool obrigatorio) {
    campo_formulario_t campo;
    campo.rotulo = rotulo;
    campo.tipo = CAMPO_TELEFONE;
    campo.valor = buffer;
    campo.tamanho = tamanho;
    campo.obrigatorio = obrigatorio;
    campo.min = 0;
    campo.max = 0;
    campo.padrao = 0;
    return campo;
}

// Função principal para exibir o formulário
bool ui_exibir_formulario(const char* titulo, const char* subtitulo, campo_formulario_t* campos, size_t num_campos) {
    // Exibir título do formulário
    ui_exibir_titulo(titulo, subtitulo);
    
    // Iterar sobre cada campo
    for (size_t i = 0; i < num_campos; i++) {
        campo_formulario_t* campo = &campos[i];
        bool sucesso = false;
        
        // Exibir separador visual entre campos
        if (i > 0) printf("\n");
        
        // Processar o campo conforme seu tipo
        switch (campo->tipo) {
            case CAMPO_STRING:
                sucesso = ui_ler_string(campo->rotulo, (char*)campo->valor, campo->tamanho, campo->obrigatorio);
                break;
                
            case CAMPO_INTEIRO:
                *(int*)campo->valor = ui_ler_inteiro(campo->rotulo, campo->min, campo->max, campo->padrao, campo->obrigatorio);
                sucesso = true;
                break;
                
            case CAMPO_DATA:
                sucesso = ui_ler_data(campo->rotulo, (char*)campo->valor, campo->tamanho, campo->obrigatorio);
                break;
                
            case CAMPO_CNPJ:
                sucesso = ui_ler_cnpj(campo->rotulo, (char*)campo->valor, campo->tamanho, campo->obrigatorio);
                break;
                
            case CAMPO_SENHA: {
                // Ler a senha como string normal (visível)
                char* senha = (char*)campo->valor;
                if (!ui_ler_string(campo->rotulo, senha, campo->tamanho, campo->obrigatorio)) {
                    sucesso = false;
                    break;
                }
                sucesso = true;
                break;
            }
                
            case CAMPO_EMAIL: {
                // Ler o e-mail como string normal
                char* email = (char*)campo->valor;
                if (!ui_ler_string(campo->rotulo, email, campo->tamanho, campo->obrigatorio)) {
                    sucesso = false;
                    break;
                }
                
                // Se não for obrigatório e estiver vazio, sucesso
                if (!campo->obrigatorio && email[0] == '\0') {
                    sucesso = true;
                    break;
                }
                
                // Validar o formato do e-mail
                if (validar_email(email)) {
                    sucesso = true;
                } else {
                    ui_exibir_erro("E-mail inválido. Use um formato válido como 'usuario@dominio.com'");
                    sucesso = false;
                }
                break;
            }
                
            case CAMPO_TELEFONE: {
                // Ler o telefone como string normal
                char* telefone = (char*)campo->valor;
                if (!ui_ler_string(campo->rotulo, telefone, campo->tamanho, campo->obrigatorio)) {
                    sucesso = false;
                    break;
                }
                
                // Se não for obrigatório e estiver vazio, sucesso
                if (!campo->obrigatorio && telefone[0] == '\0') {
                    sucesso = true;
                    break;
                }
                
                // Validar o formato do telefone
                if (validar_telefone(telefone)) {
                    sucesso = true;
                } else {
                    ui_exibir_erro("Telefone inválido. Use um formato válido com DDD e 8-9 dígitos");
                    sucesso = false;
                }
                break;
            }
        }
        
        // Se falhou em campo obrigatório, retorna falha
        if (!sucesso && campo->obrigatorio) {
            ui_exibir_erro("Falha ao preencher campo obrigatório");
            return false;
        }
    }
    
    // Todos os campos foram preenchidos com sucesso
    return true;
}