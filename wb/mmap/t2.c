#include <stdio.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, const char *argv[])
{
    int fd;
    int i;
    char *p;
    
    fd = open("a.text", O_RDWR);
    if (fd < 0) 
    {
        perror("open a.text");
        exit(1);
    }

    p = (char *)mmap(NULL, 10, PROT_WRITE | PROT_READ, MAP_SHARED, fd, 0);
    printf("0x%x\n", (unsigned int)p);
    if (p == MAP_FAILED) 
    {
        perror("mmap fd");
        exit(1);
    }
    close(fd);

    for (i = 0; i < 10; i++) 
    {
        printf("%4d", p[i]);
    }
    printf("\n");

    munmap(p, 10);
    return 0;
}
