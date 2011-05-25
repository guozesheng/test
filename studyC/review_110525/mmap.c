#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <unistd.h>

int main(int argc, const char *argv[])
{
    int fd;
    int *p;

    fd = open("a.text", O_RDWR);
    if (fd < 0) 
    {
        perror("open");
        exit(1);
    }

    p = mmap(NULL, 12, PROT_WRITE, MAP_SHARED, fd, 0);
    if (p == MAP_FAILED) 
    {
        perror("mmap");
        exit(1);
    }
    close(fd);

    p[0] = 'G';
    
    munmap(p, 12);
    return 0;
}
