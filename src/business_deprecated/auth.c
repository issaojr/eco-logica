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

    // Valida o funcionário utilizando os dados persistidos no CSV
    if (validarFuncionarioCSV(matricula, senhaInput, &temp) == 0) {
        // Aloca dinamicamente a memória para salvar o usuário logado
        Funcionario *usuarioLogado = (Funcionario *)malloc(sizeof(Funcionario));
        if (usuarioLogado == NULL) {
            return -1;
        }
        // Copia os dados do funcionário validado para a nova memória
        *usuarioLogado = temp;
        
        set_usuario_logado(usuarioLogado); // Armazena o usuário logado na sessão

        return 0; // Login bem-sucedido
    } else {
        return -2; // Login falhou
    }
}



