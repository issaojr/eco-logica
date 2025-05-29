#ifndef ESTADO_LISTAR_INDUSTRIAS_H
#define ESTADO_LISTAR_INDUSTRIAS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estados/estado.h"
#include "estados/estados.h"
#include "business/business_industria.h"
#include "persistencia/industria_dao.h"
#include "estruturas/relatorio.h"
#include "ui/industrias/ui_tela_cadastro_industrias.h"
#include "ui/relatorios/ui_relatorios.h"
#include "ui/ui_comum.h"
#include "session.h"

/**
 * Cria uma instância do estado para listar indústrias
 * @return Ponteiro para o estado criado ou NULL em caso de falha
 */
estado_t *criar_estado_listar_industrias(void);

#endif 
