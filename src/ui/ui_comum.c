#include "ui/ui_comum.h"

void ui_limpar_tela(void)
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void ui_limpar_entrada(void) /* descarta até próximo '\n' */
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void ui_exibir_separador(char caractere, int largura)
{
    for (int i = 0; i < largura; i++)
    {
        putchar(caractere);
    }
    putchar('\n');
}

void ui_exibir_titulo(const char *titulo, const char *subtitulo)
{
    int largura = UI_LARGURA_PADRAO;
    size_t largura_titulo = ui_tamanho_str_utf8(titulo);
    size_t largura_subtitulo = ui_tamanho_str_utf8(subtitulo);

    // Borda superior
    ui_exibir_separador('=', largura);
    // Título centralizado
    int espacos = (largura - largura_titulo) / 2;
    printf("%*s%s%s%s%*s\n",
           espacos, "",
           UI_COR_NEGRITO, titulo, UI_COR_RESET,
           espacos - (int)strlen(UI_COR_NEGRITO) - (int)strlen(UI_COR_RESET), "");
    // Subtítulo, se fornecido
    if (subtitulo != NULL && *subtitulo != '\0')
    {
        espacos = (largura - largura_subtitulo) / 2;
        printf("%*s%s%*s\n", espacos, "", subtitulo, espacos, "");
    }

    // Borda inferior
    ui_exibir_separador('=', largura);
}

void ui_exibir_erro(const char *mensagem)
{
    char mensagem_formatada[UI_TAMANHO_MAX_MSG];
    snprintf(mensagem_formatada, UI_TAMANHO_MAX_MSG, "%s[ERRO] %s%s\n", UI_COR_VERMELHO, mensagem, UI_COR_RESET);
    printf("%s", mensagem_formatada);
}

void ui_exibir_sucesso(const char *mensagem)
{
    char mensagem_formatada[UI_TAMANHO_MAX_MSG];
    snprintf(mensagem_formatada, UI_TAMANHO_MAX_MSG, "%s[SUCESSO] %s%s\n", UI_COR_VERDE, mensagem, UI_COR_RESET);
    printf("%s", mensagem_formatada);
}

void ui_exibir_info(const char *mensagem)
{
    char mensagem_formatada[UI_TAMANHO_MAX_MSG];
    snprintf(mensagem_formatada, UI_TAMANHO_MAX_MSG, "%s[INFO] %s%s\n", UI_COR_CIANO, mensagem, UI_COR_RESET);
    printf("%s", mensagem_formatada);
}

void ui_exibir_to_do(const char *mensagem)
{
    char mensagem_formatada[UI_TAMANHO_MAX_MSG];
    snprintf(mensagem_formatada, UI_TAMANHO_MAX_MSG, "%s[TODO] %s%s\n", UI_COR_LARANJA, mensagem, UI_COR_RESET);
    printf("%s", mensagem_formatada);
}

void ui_exibir_debug(const char *mensagem)
{
    char mensagem_formatada[UI_TAMANHO_MAX_MSG];
    snprintf(mensagem_formatada, UI_TAMANHO_MAX_MSG, "%s[DEBUG] %s%s\n", UI_COR_CIANO, mensagem, UI_COR_RESET);
    printf("%s", mensagem_formatada);
}

char *ui_prompt_selecao_opcao(const char *texto, int limite_min, int limite_max)
{
    static char buffer[128];

    snprintf(buffer, sizeof(buffer), "\n%s%s (%d-%d):%s ",
             UI_COR_PROMPT_OPCAO, texto, limite_min, limite_max, UI_COR_RESET);

    return buffer;
}

char *ui_prompt_opcao(int min, int max)
{
    static char prompt_str[80];
    snprintf(prompt_str, sizeof(prompt_str), "\n%s>> Escolha uma opção (%d-%d): %s", UI_COR_PROMPT_OPCAO, min, max,
             UI_COR_RESET);
    return prompt_str;
}

void ui_prompt_continuar(const char *mensagem)
{
    if (mensagem != NULL)
    {
        printf("%s%s%s\n", UI_COR_PROMPT_OPCAO, mensagem, UI_COR_RESET);
    }
    else
    {
        printf("%sPressione ENTER para continuar...%s\n", UI_COR_PROMPT_CONTINUAR, UI_COR_RESET);
    }
    ui_limpar_entrada();
}

void ui_prompt_voltar_inicio(const char *mensagem)
{
    if (mensagem != NULL)
    {
        printf("%s%s%s\n", UI_COR_PROMPT_VOLTAR_INICIO, mensagem, UI_COR_RESET);
    }
    else
    {
        printf("%sPressione ENTER para voltar ao início...%s\n", UI_COR_PROMPT_VOLTAR_INICIO, UI_COR_RESET);
    }
    ui_limpar_entrada();
}

void ui_prompt_voltar_menu_principal(const char *mensagem)
{
    if (mensagem != NULL)
    {
        printf("%s%s%s\n", UI_COR_PROMPT_VOLTAR_MENU_PRINCIPAL, mensagem, UI_COR_RESET);
    }
    else
    {
        printf("%sPressione ENTER para voltar ao menu principal...%s\n", UI_COR_PROMPT_VOLTAR_MENU_PRINCIPAL,
               UI_COR_RESET);
    }
    ui_limpar_entrada();
}

void ui_prompt_voltar_menu_anterior(const char *mensagem)
{
    if (mensagem != NULL)
    {
        printf("%s%s%s\n", UI_COR_PROMPT_VOLTAR_MENU_ANTERIOR, mensagem, UI_COR_RESET);
    }
    else
    {
        printf("%sPressione ENTER para voltar ao menu anterior...%s\n", UI_COR_PROMPT_VOLTAR_MENU_ANTERIOR,
               UI_COR_RESET);
    }
    ui_limpar_entrada();
}

void ui_prompt_sair(const char *mensagem)
{
    if (mensagem != NULL)
    {
        printf("%s%s%s\n", UI_COR_PROMPT_SAIR, mensagem, UI_COR_RESET);
    }
    else
    {
        printf("%sPressione ENTER para finalizar...%s\n", UI_COR_PROMPT_SAIR, UI_COR_RESET);
    }
    ui_limpar_entrada();
}

void ui_exibir_data_hora()
{
    time_t t = time(NULL);
    struct tm *tm_info = localtime(&t);
    char data_hora[64];
    strftime(data_hora, sizeof(data_hora), "%d/%m/%Y %H:%M", tm_info);

    printf("%sData e hora: %s%s\n", UI_COR_CIANO, data_hora, UI_COR_RESET);
}

void ui_pausar(const char *mensagem)
{
    if (mensagem != NULL)
    {
        printf("%s\n", mensagem);
    }
    else
    {
        printf("%sPressione ENTER para continuar...%s\n", UI_COR_PROMPT_PAUSAR, UI_COR_RESET);
    }
    ui_limpar_entrada();
}

bool ui_confirmar(const char *mensagem)
{
    char resposta[10];

    while (1)
    {
        printf("%s%s (S/N)? %s", UI_COR_PROMPT_FORM_CONFIRMAR, mensagem, UI_COR_RESET);

        if (fgets(resposta, sizeof(resposta), stdin))
        {
            size_t len = strlen(resposta);
            if (len > 0 && resposta[len - 1] == '\n')
            {
                resposta[len - 1] = '\0';
                len--;
            }

            if (len == 0)
            {
                ui_exibir_info("Por favor, responda S para Sim ou N para Não.");
                printf("\n");
                continue;
            }
            ui_converter_para_maiusculo(resposta);
            if (strcmp(resposta, "S") == 0 || strcmp(resposta, "SIM") == 0)
            {
                return true;
            }
            else if (strcmp(resposta, "N") == 0 || strcmp(resposta, "NAO") == 0 || strcmp(resposta, "NÃO") == 0)
            {
                return false;
            }
            else
            {
                ui_exibir_erro("Resposta inválida. Por favor, responda S para Sim ou N para Não.");
                printf("\n");
                continue;
            }
        }
        else
        {
            ui_exibir_erro("Erro na leitura da resposta.");
            return false;
        }
    }
}

/**
 * Retorna o número de caracteres (code-points) em uma string UTF-8,
 * contando cada byte que **não** comece com bits '10' (continuação).
 */
size_t ui_tamanho_str_utf8(const char *s)
{
    size_t count = 0;
    const unsigned char *p = (const unsigned char*)s;
    while (*p)
    {
        /*
         * se os 2 bits mais significativos NÃO forem '10' (continuação),
         * é início de code-point
         */
        if ((*p & 0xC0) != 0x80)
            count++;
        p++;
    }
    return count;
}

void ui_desenhar_cabecalho(const char *titulo)
{
    size_t largura_titulo = ui_tamanho_str_utf8(titulo);
    int espacos_totais = (UI_LARGURA_PADRAO - largura_titulo - 2);
    int espacos_iniciais = espacos_totais / 2;
    int espacos_finais = espacos_iniciais + (espacos_totais % 2);

    /* Desenha linha superior */
    ui_desenhar_linha_simples();
    putchar('|');
    /* Desenha espaços iniciais */
    for (int i = 0; i < espacos_iniciais; i++)
        putchar(' ');

    /* Escreve título */
    printf("%s", titulo);

    /* Desenha espaços finais */
    for (int i = 0; i < espacos_finais; i++)
        putchar(' ');

    putchar('|');
    printf("\n");
    /* Desenha linha inferior */
    ui_desenhar_linha_simples();
}

void ui_desenhar_linha_simples(void)
{
    putchar('+');
    for (int i = 0; i < UI_LARGURA_QUADRO - 2; i++)
        putchar('-');
    puts("+");
}

void ui_desenhar_rodape(void)
{
    putchar('+');
    for (int i = 0; i < UI_LARGURA_QUADRO - 2; i++)
        putchar('-');
    puts("+");
}

void desenhar_caixa_mensagem(const char *mensagem, int tipo)
{
    const char *prefixo;

    switch (tipo)
    {
    case 0:
        prefixo = "INFO";
        break;
    case 1:
        prefixo = "SUCESSO";
        break;
    case 2:
        prefixo = "ERRO";
        break;
    default:
        prefixo = "";
    }

    ui_desenhar_linha_simples();

    if (strlen(prefixo) > 0)
    {
        int esp = UI_LARGURA_QUADRO - 4 - strlen(prefixo);
        printf("| [%s]%*s |\n", prefixo, esp, "");
        ui_desenhar_linha_simples();
    }

    printf("| %-*s |\n", UI_LARGURA_QUADRO - 4, mensagem);

    ui_desenhar_rodape();
}

void ui_desenhar_painel_funcionario(const char *funcionario, const char *matricula)
{
    char linha[UI_LARGURA_QUADRO - 3];
    ui_desenhar_linha_simples();
    snprintf(linha, sizeof(linha), "Funcionário: %s", funcionario);
    printf("| %-*s |\n", UI_LARGURA_QUADRO - 4, linha);
    snprintf(linha, sizeof(linha), "Matrícula: %s", matricula);
    printf("| %-*s |\n", UI_LARGURA_QUADRO - 4, linha);
    ui_desenhar_rodape();
}

void ui_desenhar_painel_funcionario_selecionado(const char *funcionario, char *matricula)
{
    char linha[UI_LARGURA_QUADRO - 3];
    ui_desenhar_linha_simples();
    snprintf(linha, sizeof(linha), "=> Funcionário Selecionado");
    printf("| %-*s |\n", UI_LARGURA_QUADRO - 4, linha);
    ui_desenhar_linha_simples();
    snprintf(linha, sizeof(linha), "Funcionário: %s", funcionario);
    printf("| %-*s |\n", UI_LARGURA_QUADRO - 4, linha);
    snprintf(linha, sizeof(linha), "Matrícula: %s", matricula);
    printf("| %-*s |\n", UI_LARGURA_QUADRO - 4, linha);
    ui_desenhar_rodape();
}

void ui_desenhar_linha_funcionario(const char *funcionario, const char *matricula)
{
    char linha[UI_LARGURA_PADRAO];
    snprintf(linha, sizeof(linha), "Funcionário: %s (Matr: %s)", funcionario, matricula);
    printf(" %-*s \n", UI_LARGURA_PADRAO - 4, linha);
}

void ui_desenhar_tela_padrao(
    const char *titulo,
    const char *subtitulo,
    const char *nome_funcionario,
    const char *matricula)
{
    ui_limpar_tela();

    if (nome_funcionario != NULL && matricula != NULL)
    {
        ui_desenhar_linha_funcionario(nome_funcionario, matricula);
    }

    ui_exibir_titulo(titulo, subtitulo);
}

/**
 * @brief Desenha parte superior de uma tela de formulário padrão
 * @param titulo Título da tela
 * @param subtitulo Subtítulo da tela
 * @param titulo_cabecalho Título do cabeçalho
 */
void ui_desenhar_tela_formulario_padrao(
    const char *titulo,
    const char *subtitulo,
    const char *titulo_cabecalho)
{
    ui_limpar_tela();

    ui_exibir_titulo(titulo, subtitulo);

    ui_desenhar_cabecalho(titulo_cabecalho);

    printf("\n");
}

/**
 * @brief Desenha parte superior de uma tela de relatório padrão
 * @param titulo
 * @param subtitulo
 * @param titulo_cabecalho
 */
void ui_desenhar_tela_relatorio_padrao(
    const char *titulo,
    const char *subtitulo,
    const char *titulo_cabecalho)
{
    ui_limpar_tela();

    ui_exibir_titulo(titulo, subtitulo);

    ui_desenhar_cabecalho(titulo_cabecalho);

    printf("\n");
}

void ui_desenhar_tela_sucesso(const char *titulo, const char *mensagem)
{
    ui_limpar_tela();
    ui_exibir_titulo(titulo, NULL);

    printf("\n");
    ui_exibir_separador('*', UI_LARGURA_PADRAO);
    ui_exibir_sucesso(mensagem);
    printf("\n");
    ui_exibir_separador('*', UI_LARGURA_PADRAO);
    printf("\n");

    ui_prompt_voltar_menu_anterior(NULL);
}

void ui_desenhar_tela_erro(const char *titulo, const char *mensagem)
{
    ui_limpar_tela();

    ui_exibir_titulo(titulo, NULL);

    printf("\n");
    ui_exibir_separador('*', UI_LARGURA_PADRAO);
    ui_exibir_erro(mensagem);
    printf("\n");
    ui_exibir_separador('*', UI_LARGURA_PADRAO);
    printf("\n");

    ui_prompt_voltar_menu_anterior(NULL);
}

void ui_converter_para_maiusculo(char *str)
{
    if (!str)
        return;

    for (size_t i = 0; str[i] != '\0'; i++)
    {
        str[i] = (char)toupper((unsigned char)str[i]);
    }
}

void ui_converter_para_minusculo(char *str)
{
    if (!str)
        return;

    for (size_t i = 0; str[i] != '\0'; i++)
    {
        str[i] = (char)tolower((unsigned char)str[i]);
    }
}
