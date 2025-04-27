#ifndef CADASTRO_UI_H
#define CADASTRO_UI_H

#include <stdio.h>
#include <string.h>
#include "funcionario.h"
#include "crypto.h"     // Para usar xorCipher
#include "funcionario_business.h"   // Para usar processaCadastro
#include "utils.h"     // Para usar clearConsole
#include "logged_user_ui.h" // Para usar showLoggedUser
#include "screen_title_ui.h" // Para usar showTitleScreen
#include "info_dialog_ui.h" // Para usar showCadastroSuccessMessage e showCadastroErrorMessage
#include "entrada_ui.h" // Para usar readMatricula, readName, readPassword

/**
 * @brief Coleta os dados necessários para o cadastro de um novo usuário. 
 * Responsável por interagir com o usuário e preencher a estrutura Funcionario.
 * Também responsável por chamar a regra de negócio para o cadastro.
 * 
 */
void iniciar_interface_funcionario(void);

#endif // CADASTRO_UI_H
