#include <stdio.h>
#include <pthread.h>

#define NLOOP 5000

int counter;
pthread_mutex_t conter_mutex = PTHREAD_MUTEX_INITIALIZER;

void *doit(void *vptr);

int main(int argc, const char *argv[])
{
    pthread_t tidA, tidB;

    pthread_create(&tidA, NULL, &doit, NULL);
    pthread_create(&tidB, NULL, &doit, NULL);

    pthread_join(tidA, NULL);
    pthread_join(tidB, NULL);
    
    return 0;
}

void *doit(void *vptr)
{
    int i, val;

    for (i = 0; i < NLOOP; i++) 
    {
        pthread_mutex_lock(&conter_mutex);
        val = counter;
        printf("%x: %d\n", (unsigned int)pthread_self(), val+1);
        counter = val + 1;

        pthread_mutex_unlock(&conter_mutex);
    }

    return NULL;
}
