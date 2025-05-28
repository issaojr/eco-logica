#ifndef UI_TELA_ATUALIZACAO_RESIDUOS_H
#define UI_TELA_ATUALIZACAO_RESIDUOS_H

#include <stdio.h>
#include <stdlib.h>
#include "ui/ui_comum.h"
#include "ui/ui_menu.h"
#include "ui/ui_form.h"
#include "estruturas/residuo.h"
#include "estruturas/industria.h"
#include "estruturas/funcionario.h"
#include "session.h"

void ui_desenhar_tela_inicial_residuos(funcionario_t *f, industria_t *i);
void ui_desenhar_tela_final_residuos(funcionario_t *f, industria_t *i, residuo_t *r);
void ui_exibir_form_inicial_residuos(industria_t *i);
void ui_exibir_form_final_residuos(residuo_t *r);

#endif