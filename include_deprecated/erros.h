#ifndef ERROS_H
#define ERROS_H

// Definição dos códigos de erro
typedef enum {
    ERR_OK              = 0,    ///< Sem erro
    ERR_ALOC_MEMORIA      = -1,  ///< Erro de alocação de memória
    ERR_OPCAO_INVALIDA  = -10,  ///< Opção inválida
    ERR_OPCAO_INVALIDA_NUMERICA = -11, ///< Opção inválida (não numérica)
    ERR_LEITURA_INVALIDA = -20, ///< Erro de leitura (EOF ou string vazia)
    ERR_MATRICULA_INVALIDA = -30, ///< Matrícula inválida (não numérica ou fora do intervalo)
    ERR_LEITURA_NOME_INVALIDO = -40, ///< Nome inválido (vazio ou muito longo)
    ERR_NOME_VAZIO = -41, ///< Nome vazio
    ERR_LEITURA_SENHA_INVALIDA = -50, ///< Senha inválida (vazia ou muito longa)
    ERR_SENHA_VAZIA = -51, ///< Senha vazia
    ERR_FORMATO_DATA     = -100, ///< Formato de data inválido
    ERR_DATA_INVALIDA    = -101, ///< Data inexistente (ex.: 30/02)
    ERR_DATA_INVALIDA_MES = -102, ///< Data inválida (mês fora de intervalo)
    ERR_DATA_INVALIDA_ANO = -103, ///< Data inválida (ano fora de intervalo)
    ERR_DATA_INVALIDA_INTERVALO = -104, ///< Data inválida (intervalo de datas inválido)
    ERR_SQLITE           = -200, ///< Erro genérico do SQLite
    ERR_CADASTRO_INDUSTRIA        = -300, ///< Erro ao cadastrar indústria
    ERR_CNPJ_DUPLICADO            = -301, ///< CNPJ já cadastrado
    ERR_NOME_INDUSTRIA_INVALIDO   = -302, ///< Nome da indústria inválido
    ERR_EMAIL_RESPONSAVEL_INVALIDO= -303, ///< E-mail do responsável inválido
    ERR_RAZAO_SOCIAL_INVALIDA     = -304, ///< Razão Social inválida
    ERR_NOME_FANTASIA_INVALIDO    = -305, ///< Nome Fantasia inválido
    ERR_TELEFONE_INVALIDO         = -306, ///< Telefone inválido
    ERR_ENDERECO_INVALIDO         = -307, ///< Endereço inválido
    ERR_EMAIL_INVALIDO            = -308, ///< E-mail inválido
    ERR_DATA_ABERTURA_INVALIDA    = -309, ///< Data de Abertura inválida
    ERR_CNPJ_INVALIDO             = -310, ///< CNPJ inválido
    ERR_LOGRADOURO_INVALIDO       = -311, ///< Logradouro inválido
    ERR_NUMERO_INVALIDO           = -312, ///< Número inválido
    ERR_BAIRRO_INVALIDO           = -313, ///< Bairro inválido
    ERR_CIDADE_INVALIDA           = -314, ///< Cidade inválida
    ERR_ESTADO_INVALIDO           = -315, ///< Estado inválido
    ERR_CEP_INVALIDO              = -316,  ///< CEP inválido
    ERR_CNPJ_COMPRIMENTO         = -317, ///< CNPJ inválido (comprimento inválido)
    ERR_CNPJ_DIGITOS             = -318, ///< CNPJ inválido (não contém apenas dígitos)
    ERR_CNPJ_VAZIO               = -319, ///< CNPJ inválido (vazio)
    ERR_RAZAO_SOCIAL_VAZIO       = -320, ///< Razão Social inválida (vazia)
    ERR_NOME_FANTASIA_VAZIO      = -321, ///< Nome Fantasia inválido (vazio)
    ERR_TELEFONE_VAZIO           = -322, ///< Telefone inválido (vazio)
    ERR_ENDERECO_VAZIO           = -323, ///< Endereço inválido (vazio)
    ERR_LOGRADOURO_VAZIO         = -324, ///< Logradouro inválido (vazio)
    ERR_NUMERO_VAZIO             = -325, ///< Número inválido (vazio)
    ERR_BAIRRO_VAZIO             = -326, ///< Bairro inválido (vazio)
    ERR_CIDADE_VAZIA             = -327, ///< Cidade inválida (vazia)
    ERR_ESTADO_VAZIO             = -328, ///< Estado inválido (vazio)
    ERR_CEP_VAZIO                = -329,  ///< CEP inválido (vazio)
    ERR_LEITURA_RAZAO_SOCIAL_INVALIDA = -330, ///< Erro na entrada da razão social
    ERR_LEITURA_NOME_FANTASIA_INVALIDO = -331, ///< Erro na entrada do nome fantasia
    ERR_LEITURA_TELEFONE_INVALIDO = -332, ///< Erro na entrada do telefone
    ERR_LEITURA_ENDERECO_INVALIDO = -333, ///< Erro na entrada do endereço
    ERR_LEITURA_LOGRADOURO_INVALIDO = -334, ///< Erro na entrada do logradouro
    ERR_LEITURA_NUMERO_INVALIDO   = -335, ///< Erro na entrada do número
    ERR_LEITURA_BAIRRO_INVALIDO   = -336, ///< Erro na entrada do bairro
    ERR_LEITURA_CIDADE_INVALIDA   = -337, ///< Erro na entrada da cidade
    ERR_LEITURA_ESTADO_INVALIDO   = -338, ///< Erro na entrada do estado
    ERR_LEITURA_CEP_INVALIDO      = -339, ///< Erro na entrada do CEP
    ERR_LEITURA_CNPJ_INVALIDO     = -340, ///< Erro na entrada do CNPJ
    ERR_LEITURA_EMAIL_INVALIDO    = -341, ///< Erro na entrada do e-mail
    ERR_LEITURA_DATA_ABERTURA_INVALIDA = -342, ///< Erro na entrada da data de abertura
    ERR_TELEFONE_DIGITOS         = -343, ///< Telefone inválido (não contém apenas dígitos)
    ERR_CEP_DIGITOS              = -344, ///< CEP inválido (não contém apenas dígitos)
    ERR_CEP_COMPRIMENTO          = -345, ///< CEP inválido (comprimento inválido)
    ERR_ESTADO_COMPRIMENTO      = -347, ///< Estado inválido (comprimento inválido)
    ERR_NUMERO_DIGITOS          = -348, ///< Número inválido (não contém apenas dígitos)
    
} codigo_erro;

/**
 * Retorna a mensagem associada a um código de erro.
 * @param code  O codigo_erro retornado pela função.
 * @return      String imutável (não deve ser free()?da).
 */
const char *erro_msg(codigo_erro code);

#endif // ERROS_H
