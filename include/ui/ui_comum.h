#ifndef UI_COMUM_H
#define UI_COMUM_H

#include <stdio.h>
#include <stdbool.h>

/**
 * @brief Limpa o buffer de entrada do console
 */
void limpar_buffer_entrada(void);

/**
 * @brief Limpa a tela do console
 */
void ui_limpar_tela(void);

/**
 * @brief Exibe um título padronizado para uma tela
 * @param titulo Texto do título
 * @param subtitulo Texto do subtítulo (pode ser NULL)
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
 * @brief Exibe um prompt para o usuário pressionar ENTER para voltar ao início
 * @param mensagem Texto da mensagem de aviso
 */
void ui_prompt_voltar_inicio(const char* mensagem);

/**
 * @brief Exibe prompt para o usuário pressionar ENTER para voltar ao menu principal
 * @param mensagem Texto da mensagem (pode ser NULL para usar mensagem padrão)
 */
void ui_prompt_voltar_menu_principal(const char* mensagem);

/**
 * @brief Exibe prompt para o usuário pressionar ENTER para o voltar ao menu anterior
 * @param mensagem Texto da mensagem (pode ser NULL para usar mensagem padrão)
 */
void ui_prompt_voltar_menu_anterior(const char* mensagem);

/**
 * @brief Exibe uma mensagem de data e hora atual
 * @param data_hora String formatada com data e hora
 */
void ui_exibir_data_hora(const char* data_hora);

/**
 * @brief Pausa a execução e aguarda o usuário pressionar ENTER
 * @param mensagem Texto opcional a ser exibido (pode ser NULL para usar mensagem padrão)
 */
void ui_pausar(const char* mensagem);

/**
 * @brief Lê uma string da entrada padrão com validação de tamanho
 * @param prompt Texto do prompt
 * @param buffer Buffer para armazenar a string
 * @param tamanho Tamanho máximo da string
 * @param obrigatorio Se true, não aceita entrada vazia
 * @return true se a leitura foi bem-sucedida
 */
bool ui_ler_string(const char* prompt, char* buffer, size_t tamanho, bool obrigatorio);

/**
 * @brief Lê um número inteiro da entrada padrão com validação
 * @param prompt Texto do prompt
 * @param min Valor mínimo permitido
 * @param max Valor máximo permitido
 * @param padrao Valor padrão caso a entrada seja vazia
 * @param obrigatorio Se true, não aceita entrada vazia
 * @return O número lido, ou o valor padrão
 */
int ui_ler_inteiro(const char* prompt, int min, int max, int padrao, bool obrigatorio);

/**
 * @brief Lê uma data no formato DD/MM/AAAA com validação
 * @param prompt Texto do prompt
 * @param buffer Buffer para armazenar a data
 * @param tamanho Tamanho do buffer
 * @param obrigatorio Se true, não aceita entrada vazia
 * @return true se a data for válida
 */
bool ui_ler_data(const char* prompt, char* buffer, size_t tamanho, bool obrigatorio);

/**
 * @brief Lê um CNPJ com validação
 * @param prompt Texto do prompt
 * @param buffer Buffer para armazenar o CNPJ
 * @param tamanho Tamanho do buffer
 * @param obrigatorio Se true, não aceita entrada vazia
 * @return true se o CNPJ for válido
 */
bool ui_ler_cnpj(const char* prompt, char* buffer, size_t tamanho, bool obrigatorio);

/**
 * @brief Exibe uma interface para confirmação sim/não
 * @param mensagem Pergunta a ser exibida
 * @return true para sim, false para não
 */
bool ui_confirmar(const char* mensagem);

/**
 * @brief Desenha o cabeçalho padronizado para telas do sistema
 * @param titulo Texto do título a ser exibido no cabeçalho
 */
void desenhar_cabecalho(const char* titulo);

/**
 * @brief Desenha uma linha simples para separar seções
 */
void desenhar_linha_simples(void);

/**
 * @brief Desenha o rodapé padronizado para telas do sistema
 */
void desenhar_rodape(void);

/**
 * @brief Desenha uma caixa de diálogo com mensagem
 * @param mensagem Texto da mensagem a ser exibida
 * @param tipo Tipo da mensagem: 0=info, 1=sucesso, 2=erro
 */
void desenhar_caixa_mensagem(const char* mensagem, int tipo);

/**
 * @brief Desenha um painel com dados do funcionário
 * @param funcionario Nome do funcionário
 * @param matricula Matrícula ou ID do funcionário
 */
void desenhar_painel_funcionario(const char* funcionario, const char* matricula);

#endif // UI_COMUM_H