# Software Requirements Specification (SRS) - EcoL�gica Solu��es Ambientais

**Data:** 27/04/2025  
**Vers�o:** 0.1

---

## 1. Introdu��o

### 1.1 Objetivo
Este documento especifica os requisitos funcionais e n�o?funcionais do sistema EcoL�gica Solu��es Ambientais, desenvolvido em Linguagem C para gerenciar cadastros, atualiza��es de res�duos e gera��o de relat�rios.

### 1.2 Escopo
O sistema permitir� a autentica��o de funcion�rios, o cadastro e manuten��o de ind�strias, o registro mensal de res�duos tratados e a gera��o de relat�rios por ind�stria e globais com op��es de exporta��o.
O design de telas e fluxos em terminal (console) foi elaborado pelo usu�rio, conforme docs/ecologica-sistema-fluxo-iu.md.

### 1.3 Defini��es, Acr�nimos e Abrevia��es
- **CNPJ:** Cadastro Nacional de Pessoa Jur�dica
- **CSV:** Comma?Separated Values
- **LGPD:** Lei Geral de Prote��o de Dados

### 1.4 Refer�ncias
- Documento de requisitos do PIM IV (docs/ecologica-sistema-fluxo-iu.md)
- Manual ABNT (docs/manual.md)

### 1.5 Vis�o Geral do Documento
Este SRS est� organizado em oito se��es principais: Vis�o Geral do Sistema, Requisitos Funcionais, Requisitos N�o?Funcionais, Modelos de Dados, Fluxos de Navega��o, Crit�rios de Valida��o e Testes e Anexos.

## 2. Vis�o Geral do Sistema

### 2.1 Perspectiva do Produto
Sistema desktop CLI em C, execut�vel no Windows, com interface em terminal (fluxos em console elaborados pelo usu�rio). A implementa��o de GUI � considerada extens�o opcional e n�o faz parte da vers�o base.

### 2.2 Funcionalidades Principais
- Autentica��o de usu�rio
- CRUD de funcion�rios e ind�strias
- Registro mensal de res�duos
- Gera��o de relat�rios (ind�stria e globais)
- Exporta��o em TXT, CSV e XLS

### 2.3 Funcion�rios
- **Funcion�rio:** acessa o sistema ap�s autentica��o e realiza todas as opera��es conforme fluxos dispon�veis

### 2.4 Restri��es
- Funcionamento apenas em ambiente Windows
- Persist�ncia exclusivamente em arquivos CSV
- Interface gr�fica (GUI) n�o est� contemplada na vers�o base; apenas CLI em terminal.

### 2.5 Premissas e Depend�ncias
- Arquivos de dados existentes (funcionarios.csv, industrias.csv, residuos.csv)
- Biblioteca de criptografia simples dispon�vel

## 3. Requisitos Funcionais

| ID    | Descri��o                                          |
|-------|----------------------------------------------------|
| RF-01 | Autentica��o (login/logout com matr�cula e senha)  |
| RF-02 | Gest�o de Funcion�rios (CRUD)                      |
| RF-03 | Gest�o de Ind�strias (CRUD com valida��o de CNPJ) |
| RF-04 | Atualiza��o Mensal de Res�duos                     |
| RF-05 | Relat�rios por Ind�stria (insumos e gastos)        |
| RF-06 | Relat�rios Globais (regi�es, menores volumes, aporte) |
| RF-07 | Exporta��o de relat�rios em TXT, CSV e XLS         |

### 3.1 RF-01: Autentica��o
#### 3.1.1 Pr�-condi��o
- Arquivo funcionarios.csv existe e cont�m pelo menos um registro v�lido (funcion�rio cadastrado).
#### 3.1.2 Fluxo Principal
1. Usu�rio inicia o programa e v� prompt de login.
2. Usu�rio informa matr�cula e senha.
3. Sistema valida credenciais (senha comparada via hash).
4. Se v�lidas, carrega sess�o e exibe menu principal.
#### 3.1.3 Fluxos Alternativos
- 3A: Matr�cula n�o encontrada ? exibe mensagem de erro e retorna ao prompt.
- 3B: Senha incorreta ? exibe mensagem de erro e retorna ao prompt.
#### 3.1.4 P�s-condi��o
- Sess�o ativa com funcion�rio autenticado ou retorno ao prompt em caso de falha.
#### 3.1.5 Exemplo de I/O
Entrada: "matricula=1234, senha=senha123"
Sa�da: "Login realizado com sucesso!" ou "Erro! Usu�rio ou Senha Inv�lidos"

### 3.2 RF-02: Gest�o de Funcion�rios
#### 3.2.1 Pr�-condi��o
- Funcion�rio autenticado.
#### 3.2.2 Fluxo Principal
1. No menu, Administrador escolhe op��o "Cadastro de Funcion�rio".
2. Sistema solicita matr�cula, nome e senha do novo funcion�rio.
3. Usu�rio fornece dados; sistema aplica hash na senha.
4. Sistema adiciona registro ao funcionarios.csv.
5. Sistema confirma cadastro bem-sucedido.
#### 3.2.3 Fluxos Alternativos
- 2A: Matr�cula j� existente ? exibe erro e solicita nova matr�cula.
- 3A: Dados inv�lidos (campo vazio) ? exibe mensagem e repete entrada.
#### 3.2.4 P�s-condi��o
- Novo registro de funcion�rio persistido ou opera��o abortada.
#### 3.2.5 Exemplo de I/O
Entrada: matr�cula=2001, nome="Ana Silva", senha="abc123"
Sa�da: "Cadastro realizado com sucesso!"

### 3.3 RF-03: Gest�o de Ind�strias
#### 3.3.1 Pr�-condi��o
- Funcion�rio autenticado.
#### 3.3.2 Fluxo Principal
1. No menu, Administrador escolhe op��o "Cadastro de Ind�stria".
2. Sistema solicita campos: CNPJ, raz�o social, nome fantasia, telefone, endere�o, e-mail, data de abertura.
3. Usu�rio preenche; sistema valida formato de CNPJ e data.
4. Se v�lidos, adiciona registro ao industrias.csv.
5. Sistema confirma cadastro bem-sucedido.
#### 3.3.3 Fluxos Alternativos
- 2A: Formato de CNPJ inv�lido ? exibe erro e solicita reentrada.
- 3A: Data de abertura fora do formato dd/mm/aaaa ? exibe mensagem e repete entrada.
#### 3.3.4 P�s-condi��o
- Novo registro de ind�stria persistido ou opera��o abortada.
#### 3.3.5 Exemplo de I/O
Entrada: CNPJ="12.345.678/0001-90", raz�oSocial="X Ind�stria Ltda", ...
Sa�da: "Cadastro realizado com sucesso!"

### 3.4 RF-04: Atualiza��o Mensal de Res�duos
#### 3.4.1 Pr�-condi��o
- Funcion�rio autenticado.
#### 3.4.2 Fluxo Principal
1. No menu principal, usu�rio escolhe "Atualiza��o Mensal de Res�duos".
2. Sistema solicita CNPJ da ind�stria, ano e m�s.
3. Usu�rio informa valores; sistema verifica exist�ncia da ind�stria.
4. Sistema solicita quantidade de res�duos tratados e custo estimado.
5. Usu�rio fornece dados; sistema grava ou atualiza registro em residuos.csv.
6. Sistema confirma registro bem-sucedido.
#### 3.4.3 Fluxos Alternativos
- 2A: Ind�stria n�o cadastrada ? exibe erro e retorna ao menu.
- 3A: Formato de data inv�lido (m�s fora de 1�12 ou ano fora de faixa) ? exibe mensagem e repete entrada.
- 4A: Quantidade ou custo inv�lidos (n�o num�ricos ou negativos) ? exibe erro e repete entrada.
#### 3.4.4 P�s-condi��o
- Registro atualizado ou inserido no arquivo residues.csv, ou opera��o abortada.
#### 3.4.5 Exemplo de I/O
Entrada: CNPJ=12.345.678/0001-90, ano=2025, m�s=4, quantidade=1500.5, custo=7500.00
Sa�da: "Atualiza��o registrada com sucesso!"

### 3.5 RF-05: Relat�rios por Ind�stria
#### 3.5.1 Pr�-condi��o
- Funcion�rio autenticado.
- Arquivos industrias.csv e residuos.csv presentes.
#### 3.5.2 Fluxo Principal
1. Menu principal ? "Relat�rios por Ind�stria" ? solicita CNPJ.
2. Usu�rio informa CNPJ; sistema valida exist�ncia.
3. Exibe submenu: Insumos Tratados por Per�odo ou Total de Gastos por Per�odo.
4. Usu�rio escolhe op��o e per�odo (mensal, semestral, anual).
5. Sistema solicita data inicial e final.
6. Sistema calcula valores agregados (soma de res�duos ou custos) e exibe tabela.
7. Oferece op��es de exporta��o ou voltar ao menu.
#### 3.5.3 Fluxos Alternativos
- 1A,2A: CNPJ n�o encontrado ? erro e retorno ao menu anterior.
- 4A: Per�odo inv�lido ? mensagem e retorno ao submenu.
- 5A: Datas fora de formato ou ordem incorreta ? erro e nova solicita��o.
#### 3.5.4 P�s-condi��o
- Relat�rio exibido em tela ou exportado com sucesso.
#### 3.5.5 Exemplo de I/O
Entrada: CNPJ=12.345.678/0001-90, op��o=1, per�odo=Mensal, data inicial=01/2025, data final=04/2025
Sa�da: Tabela de insumos tratados por m�s entre Jan/2025 e Abr/2025

### 3.6 RF-06: Relat�rios Globais
#### 3.6.1 Pr�-condi��o
- Funcion�rio autenticado.
- Arquivos industrias.csv e residuos.csv presentes.
#### 3.6.2 Fluxo Principal
1. Menu principal ? "Relat�rios Globais".
2. Sistema exibe op��es: (1) Regi�es com Maior Volume, (2) Ind�strias com Menores Volumes, (3) Aporte Financeiro por Per�odo.
3. Usu�rio escolhe op��o e per�odo (mensal, semestral, anual).
4. Sistema solicita data inicial e final.
5. Conforme op��o, calcula e ordena resultados:
   - Regi�es: agrupa ind�strias por estado e soma volumes.
   - Menores volumes: lista ind�strias com menores totais.
   - Aporte: soma custos por ind�stria ou regi�o.
6. Exibe relat�rio em formato tabela e oferece exporta��o.
#### 3.6.3 Fluxos Alternativos
- 2A: Op��o inv�lida ? mensagem e repeti��o do menu.
- 4A: Datas inv�lidas ? erro e nova solicita��o.
#### 3.6.4 P�s-condi��o
- Relat�rio global exibido ou exportado.
#### 3.6.5 Exemplo de I/O
Entrada: op��o=1, per�odo=Semestral, data inicial=01/2025, data final=06/2025
Sa�da: Lista de estados ordenados por volume tratado, de maior para menor

### 3.7 RF-07: Exporta��o de Relat�rios
#### 3.7.1 Pr�-condi��o
- Relat�rio gerado conforme RF-05 ou RF-06 e em exibi��o na tela, funcion�rio logado.
- Permiss�es de escrita no diret�rio de exporta��o.
#### 3.7.2 Fluxo Principal
1. Ap�s exibir o relat�rio, sistema oferece op��es de exporta��o: (1) TXT, (2) CSV, (3) XLS, (0) Voltar.
2. Usu�rio escolhe formato.
3. Sistema solicita nome ou caminho de arquivo para salvar.
4. Usu�rio informa nome; sistema gera arquivo no formato escolhido com a tabela de dados.
5. Sistema confirma sucesso e exibe caminho do arquivo.
#### 3.7.3 Fluxos Alternativos
- 2A: Op��o inv�lida ? exibe mensagem e repete menu de exporta��o.
- 3A: Caminho ou nome inv�lido (caracteres proibidos) ? exibe erro e solicita novamente.
- 4A: Falha de I/O (permiss�o, espa�o insuficiente) ? exibe erro e retorna ao menu de exporta��o.
#### 3.7.4 P�s-condi��o
- Arquivo de relat�rio salvo no formato e local informados, ou opera��o abortada.
#### 3.7.5 Exemplo de I/O
Entrada: formato=CSV, arquivo="relatorio_industria_04_2025.csv"
Sa�da: "Relat�rio exportado com sucesso para relatorio_industria_04_2025.csv"

## 4. Requisitos N�o?Funcionais

- **RNF-01:** Persist�ncia em arquivos CSV
- **RNF-02:** Criptografia simples de senhas (LGPD)
- **RNF-03:** Tempo de gera��o de relat�rio ? 2s
- **RNF-04:** Interface CLI clara e consistente
- **RNF-05:** Arquitetura modular em C com headers e fontes organizados

## 5. Modelos de Dados

```c
// Funcion�rio
typedef struct {
    int matricula;
    char nome[100];
    char hashSenha[64];
} Funcionario;

// Ind�stria
typedef struct {
    char cnpj[15];
    char razaoSocial[100];
    char nomeFantasia[100];
    char telefone[20];
    char endereco[150];
    char email[100];
    char dataAbertura[11]; // dd/mm/aaaa
} Industria;

// Res�duo
typedef struct {
    char cnpj[15];
    int mes;
    int ano;
    double quantidade;
    double custo;
} Residuo;
```

## 6. Fluxos de Navega��o

- Tela de Login ? Menu Principal
- Menu Principal ? [Cadastro Funcion�rio | Cadastro Ind�stria | Atualiza��o Res�duos | Relat�rios]
- Rotas de exporta��o e retorno ao menu

## 7. Crit�rios de Valida��o e Testes

- Testes unit�rios para fun��es de CRUD e criptografia
- Testes de integra��o do fluxo completo (login ? cadastro ? relat�rio)
- Planilha de casos de teste com entradas v�lidas e inv�lidas

## 8. Anexos

- Diagramas de Caso de Uso

```plantuml
@startuml
left to right direction
actor Funcion�rio

(Autenticar) as UC1
(Cadastrar Funcion�rio) as UC2
(Cadastrar Ind�stria) as UC3
(Atualizar Res�duos) as UC4
(Gerar Relat�rio por Ind�stria) as UC5
(Gerar Relat�rio Global) as UC6
(Exportar Relat�rio) as UC7

Funcion�rio --> UC1
Funcion�rio --> UC2
Funcion�rio --> UC3
Funcion�rio --> UC4
Funcion�rio --> UC5
Funcion�rio --> UC6
Funcion�rio --> UC7
@enduml
```

- Diagramas de Atividade

```plantuml
@startuml
|Login Flow|
start
:Exibir prompt de matr�cula e senha;
if (Credenciais v�lidas?) then (sim)
  :Carregar sess�o;
  :Exibir menu principal;
  stop
else (n�o)
  :Exibir mensagem de erro;
  :Retornar ao prompt de login;
  stop
endif
@enduml
```

```plantuml
@startuml
|Cadastro de Funcion�rio|
start
:Exibir prompt de matr�cula, nome e senha;
:Funcion�rio insere dados;
if (Matr�cula �nica e campos v�lidos?) then (sim)
  :Hash da senha e persistir em funcionarios.csv;
  :Exibir confirma��o de sucesso;
  stop
else (n�o)
  :Exibir mensagem de erro;
  :Retornar ao in�cio do formul�rio;
  stop
endif
@enduml
```

```plantuml
@startuml
|Gera��o de Relat�rio|
start
:Exibir menu de relat�rios;
:Usu�rio escolhe tipo e per�odo;
:Solicitar datas de in�cio e fim;
:Calcular agregados no res�duos.csv e industrias.csv;
:Exibir tabela de resultados;
if (Usu�rio quer exportar?) then (sim)
  :Chamar fluxo de Exporta��o;
endif
stop
@enduml
```

```plantuml
@startuml
|Atualiza��o de Res�duos|
start
:Menu de Atualiza��o de Res�duos;
:Solicitar CNPJ, ano e m�s;
:Verificar exist�ncia de ind�stria;
:Solicitar quantidade e custo;
:Persistir em residuos.csv;
:Exibir confirma��o;
stop
@enduml
```

```plantuml
@startuml
|Exporta��o de Relat�rio|
start
:Exibir op��es de formato (TXT, CSV, XLS);
:Solicitar nome/caminho do arquivo;
:Gerar arquivo no formato e caminho informados;
:Exibir confirma��o de exporta��o;
stop
@enduml
```

- Gloss�rio
  - CSV: formato com valores separados por v�rgula.
  - CNPJ: Cadastro Nacional de Pessoa Jur�dica.
  - LGPD: Lei Geral de Prote��o de Dados.
  - Hash: representa��o codificada de senha.
  - CLI: interface de linha de comando.
