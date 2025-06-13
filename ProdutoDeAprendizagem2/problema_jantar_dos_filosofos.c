// INTEGRANTES DO GRUPO: VICENZO DE SOUZA, ROMEO NORO E ANTHONY GUEDES

#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define NUM 5

int estado[NUM];
sem_t mutex;
sem_t garfo[NUM];

#define PENSANDO 0
#define FAMINTO  1
#define COMENDO 2

int esquerda(int i) {
    return (i + NUM - 1) % NUM;
}

int direita(int i) {
    return (i + 1) % NUM;
}

void mostrar() {
    for (int i = 0; i < NUM; i++) {
        if (estado[i] == PENSANDO) printf(" %d:PENS ", i);
        else if (estado[i] == FAMINTO) printf(" %d:FOME ", i);
        else printf(" %d:COME ", i);
    }
    printf("\n");
}

void testar(int i) {
    if (estado[i] == FAMINTO &&
        estado[esquerda(i)] != COMENDO &&
        estado[direita(i)] != COMENDO) {
        
        estado[i] = COMENDO;
        sem_post(&garfo[i]);
    }
}

void pegar(int i) {
    sem_wait(&mutex);
    estado[i] = FAMINTO;
    mostrar();
    testar(i);
    sem_post(&mutex);
    sem_wait(&garfo[i]);
}

void largar(int i) {
    sem_wait(&mutex);
    estado[i] = PENSANDO;
    mostrar();
    testar(esquerda(i));
    testar(direita(i));
    sem_post(&mutex);
}

void* filosofo(void* arg) {
    int i = *(int*)arg;

    while (1) {
        printf("Filósofo %d pensando...\n", i);
        sleep(1 + rand() % 3);

        pegar(i);
        printf("Filósofo %d comendo...\n", i);
        sleep(2);

        largar(i);
    }
}

int main() {
    pthread_t t[NUM];
    int i, id[NUM];

    sem_init(&mutex, 0, 1);
    for (i = 0; i < NUM; i++) {
        sem_init(&garfo[i], 0, 0);
        estado[i] = PENSANDO;
        id[i] = i;
    }

    for (i = 0; i < NUM; i++) {
        pthread_create(&t[i], NULL, filosofo, &id[i]);
    }

    for (i = 0; i < NUM; i++) {
        pthread_join(t[i], NULL);
    }

    return 0;
}
