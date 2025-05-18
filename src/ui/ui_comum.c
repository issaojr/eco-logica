#include "ui/ui_comum.h"

void ui_limpar_tela(void)
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
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

    // Borda superior
    ui_exibir_separador('=', largura);
    // Título centralizado
    int espacos = (largura - strlen(titulo)) / 2;
    printf("%*s%s%s%s%*s\n",
           espacos, "",
           UI_COR_NEGRITO, titulo, UI_COR_RESET,
           espacos - (int)strlen(UI_COR_NEGRITO) - (int)strlen(UI_COR_RESET), "");
    // Subtítulo, se fornecido
    if (subtitulo != NULL && *subtitulo != '\0')
    {
        espacos = (largura - strlen(subtitulo)) / 2;
        printf("%*s%s%*s\n", espacos, "", subtitulo, espacos, "");
    }

    // Borda inferior
    ui_exibir_separador('=', largura);
}

void ui_exibir_erro(const char *mensagem)
{
    char mensagem_formatada[150];
    snprintf(mensagem_formatada, UI_LARGURA_PADRAO, "%s[ERRO] %s%s\n", UI_COR_VERMELHO, mensagem, UI_COR_RESET);
    printf("%s", mensagem_formatada);
}

void ui_exibir_sucesso(const char *mensagem)
{
    char mensagem_formatada[150];
    snprintf(mensagem_formatada, UI_LARGURA_PADRAO, "%s[SUCESSO] %s%s\n", UI_COR_VERDE, mensagem, UI_COR_RESET);
    printf("%s", mensagem_formatada);
}

void ui_exibir_info(const char *mensagem)
{
    char mensagem_formatada[150];
    snprintf(mensagem_formatada, UI_LARGURA_PADRAO, "%s[INFO] %s%s\n", UI_COR_CIANO, mensagem, UI_COR_RESET);
    printf("%s", mensagem_formatada);
}

void ui_exibir_to_do(const char *mensagem)
{
    char mensagem_formatada[150];
    snprintf(mensagem_formatada, UI_LARGURA_PADRAO, "%s[TODO] %s%s\n", UI_COR_LARANJA, mensagem, UI_COR_RESET);
    printf("%s", mensagem_formatada);
}

void ui_exibir_debug(const char *mensagem)
{
    char mensagem_formatada[150];
    snprintf(mensagem_formatada, UI_LARGURA_PADRAO, "%s[DEBUG] %s%s\n", UI_COR_CIANO, mensagem, UI_COR_RESET);
    printf("%s", mensagem_formatada);
}

char *ui_prompt_selecao_opcao(const char *texto, int limite_min, int limite_max)
{
    static char buffer[128];

    const char *cor_amarela = "\033[1;33m";
    const char *reset_cor = "\033[0m";

    snprintf(buffer, sizeof(buffer), "\n%s%s (%d-%d):%s ",
             cor_amarela, texto, limite_min, limite_max, reset_cor);

    return buffer;
}

char *ui_prompt_opcao(int min, int max)
{
    static char prompt_str[80];
    snprintf(prompt_str, sizeof(prompt_str), "\n%s>> Escolha uma opção (%d-%d): %s", UI_COR_AMARELO, min, max, UI_COR_RESET);
    return prompt_str;
}

void ui_prompt_continuar(const char *mensagem)
{
    if (mensagem != NULL)
    {
        printf("%s%s%s\n", UI_COR_AMARELO, mensagem, UI_COR_RESET);
    }
    else
    {
        printf("%sPressione ENTER para continuar...%s\n", UI_COR_AMARELO, UI_COR_RESET);
    }
    getchar();
}

void ui_prompt_voltar_inicio(const char *mensagem)
{
    if (mensagem != NULL)
    {
        printf("%s%s%s\n", UI_COR_AMARELO, mensagem, UI_COR_RESET);
    }
    else
    {
        printf("%sPressione ENTER para voltar ao inácio...%s\n", UI_COR_AMARELO, UI_COR_RESET);
    }
    getchar();
}

void ui_prompt_voltar_menu_principal(const char *mensagem)
{
    if (mensagem != NULL)
    {
        printf("%s%s%s\n", UI_COR_AMARELO, mensagem, UI_COR_RESET);
    }
    else
    {
        printf("%sPressione ENTER para voltar ao menu principal...%s\n", UI_COR_AMARELO, UI_COR_RESET);
    }
    getchar();
}

void ui_prompt_voltar_menu_anterior(const char *mensagem)
{
    if (mensagem != NULL)
    {
        printf("%s%s%s\n", UI_COR_AMARELO, mensagem, UI_COR_RESET);
    }
    else
    {
        printf("%sPressione ENTER para voltar ao menu anterior...%s\n", UI_COR_AMARELO, UI_COR_RESET);
    }
    getchar();
}
void ui_prompt_sair(const char *mensagem)
{
    if (mensagem != NULL)
    {
        printf("%s%s%s\n", UI_COR_AMARELO, mensagem, UI_COR_RESET);
    }
    else
    {
        printf("%sPressione ENTER para finalizar...%s\n", UI_COR_AMARELO, UI_COR_RESET);
    }
    getchar();
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
        printf("Pressione ENTER para continuar...");
    }
    getchar();
}

bool ui_confirmar(const char *mensagem)
{
    char resposta[10];

    while (1)
    {
        printf("%s%s (S/N)? %s", UI_COR_AMARELO, mensagem, UI_COR_RESET);

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
                continue;
            }
            ui_converter_para_maiusculo(resposta);
            if (resposta[0] == 'S' || strcmp(resposta, "SIM") == 0)
            {
                return true;
            }
            else if (resposta[0] == 'N' || strcmp(resposta, "NAO") == 0 || strcmp(resposta, "NÃO") == 0)
            {
                return false;
            }
            else
            {
                ui_exibir_erro("Resposta inválida. Por favor, responda S para Sim ou N para Não.");
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

void ui_desenhar_cabecalho(const char *titulo)
{
    putchar('+');
    for (int i = 0; i < UI_LARGURA_QUADRO - 2; i++)
        putchar('-');
    puts("+");

    int espacos = (UI_LARGURA_QUADRO - strlen(titulo) - 2) / 2;
    putchar('|');
    for (int i = 0; i < espacos; i++)
        putchar(' ');
    printf("%s", titulo);
    for (int i = 0; i < UI_LARGURA_QUADRO - 2 - espacos - strlen(titulo); i++)
        putchar(' ');
    puts("|");

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