#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <string.h>

int main(int argc, const char *argv[])
{
    int fd_in, fd_out;
    struct stat file_status;
    int *p_in, *p_out;

    fd_in = open(argv[1], O_RDONLY);
    fd_out = open(argv[2], O_RDWR | O_CREAT | O_TRUNC, 0666);
    if (fd_in < 0 || fd_out < 0) 
    {
        perror("open");
        exit(1);
    }

    if (fstat(fd_in, &file_status) != 0)
    {
        perror("fstat");
        exit(1);
    }

    lseek(fd_out, file_status.st_size-1, SEEK_SET);
    write(fd_out, "", 1);

    p_in = mmap(NULL, file_status.st_size, PROT_READ, MAP_PRIVATE, fd_in, 0);
    p_out = mmap(NULL, file_status.st_size, PROT_WRITE, MAP_SHARED, fd_out, 0);

    if (p_in == MAP_FAILED || p_out == MAP_FAILED) 
    {
        perror("mmap");
        exit(1);
    }

    memcpy(p_out, p_in, file_status.st_size);

    close(fd_in);
    close(fd_out);
    munmap(p_in, file_status.st_size);
    munmap(p_out, file_status.st_size);
    return 0;
}
