#ifndef ERROS_H
#define ERROS_H

// Defini��o dos c�digos de erro
typedef enum {
    ERR_OK              = 0,    ///< Sem erro
    ERR_ALOC_MEMORIA      = -1,  ///< Erro de aloca��o de mem�ria
    ERR_OPCAO_INVALIDA  = -10,  ///< Op��o inv�lida
    ERR_OPCAO_INVALIDA_NUMERICA = -11, ///< Op��o inv�lida (n�o num�rica)
    ERR_LEITURA_INVALIDA = -20, ///< Erro de leitura (EOF ou string vazia)
    ERR_MATRICULA_INVALIDA = -30, ///< Matr�cula inv�lida (n�o num�rica ou fora do intervalo)
    ERR_LEITURA_NOME_INVALIDO = -40, ///< Nome inv�lido (vazio ou muito longo)
    ERR_NOME_VAZIO = -41, ///< Nome vazio
    ERR_LEITURA_SENHA_INVALIDA = -50, ///< Senha inv�lida (vazia ou muito longa)
    ERR_SENHA_VAZIA = -51, ///< Senha vazia
    ERR_FORMATO_DATA     = -100, ///< Formato de data inv�lido
    ERR_DATA_INVALIDA    = -101, ///< Data inexistente (ex.: 30/02)
    ERR_DATA_INVALIDA_MES = -102, ///< Data inv�lida (m�s fora de intervalo)
    ERR_DATA_INVALIDA_ANO = -103, ///< Data inv�lida (ano fora de intervalo)
    ERR_DATA_INVALIDA_INTERVALO = -104, ///< Data inv�lida (intervalo de datas inv�lido)
    ERR_SQLITE           = -200, ///< Erro gen�rico do SQLite
    ERR_CADASTRO_INDUSTRIA        = -300, ///< Erro ao cadastrar ind�stria
    ERR_CNPJ_DUPLICADO            = -301, ///< CNPJ j� cadastrado
    ERR_NOME_INDUSTRIA_INVALIDO   = -302, ///< Nome da ind�stria inv�lido
    ERR_EMAIL_RESPONSAVEL_INVALIDO= -303, ///< E-mail do respons�vel inv�lido
    ERR_RAZAO_SOCIAL_INVALIDA     = -304, ///< Raz�o Social inv�lida
    ERR_NOME_FANTASIA_INVALIDO    = -305, ///< Nome Fantasia inv�lido
    ERR_TELEFONE_INVALIDO         = -306, ///< Telefone inv�lido
    ERR_ENDERECO_INVALIDO         = -307, ///< Endere�o inv�lido
    ERR_EMAIL_INVALIDO            = -308, ///< E-mail inv�lido
    ERR_DATA_ABERTURA_INVALIDA    = -309, ///< Data de Abertura inv�lida
    ERR_CNPJ_INVALIDO             = -310, ///< CNPJ inv�lido
    ERR_LOGRADOURO_INVALIDO       = -311, ///< Logradouro inv�lido
    ERR_NUMERO_INVALIDO           = -312, ///< N�mero inv�lido
    ERR_BAIRRO_INVALIDO           = -313, ///< Bairro inv�lido
    ERR_CIDADE_INVALIDA           = -314, ///< Cidade inv�lida
    ERR_ESTADO_INVALIDO           = -315, ///< Estado inv�lido
    ERR_CEP_INVALIDO              = -316,  ///< CEP inv�lido
    ERR_CNPJ_COMPRIMENTO         = -317, ///< CNPJ inv�lido (comprimento inv�lido)
    ERR_CNPJ_DIGITOS             = -318, ///< CNPJ inv�lido (n�o cont�m apenas d�gitos)
    ERR_CNPJ_VAZIO               = -319, ///< CNPJ inv�lido (vazio)
    ERR_RAZAO_SOCIAL_VAZIO       = -320, ///< Raz�o Social inv�lida (vazia)
    ERR_NOME_FANTASIA_VAZIO      = -321, ///< Nome Fantasia inv�lido (vazio)
    ERR_TELEFONE_VAZIO           = -322, ///< Telefone inv�lido (vazio)
    ERR_ENDERECO_VAZIO           = -323, ///< Endere�o inv�lido (vazio)
    ERR_LOGRADOURO_VAZIO         = -324, ///< Logradouro inv�lido (vazio)
    ERR_NUMERO_VAZIO             = -325, ///< N�mero inv�lido (vazio)
    ERR_BAIRRO_VAZIO             = -326, ///< Bairro inv�lido (vazio)
    ERR_CIDADE_VAZIA             = -327, ///< Cidade inv�lida (vazia)
    ERR_ESTADO_VAZIO             = -328, ///< Estado inv�lido (vazio)
    ERR_CEP_VAZIO                = -329,  ///< CEP inv�lido (vazio)
    ERR_LEITURA_RAZAO_SOCIAL_INVALIDA = -330, ///< Erro na entrada da raz�o social
    ERR_LEITURA_NOME_FANTASIA_INVALIDO = -331, ///< Erro na entrada do nome fantasia
    ERR_LEITURA_TELEFONE_INVALIDO = -332, ///< Erro na entrada do telefone
    ERR_LEITURA_ENDERECO_INVALIDO = -333, ///< Erro na entrada do endere�o
    ERR_LEITURA_LOGRADOURO_INVALIDO = -334, ///< Erro na entrada do logradouro
    ERR_LEITURA_NUMERO_INVALIDO   = -335, ///< Erro na entrada do n�mero
    ERR_LEITURA_BAIRRO_INVALIDO   = -336, ///< Erro na entrada do bairro
    ERR_LEITURA_CIDADE_INVALIDA   = -337, ///< Erro na entrada da cidade
    ERR_LEITURA_ESTADO_INVALIDO   = -338, ///< Erro na entrada do estado
    ERR_LEITURA_CEP_INVALIDO      = -339, ///< Erro na entrada do CEP
    ERR_LEITURA_CNPJ_INVALIDO     = -340, ///< Erro na entrada do CNPJ
    ERR_LEITURA_EMAIL_INVALIDO    = -341, ///< Erro na entrada do e-mail
    ERR_LEITURA_DATA_ABERTURA_INVALIDA = -342, ///< Erro na entrada da data de abertura
    ERR_TELEFONE_DIGITOS         = -343, ///< Telefone inv�lido (n�o cont�m apenas d�gitos)
    ERR_CEP_DIGITOS              = -344, ///< CEP inv�lido (n�o cont�m apenas d�gitos)
    ERR_CEP_COMPRIMENTO          = -345, ///< CEP inv�lido (comprimento inv�lido)
    ERR_ESTADO_COMPRIMENTO      = -347, ///< Estado inv�lido (comprimento inv�lido)
    ERR_NUMERO_DIGITOS          = -348, ///< N�mero inv�lido (n�o cont�m apenas d�gitos)
    
} codigo_erro;

/**
 * Retorna a mensagem associada a um c�digo de erro.
 * @param code  O codigo_erro retornado pela fun��o.
 * @return      String imut�vel (n�o deve ser free()?da).
 */
const char *erro_msg(codigo_erro code);

#endif // ERROS_H
