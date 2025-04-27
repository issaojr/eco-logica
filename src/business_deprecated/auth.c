#include <stdio.h>
#include <string.h>
#include <stdlib.h>     // Para usar malloc e free
#include "crypto.h"
#include "auth.h"
#include "funcionario.h"
#include "session.h"
#include "persistencia.h"

int performLogin(int matricula, const char *senhaInput) {
    
    Funcionario temp;

    // Valida o funcion�rio utilizando os dados persistidos no CSV
    if (validarFuncionarioCSV(matricula, senhaInput, &temp) == 0) {
        // Aloca dinamicamente a mem�ria para salvar o usu�rio logado
        Funcionario *usuarioLogado = (Funcionario *)malloc(sizeof(Funcionario));
        if (usuarioLogado == NULL) {
            return -1;
        }
        // Copia os dados do funcion�rio validado para a nova mem�ria
        *usuarioLogado = temp;
        
        setUsuarioLogado(usuarioLogado); // Armazena o usu�rio logado na sess�o

        return 0; // Login bem-sucedido
    } else {
        return -2; // Login falhou
    }
}



