#include "prompt_ui.h"

static const struct {
    codigo_prompt code;
    const char *msg;
} prompt_map[] = {
    { PROMPT_CNPJ, "Digite o CNPJ da ind�stria (somente d�gitos): " },
    { PROMPT_NOME_RESPONSAVEL, "Digite o nome do Respons�vel/Gerente: " },
    { PROMPT_EMAIL_RESPONSAVEL, "Digite o e-mail do respons�vel: " },
    { PROMPT_RAZAO_SOCIAL, "Digite a raz�o social: " },
    { PROMPT_NOME_FANTASIA, "Digite o nome fantasia: " },
    { PROMPT_TELEFONE, "Digite o telefone: " },
    { PROMPT_ENDERECO, "Digite o endere�o: " },
    { PROMPT_DATA_ABERTURA, "Digite a data de abertura (dd/mm/aaaa): " },
    { PROMPT_LOGRADOURO, "Digite o logradouro: " },
    { PROMPT_NUMERO, "Digite o n�mero: " },
    { PROMPT_BAIRRO, "Digite o bairro: " },
    { PROMPT_CIDADE, "Digite a cidade: " },
    { PROMPT_ESTADO, "Digite o estado: " },
    { PROMPT_CEP, "Digite o CEP: " },
    { PROMPT_EMAIL_INDUSTRIA, "Digite o e-mail da ind�stria: " },
};

const char *prompt_msg(codigo_prompt code) {
    for (size_t i = 0; i < sizeof(prompt_map)/sizeof(prompt_map[0]); i++) {
        if (prompt_map[i].code == code)
            return prompt_map[i].msg;
    }
    return "Erro desconhecido.";
}

void mostrar_prompt(const char* prompt) {
    //const size_t PROMPT_WIDTH = 100; // Largura total do prompt (colunas)

    printf(">> %s:", prompt); // Exibe o prompt
}