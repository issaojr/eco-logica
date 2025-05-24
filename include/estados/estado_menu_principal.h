#ifndef ESTADO_MENU_PRINCIPAL_H
#define ESTADO_MENU_PRINCIPAL_H

#include <stdlib.h>
#include <stdio.h>
#include "estados/estado.h"
#include "estados/estado_menu_utils.h"
#include "session.h"
#include "ui/ui_comum.h"
#include "ui/ui_tela_menu_principal.h"

/**
 * Cria uma instância do estado de menu principal
 * @return Ponteiro para o estado criado ou NULL em caso de falha
 */
estado_t *criar_estado_menu_principal(void);

#endif // ESTADO_MENU_PRINCIPAL_H
