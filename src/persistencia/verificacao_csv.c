#include "persistencia/funcionario_dao.h"
#include "persistencia/industria_dao.h"
#include "persistencia/residuo_dao.h"

#ifdef _WIN32
    #include <direct.h>
    #include <sys/stat.h>
    #define stat _stat
#else
    #include <sys/stat.h>
#endif

/**
 * Verifica e corrige a integridade de todos os arquivos CSV do sistema
 * @return true se todas as verificações foram bem sucedidas, false caso contrário
 */
bool verificar_arquivos_csv(char *erro_out)
{

    char msg_erro_func[512] = {0};
    char msg_erro_ind[512] = {0};
    char msg_erro_res[512] = {0};

    bool status_func = verificar_csv_funcionario(msg_erro_func);
    bool status_ind = verificar_csv_industria(msg_erro_ind);
    bool status_res = verificar_csv_residuo(msg_erro_res);

    snprintf(erro_out, 512,
        "Verificação de arquivos CSV:\n"
        "Funcionários: %s\n"
        "Indústrias: %s\n"
        "Resíduos: %s\n",
        status_func ? "OK" : msg_erro_func,
        status_ind ? "OK" : msg_erro_ind,
        status_res ? "OK" : msg_erro_res);

    return status_func && status_ind && status_res;
}

bool verificar_diretorio_dados(char *erro_out)
{
    struct stat st;
    if (stat("dados", &st) != 0 || !(st.st_mode & S_IFDIR))
    {
        if (erro_out)
        {
            strcpy(erro_out,
                "A pasta 'dados/' não foi encontrada.\n"
                "Certifique-se de estar executando o programa a partir da pasta 'bin/'.\n"
                "Exemplo:\n"
                "  cd bin\n"
                "  ./ecologica\n");
        }
        return false;
    }
    return true;
}
