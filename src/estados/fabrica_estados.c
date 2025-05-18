#include "estados/fabrica_estados.h"

/* Estados da Tela de Inicial */
#include "estados/estado_menu_principal.h"
#include "estados/estado_sair.h"
#include "estados/estado_sobre_projeto.h"

/* Estados de Tela de Login */
#include "estados/login/estado_form_login.h"
#include "estados/login/estado_logout.h"
#include "estados/login/estado_menu_login.h"
#include "estados/login/estado_msg_login.h"
#include "estados/login/estado_msg_logout_falha.h"
#include "estados/login/estado_msg_logout_sucesso.h"

/* Estados de Funcionários */
#include "estados/funcionarios/estado_adicionar_funcionario.h"
#include "estados/funcionarios/estado_cadastro_funcionarios.h"
#include "estados/funcionarios/estado_editar_funcionario.h"
#include "estados/funcionarios/estado_excluir_funcionario.h"
#include "estados/funcionarios/estado_listar_funcionarios.h"
#include "estados/funcionarios/estado_msg_cadastro_funcionario.h"
#include "estados/funcionarios/estado_msg_operacao_funcionario.h"

/* Estados de Indústrias */
#include "estados/industrias/estado_adicionar_industria.h"
#include "estados/industrias/estado_cadastro_industrias.h"
#include "estados/industrias/estado_editar_industria.h"
#include "estados/industrias/estado_excluir_industria.h"
#include "estados/industrias/estado_listar_industrias.h"
#include "estados/industrias/estado_msg_cadastro_industria.h"
#include "estados/industrias/estado_msg_operacao_industria.h"

/* Estados de Resíduos */
#include "estados/residuos/estado_atualizacao_residuos.h"
#include "estados/residuos/estado_msg_atualizacao_residuos.h"

/* Estados de Relatórios */
#include "estados/relatorios/estado_relatorios_globais.h"
#include "estados/relatorios/estado_relatorios_industria.h"

estado_t *criar_estado(estado_aplicacao id)
{
    switch (id)
    {
    case ESTADO_MENU_LOGIN:
        return criar_estado_menu_login();
    case ESTADO_FORM_LOGIN:
        return criar_estado_form_login();
    case ESTADO_SOBRE_PROJETO:
        return criar_estado_sobre_projeto();
    case ESTADO_MSG_LOGIN:
        return criar_estado_msg_login_sucesso();
    case ESTADO_LOGOUT:
        return criar_estado_logout();
    case ESTADO_MSG_LOGOUT_FALHA:
        return criar_estado_msg_logout_falha();
    case ESTADO_MSG_LOGOUT_SUCESSO:
        return criar_estado_msg_logout_sucesso();
    case ESTADO_MENU_PRINCIPAL:
        return criar_estado_menu_principal();
    case ESTADO_CADASTRO_FUNCIONARIOS:
        return criar_estado_cadastro_funcionarios();
    case ESTADO_LISTAR_FUNCIONARIOS:
        return criar_estado_listar_funcionarios();
    case ESTADO_ADICIONAR_FUNCIONARIO:
        return criar_estado_adicionar_funcionario();
    case ESTADO_EDITAR_FUNCIONARIO:
        return criar_estado_editar_funcionario();
    case ESTADO_EXCLUIR_FUNCIONARIO:
        return criar_estado_excluir_funcionario();
    case ESTADO_MSG_OPERACAO_FUNCIONARIO:
        return criar_estado_msg_operacao_funcionario();
    case ESTADO_MSG_CADASTRO_FUNCIONARIO:
        return criar_estado_msg_cadastro_funcionario();
    case ESTADO_CADASTRO_INDUSTRIAS:
        return criar_estado_cadastro_industrias();
    case ESTADO_LISTAR_INDUSTRIAS:
        return criar_estado_listar_industrias();
    case ESTADO_ADICIONAR_INDUSTRIA:
        return criar_estado_adicionar_industria();
    case ESTADO_EDITAR_INDUSTRIA:
        return criar_estado_editar_industria();
    case ESTADO_EXCLUIR_INDUSTRIA:
        return criar_estado_excluir_industria();
    case ESTADO_MSG_OPERACAO_INDUSTRIA:
        return criar_estado_msg_operacao_industria();
    case ESTADO_MSG_CADASTRO_INDUSTRIA:
        return criar_estado_msg_cadastro_industria();
    case ESTADO_ATUALIZACAO_RESIDUOS:
        return criar_estado_atualizacao_residuos();
    case ESTADO_MSG_ATUALIZACAO_RESIDUOS:
        return criar_estado_msg_atualizacao_residuos();
    case ESTADO_RELATORIOS_INDUSTRIA:
        return criar_estado_relatorios_industria();
    case ESTADO_RELATORIOS_GLOBAIS:
        return criar_estado_relatorios_globais();
    case ESTADO_SAIR:
        return criar_estado_sair();
    default:
        return NULL;
    }
}

/**
 * Implementação do destrutor de estados
 */
void destruir_estado(estado_t *estado)
{
    if (estado)
    {
        // Chamar a função de finalização do estado, se existir
        if (estado->finalizar)
        {
            estado->finalizar();
        }
        free(estado);
    }
}