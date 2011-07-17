#include <stdio.h>
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <strings.h>
#include <netinet/in.h>
#include <unistd.h>
#include <ctype.h>
#include <arpa/inet.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include "wrap.h"

#define MAXLINE 4096
#define SERV_PORT 8000

int main(int argc, const char *argv[])
{
    int listenfd, connfd;
    struct sockaddr_in servaddr, cliaddr;
    socklen_t cliaddr_len;
    char buf[MAXLINE];
    char str[INET_ADDRSTRLEN];
    int n;
    pid_t pid;
    int filefd;

    listenfd = my_socket(AF_INET, SOCK_STREAM, 0);

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(SERV_PORT);

    my_bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr));

    my_listen(listenfd, 20);

    printf("Accepting connections...\n");

    while (1) 
    {
        cliaddr_len = sizeof(cliaddr);
        connfd = my_accept(listenfd, (struct sockaddr *)&cliaddr, &cliaddr_len);

        pid = fork();
        if (pid == -1) 
        {
            perror("call to fork");
            exit(1);
        }
        else if (pid == 0) 
        {
            my_close(listenfd);
            //n = my_read(connfd, buf, MAXLINE);
            n = my_read(connfd, buf, 4096);
            filefd = open(buf, O_RDWR | O_CREAT | O_TRUNC, 0666);
            //my_write(filefd, &buf[strlen(buf)+1], MAXLINE-strlen(buf)-1);
            my_write(filefd, &buf[strlen(buf)+1], 4096-(strlen(buf)+1));
            while ((n = my_read(connfd, buf, MAXLINE))) 
            {
                //n = my_read(connfd, buf, MAXLINE);
                //if (n == 0)
                //{
                    //printf("The other side has been closed.\n");
                    //break;
                //}
                printf("Received from %s at PORT %d\n", inet_ntop(AF_INET, &cliaddr.sin_addr, str, sizeof(str)), ntohs(cliaddr.sin_port));

                if (filefd < 0) 
                {
                    perror("create file error");
                    exit(1);
                }

                //for (i = 0; i < n; i++) 
                //{
                    //buf[i] = toupper(buf[i]);
                //}
                my_write(filefd, buf, n);
            }
            my_close(filefd);
            exit(0);
        }
        else 
        {
            my_close(connfd);
        }
    }

    return 0;
}
