#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <strings.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

#define MAXLINE 80
#define SERV_PORT 8000

int main(int argc, const char *argv[])
{
    char *str;
    int sockfd, n;
    struct sockaddr_in servaddr;
    char buf[MAXLINE];

    if (argc != 2) 
    {
        fputs("usage: ./client message\n", stderr);
        exit(1);
    }
    str = (char *)argv[1];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    inet_pton(AF_INET, "127.0.0.1", &servaddr.sin_addr);
    servaddr.sin_port = htons(SERV_PORT);

    connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));

    write(sockfd, str, strlen(str) + 1);

    n = read(sockfd, buf, MAXLINE);
    printf("Response from server:\n");
    write(STDOUT_FILENO, buf, n);
    
    close(sockfd);
    printf("\n");
    return 0;
}
