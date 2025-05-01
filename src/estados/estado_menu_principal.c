#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "estados/estado_menu_principal.h"
#include "tela_menu_principal_ui.h"
#include "estado_menu_utils.h"
#include "session.h"

// Fun��es espec�ficas deste estado
static int inicializar(void) {
    // Limpar a tela
    system("cls");
    
    // Obter data e hora atual
    time_t t = time(NULL);
    struct tm *tm_info = localtime(&t);
    char data_hora[64];
    strftime(data_hora, sizeof(data_hora), "%d/%m/%Y %H:%M", tm_info);
    
    // Exibe informa��es do usu�rio logado
    funcionario_t *usuario = get_usuario_logado();
    if (usuario) {
        printf("???????????????????????????????????????????????????????\n");
        printf("? Usu�rio: %-20s      Matr: %-6d ?\n", usuario->nome, usuario->matricula);
        printf("? Sess�o iniciada em: %-30s ?\n", data_hora);
        printf("???????????????????????????????????????????????????????\n\n");
    }
    
    printf("EcoL�gica: Menu Principal\n");
    printf("==================================================\n\n");
    
    // Resumo de informa��es importantes
    printf("Resumo do Sistema:\n");
    printf("� Ind�strias cadastradas: [Funcionalidade a implementar]\n");
    printf("� �ltimo relat�rio gerado: [Funcionalidade a implementar]\n");
    printf("� Atualiza��es pendentes: [Funcionalidade a implementar]\n\n");
    
    printf("Escolha uma op��o >>\n\n");
    
    return 0; // sucesso
}

static estado_aplicacao processar(size_t entrada) {
    // Usar a fun��o utilit�ria para processar o menu
    return processar_estado_menu(
        tela_menu_principal_mapa,
        tela_menu_principal_mapa_n,
        tela_menu_principal_prompt,
        ESTADO_MENU_PRINCIPAL
    );
}

static void finalizar(void) {
    // N�o h� recursos espec�ficos para liberar neste estado
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