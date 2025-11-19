# Eficiência Algorítmica - Estruturas de Dados em C
### Data Structures and Algorithms

## Integrantes
Gustavo Cordeiro Braga - RM: 562247

Murilo Justino Arcanjo - RM: 565470

Rafael Quattrer Dalla Costa - RM: 562052

---

## 1. Visão Geral do Projeto

Este projeto tem como objetivo praticar e analisar estruturas de dados em C (listas, pilhas e filas) utilizando **IA como apoio crítico**. O foco não é deixar a IA escrever o código sozinho, mas **avaliar, testar e refatorar** as soluções sugeridas.

Para cada estrutura, apresentamos:

- Versão sugerida pela IA;
- Versão final do grupo com melhorias, validações e mensagens de operação;
- Arquivo `main.c` para testes funcionais;
- Comentários explicando pontos-chave de alocação, ponteiros e manipulação de memória.

Todos os códigos foram **testados no VSCode**, garantindo compilação correta e execução adequada para casos simples e de borda.

O **relatório crítico** do projeto descreve detalhadamente:

- A análise da solução da IA;
- Alterações realizadas pelo grupo;
- Comparações de complexidade e boas práticas;
- Reflexões sobre a aplicabilidade prática e uso crítico da IA.

---

## 2. Estruturas de Dados Implementadas

### 2.1 Lista Simplesmente Encadeada
- **Pasta:** `lista_simples/`
- **Arquivos:** `lista_simples.h`, `lista_simples_ia.c`, `lista_simples_grupo.c`, `main.c`
- **Descrição:** Inserção, remoção, busca e exibição em ordem crescente.
- **Testes:** Caso com lista vazia, remoção de elementos inexistentes e inserção em diferentes posições.

### 2.2 Lista Duplamente Encadeada
- **Pasta:** `lista_dupla/`
- **Arquivos:** `lista_dupla.h`, `lista_dupla_ia.c`, `lista_dupla_grupo.c`, `main.c`
- **Descrição:** Inserção e remoção no início e final, percorrendo em ambos os sentidos.
- **Testes:** Lista vazia, remoção do primeiro e último elemento, percursos head → tail e tail → head.

### 2.3 Lista Circular Duplamente Encadeada
- **Pasta:** `lista_circular_dupla/`
- **Arquivos:** `lista_circular_dupla.h`, `lista_circular_dupla_ia.c`, `lista_circular_dupla_grupo.c`, `main.c`
- **Descrição:** Avanço de k posições, remoção mantendo circularidade.
- **Testes:** Caso de lista vazia, remoção de nó específico, avanço de mais de n posições.

### 2.4 Pilha (Stack) — Lista Encadeada
- **Pasta:** `pilha/`
- **Arquivos:** `pilha.h`, `pilha_ia.c`, `pilha_grupo.c`, `main.c`
- **Descrição:** Operações push, pop, top, isEmpty e exibição.  
- **Versão Grupo:** Mensagens de operação, validação de ponteiros, tratamento de pilha vazia.
- **Testes:** Inserção múltipla, remoção, pilha vazia.

### 2.5 Fila (Queue) — Lista Encadeada
- **Pasta:** `fila/`
- **Arquivos:** `fila.h`, `fila_ia.c`, `fila_grupo.c`, `main.c`
- **Descrição:** Operações enqueue, dequeue, front, isEmpty e exibição.
- **Versão Grupo:** Mensagens de operação, tratamento de fila vazia, validação de ponteiros.
- **Testes:** Inserção múltipla, remoção, fila vazia.

---

## 3. Compilação e Execução

Para cada estrutura, abra a pasta correspondente no terminal e use:

```bash
# Compilar versão do grupo
gcc main.c <estrutura>_grupo.c -o <nome_exec>
./<nome_exec>

# Compilar versão IA
gcc main.c <estrutura>_ia.c -o <nome_exec_ia>
./<nome_exec_ia>
```

Exemplo para pilha:

```bash
cd pilha
gcc main.c pilha_grupo.c -o pilha_grupo
./pilha_grupo
```

---

## 4. Uso da IA

- **AI Companion:** ChatGPT  
- **Função:** Gerar código base, explicar conceitos e sugerir estruturas.  
- **Análise Crítica:** Todas as soluções da IA foram testadas, avaliadas para casos de borda, clareza e eficiência.  
- **Decisão Final:** Cada código foi ajustado/refatorado pelo grupo para atender critérios acadêmicos e garantir segurança (verificação de malloc, mensagens, tratamento de ponteiros).

---

## 5. Observações

- Cada estrutura está em **pasta independente**, permitindo múltiplos `main.c` sem conflito.  
- Comentários mínimos explicam manipulação de ponteiros e alocação dinâmica.  
- O relatório crítico detalha **erros encontrados na IA**, alterações realizadas pelo grupo e reflexões sobre aplicabilidade prática.  
