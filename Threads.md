# Programação Multithreading

## 1. Por que a programação multithreading é considerada multiprogramação leve?
A programação multithreading é considerada uma forma de multiprogramação leve porque permite a execução concorrente de múltiplos threads dentro do mesmo processo. Diferente da multiprogramação tradicional, que envolve a execução simultânea de múltiplos processos independentes, a multithreading compartilha recursos do processo, como memória e descritores de arquivos, tornando a troca de contexto entre threads mais rápida e eficiente do que entre processos completos.

## 2. Exemplos de programação multithreading
### a) Desempenho melhorado em relação a uma solução de thread único
- Servidores web: múltiplos threads podem processar diferentes requisições simultaneamente, reduzindo o tempo de resposta.
- Aplicações gráficas: um thread pode lidar com a interface gráfica enquanto outro executa cálculos complexos em segundo plano.

### b) Desempenho não melhorado em relação a uma solução de thread único
- Aplicações fortemente sequenciais: um código que depende de operações estritamente sequenciais não se beneficia de múltiplos threads.
- Programas limitados por I/O: se a principal limitação for a velocidade do disco ou da rede, adicionar threads pode aumentar a sobrecarga sem ganhos reais de desempenho.

## 3. Caracterização dos descritores de processos e threads
- **Descritor de processo:** contém informações sobre o estado do processo, memória alocada, descritores de arquivos, tabelas de alocação de recursos e informações de controle de execução.
- **Descritor de thread:** armazena informações sobre o registrador, contador de programa, pilha e estado do thread.

Threads são chamados de "processos leves" porque compartilham muitos recursos com o processo pai (como espaço de memória e arquivos abertos), reduzindo a sobrecarga em relação à criação e gerenciamento de processos completos.

## 4. Diferença entre threads de usuário e threads de kernel
- **Threads de usuário:** gerenciados pela biblioteca do espaço do usuário, sem intervenção do kernel. São eficientes em troca de contexto, mas podem sofrer com a falta de suporte direto do sistema operacional.
- **Threads de kernel:** gerenciados diretamente pelo kernel do sistema operacional, permitindo melhor paralelismo em sistemas multiprocessadores, mas com maior custo de gerenciamento.

## 5. Estados possíveis de um thread
1. **Criado (New)** - O thread foi criado, mas ainda não iniciou a execução.
2. **Executável (Runnable)** - O thread está pronto para ser escalonado pelo processador.
3. **Em execução (Running)** - O thread está sendo executado pelo processador.
4. **Bloqueado (Blocked)** - O thread está esperando por um recurso ou evento externo.
5. **Finalizado (Terminated)** - O thread concluiu sua execução.

## 6. Recursos usados na criação de threads e processos
- **Criação de um thread:** compartilha o espaço de memória do processo pai, necessitando apenas de alocação para a pilha e registradores.
- **Criação de um processo:** requer a alocação de uma nova tabela de memória, arquivos e recursos, além da criação de um novo espaço de execução.

## 7. Modelos multithreading
### **Modelo de Muitos-para-Um**
- **Descrição:** múltiplos threads de usuário são mapeados para um único thread de kernel.
- **Vantagens:** eficiente e rápido, sem necessidade de suporte do kernel.
- **Desvantagens:** se um thread bloquear, todos os outros threads do processo também bloqueiam.

### **Modelo de Um-para-Um**
- **Descrição:** cada thread de usuário é mapeado para um thread de kernel.
- **Vantagens:** melhora a concorrência e aproveita múltiplos núcleos.
- **Desvantagens:** pode gerar alta sobrecarga se muitos threads forem criados.

### **Modelo de Muitos-para-Muitos**
- **Descrição:** múltiplos threads de usuário são mapeados para múltiplos threads de kernel, com flexibilidade no escalonamento.
- **Vantagens:** permite alto grau de concorrência sem sobrecarregar o sistema.
- **Desvantagens:** implementação mais complexa e maior necessidade de sincronização.
