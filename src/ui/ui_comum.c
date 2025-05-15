#include "ui/ui_comum.h"

// Limpa o buffer de entrada
void ui_limpar_buffer_entrada(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void ui_limpar_tela(void) {
    #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif
}

void ui_exibir_separador(char caractere, int largura) {
    for (int i = 0; i < largura; i++) {
        putchar(caractere);
    }
    putchar('\n');
}

void ui_exibir_titulo(const char* titulo, const char* subtitulo) {
    int largura = UI_LARGURA_PADRAO;
    
    // Borda superior
    ui_exibir_separador('=', largura);
    
    // T�tulo centralizado
    int espacos = (largura - strlen(titulo)) / 2;
    printf("%*s%s%s%s%*s\n", 
           espacos, "", 
           UI_COR_NEGRITO, titulo, UI_COR_RESET, 
           espacos - (int)strlen(UI_COR_NEGRITO) - (int)strlen(UI_COR_RESET), "");
    
    // Subt�tulo, se fornecido
    if (subtitulo != NULL && *subtitulo != '\0') {
        espacos = (largura - strlen(subtitulo)) / 2;
        printf("%*s%s%*s\n", espacos, "", subtitulo, espacos, "");
    }
    
    // Borda inferior
    ui_exibir_separador('=', largura);
    
}

void ui_exibir_erro(const char* mensagem) {
    char mensagem_formatada[150];
    snprintf(mensagem_formatada, UI_LARGURA_PADRAO, "%s[ERRO] %s%s\n", UI_COR_VERMELHO, mensagem, UI_COR_RESET);
    printf("%s", mensagem_formatada);
}

void ui_exibir_sucesso(const char* mensagem) {
    char mensagem_formatada[150];
    snprintf(mensagem_formatada, UI_LARGURA_PADRAO, "%s[SUCESSO] %s%s\n", UI_COR_VERDE, mensagem, UI_COR_RESET);
    printf("%s", mensagem_formatada);
}

void ui_exibir_info(const char* mensagem) {
    char mensagem_formatada[150];
    snprintf(mensagem_formatada, UI_LARGURA_PADRAO, "%s[INFO] %s%s\n", UI_COR_CIANO, mensagem, UI_COR_RESET);
    printf("%s", mensagem_formatada);
}

void ui_exibir_to_do(const char* mensagem) {
    char mensagem_formatada[150];
    snprintf(mensagem_formatada, UI_LARGURA_PADRAO, "%s[TODO] %s%s\n", UI_COR_LARANJA, mensagem, UI_COR_RESET);
    printf("%s", mensagem_formatada);
}

void ui_exibir_debug(const char* mensagem) {
    char mensagem_formatada[150];
    snprintf(mensagem_formatada, UI_LARGURA_PADRAO, "%s[DEBUG] %s%s\n", UI_COR_CIANO, mensagem, UI_COR_RESET);
    printf("%s", mensagem_formatada);
}

char* ui_prompt_selecao_opcao(const char* texto, int limite_min, int limite_max) {
    // Buffer est�tico para armazenar o resultado
    static char buffer[128];
    
    // C�digo ANSI para texto amarelo (cor fixa)
    const char* cor_amarela = "\033[1;33m";
    const char* reset_cor = "\033[0m";
    
    // Formatar o prompt com texto e limites
    snprintf(buffer, sizeof(buffer), "\n%s%s (%d-%d):%s ", 
             cor_amarela, texto, limite_min, limite_max, reset_cor);
    
    return buffer;
}

void ui_prompt_continuar(const char* mensagem) {
    if (mensagem != NULL) {
        printf("%s%s%s\n", UI_COR_AMARELO, mensagem, UI_COR_RESET);
    } else {
        printf("%sPressione ENTER para continuar...%s\n", UI_COR_AMARELO, UI_COR_RESET);
    }
    //ui_limpar_buffer_entrada(); // Limpa o buffer antes de esperar a entrada
    getchar(); // Espera o usu�rio pressionar ENTER
}

void ui_prompt_voltar_inicio(const char* mensagem) {
    if (mensagem != NULL) {
        printf("%s%s%s\n", UI_COR_AMARELO, mensagem, UI_COR_RESET);
    } else {
        printf("%sPressione ENTER para voltar ao in�cio...%s\n", UI_COR_AMARELO, UI_COR_RESET);
    }
    //ui_limpar_buffer_entrada(); // Limpa o buffer antes de esperar a entrada
    getchar(); // Espera o usu�rio pressionar ENTER
}

void ui_prompt_voltar_menu_principal(const char* mensagem) {
    if (mensagem != NULL) {
        printf("%s%s%s\n", UI_COR_AMARELO, mensagem, UI_COR_RESET);
    } else {
        printf("%sPressione ENTER para voltar ao menu principal...%s\n", UI_COR_AMARELO, UI_COR_RESET);
    }
    //ui_limpar_buffer_entrada(); // Limpa o buffer antes de esperar a entrada
    getchar(); // Espera o usu�rio pressionar ENTER
}

void ui_prompt_voltar_menu_anterior(const char* mensagem) {
    if (mensagem != NULL) {
        printf("%s%s%s\n", UI_COR_AMARELO, mensagem, UI_COR_RESET);
    } else {
        printf("%sPressione ENTER para voltar ao menu anterior...%s\n", UI_COR_AMARELO, UI_COR_RESET);
    }
    //ui_limpar_buffer_entrada(); // Limpa o buffer antes de esperar a entrada
    getchar(); // Espera o usu�rio pressionar ENTER
}
void ui_prompt_sair(const char* mensagem) {
    if (mensagem != NULL) {
        printf("%s%s%s\n", UI_COR_AMARELO, mensagem, UI_COR_RESET);
    } else {
        printf("%sPressione ENTER para finalizar...%s\n", UI_COR_AMARELO, UI_COR_RESET);
    }
    //ui_limpar_buffer_entrada(); // Limpa o buffer antes de esperar a entrada
    getchar(); // Espera o usu�rio pressionar ENTER
}

void ui_exibir_data_hora() {
    // Obter data e hora atual
    time_t t = time(NULL);
    struct tm *tm_info = localtime(&t);
    char data_hora[64];
    strftime(data_hora, sizeof(data_hora), "%d/%m/%Y %H:%M", tm_info);
    
    // Exibir informa��es adicionais
    printf("%sData e hora: %s%s\n", UI_COR_CIANO, data_hora, UI_COR_RESET);
}

void ui_pausar(const char* mensagem) {
    if (mensagem != NULL) {
        printf("%s\n", mensagem);
    } else {
        printf("Pressione ENTER para continuar...");
    }
    // Espere o usu�rio pressionar ENTER
    getchar();
}

bool ui_ler_string(const char* prompt, char* buffer, size_t tamanho, bool obrigatorio) {
    if (prompt) {
        printf("%s: ", prompt);
    }
    
    // Garantir que o buffer esteja vazio
    buffer[0] = '\0';
    
    // Ler a linha de entrada
    if (fgets(buffer, tamanho, stdin) == NULL) {
        return false;
    }
    
    // Remover o caractere de nova linha, se presente
    size_t len = strlen(buffer);
    if (len > 0 && buffer[len - 1] == '\n') {
        buffer[len - 1] = '\0';
        len--;
    }
    
    // Verificar se a entrada � obrigat�ria e se o usu�rio forneceu algo
    if (obrigatorio && len == 0) {
        ui_exibir_erro("Campo obrigat�rio n�o pode ficar vazio");
        return false;
    }
    
    return true;
}

int ui_ler_inteiro(const char* prompt, int min, int max, int padrao, bool obrigatorio) {
    char buffer[64];
    int valor;
    
    while (1) {
        if (prompt) {
            printf("%s", prompt);
            if (!obrigatorio) {
                printf(" [%d]: ", padrao);
            } else {
                printf(": ");
            }
        }
        
        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            return padrao; // Em caso de erro, retorna o valor padr�o
        }
        
        // Remover o caractere de nova linha, se presente
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n') {
            buffer[len - 1] = '\0';
            len--;
        }
        
        // Se a entrada estiver vazia e n�o for obrigat�ria, use o valor padr�o
        if (len == 0 && !obrigatorio) {
            return padrao;
        }
        
        // Se a entrada estiver vazia e for obrigat�ria, pe�a novamente
        if (len == 0 && obrigatorio) {
            ui_exibir_erro("Campo obrigat�rio n�o pode ficar vazio");
            continue;
        }
        
        // Tentar converter para inteiro
        char* endptr;
        valor = strtol(buffer, &endptr, 10);
        
        // Verificar se a convers�o foi bem-sucedida
        if (*endptr != '\0') {
            ui_exibir_erro("Entrada inv�lida. Digite um n�mero inteiro");
            continue;
        }
        
        // Verificar se o valor est� dentro dos limites
        if (valor < min || valor > max) {
            ui_exibir_erro("Valor fora dos limites permitidos");
            printf("O valor deve estar entre %d e %d\n", min, max);
            continue;
        }
        
        break;
    }
    
    return valor;
}

// Fun��o auxiliar para validar uma data no formato DD/MM/AAAA
static bool ui_validar_data(const char* data) {
    if (strlen(data) != 10) return false;
    
    // Verificar formato DD/MM/AAAA
    if (data[2] != '/' || data[5] != '/') return false;
    
    // Verificar se todos os outros caracteres s�o d�gitos
    for (int i = 0; i < 10; i++) {
        if (i != 2 && i != 5 && !isdigit(data[i])) return false;
    }
    
    // Extrair dia, m�s e ano
    int dia = (data[0] - '0') * 10 + (data[1] - '0');
    int mes = (data[3] - '0') * 10 + (data[4] - '0');
    int ano = (data[6] - '0') * 1000 + (data[7] - '0') * 100 + 
              (data[8] - '0') * 10 + (data[9] - '0');
    
    // Regras b�sicas de valida��o
    if (mes < 1 || mes > 12) return false;
    if (dia < 1) return false;
    
    // Dias m�ximos por m�s
    int max_dias;
    switch (mes) {
        case 2: // Fevereiro
            // Verifica��o de ano bissexto
            if ((ano % 4 == 0 && ano % 100 != 0) || ano % 400 == 0)
                max_dias = 29;
            else
                max_dias = 28;
            break;
        case 4: case 6: case 9: case 11: // Meses com 30 dias
            max_dias = 30;
            break;
        default: // Meses com 31 dias
            max_dias = 31;
            break;
    }
    
    if (dia > max_dias) return false;
    
    return true;
}

bool ui_ler_data(const char* prompt, char* buffer, size_t tamanho, bool obrigatorio) {
    if (tamanho < 11) return false; // Precisa de espa�o para "DD/MM/AAAA\0"
    
    while (1) {
        if (prompt) {
            printf("%s (DD/MM/AAAA): ", prompt);
        }
        
        if (!ui_ler_string(NULL, buffer, tamanho, obrigatorio)) {
            if (!obrigatorio) return true;
            continue;
        }
        
        // Se n�o for obrigat�rio e estiver vazio, retorne
        if (!obrigatorio && buffer[0] == '\0') {
            return true;
        }
        
        // Validar a data
        if (ui_validar_data(buffer)) {
            return true;
        } else {
            ui_exibir_erro("Data inv�lida. Use o formato DD/MM/AAAA");
        }
    }
}

// Fun��o auxiliar para validar CNPJ
static bool ui_validar_cnpj(const char* cnpj) {
    if (strlen(cnpj) != 18) return false;
    
    // Verificar formato XX.XXX.XXX/XXXX-XX
    if (cnpj[2] != '.' || cnpj[6] != '.' || cnpj[10] != '/' || cnpj[15] != '-') 
        return false;
    
    // Verificar se todos os outros caracteres s�o d�gitos
    for (int i = 0; i < 18; i++) {
        if (i != 2 && i != 6 && i != 10 && i != 15 && !isdigit(cnpj[i]))
            return false;
    }
    
    // Poder�amos implementar a valida��o completa do CNPJ aqui,
    // mas isso seria mais complexo e exigiria verificar os d�gitos verificadores
    
    return true;
}

bool ui_ler_cnpj(const char* prompt, char* buffer, size_t tamanho, bool obrigatorio) {
    if (tamanho < 19) return false; // Precisa de espa�o para "XX.XXX.XXX/XXXX-XX\0"
    
    while (1) {
        if (prompt) {
            printf("%s (XX.XXX.XXX/XXXX-XX): ", prompt);
        }
        
        if (!ui_ler_string(NULL, buffer, tamanho, obrigatorio)) {
            if (!obrigatorio) return true;
            continue;
        }
        
        // Se n�o for obrigat�rio e estiver vazio, retorne
        if (!obrigatorio && buffer[0] == '\0') {
            return true;
        }
        
        // Validar o CNPJ
        if (ui_validar_cnpj(buffer)) {
            return true;
        } else {
            ui_exibir_erro("CNPJ inv�lido. Use o formato XX.XXX.XXX/XXXX-XX");
        }
    }
}

bool ui_confirmar(const char* mensagem) {
    char resposta[10];
    
    while (1) {
        printf("%s%s (S/N)? %s", UI_COR_AMARELO, mensagem, UI_COR_RESET);
        
        if (fgets(resposta, sizeof(resposta), stdin)) {
            // Remover quebra de linha
            size_t len = strlen(resposta);
            if (len > 0 && resposta[len - 1] == '\n') {
                resposta[len - 1] = '\0';
                len--;
            }
            
            // Se estiver vazio, pedir novamente
            if (len == 0) {
                ui_exibir_info("Por favor, responda S para Sim ou N para N�o.");
                continue;
            }
            
            // Converter para mai�sculo para facilitar compara��o
            ui_converter_para_maiusculo(resposta);
            
            // Verificar respostas v�lidas
            if (resposta[0] == 'S' || strcmp(resposta, "SIM") == 0) {
                return true;
            }
            else if (resposta[0] == 'N' || strcmp(resposta, "NAO") == 0 || strcmp(resposta, "N�O") == 0) {
                return false;
            }
            else {
                ui_exibir_erro("Resposta inv�lida. Por favor, responda S para Sim ou N para N�o.");
                continue;
            }
        }
        else {
            // Erro de leitura
            ui_exibir_erro("Erro na leitura da resposta.");
            return false; // Padr�o � n�o
        }
    }
}

void ui_desenhar_cabecalho(const char* titulo) {
    // Desenha a borda superior din�mica
    putchar('+'); for (int i = 0; i < UI_LARGURA_QUADRO - 2; i++) putchar('-'); puts("+");
    // Linha em branco centralizada
    //putchar('|'); for (int i = 0; i < UI_LARGURA_QUADRO - 2; i++) putchar(' '); puts("|");

    // Desenha a linha de t�tulo centralizado
    int espacos = (UI_LARGURA_QUADRO - strlen(titulo) - 2) / 2;
    putchar('|');
    for (int i = 0; i < espacos; i++) putchar(' ');
    printf("%s", titulo);
    for (int i = 0; i < UI_LARGURA_QUADRO - 2 - espacos - strlen(titulo); i++) putchar(' ');
    puts("|");

    // Desenha linha simples ap�s o t�tulo
    ui_desenhar_linha_simples();
}

void ui_desenhar_linha_simples(void) {
    // Linha separadora din�mica (barra e tra�os)
    putchar('+');
    for (int i = 0; i < UI_LARGURA_QUADRO - 2; i++) putchar('-');
    puts("+");
}

void ui_desenhar_rodape(void) {
    // Rodap� din�mico (barra e tra�os)
    putchar('+');
    for (int i = 0; i < UI_LARGURA_QUADRO - 2; i++) putchar('-');
    puts("+");
}

void desenhar_caixa_mensagem(const char* mensagem, int tipo) {
    const char* prefixo;
    
    // Determina o prefixo baseado no tipo
    switch (tipo) {
        case 0: // info
            prefixo = "INFO";
            break;
        case 1: // sucesso
            prefixo = "SUCESSO";
            break;
        case 2: // erro
            prefixo = "ERRO";
            break;
        default:
            prefixo = "";
    }
    
    // Desenha a caixa superior din�mica
    ui_desenhar_linha_simples();
    
    // Linha com o tipo da mensagem
    if (strlen(prefixo) > 0) {
        // Prefixo centralizado ou ajustado
        int esp = UI_LARGURA_QUADRO - 4 - strlen(prefixo);
        printf("| [%s]%*s |\n", prefixo, esp, "");
        ui_desenhar_linha_simples();
    }
    
    // Mensagem principal
    printf("| %-*s |\n", UI_LARGURA_QUADRO - 4, mensagem);
    
    // Rodap� da caixa din�mica
    ui_desenhar_rodape();
}

void ui_desenhar_painel_funcionario(const char* funcionario, const char* matricula) {
    char linha[UI_LARGURA_QUADRO - 3];
    ui_desenhar_linha_simples();
    snprintf(linha, sizeof(linha), "Funcion�rio: %s", funcionario);
    printf("| %-*s |\n", UI_LARGURA_QUADRO - 4, linha);
    snprintf(linha, sizeof(linha), "Matr�cula: %s", matricula);
    printf("| %-*s |\n", UI_LARGURA_QUADRO - 4, linha);
    ui_desenhar_rodape();
}

void ui_desenhar_painel_funcionario_selecionado(const char* funcionario, int matricula) {
    /* Converte matricula para string */
    char mat_str[32];
    snprintf(mat_str, sizeof(mat_str), "%d", matricula);

    /* Desenha o painel do funcion�rio */
    char linha[UI_LARGURA_QUADRO - 3];
    ui_desenhar_linha_simples();
    snprintf(linha, sizeof(linha), "=> Funcion�rio Selecionado");
    printf("| %-*s |\n", UI_LARGURA_QUADRO - 4, linha);
    ui_desenhar_linha_simples();
    snprintf(linha, sizeof(linha), "Funcion�rio: %s", funcionario);
    printf("| %-*s |\n", UI_LARGURA_QUADRO - 4, linha);
    snprintf(linha, sizeof(linha), "Matr�cula: %s", mat_str);
    printf("| %-*s |\n", UI_LARGURA_QUADRO - 4, linha);
    ui_desenhar_rodape();
}

void ui_desenhar_linha_funcionario(const char* funcionario, const char* matricula) {
    char linha[UI_LARGURA_PADRAO];
    snprintf(linha, sizeof(linha), "Funcion�rio: %s (Matr: %s)", funcionario, matricula);
    printf(" %-*s \n", UI_LARGURA_PADRAO - 4, linha);
}

void ui_desenhar_tela_padrao(
    const char *titulo, 
    const char *subtitulo, 
    const char *nome_funcionario, 
    const int matricula) {
    // Limpa a tela
    ui_limpar_tela();

    if (nome_funcionario != NULL && matricula > 0) {
        // Exibe o painel do funcion�rio logado
        char mat_str[32];
        snprintf(mat_str, sizeof(mat_str), "%d", matricula);
        ui_desenhar_linha_funcionario(nome_funcionario, mat_str);
    }

    // Exibe o t�tulo e subt�tulo
    ui_exibir_titulo(titulo, subtitulo);

    // if (nome_funcionario != NULL && matricula > 0) {
    //     // Exibe o painel do funcion�rio logado
    //     char mat_str[32];
    //     snprintf(mat_str, sizeof(mat_str), "%d", matricula);
    //     ui_desenhar_painel_funcionario(nome_funcionario, mat_str);
    // }
}

/**
 * @brief Desenha parte superior de uma tela de formul�rio padr�o
 * @param titulo T�tulo da tela
 * @param subtitulo Subt�tulo da tela
 * @param titulo_cabecalho T�tulo do cabe�alho
 */
void ui_desenhar_tela_formulario_padrao(
    const char *titulo, 
    const char *subtitulo,
    const char *titulo_cabecalho) {
    // Limpa a tela
    ui_limpar_tela();

    // Exibe o t�tulo e subt�tulo
    ui_exibir_titulo(titulo, subtitulo);

    // Exibe cabecalho do menu
    ui_desenhar_cabecalho(titulo_cabecalho);

    printf("\n");
}

/**
 * @brief Desenha parte superior de uma tela de relat�rio padr�o
 * @param titulo T�tulo da tela
 * @param subtitulo Subt�tulo da tela
 * @param titulo_cabecalho T�tulo do cabe�alho
 */
void ui_desenhar_tela_relatorio_padrao(
    const char *titulo, 
    const char *subtitulo,
    const char *titulo_cabecalho) {
    // Limpa a tela
    ui_limpar_tela();

    // Exibe o t�tulo e subt�tulo
    ui_exibir_titulo(titulo, subtitulo);

    // Exibe cabecalho do menu
    ui_desenhar_cabecalho(titulo_cabecalho);

    printf("\n");
}

void ui_desenhar_tela_sucesso(const char* titulo, const char* mensagem) {
    // Limpa a tela
    ui_limpar_tela();

    // Exibe o t�tulo
    ui_exibir_titulo(titulo, NULL);

    printf("\n");
    ui_exibir_separador('*', UI_LARGURA_PADRAO);
    // Exibe a mensagem de sucesso
    ui_exibir_sucesso(mensagem);
    printf("\n");
    ui_exibir_separador('*', UI_LARGURA_PADRAO);
    printf("\n");

    ui_prompt_voltar_menu_anterior(NULL);
}

void ui_desenhar_tela_erro(const char* titulo, const char* mensagem) {
    // Limpa a tela
    ui_limpar_tela();

    // Exibe o t�tulo
    ui_exibir_titulo(titulo, NULL);

    printf("\n");
    ui_exibir_separador('*', UI_LARGURA_PADRAO);
    // Exibe a mensagem de erro
    ui_exibir_erro(mensagem);
    printf("\n");
    ui_exibir_separador('*', UI_LARGURA_PADRAO);
    printf("\n");

    ui_prompt_voltar_menu_anterior(NULL);
}

void ui_converter_para_maiusculo(char* str) {
    if (!str) return;

    for (size_t i = 0; str[i] != '\0'; i++) {
        str[i] = (char) toupper((unsigned char) str[i]);
    }
}

void ui_converter_para_minusculo(char* str) {
    if (!str) return;

    for (size_t i = 0; str[i] != '\0'; i++) {
        str[i] = (char) tolower((unsigned char) str[i]);
    }
}