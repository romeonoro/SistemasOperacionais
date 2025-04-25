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

---

### **1. Qual a finalidade da memória cache? Se a memória cache tivesse a mesma capacidade de armazenamento da memória principal, mesmo assim existiriam motivos para os dois tipos de memória existirem? Justifique sua resposta.**

A memória cache serve para armazenar dados mais acessados pela CPU de forma mais rápida que a memória principal.  
Mesmo que tivesse a mesma capacidade, ainda haveria vantagem, pois sua velocidade de acesso é muito maior.

---

### **2. Direct Memory Access (DMA) é um mecanismo que favorece a multiprogramação nos sistemas operacionais? Justifique.**

Sim. O DMA permite a transferência de dados entre memória e dispositivos de E/S sem intervenção da CPU, permitindo que ela execute outros processos simultaneamente, favorecendo a multiprogramação.

---

### **3. Um processo, durante seu ciclo de vida, pode assumir vários estados. Relacione estes estados e os eventos que devem acontecer para a mudança de estado, com as filas de escalonadores de um Sistema Operacional.**

Estados: Novo, Pronto, Em execução, Em espera, Finalizado. <br>
Novo -> O processo é criado. <br>
Pronto -> O processo é colocado na fila de pronto, onde será executado assim que possível. <br>
Em execução -> O processo é executado enquanto não há interrupção ou evento I/O. Encerrado na fila de execução. <br>
Em espera -> O processo é encaixado na fila de espera, onde aguarda o evento I/O acabar para ser retornado. <br>
Finalizado -> O processo é finalizado, sendo retirado de qualquer fila. <br>

---

### **4. Em um sistema operacional, um processo pode, em dado instante de tempo, assumir diferentes estados, como: em execução, pronto ou bloqueado (em espera). Considere as afirmativas abaixo sobre as possíveis transições entre esses estados que um processo pode realizar.**

I. Do estado em execução para o estado bloqueado ✅  
II. Do estado em execução para o estado pronto ✅  
III. Do estado pronto para o estado em execução ✅  
IV. Do estado pronto para o estado bloqueado ❌  
V. Do estado bloqueado para o estado em execução ✅  
VI. Do estado bloqueado para o estado pronto ✅  

**Alternativa correta:** (B) Somente as afirmativas I, II, III e VI são verdadeiras.

---

### **5. Considere o exemplo a seguir, com o uso da chamada fork(). Para responder às questões 5.a), 5.b), 5.c) e 5.d), considere o código a seguir:**

```c
int main() {
    int s = 5;
    if (fork() == 0) {
        s = 7;
        printf("Processo filho, s = %d\n", s);
    } else {
        wait(NULL);
        printf("Processo pai, s = %d\n", s);
    }
}
```

**5.a) Quantos processos existem neste exemplo?**  
➡️ 2 processos (pai e filho)

**5.b) Os processos utilizam o mesmo espaço de endereçamento? Justifique.**  
➡️ Não. Após o fork, cada processo possui seu próprio espaço de memória, com cópia dos valores.

**5.c) O que será impresso na tela pelos comandos printf?**  
```
Processo filho, s = 7
Processo pai, s = 5
```

**5.d) Nesse exemplo, foi utilizada a chamada wait. Explique como acontecerá a execução dos processos com esta chamada.**  
➡️ O processo pai executa `wait()`, aguardando o término do processo filho. Só depois disso ele continua a execução.

---

### **6. Considere o exemplo a seguir, com uso da chamada fork():**

```c
int main() {
    fork();
    fork();
    return 0;
}
```

**6.a) Quantos processos existirão quando esse código for executado?**  
➡️ 4 processos

**6.b) Qual a hierarquia dos processos?**  
➡️ Processo raiz cria dois processos, e um deles cria mais um, formando 4 ao total.

---

### **7. Em relação ao gerenciamento de processos, atribua V (verdadeiro) ou F (falso) às afirmativas a seguir.**

- (V) O Bloco de Controle de Processo (PCB) é utilizado para armazenar informações sobre processos.  
- (F) Threads apresentam maior custo de criação que processos.  
- (V) Um processo pode ser criado por uma chamada fork(), copiando o espaço de memória do processo original.

---

### **8. Explique a relação entre multiprogramação e o mecanismo de interrupções em um Sistema Operacional.**

Multiprogramação permite que vários processos compartilhem a CPU.  
As interrupções pausam a execução do processo atual para tratar eventos, como chamadas de E/S, e são essenciais para alternar entre processos.

---

### **9. Leia as afirmações a seguir:**

> **I**: Ao dividirem suas atividades em múltiplas threads que podem ser executadas paralelamente, aplicações podem se beneficiar mais efetivamente dos diversos núcleos dos processadores multicore.  
> **II**: O sistema operacional nos processadores multicore pode alocar os núcleos existentes para executar simultaneamente diversas sequências de código, sobrepondo execuções e reduzindo o tempo de resposta.

**Assinale a alternativa correta:**  
(A) As duas afirmações são verdadeiras, e a segunda justifica a primeira. ✅
