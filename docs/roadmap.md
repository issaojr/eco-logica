# Roadmap do Projeto EcoLógica

## Fase 1: Estabilização da Arquitetura (1-2 dias)
- [x] Corrigir problemas de autenticação
- [x] Padronizar nomenclatura (snake_case)
- [x] Finalizar a refatoração de código para arquitetura de máquina de estados
- [ ] Remover arquivos deprecados que não serão mais utilizados
- [ ] Resolver problemas de codificação de caracteres especiais em arquivos de texto

## Fase 2: Implementação das Funcionalidades Básicas (3-5 dias)
- [x] Autenticação de usuários (RF-01)
- [ ] Gestão de Funcionários - CRUD completo (RF-02)
- [ ] Gestão de Indústrias - CRUD completo com validação de CNPJ (RF-03)
- [ ] Atualização Mensal de Resíduos (RF-04)

## Fase 3: Implementação dos Relatórios (3-4 dias)
- [ ] Relatórios por Indústria (RF-05)
  - [ ] Insumos Tratados por Período
  - [ ] Total de Gastos por Período
- [ ] Relatórios Globais (RF-06)
  - [ ] Regiões com Maior Volume de Resíduos
  - [ ] Indústrias com Menores Volumes
  - [ ] Aporte Financeiro por Período

## Fase 4: Exportação de Relatórios e Finalização (2-3 dias)
- [ ] Implementação da exportação em TXT, CSV e XLS (RF-07)
- [ ] Testes finais de todas as funcionalidades
- [ ] Correção de bugs identificados nos testes

## Fase 5: Documentação e Preparação da Entrega (2-3 dias)
- [ ] Revisão e finalização da documentação técnica
- [ ] Elaboração do manual do usuário
- [ ] Preparação do arquivo ZIP final conforme requisitos:
  - [ ] DocPIM no formato ABNT
  - [ ] Binários do programa (exe, dlls)
  - [ ] Arquivos-fonte em Linguagem C

## Prioridades Imediatas
1. **Finalizar refatoração da máquina de estados**: Este é um ponto crítico para avançar com as demais implementações.
2. **Completar o CRUD de indústrias**: Essencial para permitir o registro de resíduos.
3. **Implementar atualização de resíduos**: Necessário para gerar relatórios.

## Distribuição Sugerida de Tempo
- Fase 1: até 29/04/2025
- Fase 2: até 04/05/2025
- Fase 3: até 08/05/2025
- Fase 4: até 11/05/2025
- Fase 5: até 15/05/2025

## Riscos e Mitigação
- **Problemas de integração**: Realize testes após cada funcionalidade implementada.
- **Inconsistência de dados**: Implemente validações rigorosas nos formulários de entrada.
- **Tempo insuficiente**: Priorize as funcionalidades essenciais exigidas pelo PIM antes de implementar recursos adicionais.