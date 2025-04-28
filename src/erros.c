#include "erros.h"
#include <stdio.h>

// Mapeamento interno entre código e mensagem
// static const struct {
//     codigo_erro codigo;
//     const char *msg;
// } erros_map[] = {

    
//     { ERR_OPCAO_INVALIDA_NUMERICA, "Opção inválida. Deve ser um número." },
    
//     { ERR_LEITURA_NOME_INVALIDO, "Erro na entrada do nome. Tente novamente." },
//     { ERR_NOME_VAZIO,     "O nome não pode estar vazio. Tente novamente." },
//     { ERR_LEITURA_SENHA_INVALIDA, "Erro na entrada da senha. Tente novamente." },
//     { ERR_SENHA_VAZIA,    "A senha não pode estar vazia. Tente novamente." },
//     { ERR_DATA_INVALIDA,  "Data inválida." },
//     { ERR_DATA_INVALIDA_MES, "Mês fora de intervalo." },
//     { ERR_DATA_INVALIDA_ANO, "Ano fora de intervalo." },
//     { ERR_DATA_INVALIDA_INTERVALO, "Intervalo de datas inválido." },
//     { ERR_SQLITE,         "Falha no banco de dados." },
    
//     { ERR_NOME_INDUSTRIA_INVALIDO, "Nome da indústria inválido!" },
//     { ERR_EMAIL_RESPONSAVEL_INVALIDO, "E-mail do responsável inválido!" },
//     { ERR_RAZAO_SOCIAL_INVALIDA, "Razão Social inválida!" },
//     { ERR_NOME_FANTASIA_INVALIDO, "Nome Fantasia inválido!" },
//     { ERR_TELEFONE_INVALIDO, "Telefone inválido!" },
//     { ERR_ENDERECO_INVALIDO, "Endereço inválido!" },
//     { ERR_EMAIL_INVALIDO, "E-mail inválido!" },
//     { ERR_DATA_ABERTURA_INVALIDA, "Data de Abertura inválida!" },
    
//     { ERR_LOGRADOURO_INVALIDO, "Logradouro inválido!" },
//     { ERR_NUMERO_INVALIDO, "Número inválido!" },
//     { ERR_BAIRRO_INVALIDO, "Bairro inválido!" },
//     { ERR_CIDADE_INVALIDA, "Cidade inválida!" },
//     { ERR_ESTADO_INVALIDO, "Estado inválido!" },
//     { ERR_CEP_INVALIDO, "CEP inválido!" },
//     { ERR_CNPJ_COMPRIMENTO, "O CNPJ deve conter exatamente 14 dígitos." },
//     { ERR_CNPJ_DIGITOS, "O CNPJ deve conter apenas dígitos." },
//     { ERR_CNPJ_VAZIO, "O CNPJ não pode estar vazio." },
//     { ERR_RAZAO_SOCIAL_VAZIO, "A razão social não pode estar vazia." },
//     { ERR_NOME_FANTASIA_VAZIO, "O nome fantasia não pode estar vazio." },
//     { ERR_TELEFONE_VAZIO, "O telefone não pode estar vazio." },
//     { ERR_ENDERECO_VAZIO, "O endereço não pode estar vazio." },
//     { ERR_LOGRADOURO_VAZIO, "O logradouro não pode estar vazio." },
//     { ERR_NUMERO_VAZIO, "O número não pode estar vazio." },
//     { ERR_BAIRRO_VAZIO, "O bairro não pode estar vazio." },
//     { ERR_CIDADE_VAZIA, "A cidade não pode estar vazia." },
//     { ERR_ESTADO_VAZIO, "O estado não pode estar vazio." },
//     { ERR_CEP_VAZIO, "O CEP não pode estar vazio." },
//     { ERR_LEITURA_RAZAO_SOCIAL_INVALIDA, "Erro na entrada da razão social. Tente novamente." },
//     { ERR_LEITURA_NOME_FANTASIA_INVALIDO, "Erro na entrada do nome fantasia. Tente novamente." },
//     { ERR_LEITURA_TELEFONE_INVALIDO, "Erro na entrada do telefone. Tente novamente." },
//     { ERR_LEITURA_ENDERECO_INVALIDO, "Erro na entrada do endereço. Tente novamente." },
//     { ERR_LEITURA_LOGRADOURO_INVALIDO, "Erro na entrada do logradouro. Tente novamente." },
//     { ERR_LEITURA_NUMERO_INVALIDO, "Erro na entrada do número. Tente novamente." },
//     { ERR_LEITURA_BAIRRO_INVALIDO, "Erro na entrada do bairro. Tente novamente." },
//     { ERR_LEITURA_CIDADE_INVALIDA, "Erro na entrada da cidade. Tente novamente." },
//     { ERR_LEITURA_ESTADO_INVALIDO, "Erro na entrada do estado. Tente novamente." },
//     { ERR_LEITURA_CEP_INVALIDO, "Erro na entrada do CEP. Tente novamente." },
//     { ERR_LEITURA_CNPJ_INVALIDO, "Erro na entrada do CNPJ. Tente novamente." },
//     { ERR_LEITURA_EMAIL_INVALIDO, "Erro na entrada do e-mail. Tente novamente." },
//     { ERR_LEITURA_DATA_ABERTURA_INVALIDA, "Erro na entrada da data de abertura. Tente novamente." },
//     { ERR_TELEFONE_DIGITOS, "O telefone deve conter apenas dígitos." },
//     { ERR_CEP_DIGITOS, "O CEP deve conter apenas dígitos." },
//     { ERR_CEP_COMPRIMENTO, "O CEP deve conter exatamente 8 dígitos." },
//     { ERR_ESTADO_COMPRIMENTO, "O estado deve conter exatamente 2 letras." },
//     { ERR_NUMERO_DIGITOS, "O número deve conter apenas dígitos." },
        
// };

static const struct {
    codigo_erro codigo;
    const char *msg;
} erros_map[] = {
    { ERR_ALOC_MEMORIA,  "Erro de alocação de memória." },
    { ERR_OPCAO_INVALIDA, "Opção inválida. Escolha uma das opções válidas." },
    { ERR_LEITURA_INVALIDA, "Erro ao ler a entrada. Tente novamente." },
    { ERR_MATRICULA_INVALIDA, "Matrícula inválida. Deve ser um número inteiro de até 6 dígitos." },    
    { ERR_FORMATO_DATA,   "Formato inválido. Use mm/aaaa." },
    { ERR_CADASTRO_INDUSTRIA, "Erro ao cadastrar indústria." },
    { ERR_CNPJ_DUPLICADO, "CNPJ já cadastrado!" },
    { ERR_CNPJ_INVALIDO, "CNPJ inválido!" },
};

const char *erro_msg(codigo_erro codigo) {
    for (size_t i = 0; i < sizeof(erros_map)/sizeof(erros_map[0]); i++) {
        if (erros_map[i].codigo == codigo)
            return erros_map[i].msg;
    }
    return "Erro desconhecido.";
}
