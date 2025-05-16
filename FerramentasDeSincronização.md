# Mecanismos de Sincronização (Protocolos de Acesso - Entrada e Saída da Seção Crítica, Spin-lock)

## Conceitos

### 1. **Processos Cooperativos**
Processos cooperativos são aqueles que interagem entre si, compartilhando recursos ou dados. Eles podem ser executados de maneira sequencial ou intercalada, mas precisam coordenar suas ações para evitar conflitos e garantir que as operações sejam realizadas de forma segura e eficiente.

### 2. **Seção Crítica**
A seção crítica é a parte de um programa onde o acesso a um recurso compartilhado (como variáveis ou dispositivos) deve ser controlado para evitar que múltiplos processos acessem esse recurso ao mesmo tempo. O objetivo é garantir que apenas um processo tenha acesso ao recurso compartilhado por vez, evitando inconsistências ou falhas.

### 3. **Condição de Corrida**
A condição de corrida ocorre quando dois ou mais processos tentam acessar e modificar um recurso compartilhado simultaneamente, sem a devida sincronização. Isso pode levar a comportamentos inesperados ou incorretos, como a sobrescrição de dados, falhas no sistema ou resultados errados. A sincronização é necessária para evitar esse tipo de problema.

### 4. **Proteção da Seção Crítica**
Para proteger a seção crítica, é necessário implementar mecanismos de sincronização. As condições para proteger a seção crítica incluem:
- **Exclusão mútua**: Garante que apenas um processo possa acessar a seção crítica de cada vez.
- **Progresso**: Se nenhum processo está na seção crítica, deve ser possível selecionar um processo para entrar nela.
- **Espera limitada**: Evita que um processo fique esperando indefinidamente para entrar na seção crítica.

## Semáforos: Tipo de Dado Abstrato

Um **semáforo** é uma variável ou estrutura usada para controlar o acesso a um recurso compartilhado, garantindo a sincronização entre processos. Ele possui duas componentes principais:
- **Valor inteiro**: Usado para controlar o estado do semáforo.
- **Fila de processos**: Armazena os processos que estão esperando para acessar o recurso.

### Operações Atômicas do Semáforo

Existem duas operações principais associadas ao semáforo, que devem ser atômicas (ou seja, realizadas de forma indivisível):

1. **P (Proberen - testar ou tentar)**:
   - A operação **P** decrementa o valor do semáforo. Se o valor do semáforo for negativo, o processo que chamou a operação entra em espera e é adicionado à fila de processos. 
   ```c
   valor--;
   if (valor < 0) {  
       bloquear a thread;  
       inserir na fila de S;  
   }
2. **V (Verhogen - liberar ou incrementar)**:

- A operação V incrementa o valor do semáforo. Se o valor do semáforo era negativo, ela acorda um processo da fila para continuar sua execução.
```c
valor++;
if (valor <= 0) {  
    acordar 1 processo da fila;  
}
```
### Uso de Semáforos
1. Uso de Semáforos para Proteção da Seção Crítica
O objetivo é garantir que apenas um processo tenha acesso à seção crítica de cada vez. O semáforo serve como um mecanismo de controle de acesso.

- Exemplo de código:
```c
semaforo S;
S.valor = 1;  // Estado inicial: 0, -1, -2, -1, 0, 1
Fila de S: T2, T3
```
Thread 1:
```c
S.P();
seção_critica();
S.V();
```
Thread 2:
```c
S.P();  
secao_critica();  
S.V();
```
2. Uso de Semáforos para Estabelecer a Precedência de Operações

Exemplo de código:

Thread 1:
```c
S.P();
calculoFolha();
```
Thread 2:
```c
consultaBD();
S.V();
```
Thread 3:
```c
X.P();
transmitirFolha();
```
### Ordem de Execução:
1. Consulta ao BD deve ser feita antes do cálculo da folha: a Thread 1 espera pela consulta do BD da Thread 2.
2. Transmitir a folha deve ocorrer após o cálculo da folha: a Thread 3 espera que a Thread 1 termine o cálculo da folha.



