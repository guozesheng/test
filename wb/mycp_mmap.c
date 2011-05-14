#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>

int main(int argc, const char *argv[])
{
    int *pi, *po;
    int fd_in = open(argv[1], O_RDONLY);
    int fd_out = open(argv[2], O_RDWR | O_CREAT | O_TRUNC, 0666);
    struct stat length;

    if (fd_in < 0 || fd_out < 0) 
    {
        perror("open fail");
        exit(1);
    }

    if (fstat(fd_in, &length) != 0)
    {
        perror("fstat");
        exit(1);
    }

    lseek(fd_out, length.st_size-1, SEEK_SET);
    write(fd_out, "", 1);
    
    pi = mmap(NULL, length.st_size, PROT_READ, MAP_PRIVATE, fd_in, 0);//fstat
    po = mmap(NULL, length.st_size, PROT_WRITE, MAP_SHARED, fd_out, 0);//memcpy
    if (pi == MAP_FAILED || po == MAP_FAILED) 
    {
        perror("mmap");
        exit(1);
    }
    memcpy(po, pi, length.st_size);

    close(fd_in);
    close(fd_out);
    munmap(pi, length.st_size);
    munmap(po, length.st_size);

    return 0;
}
