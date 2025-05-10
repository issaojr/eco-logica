#ifndef UI_LISTA_FUNCIONARIO_H
#define UI_LISTA_FUNCIONARIO_H

#include "ui/ui_comum.h"
#include "persistencia/funcionario_dao.h"

/**
 * @brief Desenha a tela de lista de funcionários.
 */
void ui_desenhar_tela_lista_funcionarios(void);

/**
 * @brief Exibe a lista de funcionários cadastrados.
 */
void ui_exibir_lista_funcionarios(
    funcionario_t* funcionarios_out, 
    size_t max_funcionarios, 
    size_t* total_funcionarios_out);

#endif /* UI_LISTA_FUNCIONARIO_H */