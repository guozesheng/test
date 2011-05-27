#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

struct msg 
{
    int num;
    struct msg *next;
} ;
struct msg *head;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t has_product = PTHREAD_COND_INITIALIZER;

void *producer(void *p);
void *consumer(void *p);

int main(int argc, const char *argv[])
{
    pthread_t pid, cid;

    srand(time(NULL));

    pthread_create(&pid, NULL, producer, NULL);
    pthread_create(&cid, NULL, consumer, NULL);

    pthread_join(pid, NULL);
    pthread_join(cid, NULL);
    
    return 0;
}

void *producer(void *p)
{
    struct msg *mp;
    struct msg *tmp;

    for (; ; ) 
    {
        mp = malloc(sizeof(struct msg));

        mp->num = rand() % 1000 + 1;
        printf("Produce %d\n", mp->num);
        pthread_mutex_lock(&lock);
        tmp = head;
        while ((head != NULL) && (tmp->next != head)) 
        {
            tmp = tmp->next;
        }
        if (head != NULL) 
        {
            tmp->next = mp;
        }
        else
        {
            head = mp;
        }
        mp->next = head;
        //head = mp;
        pthread_mutex_unlock(&lock);
        pthread_cond_signal(&has_product);
        usleep(rand() % 5);
    }
}

void *consumer(void *p)
{
    struct msg *mp;

    for (; ; ) 
    {
        pthread_mutex_lock(&lock);
        while (head == NULL) 
        {
            pthread_cond_wait(&has_product, &lock);
        }
        mp = head;
        if (head->next == mp) 
        {
            head = NULL;
        }
        else 
        {
            head = mp->next;
        }
        pthread_mutex_unlock(&lock);
        printf("Consume %d\n", mp->num);
        free(mp);
        usleep(rand() % 5);
    }
}
