#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <time.h>
#include <semaphore.h>
#include <unistd.h>

#define NUM 5

int queue[NUM];
sem_t blank_number, product_number;

void *consumer(void *arg);
void *producer(void *arg);

int main(int argc, const char *argv[])
{
    pthread_t pid, cid;

    srand(time(NULL));

    sem_init(&blank_number, 0, NUM);
    sem_init(&product_number, 0, 0);
    pthread_create(&pid, NULL, producer, NULL);
    pthread_create(&cid, NULL, consumer, NULL);

    pthread_join(pid, NULL);
    pthread_join(cid, NULL);

    sem_destroy(&blank_number);
    sem_destroy(&product_number);
    
    return 0;
}

void *producer(void *arg)
{
    int p = 0;

    while (1) 
    {
        sem_wait(&blank_number);
        queue[p] = rand() % 1000 + 1;
        printf("Produce %d\n", queue[p]);
        sem_post(&product_number);
        p = (p + 1) % NUM;
        sleep(rand() % 5);
    }
}

void *consumer(void *arg)
{
    int c = 0;

    while (1) 
    {
        sem_wait(&product_number);
        printf("Consume %d\n", queue[c]);
        queue[c] = 0;
        sem_post(&blank_number);
        c = (c + 1) % NUM;
        sleep(rand() % 5);
    }
}
