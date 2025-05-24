#ifndef FABRICA_ESTADOS_H
#define FABRICA_ESTADOS_H

#include <stdlib.h>
#include "estados/estado.h"

/**
 * Protótipos das funções para criar estados específicos
 */

// Estados de login e menu iniciais
estado_t *criar_estado_menu_login(void);
estado_t *criar_estado_form_login(void);
estado_t *criar_estado_menu_principal(void);
estado_t *criar_estado_sobre_projeto(void);
estado_t *criar_estado_msg_login_sucesso(void);
estado_t *criar_estado_msg_login_falha(void);
estado_t *criar_estado_msg_logout_sucesso(void);

// Estados de cadastro de usuarios e mensagens
estado_t *criar_estado_cadastro_funcionarios(void);
estado_t *criar_estado_listar_funcionarios(void);
estado_t *criar_estado_adicionar_funcionario(void);
estado_t *criar_estado_editar_funcionario(void);
estado_t *criar_estado_excluir_funcionario(void);
estado_t *criar_estado_msg_operacao_funcionario(void);
estado_t *criar_estado_msg_cadastro_funcionario(void);

// Estados de cadastro de industrias e mensagens
estado_t *criar_estado_cadastro_industrias(void);
estado_t *criar_estado_listar_industrias(void);
estado_t *criar_estado_adicionar_industria(void);
estado_t *criar_estado_editar_industria(void);
estado_t *criar_estado_excluir_industria(void);
estado_t *criar_estado_msg_operacao_industria(void);
estado_t *criar_estado_msg_cadastro_industria(void);

// Estados de atualização de residuos e mensagens
estado_t *criar_estado_atualizacao_residuos(void);
estado_t *criar_estado_msg_atualizacao_residuos(void);

// Estados de relatórios
estado_t *criar_estado_relatorios_industria(void);
estado_t *criar_estado_relatorios_globais(void);

// Estado de saída
estado_t *criar_estado_sair(void);

// Função para destruir estados
void destruir_estado(estado_t *estado);

#endif // FABRICA_ESTADOS_H
