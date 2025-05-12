#ifndef UI_COMUM_H
#define UI_COMUM_H

/* Constantes para desenho da interface */
#define UI_LARGURA_QUADRO 80
#define UI_LARGURA_PADRAO 80

/* Cores ANSI para formata��o de texto */
#define UI_COR_RESET "\033[0m"
#define UI_COR_VERMELHO "\033[31m"
#define UI_COR_VERDE "\033[32m"
#define UI_COR_CIANO_NEGRITO "\033[1;36m"//"\033[34m" 
#define UI_COR_AMARELO "\033[33m"
#define UI_COR_CIANO "\033[36m"
#define UI_COR_NEGRITO "\033[1m"
#define UI_COR_LARANJA "\033[35m"

/* T�tulo e subt�tulos das telas */
#define UI_TITULO_PROGRAMA "EcoL�gica Solu��es Ambientais"
#define UI_SUBTITULO_PROGRAMA "Sistema de Gest�o Ambiental"
#define UI_SUBTITULO_LOGIN "Formul�rio de Login"
#define UI_SUBTITULO_CADASTRO_FUNCIONARIOS "Cadastro de Funcion�rios"
#define UI_SUBTITULO_CADASTRO_INDUSTRIAS "Cadastro de Ind�strias"
#define UI_SUBTITULO_SOBRE "Sobre o Projeto"
#define UI_SUBTITULO_LOGIN_SUCESSO "Autentica��o Bem-Sucedida"
#define UI_SUBTITULO_LOGIN_FALHA "Falha na Autentica��o"
#define UI_SUBTITULO_ADICIONAR_FUNCIONARIO_SUCESSO "Funcion�rio Adicionado com Sucesso"
#define UI_SUBTITULO_ADICIONAR_FUNCIONARIO_FALHA "Falha ao Adicionar Funcion�rio"
#define UI_SUBTITULO_ADICIONAR_FUNCIONARIO_JA_EXISTE "Funcion�rio J� Cadastrado"

/* Prompts para entrada do usu�rio */
#define PROMPT_OPCOES(min, max) "\n\033[33m>> Escolha uma op��o (" #min "-" #max "): \033[0m"
#define PROMPT_FORM(prompt_str) "\n\033[35m>> " prompt_str ": \033[0m"

#include <stdio.h>
#include <stdbool.h>

/**
 * @brief Limpa o buffer de entrada do console
 */
void ui_limpar_buffer_entrada(void);

/**
 * @brief Limpa a tela do console
 */
void ui_limpar_tela(void);

/**
 * @brief Exibe um t�tulo padronizado para uma tela
 * @param titulo Texto do t�tulo
 * @param subtitulo Texto do subt�tulo (pode ser NULL)
 */
void ui_exibir_titulo(const char* titulo, const char* subtitulo);

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
void ui_exibir_erro(const char* mensagem);

/**
 * @brief Exibe uma mensagem de sucesso formatada
 * @param mensagem Texto da mensagem de sucesso
 */
void ui_exibir_sucesso(const char* mensagem);

/**
 * @brief Exibe uma mensagem informativa formatada
 * @param mensagem Texto da mensagem informativa
 */
void ui_exibir_info(const char* mensagem);

/**
 * @brief Exibe uma mensagem de TODO (a fazer)
 * @param mensagem Texto da mensagem de TODO
 */
void ui_exibir_to_do(const char* mensagem);

/**
 * @brief Exibe um prompt para o usu�rio selecionar uma op��o
 * @param texto Texto do prompt
 * @param limite_min Valor m�nimo da op��o
 * @param limite_max Valor m�ximo da op��o
 * @return String formatada com o prompt
 */
char* ui_prompt_selecao_opcao(const char* texto, int limite_min, int limite_max);

/**
 * @brief Exibe um prompt para o usu�rio pressionar ENTER para continuar
 * @param mensagem Texto da mensagem (pode ser NULL para usar mensagem padr�o)
 */
void ui_prompt_continuar(const char* mensagem);

/**
 * @brief Exibe um prompt para o usu�rio pressionar ENTER para voltar ao in�cio
 * @param mensagem Texto da mensagem de aviso
 */
void ui_prompt_voltar_inicio(const char* mensagem);

/**
 * @brief Exibe prompt para o usu�rio pressionar ENTER para voltar ao menu principal
 * @param mensagem Texto da mensagem (pode ser NULL para usar mensagem padr�o)
 */
void ui_prompt_voltar_menu_principal(const char* mensagem);

/**
 * @brief Exibe prompt para o usu�rio pressionar ENTER para o voltar ao menu anterior
 * @param mensagem Texto da mensagem (pode ser NULL para usar mensagem padr�o)
 */
void ui_prompt_voltar_menu_anterior(const char* mensagem);


void ui_prompt_sair(const char* mensagem);

/**
 * @brief Exibe uma mensagem de data e hora atual
 * @param data_hora String formatada com data e hora
 */
void ui_exibir_data_hora(void);

/**
 * @brief Pausa a execu��o e aguarda o usu�rio pressionar ENTER
 * @param mensagem Texto opcional a ser exibido (pode ser NULL para usar mensagem padr�o)
 */
void ui_pausar(const char* mensagem);

/**
 * @brief L� uma string da entrada padr�o com valida��o de tamanho
 * @param prompt Texto do prompt
 * @param buffer Buffer para armazenar a string
 * @param tamanho Tamanho m�ximo da string
 * @param obrigatorio Se true, n�o aceita entrada vazia
 * @return true se a leitura foi bem-sucedida
 */
bool ui_ler_string(const char* prompt, char* buffer, size_t tamanho, bool obrigatorio);

/**
 * @brief L� um n�mero inteiro da entrada padr�o com valida��o
 * @param prompt Texto do prompt
 * @param min Valor m�nimo permitido
 * @param max Valor m�ximo permitido
 * @param padrao Valor padr�o caso a entrada seja vazia
 * @param obrigatorio Se true, n�o aceita entrada vazia
 * @return O n�mero lido, ou o valor padr�o
 */
int ui_ler_inteiro(const char* prompt, int min, int max, int padrao, bool obrigatorio);

/**
 * @brief L� uma data no formato DD/MM/AAAA com valida��o
 * @param prompt Texto do prompt
 * @param buffer Buffer para armazenar a data
 * @param tamanho Tamanho do buffer
 * @param obrigatorio Se true, n�o aceita entrada vazia
 * @return true se a data for v�lida
 */
bool ui_ler_data(const char* prompt, char* buffer, size_t tamanho, bool obrigatorio);

/**
 * @brief L� um CNPJ com valida��o
 * @param prompt Texto do prompt
 * @param buffer Buffer para armazenar o CNPJ
 * @param tamanho Tamanho do buffer
 * @param obrigatorio Se true, n�o aceita entrada vazia
 * @return true se o CNPJ for v�lido
 */
bool ui_ler_cnpj(const char* prompt, char* buffer, size_t tamanho, bool obrigatorio);

/**
 * @brief Exibe uma interface para confirma��o sim/n�o
 * @param mensagem Pergunta a ser exibida
 * @return true para sim, false para n�o
 */
bool ui_confirmar(const char* mensagem);

/**
 * @brief Desenha o cabe�alho padronizado para telas do sistema
 * @param titulo Texto do t�tulo a ser exibido no cabe�alho
 */
void ui_desenhar_cabecalho(const char* titulo);

/**
 * @brief Desenha uma linha simples para separar se��es
 */
void ui_desenhar_linha_simples(void);

/**
 * @brief Desenha o rodap� padronizado para telas do sistema
 */
void ui_desenhar_rodape(void);

/**
 * @brief Desenha uma caixa de di�logo com mensagem
 * @param mensagem Texto da mensagem a ser exibida
 * @param tipo Tipo da mensagem: 0=info, 1=sucesso, 2=erro
 */
void desenhar_caixa_mensagem(const char* mensagem, int tipo);

/**
 * @brief Desenha um painel com dados do funcion�rio
 * @param funcionario Nome do funcion�rio
 * @param matricula Matr�cula ou ID do funcion�rio
 */
void ui_desenhar_painel_funcionario(const char* funcionario, const char* matricula);

/**
 * @brief Desenha um painel com dados do funcion�rio selecionado
 * @param funcionario Nome do funcion�rio
 * @param matricula Matr�cula ou ID do funcion�rio
 */
void ui_desenhar_painel_funcionario_selecionado(const char* funcionario, int matricula);

/**
 * @brief Desenha parte superior de uma tela de menu padr�o
 * @param titulo T�tulo da tela
 * @param subtitulo Subt�tulo da tela
 * @param nome_funcionario Nome do funcion�rio logado
 * @param matricula Matr�cula do funcion�rio logado
 * @param titulo_cabecalho T�tulo do cabe�alho
 */
void ui_desenhar_tela_padrao(
    const char *titulo, 
    const char *subtitulo, 
    const char *nome_funcionario, 
    const int matricula);

/**
 * @brief Desenha parte superior de uma tela de formul�rio padr�o
 * @param titulo T�tulo da tela
 * @param subtitulo Subt�tulo da tela
 * @param titulo_cabecalho T�tulo do cabe�alho
 */
void ui_desenhar_tela_formulario_padrao(
    const char *titulo, 
    const char *subtitulo,
    const char *titulo_cabecalho);

/**
 * @brief Desenha parte superior de uma tela de relat�rio padr�o
 * @param titulo T�tulo da tela
 * @param subtitulo Subt�tulo da tela
 * @param titulo_cabecalho T�tulo do cabe�alho
 */
void ui_desenhar_tela_relatorio_padrao(
    const char *titulo, 
    const char *subtitulo,
    const char *titulo_cabecalho);

/**
 * @brief Desenha uma tela de sucesso
 * @param titulo T�tulo da tela
 * @param mensagem Mensagem de sucesso a ser exibida
 * @note Esta fun��o limpa a tela antes de exibir a mensagem
 */
void ui_desenhar_tela_sucesso(const char* titulo, const char* mensagem);

/**
 * @brief Desenha uma tela de erro
 * @param titulo T�tulo da tela
 * @param mensagem Mensagem de erro a ser exibida
 * @note Esta fun��o limpa a tela antes de exibir a mensagem
 */
void ui_desenhar_tela_erro(const char* titulo, const char* mensagem);
    
/**
 * @brief Converte uma string para mai�sculas
 * @param str String a ser convertida
 */
void ui_converter_para_maiusculo(char* str);

#endif // UI_COMUM_H