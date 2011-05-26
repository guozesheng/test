#include <stdio.h>
#include <pthread.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

void printids(const char *s);
void *thr_fn(void *arg);

pthread_t ntid;

int main(int argc, const char *argv[])
{
    int err;

    err = pthread_create(&ntid, NULL, thr_fn, "new thread: ");
    if (err != 0) 
    {
        fprintf(stderr, "can't create thread: %s\n", strerror(err));
        exit(1);
    }

    printids("main thread: ");
    sleep(1);
    
    return 0;
}

void *thr_fn(void *arg)
{
    printids(arg);
    
    return NULL;
}

void printids(const char *s)
{
    pid_t pid;
    pthread_t tid;

    pid = getpid();
    tid = pthread_self();

    printf("%s pid %u tid %u (0x%x)\n", s, (unsigned int)pid, (unsigned int)tid, (unsigned int)tid);
    printf("ntid = %u\n", (unsigned int)ntid);
}
