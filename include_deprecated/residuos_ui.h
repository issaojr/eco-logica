#ifndef RESIDUOS_UI_H
#define RESIDUOS_UI_H

#include <stdio.h>
#include <string.h>
#include "residuos.h"
#include "utils.h"             // clearConsole, pauseConsole
#include "residuos_business.h"// processarAtualizacaoMensal
#include "logged_user_ui.h"   // showLoggedUser
#include "screen_title_ui.h"  // showTitleScreen
#include "info_dialog_ui.h"  // showInfoDialog, showErrorDialog
#include "strings_globais.h" // MSG_ENTER_CONTINUAR
#include "erros.h"
#include "periodo_ui.h"      // ler_mes_ano

/**
 * @brief Inicia a tela de input para atualização mensal de resíduos e custos.
 */
void iniciar_interface_residuos(void);

#endif // RESIDUOS_UI_H
