#include <stdlib.h>
#include "fabrica_estados.h"
#include "estado.h"
#include "estados.h"
#include "ui/ui_comum.h"

// Stubs para estados ainda não implementados
// Serão substituídos por implementações reais futuramente

// Handlers para estado 'Sobre o Projeto'
static int sobre_inicializar(void) {
    ui_exibir_titulo("Sobre o Projeto", NULL);
    ui_exibir_info("Sistema EcoL\xF3gica - vers\xE3o acad\xEAmica");
    ui_exibir_info("Autor: Issao Hanaoka Junior");
    ui_exibir_info("UNIP - Universidade Paulista");
    ui_exibir_info("PIM IV - Projeto Integrado Multidisciplinar");
    ui_exibir_info("2025 - 1o Semestre");
    return 0;
}
static estado_aplicacao sobre_processar(size_t opcao) {
    ui_pausar(NULL);
    return ESTADO_MENU_LOGIN;
}
static void sobre_finalizar(void) {}
static estado_aplicacao sobre_obter_id(void) { return ESTADO_SOBRE_PROJETO; }

estado_t* criar_estado_sobre_projeto(void) {
    estado_t* est = malloc(sizeof(estado_t));
    if (!est) return NULL;
    est->inicializar = sobre_inicializar;
    est->processar = sobre_processar;
    est->finalizar = sobre_finalizar;
    est->obter_id = sobre_obter_id;
    return est;
}

estado_t* criar_estado_msg_logout_sucesso(void) {
    return NULL;
}

estado_t* criar_estado_cadastro_funcionario(void) {
    return NULL;
}

estado_t* criar_estado_msg_cadastro_funcionario(void) {
    return NULL;
}

estado_t* criar_estado_cadastro_industria(void) {
    return NULL;
}

estado_t* criar_estado_msg_cadastro_industria(void) {
    return NULL;
}

estado_t* criar_estado_atualizacao_residuos(void) {
    return NULL;
}

estado_t* criar_estado_msg_atualizacao_residuos(void) {
    return NULL;
}

estado_t* criar_estado_relatorios_industria(void) {
    return NULL;
}

estado_t* criar_estado_submenu_relatorios_globais(void) {
    return NULL;
}

estado_t* criar_estado_rel_globais_ins_tot(void) {
    return NULL;
}

estado_t* criar_estado_rel_globais_total_gastos(void) {
    return NULL;
}

estado_t* criar_estado_rel_globais_regiao_maior(void) {
    return NULL;
}

estado_t* criar_estado_rel_globais_ind_menor(void) {
    return NULL;
}

estado_t* criar_estado_rel_globais_aporte_financeiro(void) {
    return NULL;
}