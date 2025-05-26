#ifndef UI_COMUM_H
#define UI_COMUM_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <wchar.h>
#include <stdbool.h>
#include <time.h>
#include "estruturas/industria.h"

/* Constantes para desenho da interface */
#define UI_LARGURA_QUADRO 80
#define UI_LARGURA_PADRAO 80

/* Constantes para tamanho máximo de strings */
#define UI_TAMANHO_MAX_MSG 300

#define UI_DEBUG 0

/* Cores ANSI para formatação de texto */
#define UI_COR_RESET "\033[0m"
#define UI_COR_VERMELHO "\033[38;5;197m"
#define UI_COR_VERDE "\033[38;5;76m"
#define UI_COR_CIANO_NEGRITO "\033[1;36m"
#define UI_COR_AMARELO "\033[38;5;11m"
#define UI_COR_CIANO "\033[36m"
#define UI_COR_NEGRITO "\033[1m"
#define UI_COR_LARANJA "\033[38;5;214m"
#define UI_COR_TAB_LABEL "\033[38;5;248m" /* CINZA CLARO */
#define UI_COR_TAB_VALUE "\033[38;5;195m" /* AZUL CLARO */

#define UI_COR_PROMPT_OPCAO UI_COR_AMARELO
#define UI_COR_PROMPT_FORM UI_COR_AMARELO
#define UI_COR_PROMPT_FORM_CONFIRMAR UI_COR_AMARELO
#define UI_COR_PROMPT_CONTINUAR UI_COR_LARANJA
#define UI_COR_PROMPT_VOLTAR_INICIO UI_COR_LARANJA
#define UI_COR_PROMPT_VOLTAR_MENU_ANTERIOR UI_COR_LARANJA
#define UI_COR_PROMPT_VOLTAR_MENU_PRINCIPAL UI_COR_LARANJA
#define UI_COR_PROMPT_SAIR UI_COR_LARANJA
#define UI_COR_PROMPT_PAUSAR UI_COR_LARANJA


/* Título e subtítulos das telas */
#define UI_TITULO_PROGRAMA "EcoLógica Soluções Ambientais"
#define UI_SUBTITULO_PROGRAMA "Sistema de Gestão Ambiental"
#define UI_SUBTITULO_LOGIN "Formulário de Login"
#define UI_SUBTITULO_CADASTRO_FUNCIONARIOS "Cadastro de Funcionários"
#define UI_SUBTITULO_CADASTRO_INDUSTRIAS "Cadastro de Indústrias"
#define UI_SUBTITULO_ATUALIZACAO_RESIDUOS "Atualização de Resíduos"
#define UI_SUBTITULO_SOBRE "Sobre o Projeto"
#define UI_SUBTITULO_LOGIN_SUCESSO "Autenticação Bem-Sucedida"
#define UI_SUBTITULO_LOGIN_FALHA "Falha na Autenticação"
#define UI_SUBTITULO_ADICIONAR_FUNCIONARIO_SUCESSO "Funcionário Adicionado com Sucesso"
#define UI_SUBTITULO_ADICIONAR_FUNCIONARIO_FALHA "Falha ao Adicionar Funcionário"
#define UI_SUBTITULO_ADICIONAR_FUNCIONARIO_JA_EXISTE "Funcionário JÁ Cadastrado"

/**
 * @brief Limpa a tela do console
 */
void ui_limpar_tela(void);


void ui_limpar_entrada(void);

/**
 * @brief Exibe um título padronizado para uma tela
 * @param titulo Texto do título
 * @param subtitulo Texto do subtítulo (pode ser NULL)
 */
void ui_exibir_titulo(const char *titulo, const char *subtitulo);

/**
 * @brief Exibe uma linha separadora horizontal
 * @param caractere Caractere usado para formar a linha
 * @param largura Largura da linha
 */
void ui_exibir_separador(char caractere, int largura);

/**
 * @brief Exibe uma mensagem de erro formatada
 * @param mensagem Texto da mensagem de erro
 */
void ui_exibir_erro(const char *mensagem);

/**
 * @brief Exibe uma mensagem de sucesso formatada
 * @param mensagem Texto da mensagem de sucesso
 */
void ui_exibir_sucesso(const char *mensagem);

/**
 * @brief Exibe uma mensagem informativa formatada
 * @param mensagem Texto da mensagem informativa
 */
void ui_exibir_info(const char *mensagem);

/**
 * @brief Exibe uma mensagem de agradecimento
 * @param mensagem Texto da mensagem de agradecimento
 */
void ui_exibir_agradecimento(const char *mensagem);

/**
 * @brief Exibe uma mensagem de TODO (a fazer)
 * @param mensagem Texto da mensagem de TODO
 */
void ui_exibir_to_do(const char *mensagem);

void ui_exibir_debug(const char *mensagem);

/**
 * @brief Exibe um prompt para o usuário selecionar uma opção
 * @param texto Texto do prompt
 * @param limite_min Valor mínimo da opção
 * @param limite_max Valor máximo da opção
 * @return String formatada com o prompt
 */
char *ui_prompt_selecao_opcao(const char *texto, int limite_min, int limite_max);

/**
 * @brief Exibe um prompt para o usuário pressionar ENTER para continuar
 * @param mensagem Texto da mensagem (pode ser NULL para usar mensagem padrão)
 */
char *ui_prompt_opcao(int min, int max);

/**
 * @brief Exibe um prompt para o usuário pressionar ENTER para continuar
 * @param mensagem Texto da mensagem (pode ser NULL para usar mensagem padrão)
 */
void ui_prompt_continuar(const char *mensagem);

/**
 * @brief Exibe um prompt para o usuário pressionar ENTER para voltar ao início
 * @param mensagem Texto da mensagem de aviso
 */
void ui_prompt_voltar_inicio(const char *mensagem);

/**
 * @brief Exibe prompt para o usuário pressionar ENTER para voltar ao menu principal
 * @param mensagem Texto da mensagem (pode ser NULL para usar mensagem padrão)
 */
void ui_prompt_voltar_menu_principal(const char *mensagem);

/**
 * @brief Exibe prompt para o usuário pressionar ENTER para o voltar ao menu anterior
 * @param mensagem Texto da mensagem (pode ser NULL para usar mensagem padrão)
 */
void ui_prompt_voltar_menu_anterior(const char *mensagem);

void ui_prompt_sair(const char *mensagem);

/**
 * @brief Exibe uma mensagem de data e hora atual
 * @param data_hora String formatada com data e hora
 */
void ui_exibir_data_hora(void);

/**
 * @brief Pausa a execução e aguarda o usuário pressionar ENTER
 * @param mensagem Texto opcional a ser exibido (pode ser NULL para usar mensagem padrão)
 */
void ui_pausar(const char *mensagem);

/**
 * @brief Exibe uma interface para confirmação sim/não
 * @param mensagem Pergunta a ser exibida
 * @return true para sim, false para não
 */
bool ui_confirmar(const char *mensagem);

/**
 *
 */
size_t ui_tamanho_str_utf8(const char *s);

/**
 * @brief Desenha o cabeçalho padronizado para telas do sistema
 * @param titulo Texto do título a ser exibido no cabeçalho
 */
void ui_desenhar_cabecalho(const char *titulo);

/**
 * @brief Desenha uma linha simples para separar seções
 */
void ui_desenhar_linha_simples(void);

/**
 * @brief Desenha o rodapé padronizado para telas do sistema
 */
void ui_desenhar_rodape(void);

/**
 * @brief Desenha uma caixa de diálogo com mensagem
 * @param mensagem Texto da mensagem a ser exibida
 * @param tipo Tipo da mensagem: 0=info, 1=sucesso, 2=erro
 */
void desenhar_caixa_mensagem(const char *mensagem, int tipo);

/**
 * @brief Desenha parte superior de uma tela de menu padrão
 * @param titulo Título da tela
 * @param subtitulo Subtítulo da tela
 * @param nome_funcionario Nome do funcionário logado
 * @param matricula Matrícula do funcionário logado
 * @param titulo_cabecalho Título do cabeçalho
 */
void ui_desenhar_tela_padrao(
    const char *titulo,
    const char *subtitulo,
    const char *nome_funcionario,
    const char *matricula);

/**
 * @brief Desenha parte superior de uma tela de formulário padrão
 * @param titulo Título da tela
 * @param subtitulo Subtítulo da tela
 * @param titulo_cabecalho Título do cabeçalho
 */
void ui_desenhar_tela_formulario_padrao(
    const char *titulo,
    const char *subtitulo,
    const char *titulo_cabecalho);

/**
 * @brief Desenha parte superior de uma tela de relatório padrão
 * @param titulo Título da tela
 * @param subtitulo Subtítulo da tela
 * @param titulo_cabecalho Título do cabeçalho
 */
void ui_desenhar_tela_relatorio_padrao(
    const char *titulo,
    const char *subtitulo,
    const char *titulo_cabecalho);

/**
 * @brief Desenha uma tela de sucesso
 * @param titulo Título da tela
 * @param mensagem Mensagem de sucesso a ser exibida
 * @note Esta função limpa a tela antes de exibir a mensagem
 */
void ui_desenhar_tela_sucesso(const char *titulo, const char *mensagem);

/**
 * @brief Desenha uma tela de erro
 * @param titulo Título da tela
 * @param mensagem Mensagem de erro a ser exibida
 * @note Esta função limpa a tela antes de exibir a mensagem
 */
void ui_desenhar_tela_erro(const char *titulo, const char *mensagem);

void ui_desenhar_tela_sair(void);

void ui_desenhar_linha_painel(
    const char *label,
    const char *value,
    const char *c_inicial,
    const char *c_final,
    size_t largura_total);

/**
 * @brief Converte uma string para maiúsculas
 * @param str String a ser convertida
 */
void ui_converter_para_maiusculo(char *str);

/**
 * @brief Converte uma string para minúsculas
 * @param str String a ser convertida
 */
void ui_converter_para_minusculo(char *str);

#endif // UI_COMUM_H
