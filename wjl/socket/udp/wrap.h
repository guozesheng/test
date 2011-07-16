#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <errno.h>
#include <unistd.h>

void perr_exit(const char *s)
{
    perror(s);
    exit(1);
}

int my_accept(int fd, struct sockaddr *sa, socklen_t *salenptr)
{
    int n;

    while ((n = accept(fd, sa, salenptr)) < 0) 
    {
        if ((errno != ECONNABORTED) && (errno != EINTR)) 
        {
            perr_exit("accept error");
        }
    }

    return n;
}

void my_bind(int fd, const struct sockaddr *sa, socklen_t salen)
{
    if (bind(fd, sa, salen) < 0) 
    {
        perr_exit("bind error");
    }
}

void my_connect(int fd, const struct sockaddr *sa, socklen_t salen)
{
    if (connect(fd, sa, salen) < 0) 
    {
        perr_exit("connect error");
    }
}

void my_listen(int fd, int backlog)
{
    if (listen(fd, backlog) < 0) 
    {
        perr_exit("listen error");
    }
}

int my_socket(int family, int type, int protocol)
{
    int n;
    
    if ((n = socket(family, type, protocol)) < 0) 
    {
        perr_exit("socket error");
    }

    return n;
}

ssize_t my_read(int fd, void *ptr, size_t nbytes)
{
    ssize_t n;

    while ((n = read(fd, ptr, nbytes)) == -1) 
    {
        if (errno != EINTR) 
        {
            return -1;
        }
    }

    return n;
}

ssize_t my_write(int fd, const void *ptr, size_t nbytes)
{
    ssize_t n;
    
    while ((n = write(fd, ptr, nbytes)) == -1) 
    {
        if (errno != EINTR) 
        {
            return -1;
        }
    }

    return n;
}

void my_close(int fd)
{
    if (close(fd) == -1) 
    {
        perr_exit("close error");
    }
}
