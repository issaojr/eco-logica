#ifndef INDUSTRIA_UI_H
#define INDUSTRIA_UI_H

#include <stdio.h>
#include <string.h>
#include "industria.h"
#include "utils.h"               
#include "industria_business.h"  // Para processar o cadastro de indústria
#include "logged_user_ui.h"      // Para mostrar o usuário logado
#include "screen_title_ui.h"     // Para mostrar o título da tela
#include "info_dialog_ui.h"     // Para mostrar mensagens de sucesso e erro
#include "erros.h"             // Para os códigos de erro
#include "entrada_ui.h"         // Para ler entradas do usuário
#include "prompt_ui.h"         // Para mensagens de prompt

/**
 * @brief Coleta os dados para o cadastro de uma nova indústria e os encaminha para o processamento.
 */
void iniciar_interface_industria(void);

#endif // INDUSTRIA_UI_H
