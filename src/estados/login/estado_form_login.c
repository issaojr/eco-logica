#include "estados/login/estado_form_login.h"

// Variáveis específicas deste estado
static char matricula[8];
static char senha[64];

// Funções específicas deste estado
static int inicializar(void)
{
    // matricula = NULL;
    memset(senha, 0, sizeof(senha));

    return 0; // sucesso
}

static estado_aplicacao processar(size_t entrada)
{
    // Desenha a tela de login
    ui_desenhar_tela_form_login();

    ui_desenhar_cabecalho("INFORME SUAS CREDENCIAIS");

    // Apresenta formulário de login.
    // Matrícula e senha são lidas pelas funções de UI
    ui_ler_matricula_funcionario(matricula, sizeof(matricula));
    ui_ler_senha_funcionario(senha, sizeof(senha));

    // O processamento das credenciais é delegado é função de autenticação
    // na camada business (auth.h)
    // Se a autenticação for bem-sucedida, o funcionário é armazenado na sessão
    business_autenticar(matricula, senha);

    // [TODO] Subistituir este novo estado por ESTADO_MENU_LOGIN ou
    // ESTADO_MENU_PRINCIPAL, dependendo se o login foi bem-sucedido ou não
    // Se o login for bem-sucedido, desenha a tela de sucesso
    // Se o login falhar, desenha a tela de erro
    return ESTADO_MSG_LOGIN;
}

static void finalizar(void)
{
    // Limpa a senha após o uso
    memset(senha, 0, sizeof(senha));
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
