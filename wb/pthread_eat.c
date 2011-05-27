#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

#define N 5
#define L(x) (x)
#define R(x) (((x) + 1) % N)

pthread_mutex_t chopstick[N];

void *philosophy(void *arg);
void pickup(int me);
void drop(int me);

int main(int argc, const char *argv[])
{
    pthread_t tid[N];
    int i, p[N];

    srand(time(NULL));

    for (i = 0; i < N; i++) 
    {
        pthread_mutex_init(&chopstick[i], NULL);
    }

    for (i = 0; i < N; i++) 
    {
        p[i] = i;
    }

    for (i = 0; i < N-1; i++) 
    {
        pthread_create(&tid[i], NULL, philosophy, (void *)p[i]);
    }
    philosophy((void *)(N-1));
    
    for (i = 0; i < N-1; i++) 
    {
        pthread_join(tid[i], NULL);
    }
    for (i = 0; i < N - 1; i++) 
    {
        pthread_mutex_destroy(&chopstick[i]);
    }
    return 0;
}

void pickup(int me)
{
#if 0
    pthread_mutex_lock(&chopstick[L(me)]);
    pthread_mutex_lock(&chopstick[R(me)]);
#endif

#if 1
    if (me % N == 0) 
    {
        pthread_mutex_lock(&chopstick[R(me)]);
        pthread_mutex_lock(&chopstick[L(me)]);
    }
    else 
    {
        pthread_mutex_lock(&chopstick[L(me)]);
        pthread_mutex_lock(&chopstick[R(me)]);
    }
#endif
}

void drop(int me)
{
    pthread_mutex_unlock(&chopstick[L(me)]);
    pthread_mutex_unlock(&chopstick[R(me)]);
}

void *philosophy(void *arg)
{
    int me = (int)arg;

    while (1) 
    {
        printf("%d is thinking....\n", me);
        usleep(rand() % 10);
        pickup(me);
        printf("%d is eating....\n", me);
        usleep(rand() % 10);
        drop(me);
    }
}
