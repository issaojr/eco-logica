#ifndef FABRICA_ESTADOS_H
#define FABRICA_ESTADOS_H

#include "estado.h"

/**
 * Protótipos das funções para criar estados específicos
 */

// Estados de login e menu iniciais
estado_t* criar_estado_menu_login(void);
estado_t* criar_estado_form_login(void);
estado_t* criar_estado_menu_principal(void);
estado_t* criar_estado_sobre_projeto(void);
estado_t* criar_estado_msg_login_sucesso(void);
estado_t* criar_estado_msg_login_falha(void);
estado_t* criar_estado_msg_logout_sucesso(void);

// Estados de cadastro e mensagens
estado_t* criar_estado_cadastro_funcionario(void);
estado_t* criar_estado_msg_cadastro_funcionario(void);
estado_t* criar_estado_cadastro_industria(void);
estado_t* criar_estado_msg_cadastro_industria(void);
estado_t* criar_estado_atualizacao_residuos(void);
estado_t* criar_estado_msg_atualizacao_residuos(void);

// Estados de relatórios
estado_t* criar_estado_relatorios_industria(void);
estado_t* criar_estado_submenu_relatorios_globais(void);
estado_t* criar_estado_rel_globais_ins_tot(void);
estado_t* criar_estado_rel_globais_total_gastos(void);
estado_t* criar_estado_rel_globais_regiao_maior(void);
estado_t* criar_estado_rel_globais_ind_menor(void);
estado_t* criar_estado_rel_globais_aporte_financeiro(void);

// Estado de saída
estado_t* criar_estado_sair(void);

#endif // FABRICA_ESTADOS_H