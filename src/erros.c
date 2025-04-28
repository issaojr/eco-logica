#include "erros.h"
#include <stdio.h>

// Mapeamento interno entre c�digo e mensagem
// static const struct {
//     codigo_erro codigo;
//     const char *msg;
// } erros_map[] = {

    
//     { ERR_OPCAO_INVALIDA_NUMERICA, "Op��o inv�lida. Deve ser um n�mero." },
    
//     { ERR_LEITURA_NOME_INVALIDO, "Erro na entrada do nome. Tente novamente." },
//     { ERR_NOME_VAZIO,     "O nome n�o pode estar vazio. Tente novamente." },
//     { ERR_LEITURA_SENHA_INVALIDA, "Erro na entrada da senha. Tente novamente." },
//     { ERR_SENHA_VAZIA,    "A senha n�o pode estar vazia. Tente novamente." },
//     { ERR_DATA_INVALIDA,  "Data inv�lida." },
//     { ERR_DATA_INVALIDA_MES, "M�s fora de intervalo." },
//     { ERR_DATA_INVALIDA_ANO, "Ano fora de intervalo." },
//     { ERR_DATA_INVALIDA_INTERVALO, "Intervalo de datas inv�lido." },
//     { ERR_SQLITE,         "Falha no banco de dados." },
    
//     { ERR_NOME_INDUSTRIA_INVALIDO, "Nome da ind�stria inv�lido!" },
//     { ERR_EMAIL_RESPONSAVEL_INVALIDO, "E-mail do respons�vel inv�lido!" },
//     { ERR_RAZAO_SOCIAL_INVALIDA, "Raz�o Social inv�lida!" },
//     { ERR_NOME_FANTASIA_INVALIDO, "Nome Fantasia inv�lido!" },
//     { ERR_TELEFONE_INVALIDO, "Telefone inv�lido!" },
//     { ERR_ENDERECO_INVALIDO, "Endere�o inv�lido!" },
//     { ERR_EMAIL_INVALIDO, "E-mail inv�lido!" },
//     { ERR_DATA_ABERTURA_INVALIDA, "Data de Abertura inv�lida!" },
    
//     { ERR_LOGRADOURO_INVALIDO, "Logradouro inv�lido!" },
//     { ERR_NUMERO_INVALIDO, "N�mero inv�lido!" },
//     { ERR_BAIRRO_INVALIDO, "Bairro inv�lido!" },
//     { ERR_CIDADE_INVALIDA, "Cidade inv�lida!" },
//     { ERR_ESTADO_INVALIDO, "Estado inv�lido!" },
//     { ERR_CEP_INVALIDO, "CEP inv�lido!" },
//     { ERR_CNPJ_COMPRIMENTO, "O CNPJ deve conter exatamente 14 d�gitos." },
//     { ERR_CNPJ_DIGITOS, "O CNPJ deve conter apenas d�gitos." },
//     { ERR_CNPJ_VAZIO, "O CNPJ n�o pode estar vazio." },
//     { ERR_RAZAO_SOCIAL_VAZIO, "A raz�o social n�o pode estar vazia." },
//     { ERR_NOME_FANTASIA_VAZIO, "O nome fantasia n�o pode estar vazio." },
//     { ERR_TELEFONE_VAZIO, "O telefone n�o pode estar vazio." },
//     { ERR_ENDERECO_VAZIO, "O endere�o n�o pode estar vazio." },
//     { ERR_LOGRADOURO_VAZIO, "O logradouro n�o pode estar vazio." },
//     { ERR_NUMERO_VAZIO, "O n�mero n�o pode estar vazio." },
//     { ERR_BAIRRO_VAZIO, "O bairro n�o pode estar vazio." },
//     { ERR_CIDADE_VAZIA, "A cidade n�o pode estar vazia." },
//     { ERR_ESTADO_VAZIO, "O estado n�o pode estar vazio." },
//     { ERR_CEP_VAZIO, "O CEP n�o pode estar vazio." },
//     { ERR_LEITURA_RAZAO_SOCIAL_INVALIDA, "Erro na entrada da raz�o social. Tente novamente." },
//     { ERR_LEITURA_NOME_FANTASIA_INVALIDO, "Erro na entrada do nome fantasia. Tente novamente." },
//     { ERR_LEITURA_TELEFONE_INVALIDO, "Erro na entrada do telefone. Tente novamente." },
//     { ERR_LEITURA_ENDERECO_INVALIDO, "Erro na entrada do endere�o. Tente novamente." },
//     { ERR_LEITURA_LOGRADOURO_INVALIDO, "Erro na entrada do logradouro. Tente novamente." },
//     { ERR_LEITURA_NUMERO_INVALIDO, "Erro na entrada do n�mero. Tente novamente." },
//     { ERR_LEITURA_BAIRRO_INVALIDO, "Erro na entrada do bairro. Tente novamente." },
//     { ERR_LEITURA_CIDADE_INVALIDA, "Erro na entrada da cidade. Tente novamente." },
//     { ERR_LEITURA_ESTADO_INVALIDO, "Erro na entrada do estado. Tente novamente." },
//     { ERR_LEITURA_CEP_INVALIDO, "Erro na entrada do CEP. Tente novamente." },
//     { ERR_LEITURA_CNPJ_INVALIDO, "Erro na entrada do CNPJ. Tente novamente." },
//     { ERR_LEITURA_EMAIL_INVALIDO, "Erro na entrada do e-mail. Tente novamente." },
//     { ERR_LEITURA_DATA_ABERTURA_INVALIDA, "Erro na entrada da data de abertura. Tente novamente." },
//     { ERR_TELEFONE_DIGITOS, "O telefone deve conter apenas d�gitos." },
//     { ERR_CEP_DIGITOS, "O CEP deve conter apenas d�gitos." },
//     { ERR_CEP_COMPRIMENTO, "O CEP deve conter exatamente 8 d�gitos." },
//     { ERR_ESTADO_COMPRIMENTO, "O estado deve conter exatamente 2 letras." },
//     { ERR_NUMERO_DIGITOS, "O n�mero deve conter apenas d�gitos." },
        
// };

static const struct {
    codigo_erro codigo;
    const char *msg;
} erros_map[] = {
    { ERR_ALOC_MEMORIA,  "Erro de aloca��o de mem�ria." },
    { ERR_OPCAO_INVALIDA, "Op��o inv�lida. Escolha uma das op��es v�lidas." },
    { ERR_LEITURA_INVALIDA, "Erro ao ler a entrada. Tente novamente." },
    { ERR_MATRICULA_INVALIDA, "Matr�cula inv�lida. Deve ser um n�mero inteiro de at� 6 d�gitos." },    
    { ERR_FORMATO_DATA,   "Formato inv�lido. Use mm/aaaa." },
    { ERR_CADASTRO_INDUSTRIA, "Erro ao cadastrar ind�stria." },
    { ERR_CNPJ_DUPLICADO, "CNPJ j� cadastrado!" },
    { ERR_CNPJ_INVALIDO, "CNPJ inv�lido!" },
};

const char *erro_msg(codigo_erro codigo) {
    for (size_t i = 0; i < sizeof(erros_map)/sizeof(erros_map[0]); i++) {
        if (erros_map[i].codigo == codigo)
            return erros_map[i].msg;
    }
    return "Erro desconhecido.";
}
