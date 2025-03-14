![image](https://github.com/user-attachments/assets/37baed11-bbef-4df9-892d-2963ab90db77)

# Gerenciamento de Processos e Escalonamento

Este documento descreve o funcionamento do gerenciamento de processos em sistemas operacionais, abordando o ciclo de vida dos processos, os tipos de escalonadores e suas funções.

## Ciclo de Vida de um Processo

1. **Criação do Executável**: O arquivo executável está apenas na memória como um arquivo pronto para ser executado.

2. **Criação do Processo**: Ao executar o arquivo, um processo é criado através da chamada `fork()`, tornando-o um processo pronto.

3. **Escolha pelo Escalonador**:
   - Se houver apenas um processo, ele será escolhido automaticamente.
   - Se houver múltiplos processos, o escalonador escolherá um com base em critérios específicos.
   - Existem diferentes tipos de escalonadores: escalonador de disco, rede, CPU, etc.

4. **Execução**:
   - O processo entra em execução.
   - Se houver uma interrupção, ele retorna ao estado **pronto**, aguardando uma nova oportunidade de execução.

5. **Finalização do Processo**:
   - Se não houver interrupção, o processo conclui sua execução e libera os recursos.
   - O contexto do processo é armazenado para possível retomada futura.

6. **Operações de I/O e Eventos**:
   - Se o processo precisar de entrada/saída (I/O) ou aguardar um evento (exemplo: `printf` aguardando entrada do usuário), ele será movido para o estado **em espera**.
   - Após a conclusão da operação, ele retorna ao estado **pronto** para ser escalonado novamente.

## Filas e Escalonadores (Scheduler)

Os processos podem estar em diferentes filas, dependendo do seu estado:

- **NOVO**: Controlado pelo **escalonador de longo prazo**, responsável por decidir quando um novo processo pode entrar no sistema.
- **PRONTO**: Controlado pelo **escalonador de curto prazo**, que seleciona processos para execução rapidamente.
- **EM ESPERA**: Controlado pelo **escalonador de longo prazo**, pois processos nesta fila podem permanecer nela por minutos, dependendo da operação de I/O.

### **Escalonador de Médio Prazo: Swapping**
- Gerencia processos que precisam ser temporariamente removidos da memória RAM para liberar espaço, armazenando-os no disco e trazendo-os de volta quando necessário.

---

# **QUESTÕES**

### 1. É correto afirmar que, devido à multiprogramação, há uma menor utilização do processador? Justifique.

**Resposta:**

Não, a multiprogramação busca maximizar a utilização do processador. O escalonador gerencia a alternância entre processos para evitar que o processador fique ocioso. A organização por filas permite uma melhor distribuição dos recursos, otimizando o uso do processador.

### 2. A partir do conceito de processo, justifique o escalonamento de processos.

**Resposta:**

O escalonamento de processos é essencial para definir qual processo será executado em determinado momento. O escalonador do processador prioriza e organiza os processos, garantindo um uso eficiente da CPU e melhorando a resposta do sistema.

### 3. Caracterize o que é um processo em Sistemas Operacionais. Inclua nesta caracterização o bloco descritor de processo.

**Resposta:**

Um **processo** é um programa em execução no sistema operacional. Antes de ser executado, o programa é apenas um arquivo no disco. Ao ser carregado na memória, torna-se um processo e pode ser gerenciado pelo sistema.

O **PCB (Process Control Block - Bloco de Controle de Processo)** é uma estrutura de dados que armazena informações essenciais sobre um processo, incluindo:
- Identificação do processo (PID);
- Estado do processo (pronto, em execução, esperando, etc.);
- Registradores da CPU e contexto de execução;
- Informações sobre memória e arquivos abertos.

O PCB é essencial para a retomada de um processo após uma interrupção ou troca de contexto, garantindo a continuidade da execução.


