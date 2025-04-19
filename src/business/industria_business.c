#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "industria_business.h"
#include "industria.h"
#include "persistencia.h" // Usaremos uma função para salvar em CSV

int processarCadastroIndustria(Industria *ind) {
    if (ind == NULL)
        return -1;
    
    // Valida os dados (exemplo: garantir que o CNPJ não seja vazio)
    if (strlen(ind->cnpj) == 0) {
        return -1;
    }
    
    // Aqui você pode adicionar outras validações conforme necessário
    
    // Chama a função de persistência para salvar os dados da indústria em CSV
    int ret = salvarIndustriaCSV(ind, "industrias.csv");
    if (ret != 0) {
        return -2; // Erro ao salvar os dados
    }
    return ret;
}
