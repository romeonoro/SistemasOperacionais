## 📚 Tabela de Conteúdo

- [📘 Resumo para Prova de Sistemas Operacionais](#-resumo-para-prova-de-sistemas-operacionais)
  - [🧵 1. Programação Concorrente](#-1-programação-concorrente)
  - [👥 2. Processo vs. Thread](#-2-processo-vs-thread)
  - [⚠️ 3. Condição de Corrida (Race Condition)](#-3-condição-de-corrida-race-condition)
  - [🔁 4. Escalonamento de Processos](#-4-escalonamento-de-processos)
  - [📊 5. Políticas de Escalonamento](#-5-políticas-de-escalonamento)
  - [⏱️ 6. Métricas de Desempenho](#-6-métricas-de-desempenho)
  - [🔐 7. Problema da Seção Crítica](#-7-problema-da-seção-crítica)
  - [🔄 8. Semáforos](#-8-semáforos)
  - [🔒 9. Mutex](#-9-mutex)
  - [🧩 10. Monitores](#-10-monitores)
  - [🛠️ 11. Técnicas de Proteção da Seção Crítica](#-11-técnicas-de-proteção-da-seção-crítica)
  - [🛑 12. Deadlock](#-12-deadlock)
  - [🧯 13. Starvation](#-13-starvation)
  - [💻 14. Modo Dual e Chamadas ao Sistema](#-14-modo-dual-e-chamadas-ao-sistema)
- [💡 Algoritmos de Escalonamento de Processos](#-algoritmos-de-escalonamento-de-processos)
  - [1. FIFO ou FCFS (First In, First Out | First Come, First Served)](#1-fifo-ou-fcfs-first-in-first-out--first-come-first-served)
  - [2. SJF (Shortest Job First)](#2-sjf-shortest-job-first)
  - [3. Prioridade](#3-prioridade)
  - [Cenário: Escalonamento por Prioridade](#cenário-escalonamento-por-prioridade)
    - [Prioridade Não Preemptivo](#prioridade-não-preemptivo)
    - [Prioridade Preemptivo](#prioridade-preemptivo)
  - [Round Robin (RR)](#round-robin-rr)
  - [5. Múltiplas Filas](#5-múltiplas-filas)
  - [6. Múltiplas Filas com Realimentação](#6-múltiplas-filas-com-realimentação)


# 📘 Resumo para Prova de Sistemas Operacionais

## 🧵 1. Programação Concorrente
Execução simultânea de múltiplos fluxos de instruções.  
Threads compartilham a mesma memória do processo, tornando a troca de contexto mais rápida.  
Melhora a capacidade de resposta, economiza recursos e aumenta o desempenho em sistemas com vários processadores.

## 👥 2. Processo vs. Thread
Processo: unidade de execução com memória isolada.  
Thread: "processo leve", compartilha memória com outras threads do mesmo processo.  
Vantagens das threads: criação mais rápida, menor custo para troca de contexto, ideal para tarefas paralelas.

**Modelos de Multithreading:**
- N:1: várias threads de usuário mapeadas para uma única thread de kernel.
- 1:1: cada thread de usuário tem uma thread de kernel.
- M:N: várias threads de usuário para várias de kernel, escalonamento em dois níveis.

## ⚠️ 3. Condição de Corrida (Race Condition)
Ocorre quando dois ou mais processos acessam dados ao mesmo tempo e o resultado depende da ordem de execução.  
**Solução:** técnicas de sincronização como semáforos, mutexes e monitores.

## 🔁 4. Escalonamento de Processos
**Preemptivo vs. Não-Preemptivo**  
- Preemptivo: a CPU pode ser retirada de um processo (ex: Round Robin).  
- Não-Preemptivo: o processo libera a CPU voluntariamente (ex: FIFO).

**Objetivos do escalonamento:**
- Maximizar uso da CPU 🧠  
- Minimizar tempos de espera e resposta ⏳  
- Garantir justiça entre os processos ⚖️

**Escalonadores e Dispatcher:**
- Escalonador de curto prazo: escolhe qual processo será executado.  
- Dispatcher: faz a troca de contexto e passa o controle para a CPU.

## 📊 5. Políticas de Escalonamento
- **FIFO (FCFS):** simples, mas pode causar longas esperas.  
- **SJF:** ótimo para tempos curtos, mas difícil prever surto de CPU. Pode ser preemptivo (SRTF).  
- **Prioridade:** escolhe com base em número; pode causar starvation.  
- **Round Robin (RR):** bom para tempo compartilhado, depende do quantum.  
- **Múltiplas Filas:** separa por tipo (interativo, batch).  
- **Múltiplas Filas com Realimentação:** processos migram entre filas, evita starvation.  

**Técnicas auxiliares:**  
- Envelhecimento (Aging): aumenta prioridade de processos que esperam muito.

## ⏱️ 6. Métricas de Desempenho
- Tempo de Espera  
- Tempo de Retorno  
- Tempo de Resposta

## 🔐 7. Problema da Seção Crítica
**Requisitos:**
- Exclusão mútua ✅  
- Progresso ✅  
- Espera limitada ✅  
- Independência de velocidade ✅

## 🔄 8. Semáforos
Controlam o acesso a recursos compartilhados.  
**Operações:** P() (wait) e V() (signal).  
**Problemas:** deadlock ou inanição se mal utilizados.

## 🔒 9. Mutex
Lock binário que garante exclusão mútua.  
Ideal para evitar condições de corrida.

## 🧩 10. Monitores
Estrutura de sincronização de alto nível.  
Utiliza `wait()` e `signal()` para controlar acesso.  
Muito usado em linguagens OO como Java.

## 🛠️ 11. Técnicas de Proteção da Seção Crítica
- Semáforos ✅  
- Mutexes ✅  
- Desabilitar interrupções ✅ (uso em sistemas embarcados)  
- Monitores ✅

## 🛑 12. Deadlock
**Condições de Coffman:**
- Exclusão mútua  
- Retenção e espera  
- Não-preempção  
- Espera circular

**Estratégias:**
- Prevenção  
- Evitação (ex: algoritmo do banqueiro)  
- Detecção e Recuperação

## 🧯 13. Starvation
Quando um processo nunca é executado por estar sempre sendo preterido.  
**Solução:** envelhecimento (aging).

## 💻 14. Modo Dual e Chamadas ao Sistema
**Modo usuário vs. Modo kernel:** garante segurança e proteção dos recursos.  
**System Call:** forma do programa acessar serviços do SO.  
Ex: `fork`, `exec`, `wait`, `open`, `read`, `write`, `exit`.

---

# 💡 Algoritmos de Escalonamento de Processos

## 1. FIFO ou FCFS (First In, First Out | First Come, First Served)
- **Tipo:** Não preemptivo  
- **Descrição:** Escalona o primeiro processo que chega na fila de prontos.  
- **Funcionamento:** O processo que chegar primeiro será executado até o fim, sem interrupções.

## 2. SJF (Shortest Job First)
- **Tipo:** Ótimo (ideal em teoria)  
- **Descrição:** Escalona o processo com o menor ciclo de CPU.  

**Modos:**
- Não preemptivo
- Preemptivo

## 3. Prioridade
- **Descrição:** Escalona o processo com maior prioridade  
- **Tipos:** Preemptivo ou Não Preemptivo  

## Cenário: Escalonamento por Prioridade

### Prioridade Não Preemptivo
| Processo | Tempo de Chegada | Tempo de Execução | Tempo de Retorno |
|----------|------------------|-------------------|------------------|
| P1       | 0                | 3                 | 9                |
| P2       | 1                | 4                 | 7                |
| P3       | 2                | 2                 | 5                |
| P4       | 3                | 1                 | 6                |

### Prioridade Preemptivo
| Processo | Tempo de Chegada | Tempo de Execução | Tempo de Retorno |
|----------|------------------|-------------------|------------------|
| P1       | 0                | 1                 | 10               |
| P2       | 1                | 4                 | 4                |
| P3       | 2                | 2                 | 5                |
| P4       | 3                | 1                 | 5                |

## Round Robin (RR)
- **Tipo:** Preemptivo  
- **Quantum (q):** Fatia de tempo

**Cenário (q=2):**
| Processo | Tempo    |
|----------|----------|
| P1       | 0 → 2 → 7|
| P2       | 2 → 4 → 8|
| P3       | 4 → 6    |
| P4       | 6 → 7    |

## 5. Múltiplas Filas
- Fila de SO, Interativos (RR), 2º plano (FIFO)

## 6. Múltiplas Filas com Realimentação
- Fila 1: RR Q=4  
- Fila 2: RR Q=8  
- Fila 3: RR Q=12
