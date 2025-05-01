#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "estados/estado_menu_principal.h"
#include "tela_menu_principal_ui.h"
#include "estado_menu_utils.h"
#include "session.h"

// Funções específicas deste estado
static int inicializar(void) {
    // Limpar a tela
    system("cls");
    
    // Obter data e hora atual
    time_t t = time(NULL);
    struct tm *tm_info = localtime(&t);
    char data_hora[64];
    strftime(data_hora, sizeof(data_hora), "%d/%m/%Y %H:%M", tm_info);
    
    // Exibe informações do usuário logado
    funcionario_t *usuario = get_usuario_logado();
    if (usuario) {
        printf("???????????????????????????????????????????????????????\n");
        printf("? Usuário: %-20s      Matr: %-6d ?\n", usuario->nome, usuario->matricula);
        printf("? Sessão iniciada em: %-30s ?\n", data_hora);
        printf("???????????????????????????????????????????????????????\n\n");
    }
    
    printf("EcoLógica: Menu Principal\n");
    printf("==================================================\n\n");
    
    // Resumo de informações importantes
    printf("Resumo do Sistema:\n");
    printf("• Indústrias cadastradas: [Funcionalidade a implementar]\n");
    printf("• Último relatório gerado: [Funcionalidade a implementar]\n");
    printf("• Atualizações pendentes: [Funcionalidade a implementar]\n\n");
    
    printf("Escolha uma opção >>\n\n");
    
    return 0; // sucesso
}

static estado_aplicacao processar(size_t entrada) {
    // Usar a função utilitária para processar o menu
    return processar_estado_menu(
        tela_menu_principal_mapa,
        tela_menu_principal_mapa_n,
        tela_menu_principal_prompt,
        ESTADO_MENU_PRINCIPAL
    );
}

static void finalizar(void) {
    // Não há recursos específicos para liberar neste estado
}

static estado_aplicacao obter_id(void) {
    return ESTADO_MENU_PRINCIPAL;
}

estado_t* criar_estado_menu_principal(void) {
    estado_t* estado = (estado_t*) malloc(sizeof(estado_t));
    if (estado) {
        estado->inicializar = inicializar;
        estado->processar = processar;
        estado->finalizar = finalizar;
        estado->obter_id = obter_id;
    }
    return estado;
}