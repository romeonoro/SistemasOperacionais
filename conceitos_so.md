# Conceitos Fundamentais de Sistemas Operacionais

## 🧩 Seção Crítica
A **seção crítica** é a parte de um programa onde um processo acessa recursos compartilhados (como variáveis, arquivos ou dispositivos).  
Somente **um processo por vez** pode executar sua seção crítica — isso evita **inconsistências nos dados**.

---

## ⚡ Race Condition
Uma **condição de corrida (race condition)** ocorre quando **dois ou mais processos** acessam e modificam **simultaneamente** um mesmo recurso compartilhado, resultando em **comportamentos imprevisíveis**.  
Para evitar esse problema, utilizam-se mecanismos de **sincronização**, como **semáforos** e **monitores**.

---

## 🚦 Semáforo
Um **semáforo** é uma variável especial utilizada para **controlar o acesso** a recursos compartilhados.  
- Se o recurso estiver sendo usado, outros processos devem **aguardar**.  
- Pode ser **binário** (0 ou 1, semelhante a um bloqueio) ou **contável** (permite múltiplos acessos simultâneos, até um limite).  

Exemplo de operações:  
- `wait()` ou `P()`: solicita acesso ao recurso.  
- `signal()` ou `V()`: libera o recurso.

---

## 🔒 Exclusão Mútua
A **exclusão mútua** é o princípio que garante que **apenas um processo por vez** possa acessar a **seção crítica**.  
Pode ser implementada com **semáforos**, **locks** ou **monitores**.

---

## ⚙️ Cache
A **cache** é uma memória de alta velocidade usada para **armazenar dados frequentemente acessados pela CPU**.  
Ela é **mais rápida** que a memória principal (RAM) e **reduz o tempo de acesso** aos dados.

---

## 💾 DMA (Direct Memory Access)
O **DMA (Acesso Direto à Memória)** permite que **dados sejam transferidos diretamente** entre a **memória principal** e os **dispositivos de entrada/saída (I/O)** **sem intervenção constante da CPU**.  
Assim, a CPU pode **executar outras tarefas simultaneamente**, aumentando o desempenho geral do sistema.

---

## 🔁 Estados de um Processo
Um processo pode estar em um dos seguintes **estados**:

| Estado | Descrição |
|--------|------------|
| **Novo** | O processo está sendo criado. |
| **Pronto** | Aguardando para ser executado pela CPU. |
| **Em execução** | Está sendo executado pela CPU. |
| **Em espera (bloqueado)** | Aguardando algum evento (como I/O). |
| **Finalizado** | Terminou sua execução. |

---

## 🌱 Função `fork()`
A chamada de sistema **`fork()`** é usada em sistemas Unix/Linux para **criar um novo processo** (chamado de **filho**) que é **uma cópia do processo pai**.  
Cada processo criado pode, por sua vez, criar novos processos, formando uma **árvore de processos**.  
Exemplo: um processo raiz chama `fork()` e cria dois filhos; um deles cria mais um, e assim por diante → **4 processos no total**.

---

## 🧠 Multiprogramação
A **multiprogramação** permite que **vários processos compartilhem a CPU**, mantendo **vários programas na memória** ao mesmo tempo.  
O sistema operacional alterna a execução entre eles para **melhorar o uso da CPU**.

---

## ⏸️ Interrupções
As **interrupções** são sinais que **pausam temporariamente** a execução de um processo para que o sistema operacional **trate eventos importantes**, como operações de **entrada/saída (I/O)**.  
Elas são fundamentais para permitir a **troca de contexto** e a execução **concorrente de processos**.

---

## ⚖️ Escalonamento Preemptivo e Não-Preemptivo
- **Preemptivo**: o sistema pode **interromper** um processo em execução e **realocar a CPU** para outro processo (ex: Round Robin).  
- **Não-Preemptivo**: o processo **mantém a CPU até liberar voluntariamente** (ex: First Come First Served - FCFS).

---

## 🧵 Thread
Uma **thread** (ou **linha de execução**) é a **menor unidade de processamento** dentro de um processo.  
Threads compartilham os **recursos do processo pai** (como memória e arquivos abertos), permitindo **execução concorrente** de múltiplas tarefas dentro de um mesmo processo.

---

## ⚠️ Deadlock
Um **deadlock** ocorre quando **dois ou mais processos** ficam **bloqueados indefinidamente**, cada um **aguardando um recurso** que está sendo **mantido pelo outro**.  
Situação típica:
- Processo A possui o recurso X e precisa do Y.  
- Processo B possui o recurso Y e precisa do X.  

Nenhum deles prossegue.  
É necessário **prevenir**, **evitar** ou **recuperar** de um deadlock com técnicas de gerenciamento de recursos.
