#include "persistencia/funcionario_dao.h"
#include "persistencia/industria_dao.h"
#include "persistencia/residuo_dao.h"

/**
 * Verifica e corrige a integridade de todos os arquivos CSV do sistema
 * @return true se todas as verificações foram bem sucedidas, false caso contrário
 */
bool verificar_arquivos_csv(void)
{
    bool status_func = verificar_csv_funcionario();
    bool status_ind = verificar_csv_industria();
    bool status_res = verificar_csv_residuo();

    return status_func && status_ind && status_res;
}
