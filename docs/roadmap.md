# Roadmap do Projeto EcoL�gica

## Fase 1: Estabiliza��o da Arquitetura (1-2 dias)
- [x] Corrigir problemas de autentica��o
- [x] Padronizar nomenclatura (snake_case)
- [ ] Finalizar a refatora��o de c�digo para arquitetura de m�quina de estados
- [ ] Remover arquivos deprecados que n�o ser�o mais utilizados
- [ ] Resolver problemas de codifica��o de caracteres especiais em arquivos de texto

## Fase 2: Implementa��o das Funcionalidades B�sicas (3-5 dias)
- [x] Autentica��o de usu�rios (RF-01)
- [ ] Gest�o de Funcion�rios - CRUD completo (RF-02)
- [ ] Gest�o de Ind�strias - CRUD completo com valida��o de CNPJ (RF-03)
- [ ] Atualiza��o Mensal de Res�duos (RF-04)

## Fase 3: Implementa��o dos Relat�rios (3-4 dias)
- [ ] Relat�rios por Ind�stria (RF-05)
  - [ ] Insumos Tratados por Per�odo
  - [ ] Total de Gastos por Per�odo
- [ ] Relat�rios Globais (RF-06)
  - [ ] Regi�es com Maior Volume de Res�duos
  - [ ] Ind�strias com Menores Volumes
  - [ ] Aporte Financeiro por Per�odo

## Fase 4: Exporta��o de Relat�rios e Finaliza��o (2-3 dias)
- [ ] Implementa��o da exporta��o em TXT, CSV e XLS (RF-07)
- [ ] Testes finais de todas as funcionalidades
- [ ] Corre��o de bugs identificados nos testes

## Fase 5: Documenta��o e Prepara��o da Entrega (2-3 dias)
- [ ] Revis�o e finaliza��o da documenta��o t�cnica
- [ ] Elabora��o do manual do usu�rio
- [ ] Prepara��o do arquivo ZIP final conforme requisitos:
  - [ ] DocPIM no formato ABNT
  - [ ] Bin�rios do programa (exe, dlls)
  - [ ] Arquivos-fonte em Linguagem C

## Prioridades Imediatas
1. **Finalizar refatora��o da m�quina de estados**: Este � um ponto cr�tico para avan�ar com as demais implementa��es.
2. **Completar o CRUD de ind�strias**: Essencial para permitir o registro de res�duos.
3. **Implementar atualiza��o de res�duos**: Necess�rio para gerar relat�rios.

## Distribui��o Sugerida de Tempo
- Fase 1: at� 29/04/2025
- Fase 2: at� 04/05/2025
- Fase 3: at� 08/05/2025
- Fase 4: at� 11/05/2025
- Fase 5: at� 15/05/2025

## Riscos e Mitiga��o
- **Problemas de integra��o**: Realize testes ap�s cada funcionalidade implementada.
- **Inconsist�ncia de dados**: Implemente valida��es rigorosas nos formul�rios de entrada.
- **Tempo insuficiente**: Priorize as funcionalidades essenciais exigidas pelo PIM antes de implementar recursos adicionais.