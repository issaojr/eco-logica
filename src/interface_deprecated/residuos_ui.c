#include "residuos_ui.h"

void iniciar_interface_residuos(void) {
    // char cnpj[20];   
    // double quantidadeTratada; 
    // double custoEstimado;     

    // mostrar_usuario_autenticado(); // Exibe o usu�rio logado, se houver

    // mostrar_titulo(residuosTitle); // Exibe o t�tulo da tela de atualiza��o mensal

    // // CNPJ
    // printf(">> Digite o CNPJ da ind�stria: ");
    // if (scanf("%19s", cnpj) != 1) {
    //     while(getchar()!='\n');
    //     mostrar_dlg_erro(msgCnpjError);
    //     return;
    // }
    // while(getchar()!='\n');

    // // Ler e validar o ano e m�s
    // struct tm data_ref;
    // int ret = ler_mes_ano(">> Digite o m�s e ano (mm/aaaa): ", &data_ref);
    // if (ret != 0) {
    //     if (ret == ERR_DATA_INVALIDA) {
    //         mostrar_dlg_erro(erro_msg(ERR_DATA_INVALIDA));
    //     } else if (ret == ERR_DATA_INVALIDA_INTERVALO) {
    //         mostrar_dlg_erro(erro_msg(ERR_DATA_INVALIDA_INTERVALO));
    //     } else {
    //         mostrar_dlg_erro("Erro desconhecido ao ler a data.");
    //     }
    //     return;
    // }

    // // Quantidade tratada
    // printf(">> Digite a quantidade de res�duos tratados: ");
    // if (scanf("%lf", &quantidadeTratada) != 1) {
    //     while(getchar()!='\n');
    //     mostrar_dlg_erro(msgQuantidadeError);
    //     return;
    // }
    // while(getchar()!='\n');

    // // Custo estimado
    // printf(">> Digite o custo estimado (R$): ");
    // if (scanf("%lf", &custoEstimado) != 1) {
    //     //printf("Entrada inv�lida para custo.\n");
    //     while(getchar()!='\n');
    //     mostrar_dlg_erro(msgCustoError);
    //     return;
    // }
    // while(getchar()!='\n');

    // int resultado = processar_atualizacao_mensal(cnpj, &data_ref, quantidadeTratada, custoEstimado);
    // if (resultado) {
    //     mostrar_dlg_info(msgAtualizacaoSuccess); // Exibe mensagem de sucesso
    // } else {
    //     mostrar_dlg_erro(msgAtualizacaoError); // Exibe mensagem de erro
    // }
}
