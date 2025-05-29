#include "erros.h"
#include <stdio.h>




































































static const struct
{
    codigo_erro codigo;
    const char *msg;
} erros_map[] = {
    {ERR_ALOC_MEMORIA, "Erro ao alocar memória."},
    {ERR_OPCAO_INVALIDA, "Opção inválida. Escolha uma das opções válidas."},
    {ERR_LEITURA_INVALIDA, "Erro ao ler a entrada. Tente novamente."},
    {ERR_MATRICULA_INVALIDA, "Matrícula inválida. Deve ser um número inteiro de até 6 dígitos."},
    {ERR_FORMATO_DATA, "Formato inválido. Use mm/aaaa."},
    {ERR_CADASTRO_INDUSTRIA, "Erro ao cadastrar indústria."},
    {ERR_CNPJ_DUPLICADO, "CNPJ já cadastrado!"},
    {ERR_CNPJ_INVALIDO, "CNPJ inválido!"},
};

const char *erro_msg(codigo_erro codigo)
{
    for (size_t i = 0; i < sizeof(erros_map) / sizeof(erros_map[0]); i++)
    {
        if (erros_map[i].codigo == codigo)
            return erros_map[i].msg;
    }
    return "Erro desconhecido.";
}
