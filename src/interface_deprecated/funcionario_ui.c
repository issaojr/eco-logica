
#include "funcionario_ui.h"
#include "entrada_ui.h"

void iniciar_interface_funcionario() {
    
    int matricula;
    char nome[150];
    char senha[50];

    mostrar_usuario_autenticado(); // Exibe o usu�rio logado, se houver
    mostrar_titulo(info_msg(TITULO_CADASTRO_FUNCIONARIO)); // Exibe o t�tulo da tela de cadastro

    // Coleta a matr�cula
    matricula = ler_matricula("Matr�cula: "); // L� a matr�cula do usu�rio
    
    // Ler o nome do novo usu�rio
    ler_nome("Nome: ", nome, sizeof(nome)); // L� o nome do novo usu�rio

    // Coleta a senha do novo usu�rio
    ler_senha("Senha: ", senha, sizeof(senha)); // L� a senha do novo usu�rio

    // Inicia processamento do cadastro
    codigo_erro resultado = processa_cadastro_funcionario(matricula, nome, senha);

    // Verifica se o resultado do cadastro foi bem-sucedido
    if(resultado == ERR_OK) {
        mostrar_dlg_info(info_msg(INFO_CADASTRO_FUNCIONARIO_SUCESSO)); // Exibe mensagem de sucesso
    } else {
        mostrar_dlg_erro(erro_msg(resultado)); // Exibe mensagem de erro
    }
    
}
