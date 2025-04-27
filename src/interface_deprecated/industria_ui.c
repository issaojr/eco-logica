
#include "industria_ui.h"

void iniciar_interface_industria(void) {
    char nome_responsavel[150];           
    char email_responsavel[100];        
    char cnpj[20];           
    char razao_social[150];    
    char nome_fantasia[150];   
    char telefone[20];       
    char logradouro[200];       
    char numero[10];         
    char bairro[100];        
    char cidade[100];      
    char estado[3];           // Estado (sigla de 2 letras)
    char cep[10];          
    char email[100];          
    char data_abertura[11];    // Data de abertura (ex.: dd/mm/yyyy)

    mostrar_usuario_autenticado(); // Exibe o usuário logado, se houver

    mostrar_titulo(info_msg(TITULO_CADASTRO_INDUSTRIA)); // Exibe o título da tela de cadastro
    
    // Coleta o nome do funcionario responsavel da indústria
    ler_nome(prompt_msg(PROMPT_NOME_RESPONSAVEL), nome_responsavel, 
    sizeof(nome_responsavel));

    // Coleta o e-mail do responsável
    ler_email(prompt_msg(PROMPT_EMAIL_RESPONSAVEL), email_responsavel,
    sizeof(email_responsavel));
    
    // Coleta o CNPJ
    ler_cnpj(prompt_msg(PROMPT_CNPJ), cnpj, sizeof(cnpj));
    
    // Coleta a Razão Social
    ler_razao_social(prompt_msg(PROMPT_RAZAO_SOCIAL), razao_social, sizeof(razao_social));
    
    // Coleta o Nome Fantasia
    ler_nome_fantasia(prompt_msg(PROMPT_NOME_FANTASIA), nome_fantasia, sizeof(nome_fantasia));
    
    // Coleta o Telefone
    ler_telefone(prompt_msg(PROMPT_TELEFONE), telefone, sizeof(telefone));

    // Coleta o Endereço
    ler_logradouro(prompt_msg(PROMPT_ENDERECO), logradouro, sizeof(logradouro));

    // Coleta o Número
    ler_numero(prompt_msg(PROMPT_NUMERO), numero, sizeof(numero));

    // Coleta o Bairro
    ler_bairro(prompt_msg(PROMPT_BAIRRO), bairro, sizeof(bairro));

    // Coleta a Cidade
    ler_cidade(prompt_msg(PROMPT_CIDADE), cidade, sizeof(cidade));

    // Coleta o Estado
    ler_estado(prompt_msg(PROMPT_ESTADO), estado, sizeof(estado));
    
    // Coleta o E-mail
    ler_email(prompt_msg(PROMPT_EMAIL_INDUSTRIA), email, sizeof(email));
    
    // Coleta a Data de Abertura
    ler_data_abertura(prompt_msg(PROMPT_DATA_ABERTURA), data_abertura, sizeof(data_abertura));
      
    // Processa o cadastro por meio da camada de negócio
    codigo_erro resultado = processarCadastroIndustria(
        nome_responsavel, email_responsavel, cnpj, razao_social, nome_fantasia,
        telefone, logradouro, numero, bairro, cidade, estado, cep, email,
        data_abertura
    );
    if (resultado == ERR_OK) {
        mostrar_dlg_info(info_msg(INFO_CADASTRO_INDUSTRIA_SUCESSO)); // Exibe mensagem de sucesso
    } else {
        mostrar_dlg_erro(erro_msg(resultado)); // Exibe mensagem de erro 
    } 
}
