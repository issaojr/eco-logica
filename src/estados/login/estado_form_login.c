#include "estados/login/estado_form_login.h"

static int inicializar(void)
{
    return 0;
}

static estado_aplicacao processar(size_t entrada)
{
    funcionario_t *f_temp = malloc(sizeof(funcionario_t));
    if (!f_temp)
    {
        ui_exibir_erro("Erro ao alocar memória para funcionário.");
        return ESTADO_MENU_LOGIN;
    }

    /* Inicializa struct */
    memset(f_temp, 0, sizeof(funcionario_t));

    // Desenha a tela de login
    ui_desenhar_tela_form_login();

    ui_desenhar_cabecalho("INFORME SUAS CREDENCIAIS");

    // Apresenta formulário de login.
    // Matrícula e senha são lidas pelas funções de UI
    ui_ler_matricula_funcionario(f_temp->matricula, sizeof(f_temp->matricula));
    ui_ler_senha_funcionario(f_temp->hash_senha, sizeof(f_temp->hash_senha));

    // O processamento das credenciais é delegado é função de autenticação
    // na camada business (auth.h)
    // Se a autenticação for bem-sucedida, o funcionário é armazenado na sessão
    bool autenticou = business_autenticar(f_temp->matricula, f_temp->hash_senha);

    // Libera a memória alocada para o funcionário
    free(f_temp);

    // [TODO] Subistituir este novo estado por ESTADO_MENU_LOGIN ou
    // ESTADO_MENU_PRINCIPAL, dependendo se o login foi bem-sucedido ou não
    // Se o login for bem-sucedido, desenha a tela de sucesso
    // Se o login falhar, desenha a tela de erro
    if(autenticou)
    {
        ui_desenhar_tela_sucesso("LOGIN REALIZADO", "Bem-vindo ao sistema!");
        return ESTADO_MENU_PRINCIPAL;
    }
    else
    {
        ui_desenhar_tela_erro("LOGIN FALHOU", "Credenciais inválidas.");
        return ESTADO_MENU_LOGIN;
    }
}

static void finalizar(void)
{
}

static estado_aplicacao obter_id(void)
{
    return ESTADO_FORM_LOGIN;
}

estado_t *criar_estado_form_login(void)
{
    estado_t *estado = (estado_t*)malloc(sizeof(estado_t));
    if (estado)
    {
        estado->inicializar = inicializar;
        estado->processar = processar;
        estado->finalizar = finalizar;
        estado->obter_id = obter_id;
    }
    return estado;
}
