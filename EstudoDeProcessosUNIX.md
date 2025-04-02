# Estudo de Sistemas Operacionais

Baseado no livro *Sistemas Operacionais* de Deitel e Deitel, este estudo aborda os seguintes tópicos:

- Chaveamento de Contexto
- Interrupções (processamento de interrupções e classes de interrupções)
- Comunicação Interprocessos (Sinais, Trocas de Mensagens, Pipe, Mailboxes...)
- Estudo de Processos no UNIX

## Chaveamento de Contexto

O **chaveamento de contexto** é o processo pelo qual o sistema operacional salva o estado de um processo em execução e carrega o estado de outro processo para que este possa ser executado. Esse mecanismo permite a multitarefa, possibilitando que múltiplos processos compartilhem a CPU de forma eficiente.

Durante o chaveamento, o sistema operacional armazena informações como registradores, contador de programa e outras informações críticas do processo atual, para que ele possa ser retomado posteriormente do ponto em que foi interrompido. Embora necessário, o chaveamento de contexto introduz uma sobrecarga, pois consome ciclos de CPU sem realizar trabalho útil para o usuário.

## Interrupções

As **interrupções** são sinais enviados ao processador para indicar que um evento requer atenção imediata. Elas podem ser classificadas em:

- **Interrupções de Hardware**: Geradas por dispositivos externos, como teclados ou discos rígidos, para sinalizar eventos como a conclusão de uma operação de E/S.
- **Interrupções de Software**: Também conhecidas como exceções ou traps, são geradas por instruções específicas dentro do código do programa, como chamadas de sistema ou erros (por exemplo, divisão por zero).

O tratamento de interrupções permite que o sistema operacional responda rapidamente a eventos, interrompendo o fluxo normal de execução do programa para lidar com a situação e, em seguida, retomando a execução normal.

## Comunicação entre Processos (IPC)

A **Comunicação entre Processos** (IPC) refere-se aos mecanismos que permitem que processos separados troquem dados e informações. No UNIX, os principais métodos de IPC incluem:

- **Sinais**: Notificações assíncronas enviadas a um processo para informar sobre eventos específicos.
- **Pipes**: Canais unidirecionais que conectam a saída de um processo à entrada de outro, permitindo a comunicação por meio de um fluxo contínuo de dados.
- **Named Pipes (FIFOs)**: Semelhantes aos pipes, mas com um nome associado, permitindo comunicação entre processos que não possuem relação de parentesco.
- **Sockets**: Permitem a comunicação entre processos, seja localmente ou através de uma rede.
- **Memória Compartilhada**: Segmentos de memória acessíveis por múltiplos processos para leitura e escrita.
- **Mailboxes (Caixas de Correio)**: Mecanismos que permitem que processos enviem e recebam mensagens através de uma estrutura de dados gerenciada pelo sistema operacional.

### Exemplo de Comunicação entre Processos usando Pipes no UNIX

A seguir, apresento um exemplo em C que demonstra a comunicação entre um processo pai e um processo filho utilizando um pipe:

```c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main() {
    int fd[2];
    pid_t pid;
    char mensagem[] = "Olá do processo pai!";
    char buffer[100];

    if (pipe(fd) == -1) {
        perror("Falha ao criar o pipe");
        return 1;
    }

    pid = fork();

    if (pid < 0) {
        perror("Falha no fork");
        return 1;
    }

    if (pid > 0) { // Processo pai
        close(fd[0]); // Fecha a extremidade de leitura do pipe
        write(fd[1], mensagem, strlen(mensagem) + 1);
        close(fd[1]); // Fecha a extremidade de escrita do pipe
    } else { // Processo filho
        close(fd[1]); // Fecha a extremidade de escrita do pipe
        read(fd[0], buffer, sizeof(buffer));
        printf("Mensagem recebida pelo filho: %s\n", buffer);
        close(fd[0]); // Fecha a extremidade de leitura do pipe
    }

    return 0;
}
```

**Explicação do Código**:

1. Cria-se um pipe utilizando a função `pipe()`, que retorna dois descritores de arquivo: `fd[0]` para leitura e `fd[1]` para escrita.
2. O processo é duplicado com `fork()`. O processo pai recebe o PID do filho, enquanto o processo filho recebe 0.
3. No processo pai:
   - Fecha-se a extremidade de leitura do pipe (`fd[0]`).
   - Escreve-se uma mensagem na extremidade de escrita do pipe (`fd[1]`).
   - Fecha-se a extremidade de escrita após o uso.
4. No processo filho:
   - Fecha-se a extremidade de escrita do pipe (`fd[1]`).
   - Lê-se a mensagem da extremidade de leitura do pipe (`fd[0]`) e exibe-se no console.
   - Fecha-se a extremidade de leitura após o uso.

Este exemplo ilustra a comunicação unidirecional entre processos usando pipes no UNIX.

## Processos no UNIX

No UNIX, um **processo** é uma instância em execução de um programa. Cada processo possui um identificador único chamado PID (Process ID). A criação de novos processos é realizada através da chamada de sistema `fork()`, que duplica o processo chamador, criando um processo filho. Após a criação, o processo filho pode carregar um novo programa na memória utilizando `exec()`, substituindo seu código original por um novo.

O gerenciamento de processos no UNIX inclui operações como:

- **Criação de Processos**: Feita com `fork()`.
- **Execução de Programas**: Utilizando `exec()`.
- **Espera pelo término de um processo filho**: Com `wait()`.
- **Encerramento de Processos**: Feito com `exit()` ou envio de sinais.

