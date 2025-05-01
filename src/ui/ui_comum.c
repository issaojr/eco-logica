#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "ui/ui_comum.h"

#define UI_LARGURA_PADRAO 60
#define UI_COR_RESET "\033[0m"
#define UI_COR_VERMELHO "\033[31m"
#define UI_COR_VERDE "\033[32m"
#define UI_COR_AZUL "\033[34m"
#define UI_COR_AMARELO "\033[33m"
#define UI_COR_CIANO "\033[36m"
#define UI_COR_NEGRITO "\033[1m"

// Limpa o buffer de entrada
static void limpar_buffer_entrada(void) {
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
    
    ui_limpar_tela();
    printf("\n");
    
    // Borda superior
    ui_exibir_separador('=', largura);
    
    // Título centralizado
    int espacos = (largura - strlen(titulo)) / 2;
    printf("%*s%s%s%s%*s\n", 
           espacos, "", 
           UI_COR_NEGRITO, titulo, UI_COR_RESET, 
           espacos - (int)strlen(UI_COR_NEGRITO) - (int)strlen(UI_COR_RESET), "");
    
    // Subtítulo, se fornecido
    if (subtitulo != NULL && *subtitulo != '\0') {
        espacos = (largura - strlen(subtitulo)) / 2;
        printf("%*s%s%*s\n", espacos, "", subtitulo, espacos, "");
    }
    
    // Borda inferior
    ui_exibir_separador('=', largura);
    printf("\n");
}

void ui_exibir_erro(const char* mensagem) {
    printf("%s[ERRO] %s%s\n", UI_COR_VERMELHO, mensagem, UI_COR_RESET);
}

void ui_exibir_sucesso(const char* mensagem) {
    printf("%s[SUCESSO] %s%s\n", UI_COR_VERDE, mensagem, UI_COR_RESET);
}

void ui_exibir_info(const char* mensagem) {
    printf("%s[INFO] %s%s\n", UI_COR_AZUL, mensagem, UI_COR_RESET);
}

void ui_pausar(const char* mensagem) {
    if (mensagem != NULL) {
        printf("%s\n", mensagem);
    } else {
        printf("Pressione ENTER para continuar...");
    }
    // Espere o usuário pressionar ENTER
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
    
    // Verificar se a entrada é obrigatória e se o usuário forneceu algo
    if (obrigatorio && len == 0) {
        ui_exibir_erro("Campo obrigatório não pode ficar vazio");
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
            return padrao; // Em caso de erro, retorna o valor padrão
        }
        
        // Remover o caractere de nova linha, se presente
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n') {
            buffer[len - 1] = '\0';
            len--;
        }
        
        // Se a entrada estiver vazia e não for obrigatória, use o valor padrão
        if (len == 0 && !obrigatorio) {
            return padrao;
        }
        
        // Se a entrada estiver vazia e for obrigatória, peça novamente
        if (len == 0 && obrigatorio) {
            ui_exibir_erro("Campo obrigatório não pode ficar vazio");
            continue;
        }
        
        // Tentar converter para inteiro
        char* endptr;
        valor = strtol(buffer, &endptr, 10);
        
        // Verificar se a conversão foi bem-sucedida
        if (*endptr != '\0') {
            ui_exibir_erro("Entrada inválida. Digite um número inteiro");
            continue;
        }
        
        // Verificar se o valor está dentro dos limites
        if (valor < min || valor > max) {
            ui_exibir_erro("Valor fora dos limites permitidos");
            printf("O valor deve estar entre %d e %d\n", min, max);
            continue;
        }
        
        break;
    }
    
    return valor;
}

// Função auxiliar para validar uma data no formato DD/MM/AAAA
static bool validar_data(const char* data) {
    if (strlen(data) != 10) return false;
    
    // Verificar formato DD/MM/AAAA
    if (data[2] != '/' || data[5] != '/') return false;
    
    // Verificar se todos os outros caracteres são dígitos
    for (int i = 0; i < 10; i++) {
        if (i != 2 && i != 5 && !isdigit(data[i])) return false;
    }
    
    // Extrair dia, mês e ano
    int dia = (data[0] - '0') * 10 + (data[1] - '0');
    int mes = (data[3] - '0') * 10 + (data[4] - '0');
    int ano = (data[6] - '0') * 1000 + (data[7] - '0') * 100 + 
              (data[8] - '0') * 10 + (data[9] - '0');
    
    // Regras básicas de validação
    if (mes < 1 || mes > 12) return false;
    if (dia < 1) return false;
    
    // Dias máximos por mês
    int max_dias;
    switch (mes) {
        case 2: // Fevereiro
            // Verificação de ano bissexto
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
    if (tamanho < 11) return false; // Precisa de espaço para "DD/MM/AAAA\0"
    
    while (1) {
        if (prompt) {
            printf("%s (DD/MM/AAAA): ", prompt);
        }
        
        if (!ui_ler_string(NULL, buffer, tamanho, obrigatorio)) {
            if (!obrigatorio) return true;
            continue;
        }
        
        // Se não for obrigatório e estiver vazio, retorne
        if (!obrigatorio && buffer[0] == '\0') {
            return true;
        }
        
        // Validar a data
        if (validar_data(buffer)) {
            return true;
        } else {
            ui_exibir_erro("Data inválida. Use o formato DD/MM/AAAA");
        }
    }
}

// Função auxiliar para validar CNPJ
static bool validar_cnpj(const char* cnpj) {
    if (strlen(cnpj) != 18) return false;
    
    // Verificar formato XX.XXX.XXX/XXXX-XX
    if (cnpj[2] != '.' || cnpj[6] != '.' || cnpj[10] != '/' || cnpj[15] != '-') 
        return false;
    
    // Verificar se todos os outros caracteres são dígitos
    for (int i = 0; i < 18; i++) {
        if (i != 2 && i != 6 && i != 10 && i != 15 && !isdigit(cnpj[i]))
            return false;
    }
    
    // Poderíamos implementar a validação completa do CNPJ aqui,
    // mas isso seria mais complexo e exigiria verificar os dígitos verificadores
    
    return true;
}

bool ui_ler_cnpj(const char* prompt, char* buffer, size_t tamanho, bool obrigatorio) {
    if (tamanho < 19) return false; // Precisa de espaço para "XX.XXX.XXX/XXXX-XX\0"
    
    while (1) {
        if (prompt) {
            printf("%s (XX.XXX.XXX/XXXX-XX): ", prompt);
        }
        
        if (!ui_ler_string(NULL, buffer, tamanho, obrigatorio)) {
            if (!obrigatorio) return true;
            continue;
        }
        
        // Se não for obrigatório e estiver vazio, retorne
        if (!obrigatorio && buffer[0] == '\0') {
            return true;
        }
        
        // Validar o CNPJ
        if (validar_cnpj(buffer)) {
            return true;
        } else {
            ui_exibir_erro("CNPJ inválido. Use o formato XX.XXX.XXX/XXXX-XX");
        }
    }
}

bool ui_confirmar(const char* mensagem) {
    char resposta[10];
    
    printf("%s%s (S/N)? %s", UI_COR_AMARELO, mensagem, UI_COR_RESET);
    
    if (fgets(resposta, sizeof(resposta), stdin)) {
        // Converter para minúsculo
        resposta[0] = tolower(resposta[0]);
        return (resposta[0] == 's');
    }
    
    return false; // Padrão é não
}