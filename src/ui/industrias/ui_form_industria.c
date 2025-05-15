#include "ui/industrias/ui_form_industria.h"

// // Função auxiliar para validar CNPJ (apenas verifica se são 14 dígitos numéricos)
// static bool validar_cnpj(const char* cnpj) {
//     if (strlen(cnpj) != 14)
//         return false;
    
//     for (int i = 0; i < 14; i++) {
//         if (!isdigit(cnpj[i]))
//             return false;
//     }
    
//     return true;
// }

// // Função auxiliar para validar formato de data dd/mm/aaaa usando time.h
// static bool validar_data(const char* data) {
//     if (strlen(data) != 10)
//         return false;
    
//     // Verificar formato dd/mm/aaaa
//     if (data[2] != '/' || data[5] != '/')
//         return false;
    
//     // Verificar se os caracteres nas posições corretas são dígitos
//     for (int i = 0; i < 10; i++) {
//         if (i == 2 || i == 5) continue;  // Ignora os separadores '/'
//         if (!isdigit(data[i]))
//             return false;
//     }
    
//     // Extrair dia, mês e ano como inteiros
//     int dia, mes, ano;
//     if (sscanf(data, "%2d/%2d/%4d", &dia, &mes, &ano) != 3) {
//         return false;
//     }
    
//     // Criar uma estrutura tm para validação com time.h
//     struct tm time_data = {0};
//     time_data.tm_mday = dia;
//     time_data.tm_mon = mes - 1;  // tm_mon vai de 0 a 11
//     time_data.tm_year = ano - 1900;  // tm_year é anos desde 1900
    
//     // Validar a data usando mktime
//     time_t time_check = mktime(&time_data);
//     if (time_check == -1)
//         return false;
    
//     // Verificar se o mktime normalizou a data (se corrigiu valores inválidos)
//     if (time_data.tm_mday != dia || 
//         time_data.tm_mon != mes - 1 || 
//         time_data.tm_year != ano - 1900)
//         return false;
    
//     // Verificar se a data não é futura
//     time_t now = time(NULL);
//     if (difftime(time_check, now) > 0)
//         return false;
    
//     return true;
// }

// // Função auxiliar para validar formato de CEP (8 dígitos numéricos)
// static bool validar_cep(const char* cep) {
//     if (strlen(cep) != 8)
//         return false;
    
//     for (int i = 0; i < 8; i++) {
//         if (!isdigit(cep[i]))
//             return false;
//     }
    
//     return true;
// }

// // Função auxiliar para validar formato de estado (2 letras maiúsculas)
// static bool validar_estado(const char* estado) {
//     if (strlen(estado) != 2)
//         return false;
    
//     if (!isupper(estado[0]) || !isupper(estado[1]))
//         return false;
    
//     return true;
// }

// // Função auxiliar para validar email (verificação aprimorada)
// static bool validar_email(const char* email) {
//     if (!email || strlen(email) == 0) 
//         return false;
        
//     // Verificar tamanho mínimo para um email válido (x@y.z)
//     if (strlen(email) < 5) 
//         return false;

//     // Verificação básica: deve conter pelo menos um @ e um . após o @
//     const char* at = strchr(email, '@');
//     if (!at) return false;
    
//     const char* dot = strchr(at, '.');
//     if (!dot) return false;
    
//     // Verifica se há pelo menos um caractere antes do @, entre @ e . e depois do .
//     if (at == email) return false;
//     if (dot == at + 1) return false;
//     if (*(dot + 1) == '\0') return false;
    
//     // Verificar caracteres inválidos no email
//     for (const char* c = email; *c; c++) {
//         // Permitir apenas caracteres alfanuméricos, '_', '-', '.', '@'
//         if (!isalnum(*c) && *c != '_' && *c != '-' && *c != '.' && *c != '@') {
//             return false;
//         }
//     }
    
//     return true;
// }

// // void ui_ler_cnpj_industria(char* cnpj_buffer, size_t tamanho) {
    
// //     const char* prompt = PROMPT_FORM("Digite o CNPJ da indústria (somente números)");

// //     while (1) {
// //         printf("%s", prompt);
        
// //         // Limpar o buffer de entrada antes de ler um novo CNPJ
// //         //ui_limpar_buffer_entrada();
        
// //         if (ui_ler_string(NULL, cnpj_buffer, tamanho, true)) {
// //             if (validar_cnpj(cnpj_buffer)) {
// //                 // Garantir terminação nula e evitar estouro de buffer
// //                 cnpj_buffer[tamanho - 1] = '\0';
// //                 return; // CNPJ válido
// //             } else {
// //                 ui_exibir_erro("CNPJ inválido. Digite exatamente 14 números.");
// //             }
// //         } else {
// //             ui_exibir_erro("Entrada inválida.");
// //         }
// //     }
// // }

// /**
//  * Lê uma string de stdin com fgets e descarta o '\n' final, se presente.
//  * Retorna true em sucesso, false em EOF ou erro.
//  */
// static bool ui_ler_fstring(char *buffer, size_t size) {
//     if (!fgets(buffer, (int)size, stdin))
//         return false;
//     // remover eventual '\n' final
//     size_t len = strlen(buffer);
//     if (len > 0 && buffer[len-1] == '\n')
//         buffer[--len] = '\0';
//     return true;
// }

// void ui_ler_cnpj_industria(char *cnpj_buffer, size_t tamanho) {
//     const char *prompt = PROMPT_FORM("Digite o CNPJ da indústria (somente números)");
//     char input[CNPJ_BUFFER_SIZE];

//     // Garantir que o buffer tenha espaço mínimo
//     if (tamanho < CNPJ_BUFFER_SIZE) {
//         ui_exibir_erro("Buffer insuficiente para CNPJ.");
//         return;
//     }

//     while (true) {
//         printf("%s", prompt);

//         // ler linha inteira
//         if (!ui_ler_fstring(input, sizeof(input))) {
//             ui_exibir_erro("Falha na leitura. Tente novamente.");
//             // limpar estado de erro de stdin, se necessário
//             clearerr(stdin);
//             continue;
//         }

//         // validar comprimento e conteúdo numérico
//         if (strlen(input) != CNPJ_DIGITOS) {
//             ui_exibir_erro("CNPJ deve ter exatamente 14 dígitos.");
//             continue;
//         }
//         bool todos_numeros = true;
//         for (size_t i = 0; i < CNPJ_DIGITOS; i++) {
//             if (input[i] < '0' || input[i] > '9') {
//                 todos_numeros = false;
//                 break;
//             }
//         }
//         if (!todos_numeros) {
//             ui_exibir_erro("Use apenas caracteres numéricos (0–9).");
//             continue;
//         }

//         // validação complementar
//         if (!validar_cnpj(input)) {
//             ui_exibir_erro("CNPJ inválido segundo algoritmo de verificação.");
//             continue;
//         }

//         // tudo ok: copiar para o buffer de saída
//         strncpy(cnpj_buffer, input, tamanho);
//         cnpj_buffer[CNPJ_DIGITOS] = '\0';  // garantia extra
//         break;
//     }
// }

// void ui_ler_razao_social_industria(char* razao_social_buffer, size_t tamanho) {
//     const char* prompt = PROMPT_FORM("Digite a razão social da indústria");

//     while (1) {
//         printf("%s", prompt);
        
//         // Garantir que o buffer de entrada esteja limpo
//         //ui_limpar_buffer_entrada();
        
//         // if (ui_ler_string(NULL, razao_social_buffer, tamanho, true)) {
//         //     if (strlen(razao_social_buffer) > 0) {
//         //         // Converter para maiúsculas
//         //         ui_converter_para_maiusculo(razao_social_buffer);
                
//         //         // Garantir terminação nula e evitar estouro de buffer
//         //         razao_social_buffer[tamanho - 1] = '\0';
//         //         return; // Razão social válida
//         //     } else {
//         //         ui_exibir_erro("A razão social não pode ficar em branco.");
//         //     }
//         // } else {
//         //     ui_exibir_erro("Entrada inválida.");
//         // }

//         // Lê a entrada como string
//         if (ui_ler_string(NULL, razao_social_buffer, tamanho, true)) {
//             ui_converter_para_maiusculo(razao_social_buffer);
//             return; // Nome lido com sucesso
//         }
//         ui_exibir_erro("Entrada inválida. Tente novamente.");
//         // continua o loop automaticamente
//     }
// }

// void ui_ler_nome_fantasia_industria(char* nome_fantasia_buffer, size_t tamanho) {
//     const char* prompt = PROMPT_FORM("Digite o nome fantasia da indústria");

//     while (1) {
//         printf("%s", prompt);
        
//         if (ui_ler_string(NULL, nome_fantasia_buffer, tamanho, true)) {
//             ui_converter_para_maiusculo(nome_fantasia_buffer);
//             return; 
//         } else {
//             ui_exibir_erro("Entrada inválida. Tente novamente.");
//             continue;
//         }
//     }
// }

// void ui_ler_telefone_industria(char* telefone_buffer, size_t tamanho) {
//     const char* prompt = PROMPT_FORM("Digite o telefone da indústria");

//     while (1) {
//         printf("%s", prompt);
        
//         if (ui_ler_string(NULL, telefone_buffer, tamanho, true)) {
//             if (strlen(telefone_buffer) >= 8) {
//                 // Garantir terminação nula e evitar estouro de buffer
//                 telefone_buffer[tamanho - 1] = '\0';
//                 return; // Telefone válido
//             } else {
//                 ui_exibir_erro("O telefone deve ter no mínimo 8 caracteres.");
//             }
//         } else {
//             ui_exibir_erro("Entrada inválida.");
//         }
//     }
// }

// void ui_ler_logradouro_industria(char* logradouro_buffer, size_t tamanho) {
//     const char* prompt = PROMPT_FORM("Digite o logradouro (rua/avenida) da indústria");

//     while (1) {
//         printf("%s", prompt);
        
//         if (ui_ler_string(NULL, logradouro_buffer, tamanho, true)) {
//             if (strlen(logradouro_buffer) > 0) {
//                 // Converter para maiúsculas
//                 ui_converter_para_maiusculo(logradouro_buffer);
                
//                 // Garantir terminação nula e evitar estouro de buffer
//                 logradouro_buffer[tamanho - 1] = '\0';
//                 return; // Logradouro válido
//             } else {
//                 ui_exibir_erro("O logradouro não pode ficar em branco.");
//             }
//         } else {
//             ui_exibir_erro("Entrada inválida.");
//         }
//     }
// }

// void ui_ler_numero_industria(char* numero_buffer, size_t tamanho) {
//     const char* prompt = PROMPT_FORM("Digite o número do endereço da indústria");

//     while (1) {
//         printf("%s", prompt);
        
//         if (ui_ler_string(NULL, numero_buffer, tamanho, true)) {
//             if (strlen(numero_buffer) > 0) {
//                 // Garantir terminação nula e evitar estouro de buffer
//                 numero_buffer[tamanho - 1] = '\0';
//                 return; // Número válido
//             } else {
//                 ui_exibir_erro("O número não pode ficar em branco.");
//             }
//         } else {
//             ui_exibir_erro("Entrada inválida.");
//         }
//     }
// }

// void ui_ler_bairro_industria(char* bairro_buffer, size_t tamanho) {
//     const char* prompt = PROMPT_FORM("Digite o bairro da indústria");

//     while (1) {
//         printf("%s", prompt);
        
//         if (ui_ler_string(NULL, bairro_buffer, tamanho, true)) {
//             if (strlen(bairro_buffer) > 0) {
//                 // Converter para maiúsculas
//                 ui_converter_para_maiusculo(bairro_buffer);
                
//                 // Garantir terminação nula e evitar estouro de buffer
//                 bairro_buffer[tamanho - 1] = '\0';
//                 return; // Bairro válido
//             } else {
//                 ui_exibir_erro("O bairro não pode ficar em branco.");
//             }
//         } else {
//             ui_exibir_erro("Entrada inválida.");
//         }
//     }
// }

// void ui_ler_cidade_industria(char* cidade_buffer, size_t tamanho) {
//     const char* prompt = PROMPT_FORM("Digite a cidade da indústria");

//     while (1) {
//         printf("%s", prompt);
        
//         if (ui_ler_string(NULL, cidade_buffer, tamanho, true)) {
//             if (strlen(cidade_buffer) > 0) {
//                 // Converter para maiúsculas
//                 ui_converter_para_maiusculo(cidade_buffer);
                
//                 // Garantir terminação nula e evitar estouro de buffer
//                 cidade_buffer[tamanho - 1] = '\0';
//                 return; // Cidade válida
//             } else {
//                 ui_exibir_erro("A cidade não pode ficar em branco.");
//             }
//         } else {
//             ui_exibir_erro("Entrada inválida.");
//         }
//     }
// }

// void ui_ler_estado_industria(char* estado_buffer, size_t tamanho) {
//     // Garantir que o tamanho do buffer seja suficiente
//     if (tamanho < 3) { // UF precisa de 2 caracteres + terminador nulo
//         ui_exibir_erro("Erro interno: Buffer UF muito pequeno");
//         return;
//     }
    
//     const char* prompt = PROMPT_FORM("Digite a UF do estado (ex: SP, RJ)");

//     while (1) {
//         printf("%s", prompt);
        
//         if (ui_ler_string(NULL, estado_buffer, tamanho, true)) {
//             // Converter para maiúsculas usando a função comum
//             ui_converter_para_maiusculo(estado_buffer);
            
//             // Garantir terminação nula e evitar estouro de buffer
//             estado_buffer[tamanho - 1] = '\0';
            
//             if (validar_estado(estado_buffer)) {
//                 return; // Estado válido
//             } else {
//                 ui_exibir_erro("UF inválida. Digite exatamente 2 letras (ex: SP, RJ).");
//             }
//         } else {
//             ui_exibir_erro("Entrada inválida.");
//         }
//     }
// }

// void ui_ler_cep_industria(char* cep_buffer, size_t tamanho) {
//     // Garantir que o tamanho do buffer seja suficiente
//     if (tamanho < 9) { // CEP precisa de 8 caracteres + terminador nulo
//         ui_exibir_erro("Erro interno: Buffer CEP muito pequeno");
//         return;
//     }
    
//     const char* prompt = PROMPT_FORM("Digite o CEP (somente números)");

//     while (1) {
//         printf("%s", prompt);
        
//         if (ui_ler_string(NULL, cep_buffer, tamanho, true)) {
//             // Garantir terminação nula e evitar estouro de buffer
//             cep_buffer[tamanho - 1] = '\0';
            
//             if (validar_cep(cep_buffer)) {
//                 return; // CEP válido
//             } else {
//                 ui_exibir_erro("CEP inválido. Digite exatamente 8 números.");
//             }
//         } else {
//             ui_exibir_erro("Entrada inválida.");
//         }
//     }
// }

// void ui_ler_data_abertura_industria(char* data_buffer, size_t tamanho) {
//     // Garantir que o tamanho do buffer seja suficiente
//     if (tamanho < 11) { // Data precisa de 10 caracteres + terminador nulo
//         ui_exibir_erro("Erro interno: Buffer data muito pequeno");
//         return;
//     }
    
//     const char* prompt = PROMPT_FORM("Digite a data de abertura (formato: dd/mm/aaaa)");

//     while (1) {
//         printf("%s", prompt);
        
//         if (ui_ler_string(NULL, data_buffer, tamanho, true)) {
//             // Garantir terminação nula e evitar estouro de buffer
//             data_buffer[tamanho - 1] = '\0';
            
//             if (validar_data(data_buffer)) {
//                 return; // Data válida
//             } else {
//                 ui_exibir_erro("Data inválida. Use o formato dd/mm/aaaa.");
//             }
//         } else {
//             ui_exibir_erro("Entrada inválida.");
//         }
//     }
// }

// void ui_ler_nome_responsavel_industria(char* nome_buffer, size_t tamanho) {
//     const char* prompt = PROMPT_FORM("Digite o nome do responsável");

//     while (1) {
//         printf("%s", prompt);
        
//         if (ui_ler_string(NULL, nome_buffer, tamanho, true)) {
//             if (strlen(nome_buffer) > 0) {
//                 // Converter para maiúsculas
//                 ui_converter_para_maiusculo(nome_buffer);
                
//                 // Garantir terminação nula e evitar estouro de buffer
//                 nome_buffer[tamanho - 1] = '\0';
//                 return; // Nome válido
//             } else {
//                 ui_exibir_erro("O nome não pode ficar em branco.");
//             }
//         } else {
//             ui_exibir_erro("Entrada inválida.");
//         }
//     }
// }

// void ui_ler_email_responsavel_industria(char* email_buffer, size_t tamanho) {
//     const char* prompt = PROMPT_FORM("Digite o email do responsável");

//     while (1) {
//         printf("%s", prompt);
        
//         if (ui_ler_string(NULL, email_buffer, tamanho, true)) {
//             // Garantir terminação nula e evitar estouro de buffer
//             email_buffer[tamanho - 1] = '\0';
            
//             if (validar_email(email_buffer)) {
//                 return; // Email válido
//             } else {
//                 ui_exibir_erro("Email inválido. Verifique o formato.");
//             }
//         } else {
//             ui_exibir_erro("Entrada inválida.");
//         }
//     }
// }





// ---------------------
// Função de leitura genérica
// ---------------------
// static bool ui_ler_fstring(char *buf, size_t sz) {
//     if (!fgets(buf, (int)sz, stdin)) return false;
//     size_t len = strlen(buf);
//     if (len && buf[len-1] == '\n') buf[--len] = '\0';
//     return true;
// }

// /**
//  * Lê um campo de texto:
//  *  - imprime prompt
//  *  - lê com ui_ler_fstring
//  *  - valida com validar(buf)
//  *  - se tiver, aplica transformar(buf)
//  *  - emite ui_exibir_erro(msg) e repete até sucesso
//  */
// static void ui_ler_campo(const char *prompt,
//                          char *buffer,
//                          size_t tamanho,
//                          bool (*validar)(const char*),
//                          const char *msg_erro,
//                          void (*transformar)(char*))
// {
//     if (!prompt || !buffer || tamanho == 0) return;

//     while (1) {
//         printf("%s", prompt);
//         if (!ui_ler_fstring(buffer, tamanho)) {
//             ui_exibir_erro("Falha na leitura. Tente novamente.");
//             clearerr(stdin);
//             continue;
//         }

//         if (transformar) transformar(buffer);

//         if (validar(buffer)) {
//             return;
//         }
//         ui_exibir_erro(msg_erro);
//     }
// }

// ---------------------
// Validadores
// ---------------------
// static bool validar_nao_vazio(const char *s) {
//     return s && *s != '\0';
// }

// static bool validar_cnpj(const char *s) {
//     if (strlen(s) != CNPJ_DIGITOS) return false;
//     for (int i = 0; i < CNPJ_DIGITOS; i++)
//         if (!isdigit((unsigned char)s[i])) return false;
//     return true;
// }

// static bool validar_cep(const char *s) {
//     if (strlen(s) != CEP_DIGITOS) return false;
//     for (int i = 0; i < CEP_DIGITOS; i++)
//         if (!isdigit((unsigned char)s[i])) return false;
//     return true;
// }

// static bool validar_estado(const char *s) {
//     return strlen(s) == ESTADO_DIGITOS
//         && isupper((unsigned char)s[0])
//         && isupper((unsigned char)s[1]);
// }

// static bool validar_email(const char *e) {
//     if (!e || strlen(e) < 5) return false;
//     const char *at = strchr(e, '@');
//     if (!at || at == e) return false;
//     const char *dot = strchr(at + 1, '.');
//     if (!dot || dot == at + 1 || dot[1] == '\0') return false;
//     for (const char *p = e; *p; p++)
//         if (!isalnum((unsigned char)*p)
//          && strchr("._-@", *p) == NULL) return false;
//     return true;
// }

// static bool validar_data(const char *d) {
//     if (strlen(d) != DATA_TAMANHO || d[2] != '/' || d[5] != '/') return false;
//     for (int i = 0; i < DATA_TAMANHO; i++) {
//         if (i==2||i==5) continue;
//         if (!isdigit((unsigned char)d[i])) return false;
//     }
//     int dia, mes, ano;
//     if (sscanf(d, "%2d/%2d/%4d", &dia,&mes,&ano) != 3) return false;
//     struct tm tm0 = { .tm_mday=dia, .tm_mon=mes-1, .tm_year=ano-1900 };
//     time_t t = mktime(&tm0);
//     if (t == -1
//      || tm0.tm_mday != dia
//      || tm0.tm_mon  != mes-1
//      || tm0.tm_year != ano-1900
//      || difftime(t, time(NULL)) > 0)
//         return false;
//     return true;
// }

// // ---------------------
// // Transformadores
// // ---------------------
// static void transformar_maiusculo(char *s) {
//     for (; *s; s++) *s = toupper((unsigned char)*s);
// }
// static void transformar_minusculo(char *s) {
//     for (; *s; s++) *s = tolower((unsigned char)*s);
// }

// ---------------------
// Funções públicas (camada de UI)
// ---------------------
// void ui_ler_cnpj_industria(char *buf, size_t sz) {
//     ui_ler_campo("Digite o CNPJ da indústria (somente números)",
//                   buf, sz,
//                   validar_cnpj,
//                   "CNPJ inválido. Precisam ser 14 dígitos numéricos.",
//                   NULL);
// }

// void ui_ler_razao_social_industria(char *buf, size_t sz) {
//     ui_ler_campo("Digite a razão social da indústria",
//                   buf, sz,
//                   validar_nao_vazio,
//                   "A razão social não pode ficar em branco.",
//                   transformar_maiusculo);
// }

// void ui_ler_nome_fantasia_industria(char *buf, size_t sz) {
//     ui_ler_campo("Digite o nome fantasia da indústria",
//                   buf, sz,
//                   validar_nao_vazio,
//                   "O nome fantasia não pode ficar em branco.",
//                   transformar_maiusculo);
// }

// static bool validar_telefone(const char *s) {
//     return strlen(s) >= 8;
// }

// void ui_ler_telefone_industria(char *buf, size_t sz) {
//     ui_ler_campo(
//         "Digite o telefone da indústria",
//         buf, sz,
//         validar_telefone,
//         "Telefone deve ter ao menos 8 caracteres.",
//         NULL
//     );
// }

// void ui_ler_logradouro_industria(char *buf, size_t sz) {
//     ui_ler_campo("Digite o logradouro (rua/avenida) da indústria",
//                   buf, sz,
//                   validar_nao_vazio,
//                   "O logradouro não pode ficar em branco.",
//                   transformar_maiusculo);
// }

// void ui_ler_numero_industria(char *buf, size_t sz) {
//     ui_ler_campo("Digite o número do endereço da indústria",
//                   buf, sz,
//                   validar_nao_vazio,
//                   "O número não pode ficar em branco.",
//                   NULL);
// }

// void ui_ler_bairro_industria(char *buf, size_t sz) {
//     ui_ler_campo("Digite o bairro da indústria",
//                   buf, sz,
//                   validar_nao_vazio,
//                   "O bairro não pode ficar em branco.",
//                   transformar_maiusculo);
// }

// void ui_ler_cidade_industria(char *buf, size_t sz) {
//     ui_ler_campo("Digite a cidade da indústria",
//                   buf, sz,
//                   validar_nao_vazio,
//                   "A cidade não pode ficar em branco.",
//                   transformar_maiusculo);
// }

// void ui_ler_estado_industria(char *buf, size_t sz) {
//     ui_ler_campo("Digite a UF do estado (ex: SP, RJ)",
//                   buf, sz,
//                   validar_estado,
//                   "UF inválida. Use 2 letras maiúsculas.",
//                   transformar_maiusculo);
// }

// void ui_ler_cep_industria(char *buf, size_t sz) {
//     ui_ler_campo("Digite o CEP (somente números)",
//                   buf, sz,
//                   validar_cep,
//                   "CEP inválido. Precisam ser 8 dígitos.",
//                   NULL);
// }

// void ui_ler_data_abertura_industria(char *buf, size_t sz) {
//     ui_ler_campo("Digite a data de abertura (dd/mm/aaaa)",
//                   buf, sz,
//                   validar_data,
//                   "Data inválida ou futura. Use dd/mm/aaaa.",
//                   NULL);
// }

// void ui_ler_nome_responsavel_industria(char *buf, size_t sz) {
//     ui_ler_campo("Digite o nome do responsável",
//                   buf, sz,
//                   validar_nao_vazio,
//                   "O nome não pode ficar em branco.",
//                   transformar_maiusculo);
// }

// void ui_ler_email_responsavel_industria(char *buf, size_t sz) {
//     ui_ler_campo("Digite o email do responsável",
//                   buf, sz,
//                   validar_email,
//                   "Email inválido. Verifique o formato.",
//                   NULL);
// }


