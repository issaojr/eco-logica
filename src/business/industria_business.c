#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "industria_business.h"
#include "industria.h"
#include "persistencia.h" // Usaremos uma fun��o para salvar em CSV

int processarCadastroIndustria(Industria *ind) {
    if (ind == NULL)
        return -1;
    
    // Valida os dados (exemplo: garantir que o CNPJ n�o seja vazio)
    if (strlen(ind->cnpj) == 0) {
        printf("CNPJ n�o pode ser vazio.\n");
        return -1;
    }
    
    // Aqui voc� pode adicionar outras valida��es conforme necess�rio
    
    // Chama a fun��o de persist�ncia para salvar os dados da ind�stria em CSV
    int ret = salvarIndustriaCSV(ind, "industrias.csv");
    if (ret == 0) {
        printf("Dados salvos com sucesso em 'industrias.csv'.\n");
    } else {
        printf("Erro ao salvar os dados da ind�stria.\n");
    }
    
    return ret;
}
