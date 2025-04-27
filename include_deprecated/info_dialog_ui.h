#ifndef INFO_DIALOG_UI_H
#define INFO_DIALOG_UI_H

typedef enum {
    INFO_CADASTRO_FUNCIONARIO_SUCESSO, ///< Cadastro de funcion�rio realizado com sucesso
    INFO_CADASTRO_INDUSTRIA_SUCESSO, ///< Cadastro de ind�stria realizado com sucesso
    TITULO_CADASTRO_FUNCIONARIO, ///< T�tulo da tela de cadastro de funcion�rio
    TITULO_CADASTRO_INDUSTRIA, ///< T�tulo da tela de cadastro de ind�stria
    TITULO_CADASTRO_RESIDUOS, ///< T�tulo da tela de cadastro
} codigo_info;

/**
typedef enum {
    OPCAO_INVALIDA = -1, 
    OPCAO_LOGIN = 1,
    OPCAO_SOBRE = 2,
    OPCAO_SAIR = 0,
} codigo_opcao_login;

typedef enum {
    PRINCIPAL_OPCAO_INVALIDA = -1,
    OPCAO_CADASTRO_FUNCIONARIO = 1,
    OPCAO_CADASTRO_INDUSTRIA = 2,	
    OPCAO_CADASTRO_RESIDUOS = 3,
    OPCAO_RELATORIOS_INDUSTRIA = 4,
    OPCAO_RELATORIOS_GLOBAIS = 5,
    OPCAO_LOGOUT    = 9,
} codigo_opcao_principal;
*/

typedef enum {
    OPCAO_INVALIDA = -1,
    OPCAO_SAIR = 0,
    // menu_login
    OPCAO_LOGIN = 1,
    OPCAO_SOBRE = 2,
    // menu_principal
    OPCAO_CADASTRO_FUNCIONARIO = 1,
    OPCAO_CADASTRO_INDUSTRIA = 2,
    OPCAO_CADASTRO_RESIDUOS = 3,
    OPCAO_RELATORIOS_INDUSTRIA = 4,
    OPCAO_RELATORIOS_GLOBAIS = 5,
    OPCAO_LOGOUT = 9,
    

} codigo_opcao_menu;

void mostrar_dlg_info(const char * msg);
void mostrar_dlg_erro(const char * msg);
void mostrar_msg_pausa(void);
void mostrar_msg_erro(const char *msg);
const char *info_msg(codigo_info codigo);
//const char *opcao_login_msg(codigo_opcao_login codigo);
//const char *opcao_principal_msg(codigo_opcao_principal codigo);
/**
 * Retorna uma string correspondente ao c�digo da op��o de menu.
 * @param codigo C�digo da op��o de menu.
 */
const char *opcao_login_str(codigo_opcao_menu codigo);

#endif// INFO_DIALOG_UI_H