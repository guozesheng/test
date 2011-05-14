#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

int main(int argc, const char *argv[])
{
    int fd_in, fd_out;
    int *p_in, *p_out;
    struct stat length;

    if (argc != 3) 
    {
        printf("error\n");
        exit(1);
    }

    fd_in = open(argv[1], O_RDONLY);
    fd_out = open(argv[2], O_RDWR | O_CREAT | O_TRUNC, 0666);
    if (fd_in < 0 || fd_out < 0) 
    {
        perror("open error");
        exit(1);
    }

    if (fstat(fd_in, &length) < 0)
    {
        perror("fstat");
        exit(1);
    }

    lseek(fd_out, length.st_size-1, SEEK_SET);
    write(fd_out, "", 1);

    p_in = mmap(NULL, length.st_size, PROT_READ, MAP_PRIVATE, fd_in, 0);
    p_out = mmap(NULL, length.st_size, PROT_WRITE, MAP_SHARED, fd_out, 0);
    
    memcpy(p_out, p_in, length.st_size);

    close(fd_in);
    close(fd_out);
    munmap(p_in, length.st_size);
    munmap(p_out, length.st_size);
    return 0;
}
