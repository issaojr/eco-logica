#ifndef ERROS_H
#define ERROS_H

/**
 * C�digos de erro gen�ricos e espec�ficos do sistema.
 */
typedef enum {
    ERR_OK                            = 0,
    ERR_ALOC_MEMORIA                  = -1,
    ERR_OPCAO_INVALIDA                = -10,
    ERR_OPCAO_INVALIDA_NUMERICA       = -11,
    ERR_LEITURA_INVALIDA              = -20,
    ERR_MATRICULA_INVALIDA            = -30,
    ERR_LEITURA_NOME_INVALIDO         = -40,
    ERR_NOME_VAZIO                    = -41,
    ERR_LEITURA_SENHA_INVALIDA        = -50,
    ERR_SENHA_VAZIA                   = -51,
    ERR_FORMATO_DATA                  = -100,
    ERR_DATA_INVALIDA                 = -101,
    ERR_DATA_INVALIDA_MES             = -102,
    ERR_DATA_INVALIDA_ANO             = -103,
    ERR_DATA_INVALIDA_INTERVALO       = -104,
    ERR_SQLITE                        = -200,
    ERR_CADASTRO_INDUSTRIA            = -300,
    ERR_CNPJ_DUPLICADO                = -301,
    ERR_NOME_INDUSTRIA_INVALIDO       = -302,
    ERR_EMAIL_RESPONSAVEL_INVALIDO    = -303,
    ERR_RAZAO_SOCIAL_INVALIDA         = -304,
    ERR_NOME_FANTASIA_INVALIDO        = -305,
    ERR_TELEFONE_INVALIDO             = -306,
    ERR_ENDERECO_INVALIDO             = -307,
    ERR_EMAIL_INVALIDO                = -308,
    ERR_DATA_ABERTURA_INVALIDA        = -309,
    ERR_CNPJ_INVALIDO                 = -310,
    ERR_LOGRADOURO_INVALIDO           = -311,
    ERR_NUMERO_INVALIDO               = -312,
    ERR_BAIRRO_INVALIDO               = -313,
    ERR_CIDADE_INVALIDA               = -314,
    ERR_ESTADO_INVALIDO               = -315,
    ERR_CEP_INVALIDO                  = -316,
    ERR_CNPJ_COMPRIMENTO              = -317,
    ERR_CNPJ_DIGITOS                  = -318,
    ERR_CNPJ_VAZIO                    = -319,
    ERR_RAZAO_SOCIAL_VAZIO            = -320,
    ERR_NOME_FANTASIA_VAZIO           = -321,
    ERR_TELEFONE_VAZIO                = -322,
    ERR_ENDERECO_VAZIO                = -323,
    ERR_LOGRADOURO_VAZIO              = -324,
    ERR_NUMERO_VAZIO                  = -325,
    ERR_BAIRRO_VAZIO                  = -326,
    ERR_CIDADE_VAZIA                  = -327,
    ERR_ESTADO_VAZIO                  = -328,
    ERR_CEP_VAZIO                     = -329,
    ERR_LEITURA_RAZAO_SOCIAL_INVALIDA = -330,
    ERR_LEITURA_NOME_FANTASIA_INVALIDO = -331,
    ERR_LEITURA_TELEFONE_INVALIDO     = -332,
    ERR_LEITURA_ENDERECO_INVALIDO     = -333,
    ERR_LEITURA_LOGRADOURO_INVALIDO   = -334,
    ERR_LEITURA_NUMERO_INVALIDO       = -335,
    ERR_LEITURA_BAIRRO_INVALIDO       = -336,
    ERR_LEITURA_CIDADE_INVALIDA       = -337,
    ERR_LEITURA_ESTADO_INVALIDO       = -338,
    ERR_LEITURA_CEP_INVALIDO          = -339,
    ERR_LEITURA_CNPJ_INVALIDO         = -340,
    ERR_LEITURA_EMAIL_INVALIDO        = -341,
    ERR_LEITURA_DATA_ABERTURA_INVALIDA = -342,
    ERR_TELEFONE_DIGITOS              = -343,
    ERR_CEP_DIGITOS                   = -344,
    ERR_CEP_COMPRIMENTO               = -345,
    ERR_ESTADO_COMPRIMENTO            = -347,
    ERR_NUMERO_DIGITOS                = -348
} codigo_erro;

/**
 * Retorna mensagem associada a um c�digo de erro.
 */
const char *erro_msg(codigo_erro code);

#endif // ERROS_H