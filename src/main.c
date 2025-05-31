#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>
#include "estados/estados.h"
#include "estados/estado.h"
#include "session.h"
#include "ui/ui_comum.h"
#include "ui/ui_menu.h"
#include "persistencia/verificacao_csv.h"
#include "util.h"

typedef struct
{
    size_t indice_opcao;
    void *dados_extras;
} entrada_estado_t;

int main(void)
{
    set_locale_utf8();
    char msg_erro_diretorio[512] = {0};

    if (!verificar_diretorio_dados(msg_erro_diretorio))
    {
        ui_desenhar_tela_erro_fatal("Erro de diretório de dados", msg_erro_diretorio);
        return 1;
    }

    char msg_erro_arquivos[512] = {0};
    if (!verificar_arquivos_csv(msg_erro_arquivos))
    {
        ui_desenhar_tela_erro("Erro de verificação de arquivos CSV", msg_erro_arquivos);
        return 1;
    }

    estado_aplicacao id_estado_atual = ESTADO_MENU_LOGIN;
    estado_aplicacao id_proximo_estado;
    estado_t *estado_atual = NULL;
    entrada_estado_t entrada = {0, NULL};

    while (true)
    {
        estado_atual = criar_estado(id_estado_atual);
        if (!estado_atual)
        {
            fprintf(stderr, "Erro ao criar estado %d\n", id_estado_atual);
            return 1;
        }

        if (estado_atual->inicializar)
        {
            if (estado_atual->inicializar() != 0)
            {
                fprintf(stderr, "Erro ao inicializar estado %d\n", id_estado_atual);
                destruir_estado(estado_atual);
                return 1;
            }
        }

        entrada.indice_opcao = 0;
        id_proximo_estado = estado_atual->processar(entrada.indice_opcao);

        if (estado_atual->finalizar)
        {
            estado_atual->finalizar();
        }

        destruir_estado(estado_atual);

        if (id_estado_atual == ESTADO_SAIR && id_proximo_estado == ESTADO_SAIR)
        {
            break;
        }        

        id_estado_atual = id_proximo_estado;
    }

    logout();
    return 0;
}
