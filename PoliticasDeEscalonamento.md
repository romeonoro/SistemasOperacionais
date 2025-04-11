# 💡 Algoritmos de Escalonamento de Processos

## 1. FIFO ou FCFS (First In, First Served)

- **Tipo:** Não preemptivo  
- **Descrição:** Escalona o primeiro processo que chega na fila de prontos.  
- **Funcionamento:** O processo que chegar primeiro será executado até o fim, sem interrupções.

---

## 2. SJF (Shortest Job First)

- **Tipo:** Ótimo (ideal em teoria)  
- **Descrição:** Escalona o processo com o menor ciclo de CPU.

### Modos:
- **Não preemptivo:** O processo com menor tempo de CPU entre os disponíveis é executado até o fim.
- **Preemptivo:** Interrompe a execução atual se chegar um novo processo com menor tempo de CPU.

---

## 3. Prioridade

- **Descrição:** Escalona o processo com maior prioridade (geralmente, números menores representam maior prioridade).
- **Preemptivo ou Não Preemptivo:** Depende da política adotada.
- **PCB (Process Control Block):** Armazena, entre outras informações, a prioridade do processo.

---

## Cenário: Escalonamento por Prioridade

### Tabela de Processos

| Processo | Instante de Chegada | Ciclo de CPU | Prioridade |
|----------|---------------------|--------------|------------|
| P1       | 0                   | 3            | 4          |
| P2       | 1                   | 4            | 0          |
| P3       | 2                   | 2            | 0          |
| P4       | 3                   | 1            | 1          |

### Prioridade Não Preemptivo

| Processo | Tempo de Chegada | Tempo de Execução | Tempo de Retorno (Total) |
|----------|------------------|-------------------|--------------------------|
| P1       | 0                | 3                 | 9                        |
| P2       | 1                | 4                 | 7                        |
| P3       | 2                | 2                 | 5                        |
| P4       | 3                | 1                 | 6                        |

- **T.M.E (Tempo Médio de Execução)** = (3 + 7 + 5 + 6) / 4 = 21 / 4 = 5,25
- **T.M.R (Tempo Médio de Retorno)** = (9 + 7 + 5 + 6) / 4 = 27 / 4 = 6,75

### Prioridade Preemptivo

| Processo | Tempo de Chegada | Tempo de Execução | Tempo de Retorno (Total) |
|----------|------------------|-------------------|--------------------------|
| P1       | 0                | 1                 | 10                       |
| P2       | 1                | 4                 | 4                        |
| P3       | 2                | 2                 | 5                        |
| P4       | 3                | 1                 | 5                        |

- **T.M.E (Tempo Médio de Execução)** = (10 + 4 + 5 + 5) / 4 = 24 / 4 = 6
- **T.M.R (Tempo Médio de Retorno)** = (10 + 4 + 5 + 5) / 4 = 24 / 4 = 6

---

### Não Preemptivo

| Processo | Tempo de Espera (Fila de Prontos) | Tempo de Retorno (Total) |
|----------|-----------------------------------|--------------------------|
| P1       | 0                                 | 3                        |
| P2       | 2                                 | 6                        |
| P3       | 5                                 | 7                        |
| P4       | 6                                 | 7                        |
|          | **T.M.E** = 13 / 4 = 3,25          | **T.M.R** = 23 / 4 = 5,75|

### Preemptivo

| Processo | Tempo de Espera (Fila de Prontos) | Tempo de Retorno (Total) |
|----------|-----------------------------------|--------------------------|
| P1       | 7                                 | 10                       |
| P2       | 0                                 | 4                        |
| P3       | 3                                 | 5                        |
| P4       | 4                                 | 5                        |
|          | **T.M.E** = 14 / 4 = 3,5           | **T.M.R** = 23 / 4 = 5,75|

---

## Problema: Espera Indefinida, Starvation ou Postergação Indefinida

- **Solução:** Técnica de envelhecimento (aging)

## Fluxo de Estado de um Processo

- **NOVO** → **PRONTO** → **EXECUÇÃO** → **ESPERA** → **TÉRMINO**

---

## 4. Round-Robin (RR), Revezamento Circular ou Fatia de Tempo

- **Tipo:** Preemptivo
- **Quantum (q):** Fatia de tempo
- **Fila:** Organizada em ordem de chegada
- **Troca de Contexto:** Quando o quantum expira ou o processo é preemptado, ocorre a troca de contexto (ou chaveamento de contexto), que é o processo de salvar o estado de um processo em execução e restaurar o estado de outro processo para que ele possa ser executado.

### Cenário: Escalonamento ROUND-ROBIN (q = 2)

- **Sequência de execução:**  
  P1 → P2 → P3 → P4 → P1 → P2  
  0 → 2 → 4 → 6 → 7 → 8 → 10  

### Tabela de Processos

| Processo | Instante de Chegada | Ciclo de CPU | Prioridade | Tempo de Espera | Tempo de Retorno |
|----------|---------------------|--------------|------------|-----------------|------------------|
| P1       | 0                   | 3 (CONCLUI 1) | 4          | 5               | 8                |
| P2       | 1                   | 4 (CONCLUI 2) | 0          | 5               | 9                |
| P3       | 2                   | 2 (CONCLUI)   | 0          | 2               | 4                |
| P4       | 3                   | 1 (CONCLUI)   | 1          | 3               | 4                |

- **T.M.E (Tempo Médio de Execução)** = (5 + 5 + 2 + 3) / 4 = 15 / 4 = 3,75
- **T.M.R (Tempo Médio de Retorno)** = (8 + 9 + 4 + 4) / 4 = 25 / 4 = 6,25
