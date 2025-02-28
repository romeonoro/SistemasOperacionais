<h1>🔍 Estudo Dirigido</h1>
<h2>Estruturas do Computador ou Estruturas de Sistemas de Computação e Conceitos de Hardware e Software</h2>

<h3>1. Caracterize um sistema de computação moderno</h3>

> Composto por hardware, software e interface.

<h3>2. Quais a etapas de inicialização do computador?</h3>

> Ao inicializar, um programa inicial é chamado (bootstrap), que é armazenado na memória secundária. Ele inicializa todos os aspectos do sistema.

<h3>3. O que é interrupção? Como os Sistemas Operacionais tratam as interrupções?</h3>

> Interrupção consiste em um erro ou uma requisição específica de um programa do usuário para que um serviço do SO seja realizado. Para trata-la, a CPU para o que esta fazendo e imediatamente transfere a execução para uma locação fixa de memória.

<h3>4. Defina I/O síncrona e I/O assíncrona. Qual permite melhor uso da CPU</h3>

> E/S síncrona = é iniciada; ao término, o controle é retornado ao processo do usuário.
> E/S assíncrona = retorna ao usuário sem esperar o término da E/S, ou seja, pode continuar enquanto ocorrem outras operações do sistema, permitindo um melhor uso da CPU.

<h3>5. Qual a finalidade da DMA – Direct Memory Access? </h3>

> Permite que outros componentes acessem a memória RAM diretamente, aumentando o desempenho na transferência de uma grande quantidade de dados.

<h3>6. Como funciona a RAM? Qual o ciclo básico de execução de uma instrução? </h3>

> Memória RAM é a única (grande) área de armazenamento que o processador pode acessar diretamente, fazendo com que o computador possa realizar diversas tarefas ao mesmo tempo.
> 1. Busca de 1 instrução (LOAD)
> 2. Decodificar a instrução
> 3. Buscar memória os operandos (LOAD)
> 4. Guardar a instrução
> 5. Armazenar os resultados na RAM (STORE)
> 6. Atualizar o endereço da próxima instrução

<h3>7. Caracterize a estrutura de armazenamento de um sistema de computação.</h3>

> Compiladores/Registradores -> Cache -> Memória RAM -> Memória Secundária

<h3>8. Em que consiste o uso de cache?</h3>

> Armazena dados frequentemente/recentemente acessados, para reduzir o tempo de acesso à memória principal.

<h3>9. Caracterize os diferentes tipos de proteção de hardware suportados em um sistema de computação.</h3>

> Processador
> 1. Temporizador

> Memória Principal
> - Conjuntos de endereços que cada processo pode acessar
>  1. Registrador BASE_ LIMITE_
>  2. Gerencia -> paginação -> segmentação

> Dispositivos de E/S

> Modo DUAL de operação (do processador)
> 1. SUPERVISOR = KERNEL: executar todo o conjunto de intruções *privilegiadas*
> 2. USUÁRIOS: apenas um conjunto de instruções pode ser executado
